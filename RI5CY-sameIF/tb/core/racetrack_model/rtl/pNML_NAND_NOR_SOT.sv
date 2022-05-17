
module pNML_NAND_NOR_SOT
	
	(	input logic		IN1_NAND_NOR_sel,
		input logic		rstn,
		input logic		IN2,
		input logic		IN3,
		input logic		forward_in,
		input logic		backward_in,
		input logic		Bz_s,
		input logic		Bz_m,
		input logic		read_current, //read_current terminal
		input logic		current_s,
		input logic		current_m,
		
		output logic 	out,    //out for racetrack connection
		output logic	read_out//read terminal
	);
	

	logic D_ff_in;
	logic D_ff_out;
	logic read_in;
	logic clk_i;
	logic en; //enable for FF
	logic NAND_out;
	logic NOR_out;
	logic eval_out; //output of logic operation selection
	logic shift_in; //value for shift operation
	
	//STORAGE PART
	always_ff @(posedge clk_i, negedge rstn) begin
       if (!rstn) begin
			D_ff_out <= '0;
		end 
		else if(en) begin
			D_ff_out <= D_ff_in;
			
		end
	end
	
	//READ CIRCUIT
	always @(posedge read_current, negedge rstn) begin
       if ( !rstn ) begin
			read_out <= '0;
		end 
		else if(en) begin
			read_out <= read_in;
			
		end
	end
	
	
	assign read_in = D_ff_out;
	assign en  	   = '1; //FF enable alsways active
	assign out     = D_ff_out;
	
	
	//LOGIC PART
	assign NAND_out	= ~(IN2 & IN3);
	assign NOR_out	= ~(IN2 | IN3);
	
	//SELECTON PART
	assign eval_out  = IN1_NAND_NOR_sel ? NAND_out : NOR_out; // 1 for NAND, 0 for NOR_out
	assign shift_in = current_s ? backward_in : forward_in;
	assign D_ff_in   = current_m ? shift_in : eval_out; //shift operation is privileged
	
	//SWITCH ENABLE PART
	assign clk_i = ((Bz_s ^ D_ff_out) & Bz_m) | current_m;
	
endmodule
	
	
	
	
	
	
	
	
	
	
	
	
