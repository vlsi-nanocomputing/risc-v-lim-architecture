

module shifter
	#( parameter N_WIDTH = 5,
	   parameter CNT_WIDTH = 5
		
	)
	(
		input  logic 					clk_i,
		input  logic 					init_i,
		input  logic 					rstn_i,
		input  logic [N_WIDTH-1:0]	    N_i,
	
		output logic					pulses,
		output logic					shift_done_o
	);

	logic [CNT_WIDTH-1:0] 	cnt_int; 
	logic					cnt_en;
	logic					cmp_int;
	logic					clk_en;
	logic					shift_en;
	logic					cl;

//COUNTER
	always_ff @(posedge clk_i, negedge rstn_i, negedge cl) begin
		if(!rstn_i) begin
			cnt_int <= '0;
		end else
			if(!cl) begin
				cnt_int <= '0;
			end else if(cnt_en) begin
				cnt_int <= cnt_int + 1'b1;
			end
	end

//COMPARATOR

	always_comb begin
		cmp_int = 1'b0;
		
		if(N_i==cnt_int) begin
			cmp_int = 1'b1;
		end
	end

//CLOCK GATING	
	always_ff @(negedge clk_i, negedge rstn_i)
		if(!rstn_i)begin
			clk_en <= 1'b0;
		end
		else begin
			clk_en <= shift_en;
		end

//SIGNAL ASSIGNMENTS

	assign shift_en = !cmp_int & init_i;  
	assign cnt_en   = !cmp_int & init_i; 
	assign pulses   = clk_en & clk_i;
	assign cl		= init_i;
	assign shift_done_o 	= cmp_int;

endmodule
