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

     input  logic                          en_a_i,
     input  logic [ADDR_WIDTH-1:0]         addr_a_i,
     input  logic [31:0]                   wdata_a_i,
     output logic [INSTR_RDATA_WIDTH-1:0]  rdata_a_o,
     input  logic                          we_a_i,
     input  logic [3:0]                    be_a_i,

     input  logic                          en_b_i,
     input  logic [ADDR_WIDTH-1:0]         addr_b_i,
     input  logic [31:0]                   wdata_b_i,
     output logic [31:0]                   rdata_b_o,
     input  logic                          we_b_i,
     input  logic [3:0]                    be_b_i,
     input  logic                          gnt_b_i,
     output logic                          rvalid_b_o
    );

    localparam bytes = 2**ADDR_WIDTH;
    localparam LOGIC_MEM_FUNCT_ADDRESS = (bytes/32-4);

    // Normal memory
    logic [7:0]                      mem[bytes];
    logic [ADDR_WIDTH-1:0]           addr_a_int;
    logic [ADDR_WIDTH-1:0]           addr_b_int;
 
    // Logic-in-memory
    logic [ADDR_WIDTH-1:0]           asize_mem_int;
    logic [ADDR_WIDTH-1:0]           addr_b_range_end;
    logic                            en_b_int;
    logic [31:0]                     wdata_b_int;
    logic                            en_b_maxmin_valid;
    logic                            en_b_maxmin_q;  
    logic [31:0]                     wdata_b_maxmin_q;
    logic                            en_b_maxmin_valid_q;
    logic [ADDR_WIDTH-1:0]           addr_b_maxmin_q;
    logic                            enabled_rows[bytes];
    logic                            next_enabled_rows[bytes];
    logic                            word_wired_or[bytes];
    logic                            result_word_wired_or[bytes];
    logic                            word_wired_zeros[bytes];
    logic                            word_wired_ones[bytes];
    logic [7:0]                      mem_and[bytes];
    logic [7:0]                      mem_or[bytes];
    logic [7:0]                      mem_not[bytes];
    logic [7:0]                      mem_xor[bytes];
    logic [7:0]                      mem_in[bytes];
    logic                            word_lines[bytes];
    logic                            word_lines_int[bytes];
    logic                            decoder_range_init[bytes];
    logic                            decoder_range_end[bytes];
    logic                            range_active;
    logic [31:0]                     mask;
    logic [31:0]                     mask_count;
    logic [2:0]                      logic_in_memory_funct_int;
    logic [31:0]                     logic_in_memory_funct;
    logic [28:0]                     asize_mem;
    logic                            we_b_funct_mem;
    logic                            start_maxmin;
    logic                            stop_maxmin_iteration;
    logic [2:0]                      opcode_mem;

    always_comb addr_a_int = {addr_a_i[ADDR_WIDTH-1:2], 2'b0};
    
    always_comb asize_mem_int = {asize_mem[ADDR_WIDTH-1:0], 2'b0}; // Only 32 bits words are considered as vector elements

    //======================================================================
    // HANDSHAKING PROTOCOL
    //====================================================================== 
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

    assign rvalid_b_o          = (en_b_maxmin_valid_q || en_b_maxmin_valid ) ? stop_maxmin_iteration  : gnt_b_i; 

    //======================================================================
    // ADDRESS DECODER
    //====================================================================== 
    // RANGE DECODER
    /* Normal decoder - Initial address decoder*/
    always_comb begin
        for (int i=0; i<bytes; i++) begin
            decoder_range_init[i] = 1'b0;
        end
        decoder_range_init[addr_b_int] = 1'b1;
    end

    /* Final address decoder */
    assign range_active = en_b_int && (asize_mem != 0 && asize_mem != 1) && !we_b_funct_mem;  
 
    assign addr_b_range_end = addr_b_int + asize_mem_int;

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
            word_lines_int[i] = decoder_range_init[i] | decoder_range_end[i]; // In the range case, only two bits are equal to 1. In the single case, just one
            word_lines[i]     = decoder_range_init[i];
        end
     
        // Range operation: possible only on words (32 bits)
        if (range_active) begin
            word_lines_int[0] = 1'b0;
            word_lines_int[1] = 1'b0;
            word_lines_int[2] = 1'b0;
            word_lines_int[3] = 1'b0;
            for (int i=4; i<bytes; i=i+4) begin
                word_lines[i    ] = (word_lines_int[i] & !word_lines[i-4]) | (!word_lines_int[i] & word_lines[i-4]);
                word_lines[i + 1] = (word_lines_int[i] & !word_lines[i-4]) | (!word_lines_int[i] & word_lines[i-4]);
                word_lines[i + 2] = (word_lines_int[i] & !word_lines[i-4]) | (!word_lines_int[i] & word_lines[i-4]);
                word_lines[i + 3] = (word_lines_int[i] & !word_lines[i-4]) | (!word_lines_int[i] & word_lines[i-4]);
            end
        end
        // Single case: possible on bytes (8 bits), half-words (16 bits) and words (32 bits)
        else begin
            for (int i=0; i<bytes; i=i+4) begin
                word_lines[i  ] = be_b_i[0] && word_lines_int[i];
                word_lines[i+1] = be_b_i[1] && word_lines_int[i];
                word_lines[i+2] = be_b_i[2] && word_lines_int[i];
                word_lines[i+3] = be_b_i[3] && word_lines_int[i];
            end
        end 
    end 

    //======================================================================
    // WRITE MEMORY LOGIC
    //====================================================================== 
    always @(posedge clk_i) begin
        if (en_b_int && we_b_i) begin // DATA MEMORY PART  
            for (int row=0; row<bytes; row++) begin
                if(word_lines[row]) mem[row] <= mem_in[row];
            end
        end
    end

    assign we_b_funct_mem = (addr_b_int == LOGIC_MEM_FUNCT_ADDRESS);

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
	
    // DATA PART
    always_ff @(posedge clk_i) begin
	if (en_b_int && !we_b_i) begin
	    unique case (logic_in_memory_funct_int)
		FUNCT_AND: begin
                        for (int i=0; i<bytes; i=i+4) begin
                            if( word_lines[i] ) begin
                                rdata_b_o[ 7: 0] <= mem_and[i    ];
			        rdata_b_o[15: 8] <= mem_and[i + 1];
			        rdata_b_o[23:16] <= mem_and[i + 2];
			        rdata_b_o[31:24] <= mem_and[i + 3];
                            end
                        end	
		end
		
		FUNCT_OR: begin
                        for (int i=0; i<bytes; i=i+4) begin
                            if( word_lines[i] ) begin
                                rdata_b_o[ 7: 0] <= mem_or[i    ];
			        rdata_b_o[15: 8] <= mem_or[i + 1];
			        rdata_b_o[23:16] <= mem_or[i + 2];
			        rdata_b_o[31:24] <= mem_or[i + 3];
                            end
                        end
		end
		
		FUNCT_XOR: begin
                        for (int i=0; i<bytes; i=i+4) begin
                            if( word_lines[i] ) begin
                                rdata_b_o[ 7: 0] <= mem_xor[i    ];
			        rdata_b_o[15: 8] <= mem_xor[i + 1];
			        rdata_b_o[23:16] <= mem_xor[i + 2];
			        rdata_b_o[31:24] <= mem_xor[i + 3];
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
                            if( word_lines[i] ) begin
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

    //======================================================================
    // LOGIC-IN-MEMORY
    //======================================================================
    // LOGIC-IN-MEMORY FUNCT CELL
    // Register that shows the same value of the FUNCT CELL, except for the beginning because of the reset
    always_ff @(posedge clk_i, negedge rst_ni) begin
        if (!rst_ni) begin
            logic_in_memory_funct <= '0;
        end
        else if (en_b_int && we_b_i && addr_b_int == LOGIC_MEM_FUNCT_ADDRESS) begin
            logic_in_memory_funct <= wdata_b_i;
        end
    end

    assign opcode_mem   = logic_in_memory_funct[2:0];
    assign asize_mem    = logic_in_memory_funct[31:3];

    // AND, OR, XOR, WIRED-OR
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
                default: begin
			mem_in[row  ] = wdata_b_i[ 0+:8];
                        mem_in[row+1] = wdata_b_i[ 8+:8];
                        mem_in[row+2] = wdata_b_i[16+:8];
                        mem_in[row+3] = wdata_b_i[24+:8];
		end
            endcase
        end
    end
    
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
                    next_enabled_rows[i] = word_lines[i];
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

    // MASK LOGIC
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
 
    //======================================================================
    // Debug memory parts
    //======================================================================
`ifndef SYNTHESIS
`ifdef DEBUG
    localparam                       N_VECTOR = 32;
    logic                            sub_word_lines[4*N_VECTOR];
    logic [7:0]                      sub_mem[4*N_VECTOR];
    logic                            sub_enabled_rows[4*N_VECTOR];
    logic                            sub_word_wired_or[4*N_VECTOR];
    logic                            sub_word_lines_int[4*N_VECTOR];
    logic                            found;
    logic [31:0]                     found_content;

    always_comb begin
        for (int i=0; i<4*N_VECTOR; i++) begin
            sub_mem[i]            = mem['h30000+i];
            sub_enabled_rows[i]   = enabled_rows['h30000+i];
            sub_word_wired_or[i]  = word_wired_or['h30000+i];
            sub_word_lines[i]     = word_lines['h30000+i];
            sub_word_lines_int[i] = word_lines_int['h30000+i];
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

endmodule // dp_ram_logic
