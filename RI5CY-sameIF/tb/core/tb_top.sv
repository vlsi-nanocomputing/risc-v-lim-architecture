// Copyright 2017 Embecosm Limited <www.embecosm.com>
// Copyright 2018 Robert Balas <balasr@student.ethz.ch>
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

// Top level wrapper for a RI5CY testbench
// Contributor: Robert Balas <balasr@student.ethz.ch>
//              Jeremy Bennett <jeremy.bennett@embecosm.com>


module tb_top
    #(parameter INSTR_RDATA_WIDTH = 32,
      parameter RAM_ADDR_WIDTH = 22,
      parameter MEM_MODE = 1,    //working mode for RT memory 1=LiM, 0=std 
      parameter BOOT_ADDR  = 'h180,
      parameter PULP_CLUSTER = 0,
      parameter FPU = 0,
      parameter PULP_ZFINX = 0,
      parameter DM_HALTADDRESS = 32'h1A110800);

    // comment to record execution trace
    //`define TRACE_EXECUTION

    const time CLK_PHASE_HI       = 5ns;
    const time CLK_PHASE_LO       = 5ns;
    const time CLK_PERIOD         = CLK_PHASE_HI + CLK_PHASE_LO;
    const time STIM_APPLICATION_DEL = CLK_PERIOD * 0.1;
    const time RESP_ACQUISITION_DEL = CLK_PERIOD * 0.9;
    const time RESET_DEL = STIM_APPLICATION_DEL;
    const int  RESET_WAIT_CYCLES  = 4;
    const int  FIRMWARE_WAIT_CYCLES = 6;


	//time parameter for racetrack
	
	const time CLK_M_PHASE_HI     = 1ns;
	const time CLK_M_PHASE_LO     = 1ns;
	
	const time BZs_PHASE_HI     = 10ns;
	const time BZs_PHASE_LO     = 10ns;
	
	const time r_init_LO		= 1ns;
	const time r_phase_HI		= 1ns;
	const time r_phase_LO		= 8ns;
	
	const time w_init_LO		= 3ns;
	const time w_phase_HI		= 1ns;
	const time w_phase_LO		= 6ns;

    //Variables for Execution time estimation
    time start_sim;
    time t_exec;


    // clock and reset for tb
    logic                   clk   = 'b1;
    logic                   rst_n = 'b0;

   
    // cycle counter
    int unsigned            cycle_cnt_q;

    // testbench result
    logic                   tests_passed;
    logic                   tests_failed;
    logic                   exit_valid;
    logic [31:0]            exit_value;

    // signals for ri5cy
    logic                   fetch_enable;

   //local parameter for RT size (bytes)
   localparam MAX_SIZE = 64000*4;	//128k words (256kB)


`ifdef RT_LIM_MEM    //racetrack memory part   

//Racetrack memory signals and parameters for initialization 

    //local parameter for memory initialization	(bytes)
    localparam MAX_SIZE_MEM = 16612; 	

    localparam words = MAX_SIZE_MEM/4; //compute number of words (32 bits)

    //dummy rom bytes
    logic	[7:0]    dummy_rom [MAX_SIZE_MEM-1:0];				
    //dummy rom word
    logic [31:0] dummy_rom_w [words-1:0]; //32 bit parallelism
    logic [RAM_ADDR_WIDTH-1:0]	rt_add='b0;

`endif  





	////////////////////////////////////////
	//ATTENTION: VCD DUMP DISABLED!!!!!
	////////////////////////////////////////

    // allow vcd dump
    initial begin
        if ($test$plusargs("vcd")) begin
           // $dumpfile("riscy_tb.vcd");
           // $dumpvars(0, tb_top);
          //  $dumpvars(1, tb_top.riscv_wrapper_i.ram_i.dp_ram_i.mem);

           
        end
    end

    // we either load the provided firmware or execute a small test program that
    // doesn't do more than an infinite loop with some I/O
    initial begin: load_prog
        automatic string firmware;
        automatic int prog_size = 6;

        // wait a few cycles
        repeat (FIRMWARE_WAIT_CYCLES) begin
            @(posedge clk); //TODO: was posedge, see below
        end

        if($value$plusargs("firmware=%s", firmware)) begin
            if($test$plusargs("verbose"))
                $display("[TESTBENCH] %t: loading firmware %0s ...",
                         $time, firmware);
            $readmemh(firmware, riscv_wrapper_i.ram_i.dp_ram_i.mem);

			
    ///////////////////////////
    // Racetrack memory initialization
    ///////////////////////////
			

`ifdef RT_LIM_MEM    //racetrack memory part   
    
            $display("Start RT memory initialization");

            //WRITE RACETRACK WITH READMEMH VALUES

            $readmemh(firmware, dummy_rom);	//initialize dummy_rom

			
            //initialize dummy word_rom
            for(int i=0; i<words; i++) begin
                dummy_rom_w[i] = {dummy_rom[i*4+3], dummy_rom[i*4+2], dummy_rom[i*4+1], dummy_rom[i*4+0]};
            end  

			force  riscv_wrapper_i.ram_i.dp_ram_i.addr_b_i              = rt_add;   //initialize address to 0
			force  riscv_wrapper_i.ram_i.dp_ram_i.we_b_i                = 1'b1;     //set write enable
			force  riscv_wrapper_i.ram_i.dp_ram_i.logic_in_memory_funct = '0;       //prevent LiM operations 
			force  riscv_wrapper_i.ram_i.dp_ram_i.we_b_funct_mem        = 1'b0;     //prevent LiM operations 
			force riscv_wrapper_i.ram_i.dp_ram_i.addr_b_range           = '0;       //prevent strange behaviours with range
			force  riscv_wrapper_i.ram_i.dp_ram_i.be_b_i                = '1;       //write all bytes


			//WRITE ROUTINE

			repeat(words) begin

				//force  riscv_wrapper_i.ram_i.dp_ram_i.wdata_b_i 	= 	dummy_rom_w[rt_add];
				force  riscv_wrapper_i.ram_i.dp_ram_i.wdata_b_i 	= 	dummy_rom_w[rt_add>>2];	//address now goes 4 by 4, butdummy_Rt_w uses std addresses
				force  riscv_wrapper_i.ram_i.dp_ram_i.en_b_i    	= 1'b1;

				//diplay initialization info				
				$display("Memory initialization: time=%0t addr_h=0x0h%h addr_d=%0d wdata=0x0h%h", $time, riscv_wrapper_i.ram_i.dp_ram_i.addr_b_i, rt_add>>2, riscv_wrapper_i.ram_i.dp_ram_i.wdata_b_i);

				repeat(1) begin				//wait 1 clock cycle
					@(posedge clk);
				end
				force  riscv_wrapper_i.ram_i.dp_ram_i.en_b_i	    = 1'b0;

				@(posedge riscv_wrapper_i.ram_i.dp_ram_i.rvalid_b_o );	//wait valid signal
				repeat(1) begin				//wait 1 clock cycle
					@(posedge clk);
				end


				rt_add = rt_add +4; //update index
				force  riscv_wrapper_i.ram_i.dp_ram_i.addr_b_i 		= rt_add; //update address in RT memory

			end

			repeat(3) begin         //wait 3 clock cycles
			    @(posedge clk);
			end



			//release signals
			release riscv_wrapper_i.ram_i.dp_ram_i.addr_b_i;
			release riscv_wrapper_i.ram_i.dp_ram_i.we_b_i;
			release riscv_wrapper_i.ram_i.dp_ram_i.wdata_b_i;
			release riscv_wrapper_i.ram_i.dp_ram_i.en_b_i;
			release riscv_wrapper_i.ram_i.dp_ram_i.logic_in_memory_funct;
			release riscv_wrapper_i.ram_i.dp_ram_i.we_b_funct_mem;
			release riscv_wrapper_i.ram_i.dp_ram_i.addr_b_range;
			release riscv_wrapper_i.ram_i.dp_ram_i.be_b_i;

`endif

			

        
            // make the core start fetching instruction immediately after the firmware is loaded in memory
            fetch_enable = '1;
            $display("Start simulaion time recording: time=%0t", $time);

        end else begin
            $display("No firmware specified");
            $finish;
        end
    end

    // clock generation
    initial begin: clock_gen
        forever begin
            #CLK_PHASE_HI clk = 1'b0;
            #CLK_PHASE_LO clk = 1'b1;
        end
    end: clock_gen

`ifdef RT_LIM_MEM    //racetrack memory part   

	///////////////////////////
	// Racetrack Signals generation
	///////////////////////////

	// Bz_s generation
    initial begin: Bz_s_gen
        forever begin
            #BZs_PHASE_HI  riscv_wrapper_i.ram_i.dp_ram_i.Bz_s_i = 1'b0;
            #BZs_PHASE_LO  riscv_wrapper_i.ram_i.dp_ram_i.Bz_s_i = 1'b1;
        end
    end: Bz_s_gen


	// magnetic clock generation
    initial begin: clock_m_gen
        forever begin
            #CLK_M_PHASE_HI  riscv_wrapper_i.ram_i.dp_ram_i.clk_m_i = 1'b0;
            #CLK_M_PHASE_LO  riscv_wrapper_i.ram_i.dp_ram_i.clk_m_i = 1'b1;
        end
    end: clock_m_gen
	
	// read current waveform generation
    initial begin: read_pulse_gen
        forever begin
            #r_init_LO   riscv_wrapper_i.ram_i.dp_ram_i.read_pulse_i = 1'b1;
            #r_phase_HI  riscv_wrapper_i.ram_i.dp_ram_i.read_pulse_i = 1'b0;
            #r_phase_LO  riscv_wrapper_i.ram_i.dp_ram_i.read_pulse_i = 1'b0;
        end
    end: read_pulse_gen
	
	// write current waveform generation
    initial begin: write_pulse_gen
        forever begin
            #w_init_LO   riscv_wrapper_i.ram_i.dp_ram_i.write_pulse_i = 1'b1;
            #w_phase_HI  riscv_wrapper_i.ram_i.dp_ram_i.write_pulse_i = 1'b0;
            #w_phase_LO  riscv_wrapper_i.ram_i.dp_ram_i.write_pulse_i = 1'b0;
        end
    end: write_pulse_gen

`endif

    // reset generation
    initial begin: reset_gen
        rst_n          = 1'b0;

        // wait a few cycles
        repeat (RESET_WAIT_CYCLES) begin
            @(posedge clk); //TODO: was posedge, see below
        end

        // start running
        #RESET_DEL rst_n = 1'b1;
        if($test$plusargs("verbose"))
            $display("reset deasserted", $time);

    end: reset_gen

    // set timing format
    initial begin: timing_format
        $timeformat(-9, 0, "ns", 9);
    end: timing_format

    // abort after n cycles, if we want to
    always_ff @(posedge clk, negedge rst_n) begin
        automatic int maxcycles;
        if($value$plusargs("maxcycles=%d", maxcycles)) begin
            if (~rst_n) begin
                cycle_cnt_q <= 0;
            end else begin
                cycle_cnt_q     <= cycle_cnt_q + 1;
                if (cycle_cnt_q >= maxcycles) begin
                    $fatal(2, "Simulation aborted due to maximum cycle limit");
                end
            end
        end
    end

    // check if we succeded
    always_ff @(posedge clk, negedge rst_n) begin
        if (tests_passed) begin
            $display("ALL TESTS PASSED");
            $finish;
        end
        if (tests_failed) begin
            $display("TEST(S) FAILED!");
            $finish;
        end
        if (exit_valid) begin
            if (exit_value == 0)
                $display("EXIT SUCCESS");
            else
                $display("EXIT FAILURE: %d", exit_value);
            t_exec = $time - start_sim;
            $display("Start simulation time : time=%0t, Finish simulaion time recording: time=%0t, Execution time=%0t", start_sim, $time, t_exec);
            $finish;
        end
    end

    // wrapper for riscv, the memory system and stdout peripheral
    riscv_wrapper
        #(.INSTR_RDATA_WIDTH (INSTR_RDATA_WIDTH),
          .RAM_ADDR_WIDTH (RAM_ADDR_WIDTH),
          .BOOT_ADDR (BOOT_ADDR),
          .PULP_CLUSTER (PULP_CLUSTER),
          .FPU(FPU),
          .PULP_ZFINX(PULP_ZFINX),
          .MAX_SIZE(MAX_SIZE),	//Memory size
          .MEM_MODE(MEM_MODE),
          .DM_HALTADDRESS (DM_HALTADDRESS))
    riscv_wrapper_i
        (.clk_i          ( clk          ),
         .rst_ni         ( rst_n        ),

         .fetch_enable_i ( fetch_enable ),
         .tests_passed_o ( tests_passed ),
         .tests_failed_o ( tests_failed ),
         .exit_valid_o   ( exit_valid   ),
         .exit_value_o   ( exit_value   ));

`ifndef VERILATOR
    initial begin
        assert (INSTR_RDATA_WIDTH == 128 || INSTR_RDATA_WIDTH == 32)
            else $fatal("invalid INSTR_RDATA_WIDTH, choose 32 or 128");
    end
`endif

endmodule // tb_top
