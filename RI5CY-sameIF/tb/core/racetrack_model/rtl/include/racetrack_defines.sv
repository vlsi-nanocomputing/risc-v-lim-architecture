
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
	
	//NEED TO BE REMOVED AFTER RISC INTEGRATION
	parameter FUNCT_NONE = 3'b000;
	parameter FUNCT_XOR  = 3'b001;
	parameter FUNCT_AND  = 3'b010;
	parameter FUNCT_OR   = 3'b011;
	parameter FUNCT_MIN  = 3'b101;
	parameter FUNCT_MAX  = 3'b110;
	
	
;

endpackage