import riscv_defines::*;

module FSM
	#( parameter N_WIDTH = 22,
	   parameter CNT_WIDTH = 10
	)
	(
		input  logic 					clk_i,								//FSM clock
		input  logic					rstn_i,
		input  logic					en_i,			
		input  logic					shift_done_s_i, 					//notifies completion of set shifts
		input  logic					shift_done_r_i, 					//notifies completion of reset shifts
		input  logic					w_en_i,								//write enable from outside
		input  logic [3:0]				be_b_i,			    				//byte selector signal
		input  logic [7:0]				logic_in_memory_funct_int_i,		//logic in memory functionality
		
		output logic					shift_en_s_o,						//enable for set shifter
		output logic					shift_en_r_o,						//enable for reset shifter
						
		output logic					shift_select_o,						//enable shift pulses
		output logic					w_en_d_o,							//write enable for data 
		output logic					w_en_m_o,							//write enable for mask
		output logic					w_en_p_o,							//write enable for program racetrack	
		output logic					r_en_o,								//read enagle for logic & data 
		output logic					shift_s_o,							//shift direction
		output logic					r_valid_o,							//valid signal for read/write data
		output logic					NAND_NOR_o,							//select signal for LiM operation
		
		
		output logic					Bz_m_o,								//Bz field module
		output logic					out_select_o,						//select data or LiM data for block output
		output logic					source_shift_sel_o,					//selection signal source shift mux
		output logic					en_ff_read_o,						//enable for external FF data stabilyzer
		output logic					en_lim_buf_o						//enable signal for data buffer during byte write LiM
	);

	
	enum {IDLE,PORT_SET,READ,WRITE, WRITE_MASK_NAND, WRITE_MASK_NOR , LIM_NOR, LIM_NAND, READ_LIM, WRITE_LIM, PORT_RESET} state, next_state;
	
	logic	[3:0]	cnt_lim;		//signal for LiM programming counter
	logic			lim_done;		//notifies end of LiM oeperation
	logic			r_en_byteW;		//read enable signal for write byte
	logic			r_en_feedbackW;	//read enable signal for feedback write
	

	//===============================
	//FSM
	//===============================


	//STATE REGISTERS
	always_ff @(posedge clk_i, negedge rstn_i) begin
		if(!rstn_i) begin
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
	
				if(en_i) begin
					next_state = PORT_SET;
				end else begin
					next_state = IDLE;
				end

			end
			
			PORT_SET: begin
			
				if(shift_done_s_i)begin
					if(w_en_i) begin
						unique case(logic_in_memory_funct_int_i)
							
							 FUNCT_AND	:  next_state = WRITE_MASK_NAND;   
							 FUNCT_OR	:  next_state = WRITE_MASK_NOR;   
							 FUNCT_NAND :  next_state = WRITE_MASK_NAND;   
							 FUNCT_NOR  :  next_state = WRITE_MASK_NOR;   
							
							default: next_state = WRITE;	//go in WRITE only in NULL and XOR cases
						endcase
					end else begin
						unique case(logic_in_memory_funct_int_i)
							
							 FUNCT_AND  :  next_state = WRITE_MASK_NAND;  
							 FUNCT_OR   :  next_state = WRITE_MASK_NOR;  
							 FUNCT_NAND :  next_state = WRITE_MASK_NAND;   
							 FUNCT_NOR  :  next_state = WRITE_MASK_NOR;   
							
							default: next_state = READ;	//go in READ only in NULL and XOR cases
						endcase
					end
				end else begin
					next_state = PORT_SET;
				end
				
				
			end
			
			READ: begin
				next_state = PORT_RESET;
			end
			
			WRITE: begin
				next_state = PORT_RESET;
			end

			WRITE_MASK_NAND: begin	
				next_state = LIM_NAND;
			end
			WRITE_MASK_NOR: begin
				 next_state = LIM_NOR;
			end
			
			
			LIM_NAND: begin
				if(lim_done)begin
					if(w_en_i) begin
						next_state = WRITE_LIM;
					end else begin
						next_state = READ_LIM;
					end
				end else begin
					next_state = LIM_NAND;	//wait LiM programming
				end
			end
			
			LIM_NOR: begin
				if(lim_done)begin
					if(w_en_i) begin
						next_state = WRITE_LIM;
					end else begin
						next_state = READ_LIM;
					end
				end else begin
					next_state = LIM_NOR;	//wait LiM programming
				end
			end
			
			
			READ_LIM: begin
				next_state = PORT_RESET;
			end
			
			WRITE_LIM: begin
				next_state = PORT_RESET;
			end
			

			PORT_RESET: begin
			
				if(shift_done_r_i)begin
					if(en_i)begin		//serve a new memory request without passing from IDLE state
						next_state = PORT_SET;
					end else begin
						next_state = IDLE;
					end
				end else begin
					next_state = PORT_RESET;
				end
			end

		endcase

	end

	//OUTPUT DECODE
	always_comb begin
		unique case(state)
			IDLE: begin
				
				shift_en_s_o		= 0;
				shift_en_r_o		= 0;
				shift_select_o		= 0;
				shift_s_o			= 1; //select left value
				w_en_d_o			= 0;
				w_en_m_o			= 0;
				r_en_o				= 0;
				r_valid_o			= 0;
				NAND_NOR_o			= 0;
				Bz_m_o				= 0;
				out_select_o		= 0; //std out is data
				source_shift_sel_o	= 0;
				en_ff_read_o		= 0;
				en_lim_buf_o		= 0;
				w_en_p_o			= 0;
			end
			
			PORT_SET: begin
				
				shift_en_s_o		= 1;
				shift_en_r_o		= 0;
				shift_select_o		= 1;
				shift_s_o			= 1;
				w_en_d_o			= 0;
				w_en_m_o			= 0;
				r_en_o				= 0;
				r_valid_o			= 0;
				NAND_NOR_o			= 0;
				Bz_m_o				= 0;
				out_select_o		= 0;
				source_shift_sel_o	= 0;
				en_ff_read_o		= 0;
				en_lim_buf_o		= 0;
				w_en_p_o			= 0;
			end
			
			READ: begin
				
				shift_en_s_o		= 0;
				shift_en_r_o		= 0;
				shift_select_o		= 0;
				shift_s_o			= 1;
				w_en_d_o			= 0;
				w_en_m_o			= 0;
				r_en_o				= 1;
				r_valid_o			= 1;
				NAND_NOR_o			= 0;
				Bz_m_o				= 0;
				out_select_o		= 0;
				source_shift_sel_o	= 0;
				en_ff_read_o		= 1;
				en_lim_buf_o		= 0;
				w_en_p_o			= 0;
			end
			
			WRITE: begin
				
				shift_en_s_o		= 0;
				shift_en_r_o		= 0;
				shift_select_o		= 0;
				shift_s_o			= 0;
				w_en_d_o			= 1;
				w_en_m_o			= 0;
				r_en_o				= 0 || r_en_byteW || r_en_feedbackW;	//override read enable signal during byte write and LiM store
				r_valid_o			= 1; 				//generate valid signal to notify write operation
				NAND_NOR_o			= 0;
				Bz_m_o				= 0;
				out_select_o		= 0;
				source_shift_sel_o	= 0;
				en_ff_read_o		= 0;
				en_lim_buf_o		= 0;
				w_en_p_o			= 0;
				
			end
			
			WRITE_MASK_NAND: begin	//write mask from external register	
					
				shift_en_s_o		= 0;	
				shift_en_r_o		= 0;	
				shift_select_o		= 0;			
				shift_s_o			= 0;	
				w_en_d_o			= 0;	
				w_en_m_o			= 1;	//write mask
				r_en_o				= 0 || r_en_byteW || r_en_feedbackW; //override read enable signal during byte write and LiM store (save value in buf)	
				r_valid_o			= 0;	
				NAND_NOR_o			= 1;	
				Bz_m_o				= 0;	
				out_select_o		= 0;	
				source_shift_sel_o	= 0;	
				en_ff_read_o		= 0;	
				en_lim_buf_o		= 1;	//save actual data value
				w_en_p_o			= 1;	//write program bit			
					
			end	
			
			WRITE_MASK_NOR: begin	//write mask from external register
            	
				shift_en_s_o		= 0;
				shift_en_r_o		= 0;	
				shift_select_o		= 0;			
				shift_s_o			= 0;	
				w_en_d_o			= 0;	
				w_en_m_o			= 1;	//write mask
				r_en_o				= 0 || r_en_byteW || r_en_feedbackW; //override read enable signal during byte write and LiM store (save value in buf)	
				r_valid_o			= 0;	
				NAND_NOR_o			= 0;	
				Bz_m_o				= 0;	
				out_select_o		= 0;	
				source_shift_sel_o	= 0;	
				en_ff_read_o		= 0;	
				en_lim_buf_o		= 1;	//save actual data value
				w_en_p_o			= 1;	//write program bit			
					
			end	
					
				
			LIM_NAND: begin	
			
            	shift_en_s_o		= 0;
            	shift_en_r_o		= 0;
            	shift_select_o		= 0;
            	shift_s_o			= 0;
            	w_en_d_o			= 0;
            	w_en_m_o			= 0;
            	r_en_o				= 0;
            	r_valid_o			= 0;
            	NAND_NOR_o			= 1;
            	Bz_m_o				= 1;
            	out_select_o		= 0;
				source_shift_sel_o	= 0;
				en_ff_read_o		= 0;
				en_lim_buf_o		= 0;
				w_en_p_o			= 0;		
				
				
			end	
				
			LIM_NOR: begin	
				
				shift_en_s_o		= 0;	
				shift_en_r_o		= 0;	
				shift_select_o		= 0;	
				shift_s_o			= 0;	
				w_en_d_o			= 0;	
				w_en_m_o			= 0;	
				r_en_o				= 0;	
				r_valid_o			= 0;	
				NAND_NOR_o			= 0;	
				Bz_m_o				= 1;	
				out_select_o		= 0;	
				source_shift_sel_o	= 0;
				en_ff_read_o		= 0;
				en_lim_buf_o		= 0;
				w_en_p_o			= 0;
			end
			
			
			READ_LIM: begin
				
				shift_en_s_o		= 0;
				shift_en_r_o		= 0;
				shift_select_o		= 0;
				shift_s_o			= 1;
				w_en_d_o			= 0;
				w_en_m_o			= 0;
				r_en_o				= 1;
				r_valid_o			= 1;
				NAND_NOR_o			= 0;
				Bz_m_o				= 0;
				out_select_o		= 1;	//select logic output
				source_shift_sel_o	= 0;
				en_ff_read_o		= 1;
				en_lim_buf_o		= 0;
				w_en_p_o			= 0;
			end
			
			WRITE_LIM: begin
				
				shift_en_s_o		= 0;
				shift_en_r_o		= 0;
				shift_select_o		= 0;
				shift_s_o			= 0;
				w_en_d_o			= 1;	//write computed value
				w_en_m_o			= 0;
				r_en_o				= 1; 	//read computed value
				r_valid_o			= 1;
				NAND_NOR_o			= 0;
				Bz_m_o				= 0;
				out_select_o		= 1;	//select logic output
				source_shift_sel_o	= 0;
				en_ff_read_o		= 0;
				en_lim_buf_o		= 0;
				w_en_p_o			= 0;
			end
			
			PORT_RESET: begin
				
				shift_en_s_o		= 0;
				shift_en_r_o		= 1;
				shift_select_o		= 1;
				shift_s_o			= 0;
				w_en_d_o			= 0;
				w_en_m_o			= 0;
				r_en_o				= 0;
				r_valid_o			= 0;
				NAND_NOR_o			= 0;
				Bz_m_o				= 0;
				out_select_o		= 0;
				source_shift_sel_o	= 1; //select sampled n shift
				en_ff_read_o		= 0;
				en_lim_buf_o		= 0;
				w_en_p_o			= 0;
				
			end

		endcase

	end
	
	
	//===============================
	//LIM POGRAMMING COUNT CYCLES
	//===============================
	
	//wait some cycles for LiM operation
	
	always_ff @(posedge clk_i, negedge rstn_i, posedge shift_en_s_o) begin
		if(!rstn_i) begin	
			cnt_lim <= '0;
		end else if(shift_en_s_o)	//initialize counter during PORT_SET
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
	
	
	//===============================
	//WRITE BYTE LOGIC
	//===============================
	//During a byte write, bytes not written are left as they are
	//Un-written values are first read then, re-written in the same place
	always_comb begin
		unique case(be_b_i) 
			
			4'b1111: r_en_byteW = 1'b0; //do not read during a 4byte access
			4'b0000: r_en_byteW = 1'b0;
			
			default: r_en_byteW = 1'b1;
		
		endcase
	end
	
	//===============================
	//FEEDBACK WRITE LOGIC
	//===============================
	//Before a byte write read actual value, only active bytes are overwritten
	always_comb begin
		unique case(logic_in_memory_funct_int_i) 
			
			 FUNCT_NONE:  r_en_feedbackW = 1'b0; //do not read during a standard access (write wdata_i)
			
			
			default: r_en_feedbackW = 1'b1;	//during LiM operations read stored data (useful for LiM store operations)
		
		endcase
	end
	
	
	
	
	
	
endmodule
