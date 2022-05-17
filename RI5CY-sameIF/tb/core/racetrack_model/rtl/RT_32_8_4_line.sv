


module RT_32_8_4_line
	#(parameter	Nb  = 32 ,
	  parameter Np  = 8
	)
	(input  logic 						 rstn,
	 input  logic 			 			 Bz_s,				//field B inly needed for NAND NOR pNML
	 input  logic 			          	 Bz_m,
	 input  logic						 read_current,		//read current pulse
	 input  logic 			 			 current_s_lim,	    //lim pulse direction
	 input  logic 			 			 current_m_lim, 	//lim pulse waveform
	 input  logic 			 			 current_s_data,	//data pulse direction
	 input  logic 			 			 current_m_data, 	//data pulse waveform
	 input  logic 			 			 current_s_mask, 	//mask pulse direction
	 input  logic 			 			 current_m_mask, 	//mask pulse waveform
	 input  logic 			 			 write_i_data,   	//single bit data input
	 input  logic [Np-1:0]	 			 write_en_data,		//one write enable for each data port
	 input  logic [Np-1:0]	 			 write_en_mask, 	//one write enable for each mask port
	 input  logic 			 			 write_i_mask,	
	 input  logic 			             NAND_NOR_sel,  	// per semplicità è la stessa programmazione per tutte le celle logic
	 
	 output logic [Np-1:0]             	 r_port_data,		//read port data part
	 output logic [Np-1:0]               r_port_lim		//read port logic part
	 
	);
	
	//==========================
	//LOCAL PARAMETERS
	//==========================
	localparam  Nsp = Nb/Np;
	localparam  Nov = Nb - ((Nb/Np)*Np -(Nb/Np))-1;
	
	
	logic	[Nb+Nov-1:0]	data_line;	
	logic 	[Nb+Nov-1:0] 	lim_line;
	logic   [Nb+Nov-1:0]	mask_line;	
	logic 					lim_line_0;	
	logic 					mask_line_0;	
	logic					data_line_0;
	logic 					lim_line_last;	
	logic 					mask_line_last;	
	logic					data_line_last;
	
	
	//1st forward_in set to 0 otherwise shift in is undefined
	assign lim_line_0	    = 1'b0;
	assign mask_line_0		= 1'b0;
	assign data_line_0		= 1'b0;
	
	//Last backward_in set to 0 otherwise shift in is undefined
	assign data_line_last 	= 1'b0;
	assign lim_line_last 	= 1'b0;
	assign mask_line_last 	= 1'b0;
	
	
	//==========================
	//MASK RACETRACK
	//==========================
	genvar i;
				
	generate
		for(i=0; i<(Nb+Nov); i++)begin : mask_racetrack
		

			if(i==0) begin	//first overhead cell

			RT_cell
			overhead_mask_cell
			(  
				.rstn(rstn),
				.current_s(current_s_mask),
				.current_m(current_m_mask),
				.backward_in(mask_line[i+1]),
				.forward_in(mask_line_0),
				.out(mask_line[i])
			);

			end

			else if(i<Nov) begin	//overhead cell

			RT_cell
			overhead_mask_cell
			(  
				.rstn(rstn),
				.current_s(current_s_mask),
				.current_m(current_m_mask),
				.backward_in(mask_line[i+1]),
				.forward_in(mask_line[i-1]),
				.out(mask_line[i])
			);

			end

	
			
			else if((i==0*Nsp+Nov) || (i == 1*Nsp+Nov) || (i==2*Nsp+Nov) || (i==3*Nsp+Nov)) begin //read/write cell
			//1st half

			RT_write
			rd_wr_mask_cell //SOT cell not needed
			(
				.rstn(rstn),
				.current_s(current_s_mask),
				.current_m(current_m_mask),
				.backward_in(mask_line[i+1]), 
				.forward_in(mask_line_0),
				.write_input(write_i_mask),
				.write_enable(write_en_mask[i/Nsp]),
				.out(mask_line[i]) 
			);
			end		
			
			else if((i==4*Nsp+Nov) || (i==5*Nsp+Nov) || (i == 6*Nsp+Nov) || (i==7*Nsp+Nov)) begin //read/write cell
			//2nd half

			RT_write
			rd_wr_mask_cell
			(
				.rstn(rstn),
				.current_s(current_s_mask),
				.current_m(current_m_mask),
				.backward_in(mask_line[i+1]), 
				.forward_in(mask_line_0),
				.write_input(write_i_mask),
				.write_enable(write_en_mask[i/Nsp]),
				.out(mask_line[i]) 
			);
			end	
			
			else if( i==Nov+Nb-1) begin	//last cell, connect backward_in to 0
			
			RT_cell
			mask_cell
			(  
				.rstn(rstn),
				.current_s(current_s_mask),
				.current_m(current_m_mask),
				.backward_in(mask_line_last),
				.forward_in(mask_line[i-1]),
				.out(mask_line[i])
			);
			
			end

			else begin	//standard cells

			RT_cell
			mask_cel
			(  
				.rstn(rstn),
				.current_s(current_s_mask),
				.current_m(current_m_mask),
				.backward_in(mask_line[i+1]),
				.forward_in(mask_line[i-1]),
				.out(mask_line[i])
			);

			end

		end		
	endgenerate
	

	//==========================
	//pNML RACETRACK
	//==========================
	generate
		for(i=0; i<(Nb+Nov); i++)begin : pNML_racetrack	

			if(i==0) begin //first overhead cell

			pNML_NAND_NOR
				overhead_pNML_cell
				(
					.rstn(rstn),
					.Bz_s(Bz_s),
					.Bz_m(Bz_m),
					.current_s(current_s_lim),
					.current_m(current_m_lim),
					.backward_in(lim_line[i+1]),
					.forward_in(lim_line_0),
					.IN1_NAND_NOR_sel(NAND_NOR_sel),
					.IN2(data_line[i]), 					
					.IN3(mask_line[i]),
					.out(lim_line[i])
				);

			end
			
			else if(i<Nov) begin	//overhead cell

			pNML_NAND_NOR
			overhead_logic_cell
			(  
				.rstn(rstn),
				.Bz_s(Bz_s),
				.Bz_m(Bz_m),
				.current_s(current_s_lim),
				.current_m(current_m_lim),
				.backward_in(lim_line_0),
				.forward_in(lim_line[i-1]),
				.IN1_NAND_NOR_sel(NAND_NOR_sel),
				.IN2(data_line[i]), 					
				.IN3(mask_line[i]),
				.out(lim_line[i])
			);

			end
			
			else if((i==0*Nsp+Nov) || (i == 1*Nsp+Nov) || (i==2*Nsp+Nov) || (i==3*Nsp+Nov)) begin //read/write cell
			//1st half

			pNML_NAND_NOR_SOT
			rd_wr_logic_cell
			(
				.rstn(rstn),
				.Bz_s(Bz_s),
				.Bz_m(Bz_m),
				.current_s(current_s_lim),
				.current_m(current_m_lim),
				.read_current(read_current),
				.backward_in(lim_line_0),
				.forward_in(lim_line[i-1]),
				.IN1_NAND_NOR_sel(NAND_NOR_sel),
				.IN2(data_line[i]), 					
				.IN3(mask_line[i]),
				.read_out(r_port_lim[i/Nsp]),
				.out(lim_line[i])
			);
			end	

			else if((i==4*Nsp+Nov) || (i==5*Nsp+Nov) || (i == 6*Nsp+Nov) || (i==7*Nsp+Nov)) begin //read/write cell
			//2nd half

			pNML_NAND_NOR_SOT
			rd_wr_logic_cell
			(
				.rstn(rstn),
				.Bz_s(Bz_s),
				.Bz_m(Bz_m),
				.current_s(current_s_lim),
				.current_m(current_m_lim),
				.read_current(read_current),
				.backward_in(lim_line_0),
				.forward_in(lim_line[i-1]),
				.IN1_NAND_NOR_sel(NAND_NOR_sel),
				.IN2(data_line[i]), 					
				.IN3(mask_line[i]),
				.read_out(r_port_lim[i/Nsp]),
				.out(lim_line[i])
			);
			end	
			
			else if(i==Nov+Nb-1) begin //last cell, backward_in connected to 0
			
				pNML_NAND_NOR
				logic_cell
				(
					.rstn(rstn),
					.Bz_s(Bz_s),
					.Bz_m(Bz_m),
					.current_s(current_s_lim),
					.current_m(current_m_lim),
					.backward_in(lim_line_last),
					.forward_in(lim_line[i-1]),
					.IN1_NAND_NOR_sel(NAND_NOR_sel),
					.IN2(data_line[i]), 					
					.IN3(mask_line[i]),
					.out(lim_line[i])
				);
			
			end

			else begin

			pNML_NAND_NOR
				logic_cell
				(
					.rstn(rstn),
					.Bz_s(Bz_s),
					.Bz_m(Bz_m),
					.current_s(current_s_lim),
					.current_m(current_m_lim),
					.backward_in(lim_line[i+1]),
					.forward_in(lim_line[i-1]),
					.IN1_NAND_NOR_sel(NAND_NOR_sel),
					.IN2(data_line[i]), 					
					.IN3(mask_line[i]),
					.out(lim_line[i])
				);

			end
		end
	endgenerate

	//==========================
	//DATA RACETRACK
	//==========================
				
	generate
		for(i=0; i<(Nb+Nov); i++)begin : data_racetrack	

			if(i==0) begin	//first overhead cell

			RT_cell
			overhead_data_cell
			(  
				.rstn(rstn),
				.current_s(current_s_data),
				.current_m(current_m_data),
				.backward_in(data_line[i+1]),
				.forward_in(data_line_0),
				.out(data_line[i])
			);

			end

			else if(i<Nov) begin	//overhead cell

			RT_cell
			overhead_data_cell
			(  
				.rstn(rstn),
				.current_s(current_s_data),
				.current_m(current_m_data),
				.backward_in(data_line[i+1]),
				.forward_in(data_line[i-1]),
				.out(data_line[i])
			);

			end

			else if((i==0*Nsp+Nov) || (i == 1*Nsp+Nov) || (i==2*Nsp+Nov) || (i==3*Nsp+Nov)) begin //read/write cell
			//1st half
			RT_read_write_SOT
			rd_wr_data_cell
			(
				.rstn(rstn),
				.current_s(current_s_data),
				.current_m(current_m_data),
				.read_current(read_current),
				.backward_in(data_line[i+1]),
				.forward_in(data_line[i-1]),
				.out(data_line[i]),
				.read_out(r_port_data[i/Nsp]),
				.write_input(write_i_data),
				.write_enable(write_en_data[i/Nsp])
				
			);
			end
			
			else if((i==4*Nsp+Nov) || (i==5*Nsp+Nov) || (i == 6*Nsp+Nov) || (i==7*Nsp+Nov)) begin //read/write cell
			//2nd half
			RT_read_write_SOT
			rd_wr_data_cell
			(
				.rstn(rstn),
				.current_s(current_s_data),
				.current_m(current_m_data),
				.read_current(read_current),
				.backward_in(data_line[i+1]),
				.forward_in(data_line[i-1]),
				.out(data_line[i]),
				.read_out(r_port_data[i/Nsp]),
				.write_input(write_i_data),
				.write_enable(write_en_data[i/Nsp])
				
			);

			end	

			else if(i==Nov+Nb-1) begin //last cell, backward_in connected to 0
			
			RT_cell
			data_cell
			(  
				.rstn(rstn),
				.current_s(current_s_data),
				.current_m(current_m_data),
				.backward_in(data_line_last),
				.forward_in(data_line[i-1]),
				.out(data_line[i])
			);
			
			end

			else begin

			RT_cell
			data_cell
			(  
				.rstn(rstn),
				.current_s(current_s_data),
				.current_m(current_m_data),
				.backward_in(data_line[i+1]),
				.forward_in(data_line[i-1]),
				.out(data_line[i])
			);


			end

		end
	endgenerate

	
endmodule
