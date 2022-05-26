import racetrack_defines::*; //REMOVE AFTER RISC INTEGRATION




module RT_memory
	#(	parameter ADDR_WIDTH = 22,
		parameter MAX_SIZE	 = 1024,   	//max number of bytes		
		parameter CNT_WIDTH  = 2,		//only 2 bits required (max 3 shifts)
		parameter Nr 		 = 4, 		//number of racetrack
		parameter Nb 		 = 32, 		//rcetrack length
		parameter Np 		 = 8,
		parameter NMU 		 = 8,
		parameter NWL		 = 4096,	//random number, set during module instantiation
		parameter MEM_MODE   = 1		//std. mode is LiM
	)
	(
		input  logic 					clk_i,							//FSM clock 
		input  logic					rstn_i,				
	    input  logic					clk_m_i,   						//magnetic clock for shift operation
	    input  logic					Bz_s_i,    						
	    input  logic					en_ab_i,   						//start memory transaction signal
		input  logic [3:0]				be_b_i,							//byte selector signal
	    input  logic					write_pulse_i,					//read current waveform
	    input  logic					read_pulse_i,					//write current waveform
	    input  logic					range_active_i, 				//range active signal
	    input  logic [NWL-1:0]			word_lines,				
	    input  logic [Nr*NMU-1:0]		write_data_i,					//input write data
	    input  logic					write_en_data_i,				//write enable 
	    input  logic [Nr*NMU-1:0]	    mask_i,							//input write mask
		input  logic [7:0]              logic_in_memory_funct_int_i, 	//opcode for LiM operations
		input  logic [1:0]				n_shift_i,     					//takes ADDR's LSBs to generate N of shifts      
		input  logic [2:0]  			word_sel_i,						//word selection signal for std. mem. mode
	    
	    output logic [Nr*NMU-1:0] 		data_o,
	    output logic					valid_o				
	);
	
	
	localparam bytes  = MAX_SIZE;			
	localparam par    = Nr*NMU;						//data parallelism
	localparam words  = bytes/4; 					//number of 32bits words
	localparam blocks = words/Nb;		 
	localparam Nov = Nb - ((Nb/Np)*Np -(Nb/Np))-1;	//N of overhead cells within the racetrack
	localparam Nsp = Nb/Np;							//N of spacing cells within the racetrack
	
	
	  
	logic							shift_done_s;		//done signal for set shifter
	logic							shift_done_r;		//done signal for reset shifter
	logic							shift_en_s;			//init signal for set shifter
	logic							shift_en_r;			//init signal for reset shifter
	logic							shift_select;		//enable shifting
	logic							shift_m;			//shift waveform module
	logic							shift_s;			//shift waveform sign
	logic							w_en_d;	    		//write enable for data  sent to  racetrack
	logic							w_en_m;	    		//write enable for mask  sent to  racetrack
	logic							w_en_p;				////write enable for program racetrack  sent to  racetrack
	logic							w_pulse; 			//write current pulse
	logic							r_en;    			//read enable for data & logic sent to racetrack
	logic							r_pulse_d;			//read current pulse for data/logic
	logic							r_pulse_m;			//read current pulse for mask-data
	logic                           r_pulse_p;			//read current pulse for program-data
	logic							shift_pulses;		//shift pulses generated by shifter modules
	logic							shift_set;			//shift pulses generated by set shifter
	logic							shift_rst;			//shift pulses generated by reset shifter
	logic 							IN1_NAND_NORn;		//select NAND/NOR pNML racetrack	
	logic							Bz_m;				//Magnetic field module (used like an enable)
	logic							out_select;			//select data or LiM data			
	logic [blocks*par-1:0]			r_data_int;			//out data slice
	logic [blocks*par-1:0]			r_data_p_int;		//out data-mask slice	
	logic [blocks*par-1:0]			r_data_m_int;		//out data-program slice  
	logic [blocks-1:0]				enabled_block;  	//decoder for active blocks
	logic							w_pulse_data;		//pulses for data write operation
	logic							w_pulse_mask;   	//pulses for mask write operation
	logic							w_pulse_program;	//pulses for program racetrack write operation
	logic [Nr*NMU-1:0] 				data_d;				//active block data 
	logic [Nr*NMU-1:0] 				data_m_d;			//active block mask-data       
	logic [Nr*NMU-1:0] 				data_p_d;			//active block program-data    
	logic [1:0]						n_shift_int;		//out of n shift mux
	logic [1:0]						n_shift_rst;		//out of N shift FF
	logic							source_shift_sel;	//select shift source (set or reset shifter)
	logic							en_ff_read;			//enable for data out FF
	logic [Nr*NMU-1:0]				write_int;			//intermediate signal fro byte write
	logic [Nr*NMU-1:0] 				data_and_d;			//Bitwise AND active block data out
	logic [Nr*NMU-1:0] 				data_xor_d;			//Bitwise XOR active block data out
	logic [Nr*NMU-1:0] 				data_or_d;			//Bitwise OR active block data out
	logic [Nr*NMU-1:0]				data_xnor_d;			//Bitwise XNOR active block data out
	logic							en_lim_buf;			//enable signa for LiM buffer FF
	logic [Nr*NMU-1:0]				lim_buf;			//LiM buffer (store data values before byte write operation)
	logic [Nr*NMU-1:0]				program_w; 			//input write program racetrack 
	
	
	logic [Nr*NMU-1:0] 				data_d_int;			//out FF input, selects between data and mask-data	
	logic [Nr*NMU-1:0]	    		mask_int;			//internal input write data for mask racetrack  	
	
		
	//======================================================================
    // RACETRACK WAVEFORM GENERATION
    //====================================================================== 
	assign shift_m 		   = shift_select & shift_pulses;														//generate pulses for shift oepration
	assign w_pulse_data    = (MEM_MODE) ? w_en_d & write_pulse_i : (w_en_d & write_pulse_i & word_sel_i[0]);   	//generate pulses for data write operation		
	assign w_pulse_mask    = (MEM_MODE) ? w_en_m & write_pulse_i : (w_en_d & write_pulse_i &  word_sel_i[1]);   //generate pulses for mask write operation & data-mask oepration
	assign w_pulse_program = (MEM_MODE) ? w_en_p & write_pulse_i : (w_en_d & write_pulse_i &  word_sel_i[2]);   //generate pulses for prog write operation & prog-mask oepration
	
	assign r_pulse_d 		= r_en & read_pulse_i;		 //generate pulses for data/logic read  operation
	assign r_pulse_m		= r_en & read_pulse_i;		 //generate pulses for data-mask read  operation
	assign r_pulse_p		= r_en & read_pulse_i;		 //generate pulses for data-program read  operation
	
	//======================================================================
    // RACETRACK MEMORY ARRAY GENERATION
    //====================================================================== 
	genvar i;
	
	generate 
		for(i=0; i<blocks; i++) begin
		//=====================================
		//RACETRACK BLOCK (32-8-4)x8 32bit (1 word) parallelism LiM Mode - 32bit x3 bit parallelism (3 words) memory mode
		//=====================================
		RT_block
		#(.Nb(Nb),
		  .Np(Np),
		  .Nr(Nr),
		  .NMU(NMU)
		)
		RT_block_i
		(
			.rstn_i(rstn_i),
		    .Bz_s_i(Bz_s_i),
		    .Bz_m_i(Bz_m),
		    .read_current_d_i(r_pulse_d),			//read current waveform for data/logic
			.read_current_m_i(r_pulse_m),			//read current waveform for mask-data		
			.read_current_p_i(r_pulse_p),			//read current waveform for program-data	
		    .current_s_lim_i(shift_s),
		    .current_m_lim_i(shift_m),
		    .current_s_data_i(shift_s),
		    .current_m_data_i(shift_m),
		    .current_m_mask_i(shift_s),
		    .current_s_mask_i(shift_m),	
			.current_s_program_i(shift_s),
			.current_m_program_i(shift_m),
			.write_data_i(write_int),		
		    .write_en_data_i(w_pulse_data),			//input for mask racetrack
			.write_mask_i(mask_int),
		    .write_en_mask_i(w_pulse_mask),
			.write_program_i(program_w),			//input for program racetrack
		    .write_en_program_i(w_pulse_program),
		    .word_lines_i(word_lines[i*Nb +: Nb]),
		    .out_select_i(out_select),
		    
		    .r_data_o(r_data_int[i*par +: par]),
			.r_data_m_o(r_data_m_int[i*par +: par]),
			.r_data_p_o(r_data_p_int[i*par +: par])
		);
		end
	endgenerate
	
	//=====================================
	//ACTIVE BLOCK DECODING
	//=====================================
	generate
		for(i=0; i<blocks; i++) begin
			assign enabled_block[i] = |(word_lines[i*Nb +: Nb]);	//group word lines to understan active block
		end
	endgenerate
	
	//=====================================
	//ACTIVE BLOCK MUX
	//=====================================
	//selects 32 bits output based on the active block
	always_comb begin
	data_d   = '0;
	data_m_d = '0;
	data_p_d = '0;
	
		for (int i=0; i<blocks; i=i+1)begin //find active port
			if(enabled_block[i]==1) begin
					data_d   = r_data_int[i*par +: par];
					data_m_d = r_data_m_int[i*par +: par];
					data_p_d = r_data_p_int[i*par +: par];
					
			end
		end
	end
	
		
	//data_d selection for following logic
	always_comb begin
		data_d_int = data_d;	//LiM mode takes data racetrack
			if(!MEM_MODE) begin	//select different input data_d in std. mem mode (data racetrack or mask-data racetrack)
					
				 case(word_sel_i)
					3'b001: data_d_int = data_d;	//word 0
					3'b010: data_d_int = data_m_d;	//word 1
					3'b100: data_d_int = data_p_d;  //word 2
					
					default: data_d_int = data_d;	//word 0
				endcase
				
			end
	end
	
	
	
	
	//=====================================
	//LiM ARRAYS
	//=====================================

	assign data_and_d  = ~data_d; 			//invert NAND output (exploit Racetrack LiM result)
	assign data_or_d   = ~data_d; 			//invert NOR output  (exploit Racetrack LiM result)
	assign data_xor_d  = data_d ^ mask_i; 	//compute XOR logic operation
	assign data_xnor_d = ~data_xor_d;		//compute NXOR logic operation
		
	
	
	//=====================================
	//OUT DATA REGISTER + BYTE SELECTION + LiM STORE FUNCTIONALITIES
	//=====================================
	//Range operations are done on the full word, range_active_i bypasses byte selection
	
	always @(posedge clk_i, negedge rstn_i) begin
       if ( !rstn_i) begin
			data_o <= '0;

		end 
		else if(en_ff_read) begin	//stabilize out data when valid signal is high
		
			unique case (logic_in_memory_funct_int_i)
		
				FUNCT_AND: begin
					if(be_b_i[0] || range_active_i)begin	//active read if at least 8bit are read
						for(int i=0; i<4; i++)begin			//range_active disables byte operations (full word selection)
								if(be_b_i[i] || range_active_i) data_o[i*8 +: 8] = data_and_d[i*8 +: 8];
						end
					end
			end	
			
				FUNCT_OR: begin
					if(be_b_i[0] || range_active_i)begin
						for(int i=0; i<4; i++)begin
								if(be_b_i[i] || range_active_i) data_o[i*8 +: 8] = data_or_d[i*8 +: 8];
						end
					end
	
			end
			
				FUNCT_XOR: begin
					if(be_b_i[0] || range_active_i)begin
						for(int i=0; i<4; i++)begin
							if(be_b_i[i] || range_active_i) data_o[i*8 +: 8] = data_xor_d[i*8 +: 8];
						end
					end
			end
			
			
			FUNCT_NAND: begin
					if(be_b_i[0] || range_active_i)begin	
						for(int i=0; i<4; i++)begin			
								if(be_b_i[i] || range_active_i) data_o[i*8 +: 8] = data_d[i*8 +: 8];
						end
					end
			end	
			
			
			FUNCT_NOR: begin
					if(be_b_i[0] || range_active_i)begin
						for(int i=0; i<4; i++)begin
								if(be_b_i[i] || range_active_i) data_o[i*8 +: 8] = data_d[i*8 +: 8];
						end
					end
	
			end
			
			FUNCT_XNOR: begin
					if(be_b_i[0] || range_active_i)begin
						for(int i=0; i<4; i++)begin
							if(be_b_i[i] || range_active_i) data_o[i*8 +: 8] = data_xnor_d[i*8 +: 8];
						end
					end
			end
						
			
		
				default: begin
					if(be_b_i[0] || range_active_i)begin
						for(int i=0; i<4; i++)begin
							if(be_b_i[i] || range_active_i) data_o[i*8 +: 8] = data_d_int[i*8 +: 8];	
						end	
					end
			end
			endcase			
		end
	end
		
	//=====================================
	//WRITE DATA IN BYTE SELECTION MUX + LiM STORE FUNCTIONALITIES
	//=====================================
	always_comb begin		
	write_int = data_d_int;	//not selected byte rewrites the original data, this prevent latch inferation
	
		unique case(logic_in_memory_funct_int_i)
		//write operation can be don on each byte
			FUNCT_AND: begin	
                        for(int i=0; i<4; i++)begin
							if(be_b_i[i] || range_active_i) begin
								write_int[i*8 +: 8] = data_and_d[i*8 +: 8];	//take logic value from ractrack
							end else begin
								write_int[i*8 +: 8] = lim_buf[i*8 +: 8];	//restore actual value
							end
						end	
		end
	
			FUNCT_OR: begin
                        for(int i=0; i<4; i++)begin
							if(be_b_i[i] || range_active_i) begin
								write_int[i*8 +: 8] = data_or_d[i*8 +: 8];		//take logic value from ractrack
							end else begin
								write_int[i*8 +: 8] = lim_buf[i*8 +: 8];	//restore actual value
							end
						end	
		end
		
			FUNCT_XOR: begin
                        for(int i=0; i<4; i++)begin
							if(be_b_i[i] || range_active_i) write_int[i*8 +: 8] = data_xor_d[i*8 +: 8];
						end	
		end
		
			FUNCT_NAND: begin	
                        for(int i=0; i<4; i++)begin
							if(be_b_i[i] || range_active_i) begin
								write_int[i*8 +: 8] = data_d[i*8 +: 8];	//take logic value from ractrack
							end else begin
								write_int[i*8 +: 8] = lim_buf[i*8 +: 8];	//restore actual value
							end
						end	
		end
		
			FUNCT_NOR: begin
                        for(int i=0; i<4; i++)begin
							if(be_b_i[i] || range_active_i) begin
								write_int[i*8 +: 8] = data_d[i*8 +: 8];		//take logic value from ractrack
							end else begin
								write_int[i*8 +: 8] = lim_buf[i*8 +: 8];	//restore actual value
							end
						end	
		end
		
		
			FUNCT_XNOR: begin
                        for(int i=0; i<4; i++)begin
							if(be_b_i[i] || range_active_i) write_int[i*8 +: 8] = data_xnor_d[i*8 +: 8];
						end	
		end
		
		
				

			default: begin
						for(int i=0; i<4; i++)begin
							if(be_b_i[i] || range_active_i) write_int[i*8 +: 8] = write_data_i[i*8 +: 8];
						end	
		end
	
		endcase	
	end
	
	//=====================================
	//LiM RESULT BUFFER
	//=====================================
	//store data before LiM write (useful for byte write), data is stored in the register, written byte over-writes old bytes
	always @(posedge clk_i, negedge rstn_i) begin
       if ( !rstn_i) begin
			lim_buf <= '0;
		end else if(en_lim_buf)  begin
			lim_buf <= data_d;	//store data before LiM write (useful for byte write)
		end
	end
	
	
	
	//=====================================
	//INPUT MASK-DATA & PROGRAM-DATA SELECTION LOGIC
	//=====================================
	
	assign mask_int = (MEM_MODE)? mask_i : write_int;				//LiM mode selects input mask otherwise takes inout data
	
	assign program_w = (MEM_MODE)? {32{IN1_NAND_NORn}} : write_int; //LiM mode selects program bit	otherwise takes input data
		
	
	
	
	
	//=====================================
	//N-SHIFT FF
	//=====================================
	//stabilize input N  shift and use it during reset state
	always @(posedge clk_i, negedge rstn_i) begin
       if ( !rstn_i) begin
			n_shift_rst <= 1'b0;
		end else  begin
			n_shift_rst <= n_shift_i;
		end
	end
	
	//=====================================
	//SOURCE SHIFT (SET-RESET) MUX
	//=====================================
	
	assign shift_pulses = (source_shift_sel)? shift_rst : shift_set; //sel = 1 => rst pulses
	
	
	
	
	
	//=====================================
	//SHIFT WAVEFORM GENERATOR - SET
	//=====================================
	shifter
	#(.N_WIDTH(CNT_WIDTH),
	  .CNT_WIDTH(CNT_WIDTH)
	)
	set_shift_generator
	(.clk_i(clk_m_i), //magnetic clock 
	 .init_i(shift_en_s), 
	 .rstn_i(rstn_i),
	 .N_i(n_shift_i),
	 .shift_done_o(shift_done_s),
	 .pulses(shift_set) 
	);
	
	//=====================================
	//SHIFT WAVEFORM GENERATOR - RESET
	//=====================================
	shifter
	#(.N_WIDTH(CNT_WIDTH),
	  .CNT_WIDTH(CNT_WIDTH)
	)
	rst_shift_generator
	(.clk_i(clk_m_i), //magnetic clock 
	 .init_i(shift_en_r), 
	 .rstn_i(rstn_i),
	 .N_i(n_shift_rst),
	 .shift_done_o(shift_done_r), 
	 .pulses(shift_rst)
	);
	
	//======================================================================
    // FSM
    //====================================================================== 
	FSM
	RT_array_controller
	(
		.rstn_i(rstn_i),
		.clk_i(clk_i), 					//system clock
		.shift_done_s_i(shift_done_s), 
		.shift_done_r_i(shift_done_r), 
		.en_i(en_ab_i),
		.be_b_i(be_b_i),				
		.w_en_i(write_en_data_i),
		.shift_select_o(shift_select),
		.logic_in_memory_funct_int_i(logic_in_memory_funct_int_i),
		.shift_en_s_o(shift_en_s), 
		.shift_en_r_o(shift_en_r), 
		.shift_s_o(shift_s),
		.w_en_d_o(w_en_d),
        .w_en_m_o(w_en_m),
		.w_en_p_o(w_en_p),			
		.r_en_o(r_en),
		.r_valid_o(valid_o),	
		.NAND_NOR_o(IN1_NAND_NORn), 
		.Bz_m_o(Bz_m),		
		.out_select_o(out_select),
		.source_shift_sel_o(source_shift_sel),
		.en_ff_read_o(en_ff_read),	
		.en_lim_buf_o(en_lim_buf)	
	);
		
	
endmodule
