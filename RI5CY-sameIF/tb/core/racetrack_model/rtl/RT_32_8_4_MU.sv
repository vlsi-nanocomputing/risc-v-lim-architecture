
module RT_32_8_4_MU
	#(parameter	Nr = 4, //number of racetrack
	  parameter Nb = 32,
	  parameter Np = 8
	)
	(input  logic 						 rstn_i,
	 input  logic 			 			 Bz_s_i,			//field B inly needed for NAND NOR pNML
	 input  logic 			          	 Bz_m_i,
	 input  logic						 read_current_i,
	 input	logic						 current_s_lim_i,
	 input	logic						 current_m_lim_i,
	 input	logic						 current_s_data_i,
	 input	logic						 current_m_data_i,
	 input	logic						 current_m_mask_i,
	 input	logic						 current_s_mask_i,
	 input  logic 			 			 current_s_program_i,	
	 input  logic 			 			 current_m_program_i, 	
	 input  logic [Nr-1:0]				 write_i_data_i,   
	 input  logic 						 write_en_data_i,
	 input  logic [Nr-1:0]				 write_i_mask_i,
	 input  logic 						 write_en_mask_i,
	 input  logic [Nr-1:0]			 	 write_i_program_i,			
	 input  logic 			 			 write_en_program_i, 		
	
	 input  logic [Nb-1:0]				 word_lines_i,
	 input  logic						 out_select_i,
	  
	 output logic [Nr-1:0] 		    	 r_data_o 
	

	);
	
	//==========================
	//LOCAL PARAMETERS
	//==========================
	
	localparam  Nsp = Nb/Np;
	localparam  Nov = Nb - ((Nb/Np)*Np -(Nb/Np))-1;
	
	
	//data_int layout
	//
	//	[00, 01 ..., 07 - 10, 11, ..., 17 - ...,37] Format [racetrack no., port no.]
	//
	//data_block_o layout
	//
	//	[p00, p10, p20, p30, ..., p70, p71, p72, p73] Format [[racetrack no., port no.]
	//  Now each port output is alligned
	
	logic [Nr*Np-1:0] data_int;
	logic [Nr*Np-1:0] logic_int;
	logic [Nr*Np-1:0] data_program_int;
	logic [Nr*Np-1:0] data_mask_int;
	logic [Nr*Np-1:0] data_array;
	logic [Nr*Np-1:0] logic_array;
	logic [Nr*Np-1:0] data_program_array;
	logic [Nr*Np-1:0] data_mask_array;
	
	logic [Np-1:0]    enabled_port_wr_data; //write enable array for active port (enabled_port masked with write enable)
	logic [Np-1:0]    enabled_port_wr_mask;
	logic [Np-1:0]    enabled_port_wr_program;
	
	logic [Np-1:0]	  enabled_port_data;	//enable signal for r/w ports
	logic [Np-1:0]	  enabled_port_logic;	//enable signal for r/w ports
	logic [Np-1:0]	  enabled_port_mask;	//enable signal for r/w ports
	logic [Np-1:0]	  enabled_port_program;  //enable signal for r/w ports
	
	logic [Nr-1:0]	  data_o;
	logic [Nr-1:0] 	  lim_o;
	
	//=====================================
	//RACETRACK ARRAY 32-8-4 GENERATION
	//=====================================
	genvar i;

	generate 
		for(i=0; i<Nr; i++) begin: rt_line	//generate 4 LiM Racetrack lines
			RT_32_8_4_line
				#( .Nb(Nb),
				   .Np(Np)
				)
			RT_line_i	
				(	.rstn_i(rstn_i),
		 			.Bz_s_i(Bz_s_i),
		    		.Bz_m_i(Bz_m_i),
					.read_current_i(read_current_i),
		 			.current_s_lim_i(current_s_lim_i),	
		 			.current_m_lim_i(current_m_lim_i),
		 			.current_s_data_i(current_s_data_i), 
		 			.current_m_data_i(current_m_data_i),
		 			.current_s_mask_i(current_s_mask_i), 
		 			.current_m_mask_i(current_m_mask_i),
					.current_s_program_i(current_s_program_i), 
					.current_m_program_i(current_m_program_i), 
					.write_i_data_i(write_i_data_i[i]),   
					.write_en_data_i(enabled_port_wr_data),
		 			.write_i_mask_i(write_i_mask_i[i]),	
					.write_en_mask_i(enabled_port_wr_mask),	
					.write_i_program_i(write_i_program_i[i]),		
					.write_en_program_i(enabled_port_wr_program),   
		 
		 			.r_port_data_o(data_int[i*Np +:Np]),     //assign to data_int vector            	 
		 			.r_port_lim_o(logic_int[i*Np +:Np]),    //assign to logic_block_int vector 
					.r_port_data_mask_o(data_mask_int[i*Np +:Np]),
					.r_port_data_program_o(data_program_int[i*Np +:Np])
				);		
		end
	endgenerate
	
	
	
	//=====================================
	//PORT DECODING
	//=====================================
	
	//put in OR wordlines assigned to the same port (reduction operators)
	genvar p;
	
	generate		

		for( p=0; p<Np; p++) begin
			if(p<(Np-1))begin
				assign enabled_port_data[p]  	= |(word_lines_i[(p*Nsp)+: Nsp]);	
				assign enabled_port_logic[p] 	= |(word_lines_i[(p*Nsp)+: Nsp]);		
				assign enabled_port_mask[p]  	= |(word_lines_i[(p*Nsp)+: Nsp]);	
				assign enabled_port_program[p]	= |(word_lines_i[(p*Nsp)+: Nsp]); 
			end
			else begin
				assign enabled_port_data[p]  	= |(word_lines_i[Nb-1: p*Nsp]);	//select the whole remaining slice
				assign enabled_port_logic[p]    = |(word_lines_i[Nb-1: p*Nsp]);
			    assign enabled_port_mask[p]     = |(word_lines_i[Nb-1: p*Nsp]);
				assign enabled_port_program[p]  = |(word_lines_i[Nb-1: p*Nsp]);	
			end
		end
	endgenerate
	
	
	
	
	//=====================================
	//WRITE ENABLE LOGIC
	//=====================================

	//write enable generation
	assign enabled_port_wr_data    = enabled_port_data & {Np{write_en_data_i}}; //activate write enable only for active rows
	assign enabled_port_wr_mask    = enabled_port_mask & {Np{write_en_mask_i}};
	assign enabled_port_wr_program = enabled_port_program & {Np{write_en_program_i}};	
	
	
	
	
	//=====================================
	//OUTPUT ROUTING
	//=====================================

	always_comb begin
	
		for(int i=0; i<Nr; i=i+1) begin
				data_array[i+Nr*0]  = data_int[Np*i+0];
				data_array[i+Nr*1]  = data_int[Np*i+1];
				data_array[i+Nr*2]  = data_int[Np*i+2];
				data_array[i+Nr*3]  = data_int[Np*i+3];
				data_array[i+Nr*4]  = data_int[Np*i+4];
				data_array[i+Nr*5]  = data_int[Np*i+5];
				data_array[i+Nr*6]  = data_int[Np*i+6];
				data_array[i+Nr*7]  = data_int[Np*i+7];
				
				logic_array[i+Nr*0] = logic_int[Np*i+0];
	            logic_array[i+Nr*1] = logic_int[Np*i+1];
	            logic_array[i+Nr*2] = logic_int[Np*i+2];
	            logic_array[i+Nr*3] = logic_int[Np*i+3];
	            logic_array[i+Nr*4] = logic_int[Np*i+4];
				logic_array[i+Nr*5] = logic_int[Np*i+5];
				logic_array[i+Nr*6] = logic_int[Np*i+6];
				logic_array[i+Nr*7] = logic_int[Np*i+7];
		end	             
	end       


	//=====================================
	//DATA SLICE SELECTION
	//=====================================
	//selects Nr bits output based on the active wordline
	
	always_comb begin
	data_o = '0;
		for (int i=0; i<Np; i=i+1)begin //find active port
			if(enabled_port_data[i]==1) begin
					data_o = data_array[i*Nr +:Nr];
			end
		end
	end
	
	//=====================================
	//LOGIC SLICE SELECTION
	//=====================================

	always_comb begin
	lim_o = '0; //all zeros
		for (int i=0; i<Np; i=i+1)begin //find active port
			if(enabled_port_logic[i]==1) begin
				lim_o = logic_array[i*Nr +:Nr];
			end
		end
	end

	//=====================================
	//OUTPUT MUX
	//=====================================
	assign r_data_o = out_select_i? lim_o : data_o; //lim out=1, std data=0
	
endmodule
