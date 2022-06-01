
import riscv_defines::*;
`define DEBUG

module dummy_RT
 #(parameter ADDR_WIDTH = 10,
   parameter bytes = 1024
  )
  (
    input  logic						  clk_i,
	input  logic                          rst_ni,
	input  logic						  en_b_int_i, 
	input  logic						  we_b_i, //write enable
	input  logic [bytes-1:0]  			  word_lines_i,	//packed
	input  logic [2:0]                    opcode_mem_i, //Logic function after masking 
	input  logic [31:0]					  mask_i,
	input  logic [31:0]					  wdata_b_i,

	output logic [31:0]                   rdata_b_o,
	output logic                          rvalid_rt_o
 );



	enum {IDLE,PORT_SET,READ,WRITE, PORT_RESET, LIM_WAIT, LIM_WRITE, LIM_READ } state, next_state;	



	localparam WAIT_LIM_CYCLES = 3;	//wait cycles to mimic racetrack programming

	//dummy Racetrack Data memory array


	 logic [7:0]                      RT_mem[bytes];	//memory array
	 logic [7:0]                      mem_and[bytes]; 	//array for AND operations
	 logic [7:0]                      mem_or [bytes]; 	//array for OR operations
     logic [7:0]                      mem_xor[bytes]; 	//array for XOR operations
     logic [7:0]                      mem_in[bytes];	//array di feedback per scrivere i risultati delle operazioni logiche interne
	 logic 							  en_write;	     	//control signal given by FSM, enables data write
	 logic							  en_read;		 	//control signal given by FSM, enables data read
	 logic							  lim_done;			//wait LIM_CYCLES to emulate pNML racetrack's latency
	 logic	[3:0]					  cnt_lim;			//signal for LiM programming counter
	 logic							  cnt_init;			//load signal for LiM programming counter


    //======================================================================
    // WRITE MEMORY LOGIC
    //====================================================================== 
    always @(posedge clk_i) begin
        if (en_write) begin //enable set by FSM
            for (int row=0; row<bytes; row++) begin
                if(word_lines_i[row]) RT_mem[row] <= mem_in[row]; //write if the wordline is active
            end
        end
    end
	

	//======================================================================
    // READ MEMORY LOGIC
    //======================================================================


	// DATA PART						//questo è il mux finale in uscita, il register lo salva dopo aver fatto la scelta
    always_ff @(posedge clk_i) begin
	if (en_read) begin	//enable set by FSM
	    unique case (opcode_mem_i)
		FUNCT_AND: begin												//le codifiche FUNCT_<operation> sono in riscv_define (in rtl/include)
                        for (int i=0; i<bytes; i=i+4) begin
                            if( word_lines_i[i] ) begin
                                rdata_b_o[ 7: 0] <= mem_and[i    ];
								rdata_b_o[15: 8] <= mem_and[i + 1];
								rdata_b_o[23:16] <= mem_and[i + 2];
								rdata_b_o[31:24] <= mem_and[i + 3];
                            end
                        end	
		end
		
		FUNCT_OR: begin
                        for (int i=0; i<bytes; i=i+4) begin
                            if( word_lines_i[i] ) begin
                                rdata_b_o[ 7: 0] <= mem_or[i    ];
								rdata_b_o[15: 8] <= mem_or[i + 1];
								rdata_b_o[23:16] <= mem_or[i + 2];
								rdata_b_o[31:24] <= mem_or[i + 3];
                            end
                        end
		end
		
		FUNCT_XOR: begin
                        for (int i=0; i<bytes; i=i+4) begin
                            if( word_lines_i[i] ) begin
                                rdata_b_o[ 7: 0] <= mem_xor[i    ];
								rdata_b_o[15: 8] <= mem_xor[i + 1];
								rdata_b_o[23:16] <= mem_xor[i + 2];
								rdata_b_o[31:24] <= mem_xor[i + 3];
                            end
                        end
		end
		
	//	FUNCT_MAX, FUNCT_MIN : begin
	//		if ( stop_maxmin_iteration ) begin
    //                        for(int i=0; i<bytes; i=i+4) begin
    //                            if( next_enabled_rows[i] ) begin
	//							rdata_b_o[ 7: 0] <= RT_mem[i    ];
	//							rdata_b_o[15: 8] <= RT_mem[i + 1];
	//							rdata_b_o[23:16] <= RT_mem[i + 2];
	//							rdata_b_o[31:24] <= RT_mem[i + 3];
    //                           end
    //                        end
    //                    end
	//	end
		
		default: begin
			for (int i=0; i<bytes; i=i+4) begin
                            if( word_lines_i[i] ) begin
                                rdata_b_o[ 7: 0] <= RT_mem[i    ];
								rdata_b_o[15: 8] <= RT_mem[i + 1];
								rdata_b_o[23:16] <= RT_mem[i + 2];
								rdata_b_o[31:24] <= RT_mem[i + 3];
                            end
                        end
		end
		
		
		
	    endcase
	end  
    end


	// AND, OR, XOR, WIRED-OR
    always_comb begin
        for (int row = 0; row < bytes; row=row+4) begin			//esegue queste operazioni per ogni funzione, qua usa la maschera con le operazioni e scrive 
            // AND ARRAY										//nei corrispettivi segnali mem_and, mem_row etc
            mem_and[row    ] = RT_mem[row    ] & mask_i[ 0+:8];		//sono fatte 4 a 4 èer garantire anche l'output per misaligned accesses
            mem_and[row + 1] = RT_mem[row + 1] & mask_i[ 8+:8];
            mem_and[row + 2] = RT_mem[row + 2] & mask_i[16+:8];
            mem_and[row + 3] = RT_mem[row + 3] & mask_i[24+:8];
            // OR ARRAY
            mem_or[row    ]  = RT_mem[row    ] | mask_i[ 0+:8];
            mem_or[row + 1]  = RT_mem[row + 1] | mask_i[ 8+:8];
            mem_or[row + 2]  = RT_mem[row + 2] | mask_i[16+:8];
            mem_or[row + 3]  = RT_mem[row + 3] | mask_i[24+:8];
            // XOR ARRAY
            mem_xor[row    ] = RT_mem[row    ] ^ mask_i[ 0+:8];
            mem_xor[row + 1] = RT_mem[row + 1] ^ mask_i[ 8+:8];
            mem_xor[row + 2] = RT_mem[row + 2] ^ mask_i[16+:8];
            mem_xor[row + 3] = RT_mem[row + 3] ^ mask_i[24+:8];

            // WIRED-OR ARRAY (NOT IMPLEMENTED NOW)
           // word_wired_or[row  ] = ( | ({RT_mem[row+3], RT_mem[row+2], RT_mem[row+1], RT_mem[row  ]} & mask_i) );
           // word_wired_or[row+1] = ( | ({RT_mem[row+3], RT_mem[row+2], RT_mem[row+1], RT_mem[row  ]} & mask_i) );
           // word_wired_or[row+2] = ( | ({RT_mem[row+3], RT_mem[row+2], RT_mem[row+1], RT_mem[row  ]} & mask_i) );
           // word_wired_or[row+3] = ( | ({RT_mem[row+3], RT_mem[row+2], RT_mem[row+1], RT_mem[row  ]} & mask_i) );


            // WRITE-IN ARRAY
       unique case (opcode_mem_i)		//Write back in the array, con FUNCT_<op_type> sceglie cosa scrivere all'indietro
                FUNCT_AND: begin
                        mem_in[row  ] = mem_and[row  ];	//per ogni caso scrivi all'indietro dentro la cella di memoria nel feedback array mem_in
						mem_in[row+1] = mem_and[row+1];	//la scrittura vera e propria avviene con il registro (vedi sopra)
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
						mem_in[row  ] = wdata_b_i[ 0+:8];				//caso default scrivi dato che viene da fuori
                        mem_in[row+1] = wdata_b_i[ 8+:8];
                        mem_in[row+2] = wdata_b_i[16+:8];
                        mem_in[row+3] = wdata_b_i[24+:8];
		end
            endcase
        end
    end



	//===============================
	//FSM
	//===============================


	//STATE REGISTERS
	always_ff @(posedge clk_i, negedge rst_ni) begin
		if(!rst_ni) begin
			state <= IDLE;
		end
		else begin
			state<= next_state;
		end
	end


	//STATE TRANSITION

	always_comb begin
		unique case(state)

			IDLE: begin			
	
				if(en_b_int_i) begin
					next_state = PORT_SET;
				end else begin
					next_state = IDLE;
				end

			end

			PORT_SET: begin	
	
				
				if(opcode_mem_i == FUNCT_AND || opcode_mem_i == FUNCT_OR) begin
					 next_state = LIM_WAIT;
				end else begin					
					if(we_b_i) begin
						next_state = WRITE;
					end else begin
						next_state = READ;
					end
				end				
			end
			
			READ: begin
				next_state = PORT_RESET;
			end
			
			WRITE: begin
				next_state = PORT_RESET;
			end


			LIM_WAIT: begin
				if(lim_done) begin
					if(we_b_i) begin
						next_state = WRITE;
					end else begin
						next_state = READ;
					end
				end else begin
					next_state = LIM_WAIT;
				end
			end


			LIM_READ: begin
				next_state = PORT_RESET;
			end


			LIM_WRITE: begin
				next_state = PORT_RESET;
			end


			PORT_RESET: begin						
				if(en_b_int_i) begin
					next_state = PORT_SET;
				end else begin
					next_state = IDLE;
				end
			end
			

		endcase

	end


	//OUTPUT DECODE
	always_comb begin
		unique case(state)
			IDLE: begin
				
				en_read				= 1'b0;
				en_write			= 1'b0;
				rvalid_rt_o			= 1'b0;
				cnt_init			= 1'b0;
			end

			PORT_SET: begin			//NEW
				
				en_read				= 1'b0;
				en_write			= 1'b0;	
				rvalid_rt_o			= 1'b0;
				cnt_init			= 1'b1;	//load cycles in the counter
			end
			
			WRITE: begin
				
				en_read				= 1'b0;
				en_write			= 1'b1;	//in the RT there is here the write operation, so valid signal is high here to allow port reset
				rvalid_rt_o			= 1'b1;
				cnt_init			= 1'b0;
			end
			
			READ: begin
				
				en_read				= 1'b1;
				en_write			= 1'b0;
				rvalid_rt_o			= 1'b1;	//valid signal is high here to allow port reset
				cnt_init			= 1'b0;
			end

			LIM_WAIT: begin
				
				en_read				= 1'b0;
				en_write			= 1'b0;
				rvalid_rt_o			= 1'b0;
				cnt_init			= 1'b0;
			end


			LIM_READ: begin
				
				en_read				= 1'b1;
				en_write			= 1'b0;
				rvalid_rt_o			= 1'b1;	//valid signal is high here to allow port reset
				cnt_init			= 1'b0;
			end


			LIM_WRITE: begin
				
				en_read				= 1'b0;
				en_write			= 1'b1;	//in the RT there is here the write operation, so valid signal is high here to allow port reset
				rvalid_rt_o			= 1'b1;
				cnt_init			= 1'b0;
			end



			
			PORT_RESET: begin
				
				en_read				= 1'b0;
				en_write			= 1'b0;
				rvalid_rt_o			= 1'b0;
				cnt_init			= 1'b1;
			end




		endcase
	end


	//===============================
	//LIM POGRAMMING COUNT CYCLES
	//===============================
	
	//wait some cycles for LiM operation
	
	always_ff @(posedge clk_i, negedge  rst_ni, posedge cnt_init) begin
		if(!rst_ni) begin	
			cnt_lim <= '0;
		end else if(cnt_init)	//initialize counter during PORT_SET
			cnt_lim <= (WAIT_LIM_CYCLES);
		else begin
			cnt_lim<= cnt_lim - 1;
		end
	end
	
	//comparator
	always_comb begin
	lim_done = 1'b0;
		if(cnt_lim == 0) begin
			lim_done = 1'b1;
		end
	end










endmodule	//dummy_RT
