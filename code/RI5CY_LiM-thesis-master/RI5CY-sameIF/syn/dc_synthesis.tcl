#=================================
# Design Compiler script
#=================================

set DESIGN_RTL_DIR   ../rtl
set DESIGN_MEM_DIR   ../tb/core

if {[file exists .riscv]} {

  # Variables
  set top              riscv_core

  # Analyze
  analyze -library work -format sverilog $DESIGN_RTL_DIR/include/apu_core_package.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/include/apu_macros.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/fpnew/src/fpnew_pkg.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/include/riscv_defines.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/include/riscv_tracer_defines.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/include/riscv_config.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_if_stage.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/cluster_clock_gating.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/cv32e40p_sim_clock_gate.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_alu_basic.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_cs_registers.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_register_file.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_load_store_unit.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_id_stage.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_decoder.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_compressed_decoder.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_fetch_fifo.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_prefetch_buffer.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_prefetch_L0_buffer.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_L0_buffer.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_hwloop_regs.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_hwloop_controller.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_mult.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_register_file_latch.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/register_file_test_wrap.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_int_controller.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_ex_stage.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_alu_div.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_alu.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_pmp.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_apu_disp.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_controller.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/riscv_core.sv

  # Elaborate
  elaborate $top

  # Synthesis constraints
  source dc_synthesis_constraints.tcl

  # Compile
  compile -map_effort high
  write -hierarchy -format verilog -hier -output netlist/riscv_core_synthesized.v

  # Reports
  write_sdc reports/riscv_core_synthesized.sdc
  report_timing -max_paths 2 > reports/riscv_core_synthesized_timing_report.rpt
  report_area > reports/riscv_core_synthesized_area_report.rpt
  report_power > reports/riscv_core_synthesized_power_report.rpt

} elseif {[file exists .mem]} {

  # Variables
  set top             dp_ram_logic

  # Analyze
  analyze -library work -format sverilog $DESIGN_RTL_DIR/fpnew/src/fpnew_pkg.sv
  analyze -library work -format sverilog $DESIGN_RTL_DIR/include/riscv_defines.sv
  analyze -library work -format sverilog $DESIGN_MEM_DIR/dp_ram_logic.sv

  # Elaborate
  elaborate $top

  # Synthesis constraints
  source dc_synthesis_constraints.tcl

  # Compile
  compile -map_effort high
  write -hierarchy -format verilog -hier -output netlist/riscv_mem_synthesized.v

  # Reports
  write_sdc reports/riscv_core_synthesized.sdc
  report_timing -max_paths 2 > reports/riscv_mem_synthesized_timing_report.rpt
  report_area > reports/riscv_mem_synthesized_area_report.rpt
  report_power > reports/riscv_mem_synthesized_power_report.rpt
}

exit
