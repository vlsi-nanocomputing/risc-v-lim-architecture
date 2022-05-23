import racetrack_defines::*; //REMOVE AFTER RISC INTEGRATION

module mem_datapath
	#( parameter ADDR_WIDTH = 9, 
	  	   
	   parameter MAX_SIZE	 = 1032,	//New value multiple of 2 and multiple of 3 (258 words)
	   
	   parameter Nb  = 32, //Length racetrack
	   parameter Np  = 8, //N port
	   parameter Nr  = 4, //N racetrack in MU
	   parameter NMU = 8, //N Macro Unit
	   parameter CNT_WIDTH = 2, //only 2 bits required (max 3 shifts)
	   parameter MEM_MODE = 1	//std. mode is LiM
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
		input  logic [7:0]				logic_in_memory_funct_int_i,	
		
		output logic [Nr*NMU-1:0] 		r_data_o,
		output logic					r_valid_o
	);
	
	localparam bytes   		= MAX_SIZE;		
	localparam par     		= Nr*NMU;							//data parallelism
	localparam words   		= bytes/4; 							//number of 32bits words
	localparam words_tri	= words*3;							//number of words in std. mem. mode
	localparam blocks  		= words/Nb;		 
	localparam Nov 	   		= Nb - ((Nb/Np)*Np -(Nb/Np))-1;		//N of overhead cells within the racetrack
	localparam Nsp 	   		= Nb/Np;		
	localparam triplets 	= words_tri/3;						//number of triplets
	
	
    logic 	[words-1:0]				word_lines;	 
	logic 	[words-1:0]				word_lines_lim;	 
	logic 	[words_tri-1:0]			word_lines_tri;	 
	logic	[triplets-1:0]			active_triplet;
	logic   [ADDR_WIDTH-1:0]		ADDR_int;		//output of address mux
	logic	[ADDR_WIDTH-1:0]		ADDR_std_mode;	//signal for address manipulation in std. mem. mode
	logic       					word_sel;
	logic	[2:0]					word_sel_tri;
	logic	[1:0]					n_shift;
	logic   [ADDR_WIDTH-1:0]		ADDR_i_dec;		//decoded address (std addr are incremented by 4)
	
	//======================================================================
    // ADDRESS MAPPING (std. mem mode) & SELECTION
    //====================================================================== 
	
	assign ADDR_i_dec		= ADDR_i>>2;	//decode std address
		
	assign ADDR_std_mode 	= ADDR_i_dec /3; 
	
	assign ADDR_int 		= (MEM_MODE) ? ADDR_i_dec : ADDR_std_mode;
	
	assign n_shift 			= ADDR_int[1:0]; //In LiM mode takes addr_dec, in std. mem . mode takes addr_dec/3
	
	
	//======================================================================
    // STD. MEM. WORDLINE DECODER
    //====================================================================== 
	
	/*ACTIVE TRIPLET SELECTION	*/
	genvar i;
	
	generate
		for (i=0; i<words_tri; i=i+3) begin	: gen_active_triplet
			assign active_triplet[i/3] = (word_lines_tri[i] || word_lines_tri[i+1] || word_lines_tri[i+2]) ;	//AND with MEM_MODE bit to prevent
		end																													//unwanted activation
	
	endgenerate
	
	
	/*	TRIPLET WORD SELECTION	*/
	always_comb begin
	word_sel_tri = 3'b0;
		for(int i=0; i<triplets; i++) begin
			if(active_triplet[i])begin
				word_sel_tri[0] = word_lines_tri[i*3];
				word_sel_tri[1] = word_lines_tri[i*3+1];
				word_sel_tri[2] = word_lines_tri[i*3+2];
			end
		end
	end
	
	//std_wordlines: wordlines for std. mem. mode
	always_comb begin
        for (int i=0; i<words_tri; i++) begin
            word_lines_tri[i] = 1'b0; //initiaize to 0 wordlines
        end
	   word_lines_tri[ADDR_i_dec] = 1'b1 & !MEM_MODE; //NEW
    end
	
	
	//======================================================================
    // LiM WORDLINE DECODER
    //====================================================================== 
    always_comb begin
        for (int i=0; i<words; i++) begin
            word_lines_lim[i] = 1'b0; //initiaize to 0 wordlines
        end
	   word_lines_lim[ADDR_i_dec] = 1'b1 & MEM_MODE;; //set to 1 active wordline
    end
	
	
	//======================================================================
    // WORDLINE MUX
    //====================================================================== 
	
	assign word_lines = (MEM_MODE) ? word_lines_lim : active_triplet; 	//MEM_MODE = 1 LiM mode
	
	
	
	
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
	  .CNT_WIDTH(CNT_WIDTH),
	  .MEM_MODE(MEM_MODE)
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
		.n_shift_i(n_shift), 
		.logic_in_memory_funct_int_i(logic_in_memory_funct_int_i),
		.word_sel_i(word_sel_tri),
		
		.data_o(r_data_o),
		.valid_o(r_valid_o)	
	);
	
endmodule
