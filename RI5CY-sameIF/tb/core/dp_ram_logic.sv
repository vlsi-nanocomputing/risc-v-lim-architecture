// Copyright 2015 ETH Zurich and University of Bologna.
// Copyright 2017 Embecosm Limited <www.embecosm.com>
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

import riscv_defines::*;
`define DEBUG

module dp_ram_logic
    #(parameter ADDR_WIDTH = 10, 
	 parameter INSTR_RDATA_WIDTH = 32)
    (input  logic                          clk_i,			
     input  logic                          rst_ni,			

	//Istruzioni "a"
     input  logic                          en_a_i,
     input  logic [ADDR_WIDTH-1:0]         addr_a_i,
     input  logic [31:0]                   wdata_a_i,
     output logic [INSTR_RDATA_WIDTH-1:0]  rdata_a_o, 	//output read instruction
     input  logic                          we_a_i, 		//set to 0 in mm_ram (always load)
     input  logic [3:0]                    be_a_i, 		// set to all 1s in mm_ram, always want 32-bits

	//Dati "b"
     input  logic                          en_b_i, 		// Bank request from amo_shim
     input  logic [ADDR_WIDTH-1:0]         addr_b_i, 	//data address 
     input  logic [31:0]                   wdata_b_i, 	//input data
     output logic [31:0]                   rdata_b_o, 	//output read data
     input  logic                          we_b_i,  	//  1: Store, 0: Load from amo_shim
     input  logic [3:0]                    be_b_i, 		// Byte enable from amo_shim
     input  logic                          gnt_b_i, 	//bank grant from amo shim
     output logic                          rvalid_b_o 	//data valid signal
    );

    localparam bytes = 2**ADDR_WIDTH;		
	

    localparam LOGIC_MEM_FUNCT_ADDRESS = (bytes/32-4); //Special programming address LOGIC_MEM_FUNCT_ADDRESS= 131068(dec) = 1FFFC 
														
														
    // Normal memory
    logic [7:0]                      mem[bytes];	// 8bit wide vector array with 4194304 depth
													// 4 memory lines is a word (4 bytes)
	
    logic [ADDR_WIDTH-1:0]           addr_a_int;	// instruction addresses
    logic [ADDR_WIDTH-1:0]           addr_b_int;	//data addresses
 
    // Logic-in-memory
    logic [ADDR_WIDTH-1:0]           asize_mem_int;		//range operation without byte offset (2 LSBs)
    logic [ADDR_WIDTH-1:0]           addr_b_range_end;	//range operation end address
    logic                            en_b_int;			// Bank request internal (after manipulation)
    logic [31:0]                     wdata_b_int;
    logic                            word_lines[bytes];
    logic                            word_lines_int[bytes];
    logic                            decoder_range_init[bytes]; //initial decoder range
    logic                            decoder_range_end[bytes];	//final decoder range 
    logic                            range_active;		//signal that identifies a range operation
    logic [31:0]                     mask;	
    logic [2:0]                      logic_in_memory_funct_int; 	//Logic function after masking 
    logic [31:0]                     logic_in_memory_funct; 		//LiM programming cell
    logic [28:0]                     asize_mem;						//Range for LiM operations
    logic                            we_b_funct_mem;				//Notifies LiM programming
    logic [2:0]                      opcode_mem; 					//Opcode for LiM operations


    always_comb addr_a_int = {addr_a_i[ADDR_WIDTH-1:2], 2'b0};
    
    always_comb asize_mem_int = {asize_mem[ADDR_WIDTH-1:0], 2'b0}; // Only 32 bits words are considered as vector elements
	
	//======================================================================
	//	NEW SIGNALS
	logic							en_b_rt_valid;	 		 
	logic							en_b_rt_valid_q;	
	logic                           en_b_rt_q;				//sampled en_b 
	logic [ADDR_WIDTH-1:0]          addr_b_rt_q;			//sampeld address for RT
	logic [31:0]                    wdata_b_rt_q;			//sambled write_data for RT
	logic							rvalid_rt;				//valid signal from RT 
	logic							rvalid_rt_int;			//internal valid signal from RT (useful for range oprations)
	logic [3:0]						be_b_int;				//internal be_b
	logic [3:0]						be_b_q;					//sampled be_b signal 
	logic [bytes-1:0]               word_lines_p;			//packed wordlines for dummy RT
	logic   					    en_b_int_rt;			//masked start transaction signal for RT
	logic							we_b_rt;				//masked write enable for RT
	logic                           decoder_range [bytes];	//final decoder range 
	logic [ADDR_WIDTH-1:0]          addr_b_range;			//address in range operations
	logic							ld;						//load enable for counter in range decoder
	logic							cnt_en;					//enable for counter in range decoder
	logic							cmp_end_add;			//comparator for end address in range decoder	
	logic [ADDR_WIDTH-1:0]          addr_b_range_cmp;		//address end decremented by four for the comparators			

	logic							we_b_q;				
	logic							we_b_int;				
	
	
	


	//======================================================================
    // NEW HANDSHAKING PROTOCOL (takes into account RT's latency)
    //====================================================================== 
	
	 assign en_b_rt_valid = en_b_i && !we_b_funct_mem;	//generate enable signal for sampling input signals

	
	
	//sample input signal for handshake
	always_ff @(posedge clk_i, negedge rst_ni) begin
        if (~rst_ni) begin								//if reset is 0 (active low) set the signal to 0
             en_b_rt_valid_q   <= 1'b0;
        end
        else if (en_b_rt_valid || rvalid_rt) begin	
             en_b_rt_q             <= en_b_i; 							
			 wdata_b_rt_q      	   <= wdata_b_i;
             en_b_rt_valid_q   	   <= en_b_rt_valid;
			 addr_b_rt_q		   <= {addr_b_i[ADDR_WIDTH-1:2], 2'b0};
			 be_b_q				   <= be_b_i;
			 we_b_q				   <= we_b_i;	

        end
    end  
	
	
	// Valid signal for maxmin handshake
    assign en_b_int            = (en_b_rt_valid_q) ? en_b_rt_q        	 : en_b_i;
    assign wdata_b_int         = (en_b_rt_valid_q) ? wdata_b_rt_q      	 : wdata_b_i;
    assign addr_b_int          = (en_b_rt_valid_q) ? addr_b_rt_q       	 : {addr_b_i[ADDR_WIDTH-1:2], 2'b0};
	assign be_b_int			   = (en_b_rt_valid_q) ? be_b_q        	     : be_b_i;
	assign we_b_int			   = (en_b_rt_valid_q) ? we_b_q				 : we_b_i;		

	//only sw_active_logic can be carried out in one clock cycle
    assign rvalid_b_o          = (en_b_rt_valid_q || en_b_rt_valid ) ?  rvalid_rt  : gnt_b_i; 	
	


    //======================================================================
    // ADDRESS DECODER -RANGE SERIALIZER
    //====================================================================== 
    // RANGE DECODER
    /* Normal decoder - Initial address decoder*/
    always_comb begin
        for (int i=0; i<bytes; i++) begin
            decoder_range_init[i] = 1'b0; 
        end
        decoder_range_init[addr_b_int] = 1'b1; 
    end

	/*Decoder for range operations*/	
	    always_comb begin
        for (int i=0; i<bytes; i++) begin // Range operations can be done only with aligned memory locations
            decoder_range[i] = 1'b0;
        end
        if (range_active) begin //if it is a range operation go on 
            decoder_range[addr_b_range] = 1'b1; //assert active wordline
        end
    end


    /* Final address decoder */
    assign range_active = en_b_int && (asize_mem != 0 && asize_mem != 1) && !we_b_funct_mem;  //generate a signal when range operations are active
 
    assign addr_b_range_end = addr_b_int + asize_mem_int;



    /* Word_lines */    //Qua mette a 1 le wordlines selezionate 
    always_comb begin
        // Initialization					
        for (int i=0; i<bytes; i++) begin
            word_lines[i]     = decoder_range_init[i];	//initialize with no range wordlines
        end
     
        // Range operation: possible only on words (32 bits)
        if (range_active) begin
            //decoder_range[0] = 1'b0;	
            //decoder_range[1] = 1'b0;
            //decoder_range[2] = 1'b0;
            //decoder_range[3] = 1'b0;
            for (int i=4; i<bytes; i=i+4) begin
                word_lines[i    ] = decoder_range[i];
                word_lines[i + 1] = decoder_range[i];
                word_lines[i + 2] = decoder_range[i];
                word_lines[i + 3] = decoder_range[i];
            end
        end
        // Single case: possible on bytes (8 bits), half-words (16 bits) and words (32 bits)	(range not active)
        else begin
            for (int i=0; i<bytes; i=i+4) begin
                word_lines[i  ] = be_b_int[0] && decoder_range_init[i];
                word_lines[i+1] = be_b_int[1] && decoder_range_init[i];
                word_lines[i+2] = be_b_int[2] && decoder_range_init[i];
                word_lines[i+3] = be_b_int[3] && decoder_range_init[i];
            end
        end 
    end 


	/*	Counter for range operations */

	always @(posedge clk_i, negedge rst_ni, posedge ld) begin
		if(!rst_ni) begin
			addr_b_range <= '0;
		end else if(ld) begin
			addr_b_range <= addr_b_i;
		end

		if(cnt_en) begin
			addr_b_range <= addr_b_range +32'h4;	//addresses are incremented 4 by 4 
		end
	end

	assign ld 	      		= en_b_i && range_active;			//load value when there is a range memory transaction	
	assign cnt_en 	  		= rvalid_rt_int && !cmp_end_add;	//increment add when memory transaction is done and it is not the final address
	assign addr_b_range_cmp =  addr_b_range_end -32'h4;			//takes the decision on address N-1

	//Comparator for end address in range operations
	always_comb begin
		cmp_end_add = 1'b0; //initialize to 0

		if(addr_b_range == addr_b_range_cmp) begin
			cmp_end_add = 1'b1;
		end
	end

	//======================================================================
	
	//active when the LiM is being programmed
    assign we_b_funct_mem = (addr_b_int == LOGIC_MEM_FUNCT_ADDRESS); 
																	 
	
	//internal logic_in_memory_funct, it is 0 when the LiM is being programmed																
    assign logic_in_memory_funct_int = logic_in_memory_funct[2:0] & {3{~we_b_funct_mem}}; // when funct cell is written, the old stored functionality should be ignored
																						  
																						  
    //======================================================================
    // READ MEMORY LOGIC
    //======================================================================
	

    // INSTRUCTION PART
    always_ff @(posedge clk_i) begin
		for (int i = 0; i < INSTR_RDATA_WIDTH/8; i++) begin
			rdata_a_o[(i*8)+: 8] <= mem[addr_a_int +  i]; 
		end												  
    end
	


    //======================================================================
    // LOGIC-IN-MEMORY
    //======================================================================
    // LOGIC-IN-MEMORY FUNCT CELL
    // Register that shows the same value of the FUNCT CELL, except for the beginning because of the reset


    always_ff @(posedge clk_i, negedge rst_ni) begin
        if (!rst_ni) begin
            logic_in_memory_funct <= '0;
        end
		  else if (en_b_int && we_b_int && addr_b_int == LOGIC_MEM_FUNCT_ADDRESS) begin

            logic_in_memory_funct <= wdata_b_i;											
        end
    end
	
	
	
	assign opcode_mem   = logic_in_memory_funct[2:0]; 
    assign asize_mem    = logic_in_memory_funct[31:3];	
	
	
	//======================================================================
    // DUMMY RT MEMORY
    //======================================================================

	//convert unpacked wordlines to packed array
	assign word_lines_p = { << { word_lines }};


	assign en_b_int_rt = en_b_int && !we_b_funct_mem;	//disable RT during sw_active_logic

    /*RVALID_RT LOGIC*/
	always_comb begin

		//initialize to 0
		rvalid_rt = 1'b0; 
		
		if(range_active) begin
			rvalid_rt = rvalid_rt_int && cmp_end_add;	//valid is on during last access of range operation
		end else begin
			rvalid_rt = rvalid_rt_int;					//if range is not active take direclty rvalid_rt
		end

	end


	dummy_RT#(
		.ADDR_WIDTH(ADDR_WIDTH),
		.bytes(bytes)
	)
	dummy_racetrack
	(
		.clk_i(clk_i),
		.rst_ni(rst_ni),
		.en_b_int_i(en_b_int_rt),				//enable for starting memory transaction
		.we_b_i(we_b_int),						//write enable
		.word_lines_i(word_lines_p),
		.opcode_mem_i(opcode_mem),
		.mask_i(mask), 							
		.wdata_b_i(wdata_b_int),				//write data
		
		.rdata_b_o(rdata_b_o),
		.rvalid_rt_o(rvalid_rt_int)

	);
	
	
	
	

    //======================================================================
    // MASK LOGIC
    //======================================================================
    
     assign   mask = wdata_b_int;	//takes the mask from wdata_b_int 
        
 
    //======================================================================
    // Debug memory parts
    //======================================================================
`ifndef SYNTHESIS
`ifdef DEBUG
    localparam                       N_VECTOR = 32;
    logic                            sub_word_lines[4*N_VECTOR];
    logic [7:0]                      sub_mem[4*N_VECTOR];
	logic [7:0]						 sub_mem_rt[4*N_VECTOR];
    logic                            sub_word_lines_int[4*N_VECTOR];


    always_comb begin
        for (int i=0; i<4*N_VECTOR; i++) begin 
            sub_mem[i]            = mem['h30000+i]; //h30000 = 196608
			sub_mem_rt[i]		  = dummy_racetrack.RT_mem['h30000+i]; //ADD RT memory array	
            sub_word_lines[i]     = word_lines['h30000+i];		

            sub_word_lines_int[i] = word_lines_int['h30000+i];
        end
    end


`endif
`endif

endmodule // dp_ram_logic
