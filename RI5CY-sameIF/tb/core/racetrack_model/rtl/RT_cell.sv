


module RT_cell
	
	(	input logic		rstn,
		input logic		forward_in,
		input logic		backward_in,
		input logic		current_s,
		input logic		current_m,
		
		output logic 	out
	);
	
	logic clk_i; //clock signal for FF
	logic sw_enable; //switch enable for FF
	logic D_ff_out;
	logic en; //enable for FF
	logic shift_in; //value for shift operation
	
	//STORAGE PART
	always @(posedge clk_i, negedge rstn) begin
       if ( !rstn) begin
			D_ff_out <= '0;
		end 
		else if(en) begin
			D_ff_out <= shift_in;
			
		end
	end
	
	assign en  = '1; //FF enable alsways active
	assign out = D_ff_out;
	
	//SELECTON PART
	assign shift_in = current_s ? backward_in : forward_in;
	
	//SWITCH ENABLE PART
	assign clk_i = current_m;
	
endmodule
	
	
	
	
	
	
	
	
	
	
	