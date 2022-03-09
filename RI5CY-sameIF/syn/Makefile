# Synthesis Makefile

# ===================================================================
# Variables
# ===================================================================
# Design Compiler configuration
DC_SCRIPT             = dc_synthesis.tcl
DC_SHELL              = dc_shell-t

# ===================================================================
# Default target
# ===================================================================
# assume dc-syn if no target chosen
.DEFAULT_GOAL := dc-syn-riscv

# ===================================================================
# Design compiler synthesis
# ===================================================================
# run synthesis riscv
.riscv:
	touch .riscv

.PHONY: dc-syn-riscv
dc-syn-riscv: .riscv
	mkdir netlist reports ; \
	$(DC_SHELL) -f $(DC_SCRIPT) ; \
        rm .riscv

# run synthesis memory
.mem:
	touch .mem

.PHONY: dc-syn-mem
dc-syn-mem: .mem
	mkdir netlist reports ; \
	$(DC_SHELL) -f $(DC_SCRIPT) ; \
        rm .mem

# clean synthesis results
.PHONY: clean
clean:
	rm -r netlist reports work ; \
	rm command.log default.svf filenames.log
