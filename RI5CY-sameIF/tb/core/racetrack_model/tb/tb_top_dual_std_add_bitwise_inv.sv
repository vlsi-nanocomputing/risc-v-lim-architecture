
import racetrack_defines::*;

//timescale unit configured in script


module tb_mem_datapath_fast;

	localparam ADDR_WIDTH = 8;
	localparam MAX_SIZE	 = 256;	//with ADDR_WIDTH = 8 we have 256 bytes
	localparam MEM_MODE  = 1;	//test LiM mode
	
	logic						clk_system =1'b1;
	logic 						clk_m = 1'b1;
	logic           			en_ab;
	logic  [3:0]				be_b;
	logic						range_active = 1'b0; //disable range operations
	logic						Bz_s = 1'b1;
	logic						read_pulse = 1'b1;
	logic						write_pulse= 1'b1;
	logic 						rstn;
	logic 	[ADDR_WIDTH-1:0]	ADDR;
	logic	[31:0]				write_i_data;
	logic						write_en_data;
	logic	[31:0]				mask;
	logic	[31:0]				r_data_out;
	logic						r_valid;
	logic	[7:0]				opcode_mem;
	
	mem_datapath
	#(.ADDR_WIDTH(ADDR_WIDTH),
	  .MAX_SIZE(MAX_SIZE),
	  .MEM_MODE(MEM_MODE)
	)
	datapath
	(
		.rstn_i(rstn),
		.clk_i(clk_system),
		.clk_m_i(clk_m),
		.en_ab_i(en_ab),
		.be_b_i(be_b),
		.Bz_s_i(Bz_s),
		.write_pulse_i(write_pulse),
		.read_pulse_i(read_pulse),
		.ADDR_i(ADDR),
		.write_i_data_i(write_i_data),
		.write_en_data_i(write_en_data),
		.mask_i(mask),
		.logic_in_memory_funct_int_i(opcode_mem),
		.range_active_i(range_active),
		.r_data_o(r_data_out),
		.r_valid_o(r_valid)
	);
			
	// Bz_s generation
    initial begin: Bz_s_gen
        forever begin
            #BZs_PHASE_HI  Bz_s = 1'b0;
            #BZs_PHASE_LO  Bz_s = 1'b1;
        end
    end: Bz_s_gen
		
	// system clock generation
    initial begin: clock_system_gen
        forever begin
            #CLK_PHASE_HI  clk_system = 1'b0;
            #CLK_PHASE_LO  clk_system = 1'b1;
        end
    end: clock_system_gen
	
	// magnetic clock generation
    initial begin: clock_m_gen
        forever begin
            #CLK_M_PHASE_HI  clk_m = 1'b0;
            #CLK_M_PHASE_LO  clk_m = 1'b1;
        end
    end: clock_m_gen
	
	// read current waveform generation
    initial begin: read_pulse_gen
        forever begin
            #r_init_LO   read_pulse = 1'b1;
            #r_phase_HI  read_pulse = 1'b0;
			#r_phase_LO  read_pulse = 1'b0;
        end
    end: read_pulse_gen
	
	// read current waveform generation
    initial begin: write_pulse_gen
        forever begin
            #w_init_LO   write_pulse = 1'b1;
            #w_phase_HI  write_pulse = 1'b0;
			#w_phase_LO  write_pulse = 1'b0;
        end
    end: write_pulse_gen
	


	initial begin
		rstn 			= 1'b0;
		ADDR 			= 8'h0;
		en_ab 			= 1'b0;
		opcode_mem    	= FUNCT_NONE;	//select standard behaviour
		write_i_data  	= 32'h0; 		//write 0
		write_en_data 	= 1'b1;
		mask  			= 32'hf1;
		be_b		  	= 4'b1111; //select all bytes
		
		repeat(2) begin				//wait 2 clock cycles for reset operation
			@(posedge clk_system);
		end
	    rstn = 1'b1;
		
		//WRITE ROUTINE
		repeat(5) begin
			en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
			ADDR = ADDR +4;
			write_i_data = write_i_data +32'h349B;	//add 13467
		end
		
		//reset add
		ADDR = 8'h0;
		write_en_data 	= 1'b0;
		
		//READ ROUTINE (OK)
		repeat(5) begin
			en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
			ADDR = ADDR +4;
		end
		
		
		//SW NOR 
		mask = 32'hF1;
		
		//reset add
		ADDR = 8'h0;
		write_en_data 	= 1'b1;
		opcode_mem      = FUNCT_NOR;		//NOR
		
		//WRITE LiM SW ROUTINE
		repeat(5) begin
			en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
			ADDR = ADDR +4;
		end
		
		
		//reset add
		ADDR = 8'h0;
		write_en_data 	= 1'b0;
		opcode_mem      = FUNCT_NONE;		//NULL
		
		//READ ROUTINE (OK)
		repeat(5) begin
			en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
			ADDR = ADDR +4;
		end
		
		
		//SW NAND
		mask = 32'hFFFFFFFD;
		
		//reset add
		ADDR = 8'h0;
		write_en_data 	= 1'b1;
		opcode_mem    = FUNCT_NAND;		//NAND
		
		//WRITE LiM SW ROUTINE
		repeat(5) begin
			en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
			ADDR = ADDR +4;
		end
		
		
		//reset add
		ADDR = 8'h0;
		write_en_data 	= 1'b0;
		opcode_mem      = FUNCT_NONE;		//NULL
		 
		//READ ROUTINE (OK)
		repeat(5) begin
			en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
			ADDR = ADDR +4;
		end
		
		//SW XNOR
		mask = 32'hFFFF62FC;
		
		//reset add
		ADDR = 8'h0;
		write_en_data 	= 1'b1;
		opcode_mem    = FUNCT_XNOR;		//XNOR
		
		//WRITE LiM SW ROUTINE
		repeat(5) begin
			en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
			ADDR = ADDR +4;
		end
		
		
		//reset add
		ADDR = 8'h0;
		write_en_data 	= 1'b0;
		opcode_mem      = FUNCT_NONE;		//NULL
		
		//READ ROUTINE (OK)
		repeat(5) begin
			en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
			ADDR = ADDR +4;
		end
		
		
		//reset add & data
		ADDR = 8'h0;
		opcode_mem      = FUNCT_NONE;		//NULL
		write_i_data  	= 32'h0; 		//write 0
		write_en_data 	= 1'b1;


		//WRITE ROUTINE (reset initial vector)
		repeat(5) begin
			en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
			ADDR = ADDR +4;
			write_i_data = write_i_data +32'h349B;	//add 13467
		end

		


		//reset add
		ADDR = 8'h0;
		mask = 32'hF1;
		write_en_data 	= 1'b0;
		opcode_mem      = FUNCT_NOR;		//NOR
		
		//READ ROUTINE LW NOR (OK)
		repeat(5) begin
			en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
			ADDR = ADDR +4;
		end


		//reset add
		ADDR = 8'h0;
		mask = 32'hF1;
		write_en_data 	= 1'b0;
		opcode_mem    = FUNCT_NAND;		//NAND
		
		//READ ROUTINE LW NAND (OK)
		repeat(5) begin
			en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
			ADDR = ADDR +4;
		end


		
		//reset add
		ADDR = 8'h0;
		mask = 32'hF1;
		write_en_data 	= 1'b0;
		opcode_mem    = FUNCT_XNOR;		//XNOR
		
		//READ ROUTINE LW XNOR (OK)
		repeat(5) begin
			en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
			ADDR = ADDR +4;
		end
		
		
		
		//reset add
		ADDR = 8'h0;
		opcode_mem      = FUNCT_NONE;		//NULL
		
		write_i_data  	= 32'h0; 		//write 0
		write_en_data 	= 1'b1;


		//WRITE ROUTINE (reset initial vector)
		repeat(5) begin
			en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
			ADDR = ADDR +4;
			write_i_data = write_i_data +32'h349B;	//add 13467
		end


		
		
		//BYTE READ ROUTINE (NAND)
		
		//Read 2nd element (v[1])
		mask = 32'h8D;
		write_en_data 	= 1'b0;
		ADDR = 8'h4;			//read 2nd element
		en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
		
		
		opcode_mem    = FUNCT_NAND;		//AND
		be_b		  = 4'b0001; //select 1st byte
		en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
			
		be_b		  = 4'b0011; //select 16bit
		en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
		
		be_b		  = 4'b1111; //select 32bit 
		en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
				
		
		
		//BYTE WR ROUTINE
		write_en_data 	= 1'b1;
		opcode_mem    = FUNCT_XNOR;		//XNOR					
		be_b		  = 4'b0001; //select 8bit 
		en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
			
		//read result
		write_en_data 	= 1'b0;
		opcode_mem    = FUNCT_NONE;		//NULL
		be_b		  = 4'b1111; //select all bits
		en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
			
			
			
			
		write_en_data 	= 1'b1;
		opcode_mem    = FUNCT_XNOR;		//XNOR	
		be_b		  = 4'b0010; //select 2nd B
		en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end	
			
		//read result
		write_en_data 	= 1'b0;
		opcode_mem    = FUNCT_NONE;		//NULL
		be_b		  = 4'b1111; //select all bits
		en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
			
			
			
			
		write_en_data 	= 1'b1;
		opcode_mem    = FUNCT_XNOR;		//XNOR		
		be_b		  = 4'b0100; //select 3rd B 
		en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end		
			
		//read result
		write_en_data 	= 1'b0;
		opcode_mem    = FUNCT_NONE;		//NULL
		be_b		  = 4'b1111; //select all bits
		en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
			
			
			
			
		write_en_data 	= 1'b1;
		opcode_mem    = FUNCT_XNOR;		//XNOR			
		be_b		  = 4'b1000; //select 4th B
		en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end		
			
		//read result
		write_en_data 	= 1'b0;
		opcode_mem    = FUNCT_NONE;		//NULL
		be_b		  = 4'b1111; //select all bits
		en_ab = 1;
			repeat(1) begin				//wait 1 clock cycle
				@(posedge clk_system);
			end
			en_ab = 0;
			@(posedge r_valid);
			repeat(1) begin				//wait 1 clock cycles
				@(posedge clk_system);
			end
		
		

	end

endmodule
