
package racetrack_defines;

	const time CLK_PHASE_HI       = 5ns;
	const time CLK_PHASE_LO       = 5ns;
	
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
	
	parameter WAIT_LIM_CYCLES   = 2;
		
	
	parameter FUNCT_NONE = 8'b00000000;
	parameter FUNCT_XOR  = 8'b00000001;
	parameter FUNCT_AND  = 8'b00000010;
	parameter FUNCT_OR   = 8'b00000011;
	parameter FUNCT_NAND = 8'b00001010;
	parameter FUNCT_NOR  = 8'b00001011;
	parameter FUNCT_XNOR = 8'b00001001;

	
	
;

endpackage
