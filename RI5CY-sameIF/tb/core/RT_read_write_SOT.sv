


module RT_read_write_SOT
	
	(	input logic		rstn,
		input logic		forward_in,
		input logic		backward_in,
		input logic		current_s,	  //write current_s terminal
		input logic		current_m,	  //write current_m terminal
		input logic		read_current, //read_current terminal
		input logic		write_input,  //write terminal
		input logic		write_enable,
		
		output logic 	out,   		 //out for racetrack connection
		output logic	read_out	 //read terminal
	);
	
	
	
	logic D_ff_out;
	logic D_ff_in;
	logic read_in;
	logic clk_i;
	logic en; 		//enable for FF
	logic shift_in; //value for shift operation
	
	//STORAGE PART
	always @(posedge clk_i, negedge rstn) begin
       if ( !rstn ) begin
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
	
	
	assign en  	   = '1; //FF enable alsways active
	assign out 	   = D_ff_out;
	assign read_in = D_ff_out;
	
	//SELECTON PART
	assign shift_in = current_s ? backward_in : forward_in;
	assign D_ff_in  = write_enable ? write_input : shift_in;
	
	//SWITCH ENABLE PART
	assign clk_i = current_m | write_enable;
	
endmodule
	
	
	
	
	
	
	
	
	
	
	
