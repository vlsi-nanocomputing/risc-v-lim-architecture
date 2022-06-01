# Copyright 2019 Clifford Wolf
# Copyright 2019 Robert Balas
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
# REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
# INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
# LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
# OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
# PERFORMANCE OF THIS SOFTWARE.

# Author: Robert Balas (balasr@iis.ee.ethz.ch)
# Description: All in one. Uses parts of picorv32's makefile for handling the
# firmware and handling csmith programs


# ===================================================================
# Variables
# ===================================================================
MAKE			= make
CTAGS			= ctags
CSMITH			= csmith

# vsim configuration
VLIB			= vlib
VWORK			= work

VLOG			= vlog
VLOG_FLAGS		= -pedanticerrors -suppress 2577 -suppress 2583
VLOG_LOG                = vloggy

VOPT			= vopt
VOPT_FLAGS		= -debugdb -fsmdebug -pedanticerrors +acc#=mnprft

VSIM			= vsim
VSIM_HOME               = /usr/pack/modelsim-kgf/questasim
VSIM_FLAGS              = -voptargs=+acc
ALL_VSIM_FLAGS		= $(VSIM_FLAGS)
VSIM_DEBUG_FLAGS	= -debugdb
VSIM_GUI_DEBUG_FLAGS    = -gui -debugdb
VSIM_GUI_FLAGS          = -gui
VSIM_SCRIPT             = vsim.tcl

VCS                     = bash vcs
# VCS_HOME                = ${VCS_HOME}
VCS_FLAGS               = -LDFLAGS -Wl,--no-as-needed
SIMV_FLAGS              = +vcdfile 

# verilator configuration
VERILATOR		= verilator
VERI_FLAGS              +=
VERI_COMPILE_FLAGS      += -Wno-BLKANDNBLK # hope this doesn't hurt us in the long run
VERI_TRACE              =
VERI_DIR                = cobj_dir
VERI_CFLAGS             = -O2

# RTL source files
RTLSRC_HOME             := ../..
RTLSRC_TB_PKG		:=
RTLSRC_TB_TOP		:= tb_top.sv
RTLSRC_TB		:= $(filter-out riscv_tb_pkg.sv tb_top_verilator.sv,\
				$(wildcard *.sv))
RTLSRC_VERI_TB          := $(filter-out tb_top.sv, $(wildcard *.sv))
RTLSRC_INCDIR           := $(RTLSRC_HOME)/rtl/include
RTLSRC_PKG		:= $(RTLSRC_HOME)/rtl/fpnew/src/fpnew_pkg.sv \
				$(addprefix $(RTLSRC_HOME)/rtl/include/,\
				apu_core_package.sv riscv_defines.sv \
				riscv_tracer_defines.sv ../../tb/tb_riscv/include/perturbation_defines.sv)
RTLSRC			:= $(filter-out $(RTLSRC_HOME)/rtl/riscv_register_file_latch.sv,\
				$(wildcard $(RTLSRC_HOME)/rtl/*.sv) $(RTLSRC_HOME)/tb/tb_riscv/riscv_random_stall.sv $(RTLSRC_HOME)/tb/tb_riscv/riscv_random_interrupt_generator.sv)
RTLSRC_FPNEW_INCDIR := $(RTLSRC_HOME)/rtl/fpnew/src/common_cells/include
RTLSRC_FPNEWPKG     := $(RTLSRC_HOME)/rtl/fpnew/src/fpu_div_sqrt_mvp/hdl/defs_div_sqrt_mvp.sv
RTLSRC_FPNEW        := $(wildcard $(RTLSRC_HOME)/rtl/fpnew/src/*.sv) $(wildcard $(RTLSRC_HOME)/rtl/fpnew/src/fpu_div_sqrt_mvp/hdl/*.sv) \
                    $(wildcard $(RTLSRC_HOME)/rtl/fpnew/src/common_cells/src/*.sv) $(wildcard $(RTLSRC_HOME)/rtl/fpnew/src/common_cells/src/deprecated/*.sv)
# TODO: clean this up
RTLSRC_VLOG_TB_TOP	:= $(basename $(notdir $(RTLSRC_TB_TOP)))
RTLSRC_VOPT_TB_TOP	:= $(RTLSRC_VLOG_TB_TOP)#$(addsuffix _vopt, $(RTLSRC_VLOG_TB_TOP))

# riscv toolchain install path
RISCV_LIB               ?= /home/thesis/gianluca.goti/riscv-compiler-ext-inv
RISCV_EXE_PREFIX         = $(RISCV_LIB)/bin/riscv32-unknown-elf-

# firmware vars
FIRMWARE                 = firmware/
RISCV_TEST_INCLUDES      = -Iriscv_tests/ -Iriscv_tests/macros/scalar \
				-Iriscv_tests/rv64ui -Iriscv_tests/rv64um -Iriscv_tests/rv64ua
FIRMWARE_OBJS		 = $(addprefix firmware/, start.o \
				print.o sieve.o multest.o stats.o)
FIRMWARE_TEST_OBJS       = $(addsuffix .o, \
				$(basename $(wildcard riscv_tests/rv32ui/*.S)) \
				$(basename $(wildcard riscv_tests/rv32um/*.S)) \
				$(basename $(wildcard riscv_tests/rv32uc/*.S)))

COMPLIANCE_TEST_OBJS	 = $(addsuffix .o, \
				$(basename $(wildcard riscv_compliance_tests/*.S)))

# csmith vars
CSMITH_INCLUDE           = ~/.local/include/csmith-2.4.0
CSMITH_TIMEOUT_REF       = 2
CSMITH_TIMEOUT_VSIM      = 3000
CSMITH_TIMEOUT_VERI      = 100

# GCC configuration
CUSTOM_GCC_FLAGS         =

# ===================================================================
# Default and all targets
# ===================================================================
# assume vsim if no target chosen
.DEFAULT_GOAL := firmware-vsim-run

all: firmware-vsim-run

# ===================================================================
# Modelsim testbench compilation
# ===================================================================
vlib: .lib-rtl

.lib-rtl:
	$(VLIB) $(VWORK)
	touch .lib-rtl

# rebuild if we change some sourcefile
.build-rtl: .lib-rtl $(RTLSRC_PKG) $(RTLSRC) $(RTLSRC_TB_PKG) $(RTLSRC_TB)
	$(VLOG) -work $(VWORK) +incdir+$(RTLSRC_INCDIR) $(VLOG_FLAGS) \
	$(RTLSRC_PKG) $(RTLSRC) $(RTLSRC_TB_PKG) $(RTLSRC_TB)
	touch .build-rtl

vsim-all: .build-rtl

.opt-rtl: .build-rtl
	$(VOPT) -work $(VWORK) $(VOPT_FLAGS) $(RTLSRC_VLOG_TB_TOP) -o \
	$(RTLSRC_VOPT_TB_TOP)
	touch .opt-rtl

# rebuild if we change some sourcefile
.build-rtl-fp: .lib-rtl $(RTLSRC_PKG) $(RTLSRC_FPNEWPKG) $(RTLSRC_FPNEW) $(RTLSRC) $(RTLSRC_TB_PKG) $(RTLSRC_TB)
	$(VLOG) -work $(VWORK) +incdir+$(RTLSRC_INCDIR) +incdir+$(RTLSRC_FPNEW_INCDIR) $(VLOG_FLAGS) \
	$(RTLSRC_PKG) $(RTLSRC_FPNEWPKG) $(RTLSRC_FPNEW) $(RTLSRC) $(RTLSRC_TB_PKG) $(RTLSRC_TB)
	touch .build-rtl-fp

vsim-all-fp: .opt-rtl-fp

.opt-rtl-fp: .build-rtl-fp
	$(VOPT) -work $(VWORK) $(VOPT_FLAGS) -g FPU=1 $(RTLSRC_VLOG_TB_TOP) -o \
	$(RTLSRC_VOPT_TB_TOP)
	touch .opt-rtl-fp

.PHONY: dpiheader
dpiheader: .build-tb
	$(VLOG) -work $(VWORK) -l $(VLOG_LOG) -dpiheader $(DPINAME) $(DPISRC)

# ===================================================================
# VCS testbench compilation
# ===================================================================
#ORIGIANL TIMESCALE -timescale=1ns/1ps 

vcsify: $(RTLSRC_PKG) $(RTLSRC) $(RTLSRC_TB_PKG) $(RTLSRC_TB)
	$(VCS) +vc -sverilog -race=all -ignore unique_checks -full64 \
		-timescale=1ns/1ns -j20\
		-CC "-I$(VCS_HOME)/include -O3 -march=native" $(VCS_FLAGS) \
		$(RTLSRC_PKG) $(RTLSRC) $(RTLSRC_TB_PKG) $(RTLSRC_TB) \
		+incdir+$(RTLSRC_INCDIR) 

vcs-run: vcsify firmware/firmware.hex
	./simv $(SIMV_FLAGS)

vcs-run-xnor: vcsify custom/xnor_net.hex
	./simv $(SIMV_FLAGS) "+firmware=custom/xnor_net.hex"
	mv trace_core_00_0.log TraceAlgorithms/xnor_net.log

vcs-run-bitwise: vcsify custom/bitwise.hex
	./simv $(SIMV_FLAGS) "+firmware=custom/bitwise.hex"
	mv trace_core_00_0.log TraceAlgorithms/bitwise.log

vcs-run-bitmap: vcsify custom/bitmap_search.hex
	./simv $(SIMV_FLAGS) "+firmware=custom/bitmap_search.hex"
	mv trace_core_00_0.log TraceAlgorithms/bitmap.log

vcs-run-transport: vcsify custom/transport_min_cost.hex
	./simv $(SIMV_FLAGS) "+firmware=custom/transport_min_cost.hex"
	mv trace_core_00_0.log TraceAlgorithms/transport.log

vcs-run-aes: vcsify custom/aes128_addroundkey.hex
	./simv $(SIMV_FLAGS) "+firmware=custom/aes128_addroundkey.hex"
	mv trace_core_00_0.log TraceAlgorithms/aes.log

vcs-run-max_min: vcsify custom/max_min.hex
	./simv $(SIMV_FLAGS) "+firmware=custom/max_min.hex"
	mv trace_core_00_0.log TraceAlgorithms/max_min.log


#LIM PROGRAMS
vcs-run-xnorlim: vcsify custom/xnor_net_lim.hex
	./simv $(SIMV_FLAGS) "+firmware=custom/xnor_net_lim.hex"
	mv trace_core_00_0.log TraceAlgorithms/xnor_net_lim.log

vcs-run-test_lim: vcsify custom/test_lim.hex
	./simv $(SIMV_FLAGS) "+firmware=custom/test_lim.hex"

vcs-run-bitwise_lim: vcsify custom/bitwise_lim.hex
	./simv $(SIMV_FLAGS) "+firmware=custom/bitwise_lim.hex"
	mv trace_core_00_0.log TraceAlgorithms/bitwise_lim.log

vcs-run-bitmap_lim: vcsify custom/bitmap_search_lim.hex
	./simv $(SIMV_FLAGS) "+firmware=custom/bitmap_search_lim.hex"
	mv trace_core_00_0.log TraceAlgorithms/bitmap_lim.log

vcs-run-aes_lim: vcsify custom/aes128_addroundkey_lim.hex
	./simv $(SIMV_FLAGS) "+firmware=custom/aes128_addroundkey_lim.hex"
	mv trace_core_00_0.log TraceAlgorithms/aes_lim.log

vcs-run-max_min_lim: vcsify custom/max_min_lim.hex
	./simv $(SIMV_FLAGS) "+firmware=custom/max_min_lim.hex"
	mv trace_core_00_0.log TraceAlgorithms/max_min_lim.log

vcs-run-transport_lim: vcsify custom/transport_min_cost_lim.hex
	./simv $(SIMV_FLAGS) "+firmware=custom/transport_min_cost_lim.hex"
	mv trace_core_00_0.log TraceAlgorithms/transport_lim.log

#Run programs for RT memory

vcs-run-bitwise-ext-asm-rt: vcsify custom/bitwise_lim_ext_asm.hex
	./simv $(SIMV_FLAGS) "+firmware=custom/bitwise_lim_ext_asm.hex" +verbose +t 1ns +j20 
	mv trace_core_00_0.log TraceAlgorithms/bitwise_lim_ext_asm_RT.log

vcs-run-bitwise-ext-inv-asm-rt: vcsify custom/bitwise_lim_ext_inv_asm.hex
	./simv $(SIMV_FLAGS) "+firmware=custom/bitwise_lim_ext_inv_asm.hex" +verbose +t 1ns +j20 
	mv trace_core_00_0.log TraceAlgorithms/bitwise_lim_ext_inv_asm_RT.log










vcs-run-gui: VCS_FLAGS+=-debug_all
vcs-run-gui: vcsify firmware/firmware.hex
	./simv $(SIMV_FLAGS) -gui

vcs-clean:
	rm -rf simv* *.daidir *.vpd *.db csrc ucli.key vc_hdrs.h

# ===================================================================
# Verilator testbench compilation
# ===================================================================d dumping. This hacky part is required
# because we need to conditionally compile the testbench (-DVCD_TRACE) and pass
# the --trace flags to the verilator call
ifeq ($(findstring +vcd,$(VERI_FLAGS)),+vcd)
VERI_TRACE="--trace"
VERI_CFLAGS+="-DVCD_TRACE"
endif

verilate: testbench_verilator

testbench_verilator: $(RTLSRC_PKG) $(RTLSRC_VERI_TB) $(RTLSRC)
	$(VERILATOR) --cc --sv --exe \
		$(VERI_TRACE) \
		--Wno-lint --Wno-UNOPTFLAT \
		--Wno-MODDUP +incdir+$(RTLSRC_INCDIR) --top-module \
		tb_top_verilator $(RTLSRC_PKG) $(RTLSRC_VERI_TB) $(RTLSRC) \
		tb_top_verilator.cpp --Mdir $(VERI_DIR) \
		-CFLAGS "-std=gnu++11 $(VERI_CFLAGS)" \
		$(VERI_COMPILE_FLAGS)
	$(MAKE) -C $(VERI_DIR) -f Vtb_top_verilator.mk
	cp $(VERI_DIR)/Vtb_top_verilator testbench_verilator

verilate-clean:
	if [ -d $(VERI_DIR) ]; then rm -r $(VERI_DIR); fi
	rm -rf testbench_verilator

# run tb and exit
.PHONY: vsim-run
vsim-run: ALL_VSIM_FLAGS += -c
vsim-run: vsim-all
	$(VSIM) $(ALL_VSIM_FLAGS) \
	$(RTLSRC_VOPT_TB_TOP) -do 'source $(VSIM_SCRIPT); exit -f'

# run tb and drop into interactive shell
.PHONY: vsim-run-sh
vsim-run-sh: ALL_VSIM_FLAGS += -c
vsim-run-sh: vsim-all
	$(VSIM) -work $(VWORK) $(ALL_VSIM_FLAGS) \
	$(RTLSRC_VOPT_TB_TOP) -do $(VSIM_SCRIPT)

# run tb with simulator gui
.PHONY: vsim-run-gui
vsim-run-gui: ALL_VSIM_FLAGS += $(VSIM_GUI_FLAGS)
vsim-run-gui: vsim-all
	$(VSIM) $(ALL_VSIM_FLAGS) \
	work.tb_top -do $(VSIM_SCRIPT)

.PHONY: tb-clean
tb-clean:
	if [ -d $(VWORK) ]; then rm -r $(VWORK); fi
	rm -f transcript vsim.wlf vsim.dbg trace_core*.log \
	.build-rtl .opt-rtl .lib-rtl *.vcd objdump

# run tb and exit
.PHONY: vsim-run-fp
vsim-run-fp: ALL_VSIM_FLAGS += -c
vsim-run-fp: vsim-all-fp
	$(VSIM) -work $(VWORK) $(ALL_VSIM_FLAGS) -GFPU=1 \
	$(RTLSRC_VOPT_TB_TOP) -do 'source $(VSIM_SCRIPT); exit -f'

# run tb and drop into interactive shell
.PHONY: vsim-run-sh-fp
vsim-run-sh-fp: ALL_VSIM_FLAGS += -c
vsim-run-sh-fp: vsim-all-fp
	$(VSIM) -work $(VWORK) $(ALL_VSIM_FLAGS) \
	$(RTLSRC_VOPT_TB_TOP) -do $(VSIM_SCRIPT)

# run tb with simulator gui
.PHONY: vsim-run-gui-fp
vsim-run-gui-fp: ALL_VSIM_FLAGS += $(VSIM_GUI_FLAGS)
vsim-run-gui-fp: vsim-all-fp
	$(VSIM) -work $(VWORK) $(ALL_VSIM_FLAGS) -GFPU=1 \
	$(RTLSRC_VOPT_TB_TOP) -do $(VSIM_SCRIPT)

.PHONY: tb-clean-fp
tb-clean-fp:
	if [ -d $(VWORK) ]; then rm -r $(VWORK); fi
	rm -f transcript vsim.wlf vsim.dbg trace_core*.log \
	.build-rtl-fp .opt-rtl-fp .lib-rtl-fp *.vcd objdump

# ===================================================================
# Programs compilation and run
# ===================================================================
# rules to generate hex (loadable by simulators) from elf
%.hex: %.elf
	$(RISCV_EXE_PREFIX)objcopy -O verilog $< $@

# Running custom programs:
# This is an example for running a custom program in the testbench
# We link with our custom crt0.s and syscalls.c against newlib so that we can
# use the c standard library
# Change the program name to compile your own program
custom/bitmap_search.elf: custom/bitmap_search.c
	$(RISCV_EXE_PREFIX)gcc -march=rv32ima -o $@ -w -Os -g -nostdlib \
		$(CUSTOM_GCC_FLAGS) \
		-T custom/link.ld \
		-static \
		custom/crt0.S \
		$^ custom/syscalls.c custom/vectors.S \
		-I $(RISCV_LIB)/riscv32-unknown-elf/include \
		-L $(RISCV_LIB)/riscv32-unknown-elf/lib \
		-lc -lm -lgcc

custom/bitwise.elf: custom/bitwise.c
	$(RISCV_EXE_PREFIX)gcc -march=rv32ima -o $@ -w -Os -g -nostdlib \
		$(CUSTOM_GCC_FLAGS) \
		-T custom/link.ld \
		-static \
		custom/crt0.S \
		$^ custom/syscalls.c custom/vectors.S \
		-I $(RISCV_LIB)/riscv32-unknown-elf/include \
		-L $(RISCV_LIB)/riscv32-unknown-elf/lib \
		-lc -lm -lgcc

custom/transport_min_cost.elf: custom/transport_min_cost.c
	$(RISCV_EXE_PREFIX)gcc -march=rv32ima -o $@ -w -Os -g -nostdlib \
		$(CUSTOM_GCC_FLAGS) \
		-T custom/link.ld \
		-static \
		custom/crt0.S \
		$^ custom/syscalls.c custom/vectors.S \
		-I $(RISCV_LIB)/riscv32-unknown-elf/include \
		-L $(RISCV_LIB)/riscv32-unknown-elf/lib \
		-lc -lm -lgcc

custom/aes128_addroundkey.elf: custom/aes128_addroundkey.c
	$(RISCV_EXE_PREFIX)gcc -march=rv32ima -o $@ -w -Os -g -nostdlib \
		$(CUSTOM_GCC_FLAGS) \
		-T custom/link.ld \
		-static \
		custom/crt0.S \
		$^ custom/syscalls.c custom/vectors.S \
		-I $(RISCV_LIB)/riscv32-unknown-elf/include \
		-L $(RISCV_LIB)/riscv32-unknown-elf/lib \
		-lc -lm -lgcc

custom/max_min.elf: custom/max_min.c
	$(RISCV_EXE_PREFIX)gcc -march=rv32ima -o $@ -w -Os -g -nostdlib \
		$(CUSTOM_GCC_FLAGS) \
		-T custom/link.ld \
		-static \
		custom/crt0.S \
		$^ custom/syscalls.c custom/vectors.S \
		-I $(RISCV_LIB)/riscv32-unknown-elf/include \
		-L $(RISCV_LIB)/riscv32-unknown-elf/lib \
		-lc -lm -lgcc

custom/hello_world.elf: custom/hello_world.c
	$(RISCV_EXE_PREFIX)gcc -march=rv32ima -o $@ -w -Os -g -nostdlib \
		$(CUSTOM_GCC_FLAGS) \
		-T custom/link.ld \
		-static \
		custom/crt0.S \
		$^ custom/syscalls.c custom/vectors.S \
		-I $(RISCV_LIB)/riscv32-unknown-elf/include \
		-L $(RISCV_LIB)/riscv32-unknown-elf/lib \
		-lc -lm -lgcc

custom/xnor_net.elf: custom/xnor_net.c
	$(RISCV_EXE_PREFIX)gcc -march=rv32ima -mabi=ilp32 -o $@ -w -Os -g -nostdlib \
		$(CUSTOM_GCC_FLAGS) \
		-T custom/link.ld \
		-static \
		custom/crt0.S \
		$^ custom/syscalls.c custom/vectors.S \
		-I $(RISCV_LIB)/riscv32-unknown-elf/include \
		-L $(RISCV_LIB)/riscv32-unknown-elf/lib \
		-lc -lm -lgcc

custom/test_lim.elf: custom/test_lim.c
	$(RISCV_EXE_PREFIX)gcc -march=rv32ima -mabi=ilp32 -o $@ -w -Os -g -nostdlib \
		$(CUSTOM_GCC_FLAGS) \
		-T custom/link.ld \
		-static \
		custom/crt0.S \
		$^ custom/syscalls.c custom/vectors.S \
		-I $(RISCV_LIB)/riscv32-unknown-elf/include \
		-L $(RISCV_LIB)/riscv32-unknown-elf/lib \
		-lc -lm -lgcc

custom/xnor_net_lim.elf: custom/xnor_net_lim.c
	$(RISCV_EXE_PREFIX)gcc -march=rv32ima -mabi=ilp32 -o $@ -w -Os -g -nostdlib \
		$(CUSTOM_GCC_FLAGS) \
		-T custom/link.ld \
		-static \
		custom/crt0.S \
		$^ custom/syscalls.c custom/vectors.S \
		-I $(RISCV_LIB)/riscv32-unknown-elf/include \
		-L $(RISCV_LIB)/riscv32-unknown-elf/lib \
		-lc -lm -lgcc

custom/bitwise_lim_ext_asm.elf: custom/bitwise_lim_ext_asm.c
	$(RISCV_EXE_PREFIX)gcc -march=rv32ima -mabi=ilp32 -o $@ -w -Os -g -nostdlib \
		$(CUSTOM_GCC_FLAGS) \
		-T custom/link.ld \
		-static \
		custom/crt0.S \
		$^ custom/syscalls.c custom/vectors.S \
		-I $(RISCV_LIB)/riscv32-unknown-elf/include \
		-L $(RISCV_LIB)/riscv32-unknown-elf/lib \
		-lc -lm -lgcc

custom/bitwise_lim_ext_inv_asm.elf: custom/bitwise_lim_ext_inv_asm.c
	$(RISCV_EXE_PREFIX)gcc -march=rv32ima -mabi=ilp32 -o $@ -w -Os -g -nostdlib \
		$(CUSTOM_GCC_FLAGS) \
		-T custom/link.ld \
		-static \
		custom/crt0.S \
		$^ custom/syscalls.c custom/vectors.S \
		-I $(RISCV_LIB)/riscv32-unknown-elf/include \
		-L $(RISCV_LIB)/riscv32-unknown-elf/lib \
		-lc -lm -lgcc




custom-clean:
	find ./custom -maxdepth 1 -not -name '*lim.hex' -name '*.hex' -delete && rm ./custom/*.elf

.PHONY: custom-vsim-run
custom-vsim-run: vsim-all custom/hello_world.hex
custom-vsim-run: ALL_VSIM_FLAGS += "+firmware=custom/hello_world.hex"
custom-vsim-run: vsim-run

.PHONY: custom-vsim-run-xnor_net
custom-vsim-run-xnor_net: vsim-all custom/xnor_net.hex
custom-vsim-run-xnor_net: ALL_VSIM_FLAGS += "+firmware=custom/xnor_net.hex"
custom-vsim-run-xnor_net: vsim-run-gui

.PHONY: custom-vsim-run-xnor_net_lim
custom-vsim-run-xnor_net_lim: vsim-all custom/xnor_net_lim.hex
custom-vsim-run-xnor_net_lim: ALL_VSIM_FLAGS += "+firmware=custom/xnor_net_lim.hex"
custom-vsim-run-xnor_net_lim: vsim-run-gui

.PHONY: custom-vsim-run-gui-bitmap
custom-vsim-run-gui-bitmap: vsim-all custom/bitmap_search_lim.hex
custom-vsim-run-gui-bitmap: ALL_VSIM_FLAGS += "+firmware=custom/bitmap_search_lim.hex"
custom-vsim-run-gui-bitmap: vsim-run-gui

.PHONY: custom-vsim-run-gui-aes
custom-vsim-run-gui-aes: vsim-all custom/aes128_addroundkey_lim.hex
custom-vsim-run-gui-aes: ALL_VSIM_FLAGS += "+firmware=custom/aes128_addroundkey_lim.hex"
custom-vsim-run-gui-aes: vsim-run-gui

.PHONY: custom-vsim-run-gui-bitwise
custom-vsim-run-gui-bitwise: vsim-all custom/bitwise_lim.hex
custom-vsim-run-gui-bitwise: ALL_VSIM_FLAGS += "+firmware=custom/bitwise_lim.hex"
custom-vsim-run-gui-bitwise: vsim-run-gui

#LiM programs with new extended compiler

.PHONY: custom-vsim-run-gui-bitwise-ext-asm
custom-vsim-run-gui-bitwise-ext-asm: vsim-all custom/bitwise_lim_ext_asm.hex
custom-vsim-run-gui-bitwise-ext-asm: ALL_VSIM_FLAGS += "+firmware=custom/bitwise_lim_ext_asm.hex" +verbose
custom-vsim-run-gui-bitwise-ext-asm: vsim-run-gui

#test new inverting functionalities
.PHONY: custom-vsim-run-gui-bitwise-ext-inv-asm
custom-vsim-run-gui-bitwise-ext-inv-asm: vsim-all custom/bitwise_lim_ext_inv_asm.hex
custom-vsim-run-gui-bitwise-ext-inv-asm: ALL_VSIM_FLAGS += "+firmware=custom/bitwise_lim_ext_inv_asm.hex" +verbose 
custom-vsim-run-gui-bitwise-ext-inv-asm: vsim-run-gui



.PHONY: custom-veri-run
custom-veri-run: verilate custom/hello_world.hex
	./testbench_verilator $(VERI_FLAGS) \
		"+firmware=custom/hello_world.hex"

# Running custom fp programs:
# This is an example for running a floating-point matrix multiplication in the testbench
# We link with our custom crt0.s and syscalls.c against newlib so that we can
# use the c standard library
custom_fp/main.elf: custom_fp/matmulNxN.c custom_fp/main.c
	$(RISCV_EXE_PREFIX)gcc -march=rv32imfc -mabi=ilp32f -o $@ -w -g -nostdlib \
		$(CUSTOM_GCC_FLAGS) \
		-T custom/link.ld  \
		-static \
		custom/crt0.S \
		$^ custom/syscalls.c custom/vectors.S \
		-I $(RISCV_LIB)/riscv32-unknown-elf/include \
		-L $(RISCV_LIB)/riscv32-unknown-elf/lib \
		-lc -lm -lgcc
custom-fp-clean:
	rm -rf custom_fp/main.elf custom_fp/main.hex

.PHONY: custom-fp-vsim-run
custom-fp-vsim-run: vsim-all-fp custom_fp/main.hex
custom-fp-vsim-run: ALL_VSIM_FLAGS += "+firmware=custom_fp/main.hex"
custom-fp-vsim-run: vsim-run-fp


.PHONY: custom-fp-vsim-run-gui
custom-fp-vsim-run-gui: vsim-all-fp custom_fp/main.hex
custom-fp-vsim-run-gui: ALL_VSIM_FLAGS += "+firmware=custom_fp/main.hex"
custom-fp-vsim-run-gui: vsim-run-gui-fp

# compile and run interrupt_test
interrupt_test/interrupt_test.elf: interrupt_test/interrupt_test.c
	$(RISCV_EXE_PREFIX)gcc -march=rv32imc -o $@ -w -Os -g -nostdlib \
		-T custom/link.ld  \
		-static \
		custom/crt0.S \
		$^ custom/syscalls.c interrupt_test/vectors.S \
		-I $(RISCV_LIB)/riscv32-unknown-elf/include \
		-L $(RISCV_LIB)/riscv32-unknown-elf/lib \
		-lc -lm -lgcc
interrupt-clean:
	rm -rf interrupt_test/interrupt_test.elf interrupt_test/interrupt_test.hex

.PHONY: interrupt-vsim-run
interrupt-vsim-run: vsim-all interrupt_test/interrupt_test.hex
interrupt-vsim-run: ALL_VSIM_FLAGS += "+firmware=interrupt_test/interrupt_test.hex"
interrupt-vsim-run: vsim-run

.PHONY: interrupt-vsim-run-gui

interrupt-vsim-run-gui: vsim-all interrupt_test/interrupt_test.hex
interrupt-vsim-run-gui: ALL_VSIM_FLAGS += "+firmware=interrupt_test/interrupt_test.hex"
interrupt-vsim-run-gui: vsim-run-gui


# compile and dump picorv firmware
firmware/firmware.elf: $(FIRMWARE_OBJS) $(FIRMWARE_TEST_OBJS) $(COMPLIANCE_TEST_OBJS) \
				firmware/link.ld
	$(RISCV_EXE_PREFIX)gcc -g -Os -march=rv32imc -ffreestanding -nostdlib -o $@ \
		$(RISCV_TEST_INCLUDES) \
		-Wl,-Bstatic,-T,firmware/link.ld,-Map,firmware/firmware.map,--strip-debug \
		$(FIRMWARE_OBJS) $(FIRMWARE_TEST_OBJS) $(COMPLIANCE_TEST_OBJS) -lgcc

firmware/start.o: firmware/start.S
	$(RISCV_EXE_PREFIX)gcc -c -march=rv32imc -g -o $@ $<

firmware/%.o: firmware/%.c
	$(RISCV_EXE_PREFIX)gcc -c -march=rv32ic -g -Os --std=c99 -Wall \
		$(RISCV_TEST_INCLUDES) \
		-ffreestanding -nostdlib -o $@ $<

riscv_tests/rv32ui/%.o: riscv_tests/rv32ui/%.S riscv_tests/riscv_test.h \
			riscv_tests/macros/scalar/test_macros.h
	$(RISCV_EXE_PREFIX)gcc -c -march=rv32im -g -o $@ \
		$(RISCV_TEST_INCLUDES) \
		-DTEST_FUNC_NAME=$(notdir $(basename $<)) \
		-DTEST_FUNC_TXT='"$(notdir $(basename $<))"' \
		-DTEST_FUNC_RET=$(notdir $(basename $<))_ret $<

riscv_tests/rv32um/%.o: riscv_tests/rv32um/%.S riscv_tests/riscv_test.h \
			riscv_tests/macros/scalar/test_macros.h
	$(RISCV_EXE_PREFIX)gcc -c -march=rv32im -g -o $@ \
		$(RISCV_TEST_INCLUDES) \
		-DTEST_FUNC_NAME=$(notdir $(basename $<)) \
		-DTEST_FUNC_TXT='"$(notdir $(basename $<))"' \
		-DTEST_FUNC_RET=$(notdir $(basename $<))_ret $<

riscv_tests/rv32uc/%.o: riscv_tests/rv32uc/%.S riscv_tests/riscv_test.h \
			riscv_tests/macros/scalar/test_macros.h
	$(RISCV_EXE_PREFIX)gcc -c -march=rv32imc -g -o $@ \
		$(RISCV_TEST_INCLUDES) \
		-DTEST_FUNC_NAME=$(notdir $(basename $<)) \
		-DTEST_FUNC_TXT='"$(notdir $(basename $<))"' \
		-DTEST_FUNC_RET=$(notdir $(basename $<))_ret $<

riscv_tests/rv32ua/%.o: riscv_tests/rv32ua/%.S riscv_tests/riscv_test.h \
			riscv_tests/macros/scalar/test_macros.h
	$(RISCV_EXE_PREFIX)gcc -c -march=rv32ima -g -o $@ \
		$(RISCV_TEST_INCLUDES) \
		-DTEST_FUNC_NAME=$(notdir $(basename $<)) \
		-DTEST_FUNC_TXT='"$(notdir $(basename $<))"' \
		-DTEST_FUNC_RET=$(notdir $(basename $<))_ret $<

# Build riscv_compliance_test. Make sure to escape dashes to underscores
riscv_compliance_tests/%.o: riscv_compliance_tests/%.S riscv_compliance_tests/riscv_test.h \
			riscv_compliance_tests/test_macros.h riscv_compliance_tests/compliance_io.h \
			riscv_compliance_tests/compliance_test.h
	$(RISCV_EXE_PREFIX)gcc -c -march=rv32im -g -o $@ \
		-DTEST_FUNC_NAME=$(notdir $(subst -,_,$(basename $<))) \
		-DTEST_FUNC_TXT='"$(notdir $(subst -,_,$(basename $<)))"' \
		-DTEST_FUNC_RET=$(notdir $(subst -,_,$(basename $<)))_ret $<

# run picorv firmware
# in verilator
.PHONY: firmware-veri-run
firmware-veri-run: verilate firmware/firmware.hex
	./testbench_verilator $(VERI_FLAGS) \
		"+firmware=firmware/firmware.hex"

# in vsim
.PHONY: firmware-vsim-run
firmware-vsim-run: vsim-all firmware/firmware.hex
firmware-vsim-run: ALL_VSIM_FLAGS += "+firmware=firmware/firmware.hex"
firmware-vsim-run: vsim-run

.PHONY: firmware-vsim-run-gui
firmware-vsim-run-gui: vsim-all firmware/firmware.hex
firmware-vsim-run-gui: ALL_VSIM_FLAGS += "+firmware=firmware/firmware.hex"
firmware-vsim-run-gui: vsim-run-gui

# in vcs
.PHONY: firmware-vcs-run
firmware-vcs-run: vcsify firmware/firmware.hex
	./simv $(SIMV_FLAGS) "+firmware=firmware/firmware.hex"

.PHONY: firmware-vcs-run-gui
firmware-vcs-run-gui: VCS_FLAGS+=-debug_all
firmware-vcs-run-gui: vcsify firmware/firmware.hex
	./simv $(SIMV_FLAGS) -gui "+firmware=firmware/firmware.hex"

.PHONY: firmware-clean
firmware-clean:
	rm -vrf $(addprefix firmware/firmware., elf bin hex map) \
		$(FIRMWARE_OBJS) $(FIRMWARE_TEST_OBJS) $(COMPLIANCE_TEST_OBJS)

# csmith targets
csmith/test.c:
	echo "integer size = 4" > csmith/platform.info
	echo "pointer size = 4" >> csmith/platform.info
	$(CSMITH) --no-packed-struct -o csmith/test.c
	gawk '/Seed:/ {print$$2,$$3;}' csmith/test.c

csmith/test_ref: csmith/test.c
	gcc -m32 -o csmith/test_ref -w -Os -I $(CSMITH_INCLUDE) csmith/test.c

csmith/test.elf: csmith/test.c csmith/syscalls.c csmith/start.S
	$(RISCV_EXE_PREFIX)gcc -march=rv32imc -o csmith/test.elf -w -Os \
		-I $(CSMITH_INCLUDE) \
		-T csmith/link.ld  \
		csmith/test.c csmith/syscalls.c csmith/start.S -Wl,--verbose
	chmod u+x csmith/test.elf

csmith-clean:
	rm -rf $(addprefix csmith/, test.c test.elf test.hex test_ref)

# simulators and fesvr for csmith
riscv-fesvr/build.ok:
	rm -rf riscv-fesvr
	git clone https://github.com/riscv/riscv-fesvr.git riscv-fesvr
	+cd riscv-fesvr && git checkout 1c02bd6 && \
		./configure && make && touch build.ok

riscv-isa-sim/build.ok: riscv-fesvr/build.ok
	rm -rf riscv-isa-sim
	git clone https://github.com/riscv/riscv-isa-sim.git riscv-isa-sim
	cd riscv-isa-sim && git checkout 10ae74e
	cd riscv-isa-sim && patch -p1 < ../csmith/riscv-isa-sim.diff
	cd riscv-isa-sim && \
		LDFLAGS="-L../riscv-fesvr" ./configure --with-isa=RV32IMC
	+cd riscv-isa-sim \
		&& ln -s ../riscv-fesvr/fesvr . && make && touch build.ok

.PHONY: csmith-spike
csmith-spike: riscv-fesvr/build.ok riscv-isa-sim/build.ok csmith/test_ref \
		 csmith/test.elf
	timeout $(CSMITH_TIMEOUT_REF) ./csmith/test_ref > csmith/output_ref.txt \
		&& cat csmith/output_ref.txt
	LD_LIBRARY_PATH="./riscv-isa-sim:./riscv-fesvr" \
		./riscv-isa-sim/spike csmith/test.elf > csmith/output_sim.txt
	diff -u csmith/output_ref.txt csmith/output_sim.txt

# run verilator on csmith/test.hex and only return the checksum, if any. We also have
# a timeout mechanism in place to prevent infinite loops
.PHONY: csmith-veri-rtl
csmith-veri-rtl: verilate csmith/test.hex
csmith-veri-rtl: VERI_FLAGS += "+firmware=csmith/test.hex"
csmith-veri-rtl:
	timeout $(CSMITH_TIMEOUT_VERI) ./testbench_verilator $(VERI_FLAGS) \
	| grep 'checksum' > csmith/output_sim.txt

# run vsim on csmith/test.hex and only return the checksum, if any. We also have
# a timeout mechanism in place to prevent infinite loops
.PHONY: csmith-vsim-rtl
csmith-vsim-rtl: vsim-all csmith/test.hex
csmith-vsim-rtl: ALL_VSIM_FLAGS += "-GBOOT_ADDR=128"
csmith-vsim-rtl: ALL_VSIM_FLAGS += "+firmware=csmith/test.hex"
csmith-vsim-rtl:
	timeout $(CSMITH_TIMEOUT_VSIM) $(VSIM) -work $(VWORK) \
	$(ALL_VSIM_FLAGS) \
	$(RTLSRC_VOPT_TB_TOP) -do 'source $(VSIM_SCRIPT); exit -f' \
	| grep 'checksum' | cut -c 3- > csmith/output_sim.txt

.PHONY: csmith-loop
csmith-loop: riscv-fesvr/build.ok riscv-isa-sim/build.ok
# Check if the reference program terminates and if spike produces the same
# result. Otherwise we just skip the test. Then we check if we produce the same
# output with the rtl model (ri5cy). Stop on first failed test
	+set -e; \
	x() { echo "$$*" >&2; "$$@"; }; \
	i=1; j=0; k=0;\
	while true; do \
		echo; echo; \
		echo "--- test#$$((i++)) passed:$${j} skipped:$${k} ---"; \
		x rm -f $(addprefix csmith/, test.hex test.elf \
			test.c test_ref output_ref.txt output_sim.txt); \
		x make csmith-spike csmith/test.hex || \
			{ \
				echo SKIP; \
				! ((k++)); \
				continue; \
			}; \
		x rm -f csmith/output_sim.txt; \
		x make csmith-veri-rtl; \
		x diff -u csmith/output_ref.txt csmith/output_sim.txt; \
			echo OK; ! ((j++)); \
	done


# general targets
.PHONY: clean
clean: tb-clean tb-clean-fp verilate-clean vcs-clean firmware-clean csmith-clean custom-clean custom-fp-clean interrupt-clean

.PHONY: distclean
distclean: clean
	rm -rf riscv-fesvr riscv-isa-sim work
