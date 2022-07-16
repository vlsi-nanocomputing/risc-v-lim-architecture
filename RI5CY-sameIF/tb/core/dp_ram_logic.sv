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
     parameter MAX_SIZE = 8192*4,
     parameter MEM_MODE = 1,
     parameter INSTR_RDATA_WIDTH = 32)
    (input  logic                          clk_i,
     input  logic                          rst_ni,			

	
     input  logic                          en_a_i,
     input  logic [ADDR_WIDTH-1:0]         addr_a_i,
     input  logic [31:0]                   wdata_a_i,
     output logic [INSTR_RDATA_WIDTH-1:0]  rdata_a_o,   //output read instruction
     input  logic                          we_a_i,      //set to 0 in mm_ram (always load)
     input  logic [3:0]                    be_a_i,      // set to all 1s in mm_ram, always want 32-bits

	
     input  logic                          en_b_i,      // Bank request from amo_shim
     input  logic [ADDR_WIDTH-1:0]         addr_b_i,    //data address 
     input  logic [31:0]                   wdata_b_i,   //input data
     output logic [31:0]                   rdata_b_o,   //output read data
     input  logic                          we_b_i,      //  1: Store, 0: Load from amo_shim
     input  logic [3:0]                    be_b_i,      // Byte enable from amo_shim
     input  logic                          gnt_b_i,     //bank grant from amo shim
     output logic                          rvalid_b_o   //data valid signal
    );

`ifdef RT_LIM_MEM    //LiM Racetrack memory part   
    localparam bytes     = MAX_SIZE;
    localparam words     = bytes/4; 	
    localparam Nb        = 32;    //Length racetrack
    localparam Nr        = 4;     //N racetrack in MU
    localparam NMU       = 8;     //N Macro Unit
    localparam par       = Nr*NMU;
    localparam blocks    = words/Nb;	


	
    localparam LOGIC_MEM_FUNCT_ADDRESS = 32'h0001fffc; //Special LiM programming address




`elsif LIM_MEM   //LiM memory part

    localparam bytes = 2**ADDR_WIDTH;
    localparam words = bytes/4; 
    localparam LOGIC_MEM_FUNCT_ADDRESS = (bytes/32-4);

`elsif STD_MEM  //standard memory part

    localparam bytes = 2**ADDR_WIDTH;
    localparam words = 1; //remove unnecessary signals with ifdef
	
`endif
  
    localparam words_tri = words*3;
    localparam triplets  = words_tri/3;
	
														
														
    // Normal memory (global signals)
    logic [7:0]                      mem[bytes];                    //memory array for isntruction part	
						
	
    logic [ADDR_WIDTH-1:0]           addr_a_int;                    //instruction addresses
    logic [ADDR_WIDTH-1:0]           addr_b_int;                    //data addresses


`ifndef RT_LIM_MEM

    //Signals for std & std-LiM signals
    logic [7:0]                      mem_in[bytes];		
    logic                            word_lines_std_mem[bytes];     //wordlines for byte addressed memory
    logic                            word_lines_std_mem_int[bytes]; 
    
 
`endif

`ifndef STD_MEM
 
    // Logic-in-memory signals
    logic [ADDR_WIDTH-1:0]           asize_mem_int;                 //range operation without byte offset (2 LSBs)
    logic [ADDR_WIDTH-1:0]           addr_b_range_end;              //range operation end address
    logic [ADDR_WIDTH-1:0]           ADDR_int_par;                  //address coding for higher range parallelism
    logic [ADDR_WIDTH-1:0]           ADDR_int;                      //output of address mux
    logic                            en_b_int;                      // Bank request internal (after manipulation)
    logic [31:0]                     wdata_b_int;
    logic                            word_lines[words];             //wordlines for word addressed memory
    logic                            word_lines_int[words];
    logic                            range_active;                  //signal that identifies a range operation
    logic [31:0]                     mask;	
    logic [7:0]                      logic_in_memory_funct_int;     //Logic function after masking 
    logic [31:0]                     logic_in_memory_funct;         //LiM programming cell
    logic [23:0]                     asize_mem;                     //Range for LiM operations
    logic                            we_b_funct_mem;                //Notifies LiM programming
    logic [7:0]                      opcode_mem;                    //Opcode for LiM operations
    logic                            en_b_rt_valid;	 		 
    logic                            en_b_rt_valid_q;	
    logic                            en_b_rt_q;                     //sampled en_b 
    logic [ADDR_WIDTH-1:0]           addr_b_rt_q;                   //sampeld address for RT
    logic [31:0]                     wdata_b_rt_q;                  //sambled write_data for RT
    logic                            rvalid_rt;                     //valid signal from RT 
    logic                            rvalid_rt_int;                 //internal valid signal from RT (useful for range oprations)
    logic [3:0]                      be_b_int;                      //internal be_b
    logic [3:0]                      be_b_q;                        //sampled be_b signal 
    logic [words-1:0]                word_lines_p;                  //packed wordlines for dummy RT
    logic                            en_b_int_rt;                   //masked start transaction signal for RT
    logic [ADDR_WIDTH-1:0]           addr_b_range;                  //address in range operations
    logic                            ld;                            //load enable for counter in range decoder
    logic                            cnt_en;                        //enable for counter in range decoder
    logic                            cmp_end_add;                   //comparator for end address in range decoder	
    logic [ADDR_WIDTH-1:0]           addr_b_range_cmp;              //address end decremented by four for the comparators			
    logic                            we_b_q;				
    logic                            we_b_int;				
    logic [ADDR_WIDTH-1:0]           addr_b_int_dec;                //decoded address (divide by 4)
    logic [ADDR_WIDTH-1:0]           addr_b_range_dec;              //decoded address (divide by 4)
    logic [ADDR_WIDTH-1:0]           addr_mem_dec;                  //decoded address (divide by 3) for memory mode
    logic                            decoder_init[words];           //initial decoder for word addressed memory
    logic                            word_lines_lim[words];         //word_lines for LiM mode RT memory
    logic                            word_lines_tri[words_tri];     //word_lines for memory mode RT memory
    logic                            active_triplet[triplets];
    logic [2:0]                      word_sel_tri;                  //word selection for memory mode
    logic [1:0]                      n_shift;                       //n. of required shift
    logic [1:0]                      n_shift_lim;                   //n. of required shift for LiM mode
    logic [31:0]                     mask_count;                    //mask signal for max/min operation
    logic                            start_maxmin;                  //start signal for max/min operation
    logic                            stop_maxmin_iteration;         //stop signal for max/min operation                
    logic                            en_b_maxmin_valid;             //valid signal for maxmin operations
    logic                            en_b_maxmin_q;                 //sampled enable sinal for max/min operations            
    logic [31:0]                     wdata_b_maxmin_q;              //sampled write data for max/min operations
    logic                            en_b_maxmin_valid_q;           //sampled valid signal for max/min operations
    logic [ADDR_WIDTH-1:0]           addr_b_maxmin_q;               //sampled addr for max/min operations
    logic                            decoder_range_init[bytes];     //range decoder init wordlines for byte addr. memory
    logic                            decoder_range_end[bytes];      //range decoder end wordlines for byte addr. memory
    logic                            word_wired_zeros[bytes];       //constant for max/min operations
    logic                            word_wired_ones[bytes];        //constant for max/min operations
    logic                            word_wired_or[bytes];          //wired or array
    logic                            result_word_wired_or[bytes];   //result wired or array
    logic                            enabled_rows[bytes];           //enabled rows for max/min operations
    logic                            next_enabled_rows[bytes];      //next enabled rows for max/min operations
    
    logic [7:0]                      mem_and[bytes];
    logic [7:0]                      mem_or[bytes];
    logic [7:0]                      mem_xor[bytes];


    logic                            word_lines_reord[words];         //reordered word lines
    logic                            decoder_range_end_rt[words];     //range decoder end wordlines for word addr. memory
    logic                            decoder_range_init_rt[bytes];    //range decoder init wordlines for byte addr. memory

`endif

    
`ifdef RT_LIM_MEM    //racetrack memory part

    //Racetrack waveforms
       logic						   clk_m_i       = 1'b1;    //magnetic clock
       logic						   Bz_s_i        = 1'b1;    //Magnetic field sign
       logic						   write_pulse_i = 1'b1;    //write pulse for racetrack
       logic						   read_pulse_i  = 1'b1;    //read pulse for racetrack
 
`endif


    always_comb addr_a_int = {addr_a_i[ADDR_WIDTH-1:2], 2'b0};


    
    
	


    //======================================================================
    // HANDSHAKING PROTOCOL 
    //====================================================================== 

    
`ifdef RT_LIM_MEM    //racetrack memory part
	
        assign en_b_rt_valid = en_b_i && !we_b_funct_mem;	//generate enable signal for sampling input signals

	
        //sample input signal for handshake
        always_ff @(posedge clk_i, negedge rst_ni) begin
            if (~rst_ni) begin								//if reset is 0 (active low) set the signal to 0
                 en_b_rt_valid_q   <= 1'b0;
            end
            else if (en_b_rt_valid || rvalid_rt) begin	
                 en_b_rt_q             <= en_b_i; 							
                 wdata_b_rt_q          <= wdata_b_i;
                 en_b_rt_valid_q       <= en_b_rt_valid;
                 addr_b_rt_q           <= {addr_b_i[ADDR_WIDTH-1:2], 2'b0};
                 be_b_q                <= be_b_i;
                 we_b_q                <= we_b_i;	

            end
        end  
	
	
        // Valid signal for maxmin handshake
        assign en_b_int            = (en_b_rt_valid_q) ? en_b_rt_q           : en_b_i;
        assign wdata_b_int         = (en_b_rt_valid_q) ? wdata_b_rt_q        : wdata_b_i;
        assign addr_b_int          = (en_b_rt_valid_q) ? addr_b_rt_q         : {addr_b_i[ADDR_WIDTH-1:2], 2'b0};
        assign be_b_int            = (en_b_rt_valid_q) ? be_b_q              : be_b_i;
        assign we_b_int            = (en_b_rt_valid_q) ? we_b_q              : we_b_i;		

        //only sw_active_logic can be carried out in one clock cycle
        assign rvalid_b_o          = (en_b_rt_valid_q || en_b_rt_valid ) ?  rvalid_rt  : gnt_b_i; 	



	
`elsif LIM_MEM    //LiM standard memory part




        // Registers to mantain stable the input data in case of maxmin request
        assign en_b_maxmin_valid = ((opcode_mem == FUNCT_MIN) || (opcode_mem == FUNCT_MAX)) && en_b_i && !we_b_funct_mem;

        assign start_maxmin = en_b_maxmin_valid && gnt_b_i;

        always_ff @(posedge clk_i, negedge rst_ni) begin
            if (~rst_ni) begin
                 en_b_maxmin_valid_q   <= 1'b0;
            end
            else if (en_b_maxmin_valid || stop_maxmin_iteration) begin
                 en_b_maxmin_q         <= en_b_i;
                 wdata_b_maxmin_q      <= wdata_b_i;
                 en_b_maxmin_valid_q   <= en_b_maxmin_valid;
                 addr_b_maxmin_q       <= {addr_b_i[ADDR_WIDTH-1:2], 2'b0};
            end
        end  

        // Valid signal for maxmin handshake
        assign en_b_int            = (en_b_maxmin_valid_q) ? en_b_maxmin_q         : en_b_i;
        assign wdata_b_int         = (en_b_maxmin_valid_q) ? wdata_b_maxmin_q      : wdata_b_i;
        assign addr_b_int          = (en_b_maxmin_valid_q) ? addr_b_maxmin_q       : {addr_b_i[ADDR_WIDTH-1:2], 2'b0};
        assign we_b_int            = we_b_i;
        assign rvalid_b_o          = (en_b_maxmin_valid_q || en_b_maxmin_valid ) ? stop_maxmin_iteration  : gnt_b_i; 

`elsif STD_MEM

        always_comb  addr_b_int = {addr_b_i[ADDR_WIDTH-1:2], 2'b0};
        assign rvalid_b_o       =  gnt_b_i; 

`endif




    //======================================================================
    // ADDRESS DECODER 
    //====================================================================== 

    
   
 
`ifdef RT_LIM_MEM    //racetrack memory part   

     //MAP RISC address (4 by 4)
     assign addr_b_int_dec = addr_b_int >> 2; //divide by 4

     //MAP MEMORY MODE address 
     assign addr_mem_dec = addr_b_int_dec/3;	


	 /*Decoder for range operations (LiM mode)*/	

     // RANGE DECODER
     /* Normal decoder - Initial address decoder*/
     always_comb begin
         for (int i=0; i<words; i++) begin
             decoder_range_init_rt[i] = 1'b0;
         end
        decoder_range_init_rt[addr_b_int_dec] = 1'b1;
     end



        always_comb begin
            for (int i=0; i<words; i++) begin // Range operations can be done only with aligned memory locations
                decoder_range_end_rt[i] = 1'b0;
            end
            if (range_active) begin
                decoder_range_end_rt[addr_b_range_end>>2] = 1'b1;
            end
        end


        always_comb begin
        // Initialization
        for (int i=0; i<words; i++) begin
            word_lines_int[i] = decoder_range_init_rt[i] | decoder_range_end_rt[i]; // In the range case, only two bits are equal to 1. In the single case, just one
            word_lines_lim[i]     = decoder_range_init_rt[i];
        end
     
        // Range operation: possible only on words (32 bits)
        if (range_active) begin
            word_lines_int[0] = 1'b0;
            for (int i=1; i<words; i=i+1) begin
                word_lines_lim[i    ] = (word_lines_int[i] & !word_lines_lim[i-1]) | (!word_lines_int[i] & word_lines_lim[i-1]);
            end
        end
        // Single case: possible on bytes (8 bits), half-words (16 bits) and words (32 bits)
        else begin
            for (int i=0; i<words; i=i+1) begin
                word_lines_lim[i  ] =  word_lines_int[i];
            end
        end 
    end 


	/* Active triplet selection  (Memory mode)*/
  	genvar i;
  
	  generate
		for (i=0; i<words_tri; i=i+3) begin  : gen_active_triplet
		  assign active_triplet[i/3] = (word_lines_tri[i]  || word_lines_tri[i+1] ||  word_lines_tri[i+2]) ;  
		end                                                          
	  
	  endgenerate

	
	/* Triplet word selection */
	  always_comb begin
	  word_sel_tri = 3'b0;
		for(int i=0; i<triplets; i++) begin
		  if(active_triplet[i])begin
		    word_sel_tri[0] = word_lines_tri[i*3];
		    word_sel_tri[1] = word_lines_tri[i*3+1];
		    word_sel_tri[2] = word_lines_tri[i*3+2];
		  end
		end
	  end
  
    //std_wordlines: wordlines for std. mem. mode
        always_comb begin
            for (int i=0; i<words_tri; i++) begin
                word_lines_tri[i] = 1'b0; //initiaize to 0 wordlines
            end
            word_lines_tri[addr_b_int_dec] = 1'b1 & !MEM_MODE; //NEW
        end


	
    // WORDLINE MUX
    assign word_lines = (MEM_MODE) ? word_lines_lim : active_triplet;   //MEM_MODE = 1 LiM mode
	



    //WORDLINES REORDERING
    //Exploit a different word storing policy to enable parallel access feature

    always_comb begin
        for (int i=0; i<words; i++) begin
            word_lines_reord[i] = 1'b0; //initiaize to 0 
        end
	  
	    for (int i=0; i<blocks; i++) begin
            
			word_lines_reord[0  + i*Nb] = 	word_lines[0*blocks+i];
			word_lines_reord[1  + i*Nb] = 	word_lines[1*blocks+i];
			word_lines_reord[2  + i*Nb] = 	word_lines[2*blocks+i];
			word_lines_reord[3  + i*Nb] = 	word_lines[3*blocks+i];
			word_lines_reord[4  + i*Nb] = 	word_lines[4*blocks+i];
			word_lines_reord[5  + i*Nb] = 	word_lines[5*blocks+i];
			word_lines_reord[6  + i*Nb] = 	word_lines[6*blocks+i];
			word_lines_reord[7  + i*Nb] = 	word_lines[7*blocks+i];
			word_lines_reord[8  + i*Nb] = 	word_lines[8*blocks+i];
			word_lines_reord[9  + i*Nb] = 	word_lines[9*blocks+i];
			word_lines_reord[10 + i*Nb] = 	word_lines[10*blocks+i];
			word_lines_reord[11 + i*Nb] = 	word_lines[11*blocks+i];
			word_lines_reord[12 + i*Nb] = 	word_lines[12*blocks+i];
			word_lines_reord[13 + i*Nb] = 	word_lines[13*blocks+i];
			word_lines_reord[14 + i*Nb] = 	word_lines[14*blocks+i];
			word_lines_reord[15 + i*Nb] = 	word_lines[15*blocks+i];
			word_lines_reord[16 + i*Nb] = 	word_lines[16*blocks+i];
			word_lines_reord[17 + i*Nb] = 	word_lines[17*blocks+i];
			word_lines_reord[18 + i*Nb] = 	word_lines[18*blocks+i];
			word_lines_reord[19 + i*Nb] = 	word_lines[19*blocks+i];
			word_lines_reord[20 + i*Nb] = 	word_lines[20*blocks+i];
			word_lines_reord[21 + i*Nb] = 	word_lines[21*blocks+i];
			word_lines_reord[22 + i*Nb] = 	word_lines[22*blocks+i];
			word_lines_reord[23 + i*Nb] = 	word_lines[23*blocks+i];
			word_lines_reord[24 + i*Nb] = 	word_lines[24*blocks+i];
			word_lines_reord[25 + i*Nb] = 	word_lines[25*blocks+i];
			word_lines_reord[26 + i*Nb] = 	word_lines[26*blocks+i];
			word_lines_reord[27 + i*Nb] = 	word_lines[27*blocks+i];
			word_lines_reord[28 + i*Nb] = 	word_lines[28*blocks+i];
			word_lines_reord[29 + i*Nb] = 	word_lines[29*blocks+i];
			word_lines_reord[30 + i*Nb] = 	word_lines[30*blocks+i];
			word_lines_reord[31 + i*Nb] = 	word_lines[31*blocks+i];
			
        end  
	  
    end



	//N. SHIFT GENERATION
    assign addr_b_range_dec = addr_b_range>>2;

    assign ADDR_int 		= (MEM_MODE) ? addr_b_int_dec: addr_mem_dec;
	
    assign ADDR_int_par     = ADDR_int /blocks;
	
    //select n shift based on the memory mode
    assign n_shift 			= ADDR_int_par[1:0]; //In LiM mode takes addr_dec, in std. mem . mode takes addr_dec/3 


`elsif LIM_MEM //LiM standard memory part


    // RANGE DECODER
    /* Normal decoder - Initial address decoder*/
    always_comb begin
        for (int i=0; i<bytes; i++) begin
            decoder_range_init[i] = 1'b0;
        end
        decoder_range_init[addr_b_int] = 1'b1;
    end

    always_comb begin
        for (int i=0; i<bytes; i++) begin // Range operations can be done only with aligned memory locations
            decoder_range_end[i] = 1'b0;
        end
        if (range_active) begin
            decoder_range_end[addr_b_range_end] = 1'b1;
        end
    end

    /* Word_lines */
    always_comb begin
        // Initialization
        for (int i=0; i<bytes; i++) begin
            word_lines_std_mem_int[i] = decoder_range_init[i] | decoder_range_end[i]; // In the range case, only two bits are equal to 1. In the single case, just one
            word_lines_std_mem[i]     = decoder_range_init[i];
        end
     
        // Range operation: possible only on words (32 bits)
        if (range_active) begin
            word_lines_std_mem_int[0] = 1'b0;
            word_lines_std_mem_int[1] = 1'b0;
            word_lines_std_mem_int[2] = 1'b0;
            word_lines_std_mem_int[3] = 1'b0;
            for (int i=4; i<bytes; i=i+4) begin
                word_lines_std_mem[i    ] = (word_lines_std_mem_int[i] & !word_lines_std_mem[i-4]) | (!word_lines_std_mem_int[i] & word_lines_std_mem[i-4]);
                word_lines_std_mem[i + 1] = (word_lines_std_mem_int[i] & !word_lines_std_mem[i-4]) | (!word_lines_std_mem_int[i] & word_lines_std_mem[i-4]);
                word_lines_std_mem[i + 2] = (word_lines_std_mem_int[i] & !word_lines_std_mem[i-4]) | (!word_lines_std_mem_int[i] & word_lines_std_mem[i-4]);
                word_lines_std_mem[i + 3] = (word_lines_std_mem_int[i] & !word_lines_std_mem[i-4]) | (!word_lines_std_mem_int[i] & word_lines_std_mem[i-4]);
            end
        end
        // Single case: possible on bytes (8 bits), half-words (16 bits) and words (32 bits)
        else begin
            for (int i=0; i<bytes; i=i+4) begin
                word_lines_std_mem[i  ] = be_b_i[0] && word_lines_std_mem_int[i];
                word_lines_std_mem[i+1] = be_b_i[1] && word_lines_std_mem_int[i];
                word_lines_std_mem[i+2] = be_b_i[2] && word_lines_std_mem_int[i];
                word_lines_std_mem[i+3] = be_b_i[3] && word_lines_std_mem_int[i];
            end
        end 
    end 



`elsif STD_MEM //standard memory part


        /* Initial address decoder*/
            always_comb begin
                for (int i=0; i<bytes; i++) begin
                    word_lines_std_mem_int[i] = 1'b0;
                end
                word_lines_std_mem_int[addr_b_int] = 1'b1;
            end

        /*Final address decoder with byte selection*/
        always_comb begin
            for (int i=0; i<bytes; i=i+4) begin
                word_lines_std_mem[i  ] = be_b_i[0] && word_lines_std_mem_int[i];
                word_lines_std_mem[i+1] = be_b_i[1] && word_lines_std_mem_int[i];
                word_lines_std_mem[i+2] = be_b_i[2] && word_lines_std_mem_int[i];
                word_lines_std_mem[i+3] = be_b_i[3] && word_lines_std_mem_int[i];
            end
        end


`endif

`ifndef STD_MEM 
	
    /* Final address decoder */ 
    assign range_active = en_b_int && (asize_mem != 0 && asize_mem != 1) && !we_b_funct_mem;  //generate a signal when range operations are active
 
    assign addr_b_range_end = addr_b_int + asize_mem_int;
	

    

	/* LiM programming decocoding */
    assign we_b_funct_mem = (addr_b_int == LOGIC_MEM_FUNCT_ADDRESS); 
																	 
	assign logic_in_memory_funct_int = logic_in_memory_funct[7:0] & {8{~we_b_funct_mem}}; // when funct cell is written, the old stored functionality should be ignored

`endif					

																	  
																						  
    //======================================================================
    // READ MEMORY LOGIC
    //======================================================================
	//Independent from data memory technology

    // INSTRUCTION PART
    always_ff @(posedge clk_i) begin
		for (int i = 0; i < INSTR_RDATA_WIDTH/8; i++) begin
			rdata_a_o[(i*8)+: 8] <= mem[addr_a_int +  i]; 
		end												  
    end
	

`ifndef STD_MEM 
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
    
    always_comb asize_mem_int = {asize_mem[ADDR_WIDTH-1:0], 2'b0}; // Only 32 bits words are considered as vector elements

	
    assign opcode_mem   = logic_in_memory_funct[7:0]; 
    assign asize_mem    = logic_in_memory_funct[31:8];	

`endif

    //======================================================================
    // MEMORY ARRAY INSTANTIATION
    //======================================================================

`ifdef RT_LIM_MEM    //racetrack memory part
	
	
    // RT MEMORY

	//convert unpacked wordlines to packed array
	assign word_lines_p = { << { word_lines_reord }};


	assign en_b_int_rt = en_b_int && !we_b_funct_mem;	//disable RT during sw_active_logic


    /*RVALID_RT LOGIC*/



    assign rvalid_rt = rvalid_rt_int;	


    // RACETRACK MEMORY MODULE
    
	RT_memory
	#(.ADDR_WIDTH(ADDR_WIDTH),										
	  .MAX_SIZE(MAX_SIZE),											
	  .MEM_MODE(MEM_MODE),											
	  .NWL(words)													
	 
	)
	racetrack_memory
	(
		.rstn_i(rst_ni),											
		.clk_i(clk_i),													
		.clk_m_i(clk_m_i),											
		.Bz_s_i(Bz_s_i),  											
		.en_ab_i(en_b_int_rt),  									
		.be_b_i(be_b_int),											
		.range_active_i(range_active),								
		.write_pulse_i(write_pulse_i),								
		.read_pulse_i(read_pulse_i),													
		.word_lines(word_lines_p),									
		.write_data_i(wdata_b_int),									
		.write_en_data_i(we_b_int),									
		.mask_i(mask),												
		.n_shift_i(n_shift),  	
		.logic_in_memory_funct_int_i(logic_in_memory_funct_int),	
        .word_sel_i(word_sel_tri),									
		
		.data_o(rdata_b_o),											
		.valid_o(rvalid_rt_int)										
	);


`elsif LIM_MEM    //LiM standard memory part

   

    /* Write Logic - Data part */

    always @(posedge clk_i) begin
        if (en_b_int && we_b_i) begin // DATA MEMORY PART  
            for (int row=0; row<bytes; row++) begin
                if(word_lines_std_mem[row]) mem[row] <= mem_in[row];
            end
        end
    end
    
   /* Read logic */
    always_ff @(posedge clk_i) begin
	if (en_b_int && !we_b_i) begin
	    unique case (logic_in_memory_funct_int)
		FUNCT_AND: begin
                        for (int i=0; i<bytes; i=i+4) begin
                            if( word_lines_std_mem[i] ) begin
                                rdata_b_o[ 7: 0] <= mem_and[i    ];
                                rdata_b_o[15: 8] <= mem_and[i + 1];
                                rdata_b_o[23:16] <= mem_and[i + 2];
                                rdata_b_o[31:24] <= mem_and[i + 3];
                            end
                        end	
		end
		
		FUNCT_OR: begin
                        for (int i=0; i<bytes; i=i+4) begin
                            if( word_lines_std_mem[i] ) begin
                                rdata_b_o[ 7: 0] <= mem_or[i    ];
                                rdata_b_o[15: 8] <= mem_or[i + 1];
                                rdata_b_o[23:16] <= mem_or[i + 2];
                                rdata_b_o[31:24] <= mem_or[i + 3];
                            end
                        end
		end
		
		FUNCT_XOR: begin
                        for (int i=0; i<bytes; i=i+4) begin
                            if( word_lines_std_mem[i] ) begin
                                rdata_b_o[ 7: 0] <= mem_xor[i    ];
                                rdata_b_o[15: 8] <= mem_xor[i + 1];
                                rdata_b_o[23:16] <= mem_xor[i + 2];
                                rdata_b_o[31:24] <= mem_xor[i + 3];
                            end
                        end
		end

		FUNCT_NOR: begin
                        for (int i=0; i<bytes; i=i+4) begin
                            if( word_lines_std_mem[i] ) begin
                                rdata_b_o[ 7: 0] <= ~(mem_or[i    ]);
                                rdata_b_o[15: 8] <= ~(mem_or[i + 1]);
                                rdata_b_o[23:16] <= ~(mem_or[i + 2]);
                                rdata_b_o[31:24] <= ~(mem_or[i + 3]);
                            end
                        end
		end

		FUNCT_NAND: begin
                        for (int i=0; i<bytes; i=i+4) begin
                            if( word_lines_std_mem[i] ) begin
                                rdata_b_o[ 7: 0] <= ~(mem_and[i    ]);
                                rdata_b_o[15: 8] <= ~(mem_and[i + 1]);
                                rdata_b_o[23:16] <= ~(mem_and[i + 2]);
                                rdata_b_o[31:24] <= ~(mem_and[i + 3]);
                            end
                        end
		end

		FUNCT_XNOR: begin
                        for (int i=0; i<bytes; i=i+4) begin
                            if( word_lines_std_mem[i] ) begin
                                rdata_b_o[ 7: 0] <= ~(mem_xor[i    ]);
                                rdata_b_o[15: 8] <= ~(mem_xor[i + 1]);
                                rdata_b_o[23:16] <= ~(mem_xor[i + 2]);
                                rdata_b_o[31:24] <= ~(mem_xor[i + 3]);
                            end
                        end
		end
		
		FUNCT_MAX, FUNCT_MIN : begin
			if ( stop_maxmin_iteration ) begin
                            for(int i=0; i<bytes; i=i+4) begin
                                if( next_enabled_rows[i] ) begin
                                    rdata_b_o[ 7: 0] <= mem[i    ];
                                    rdata_b_o[15: 8] <= mem[i + 1];
                                    rdata_b_o[23:16] <= mem[i + 2];
                                    rdata_b_o[31:24] <= mem[i + 3];
                                end
                            end
                        end
		end
		
		default: begin
			for (int i=0; i<bytes; i=i+4) begin
                            if( word_lines_std_mem[i] ) begin
                                rdata_b_o[ 7: 0] <= mem[i    ];
                                rdata_b_o[15: 8] <= mem[i + 1];
                                rdata_b_o[23:16] <= mem[i + 2];
                                rdata_b_o[31:24] <= mem[i + 3];
                            end
                        end
		end
	    endcase
	end  
    end



    /* Internal array computation */    


    // AND, OR, XOR, WIRED-OR, NAND, NOR, XNOR
    always_comb begin
        for (int row = 0; row < bytes; row=row+4) begin
            // AND ARRAY
            mem_and[row    ] = mem[row    ] & mask[ 0+:8];
            mem_and[row + 1] = mem[row + 1] & mask[ 8+:8];
            mem_and[row + 2] = mem[row + 2] & mask[16+:8];
            mem_and[row + 3] = mem[row + 3] & mask[24+:8];
            // OR ARRAY
            mem_or[row    ]  = mem[row    ] | mask[ 0+:8];
            mem_or[row + 1]  = mem[row + 1] | mask[ 8+:8];
            mem_or[row + 2]  = mem[row + 2] | mask[16+:8];
            mem_or[row + 3]  = mem[row + 3] | mask[24+:8];
            // XOR ARRAY
            mem_xor[row    ] = mem[row    ] ^ mask[ 0+:8];
            mem_xor[row + 1] = mem[row + 1] ^ mask[ 8+:8];
            mem_xor[row + 2] = mem[row + 2] ^ mask[16+:8];
            mem_xor[row + 3] = mem[row + 3] ^ mask[24+:8];
            // WIRED-OR ARRAY
            word_wired_or[row  ] = ( | ({mem[row+3], mem[row+2], mem[row+1], mem[row  ]} & mask) );
            word_wired_or[row+1] = ( | ({mem[row+3], mem[row+2], mem[row+1], mem[row  ]} & mask) );
            word_wired_or[row+2] = ( | ({mem[row+3], mem[row+2], mem[row+1], mem[row  ]} & mask) );
            word_wired_or[row+3] = ( | ({mem[row+3], mem[row+2], mem[row+1], mem[row  ]} & mask) );
            // WRITE-IN ARRAY
            unique case (logic_in_memory_funct_int)
                FUNCT_AND: begin
                        mem_in[row  ] = mem_and[row  ];
                        mem_in[row+1] = mem_and[row+1];
                        mem_in[row+2] = mem_and[row+2];
                        mem_in[row+3] = mem_and[row+3];
		end
                FUNCT_OR: begin
                        mem_in[row  ] = mem_or[row  ];
                        mem_in[row+1] = mem_or[row+1];
                        mem_in[row+2] = mem_or[row+2];
                        mem_in[row+3] = mem_or[row+3];
		end
                FUNCT_XOR: begin
                        mem_in[row  ] = mem_xor[row  ];
                        mem_in[row+1] = mem_xor[row+1];
                        mem_in[row+2] = mem_xor[row+2];
                        mem_in[row+3] = mem_xor[row+3];
		end
				FUNCT_NOR: begin
                        mem_in[row  ] = ~(mem_or[row  ]);
                        mem_in[row+1] = ~(mem_or[row+1]);
                        mem_in[row+2] = ~(mem_or[row+2]);
                        mem_in[row+3] = ~(mem_or[row+3]);
		end
				FUNCT_NAND: begin
                        mem_in[row  ] = ~(mem_and[row  ]);
                        mem_in[row+1] = ~(mem_and[row+1]);
                        mem_in[row+2] = ~(mem_and[row+2]);
                        mem_in[row+3] = ~(mem_and[row+3]);
		end
				FUNCT_XNOR: begin
                        mem_in[row  ] = ~(mem_xor[row  ]);
                        mem_in[row+1] = ~(mem_xor[row+1]);
                        mem_in[row+2] = ~(mem_xor[row+2]);
                        mem_in[row+3] = ~(mem_xor[row+3]);
		end

                default: begin
			            mem_in[row  ] = wdata_b_i[ 0+:8];
                        mem_in[row+1] = wdata_b_i[ 8+:8];
                        mem_in[row+2] = wdata_b_i[16+:8];
                        mem_in[row+3] = wdata_b_i[24+:8];
		end
            endcase
        end
    end

`elsif STD_MEM //standard memory array


    /* Write Logic - Data part */

    always @(posedge clk_i) begin
        if (en_b_i && we_b_i) begin // DATA MEMORY PART  
            for (int row=0; row<bytes; row++) begin
                if(word_lines_std_mem[row]) mem[row] <= mem_in[row];
            end
        end
    end


    /* Read logic */
    always_ff @(posedge clk_i) begin
	    if (en_b_i && !we_b_i) begin
            for (int i=0; i<bytes; i=i+4) begin
                   if( word_lines_std_mem[i] ) begin
                       rdata_b_o[ 7: 0] <= mem[i    ];
                       rdata_b_o[15: 8] <= mem[i + 1];
                       rdata_b_o[23:16] <= mem[i + 2];
                       rdata_b_o[31:24] <= mem[i + 3];
                   end
		     end
        end
    end

    /* Write in array */
    always_comb begin
        for (int row = 0; row < bytes; row=row+4) begin
            mem_in[row  ] = wdata_b_i[ 0+:8];
            mem_in[row+1] = wdata_b_i[ 8+:8];
            mem_in[row+2] = wdata_b_i[16+:8];
            mem_in[row+3] = wdata_b_i[24+:8];
        end
    end

	
`endif



`ifdef LIM_MEM   

    //======================================================================
    // MIN-MAX LOGIC
    //======================================================================

// MIN-MAX LOGIC
    /* constant vectors */
    always_comb begin
        for (int i=0; i<bytes; i++) begin
            word_wired_zeros[i] = 1'b0;
            word_wired_ones[i]  = 1'b1;
        end
    end

    /* result_wired_or logic */
    always_comb begin
        unique case (opcode_mem) 
            FUNCT_MAX: begin // Disabled row will show wired-or result equal to 0
                for (int i = 0; i < bytes; i++) begin
                    result_word_wired_or[i] = word_wired_or[i] && enabled_rows[i];
                end
            end

            FUNCT_MIN: begin // Disabled row will show wired-or result equal to 1
                for (int i = 0; i < bytes; i++) begin
                    result_word_wired_or[i] = word_wired_or[i] || !enabled_rows[i];
                end
            end
    
            default: begin
                for (int i = 0; i < bytes; i++) begin
                    result_word_wired_or[i] = word_wired_or[i];
                end
            end
        endcase
    end
    
    /* enabled_rows logic */
    always @(posedge clk_i) begin
        enabled_rows <= next_enabled_rows;
    end

    always_comb begin
        for (int i=0; i<bytes; i++) begin
            next_enabled_rows[i] = '0;
        end

        if (en_b_int) begin
            // Initaliase enabled_rows
            if (start_maxmin) begin
                for (int i=0; i<bytes; i++) begin //only data memory part
                    next_enabled_rows[i] = word_lines_std_mem[i];
                end
            // Update enabled_rows
            end else begin
                unique case (opcode_mem) 
                    FUNCT_MAX: begin
                        if (result_word_wired_or == word_wired_zeros || result_word_wired_or == word_wired_ones) begin // do not update the enable
                            next_enabled_rows = enabled_rows;
                        end
                        else begin
                            for (int i = 0; i < bytes; i=i+4) begin
                                if (enabled_rows[i]) begin // enable for the entire word (32-bit) is updated
                                    next_enabled_rows[i  ] = result_word_wired_or[i];
                                    next_enabled_rows[i+1] = result_word_wired_or[i];
                                    next_enabled_rows[i+2] = result_word_wired_or[i];
                                    next_enabled_rows[i+3] = result_word_wired_or[i];
                                end
                            end                             
                        end
                    end  

                    FUNCT_MIN: begin
                        if (result_word_wired_or == word_wired_zeros || result_word_wired_or == word_wired_ones) begin // do not update the enable
                            next_enabled_rows = enabled_rows;
                        end
                        else begin
                            for (int i = 0; i < bytes; i=i+4) begin
                                if (enabled_rows[i]) begin // enable for the entire word (32-bit) is updated
                                    next_enabled_rows[i  ] = !result_word_wired_or[i];
                                    next_enabled_rows[i+1] = !result_word_wired_or[i];
                                    next_enabled_rows[i+2] = !result_word_wired_or[i];
                                    next_enabled_rows[i+3] = !result_word_wired_or[i];
                                end
                            end                             
                        end
                    end 
 
                    default: begin
                        for (int i=0; i<bytes; i++) begin
                            next_enabled_rows[i] = '0; 
                        end
                    end
                endcase
            end
        end
    end

`endif











    //======================================================================
    // MASK LOGIC
    //======================================================================
    
`ifdef RT_LIM_MEM    //racetrack memory part

        assign   mask = wdata_b_int;	//takes the mask from wdata_b_int 

`elsif LIM_MEM           //std. memory part
        
        always @(posedge clk_i, negedge rst_ni) begin
            if ( !rst_ni ) begin
                mask_count <= '0;
            end else if ( (opcode_mem==FUNCT_MAX || opcode_mem==FUNCT_MIN) && en_b_int && !we_b_funct_mem ) begin
                if (start_maxmin) begin
                    mask_count <= 2**31;
                end
                else begin
                    mask_count <= mask_count/2;
                end;
            end
         end

        assign stop_maxmin_iteration = mask_count[0];
    
        always_comb begin
            mask = wdata_b_int;
            if( (opcode_mem==FUNCT_MAX || opcode_mem==FUNCT_MIN) && en_b_int && !we_b_funct_mem ) begin
                mask = mask_count;
            end
        end   

`endif

        
 
    //======================================================================
    // Debug memory parts
    //======================================================================
`ifndef SYNTHESIS
`ifdef DEBUG
`ifdef RT_LIM_MEM

    localparam                       N_VECTOR = 32;
    logic                            sub_word_lines[4*N_VECTOR];
    logic [7:0]                      sub_mem[4*N_VECTOR];
    logic                            sub_word_lines_int[4*N_VECTOR];


    always_comb begin
        for (int i=0; i<4*N_VECTOR; i++) begin 
            sub_mem[i]            = mem['h30000+i]; //h30000 = 196608
            sub_word_lines[i]     = word_lines['h5dc+i];		

            sub_word_lines_int[i] = word_lines_int['h30000+i];
        end
    end
`elsif LIM_MEM

    localparam                       N_VECTOR = 32;
    logic                            sub_word_lines[4*N_VECTOR];
    logic [7:0]                      sub_mem[4*N_VECTOR];
    logic [7:0]                      sub_mem_and[4*N_VECTOR];	
    logic                            sub_enabled_rows[4*N_VECTOR];
    logic                            sub_word_wired_or[4*N_VECTOR];
    logic                            sub_word_lines_int[4*N_VECTOR];
    logic                            found;
    logic [31:0]                     found_content;

    always_comb begin
        for (int i=0; i<4*N_VECTOR; i++) begin
            sub_mem[i]            = mem['h30000+i];
			sub_mem_and[i]        = mem_and['h30000+i];
            sub_enabled_rows[i]   = enabled_rows['h30000+i];
            sub_word_wired_or[i]  = word_wired_or['h30000+i];
            sub_word_lines[i]     = word_lines_std_mem['h30000+i];
            sub_word_lines_int[i] = word_lines_std_mem_int['h30000+i];
        end
    end

    always_comb begin
        found = 1'b0;
        for (int i=0; i<bytes; i=i+4) begin
           if( enabled_rows[i] ) begin
               found         = 1'b1;
               found_content = {mem[i+3], mem[i+2], mem[i+1], mem[i]};
           end
        end
    end

`endif
`endif
`endif

endmodule // dp_ram_logic
