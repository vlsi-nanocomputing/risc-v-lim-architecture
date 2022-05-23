
module mem_datapath
	#( parameter ADDR_WIDTH = 8, //256 bytes - 2 blocks
	   parameter MAX_SIZE	 = 1024,   	//max number of bytes		
	   parameter Nb  = 32, //Length racetrack
	   parameter Np  = 8, //N port
	   parameter Nr  = 4, //N racetrack in MU
	   parameter NMU = 8, //N Macro Unit
	   parameter CNT_WIDTH = 2 //only 2 bits required (max 3 shifts)
	)
	(
		input  logic 					clk_i,		//Sytem - FSM clock 
		input  logic					rstn_i,
		input  logic					clk_m_i,    //magnetic clock for shift operation
		input  logic					Bz_s_i,
		input  logic					en_ab_i,    //start memory transaction signal (a & b stands for instr and data)
		input  logic [3:0]				be_b_i,		//byte selector signal
		input  logic					write_pulse_i,
		input  logic					read_pulse_i,
		input  logic					range_active_i,
		input  logic [ADDR_WIDTH-1:0]	ADDR_i,
		input  logic [Nr*NMU-1:0]		write_i_data_i,
		input  logic					write_en_data_i, //single write enable for data (mask is written during LiM operation)
		input  logic [Nr*NMU-1:0]	    mask_i,
		input  logic [2:0]				logic_in_memory_funct_int_i,	
		
		output logic [Nr*NMU-1:0] 		r_data_o,
		output logic					r_valid_o
	);

	
	localparam bytes  = MAX_SIZE;		//NEW	
	localparam par    = Nr*NMU;			//data parallelism
	localparam words  = bytes/4; 		//number of 32bits words
	localparam blocks = words/Nb;		 
	localparam Nov = Nb - ((Nb/Np)*Np -(Nb/Np))-1;	//N of overhead cells within the racetrack
	localparam Nsp = Nb/Np;		
	
    logic 	[words-1:0]				word_lines;	  
	logic   [ADDR_WIDTH-1:0]		ADDR_i_dec;		//decoded address (std addr are incremented by 4)
	
	//======================================================================
    // ADDRESS MAPPING
    //====================================================================== 
	
	assign ADDR_i_dec		= ADDR_i>>2;	//decode std address	

	//======================================================================
    // ADDRESS DECODER
    //====================================================================== 
    /* Normal decoder*/
    always_comb begin
        for (int i=0; i<words; i++) begin
            word_lines[i] = 1'b0; //initiaize to 0 wordlines
        end
        word_lines[ADDR_i_dec] = 1'b1; //set to 1 active wordline
    end
	
	
	//======================================================================
    // RACETRACK MEMORY 
    //====================================================================== 
	RT_memory
	#(.ADDR_WIDTH(ADDR_WIDTH),
	  .MAX_SIZE(MAX_SIZE),
	  .Nr(Nr),
	  .Nb(Nb),	
	  .Np(Np),		
	  .NMU(NMU),		
	  .NWL(words),
	  .CNT_WIDTH(CNT_WIDTH)
	)
	racetrack_memory
	(
		.rstn_i(rstn_i),
		.clk_i(clk_i),		
		.clk_m_i(clk_m_i),	
		.Bz_s_i(Bz_s_i),  		
		.en_ab_i(en_ab_i),  
		.be_b_i(be_b_i),
		.range_active_i(range_active_i),
		.write_pulse_i(write_pulse_i),
		.read_pulse_i(read_pulse_i),
		.word_lines(word_lines),
		.write_data_i(write_i_data_i),
		.write_en_data_i(write_en_data_i),
		.mask_i(mask_i),
		.n_shift_i(ADDR_i_dec[1:0]),   
		.logic_in_memory_funct_int_i(logic_in_memory_funct_int_i),
		
		.data_o(r_data_o),
		.valid_o(r_valid_o)	
	);
	
endmodule
