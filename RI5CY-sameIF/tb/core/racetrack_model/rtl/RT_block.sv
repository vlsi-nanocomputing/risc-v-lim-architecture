
module RT_block
	#( parameter Nb  = 32,
	   parameter Np  = 8, 
	   parameter Nr  = 4,
	   parameter NMU = 8
	 )
	 ( 
		input logic					 rstn_i,
		input logic					 Bz_s_i,
		input logic					 Bz_m_i,
		input logic				 	 read_current_d_i,
		input logic				 	 read_current_m_i,
		input logic				 	 read_current_p_i,
		input logic					 current_s_lim_i,
		input logic					 current_m_lim_i,
		input logic					 current_s_data_i,
		input logic     			 current_m_data_i,
	    input logic     			 current_m_mask_i,
	    input logic     			 current_s_mask_i,
		input logic 			 	 current_s_program_i,	
		input logic 			 	 current_m_program_i, 	
		input logic	 [Nr*NMU-1:0]	 write_data_i,			//input write data racetrack
	    input logic     			 write_en_data_i,
	    input logic  [Nr*NMU-1:0]    write_mask_i,			//input write mask racetrack
		input logic					 write_en_mask_i,
		input logic  [Nr*NMU-1:0]    write_program_i,		//input write program racetrack		
		input logic					 write_en_program_i,										
        input logic  [Nb-1:0]		 word_lines_i,
		input logic					 out_select_i,
						
		output logic [Nr*NMU-1:0]	 r_data_o,		//output (data & pNML)			
		output logic [Nr*NMU-1:0] 	 r_data_m_o,	//out r_data of mask racetrack (for std. mem. mode)		
		output logic [Nr*NMU-1:0] 	 r_data_p_o 	//out r_data of program racetrack (for std. mem. mode)					
	); 
	
	
	
	//=====================================
	//RACETRACK ARRAY (32-8-4)xNMU (32bit parallelism with NMU=8)
	//=====================================
	genvar i;
	
	generate
		for(i=0; i<NMU; i++) begin
			RT_32_8_4_MU
			#(.Nr(Nr),
			  .Nb(Nb),
			  .Np(Np)
			)
			RT_32_8_4_block
			( .rstn_i(rstn_i),
			  .Bz_s_i(Bz_s_i),
			  .Bz_m_i(Bz_m_i),
			  .read_current_d_i(read_current_d_i), 
			  .read_current_m_i(read_current_m_i), 
			  .read_current_p_i(read_current_p_i), 
			  .current_s_lim_i(current_s_lim_i),
			  .current_m_lim_i(current_m_lim_i),
			  .current_s_data_i(current_s_data_i),
			  .current_m_data_i(current_m_data_i),
			  .current_m_mask_i(current_s_mask_i),
			  .current_s_mask_i(current_m_mask_i),
			  .current_s_program_i(current_s_program_i), 
			  .current_m_program_i(current_m_program_i), 
			  .write_i_data_i(write_data_i[i*Nr +:Nr]),
			  .write_en_data_i(write_en_data_i),
			  .write_i_mask_i(write_mask_i[i*Nr +:Nr]),
			  .write_en_mask_i(write_en_mask_i),
			  .write_i_program_i(write_program_i[i*Nr +:Nr]),	
			  .write_en_program_i(write_en_program_i),			
			  
			  .word_lines_i(word_lines_i), 
			  .out_select_i(out_select_i),
			  
			  .r_data_o(r_data_o[i*Nr +:Nr]),
			  .r_data_m_o(r_data_m_o[i*Nr +:Nr]),
			  .r_data_p_o(r_data_p_o[i*Nr +:Nr])
			 
			);
		end
	endgenerate
	
	
endmodule
