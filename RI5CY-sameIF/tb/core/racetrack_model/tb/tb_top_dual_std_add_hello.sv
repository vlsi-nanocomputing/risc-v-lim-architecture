
import racetrack_defines::*;

//timescale unit configured in script


module tb_mem_datapath_fast;

	localparam ADDR_WIDTH = 9;
	localparam MAX_SIZE	 = 256;	//with ADDR_WIDTH = 8 we have 256 bytes 
	localparam MEM_MODE  = 0;	//test std. memory mode

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
	
	
	logic	[15:0]				hello_mem[19:0];
	
	
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
		opcode_mem    	= 8'h0;		//select standard behaviour
		write_i_data  	= 32'h0; 		//write 0
		write_en_data 	= 1'b1;
		mask  			= 32'hC2;
		be_b		  	= 4'b1111; 		//select all bytes
		
		repeat(2) begin					//wait 2 clock cycles for reset operation
			@(posedge clk_system);
		end
	    rstn = 1'b1;


		 //upload 1st file
		 $readmemh("hello_1.hex", hello_mem);
		 
		

		
		//WRITE ROUTINE BLOCK 1
		repeat(20) begin
			write_i_data = hello_mem[ADDR/4];	
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
		ADDR = 9'h0;
		write_en_data 	= 1'b0;
		
		//READ ROUTINE (OK)
		repeat(20) begin
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
		
		
		
		
		
		ADDR =	9'h180;	//add 384 considering 3 data for each row
		$readmemh("hello_2.hex", hello_mem);
		write_en_data 	= 1'b1;
		
		
		//WRITE ROUTINE BLOCK 2
		repeat(20) begin
			write_i_data = hello_mem[(ADDR-9'h180)/4];	//start writing from location 32
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
		ADDR =	9'h180;	//add 384 considering 3 data for each row
		write_en_data 	= 1'b0;
		
		//READ ROUTINE BLOCK 2
		repeat(20) begin
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
				
		
		

	end

endmodule
