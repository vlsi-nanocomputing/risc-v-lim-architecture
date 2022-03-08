// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vtop::traceInit, &Vtop::traceFull, &Vtop::traceChg, this);
}
void Vtop::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vtop* t = (Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vtop::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t = (Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vtop::traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vtop::traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+5913,"clk_i", false,-1);
        vcdp->declBit(c+5921,"rstn_i", false,-1);
        vcdp->declBit(c+5929,"irq_i", false,-1);
        vcdp->declBus(c+5937,"irq_id_i", false,-1, 4,0);
        vcdp->declBit(c+5945,"irq_ack_o", false,-1);
        vcdp->declBus(c+5953,"irq_id_o", false,-1, 4,0);
        vcdp->declBit(c+5961,"debug_req_i", false,-1);
        vcdp->declBit(c+5969,"fetch_enable_i", false,-1);
        vcdp->declBit(c+5977,"core_busy_o", false,-1);
        vcdp->declBus(c+5993,"top ADDR_WIDTH", false,-1, 31,0);
        vcdp->declBus(c+6001,"top BOOT_ADDR", false,-1, 31,0);
        vcdp->declBus(c+6009,"top PULP_CLUSTER", false,-1, 31,0);
        vcdp->declBus(c+6009,"top FPU", false,-1, 31,0);
        vcdp->declBus(c+6009,"top PULP_ZFINX", false,-1, 31,0);
        vcdp->declBus(c+6017,"top DM_HALTADDRESS", false,-1, 31,0);
        vcdp->declBit(c+5913,"top clk_i", false,-1);
        vcdp->declBit(c+5921,"top rstn_i", false,-1);
        vcdp->declBit(c+5929,"top irq_i", false,-1);
        vcdp->declBus(c+5937,"top irq_id_i", false,-1, 4,0);
        vcdp->declBit(c+1825,"top irq_ack_o", false,-1);
        vcdp->declBus(c+4057,"top irq_id_o", false,-1, 4,0);
        vcdp->declBit(c+5961,"top debug_req_i", false,-1);
        vcdp->declBit(c+5969,"top fetch_enable_i", false,-1);
        vcdp->declBit(c+1833,"top core_busy_o", false,-1);
        vcdp->declBit(c+297,"top instr_req", false,-1);
        vcdp->declBit(c+297,"top instr_gnt", false,-1);
        vcdp->declBit(c+5809,"top instr_rvalid", false,-1);
        vcdp->declBus(c+305,"top instr_addr", false,-1, 21,0);
        vcdp->declArray(c+5817,"top instr_rdata", false,-1, 127,0);
        vcdp->declBit(c+313,"top data_req", false,-1);
        vcdp->declBit(c+313,"top data_gnt", false,-1);
        vcdp->declBit(c+5849,"top data_rvalid", false,-1);
        vcdp->declBus(c+3593,"top data_addr", false,-1, 21,0);
        vcdp->declBit(c+5873,"top data_we", false,-1);
        vcdp->declBus(c+3601,"top data_be", false,-1, 3,0);
        vcdp->declBus(c+5857,"top data_rdata", false,-1, 31,0);
        vcdp->declBus(c+3609,"top data_wdata", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i PULP_CLUSTER", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i FPU", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i PULP_ZFINX", false,-1, 31,0);
        vcdp->declBus(c+6017,"top riscv_core_i DM_HALTADDRESS", false,-1, 31,0);
        vcdp->declBit(c+5913,"top riscv_core_i clk_i", false,-1);
        vcdp->declBit(c+5921,"top riscv_core_i rst_ni", false,-1);
        vcdp->declBit(c+6025,"top riscv_core_i clock_en_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i test_en_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i fregfile_disable_i", false,-1);
        vcdp->declBus(c+6001,"top riscv_core_i boot_addr_i", false,-1, 31,0);
        vcdp->declBus(c+6041,"top riscv_core_i core_id_i", false,-1, 3,0);
        vcdp->declBus(c+6049,"top riscv_core_i cluster_id_i", false,-1, 5,0);
        vcdp->declBit(c+297,"top riscv_core_i instr_req_o", false,-1);
        vcdp->declBit(c+297,"top riscv_core_i instr_gnt_i", false,-1);
        vcdp->declBit(c+5809,"top riscv_core_i instr_rvalid_i", false,-1);
        vcdp->declBus(c+321,"top riscv_core_i instr_addr_o", false,-1, 31,0);
        vcdp->declBus(c+5865,"top riscv_core_i instr_rdata_i", false,-1, 31,0);
        vcdp->declBit(c+313,"top riscv_core_i data_req_o", false,-1);
        vcdp->declBit(c+313,"top riscv_core_i data_gnt_i", false,-1);
        vcdp->declBit(c+5849,"top riscv_core_i data_rvalid_i", false,-1);
        vcdp->declBit(c+5873,"top riscv_core_i data_we_o", false,-1);
        vcdp->declBus(c+3601,"top riscv_core_i data_be_o", false,-1, 3,0);
        vcdp->declBus(c+3617,"top riscv_core_i data_addr_o", false,-1, 31,0);
        vcdp->declBus(c+3609,"top riscv_core_i data_wdata_o", false,-1, 31,0);
        vcdp->declBus(c+5857,"top riscv_core_i data_rdata_i", false,-1, 31,0);
        vcdp->declBit(c+6033,"top riscv_core_i apu_master_req_o", false,-1);
        vcdp->declBit(c+6025,"top riscv_core_i apu_master_ready_o", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i apu_master_gnt_i", false,-1);
        vcdp->declArray(c+1,"top riscv_core_i apu_master_operands_o", false,-1, 95,0);
        vcdp->declBus(c+6049,"top riscv_core_i apu_master_op_o", false,-1, 5,0);
        vcdp->declBus(c+6057,"top riscv_core_i apu_master_type_o", false,-1, -1,0);
        vcdp->declBus(c+6065,"top riscv_core_i apu_master_flags_o", false,-1, 14,0);
        vcdp->declBit(c+6033,"top riscv_core_i apu_master_valid_i", false,-1);
        vcdp->declBus(c+6073,"top riscv_core_i apu_master_result_i", false,-1, 31,0);
        vcdp->declBus(c+6081,"top riscv_core_i apu_master_flags_i", false,-1, 4,0);
        vcdp->declBit(c+1825,"top riscv_core_i irq_ack_o", false,-1);
        vcdp->declBus(c+4057,"top riscv_core_i irq_id_o", false,-1, 4,0);
        vcdp->declBit(c+6033,"top riscv_core_i irq_software_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i irq_timer_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i irq_external_i", false,-1);
        vcdp->declBus(c+6065,"top riscv_core_i irq_fast_i", false,-1, 14,0);
        vcdp->declBit(c+6033,"top riscv_core_i irq_nmi_i", false,-1);
        vcdp->declBus(c+6073,"top riscv_core_i irq_fastx_i", false,-1, 31,0);
        vcdp->declBit(c+5961,"top riscv_core_i debug_req_i", false,-1);
        vcdp->declBit(c+5969,"top riscv_core_i fetch_enable_i", false,-1);
        vcdp->declBit(c+1833,"top riscv_core_i core_busy_o", false,-1);
        vcdp->declBus(c+6009,"top riscv_core_i N_EXT_PERF_COUNTERS", false,-1, 31,0);
        vcdp->declBus(c+6089,"top riscv_core_i INSTR_RDATA_WIDTH", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i PULP_SECURE", false,-1, 31,0);
        vcdp->declBus(c+6097,"top riscv_core_i N_PMP_ENTRIES", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i USE_PMP", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i A_EXTENSION", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i FP_DIVSQRT", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i SHARED_FP", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i SHARED_DSP_MULT", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i SHARED_INT_MULT", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i SHARED_INT_DIV", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i SHARED_FP_DIVSQRT", false,-1, 31,0);
        vcdp->declBus(c+4065,"top riscv_core_i data_atop_o", false,-1, 5,0);
        vcdp->declBus(c+6105,"top riscv_core_i ext_perf_counters_i", false,-1, -1,0);
        vcdp->declBit(c+6033,"top riscv_core_i irq_sec_i", false,-1);
        vcdp->declBit(c+6025,"top riscv_core_i sec_lvl_o", false,-1);
        vcdp->declBus(c+6113,"top riscv_core_i N_HWLP", false,-1, 31,0);
        vcdp->declBus(c+6121,"top riscv_core_i N_HWLP_BITS", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i APU", false,-1, 31,0);
        vcdp->declBit(c+1841,"top riscv_core_i is_hwlp_id", false,-1);
        vcdp->declBus(c+4073,"top riscv_core_i hwlp_dec_cnt_id", false,-1, 1,0);
        vcdp->declBit(c+4081,"top riscv_core_i instr_valid_id", false,-1);
        vcdp->declBus(c+4089,"top riscv_core_i instr_rdata_id", false,-1, 31,0);
        vcdp->declBit(c+4097,"top riscv_core_i is_compressed_id", false,-1);
        vcdp->declBit(c+4105,"top riscv_core_i is_fetch_failed_id", false,-1);
        vcdp->declBit(c+4113,"top riscv_core_i illegal_c_insn_id", false,-1);
        vcdp->declBus(c+3625,"top riscv_core_i pc_if", false,-1, 31,0);
        vcdp->declBus(c+5881,"top riscv_core_i pc_id", false,-1, 31,0);
        vcdp->declBit(c+329,"top riscv_core_i clear_instr_valid", false,-1);
        vcdp->declBit(c+337,"top riscv_core_i pc_set", false,-1);
        vcdp->declBus(c+345,"top riscv_core_i pc_mux_id", false,-1, 2,0);
        vcdp->declBus(c+3633,"top riscv_core_i exc_pc_mux_id", false,-1, 2,0);
        vcdp->declBus(c+3641,"top riscv_core_i exc_cause", false,-1, 5,0);
        vcdp->declBus(c+3649,"top riscv_core_i trap_addr_mux", false,-1, 1,0);
        vcdp->declBit(c+6129,"top riscv_core_i lsu_load_err", false,-1);
        vcdp->declBit(c+6137,"top riscv_core_i lsu_store_err", false,-1);
        vcdp->declBit(c+3657,"top riscv_core_i is_decoding", false,-1);
        vcdp->declBit(c+4121,"top riscv_core_i useincr_addr_ex", false,-1);
        vcdp->declBit(c+3665,"top riscv_core_i data_misaligned", false,-1);
        vcdp->declBit(c+3673,"top riscv_core_i mult_multicycle", false,-1);
        vcdp->declBus(c+3681,"top riscv_core_i jump_target_id", false,-1, 31,0);
        vcdp->declBus(c+5889,"top riscv_core_i jump_target_ex", false,-1, 31,0);
        vcdp->declBit(c+4129,"top riscv_core_i branch_in_ex", false,-1);
        vcdp->declBit(c+1849,"top riscv_core_i branch_decision", false,-1);
        vcdp->declBit(c+1857,"top riscv_core_i ctrl_busy", false,-1);
        vcdp->declBit(c+1433,"top riscv_core_i if_busy", false,-1);
        vcdp->declBit(c+1441,"top riscv_core_i lsu_busy", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i apu_busy", false,-1);
        vcdp->declBus(c+4137,"top riscv_core_i pc_ex", false,-1, 31,0);
        vcdp->declBit(c+4145,"top riscv_core_i alu_en_ex", false,-1);
        vcdp->declBus(c+4153,"top riscv_core_i alu_operator_ex", false,-1, 6,0);
        vcdp->declBus(c+4161,"top riscv_core_i alu_operand_a_ex", false,-1, 31,0);
        vcdp->declBus(c+4169,"top riscv_core_i alu_operand_b_ex", false,-1, 31,0);
        vcdp->declBus(c+5889,"top riscv_core_i alu_operand_c_ex", false,-1, 31,0);
        vcdp->declBus(c+4177,"top riscv_core_i bmask_a_ex", false,-1, 4,0);
        vcdp->declBus(c+4185,"top riscv_core_i bmask_b_ex", false,-1, 4,0);
        vcdp->declBus(c+4193,"top riscv_core_i imm_vec_ext_ex", false,-1, 1,0);
        vcdp->declBus(c+4201,"top riscv_core_i alu_vec_mode_ex", false,-1, 1,0);
        vcdp->declBit(c+4209,"top riscv_core_i alu_is_clpx_ex", false,-1);
        vcdp->declBit(c+4217,"top riscv_core_i alu_is_subrot_ex", false,-1);
        vcdp->declBus(c+4225,"top riscv_core_i alu_clpx_shift_ex", false,-1, 1,0);
        vcdp->declBus(c+4233,"top riscv_core_i mult_operator_ex", false,-1, 2,0);
        vcdp->declBus(c+4241,"top riscv_core_i mult_operand_a_ex", false,-1, 31,0);
        vcdp->declBus(c+4249,"top riscv_core_i mult_operand_b_ex", false,-1, 31,0);
        vcdp->declBus(c+4257,"top riscv_core_i mult_operand_c_ex", false,-1, 31,0);
        vcdp->declBit(c+4265,"top riscv_core_i mult_en_ex", false,-1);
        vcdp->declBit(c+4273,"top riscv_core_i mult_sel_subword_ex", false,-1);
        vcdp->declBus(c+4281,"top riscv_core_i mult_signed_mode_ex", false,-1, 1,0);
        vcdp->declBus(c+4289,"top riscv_core_i mult_imm_ex", false,-1, 4,0);
        vcdp->declBus(c+4297,"top riscv_core_i mult_dot_op_a_ex", false,-1, 31,0);
        vcdp->declBus(c+4305,"top riscv_core_i mult_dot_op_b_ex", false,-1, 31,0);
        vcdp->declBus(c+4313,"top riscv_core_i mult_dot_op_c_ex", false,-1, 31,0);
        vcdp->declBus(c+4321,"top riscv_core_i mult_dot_signed_ex", false,-1, 1,0);
        vcdp->declBit(c+6145,"top riscv_core_i mult_is_clpx_ex_o", false,-1);
        vcdp->declBus(c+4329,"top riscv_core_i mult_clpx_shift_ex", false,-1, 1,0);
        vcdp->declBit(c+4337,"top riscv_core_i mult_clpx_img_ex", false,-1);
        vcdp->declBus(c+6081,"top riscv_core_i fprec_csr", false,-1, 4,0);
        vcdp->declBus(c+6153,"top riscv_core_i frm_csr", false,-1, 2,0);
        vcdp->declBus(c+6081,"top riscv_core_i fflags", false,-1, 4,0);
        vcdp->declBus(c+6081,"top riscv_core_i fflags_csr", false,-1, 4,0);
        vcdp->declBit(c+6033,"top riscv_core_i fflags_we", false,-1);
        vcdp->declBit(c+4345,"top riscv_core_i apu_en_ex", false,-1);
        vcdp->declBus(c+4353,"top riscv_core_i apu_type_ex", false,-1, -1,0);
        vcdp->declBus(c+4361,"top riscv_core_i apu_flags_ex", false,-1, 14,0);
        vcdp->declBus(c+4369,"top riscv_core_i apu_op_ex", false,-1, 5,0);
        vcdp->declBus(c+4377,"top riscv_core_i apu_lat_ex", false,-1, 1,0);
        vcdp->declArray(c+4385,"top riscv_core_i apu_operands_ex", false,-1, 95,0);
        vcdp->declBus(c+4409,"top riscv_core_i apu_waddr_ex", false,-1, 5,0);
        vcdp->declBus(c+6161,"top riscv_core_i apu_read_regs", false,-1, 17,0);
        vcdp->declBus(c+6153,"top riscv_core_i apu_read_regs_valid", false,-1, 2,0);
        vcdp->declBit(c+6033,"top riscv_core_i apu_read_dep", false,-1);
        vcdp->declBus(c+6169,"top riscv_core_i apu_write_regs", false,-1, 11,0);
        vcdp->declBus(c+6057,"top riscv_core_i apu_write_regs_valid", false,-1, 1,0);
        vcdp->declBit(c+6033,"top riscv_core_i apu_write_dep", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i perf_apu_type", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i perf_apu_cont", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i perf_apu_dep", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i perf_apu_wb", false,-1);
        vcdp->declBus(c+4417,"top riscv_core_i regfile_waddr_ex", false,-1, 5,0);
        vcdp->declBit(c+4425,"top riscv_core_i regfile_we_ex", false,-1);
        vcdp->declBus(c+4433,"top riscv_core_i regfile_waddr_fw_wb_o", false,-1, 5,0);
        vcdp->declBit(c+1865,"top riscv_core_i regfile_we_wb", false,-1);
        vcdp->declBus(c+3689,"top riscv_core_i regfile_wdata", false,-1, 31,0);
        vcdp->declBus(c+4441,"top riscv_core_i regfile_alu_waddr_ex", false,-1, 5,0);
        vcdp->declBit(c+4449,"top riscv_core_i regfile_alu_we_ex", false,-1);
        vcdp->declBus(c+4441,"top riscv_core_i regfile_alu_waddr_fw", false,-1, 5,0);
        vcdp->declBit(c+1873,"top riscv_core_i regfile_alu_we_fw", false,-1);
        vcdp->declBus(c+353,"top riscv_core_i regfile_alu_wdata_fw", false,-1, 31,0);
        vcdp->declBit(c+4457,"top riscv_core_i csr_access_ex", false,-1);
        vcdp->declBus(c+4465,"top riscv_core_i csr_op_ex", false,-1, 1,0);
        vcdp->declBus(c+4473,"top riscv_core_i mtvec", false,-1, 23,0);
        vcdp->declBus(c+4481,"top riscv_core_i mtvecx", false,-1, 23,0);
        vcdp->declBus(c+6177,"top riscv_core_i utvec", false,-1, 23,0);
        vcdp->declBit(c+4457,"top riscv_core_i csr_access", false,-1);
        vcdp->declBus(c+4465,"top riscv_core_i csr_op", false,-1, 1,0);
        vcdp->declBus(c+1881,"top riscv_core_i csr_addr", false,-1, 11,0);
        vcdp->declBus(c+1881,"top riscv_core_i csr_addr_int", false,-1, 11,0);
        vcdp->declBus(c+1889,"top riscv_core_i csr_rdata", false,-1, 31,0);
        vcdp->declBus(c+4161,"top riscv_core_i csr_wdata", false,-1, 31,0);
        vcdp->declBus(c+6185,"top riscv_core_i current_priv_lvl", false,-1, 1,0);
        vcdp->declBit(c+5873,"top riscv_core_i data_we_ex", false,-1);
        vcdp->declBus(c+4065,"top riscv_core_i data_atop_ex", false,-1, 5,0);
        vcdp->declBus(c+5897,"top riscv_core_i data_type_ex", false,-1, 1,0);
        vcdp->declBus(c+4489,"top riscv_core_i data_sign_ext_ex", false,-1, 1,0);
        vcdp->declBus(c+4497,"top riscv_core_i data_reg_offset_ex", false,-1, 1,0);
        vcdp->declBit(c+4505,"top riscv_core_i data_req_ex", false,-1);
        vcdp->declBit(c+4513,"top riscv_core_i data_load_event_ex", false,-1);
        vcdp->declBit(c+5905,"top riscv_core_i data_misaligned_ex", false,-1);
        vcdp->declBus(c+3689,"top riscv_core_i lsu_rdata", false,-1, 31,0);
        vcdp->declBit(c+361,"top riscv_core_i halt_if", false,-1);
        vcdp->declBit(c+369,"top riscv_core_i id_ready", false,-1);
        vcdp->declBit(c+377,"top riscv_core_i ex_ready", false,-1);
        vcdp->declBit(c+385,"top riscv_core_i id_valid", false,-1);
        vcdp->declBit(c+393,"top riscv_core_i ex_valid", false,-1);
        vcdp->declBit(c+401,"top riscv_core_i wb_valid", false,-1);
        vcdp->declBit(c+409,"top riscv_core_i lsu_ready_ex", false,-1);
        vcdp->declBit(c+401,"top riscv_core_i lsu_ready_wb", false,-1);
        vcdp->declBit(c+6025,"top riscv_core_i apu_ready_wb", false,-1);
        vcdp->declBit(c+1897,"top riscv_core_i instr_req_int", false,-1);
        vcdp->declBit(c+4521,"top riscv_core_i m_irq_enable", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i u_irq_enable", false,-1);
        vcdp->declBit(c+1905,"top riscv_core_i csr_irq_sec", false,-1);
        vcdp->declBus(c+4529,"top riscv_core_i mepc", false,-1, 31,0);
        vcdp->declBus(c+6073,"top riscv_core_i uepc", false,-1, 31,0);
        vcdp->declBus(c+4537,"top riscv_core_i depc", false,-1, 31,0);
        vcdp->declBit(c+6193,"top riscv_core_i irq_software", false,-1);
        vcdp->declBit(c+6201,"top riscv_core_i irq_timer", false,-1);
        vcdp->declBit(c+6209,"top riscv_core_i irq_external", false,-1);
        vcdp->declBus(c+6217,"top riscv_core_i irq_fast", false,-1, 14,0);
        vcdp->declBit(c+6225,"top riscv_core_i irq_nmi", false,-1);
        vcdp->declBit(c+417,"top riscv_core_i csr_save_cause", false,-1);
        vcdp->declBit(c+3697,"top riscv_core_i csr_save_if", false,-1);
        vcdp->declBit(c+425,"top riscv_core_i csr_save_id", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i csr_save_ex", false,-1);
        vcdp->declBus(c+433,"top riscv_core_i csr_cause", false,-1, 6,0);
        vcdp->declBit(c+3705,"top riscv_core_i csr_restore_mret_id", false,-1);
        vcdp->declBit(c+3713,"top riscv_core_i csr_restore_uret_id", false,-1);
        vcdp->declBit(c+3721,"top riscv_core_i csr_restore_dret_id", false,-1);
        vcdp->declBit(c+4545,"top riscv_core_i debug_mode", false,-1);
        vcdp->declBus(c+441,"top riscv_core_i debug_cause", false,-1, 2,0);
        vcdp->declBit(c+449,"top riscv_core_i debug_csr_save", false,-1);
        vcdp->declBit(c+4553,"top riscv_core_i debug_single_step", false,-1);
        vcdp->declBit(c+4561,"top riscv_core_i debug_ebreakm", false,-1);
        vcdp->declBit(c+4569,"top riscv_core_i debug_ebreaku", false,-1);
        vcdp->declQuad(c+4577,"top riscv_core_i hwlp_start", false,-1, 63,0);
        vcdp->declQuad(c+4593,"top riscv_core_i hwlp_end", false,-1, 63,0);
        vcdp->declQuad(c+4609,"top riscv_core_i hwlp_cnt", false,-1, 63,0);
        vcdp->declBus(c+1913,"top riscv_core_i csr_hwlp_regid", false,-1, 0,0);
        vcdp->declBus(c+1921,"top riscv_core_i csr_hwlp_we", false,-1, 2,0);
        vcdp->declBus(c+1929,"top riscv_core_i csr_hwlp_data", false,-1, 31,0);
        vcdp->declBit(c+457,"top riscv_core_i perf_imiss", false,-1);
        vcdp->declBit(c+465,"top riscv_core_i perf_jump", false,-1);
        vcdp->declBit(c+1937,"top riscv_core_i perf_jr_stall", false,-1);
        vcdp->declBit(c+473,"top riscv_core_i perf_ld_stall", false,-1);
        vcdp->declBit(c+3729,"top riscv_core_i perf_pipeline_stall", false,-1);
        vcdp->declBit(c+1945,"top riscv_core_i core_ctrl_firstfetch", false,-1);
        vcdp->declBit(c+1449,"top riscv_core_i core_busy_int", false,-1);
        vcdp->declBit(c+4625,"top riscv_core_i core_busy_q", false,-1);
        vcdp->declArray(c+6233,"top riscv_core_i pmp_addr", false,-1, 511,0);
        vcdp->declArray(c+6361,"top riscv_core_i pmp_cfg", false,-1, 127,0);
        vcdp->declBit(c+313,"top riscv_core_i data_req_pmp", false,-1);
        vcdp->declBus(c+3617,"top riscv_core_i data_addr_pmp", false,-1, 31,0);
        vcdp->declBit(c+6393,"top riscv_core_i data_we_pmp", false,-1);
        vcdp->declBit(c+313,"top riscv_core_i data_gnt_pmp", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i data_err_pmp", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i data_err_ack", false,-1);
        vcdp->declBit(c+297,"top riscv_core_i instr_req_pmp", false,-1);
        vcdp->declBit(c+297,"top riscv_core_i instr_gnt_pmp", false,-1);
        vcdp->declBus(c+321,"top riscv_core_i instr_addr_pmp", false,-1, 31,0);
        vcdp->declBit(c+6033,"top riscv_core_i instr_err_pmp", false,-1);
        vcdp->declBit(c+1953,"top riscv_core_i irq_pending", false,-1);
        vcdp->declBus(c+1961,"top riscv_core_i irq_id", false,-1, 5,0);
        vcdp->declBit(c+1801,"top riscv_core_i is_interrupt", false,-1);
        vcdp->declBit(c+5913,"top riscv_core_i clk", false,-1);
        vcdp->declBit(c+5985,"top riscv_core_i clock_en", false,-1);
        vcdp->declBit(c+1969,"top riscv_core_i sleeping", false,-1);
        vcdp->declBit(c+4633,"top riscv_core_i mult_is_clpx_ex", false,-1);
        vcdp->declBit(c+5913,"top riscv_core_i core_clock_gate_i clk_i", false,-1);
        vcdp->declBit(c+5985,"top riscv_core_i core_clock_gate_i en_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i core_clock_gate_i test_en_i", false,-1);
        vcdp->declBit(c+5913,"top riscv_core_i core_clock_gate_i clk_o", false,-1);
        vcdp->declBus(c+6113,"top riscv_core_i if_stage_i N_HWLP", false,-1, 31,0);
        vcdp->declBus(c+6089,"top riscv_core_i if_stage_i RDATA_WIDTH", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i if_stage_i FPU", false,-1, 31,0);
        vcdp->declBus(c+6017,"top riscv_core_i if_stage_i DM_HALTADDRESS", false,-1, 31,0);
        vcdp->declBit(c+5913,"top riscv_core_i if_stage_i clk", false,-1);
        vcdp->declBit(c+5921,"top riscv_core_i if_stage_i rst_n", false,-1);
        vcdp->declBus(c+4473,"top riscv_core_i if_stage_i m_trap_base_addr_i", false,-1, 23,0);
        vcdp->declBus(c+4481,"top riscv_core_i if_stage_i m_trap_base_addrx_i", false,-1, 23,0);
        vcdp->declBus(c+6177,"top riscv_core_i if_stage_i u_trap_base_addr_i", false,-1, 23,0);
        vcdp->declBus(c+3649,"top riscv_core_i if_stage_i trap_addr_mux_i", false,-1, 1,0);
        vcdp->declBus(c+6401,"top riscv_core_i if_stage_i boot_addr_i", false,-1, 30,0);
        vcdp->declBit(c+1897,"top riscv_core_i if_stage_i req_i", false,-1);
        vcdp->declBit(c+297,"top riscv_core_i if_stage_i instr_req_o", false,-1);
        vcdp->declBus(c+321,"top riscv_core_i if_stage_i instr_addr_o", false,-1, 31,0);
        vcdp->declBit(c+297,"top riscv_core_i if_stage_i instr_gnt_i", false,-1);
        vcdp->declBit(c+5809,"top riscv_core_i if_stage_i instr_rvalid_i", false,-1);
        vcdp->declBus(c+5865,"top riscv_core_i if_stage_i instr_rdata_i", false,-1, 31,0);
        vcdp->declBit(c+6033,"top riscv_core_i if_stage_i instr_err_pmp_i", false,-1);
        vcdp->declBus(c+4073,"top riscv_core_i if_stage_i hwlp_dec_cnt_id_o", false,-1, 1,0);
        vcdp->declBit(c+1841,"top riscv_core_i if_stage_i is_hwlp_id_o", false,-1);
        vcdp->declBit(c+4081,"top riscv_core_i if_stage_i instr_valid_id_o", false,-1);
        vcdp->declBus(c+4089,"top riscv_core_i if_stage_i instr_rdata_id_o", false,-1, 31,0);
        vcdp->declBit(c+4097,"top riscv_core_i if_stage_i is_compressed_id_o", false,-1);
        vcdp->declBit(c+4113,"top riscv_core_i if_stage_i illegal_c_insn_id_o", false,-1);
        vcdp->declBus(c+3625,"top riscv_core_i if_stage_i pc_if_o", false,-1, 31,0);
        vcdp->declBus(c+5881,"top riscv_core_i if_stage_i pc_id_o", false,-1, 31,0);
        vcdp->declBit(c+4105,"top riscv_core_i if_stage_i is_fetch_failed_o", false,-1);
        vcdp->declBit(c+329,"top riscv_core_i if_stage_i clear_instr_valid_i", false,-1);
        vcdp->declBit(c+337,"top riscv_core_i if_stage_i pc_set_i", false,-1);
        vcdp->declBus(c+4529,"top riscv_core_i if_stage_i mepc_i", false,-1, 31,0);
        vcdp->declBus(c+6073,"top riscv_core_i if_stage_i uepc_i", false,-1, 31,0);
        vcdp->declBus(c+4537,"top riscv_core_i if_stage_i depc_i", false,-1, 31,0);
        vcdp->declBus(c+345,"top riscv_core_i if_stage_i pc_mux_i", false,-1, 2,0);
        vcdp->declBus(c+3633,"top riscv_core_i if_stage_i exc_pc_mux_i", false,-1, 2,0);
        vcdp->declBus(c+3737,"top riscv_core_i if_stage_i exc_vec_pc_mux_i", false,-1, 4,0);
        vcdp->declBus(c+3681,"top riscv_core_i if_stage_i jump_target_id_i", false,-1, 31,0);
        vcdp->declBus(c+5889,"top riscv_core_i if_stage_i jump_target_ex_i", false,-1, 31,0);
        vcdp->declQuad(c+4577,"top riscv_core_i if_stage_i hwlp_start_i", false,-1, 63,0);
        vcdp->declQuad(c+4593,"top riscv_core_i if_stage_i hwlp_end_i", false,-1, 63,0);
        vcdp->declQuad(c+4609,"top riscv_core_i if_stage_i hwlp_cnt_i", false,-1, 63,0);
        vcdp->declBit(c+361,"top riscv_core_i if_stage_i halt_if_i", false,-1);
        vcdp->declBit(c+369,"top riscv_core_i if_stage_i id_ready_i", false,-1);
        vcdp->declBit(c+1433,"top riscv_core_i if_stage_i if_busy_o", false,-1);
        vcdp->declBit(c+457,"top riscv_core_i if_stage_i perf_imiss_o", false,-1);
        vcdp->declBus(c+4641,"top riscv_core_i if_stage_i offset_fsm_cs", false,-1, 0,0);
        vcdp->declBus(c+481,"top riscv_core_i if_stage_i offset_fsm_ns", false,-1, 0,0);
        vcdp->declBit(c+489,"top riscv_core_i if_stage_i if_valid", false,-1);
        vcdp->declBit(c+497,"top riscv_core_i if_stage_i if_ready", false,-1);
        vcdp->declBit(c+505,"top riscv_core_i if_stage_i valid", false,-1);
        vcdp->declBit(c+1433,"top riscv_core_i if_stage_i prefetch_busy", false,-1);
        vcdp->declBit(c+513,"top riscv_core_i if_stage_i branch_req", false,-1);
        vcdp->declBus(c+1753,"top riscv_core_i if_stage_i fetch_addr_n", false,-1, 31,0);
        vcdp->declBit(c+521,"top riscv_core_i if_stage_i fetch_valid", false,-1);
        vcdp->declBit(c+529,"top riscv_core_i if_stage_i fetch_ready", false,-1);
        vcdp->declBus(c+537,"top riscv_core_i if_stage_i fetch_rdata", false,-1, 31,0);
        vcdp->declBus(c+3625,"top riscv_core_i if_stage_i fetch_addr", false,-1, 31,0);
        vcdp->declBit(c+4649,"top riscv_core_i if_stage_i is_hwlp_id_q", false,-1);
        vcdp->declBit(c+1977,"top riscv_core_i if_stage_i fetch_is_hwlp", false,-1);
        vcdp->declBus(c+3745,"top riscv_core_i if_stage_i exc_pc", false,-1, 31,0);
        vcdp->declBit(c+3753,"top riscv_core_i if_stage_i hwlp_jump", false,-1);
        vcdp->declBit(c+1985,"top riscv_core_i if_stage_i hwlp_branch", false,-1);
        vcdp->declBus(c+3761,"top riscv_core_i if_stage_i hwlp_target", false,-1, 31,0);
        vcdp->declBus(c+3769,"top riscv_core_i if_stage_i hwlp_dec_cnt", false,-1, 1,0);
        vcdp->declBus(c+4657,"top riscv_core_i if_stage_i hwlp_dec_cnt_if", false,-1, 1,0);
        vcdp->declBus(c+3777,"top riscv_core_i if_stage_i trap_base_addr", false,-1, 23,0);
        vcdp->declBit(c+545,"top riscv_core_i if_stage_i fetch_failed", false,-1);
        vcdp->declBus(c+553,"top riscv_core_i if_stage_i instr_decompressed", false,-1, 31,0);
        vcdp->declBit(c+561,"top riscv_core_i if_stage_i illegal_c_insn", false,-1);
        vcdp->declBit(c+569,"top riscv_core_i if_stage_i instr_compressed_int", false,-1);
        vcdp->declBus(c+6113,"top riscv_core_i if_stage_i hwloop_controller_i N_REGS", false,-1, 31,0);
        vcdp->declBus(c+3625,"top riscv_core_i if_stage_i hwloop_controller_i current_pc_i", false,-1, 31,0);
        vcdp->declQuad(c+4577,"top riscv_core_i if_stage_i hwloop_controller_i hwlp_start_addr_i", false,-1, 63,0);
        vcdp->declQuad(c+4593,"top riscv_core_i if_stage_i hwloop_controller_i hwlp_end_addr_i", false,-1, 63,0);
        vcdp->declQuad(c+4609,"top riscv_core_i if_stage_i hwloop_controller_i hwlp_counter_i", false,-1, 63,0);
        vcdp->declBus(c+3769,"top riscv_core_i if_stage_i hwloop_controller_i hwlp_dec_cnt_o", false,-1, 1,0);
        vcdp->declBus(c+1993,"top riscv_core_i if_stage_i hwloop_controller_i hwlp_dec_cnt_id_i", false,-1, 1,0);
        vcdp->declBit(c+3753,"top riscv_core_i if_stage_i hwloop_controller_i hwlp_jump_o", false,-1);
        vcdp->declBus(c+3761,"top riscv_core_i if_stage_i hwloop_controller_i hwlp_targ_addr_o", false,-1, 31,0);
        vcdp->declBus(c+3785,"top riscv_core_i if_stage_i hwloop_controller_i pc_is_end_addr", false,-1, 1,0);
        vcdp->declBus(c+3793,"top riscv_core_i if_stage_i hwloop_controller_i j", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i if_stage_i compressed_decoder_i FPU", false,-1, 31,0);
        vcdp->declBus(c+537,"top riscv_core_i if_stage_i compressed_decoder_i instr_i", false,-1, 31,0);
        vcdp->declBus(c+553,"top riscv_core_i if_stage_i compressed_decoder_i instr_o", false,-1, 31,0);
        vcdp->declBit(c+569,"top riscv_core_i if_stage_i compressed_decoder_i is_compressed_o", false,-1);
        vcdp->declBit(c+561,"top riscv_core_i if_stage_i compressed_decoder_i illegal_instr_o", false,-1);
        vcdp->declBit(c+5913,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i clk", false,-1);
        vcdp->declBit(c+5921,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i rst_n", false,-1);
        vcdp->declBit(c+1897,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i req_i", false,-1);
        vcdp->declBit(c+513,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i branch_i", false,-1);
        vcdp->declBus(c+1761,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i addr_i", false,-1, 31,0);
        vcdp->declBit(c+3753,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i hwloop_i", false,-1);
        vcdp->declBus(c+3761,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i hwloop_target_i", false,-1, 31,0);
        vcdp->declBit(c+1985,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i hwlp_branch_o", false,-1);
        vcdp->declBit(c+529,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i ready_i", false,-1);
        vcdp->declBit(c+521,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i valid_o", false,-1);
        vcdp->declBus(c+537,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i rdata_o", false,-1, 31,0);
        vcdp->declBus(c+3625,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i addr_o", false,-1, 31,0);
        vcdp->declBit(c+1977,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i is_hwlp_o", false,-1);
        vcdp->declBit(c+297,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i instr_req_o", false,-1);
        vcdp->declBit(c+297,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i instr_gnt_i", false,-1);
        vcdp->declBus(c+321,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i instr_addr_o", false,-1, 31,0);
        vcdp->declBus(c+5865,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i instr_rdata_i", false,-1, 31,0);
        vcdp->declBit(c+5809,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i instr_rvalid_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i instr_err_pmp_i", false,-1);
        vcdp->declBit(c+545,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fetch_failed_o", false,-1);
        vcdp->declBit(c+1433,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i busy_o", false,-1);
        vcdp->declBus(c+4665,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i CS", false,-1, 2,0);
        vcdp->declBus(c+577,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i NS", false,-1, 2,0);
        vcdp->declBus(c+4673,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i hwlp_CS", false,-1, 2,0);
        vcdp->declBus(c+585,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i hwlp_NS", false,-1, 2,0);
        vcdp->declBus(c+4681,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i instr_addr_q", false,-1, 31,0);
        vcdp->declBus(c+4689,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fetch_addr", false,-1, 31,0);
        vcdp->declBit(c+593,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fetch_is_hwlp", false,-1);
        vcdp->declBit(c+601,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i addr_valid", false,-1);
        vcdp->declBit(c+609,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_valid", false,-1);
        vcdp->declBit(c+4697,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_ready", false,-1);
        vcdp->declBit(c+617,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_clear", false,-1);
        vcdp->declBit(c+2001,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_hwlp", false,-1);
        vcdp->declBit(c+3801,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i valid_stored", false,-1);
        vcdp->declBit(c+3809,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i hwlp_masked", false,-1);
        vcdp->declBit(c+1985,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i hwlp_branch", false,-1);
        vcdp->declBit(c+625,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i hwloop_speculative", false,-1);
        vcdp->declBit(c+633,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i unaligned_is_compressed", false,-1);
        vcdp->declBit(c+5913,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i clk", false,-1);
        vcdp->declBit(c+5921,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i rst_n", false,-1);
        vcdp->declBit(c+617,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i clear_i", false,-1);
        vcdp->declBus(c+4681,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i in_addr_i", false,-1, 31,0);
        vcdp->declBus(c+5865,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i in_rdata_i", false,-1, 31,0);
        vcdp->declBit(c+609,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i in_valid_i", false,-1);
        vcdp->declBit(c+4697,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i in_ready_o", false,-1);
        vcdp->declBit(c+2001,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i in_replace2_i", false,-1);
        vcdp->declBit(c+2001,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i in_is_hwlp_i", false,-1);
        vcdp->declBit(c+521,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i out_valid_o", false,-1);
        vcdp->declBit(c+529,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i out_ready_i", false,-1);
        vcdp->declBus(c+537,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i out_rdata_o", false,-1, 31,0);
        vcdp->declBus(c+3625,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i out_addr_o", false,-1, 31,0);
        vcdp->declBit(c+633,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i unaligned_is_compressed_o", false,-1);
        vcdp->declBit(c+3801,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i out_valid_stored_o", false,-1);
        vcdp->declBit(c+1977,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i out_is_hwlp_o", false,-1);
        vcdp->declBus(c+6409,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i DEPTH", false,-1, 31,0);
        vcdp->declArray(c+641,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i addr_n", false,-1, 127,0);
        vcdp->declArray(c+673,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i addr_int", false,-1, 127,0);
        vcdp->declArray(c+4705,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i addr_Q", false,-1, 127,0);
        vcdp->declArray(c+705,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i rdata_n", false,-1, 127,0);
        vcdp->declArray(c+737,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i rdata_int", false,-1, 127,0);
        vcdp->declArray(c+4737,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i rdata_Q", false,-1, 127,0);
        vcdp->declBus(c+769,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i valid_n", false,-1, 0,3);
        vcdp->declBus(c+777,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i valid_int", false,-1, 0,3);
        vcdp->declBus(c+4769,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i valid_Q", false,-1, 0,3);
        vcdp->declBus(c+785,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i is_hwlp_n", false,-1, 0,1);
        vcdp->declBus(c+793,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i is_hwlp_int", false,-1, 0,1);
        vcdp->declBus(c+4777,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i is_hwlp_Q", false,-1, 0,1);
        vcdp->declBus(c+801,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i addr_next", false,-1, 31,0);
        vcdp->declBus(c+809,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i rdata", false,-1, 31,0);
        vcdp->declBus(c+1745,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i rdata_unaligned", false,-1, 31,0);
        vcdp->declBit(c+817,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i valid", false,-1);
        vcdp->declBit(c+1457,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i valid_unaligned", false,-1);
        vcdp->declBit(c+825,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i aligned_is_compressed", false,-1);
        vcdp->declBit(c+633,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i unaligned_is_compressed", false,-1);
        vcdp->declBit(c+4785,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i aligned_is_compressed_st", false,-1);
        vcdp->declBit(c+4793,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i unaligned_is_compressed_st", false,-1);
        vcdp->declBus(c+833,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i unnamedblk1 j", false,-1, 31,0);
        vcdp->declBus(c+841,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i unnamedblk2 i", false,-1, 31,0);
        vcdp->declBus(c+849,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i unnamedblk3 i", false,-1, 31,0);
        vcdp->declBus(c+857,"top riscv_core_i if_stage_i prefetch_32 prefetch_buffer_i fifo_i unnamedblk4 i", false,-1, 31,0);
        vcdp->declBus(c+6113,"top riscv_core_i id_stage_i N_HWLP", false,-1, 31,0);
        vcdp->declBus(c+6121,"top riscv_core_i id_stage_i N_HWLP_BITS", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i PULP_SECURE", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i A_EXTENSION", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i APU", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i FPU", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i PULP_ZFINX", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i FP_DIVSQRT", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i SHARED_FP", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i SHARED_DSP_MULT", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i SHARED_INT_MULT", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i SHARED_INT_DIV", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i SHARED_FP_DIVSQRT", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i WAPUTYPE", false,-1, 31,0);
        vcdp->declBus(c+6417,"top riscv_core_i id_stage_i APU_NARGS_CPU", false,-1, 31,0);
        vcdp->declBus(c+6425,"top riscv_core_i id_stage_i APU_WOP_CPU", false,-1, 31,0);
        vcdp->declBus(c+6433,"top riscv_core_i id_stage_i APU_NDSFLAGS_CPU", false,-1, 31,0);
        vcdp->declBus(c+6441,"top riscv_core_i id_stage_i APU_NUSFLAGS_CPU", false,-1, 31,0);
        vcdp->declBit(c+5913,"top riscv_core_i id_stage_i clk", false,-1);
        vcdp->declBit(c+5921,"top riscv_core_i id_stage_i rst_n", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i test_en_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i fregfile_disable_i", false,-1);
        vcdp->declBit(c+5969,"top riscv_core_i id_stage_i fetch_enable_i", false,-1);
        vcdp->declBit(c+1857,"top riscv_core_i id_stage_i ctrl_busy_o", false,-1);
        vcdp->declBit(c+1945,"top riscv_core_i id_stage_i core_ctrl_firstfetch_o", false,-1);
        vcdp->declBit(c+3657,"top riscv_core_i id_stage_i is_decoding_o", false,-1);
        vcdp->declBus(c+4073,"top riscv_core_i id_stage_i hwlp_dec_cnt_i", false,-1, 1,0);
        vcdp->declBit(c+1841,"top riscv_core_i id_stage_i is_hwlp_i", false,-1);
        vcdp->declBit(c+4081,"top riscv_core_i id_stage_i instr_valid_i", false,-1);
        vcdp->declBus(c+4089,"top riscv_core_i id_stage_i instr_rdata_i", false,-1, 31,0);
        vcdp->declBit(c+1897,"top riscv_core_i id_stage_i instr_req_o", false,-1);
        vcdp->declBit(c+4129,"top riscv_core_i id_stage_i branch_in_ex_o", false,-1);
        vcdp->declBit(c+1849,"top riscv_core_i id_stage_i branch_decision_i", false,-1);
        vcdp->declBus(c+3681,"top riscv_core_i id_stage_i jump_target_o", false,-1, 31,0);
        vcdp->declBit(c+329,"top riscv_core_i id_stage_i clear_instr_valid_o", false,-1);
        vcdp->declBit(c+337,"top riscv_core_i id_stage_i pc_set_o", false,-1);
        vcdp->declBus(c+345,"top riscv_core_i id_stage_i pc_mux_o", false,-1, 2,0);
        vcdp->declBus(c+3633,"top riscv_core_i id_stage_i exc_pc_mux_o", false,-1, 2,0);
        vcdp->declBus(c+3649,"top riscv_core_i id_stage_i trap_addr_mux_o", false,-1, 1,0);
        vcdp->declBit(c+4113,"top riscv_core_i id_stage_i illegal_c_insn_i", false,-1);
        vcdp->declBit(c+4097,"top riscv_core_i id_stage_i is_compressed_i", false,-1);
        vcdp->declBit(c+4105,"top riscv_core_i id_stage_i is_fetch_failed_i", false,-1);
        vcdp->declBus(c+3625,"top riscv_core_i id_stage_i pc_if_i", false,-1, 31,0);
        vcdp->declBus(c+5881,"top riscv_core_i id_stage_i pc_id_i", false,-1, 31,0);
        vcdp->declBit(c+361,"top riscv_core_i id_stage_i halt_if_o", false,-1);
        vcdp->declBit(c+369,"top riscv_core_i id_stage_i id_ready_o", false,-1);
        vcdp->declBit(c+377,"top riscv_core_i id_stage_i ex_ready_i", false,-1);
        vcdp->declBit(c+401,"top riscv_core_i id_stage_i wb_ready_i", false,-1);
        vcdp->declBit(c+385,"top riscv_core_i id_stage_i id_valid_o", false,-1);
        vcdp->declBit(c+393,"top riscv_core_i id_stage_i ex_valid_i", false,-1);
        vcdp->declBus(c+4137,"top riscv_core_i id_stage_i pc_ex_o", false,-1, 31,0);
        vcdp->declBus(c+4161,"top riscv_core_i id_stage_i alu_operand_a_ex_o", false,-1, 31,0);
        vcdp->declBus(c+4169,"top riscv_core_i id_stage_i alu_operand_b_ex_o", false,-1, 31,0);
        vcdp->declBus(c+5889,"top riscv_core_i id_stage_i alu_operand_c_ex_o", false,-1, 31,0);
        vcdp->declBus(c+4177,"top riscv_core_i id_stage_i bmask_a_ex_o", false,-1, 4,0);
        vcdp->declBus(c+4185,"top riscv_core_i id_stage_i bmask_b_ex_o", false,-1, 4,0);
        vcdp->declBus(c+4193,"top riscv_core_i id_stage_i imm_vec_ext_ex_o", false,-1, 1,0);
        vcdp->declBus(c+4201,"top riscv_core_i id_stage_i alu_vec_mode_ex_o", false,-1, 1,0);
        vcdp->declBus(c+4417,"top riscv_core_i id_stage_i regfile_waddr_ex_o", false,-1, 5,0);
        vcdp->declBit(c+4425,"top riscv_core_i id_stage_i regfile_we_ex_o", false,-1);
        vcdp->declBus(c+4441,"top riscv_core_i id_stage_i regfile_alu_waddr_ex_o", false,-1, 5,0);
        vcdp->declBit(c+4449,"top riscv_core_i id_stage_i regfile_alu_we_ex_o", false,-1);
        vcdp->declBit(c+4145,"top riscv_core_i id_stage_i alu_en_ex_o", false,-1);
        vcdp->declBus(c+4153,"top riscv_core_i id_stage_i alu_operator_ex_o", false,-1, 6,0);
        vcdp->declBit(c+4209,"top riscv_core_i id_stage_i alu_is_clpx_ex_o", false,-1);
        vcdp->declBit(c+4217,"top riscv_core_i id_stage_i alu_is_subrot_ex_o", false,-1);
        vcdp->declBus(c+4225,"top riscv_core_i id_stage_i alu_clpx_shift_ex_o", false,-1, 1,0);
        vcdp->declBus(c+4233,"top riscv_core_i id_stage_i mult_operator_ex_o", false,-1, 2,0);
        vcdp->declBus(c+4241,"top riscv_core_i id_stage_i mult_operand_a_ex_o", false,-1, 31,0);
        vcdp->declBus(c+4249,"top riscv_core_i id_stage_i mult_operand_b_ex_o", false,-1, 31,0);
        vcdp->declBus(c+4257,"top riscv_core_i id_stage_i mult_operand_c_ex_o", false,-1, 31,0);
        vcdp->declBit(c+4265,"top riscv_core_i id_stage_i mult_en_ex_o", false,-1);
        vcdp->declBit(c+4273,"top riscv_core_i id_stage_i mult_sel_subword_ex_o", false,-1);
        vcdp->declBus(c+4281,"top riscv_core_i id_stage_i mult_signed_mode_ex_o", false,-1, 1,0);
        vcdp->declBus(c+4289,"top riscv_core_i id_stage_i mult_imm_ex_o", false,-1, 4,0);
        vcdp->declBus(c+4297,"top riscv_core_i id_stage_i mult_dot_op_a_ex_o", false,-1, 31,0);
        vcdp->declBus(c+4305,"top riscv_core_i id_stage_i mult_dot_op_b_ex_o", false,-1, 31,0);
        vcdp->declBus(c+4313,"top riscv_core_i id_stage_i mult_dot_op_c_ex_o", false,-1, 31,0);
        vcdp->declBus(c+4321,"top riscv_core_i id_stage_i mult_dot_signed_ex_o", false,-1, 1,0);
        vcdp->declBit(c+4633,"top riscv_core_i id_stage_i mult_is_clpx_ex_o", false,-1);
        vcdp->declBus(c+4329,"top riscv_core_i id_stage_i mult_clpx_shift_ex_o", false,-1, 1,0);
        vcdp->declBit(c+4337,"top riscv_core_i id_stage_i mult_clpx_img_ex_o", false,-1);
        vcdp->declBit(c+4345,"top riscv_core_i id_stage_i apu_en_ex_o", false,-1);
        vcdp->declBus(c+4353,"top riscv_core_i id_stage_i apu_type_ex_o", false,-1, -1,0);
        vcdp->declBus(c+4369,"top riscv_core_i id_stage_i apu_op_ex_o", false,-1, 5,0);
        vcdp->declBus(c+4377,"top riscv_core_i id_stage_i apu_lat_ex_o", false,-1, 1,0);
        vcdp->declArray(c+4385,"top riscv_core_i id_stage_i apu_operands_ex_o", false,-1, 95,0);
        vcdp->declBus(c+4361,"top riscv_core_i id_stage_i apu_flags_ex_o", false,-1, 14,0);
        vcdp->declBus(c+4409,"top riscv_core_i id_stage_i apu_waddr_ex_o", false,-1, 5,0);
        vcdp->declBus(c+6161,"top riscv_core_i id_stage_i apu_read_regs_o", false,-1, 17,0);
        vcdp->declBus(c+6153,"top riscv_core_i id_stage_i apu_read_regs_valid_o", false,-1, 2,0);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i apu_read_dep_i", false,-1);
        vcdp->declBus(c+6169,"top riscv_core_i id_stage_i apu_write_regs_o", false,-1, 11,0);
        vcdp->declBus(c+6057,"top riscv_core_i id_stage_i apu_write_regs_valid_o", false,-1, 1,0);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i apu_write_dep_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i apu_perf_dep_o", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i apu_busy_i", false,-1);
        vcdp->declBus(c+6153,"top riscv_core_i id_stage_i frm_i", false,-1, 2,0);
        vcdp->declBit(c+4457,"top riscv_core_i id_stage_i csr_access_ex_o", false,-1);
        vcdp->declBus(c+4465,"top riscv_core_i id_stage_i csr_op_ex_o", false,-1, 1,0);
        vcdp->declBus(c+6185,"top riscv_core_i id_stage_i current_priv_lvl_i", false,-1, 1,0);
        vcdp->declBit(c+1905,"top riscv_core_i id_stage_i csr_irq_sec_o", false,-1);
        vcdp->declBus(c+433,"top riscv_core_i id_stage_i csr_cause_o", false,-1, 6,0);
        vcdp->declBit(c+3697,"top riscv_core_i id_stage_i csr_save_if_o", false,-1);
        vcdp->declBit(c+425,"top riscv_core_i id_stage_i csr_save_id_o", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i csr_save_ex_o", false,-1);
        vcdp->declBit(c+3705,"top riscv_core_i id_stage_i csr_restore_mret_id_o", false,-1);
        vcdp->declBit(c+3713,"top riscv_core_i id_stage_i csr_restore_uret_id_o", false,-1);
        vcdp->declBit(c+3721,"top riscv_core_i id_stage_i csr_restore_dret_id_o", false,-1);
        vcdp->declBit(c+417,"top riscv_core_i id_stage_i csr_save_cause_o", false,-1);
        vcdp->declQuad(c+4577,"top riscv_core_i id_stage_i hwlp_start_o", false,-1, 63,0);
        vcdp->declQuad(c+4593,"top riscv_core_i id_stage_i hwlp_end_o", false,-1, 63,0);
        vcdp->declQuad(c+4609,"top riscv_core_i id_stage_i hwlp_cnt_o", false,-1, 63,0);
        vcdp->declBus(c+1913,"top riscv_core_i id_stage_i csr_hwlp_regid_i", false,-1, 0,0);
        vcdp->declBus(c+1921,"top riscv_core_i id_stage_i csr_hwlp_we_i", false,-1, 2,0);
        vcdp->declBus(c+1929,"top riscv_core_i id_stage_i csr_hwlp_data_i", false,-1, 31,0);
        vcdp->declBit(c+4505,"top riscv_core_i id_stage_i data_req_ex_o", false,-1);
        vcdp->declBit(c+5873,"top riscv_core_i id_stage_i data_we_ex_o", false,-1);
        vcdp->declBus(c+5897,"top riscv_core_i id_stage_i data_type_ex_o", false,-1, 1,0);
        vcdp->declBus(c+4489,"top riscv_core_i id_stage_i data_sign_ext_ex_o", false,-1, 1,0);
        vcdp->declBus(c+4497,"top riscv_core_i id_stage_i data_reg_offset_ex_o", false,-1, 1,0);
        vcdp->declBit(c+4513,"top riscv_core_i id_stage_i data_load_event_ex_o", false,-1);
        vcdp->declBit(c+5905,"top riscv_core_i id_stage_i data_misaligned_ex_o", false,-1);
        vcdp->declBit(c+4121,"top riscv_core_i id_stage_i prepost_useincr_ex_o", false,-1);
        vcdp->declBit(c+3665,"top riscv_core_i id_stage_i data_misaligned_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i data_err_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i data_err_ack_o", false,-1);
        vcdp->declBus(c+4065,"top riscv_core_i id_stage_i atop_ex_o", false,-1, 5,0);
        vcdp->declBit(c+1953,"top riscv_core_i id_stage_i irq_pending_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i irq_sec_i", false,-1);
        vcdp->declBus(c+1961,"top riscv_core_i id_stage_i irq_id_i", false,-1, 5,0);
        vcdp->declBit(c+4521,"top riscv_core_i id_stage_i m_irq_enable_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i u_irq_enable_i", false,-1);
        vcdp->declBit(c+1825,"top riscv_core_i id_stage_i irq_ack_o", false,-1);
        vcdp->declBus(c+4057,"top riscv_core_i id_stage_i irq_id_o", false,-1, 4,0);
        vcdp->declBus(c+3641,"top riscv_core_i id_stage_i exc_cause_o", false,-1, 5,0);
        vcdp->declBit(c+4545,"top riscv_core_i id_stage_i debug_mode_o", false,-1);
        vcdp->declBus(c+441,"top riscv_core_i id_stage_i debug_cause_o", false,-1, 2,0);
        vcdp->declBit(c+449,"top riscv_core_i id_stage_i debug_csr_save_o", false,-1);
        vcdp->declBit(c+5961,"top riscv_core_i id_stage_i debug_req_i", false,-1);
        vcdp->declBit(c+4553,"top riscv_core_i id_stage_i debug_single_step_i", false,-1);
        vcdp->declBit(c+4561,"top riscv_core_i id_stage_i debug_ebreakm_i", false,-1);
        vcdp->declBit(c+4569,"top riscv_core_i id_stage_i debug_ebreaku_i", false,-1);
        vcdp->declBus(c+4433,"top riscv_core_i id_stage_i regfile_waddr_wb_i", false,-1, 5,0);
        vcdp->declBit(c+1865,"top riscv_core_i id_stage_i regfile_we_wb_i", false,-1);
        vcdp->declBus(c+3689,"top riscv_core_i id_stage_i regfile_wdata_wb_i", false,-1, 31,0);
        vcdp->declBus(c+4441,"top riscv_core_i id_stage_i regfile_alu_waddr_fw_i", false,-1, 5,0);
        vcdp->declBit(c+1873,"top riscv_core_i id_stage_i regfile_alu_we_fw_i", false,-1);
        vcdp->declBus(c+353,"top riscv_core_i id_stage_i regfile_alu_wdata_fw_i", false,-1, 31,0);
        vcdp->declBit(c+3673,"top riscv_core_i id_stage_i mult_multicycle_i", false,-1);
        vcdp->declBit(c+465,"top riscv_core_i id_stage_i perf_jump_o", false,-1);
        vcdp->declBit(c+1937,"top riscv_core_i id_stage_i perf_jr_stall_o", false,-1);
        vcdp->declBit(c+473,"top riscv_core_i id_stage_i perf_ld_stall_o", false,-1);
        vcdp->declBit(c+3729,"top riscv_core_i id_stage_i perf_pipeline_stall_o", false,-1);
        vcdp->declBus(c+4089,"top riscv_core_i id_stage_i instr", false,-1, 31,0);
        vcdp->declBit(c+865,"top riscv_core_i id_stage_i deassert_we", false,-1);
        vcdp->declBit(c+3817,"top riscv_core_i id_stage_i illegal_insn_dec", false,-1);
        vcdp->declBit(c+2009,"top riscv_core_i id_stage_i ebrk_insn", false,-1);
        vcdp->declBit(c+2017,"top riscv_core_i id_stage_i mret_insn_dec", false,-1);
        vcdp->declBit(c+2025,"top riscv_core_i id_stage_i uret_insn_dec", false,-1);
        vcdp->declBit(c+2033,"top riscv_core_i id_stage_i dret_insn_dec", false,-1);
        vcdp->declBit(c+2041,"top riscv_core_i id_stage_i ecall_insn_dec", false,-1);
        vcdp->declBit(c+2049,"top riscv_core_i id_stage_i pipe_flush_dec", false,-1);
        vcdp->declBit(c+2057,"top riscv_core_i id_stage_i fencei_insn_dec", false,-1);
        vcdp->declBit(c+2065,"top riscv_core_i id_stage_i rega_used_dec", false,-1);
        vcdp->declBit(c+2073,"top riscv_core_i id_stage_i regb_used_dec", false,-1);
        vcdp->declBit(c+2081,"top riscv_core_i id_stage_i regc_used_dec", false,-1);
        vcdp->declBit(c+3825,"top riscv_core_i id_stage_i branch_taken_ex", false,-1);
        vcdp->declBus(c+873,"top riscv_core_i id_stage_i jump_in_id", false,-1, 1,0);
        vcdp->declBus(c+2089,"top riscv_core_i id_stage_i jump_in_dec", false,-1, 1,0);
        vcdp->declBit(c+3665,"top riscv_core_i id_stage_i misaligned_stall", false,-1);
        vcdp->declBit(c+1937,"top riscv_core_i id_stage_i jr_stall", false,-1);
        vcdp->declBit(c+473,"top riscv_core_i id_stage_i load_stall", false,-1);
        vcdp->declBit(c+2097,"top riscv_core_i id_stage_i csr_apu_stall", false,-1);
        vcdp->declBit(c+2105,"top riscv_core_i id_stage_i instr_multicycle", false,-1);
        vcdp->declBit(c+881,"top riscv_core_i id_stage_i hwloop_mask", false,-1);
        vcdp->declBit(c+889,"top riscv_core_i id_stage_i halt_id", false,-1);
        vcdp->declBus(c+1465,"top riscv_core_i id_stage_i logic_in_memory_funct", false,-1, 31,0);
        vcdp->declBus(c+2113,"top riscv_core_i id_stage_i imm_i_type", false,-1, 31,0);
        vcdp->declBus(c+4801,"top riscv_core_i id_stage_i imm_iz_type", false,-1, 31,0);
        vcdp->declBus(c+4809,"top riscv_core_i id_stage_i imm_s_type", false,-1, 31,0);
        vcdp->declBus(c+4817,"top riscv_core_i id_stage_i imm_logmem_type", false,-1, 31,0);
        vcdp->declBus(c+4825,"top riscv_core_i id_stage_i imm_sb_type", false,-1, 31,0);
        vcdp->declBus(c+4833,"top riscv_core_i id_stage_i imm_u_type", false,-1, 31,0);
        vcdp->declBus(c+4841,"top riscv_core_i id_stage_i imm_uj_type", false,-1, 31,0);
        vcdp->declBus(c+4849,"top riscv_core_i id_stage_i imm_z_type", false,-1, 31,0);
        vcdp->declBus(c+4857,"top riscv_core_i id_stage_i imm_s2_type", false,-1, 31,0);
        vcdp->declBus(c+4865,"top riscv_core_i id_stage_i imm_bi_type", false,-1, 31,0);
        vcdp->declBus(c+4873,"top riscv_core_i id_stage_i imm_s3_type", false,-1, 31,0);
        vcdp->declBus(c+4881,"top riscv_core_i id_stage_i imm_vs_type", false,-1, 31,0);
        vcdp->declBus(c+2121,"top riscv_core_i id_stage_i imm_vu_type", false,-1, 31,0);
        vcdp->declBus(c+4889,"top riscv_core_i id_stage_i imm_shuffleb_type", false,-1, 31,0);
        vcdp->declBus(c+4897,"top riscv_core_i id_stage_i imm_shuffleh_type", false,-1, 31,0);
        vcdp->declBus(c+2129,"top riscv_core_i id_stage_i imm_shuffle_type", false,-1, 31,0);
        vcdp->declBus(c+4905,"top riscv_core_i id_stage_i imm_clip_type", false,-1, 31,0);
        vcdp->declBus(c+2137,"top riscv_core_i id_stage_i imm_a", false,-1, 31,0);
        vcdp->declBus(c+3833,"top riscv_core_i id_stage_i imm_b", false,-1, 31,0);
        vcdp->declBus(c+3681,"top riscv_core_i id_stage_i jump_target", false,-1, 31,0);
        vcdp->declBit(c+4913,"top riscv_core_i id_stage_i irq_req_ctrl", false,-1);
        vcdp->declBit(c+4921,"top riscv_core_i id_stage_i irq_sec_ctrl", false,-1);
        vcdp->declBus(c+4929,"top riscv_core_i id_stage_i irq_id_ctrl", false,-1, 5,0);
        vcdp->declBit(c+2145,"top riscv_core_i id_stage_i exc_ack", false,-1);
        vcdp->declBit(c+897,"top riscv_core_i id_stage_i exc_kill", false,-1);
        vcdp->declBus(c+4937,"top riscv_core_i id_stage_i regfile_addr_ra_id", false,-1, 5,0);
        vcdp->declBus(c+4945,"top riscv_core_i id_stage_i regfile_addr_rb_id", false,-1, 5,0);
        vcdp->declBus(c+2153,"top riscv_core_i id_stage_i regfile_addr_rc_id", false,-1, 5,0);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i regfile_fp_a", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i regfile_fp_b", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i regfile_fp_c", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i regfile_fp_d", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i fregfile_ena", false,-1);
        vcdp->declBus(c+4953,"top riscv_core_i id_stage_i regfile_waddr_id", false,-1, 5,0);
        vcdp->declBus(c+2161,"top riscv_core_i id_stage_i regfile_alu_waddr_id", false,-1, 5,0);
        vcdp->declBit(c+905,"top riscv_core_i id_stage_i regfile_alu_we_id", false,-1);
        vcdp->declBit(c+3841,"top riscv_core_i id_stage_i regfile_alu_we_dec_id", false,-1);
        vcdp->declBus(c+2169,"top riscv_core_i id_stage_i regfile_data_ra_id", false,-1, 31,0);
        vcdp->declBus(c+4961,"top riscv_core_i id_stage_i regfile_data_rb_id", false,-1, 31,0);
        vcdp->declBus(c+2177,"top riscv_core_i id_stage_i regfile_data_rc_id", false,-1, 31,0);
        vcdp->declBit(c+3849,"top riscv_core_i id_stage_i alu_en", false,-1);
        vcdp->declBus(c+2185,"top riscv_core_i id_stage_i alu_operator", false,-1, 6,0);
        vcdp->declBus(c+3857,"top riscv_core_i id_stage_i alu_op_a_mux_sel", false,-1, 2,0);
        vcdp->declBus(c+3865,"top riscv_core_i id_stage_i alu_op_b_mux_sel", false,-1, 2,0);
        vcdp->declBus(c+3873,"top riscv_core_i id_stage_i alu_op_c_mux_sel", false,-1, 1,0);
        vcdp->declBus(c+2193,"top riscv_core_i id_stage_i regc_mux", false,-1, 1,0);
        vcdp->declBus(c+2201,"top riscv_core_i id_stage_i imm_a_mux_sel", false,-1, 0,0);
        vcdp->declBus(c+3881,"top riscv_core_i id_stage_i imm_b_mux_sel", false,-1, 3,0);
        vcdp->declBus(c+2209,"top riscv_core_i id_stage_i jump_target_mux_sel", false,-1, 1,0);
        vcdp->declBus(c+2217,"top riscv_core_i id_stage_i mult_operator", false,-1, 2,0);
        vcdp->declBit(c+913,"top riscv_core_i id_stage_i mult_en", false,-1);
        vcdp->declBit(c+921,"top riscv_core_i id_stage_i mult_int_en", false,-1);
        vcdp->declBit(c+2225,"top riscv_core_i id_stage_i mult_sel_subword", false,-1);
        vcdp->declBus(c+2233,"top riscv_core_i id_stage_i mult_signed_mode", false,-1, 1,0);
        vcdp->declBit(c+929,"top riscv_core_i id_stage_i mult_dot_en", false,-1);
        vcdp->declBus(c+2241,"top riscv_core_i id_stage_i mult_dot_signed", false,-1, 1,0);
        vcdp->declBus(c+6449,"top riscv_core_i id_stage_i fpu_src_fmt", false,-1, 2,0);
        vcdp->declBus(c+6449,"top riscv_core_i id_stage_i fpu_dst_fmt", false,-1, 2,0);
        vcdp->declBus(c+6457,"top riscv_core_i id_stage_i fpu_int_fmt", false,-1, 1,0);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i apu_en", false,-1);
        vcdp->declBus(c+6057,"top riscv_core_i id_stage_i apu_type", false,-1, -1,0);
        vcdp->declBus(c+6049,"top riscv_core_i id_stage_i apu_op", false,-1, 5,0);
        vcdp->declBus(c+6057,"top riscv_core_i id_stage_i apu_lat", false,-1, 1,0);
        vcdp->declArray(c+25,"top riscv_core_i id_stage_i apu_operands", false,-1, 95,0);
        vcdp->declBus(c+6065,"top riscv_core_i id_stage_i apu_flags", false,-1, 14,0);
        vcdp->declBus(c+6049,"top riscv_core_i id_stage_i apu_waddr", false,-1, 5,0);
        vcdp->declBus(c+6465,"top riscv_core_i id_stage_i apu_read_regs", false,-1, 17,0);
        vcdp->declBus(c+6473,"top riscv_core_i id_stage_i apu_read_regs_valid", false,-1, 2,0);
        vcdp->declBus(c+6481,"top riscv_core_i id_stage_i apu_write_regs", false,-1, 11,0);
        vcdp->declBus(c+6489,"top riscv_core_i id_stage_i apu_write_regs_valid", false,-1, 1,0);
        vcdp->declBus(c+6057,"top riscv_core_i id_stage_i apu_flags_src", false,-1, -1,0);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i apu_stall", false,-1);
        vcdp->declBus(c+6153,"top riscv_core_i id_stage_i fp_rnd_mode", false,-1, 2,0);
        vcdp->declBit(c+937,"top riscv_core_i id_stage_i regfile_we_id", false,-1);
        vcdp->declBit(c+2249,"top riscv_core_i id_stage_i regfile_alu_waddr_mux_sel", false,-1);
        vcdp->declBit(c+3889,"top riscv_core_i id_stage_i data_we_id", false,-1);
        vcdp->declBus(c+3897,"top riscv_core_i id_stage_i data_type_id", false,-1, 1,0);
        vcdp->declBus(c+2257,"top riscv_core_i id_stage_i data_sign_ext_id", false,-1, 1,0);
        vcdp->declBus(c+6057,"top riscv_core_i id_stage_i data_reg_offset_id", false,-1, 1,0);
        vcdp->declBit(c+945,"top riscv_core_i id_stage_i data_req_id", false,-1);
        vcdp->declBit(c+2265,"top riscv_core_i id_stage_i data_load_event_id", false,-1);
        vcdp->declBus(c+6049,"top riscv_core_i id_stage_i atop_id", false,-1, 5,0);
        vcdp->declBus(c+953,"top riscv_core_i id_stage_i hwloop_regid", false,-1, 0,0);
        vcdp->declBus(c+4969,"top riscv_core_i id_stage_i hwloop_regid_int", false,-1, 0,0);
        vcdp->declBus(c+961,"top riscv_core_i id_stage_i hwloop_we", false,-1, 2,0);
        vcdp->declBus(c+1473,"top riscv_core_i id_stage_i hwloop_we_int", false,-1, 2,0);
        vcdp->declBus(c+969,"top riscv_core_i id_stage_i hwloop_we_masked", false,-1, 2,0);
        vcdp->declBit(c+2273,"top riscv_core_i id_stage_i hwloop_target_mux_sel", false,-1);
        vcdp->declBit(c+2281,"top riscv_core_i id_stage_i hwloop_start_mux_sel", false,-1);
        vcdp->declBit(c+2289,"top riscv_core_i id_stage_i hwloop_cnt_mux_sel", false,-1);
        vcdp->declBus(c+3905,"top riscv_core_i id_stage_i hwloop_target", false,-1, 31,0);
        vcdp->declBus(c+1769,"top riscv_core_i id_stage_i hwloop_start", false,-1, 31,0);
        vcdp->declBus(c+3913,"top riscv_core_i id_stage_i hwloop_start_int", false,-1, 31,0);
        vcdp->declBus(c+1777,"top riscv_core_i id_stage_i hwloop_end", false,-1, 31,0);
        vcdp->declBus(c+977,"top riscv_core_i id_stage_i hwloop_cnt", false,-1, 31,0);
        vcdp->declBus(c+985,"top riscv_core_i id_stage_i hwloop_cnt_int", false,-1, 31,0);
        vcdp->declBit(c+993,"top riscv_core_i id_stage_i hwloop_valid", false,-1);
        vcdp->declBit(c+2297,"top riscv_core_i id_stage_i csr_access", false,-1);
        vcdp->declBus(c+1481,"top riscv_core_i id_stage_i csr_op", false,-1, 1,0);
        vcdp->declBit(c+3921,"top riscv_core_i id_stage_i csr_status", false,-1);
        vcdp->declBit(c+3929,"top riscv_core_i id_stage_i prepost_useincr", false,-1);
        vcdp->declBus(c+3937,"top riscv_core_i id_stage_i operand_a_fw_mux_sel", false,-1, 1,0);
        vcdp->declBus(c+3945,"top riscv_core_i id_stage_i operand_b_fw_mux_sel", false,-1, 1,0);
        vcdp->declBus(c+3953,"top riscv_core_i id_stage_i operand_c_fw_mux_sel", false,-1, 1,0);
        vcdp->declBus(c+1001,"top riscv_core_i id_stage_i operand_a_fw_id", false,-1, 31,0);
        vcdp->declBus(c+1009,"top riscv_core_i id_stage_i operand_b_fw_id", false,-1, 31,0);
        vcdp->declBus(c+1017,"top riscv_core_i id_stage_i operand_c_fw_id", false,-1, 31,0);
        vcdp->declBus(c+1025,"top riscv_core_i id_stage_i operand_b", false,-1, 31,0);
        vcdp->declBus(c+1033,"top riscv_core_i id_stage_i operand_b_vec", false,-1, 31,0);
        vcdp->declBus(c+1041,"top riscv_core_i id_stage_i operand_c", false,-1, 31,0);
        vcdp->declBus(c+1489,"top riscv_core_i id_stage_i operand_c_vec", false,-1, 31,0);
        vcdp->declBus(c+1049,"top riscv_core_i id_stage_i alu_operand_a", false,-1, 31,0);
        vcdp->declBus(c+1057,"top riscv_core_i id_stage_i alu_operand_b", false,-1, 31,0);
        vcdp->declBus(c+1041,"top riscv_core_i id_stage_i alu_operand_c", false,-1, 31,0);
        vcdp->declBus(c+2305,"top riscv_core_i id_stage_i bmask_a_mux", false,-1, 0,0);
        vcdp->declBus(c+2313,"top riscv_core_i id_stage_i bmask_b_mux", false,-1, 1,0);
        vcdp->declBit(c+2321,"top riscv_core_i id_stage_i alu_bmask_a_mux_sel", false,-1);
        vcdp->declBit(c+2329,"top riscv_core_i id_stage_i alu_bmask_b_mux_sel", false,-1);
        vcdp->declBus(c+2337,"top riscv_core_i id_stage_i mult_imm_mux", false,-1, 0,0);
        vcdp->declBus(c+2345,"top riscv_core_i id_stage_i bmask_a_id_imm", false,-1, 4,0);
        vcdp->declBus(c+2353,"top riscv_core_i id_stage_i bmask_b_id_imm", false,-1, 4,0);
        vcdp->declBus(c+1497,"top riscv_core_i id_stage_i bmask_a_id", false,-1, 4,0);
        vcdp->declBus(c+1505,"top riscv_core_i id_stage_i bmask_b_id", false,-1, 4,0);
        vcdp->declBus(c+2361,"top riscv_core_i id_stage_i imm_vec_ext_id", false,-1, 1,0);
        vcdp->declBus(c+2369,"top riscv_core_i id_stage_i mult_imm_id", false,-1, 4,0);
        vcdp->declBus(c+2377,"top riscv_core_i id_stage_i alu_vec_mode", false,-1, 1,0);
        vcdp->declBit(c+3961,"top riscv_core_i id_stage_i scalar_replication", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i scalar_replication_c", false,-1);
        vcdp->declBit(c+2385,"top riscv_core_i id_stage_i reg_d_ex_is_reg_a_id", false,-1);
        vcdp->declBit(c+2393,"top riscv_core_i id_stage_i reg_d_ex_is_reg_b_id", false,-1);
        vcdp->declBit(c+2401,"top riscv_core_i id_stage_i reg_d_ex_is_reg_c_id", false,-1);
        vcdp->declBit(c+2409,"top riscv_core_i id_stage_i reg_d_wb_is_reg_a_id", false,-1);
        vcdp->declBit(c+2417,"top riscv_core_i id_stage_i reg_d_wb_is_reg_b_id", false,-1);
        vcdp->declBit(c+2425,"top riscv_core_i id_stage_i reg_d_wb_is_reg_c_id", false,-1);
        vcdp->declBit(c+2433,"top riscv_core_i id_stage_i reg_d_alu_is_reg_a_id", false,-1);
        vcdp->declBit(c+2441,"top riscv_core_i id_stage_i reg_d_alu_is_reg_b_id", false,-1);
        vcdp->declBit(c+2449,"top riscv_core_i id_stage_i reg_d_alu_is_reg_c_id", false,-1);
        vcdp->declBit(c+2457,"top riscv_core_i id_stage_i is_clpx", false,-1);
        vcdp->declBit(c+2465,"top riscv_core_i id_stage_i is_subrot", false,-1);
        vcdp->declBit(c+2473,"top riscv_core_i id_stage_i mret_dec", false,-1);
        vcdp->declBit(c+2481,"top riscv_core_i id_stage_i uret_dec", false,-1);
        vcdp->declBit(c+2489,"top riscv_core_i id_stage_i dret_dec", false,-1);
        vcdp->declBus(c+6425,"top riscv_core_i id_stage_i registers_i ADDR_WIDTH", false,-1, 31,0);
        vcdp->declBus(c+6089,"top riscv_core_i id_stage_i registers_i DATA_WIDTH", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i registers_i FPU", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i registers_i PULP_ZFINX", false,-1, 31,0);
        vcdp->declBit(c+5913,"top riscv_core_i id_stage_i registers_i clk", false,-1);
        vcdp->declBit(c+5921,"top riscv_core_i id_stage_i registers_i rst_n", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i registers_i test_en_i", false,-1);
        vcdp->declBus(c+4937,"top riscv_core_i id_stage_i registers_i raddr_a_i", false,-1, 5,0);
        vcdp->declBus(c+2169,"top riscv_core_i id_stage_i registers_i rdata_a_o", false,-1, 31,0);
        vcdp->declBus(c+4945,"top riscv_core_i id_stage_i registers_i raddr_b_i", false,-1, 5,0);
        vcdp->declBus(c+4961,"top riscv_core_i id_stage_i registers_i rdata_b_o", false,-1, 31,0);
        vcdp->declBus(c+2153,"top riscv_core_i id_stage_i registers_i raddr_c_i", false,-1, 5,0);
        vcdp->declBus(c+2177,"top riscv_core_i id_stage_i registers_i rdata_c_o", false,-1, 31,0);
        vcdp->declBus(c+4433,"top riscv_core_i id_stage_i registers_i waddr_a_i", false,-1, 5,0);
        vcdp->declBus(c+3689,"top riscv_core_i id_stage_i registers_i wdata_a_i", false,-1, 31,0);
        vcdp->declBit(c+1865,"top riscv_core_i id_stage_i registers_i we_a_i", false,-1);
        vcdp->declBus(c+4441,"top riscv_core_i id_stage_i registers_i waddr_b_i", false,-1, 5,0);
        vcdp->declBus(c+353,"top riscv_core_i id_stage_i registers_i wdata_b_i", false,-1, 31,0);
        vcdp->declBit(c+1873,"top riscv_core_i id_stage_i registers_i we_b_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i registers_i BIST", false,-1);
        vcdp->declBit(c+6497,"top riscv_core_i id_stage_i registers_i CSN_T", false,-1);
        vcdp->declBit(c+6505,"top riscv_core_i id_stage_i registers_i WEN_T", false,-1);
        vcdp->declBus(c+6513,"top riscv_core_i id_stage_i registers_i A_T", false,-1, 5,0);
        vcdp->declBus(c+6521,"top riscv_core_i id_stage_i registers_i D_T", false,-1, 31,0);
        vcdp->declBus(c+2169,"top riscv_core_i id_stage_i registers_i Q_T", false,-1, 31,0);
        vcdp->declBus(c+4937,"top riscv_core_i id_stage_i registers_i ReadAddr_a_muxed", false,-1, 5,0);
        vcdp->declBit(c+1865,"top riscv_core_i id_stage_i registers_i WriteEnable_a_muxed", false,-1);
        vcdp->declBus(c+4433,"top riscv_core_i id_stage_i registers_i WriteAddr_a_muxed", false,-1, 5,0);
        vcdp->declBus(c+3689,"top riscv_core_i id_stage_i registers_i WriteData_a_muxed", false,-1, 31,0);
        vcdp->declBit(c+1873,"top riscv_core_i id_stage_i registers_i WriteEnable_b_muxed", false,-1);
        vcdp->declBus(c+4441,"top riscv_core_i id_stage_i registers_i WriteAddr_b_muxed", false,-1, 5,0);
        vcdp->declBus(c+353,"top riscv_core_i id_stage_i registers_i WriteData_b_muxed", false,-1, 31,0);
        vcdp->declBus(c+4977,"top riscv_core_i id_stage_i registers_i TestReadAddr_Q", false,-1, 5,0);
        vcdp->declBus(c+6425,"top riscv_core_i id_stage_i registers_i riscv_register_file_i ADDR_WIDTH", false,-1, 31,0);
        vcdp->declBus(c+6089,"top riscv_core_i id_stage_i registers_i riscv_register_file_i DATA_WIDTH", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i registers_i riscv_register_file_i FPU", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i registers_i riscv_register_file_i PULP_ZFINX", false,-1, 31,0);
        vcdp->declBit(c+5913,"top riscv_core_i id_stage_i registers_i riscv_register_file_i clk", false,-1);
        vcdp->declBit(c+5921,"top riscv_core_i id_stage_i registers_i riscv_register_file_i rst_n", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i registers_i riscv_register_file_i test_en_i", false,-1);
        vcdp->declBus(c+4937,"top riscv_core_i id_stage_i registers_i riscv_register_file_i raddr_a_i", false,-1, 5,0);
        vcdp->declBus(c+2169,"top riscv_core_i id_stage_i registers_i riscv_register_file_i rdata_a_o", false,-1, 31,0);
        vcdp->declBus(c+4945,"top riscv_core_i id_stage_i registers_i riscv_register_file_i raddr_b_i", false,-1, 5,0);
        vcdp->declBus(c+4961,"top riscv_core_i id_stage_i registers_i riscv_register_file_i rdata_b_o", false,-1, 31,0);
        vcdp->declBus(c+2153,"top riscv_core_i id_stage_i registers_i riscv_register_file_i raddr_c_i", false,-1, 5,0);
        vcdp->declBus(c+2177,"top riscv_core_i id_stage_i registers_i riscv_register_file_i rdata_c_o", false,-1, 31,0);
        vcdp->declBus(c+4433,"top riscv_core_i id_stage_i registers_i riscv_register_file_i waddr_a_i", false,-1, 5,0);
        vcdp->declBus(c+3689,"top riscv_core_i id_stage_i registers_i riscv_register_file_i wdata_a_i", false,-1, 31,0);
        vcdp->declBit(c+1865,"top riscv_core_i id_stage_i registers_i riscv_register_file_i we_a_i", false,-1);
        vcdp->declBus(c+4441,"top riscv_core_i id_stage_i registers_i riscv_register_file_i waddr_b_i", false,-1, 5,0);
        vcdp->declBus(c+353,"top riscv_core_i id_stage_i registers_i riscv_register_file_i wdata_b_i", false,-1, 31,0);
        vcdp->declBit(c+1873,"top riscv_core_i id_stage_i registers_i riscv_register_file_i we_b_i", false,-1);
        vcdp->declBus(c+6089,"top riscv_core_i id_stage_i registers_i riscv_register_file_i NUM_WORDS", false,-1, 31,0);
        vcdp->declBus(c+6089,"top riscv_core_i id_stage_i registers_i riscv_register_file_i NUM_FP_WORDS", false,-1, 31,0);
        vcdp->declBus(c+6089,"top riscv_core_i id_stage_i registers_i riscv_register_file_i NUM_TOT_WORDS", false,-1, 31,0);
        vcdp->declArray(c+4985,"top riscv_core_i id_stage_i registers_i riscv_register_file_i mem", false,-1, 1023,0);
        vcdp->declArray(c+6529,"top riscv_core_i id_stage_i registers_i riscv_register_file_i mem_fp", false,-1, 1023,0);
        vcdp->declBus(c+4433,"top riscv_core_i id_stage_i registers_i riscv_register_file_i waddr_a", false,-1, 5,0);
        vcdp->declBus(c+4441,"top riscv_core_i id_stage_i registers_i riscv_register_file_i waddr_b", false,-1, 5,0);
        vcdp->declBus(c+2497,"top riscv_core_i id_stage_i registers_i riscv_register_file_i we_a_dec", false,-1, 31,0);
        vcdp->declBus(c+2505,"top riscv_core_i id_stage_i registers_i riscv_register_file_i we_b_dec", false,-1, 31,0);
        vcdp->declBus(c+6785,"top riscv_core_i id_stage_i registers_i riscv_register_file_i we_a_decoder unnamedblk1 i", false,-1, 31,0);
        vcdp->declBus(c+6785,"top riscv_core_i id_stage_i registers_i riscv_register_file_i we_b_decoder unnamedblk2 i", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i decoder_i A_EXTENSION", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i decoder_i FPU", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i decoder_i FP_DIVSQRT", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i decoder_i PULP_SECURE", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i decoder_i SHARED_FP", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i decoder_i SHARED_DSP_MULT", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i decoder_i SHARED_INT_MULT", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i decoder_i SHARED_INT_DIV", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i decoder_i SHARED_FP_DIVSQRT", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i decoder_i WAPUTYPE", false,-1, 31,0);
        vcdp->declBus(c+6425,"top riscv_core_i id_stage_i decoder_i APU_WOP_CPU", false,-1, 31,0);
        vcdp->declBit(c+865,"top riscv_core_i id_stage_i decoder_i deassert_we_i", false,-1);
        vcdp->declBit(c+3665,"top riscv_core_i id_stage_i decoder_i data_misaligned_i", false,-1);
        vcdp->declBit(c+3673,"top riscv_core_i id_stage_i decoder_i mult_multicycle_i", false,-1);
        vcdp->declBit(c+2105,"top riscv_core_i id_stage_i decoder_i instr_multicycle_o", false,-1);
        vcdp->declBit(c+3817,"top riscv_core_i id_stage_i decoder_i illegal_insn_o", false,-1);
        vcdp->declBit(c+2009,"top riscv_core_i id_stage_i decoder_i ebrk_insn_o", false,-1);
        vcdp->declBit(c+2017,"top riscv_core_i id_stage_i decoder_i mret_insn_o", false,-1);
        vcdp->declBit(c+2025,"top riscv_core_i id_stage_i decoder_i uret_insn_o", false,-1);
        vcdp->declBit(c+2033,"top riscv_core_i id_stage_i decoder_i dret_insn_o", false,-1);
        vcdp->declBit(c+2473,"top riscv_core_i id_stage_i decoder_i mret_dec_o", false,-1);
        vcdp->declBit(c+2481,"top riscv_core_i id_stage_i decoder_i uret_dec_o", false,-1);
        vcdp->declBit(c+2489,"top riscv_core_i id_stage_i decoder_i dret_dec_o", false,-1);
        vcdp->declBit(c+2041,"top riscv_core_i id_stage_i decoder_i ecall_insn_o", false,-1);
        vcdp->declBit(c+2049,"top riscv_core_i id_stage_i decoder_i pipe_flush_o", false,-1);
        vcdp->declBit(c+2057,"top riscv_core_i id_stage_i decoder_i fencei_insn_o", false,-1);
        vcdp->declBit(c+2065,"top riscv_core_i id_stage_i decoder_i rega_used_o", false,-1);
        vcdp->declBit(c+2073,"top riscv_core_i id_stage_i decoder_i regb_used_o", false,-1);
        vcdp->declBit(c+2081,"top riscv_core_i id_stage_i decoder_i regc_used_o", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i decoder_i reg_fp_a_o", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i decoder_i reg_fp_b_o", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i decoder_i reg_fp_c_o", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i decoder_i reg_fp_d_o", false,-1);
        vcdp->declBus(c+2305,"top riscv_core_i id_stage_i decoder_i bmask_a_mux_o", false,-1, 0,0);
        vcdp->declBus(c+2313,"top riscv_core_i id_stage_i decoder_i bmask_b_mux_o", false,-1, 1,0);
        vcdp->declBit(c+2321,"top riscv_core_i id_stage_i decoder_i alu_bmask_a_mux_sel_o", false,-1);
        vcdp->declBit(c+2329,"top riscv_core_i id_stage_i decoder_i alu_bmask_b_mux_sel_o", false,-1);
        vcdp->declBus(c+4089,"top riscv_core_i id_stage_i decoder_i instr_rdata_i", false,-1, 31,0);
        vcdp->declBit(c+4113,"top riscv_core_i id_stage_i decoder_i illegal_c_insn_i", false,-1);
        vcdp->declBit(c+3849,"top riscv_core_i id_stage_i decoder_i alu_en_o", false,-1);
        vcdp->declBus(c+2185,"top riscv_core_i id_stage_i decoder_i alu_operator_o", false,-1, 6,0);
        vcdp->declBus(c+3857,"top riscv_core_i id_stage_i decoder_i alu_op_a_mux_sel_o", false,-1, 2,0);
        vcdp->declBus(c+3865,"top riscv_core_i id_stage_i decoder_i alu_op_b_mux_sel_o", false,-1, 2,0);
        vcdp->declBus(c+3873,"top riscv_core_i id_stage_i decoder_i alu_op_c_mux_sel_o", false,-1, 1,0);
        vcdp->declBus(c+2377,"top riscv_core_i id_stage_i decoder_i alu_vec_mode_o", false,-1, 1,0);
        vcdp->declBit(c+3961,"top riscv_core_i id_stage_i decoder_i scalar_replication_o", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i decoder_i scalar_replication_c_o", false,-1);
        vcdp->declBus(c+2201,"top riscv_core_i id_stage_i decoder_i imm_a_mux_sel_o", false,-1, 0,0);
        vcdp->declBus(c+3881,"top riscv_core_i id_stage_i decoder_i imm_b_mux_sel_o", false,-1, 3,0);
        vcdp->declBus(c+2193,"top riscv_core_i id_stage_i decoder_i regc_mux_o", false,-1, 1,0);
        vcdp->declBit(c+2457,"top riscv_core_i id_stage_i decoder_i is_clpx_o", false,-1);
        vcdp->declBit(c+2465,"top riscv_core_i id_stage_i decoder_i is_subrot_o", false,-1);
        vcdp->declBus(c+2217,"top riscv_core_i id_stage_i decoder_i mult_operator_o", false,-1, 2,0);
        vcdp->declBit(c+921,"top riscv_core_i id_stage_i decoder_i mult_int_en_o", false,-1);
        vcdp->declBit(c+929,"top riscv_core_i id_stage_i decoder_i mult_dot_en_o", false,-1);
        vcdp->declBus(c+2337,"top riscv_core_i id_stage_i decoder_i mult_imm_mux_o", false,-1, 0,0);
        vcdp->declBit(c+2225,"top riscv_core_i id_stage_i decoder_i mult_sel_subword_o", false,-1);
        vcdp->declBus(c+2233,"top riscv_core_i id_stage_i decoder_i mult_signed_mode_o", false,-1, 1,0);
        vcdp->declBus(c+2241,"top riscv_core_i id_stage_i decoder_i mult_dot_signed_o", false,-1, 1,0);
        vcdp->declBus(c+6153,"top riscv_core_i id_stage_i decoder_i frm_i", false,-1, 2,0);
        vcdp->declBus(c+6449,"top riscv_core_i id_stage_i decoder_i fpu_dst_fmt_o", false,-1, 2,0);
        vcdp->declBus(c+6449,"top riscv_core_i id_stage_i decoder_i fpu_src_fmt_o", false,-1, 2,0);
        vcdp->declBus(c+6457,"top riscv_core_i id_stage_i decoder_i fpu_int_fmt_o", false,-1, 1,0);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i decoder_i apu_en_o", false,-1);
        vcdp->declBus(c+6057,"top riscv_core_i id_stage_i decoder_i apu_type_o", false,-1, -1,0);
        vcdp->declBus(c+6049,"top riscv_core_i id_stage_i decoder_i apu_op_o", false,-1, 5,0);
        vcdp->declBus(c+6057,"top riscv_core_i id_stage_i decoder_i apu_lat_o", false,-1, 1,0);
        vcdp->declBus(c+6057,"top riscv_core_i id_stage_i decoder_i apu_flags_src_o", false,-1, -1,0);
        vcdp->declBus(c+6153,"top riscv_core_i id_stage_i decoder_i fp_rnd_mode_o", false,-1, 2,0);
        vcdp->declBit(c+937,"top riscv_core_i id_stage_i decoder_i regfile_mem_we_o", false,-1);
        vcdp->declBit(c+905,"top riscv_core_i id_stage_i decoder_i regfile_alu_we_o", false,-1);
        vcdp->declBit(c+3841,"top riscv_core_i id_stage_i decoder_i regfile_alu_we_dec_o", false,-1);
        vcdp->declBit(c+2249,"top riscv_core_i id_stage_i decoder_i regfile_alu_waddr_sel_o", false,-1);
        vcdp->declBit(c+2297,"top riscv_core_i id_stage_i decoder_i csr_access_o", false,-1);
        vcdp->declBit(c+3921,"top riscv_core_i id_stage_i decoder_i csr_status_o", false,-1);
        vcdp->declBus(c+1481,"top riscv_core_i id_stage_i decoder_i csr_op_o", false,-1, 1,0);
        vcdp->declBus(c+6185,"top riscv_core_i id_stage_i decoder_i current_priv_lvl_i", false,-1, 1,0);
        vcdp->declBit(c+945,"top riscv_core_i id_stage_i decoder_i data_req_o", false,-1);
        vcdp->declBit(c+3889,"top riscv_core_i id_stage_i decoder_i data_we_o", false,-1);
        vcdp->declBit(c+3929,"top riscv_core_i id_stage_i decoder_i prepost_useincr_o", false,-1);
        vcdp->declBus(c+3897,"top riscv_core_i id_stage_i decoder_i data_type_o", false,-1, 1,0);
        vcdp->declBus(c+2257,"top riscv_core_i id_stage_i decoder_i data_sign_extension_o", false,-1, 1,0);
        vcdp->declBus(c+6057,"top riscv_core_i id_stage_i decoder_i data_reg_offset_o", false,-1, 1,0);
        vcdp->declBit(c+2265,"top riscv_core_i id_stage_i decoder_i data_load_event_o", false,-1);
        vcdp->declBus(c+6049,"top riscv_core_i id_stage_i decoder_i atop_o", false,-1, 5,0);
        vcdp->declBus(c+1473,"top riscv_core_i id_stage_i decoder_i hwloop_we_o", false,-1, 2,0);
        vcdp->declBit(c+2273,"top riscv_core_i id_stage_i decoder_i hwloop_target_mux_sel_o", false,-1);
        vcdp->declBit(c+2281,"top riscv_core_i id_stage_i decoder_i hwloop_start_mux_sel_o", false,-1);
        vcdp->declBit(c+2289,"top riscv_core_i id_stage_i decoder_i hwloop_cnt_mux_sel_o", false,-1);
        vcdp->declBus(c+2089,"top riscv_core_i id_stage_i decoder_i jump_in_dec_o", false,-1, 1,0);
        vcdp->declBus(c+873,"top riscv_core_i id_stage_i decoder_i jump_in_id_o", false,-1, 1,0);
        vcdp->declBus(c+2209,"top riscv_core_i id_stage_i decoder_i jump_target_mux_sel_o", false,-1, 1,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i decoder_i APUTYPE_DSP_MULT", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i decoder_i APUTYPE_INT_MULT", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i decoder_i APUTYPE_INT_DIV", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i decoder_i APUTYPE_FP", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i decoder_i APUTYPE_ADDSUB", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i decoder_i APUTYPE_MULT", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i decoder_i APUTYPE_CAST", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i decoder_i APUTYPE_MAC", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i decoder_i APUTYPE_DIV", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i decoder_i APUTYPE_SQRT", false,-1, 31,0);
        vcdp->declBit(c+2513,"top riscv_core_i id_stage_i decoder_i regfile_mem_we", false,-1);
        vcdp->declBit(c+3841,"top riscv_core_i id_stage_i decoder_i regfile_alu_we", false,-1);
        vcdp->declBit(c+2521,"top riscv_core_i id_stage_i decoder_i data_req", false,-1);
        vcdp->declBus(c+2529,"top riscv_core_i id_stage_i decoder_i hwloop_we", false,-1, 2,0);
        vcdp->declBit(c+3969,"top riscv_core_i id_stage_i decoder_i csr_illegal", false,-1);
        vcdp->declBus(c+2089,"top riscv_core_i id_stage_i decoder_i jump_in_id", false,-1, 1,0);
        vcdp->declBus(c+2537,"top riscv_core_i id_stage_i decoder_i csr_op", false,-1, 1,0);
        vcdp->declBit(c+2545,"top riscv_core_i id_stage_i decoder_i mult_int_en", false,-1);
        vcdp->declBit(c+2553,"top riscv_core_i id_stage_i decoder_i mult_dot_en", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i decoder_i apu_en", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i decoder_i check_fprm", false,-1);
        vcdp->declBus(c+6793,"top riscv_core_i id_stage_i decoder_i fpu_op", false,-1, 3,0);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i decoder_i fpu_op_mod", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i decoder_i fpu_vec_op", false,-1);
        vcdp->declBus(c+6801,"top riscv_core_i id_stage_i decoder_i fp_op_group", false,-1, 1,0);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i controller_i FPU", false,-1, 31,0);
        vcdp->declBit(c+5913,"top riscv_core_i id_stage_i controller_i clk", false,-1);
        vcdp->declBit(c+5921,"top riscv_core_i id_stage_i controller_i rst_n", false,-1);
        vcdp->declBit(c+5969,"top riscv_core_i id_stage_i controller_i fetch_enable_i", false,-1);
        vcdp->declBit(c+1857,"top riscv_core_i id_stage_i controller_i ctrl_busy_o", false,-1);
        vcdp->declBit(c+1945,"top riscv_core_i id_stage_i controller_i first_fetch_o", false,-1);
        vcdp->declBit(c+3657,"top riscv_core_i id_stage_i controller_i is_decoding_o", false,-1);
        vcdp->declBit(c+4105,"top riscv_core_i id_stage_i controller_i is_fetch_failed_i", false,-1);
        vcdp->declBit(c+865,"top riscv_core_i id_stage_i controller_i deassert_we_o", false,-1);
        vcdp->declBit(c+3817,"top riscv_core_i id_stage_i controller_i illegal_insn_i", false,-1);
        vcdp->declBit(c+2041,"top riscv_core_i id_stage_i controller_i ecall_insn_i", false,-1);
        vcdp->declBit(c+2017,"top riscv_core_i id_stage_i controller_i mret_insn_i", false,-1);
        vcdp->declBit(c+2025,"top riscv_core_i id_stage_i controller_i uret_insn_i", false,-1);
        vcdp->declBit(c+2033,"top riscv_core_i id_stage_i controller_i dret_insn_i", false,-1);
        vcdp->declBit(c+2473,"top riscv_core_i id_stage_i controller_i mret_dec_i", false,-1);
        vcdp->declBit(c+2481,"top riscv_core_i id_stage_i controller_i uret_dec_i", false,-1);
        vcdp->declBit(c+2489,"top riscv_core_i id_stage_i controller_i dret_dec_i", false,-1);
        vcdp->declBit(c+2049,"top riscv_core_i id_stage_i controller_i pipe_flush_i", false,-1);
        vcdp->declBit(c+2009,"top riscv_core_i id_stage_i controller_i ebrk_insn_i", false,-1);
        vcdp->declBit(c+2057,"top riscv_core_i id_stage_i controller_i fencei_insn_i", false,-1);
        vcdp->declBit(c+3921,"top riscv_core_i id_stage_i controller_i csr_status_i", false,-1);
        vcdp->declBit(c+2105,"top riscv_core_i id_stage_i controller_i instr_multicycle_i", false,-1);
        vcdp->declBit(c+881,"top riscv_core_i id_stage_i controller_i hwloop_mask_o", false,-1);
        vcdp->declBit(c+4081,"top riscv_core_i id_stage_i controller_i instr_valid_i", false,-1);
        vcdp->declBit(c+1897,"top riscv_core_i id_stage_i controller_i instr_req_o", false,-1);
        vcdp->declBit(c+337,"top riscv_core_i id_stage_i controller_i pc_set_o", false,-1);
        vcdp->declBus(c+345,"top riscv_core_i id_stage_i controller_i pc_mux_o", false,-1, 2,0);
        vcdp->declBus(c+3633,"top riscv_core_i id_stage_i controller_i exc_pc_mux_o", false,-1, 2,0);
        vcdp->declBus(c+3649,"top riscv_core_i id_stage_i controller_i trap_addr_mux_o", false,-1, 1,0);
        vcdp->declBit(c+4505,"top riscv_core_i id_stage_i controller_i data_req_ex_i", false,-1);
        vcdp->declBit(c+5873,"top riscv_core_i id_stage_i controller_i data_we_ex_i", false,-1);
        vcdp->declBit(c+3665,"top riscv_core_i id_stage_i controller_i data_misaligned_i", false,-1);
        vcdp->declBit(c+2265,"top riscv_core_i id_stage_i controller_i data_load_event_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i controller_i data_err_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i controller_i data_err_ack_o", false,-1);
        vcdp->declBit(c+3673,"top riscv_core_i id_stage_i controller_i mult_multicycle_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i controller_i apu_en_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i controller_i apu_read_dep_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i controller_i apu_write_dep_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i controller_i apu_stall_o", false,-1);
        vcdp->declBit(c+3825,"top riscv_core_i id_stage_i controller_i branch_taken_ex_i", false,-1);
        vcdp->declBus(c+873,"top riscv_core_i id_stage_i controller_i jump_in_id_i", false,-1, 1,0);
        vcdp->declBus(c+2089,"top riscv_core_i id_stage_i controller_i jump_in_dec_i", false,-1, 1,0);
        vcdp->declBit(c+1953,"top riscv_core_i id_stage_i controller_i irq_pending_i", false,-1);
        vcdp->declBit(c+4913,"top riscv_core_i id_stage_i controller_i irq_req_ctrl_i", false,-1);
        vcdp->declBit(c+4921,"top riscv_core_i id_stage_i controller_i irq_sec_ctrl_i", false,-1);
        vcdp->declBus(c+4929,"top riscv_core_i id_stage_i controller_i irq_id_ctrl_i", false,-1, 5,0);
        vcdp->declBit(c+4521,"top riscv_core_i id_stage_i controller_i m_IE_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i controller_i u_IE_i", false,-1);
        vcdp->declBus(c+6185,"top riscv_core_i id_stage_i controller_i current_priv_lvl_i", false,-1, 1,0);
        vcdp->declBit(c+1825,"top riscv_core_i id_stage_i controller_i irq_ack_o", false,-1);
        vcdp->declBus(c+4057,"top riscv_core_i id_stage_i controller_i irq_id_o", false,-1, 4,0);
        vcdp->declBus(c+3641,"top riscv_core_i id_stage_i controller_i exc_cause_o", false,-1, 5,0);
        vcdp->declBit(c+2145,"top riscv_core_i id_stage_i controller_i exc_ack_o", false,-1);
        vcdp->declBit(c+897,"top riscv_core_i id_stage_i controller_i exc_kill_o", false,-1);
        vcdp->declBit(c+4545,"top riscv_core_i id_stage_i controller_i debug_mode_o", false,-1);
        vcdp->declBus(c+441,"top riscv_core_i id_stage_i controller_i debug_cause_o", false,-1, 2,0);
        vcdp->declBit(c+449,"top riscv_core_i id_stage_i controller_i debug_csr_save_o", false,-1);
        vcdp->declBit(c+5961,"top riscv_core_i id_stage_i controller_i debug_req_i", false,-1);
        vcdp->declBit(c+4553,"top riscv_core_i id_stage_i controller_i debug_single_step_i", false,-1);
        vcdp->declBit(c+4561,"top riscv_core_i id_stage_i controller_i debug_ebreakm_i", false,-1);
        vcdp->declBit(c+4569,"top riscv_core_i id_stage_i controller_i debug_ebreaku_i", false,-1);
        vcdp->declBit(c+3697,"top riscv_core_i id_stage_i controller_i csr_save_if_o", false,-1);
        vcdp->declBit(c+425,"top riscv_core_i id_stage_i controller_i csr_save_id_o", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i controller_i csr_save_ex_o", false,-1);
        vcdp->declBus(c+433,"top riscv_core_i id_stage_i controller_i csr_cause_o", false,-1, 6,0);
        vcdp->declBit(c+1905,"top riscv_core_i id_stage_i controller_i csr_irq_sec_o", false,-1);
        vcdp->declBit(c+3705,"top riscv_core_i id_stage_i controller_i csr_restore_mret_id_o", false,-1);
        vcdp->declBit(c+3713,"top riscv_core_i id_stage_i controller_i csr_restore_uret_id_o", false,-1);
        vcdp->declBit(c+3721,"top riscv_core_i id_stage_i controller_i csr_restore_dret_id_o", false,-1);
        vcdp->declBit(c+417,"top riscv_core_i id_stage_i controller_i csr_save_cause_o", false,-1);
        vcdp->declBit(c+3841,"top riscv_core_i id_stage_i controller_i regfile_we_id_i", false,-1);
        vcdp->declBus(c+2161,"top riscv_core_i id_stage_i controller_i regfile_alu_waddr_id_i", false,-1, 5,0);
        vcdp->declBit(c+4425,"top riscv_core_i id_stage_i controller_i regfile_we_ex_i", false,-1);
        vcdp->declBus(c+4417,"top riscv_core_i id_stage_i controller_i regfile_waddr_ex_i", false,-1, 5,0);
        vcdp->declBit(c+1865,"top riscv_core_i id_stage_i controller_i regfile_we_wb_i", false,-1);
        vcdp->declBit(c+1873,"top riscv_core_i id_stage_i controller_i regfile_alu_we_fw_i", false,-1);
        vcdp->declBus(c+3937,"top riscv_core_i id_stage_i controller_i operand_a_fw_mux_sel_o", false,-1, 1,0);
        vcdp->declBus(c+3945,"top riscv_core_i id_stage_i controller_i operand_b_fw_mux_sel_o", false,-1, 1,0);
        vcdp->declBus(c+3953,"top riscv_core_i id_stage_i controller_i operand_c_fw_mux_sel_o", false,-1, 1,0);
        vcdp->declBit(c+2385,"top riscv_core_i id_stage_i controller_i reg_d_ex_is_reg_a_i", false,-1);
        vcdp->declBit(c+2393,"top riscv_core_i id_stage_i controller_i reg_d_ex_is_reg_b_i", false,-1);
        vcdp->declBit(c+2401,"top riscv_core_i id_stage_i controller_i reg_d_ex_is_reg_c_i", false,-1);
        vcdp->declBit(c+2409,"top riscv_core_i id_stage_i controller_i reg_d_wb_is_reg_a_i", false,-1);
        vcdp->declBit(c+2417,"top riscv_core_i id_stage_i controller_i reg_d_wb_is_reg_b_i", false,-1);
        vcdp->declBit(c+2425,"top riscv_core_i id_stage_i controller_i reg_d_wb_is_reg_c_i", false,-1);
        vcdp->declBit(c+2433,"top riscv_core_i id_stage_i controller_i reg_d_alu_is_reg_a_i", false,-1);
        vcdp->declBit(c+2441,"top riscv_core_i id_stage_i controller_i reg_d_alu_is_reg_b_i", false,-1);
        vcdp->declBit(c+2449,"top riscv_core_i id_stage_i controller_i reg_d_alu_is_reg_c_i", false,-1);
        vcdp->declBit(c+361,"top riscv_core_i id_stage_i controller_i halt_if_o", false,-1);
        vcdp->declBit(c+889,"top riscv_core_i id_stage_i controller_i halt_id_o", false,-1);
        vcdp->declBit(c+3665,"top riscv_core_i id_stage_i controller_i misaligned_stall_o", false,-1);
        vcdp->declBit(c+1937,"top riscv_core_i id_stage_i controller_i jr_stall_o", false,-1);
        vcdp->declBit(c+473,"top riscv_core_i id_stage_i controller_i load_stall_o", false,-1);
        vcdp->declBit(c+369,"top riscv_core_i id_stage_i controller_i id_ready_i", false,-1);
        vcdp->declBit(c+393,"top riscv_core_i id_stage_i controller_i ex_valid_i", false,-1);
        vcdp->declBit(c+401,"top riscv_core_i id_stage_i controller_i wb_ready_i", false,-1);
        vcdp->declBit(c+465,"top riscv_core_i id_stage_i controller_i perf_jump_o", false,-1);
        vcdp->declBit(c+1937,"top riscv_core_i id_stage_i controller_i perf_jr_stall_o", false,-1);
        vcdp->declBit(c+473,"top riscv_core_i id_stage_i controller_i perf_ld_stall_o", false,-1);
        vcdp->declBit(c+3729,"top riscv_core_i id_stage_i controller_i perf_pipeline_stall_o", false,-1);
        vcdp->declBus(c+5241,"top riscv_core_i id_stage_i controller_i ctrl_fsm_cs", false,-1, 4,0);
        vcdp->declBus(c+1065,"top riscv_core_i id_stage_i controller_i ctrl_fsm_ns", false,-1, 4,0);
        vcdp->declBit(c+1073,"top riscv_core_i id_stage_i controller_i jump_done", false,-1);
        vcdp->declBit(c+5249,"top riscv_core_i id_stage_i controller_i jump_done_q", false,-1);
        vcdp->declBit(c+1081,"top riscv_core_i id_stage_i controller_i jump_in_dec", false,-1);
        vcdp->declBit(c+1089,"top riscv_core_i id_stage_i controller_i branch_in_id", false,-1);
        vcdp->declBit(c+2561,"top riscv_core_i id_stage_i controller_i boot_done", false,-1);
        vcdp->declBit(c+5257,"top riscv_core_i id_stage_i controller_i boot_done_q", false,-1);
        vcdp->declBit(c+1097,"top riscv_core_i id_stage_i controller_i irq_enable_int", false,-1);
        vcdp->declBit(c+5265,"top riscv_core_i id_stage_i controller_i data_err_q", false,-1);
        vcdp->declBit(c+4545,"top riscv_core_i id_stage_i controller_i debug_mode_q", false,-1);
        vcdp->declBit(c+2569,"top riscv_core_i id_stage_i controller_i debug_mode_n", false,-1);
        vcdp->declBit(c+1105,"top riscv_core_i id_stage_i controller_i ebrk_force_debug_mode", false,-1);
        vcdp->declBit(c+5273,"top riscv_core_i id_stage_i controller_i illegal_insn_q", false,-1);
        vcdp->declBit(c+1113,"top riscv_core_i id_stage_i controller_i illegal_insn_n", false,-1);
        vcdp->declBit(c+1121,"top riscv_core_i id_stage_i controller_i instr_valid_irq_flush_n", false,-1);
        vcdp->declBit(c+5281,"top riscv_core_i id_stage_i controller_i instr_valid_irq_flush_q", false,-1);
        vcdp->declBus(c+6009,"top riscv_core_i id_stage_i int_controller_i PULP_SECURE", false,-1, 31,0);
        vcdp->declBit(c+5913,"top riscv_core_i id_stage_i int_controller_i clk", false,-1);
        vcdp->declBit(c+5921,"top riscv_core_i id_stage_i int_controller_i rst_n", false,-1);
        vcdp->declBit(c+4913,"top riscv_core_i id_stage_i int_controller_i irq_req_ctrl_o", false,-1);
        vcdp->declBit(c+4921,"top riscv_core_i id_stage_i int_controller_i irq_sec_ctrl_o", false,-1);
        vcdp->declBus(c+4929,"top riscv_core_i id_stage_i int_controller_i irq_id_ctrl_o", false,-1, 5,0);
        vcdp->declBit(c+2145,"top riscv_core_i id_stage_i int_controller_i ctrl_ack_i", false,-1);
        vcdp->declBit(c+897,"top riscv_core_i id_stage_i int_controller_i ctrl_kill_i", false,-1);
        vcdp->declBit(c+1953,"top riscv_core_i id_stage_i int_controller_i irq_pending_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i int_controller_i irq_sec_i", false,-1);
        vcdp->declBus(c+1961,"top riscv_core_i id_stage_i int_controller_i irq_id_i", false,-1, 5,0);
        vcdp->declBit(c+4521,"top riscv_core_i id_stage_i int_controller_i m_IE_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i id_stage_i int_controller_i u_IE_i", false,-1);
        vcdp->declBus(c+6185,"top riscv_core_i id_stage_i int_controller_i current_priv_lvl_i", false,-1, 1,0);
        vcdp->declBus(c+5289,"top riscv_core_i id_stage_i int_controller_i exc_ctrl_cs", false,-1, 1,0);
        vcdp->declBit(c+4521,"top riscv_core_i id_stage_i int_controller_i irq_enable_ext", false,-1);
        vcdp->declBus(c+4929,"top riscv_core_i id_stage_i int_controller_i irq_id_q", false,-1, 5,0);
        vcdp->declBit(c+4921,"top riscv_core_i id_stage_i int_controller_i irq_sec_q", false,-1);
        vcdp->declBus(c+6113,"top riscv_core_i id_stage_i hwloop_regs_i N_REGS", false,-1, 31,0);
        vcdp->declBus(c+6121,"top riscv_core_i id_stage_i hwloop_regs_i N_REG_BITS", false,-1, 31,0);
        vcdp->declBit(c+5913,"top riscv_core_i id_stage_i hwloop_regs_i clk", false,-1);
        vcdp->declBit(c+5921,"top riscv_core_i id_stage_i hwloop_regs_i rst_n", false,-1);
        vcdp->declBus(c+1769,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_start_data_i", false,-1, 31,0);
        vcdp->declBus(c+1777,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_end_data_i", false,-1, 31,0);
        vcdp->declBus(c+977,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_cnt_data_i", false,-1, 31,0);
        vcdp->declBus(c+961,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_we_i", false,-1, 2,0);
        vcdp->declBus(c+953,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_regid_i", false,-1, 0,0);
        vcdp->declBit(c+993,"top riscv_core_i id_stage_i hwloop_regs_i valid_i", false,-1);
        vcdp->declBus(c+4073,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_dec_cnt_i", false,-1, 1,0);
        vcdp->declQuad(c+4577,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_start_addr_o", false,-1, 63,0);
        vcdp->declQuad(c+4593,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_end_addr_o", false,-1, 63,0);
        vcdp->declQuad(c+4609,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_counter_o", false,-1, 63,0);
        vcdp->declQuad(c+4577,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_start_q", false,-1, 63,0);
        vcdp->declQuad(c+4593,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_end_q", false,-1, 63,0);
        vcdp->declQuad(c+4609,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_counter_q", false,-1, 63,0);
        vcdp->declQuad(c+2577,"top riscv_core_i id_stage_i hwloop_regs_i hwlp_counter_n", false,-1, 63,0);
        vcdp->declBus(c+5297,"top riscv_core_i id_stage_i hwloop_regs_i i", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i ex_stage_i FPU", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i ex_stage_i FP_DIVSQRT", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i ex_stage_i SHARED_FP", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i ex_stage_i SHARED_DSP_MULT", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i ex_stage_i SHARED_INT_DIV", false,-1, 31,0);
        vcdp->declBus(c+6417,"top riscv_core_i ex_stage_i APU_NARGS_CPU", false,-1, 31,0);
        vcdp->declBus(c+6425,"top riscv_core_i ex_stage_i APU_WOP_CPU", false,-1, 31,0);
        vcdp->declBus(c+6433,"top riscv_core_i ex_stage_i APU_NDSFLAGS_CPU", false,-1, 31,0);
        vcdp->declBus(c+6441,"top riscv_core_i ex_stage_i APU_NUSFLAGS_CPU", false,-1, 31,0);
        vcdp->declBit(c+5913,"top riscv_core_i ex_stage_i clk", false,-1);
        vcdp->declBit(c+5921,"top riscv_core_i ex_stage_i rst_n", false,-1);
        vcdp->declBus(c+4153,"top riscv_core_i ex_stage_i alu_operator_i", false,-1, 6,0);
        vcdp->declBus(c+4161,"top riscv_core_i ex_stage_i alu_operand_a_i", false,-1, 31,0);
        vcdp->declBus(c+4169,"top riscv_core_i ex_stage_i alu_operand_b_i", false,-1, 31,0);
        vcdp->declBus(c+5889,"top riscv_core_i ex_stage_i alu_operand_c_i", false,-1, 31,0);
        vcdp->declBit(c+4145,"top riscv_core_i ex_stage_i alu_en_i", false,-1);
        vcdp->declBus(c+4177,"top riscv_core_i ex_stage_i bmask_a_i", false,-1, 4,0);
        vcdp->declBus(c+4185,"top riscv_core_i ex_stage_i bmask_b_i", false,-1, 4,0);
        vcdp->declBus(c+4193,"top riscv_core_i ex_stage_i imm_vec_ext_i", false,-1, 1,0);
        vcdp->declBus(c+4201,"top riscv_core_i ex_stage_i alu_vec_mode_i", false,-1, 1,0);
        vcdp->declBit(c+4209,"top riscv_core_i ex_stage_i alu_is_clpx_i", false,-1);
        vcdp->declBit(c+4217,"top riscv_core_i ex_stage_i alu_is_subrot_i", false,-1);
        vcdp->declBus(c+4225,"top riscv_core_i ex_stage_i alu_clpx_shift_i", false,-1, 1,0);
        vcdp->declBus(c+4233,"top riscv_core_i ex_stage_i mult_operator_i", false,-1, 2,0);
        vcdp->declBus(c+4241,"top riscv_core_i ex_stage_i mult_operand_a_i", false,-1, 31,0);
        vcdp->declBus(c+4249,"top riscv_core_i ex_stage_i mult_operand_b_i", false,-1, 31,0);
        vcdp->declBus(c+4257,"top riscv_core_i ex_stage_i mult_operand_c_i", false,-1, 31,0);
        vcdp->declBit(c+4265,"top riscv_core_i ex_stage_i mult_en_i", false,-1);
        vcdp->declBit(c+4273,"top riscv_core_i ex_stage_i mult_sel_subword_i", false,-1);
        vcdp->declBus(c+4281,"top riscv_core_i ex_stage_i mult_signed_mode_i", false,-1, 1,0);
        vcdp->declBus(c+4289,"top riscv_core_i ex_stage_i mult_imm_i", false,-1, 4,0);
        vcdp->declBus(c+4297,"top riscv_core_i ex_stage_i mult_dot_op_a_i", false,-1, 31,0);
        vcdp->declBus(c+4305,"top riscv_core_i ex_stage_i mult_dot_op_b_i", false,-1, 31,0);
        vcdp->declBus(c+4313,"top riscv_core_i ex_stage_i mult_dot_op_c_i", false,-1, 31,0);
        vcdp->declBus(c+4321,"top riscv_core_i ex_stage_i mult_dot_signed_i", false,-1, 1,0);
        vcdp->declBit(c+4633,"top riscv_core_i ex_stage_i mult_is_clpx_i", false,-1);
        vcdp->declBus(c+4329,"top riscv_core_i ex_stage_i mult_clpx_shift_i", false,-1, 1,0);
        vcdp->declBit(c+4337,"top riscv_core_i ex_stage_i mult_clpx_img_i", false,-1);
        vcdp->declBit(c+3673,"top riscv_core_i ex_stage_i mult_multicycle_o", false,-1);
        vcdp->declBus(c+6081,"top riscv_core_i ex_stage_i fpu_prec_i", false,-1, 4,0);
        vcdp->declBus(c+6081,"top riscv_core_i ex_stage_i fpu_fflags_o", false,-1, 4,0);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i fpu_fflags_we_o", false,-1);
        vcdp->declBit(c+4345,"top riscv_core_i ex_stage_i apu_en_i", false,-1);
        vcdp->declBus(c+4369,"top riscv_core_i ex_stage_i apu_op_i", false,-1, 5,0);
        vcdp->declBus(c+4377,"top riscv_core_i ex_stage_i apu_lat_i", false,-1, 1,0);
        vcdp->declArray(c+4385,"top riscv_core_i ex_stage_i apu_operands_i", false,-1, 95,0);
        vcdp->declBus(c+4409,"top riscv_core_i ex_stage_i apu_waddr_i", false,-1, 5,0);
        vcdp->declBus(c+4361,"top riscv_core_i ex_stage_i apu_flags_i", false,-1, 14,0);
        vcdp->declBus(c+6161,"top riscv_core_i ex_stage_i apu_read_regs_i", false,-1, 17,0);
        vcdp->declBus(c+6153,"top riscv_core_i ex_stage_i apu_read_regs_valid_i", false,-1, 2,0);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i apu_read_dep_o", false,-1);
        vcdp->declBus(c+6169,"top riscv_core_i ex_stage_i apu_write_regs_i", false,-1, 11,0);
        vcdp->declBus(c+6057,"top riscv_core_i ex_stage_i apu_write_regs_valid_i", false,-1, 1,0);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i apu_write_dep_o", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i apu_perf_type_o", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i apu_perf_cont_o", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i apu_perf_wb_o", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i apu_busy_o", false,-1);
        vcdp->declBit(c+6025,"top riscv_core_i ex_stage_i apu_ready_wb_o", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i apu_master_req_o", false,-1);
        vcdp->declBit(c+6025,"top riscv_core_i ex_stage_i apu_master_ready_o", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i apu_master_gnt_i", false,-1);
        vcdp->declArray(c+1,"top riscv_core_i ex_stage_i apu_master_operands_o", false,-1, 95,0);
        vcdp->declBus(c+6049,"top riscv_core_i ex_stage_i apu_master_op_o", false,-1, 5,0);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i apu_master_valid_i", false,-1);
        vcdp->declBus(c+6073,"top riscv_core_i ex_stage_i apu_master_result_i", false,-1, 31,0);
        vcdp->declBit(c+4505,"top riscv_core_i ex_stage_i lsu_en_i", false,-1);
        vcdp->declBus(c+3689,"top riscv_core_i ex_stage_i lsu_rdata_i", false,-1, 31,0);
        vcdp->declBit(c+4129,"top riscv_core_i ex_stage_i branch_in_ex_i", false,-1);
        vcdp->declBus(c+4441,"top riscv_core_i ex_stage_i regfile_alu_waddr_i", false,-1, 5,0);
        vcdp->declBit(c+4449,"top riscv_core_i ex_stage_i regfile_alu_we_i", false,-1);
        vcdp->declBit(c+4425,"top riscv_core_i ex_stage_i regfile_we_i", false,-1);
        vcdp->declBus(c+4417,"top riscv_core_i ex_stage_i regfile_waddr_i", false,-1, 5,0);
        vcdp->declBit(c+4457,"top riscv_core_i ex_stage_i csr_access_i", false,-1);
        vcdp->declBus(c+1889,"top riscv_core_i ex_stage_i csr_rdata_i", false,-1, 31,0);
        vcdp->declBus(c+4433,"top riscv_core_i ex_stage_i regfile_waddr_wb_o", false,-1, 5,0);
        vcdp->declBit(c+1865,"top riscv_core_i ex_stage_i regfile_we_wb_o", false,-1);
        vcdp->declBus(c+3689,"top riscv_core_i ex_stage_i regfile_wdata_wb_o", false,-1, 31,0);
        vcdp->declBus(c+4441,"top riscv_core_i ex_stage_i regfile_alu_waddr_fw_o", false,-1, 5,0);
        vcdp->declBit(c+1873,"top riscv_core_i ex_stage_i regfile_alu_we_fw_o", false,-1);
        vcdp->declBus(c+353,"top riscv_core_i ex_stage_i regfile_alu_wdata_fw_o", false,-1, 31,0);
        vcdp->declBus(c+5889,"top riscv_core_i ex_stage_i jump_target_o", false,-1, 31,0);
        vcdp->declBit(c+1849,"top riscv_core_i ex_stage_i branch_decision_o", false,-1);
        vcdp->declBit(c+409,"top riscv_core_i ex_stage_i lsu_ready_ex_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i lsu_err_i", false,-1);
        vcdp->declBit(c+377,"top riscv_core_i ex_stage_i ex_ready_o", false,-1);
        vcdp->declBit(c+393,"top riscv_core_i ex_stage_i ex_valid_o", false,-1);
        vcdp->declBit(c+401,"top riscv_core_i ex_stage_i wb_ready_i", false,-1);
        vcdp->declBus(c+1129,"top riscv_core_i ex_stage_i alu_result", false,-1, 31,0);
        vcdp->declBus(c+1137,"top riscv_core_i ex_stage_i mult_result", false,-1, 31,0);
        vcdp->declBit(c+1849,"top riscv_core_i ex_stage_i alu_cmp_result", false,-1);
        vcdp->declBit(c+5305,"top riscv_core_i ex_stage_i regfile_we_lsu", false,-1);
        vcdp->declBus(c+4433,"top riscv_core_i ex_stage_i regfile_waddr_lsu", false,-1, 5,0);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i wb_contention", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i wb_contention_lsu", false,-1);
        vcdp->declBit(c+1145,"top riscv_core_i ex_stage_i alu_ready", false,-1);
        vcdp->declBit(c+2593,"top riscv_core_i ex_stage_i mult_ready", false,-1);
        vcdp->declBit(c+6025,"top riscv_core_i ex_stage_i fpu_ready", false,-1);
        vcdp->declBit(c+6809,"top riscv_core_i ex_stage_i fpu_valid", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i apu_valid", false,-1);
        vcdp->declBus(c+6049,"top riscv_core_i ex_stage_i apu_waddr", false,-1, 5,0);
        vcdp->declBus(c+6817,"top riscv_core_i ex_stage_i apu_result", false,-1, 31,0);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i apu_stall", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i apu_active", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i apu_singlecycle", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i apu_multicycle", false,-1);
        vcdp->declBit(c+6825,"top riscv_core_i ex_stage_i apu_req", false,-1);
        vcdp->declBit(c+6833,"top riscv_core_i ex_stage_i apu_ready", false,-1);
        vcdp->declBit(c+6841,"top riscv_core_i ex_stage_i apu_gnt", false,-1);
        vcdp->declBus(c+6009,"top riscv_core_i ex_stage_i alu_i SHARED_INT_DIV", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i ex_stage_i alu_i FPU", false,-1, 31,0);
        vcdp->declBit(c+5913,"top riscv_core_i ex_stage_i alu_i clk", false,-1);
        vcdp->declBit(c+5921,"top riscv_core_i ex_stage_i alu_i rst_n", false,-1);
        vcdp->declBit(c+4145,"top riscv_core_i ex_stage_i alu_i enable_i", false,-1);
        vcdp->declBus(c+4153,"top riscv_core_i ex_stage_i alu_i operator_i", false,-1, 6,0);
        vcdp->declBus(c+4161,"top riscv_core_i ex_stage_i alu_i operand_a_i", false,-1, 31,0);
        vcdp->declBus(c+4169,"top riscv_core_i ex_stage_i alu_i operand_b_i", false,-1, 31,0);
        vcdp->declBus(c+5889,"top riscv_core_i ex_stage_i alu_i operand_c_i", false,-1, 31,0);
        vcdp->declBus(c+4201,"top riscv_core_i ex_stage_i alu_i vector_mode_i", false,-1, 1,0);
        vcdp->declBus(c+4177,"top riscv_core_i ex_stage_i alu_i bmask_a_i", false,-1, 4,0);
        vcdp->declBus(c+4185,"top riscv_core_i ex_stage_i alu_i bmask_b_i", false,-1, 4,0);
        vcdp->declBus(c+4193,"top riscv_core_i ex_stage_i alu_i imm_vec_ext_i", false,-1, 1,0);
        vcdp->declBit(c+4209,"top riscv_core_i ex_stage_i alu_i is_clpx_i", false,-1);
        vcdp->declBit(c+4217,"top riscv_core_i ex_stage_i alu_i is_subrot_i", false,-1);
        vcdp->declBus(c+4225,"top riscv_core_i ex_stage_i alu_i clpx_shift_i", false,-1, 1,0);
        vcdp->declBus(c+1129,"top riscv_core_i ex_stage_i alu_i result_o", false,-1, 31,0);
        vcdp->declBit(c+1849,"top riscv_core_i ex_stage_i alu_i comparison_result_o", false,-1);
        vcdp->declBit(c+1145,"top riscv_core_i ex_stage_i alu_i ready_o", false,-1);
        vcdp->declBit(c+377,"top riscv_core_i ex_stage_i alu_i ex_ready_i", false,-1);
        vcdp->declBus(c+2601,"top riscv_core_i ex_stage_i alu_i operand_a_rev", false,-1, 31,0);
        vcdp->declBus(c+5313,"top riscv_core_i ex_stage_i alu_i operand_a_neg", false,-1, 31,0);
        vcdp->declBus(c+2609,"top riscv_core_i ex_stage_i alu_i operand_a_neg_rev", false,-1, 31,0);
        vcdp->declBus(c+5321,"top riscv_core_i ex_stage_i alu_i operand_b_neg", false,-1, 31,0);
        vcdp->declBus(c+1153,"top riscv_core_i ex_stage_i alu_i div_shift", false,-1, 5,0);
        vcdp->declBit(c+2617,"top riscv_core_i ex_stage_i alu_i div_valid", false,-1);
        vcdp->declBus(c+2625,"top riscv_core_i ex_stage_i alu_i bmask", false,-1, 31,0);
        vcdp->declBit(c+2633,"top riscv_core_i ex_stage_i alu_i adder_op_b_negate", false,-1);
        vcdp->declBus(c+2641,"top riscv_core_i ex_stage_i alu_i adder_op_a", false,-1, 31,0);
        vcdp->declBus(c+2649,"top riscv_core_i ex_stage_i alu_i adder_op_b", false,-1, 31,0);
        vcdp->declQuad(c+2657,"top riscv_core_i ex_stage_i alu_i adder_in_a", false,-1, 35,0);
        vcdp->declQuad(c+2673,"top riscv_core_i ex_stage_i alu_i adder_in_b", false,-1, 35,0);
        vcdp->declBus(c+2689,"top riscv_core_i ex_stage_i alu_i adder_result", false,-1, 31,0);
        vcdp->declQuad(c+2697,"top riscv_core_i ex_stage_i alu_i adder_result_expanded", false,-1, 36,0);
        vcdp->declBus(c+2713,"top riscv_core_i ex_stage_i alu_i adder_round_value", false,-1, 31,0);
        vcdp->declBus(c+2721,"top riscv_core_i ex_stage_i alu_i adder_round_result", false,-1, 31,0);
        vcdp->declBit(c+2729,"top riscv_core_i ex_stage_i alu_i shift_left", false,-1);
        vcdp->declBit(c+2737,"top riscv_core_i ex_stage_i alu_i shift_use_round", false,-1);
        vcdp->declBit(c+2745,"top riscv_core_i ex_stage_i alu_i shift_arithmetic", false,-1);
        vcdp->declBus(c+1161,"top riscv_core_i ex_stage_i alu_i shift_amt_left", false,-1, 31,0);
        vcdp->declBus(c+1169,"top riscv_core_i ex_stage_i alu_i shift_amt", false,-1, 31,0);
        vcdp->declBus(c+1177,"top riscv_core_i ex_stage_i alu_i shift_amt_int", false,-1, 31,0);
        vcdp->declBus(c+5329,"top riscv_core_i ex_stage_i alu_i shift_amt_norm", false,-1, 31,0);
        vcdp->declBus(c+2753,"top riscv_core_i ex_stage_i alu_i shift_op_a", false,-1, 31,0);
        vcdp->declBus(c+1185,"top riscv_core_i ex_stage_i alu_i shift_result", false,-1, 31,0);
        vcdp->declBus(c+1193,"top riscv_core_i ex_stage_i alu_i shift_right_result", false,-1, 31,0);
        vcdp->declBus(c+1201,"top riscv_core_i ex_stage_i alu_i shift_left_result", false,-1, 31,0);
        vcdp->declBus(c+5337,"top riscv_core_i ex_stage_i alu_i clpx_shift_ex", false,-1, 15,0);
        vcdp->declQuad(c+2761,"top riscv_core_i ex_stage_i alu_i shift_op_a_32", false,-1, 63,0);
        vcdp->declBus(c+2777,"top riscv_core_i ex_stage_i alu_i is_equal", false,-1, 3,0);
        vcdp->declBus(c+2785,"top riscv_core_i ex_stage_i alu_i is_greater", false,-1, 3,0);
        vcdp->declBus(c+2793,"top riscv_core_i ex_stage_i alu_i f_is_greater", false,-1, 3,0);
        vcdp->declBus(c+2801,"top riscv_core_i ex_stage_i alu_i cmp_signed", false,-1, 3,0);
        vcdp->declBus(c+2809,"top riscv_core_i ex_stage_i alu_i is_equal_vec", false,-1, 3,0);
        vcdp->declBus(c+2817,"top riscv_core_i ex_stage_i alu_i is_greater_vec", false,-1, 3,0);
        vcdp->declBus(c+5345,"top riscv_core_i ex_stage_i alu_i operand_b_eq", false,-1, 31,0);
        vcdp->declBit(c+2825,"top riscv_core_i ex_stage_i alu_i is_equal_clip", false,-1);
        vcdp->declBus(c+2833,"top riscv_core_i ex_stage_i alu_i cmp_result", false,-1, 3,0);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i alu_i f_is_qnan", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i alu_i f_is_snan", false,-1);
        vcdp->declBus(c+2841,"top riscv_core_i ex_stage_i alu_i f_is_nan", false,-1, 3,0);
        vcdp->declBus(c+2849,"top riscv_core_i ex_stage_i alu_i result_minmax", false,-1, 31,0);
        vcdp->declBus(c+6073,"top riscv_core_i ex_stage_i alu_i fp_canonical_nan", false,-1, 31,0);
        vcdp->declBus(c+2857,"top riscv_core_i ex_stage_i alu_i sel_minmax", false,-1, 3,0);
        vcdp->declBit(c+5353,"top riscv_core_i ex_stage_i alu_i do_min", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i ex_stage_i alu_i minmax_is_fp_special", false,-1);
        vcdp->declBus(c+2865,"top riscv_core_i ex_stage_i alu_i minmax_b", false,-1, 31,0);
        vcdp->declBus(c+6073,"top riscv_core_i ex_stage_i alu_i fclass_result", false,-1, 31,0);
        vcdp->declBus(c+6073,"top riscv_core_i ex_stage_i alu_i f_sign_inject_result", false,-1, 31,0);
        vcdp->declBus(c+2873,"top riscv_core_i ex_stage_i alu_i clip_result", false,-1, 31,0);
        vcdp->declBus(c+2881,"top riscv_core_i ex_stage_i alu_i shuffle_byte_sel", false,-1, 7,0);
        vcdp->declBus(c+2889,"top riscv_core_i ex_stage_i alu_i shuffle_reg_sel", false,-1, 3,0);
        vcdp->declBus(c+2897,"top riscv_core_i ex_stage_i alu_i shuffle_reg1_sel", false,-1, 1,0);
        vcdp->declBus(c+2905,"top riscv_core_i ex_stage_i alu_i shuffle_reg0_sel", false,-1, 1,0);
        vcdp->declBus(c+2913,"top riscv_core_i ex_stage_i alu_i shuffle_through", false,-1, 3,0);
        vcdp->declBus(c+3977,"top riscv_core_i ex_stage_i alu_i shuffle_r1", false,-1, 31,0);
        vcdp->declBus(c+2921,"top riscv_core_i ex_stage_i alu_i shuffle_r0", false,-1, 31,0);
        vcdp->declBus(c+3985,"top riscv_core_i ex_stage_i alu_i shuffle_r1_in", false,-1, 31,0);
        vcdp->declBus(c+2929,"top riscv_core_i ex_stage_i alu_i shuffle_r0_in", false,-1, 31,0);
        vcdp->declBus(c+3993,"top riscv_core_i ex_stage_i alu_i shuffle_result", false,-1, 31,0);
        vcdp->declBus(c+4001,"top riscv_core_i ex_stage_i alu_i pack_result", false,-1, 31,0);
        vcdp->declBus(c+2937,"top riscv_core_i ex_stage_i alu_i ff_input", false,-1, 31,0);
        vcdp->declBus(c+2945,"top riscv_core_i ex_stage_i alu_i cnt_result", false,-1, 5,0);
        vcdp->declBus(c+1513,"top riscv_core_i ex_stage_i alu_i clb_result", false,-1, 5,0);
        vcdp->declBus(c+1521,"top riscv_core_i ex_stage_i alu_i ff1_result", false,-1, 4,0);
        vcdp->declBit(c+1529,"top riscv_core_i ex_stage_i alu_i ff_no_one", false,-1);
        vcdp->declBus(c+1537,"top riscv_core_i ex_stage_i alu_i fl1_result", false,-1, 4,0);
        vcdp->declBus(c+1209,"top riscv_core_i ex_stage_i alu_i bitop_result", false,-1, 5,0);
        vcdp->declBit(c+5361,"top riscv_core_i ex_stage_i alu_i extract_is_signed", false,-1);
        vcdp->declBit(c+1545,"top riscv_core_i ex_stage_i alu_i extract_sign", false,-1);
        vcdp->declBus(c+5369,"top riscv_core_i ex_stage_i alu_i bmask_first", false,-1, 31,0);
        vcdp->declBus(c+2953,"top riscv_core_i ex_stage_i alu_i bmask_inv", false,-1, 31,0);
        vcdp->declBus(c+1785,"top riscv_core_i ex_stage_i alu_i bextins_and", false,-1, 31,0);
        vcdp->declBus(c+1217,"top riscv_core_i ex_stage_i alu_i bextins_result", false,-1, 31,0);
        vcdp->declBus(c+2961,"top riscv_core_i ex_stage_i alu_i bclr_result", false,-1, 31,0);
        vcdp->declBus(c+2969,"top riscv_core_i ex_stage_i alu_i bset_result", false,-1, 31,0);
        vcdp->declBus(c+1225,"top riscv_core_i ex_stage_i alu_i radix_2_rev", false,-1, 31,0);
        vcdp->declBus(c+1233,"top riscv_core_i ex_stage_i alu_i radix_4_rev", false,-1, 31,0);
        vcdp->declBus(c+1241,"top riscv_core_i ex_stage_i alu_i radix_8_rev", false,-1, 31,0);
        vcdp->declBus(c+1553,"top riscv_core_i ex_stage_i alu_i reverse_result", false,-1, 31,0);
        vcdp->declBus(c+5377,"top riscv_core_i ex_stage_i alu_i radix_mux_sel", false,-1, 1,0);
        vcdp->declBus(c+2977,"top riscv_core_i ex_stage_i alu_i result_div", false,-1, 31,0);
        vcdp->declBit(c+1145,"top riscv_core_i ex_stage_i alu_i div_ready", false,-1);
        vcdp->declBit(c+5385,"top riscv_core_i ex_stage_i alu_i int_div div_signed", false,-1);
        vcdp->declBit(c+2985,"top riscv_core_i ex_stage_i alu_i int_div div_op_a_signed", false,-1);
        vcdp->declBit(c+5393,"top riscv_core_i ex_stage_i alu_i int_div div_op_b_signed", false,-1);
        vcdp->declBus(c+1561,"top riscv_core_i ex_stage_i alu_i int_div div_shift_int", false,-1, 5,0);
        vcdp->declBus(c+4161,"top riscv_core_i ex_stage_i alu_i alu_popcnt_i in_i", false,-1, 31,0);
        vcdp->declBus(c+2945,"top riscv_core_i ex_stage_i alu_i alu_popcnt_i result_o", false,-1, 5,0);
        vcdp->declBus(c+2993,"top riscv_core_i ex_stage_i alu_i alu_popcnt_i cnt_l1", false,-1, 31,0);
        vcdp->declBus(c+3001,"top riscv_core_i ex_stage_i alu_i alu_popcnt_i cnt_l2", false,-1, 23,0);
        vcdp->declBus(c+3009,"top riscv_core_i ex_stage_i alu_i alu_popcnt_i cnt_l3", false,-1, 15,0);
        vcdp->declBus(c+3017,"top riscv_core_i ex_stage_i alu_i alu_popcnt_i cnt_l4", false,-1, 9,0);
        vcdp->declBus(c+6089,"top riscv_core_i ex_stage_i alu_i alu_ff_i LEN", false,-1, 31,0);
        vcdp->declBus(c+2937,"top riscv_core_i ex_stage_i alu_i alu_ff_i in_i", false,-1, 31,0);
        vcdp->declBus(c+1521,"top riscv_core_i ex_stage_i alu_i alu_ff_i first_one_o", false,-1, 4,0);
        vcdp->declBit(c+1529,"top riscv_core_i ex_stage_i alu_i alu_ff_i no_ones_o", false,-1);
        vcdp->declBus(c+6441,"top riscv_core_i ex_stage_i alu_i alu_ff_i NUM_LEVELS", false,-1, 31,0);
        vcdp->declArray(c+49,"top riscv_core_i ex_stage_i alu_i alu_ff_i index_lut", false,-1, 159,0);
        vcdp->declBus(c+1569,"top riscv_core_i ex_stage_i alu_i alu_ff_i sel_nodes", false,-1, 31,0);
        vcdp->declArray(c+1577,"top riscv_core_i ex_stage_i alu_i alu_ff_i index_nodes", false,-1, 159,0);
        vcdp->declBus(c+6089,"top riscv_core_i ex_stage_i alu_i int_div div_i C_WIDTH", false,-1, 31,0);
        vcdp->declBus(c+6425,"top riscv_core_i ex_stage_i alu_i int_div div_i C_LOG_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+5913,"top riscv_core_i ex_stage_i alu_i int_div div_i Clk_CI", false,-1);
        vcdp->declBit(c+5921,"top riscv_core_i ex_stage_i alu_i int_div div_i Rst_RBI", false,-1);
        vcdp->declBus(c+4169,"top riscv_core_i ex_stage_i alu_i int_div div_i OpA_DI", false,-1, 31,0);
        vcdp->declBus(c+1201,"top riscv_core_i ex_stage_i alu_i int_div div_i OpB_DI", false,-1, 31,0);
        vcdp->declBus(c+1153,"top riscv_core_i ex_stage_i alu_i int_div div_i OpBShift_DI", false,-1, 5,0);
        vcdp->declBit(c+3025,"top riscv_core_i ex_stage_i alu_i int_div div_i OpBIsZero_SI", false,-1);
        vcdp->declBit(c+2985,"top riscv_core_i ex_stage_i alu_i int_div div_i OpBSign_SI", false,-1);
        vcdp->declBus(c+5401,"top riscv_core_i ex_stage_i alu_i int_div div_i OpCode_SI", false,-1, 1,0);
        vcdp->declBit(c+2617,"top riscv_core_i ex_stage_i alu_i int_div div_i InVld_SI", false,-1);
        vcdp->declBit(c+377,"top riscv_core_i ex_stage_i alu_i int_div div_i OutRdy_SI", false,-1);
        vcdp->declBit(c+1145,"top riscv_core_i ex_stage_i alu_i int_div div_i OutVld_SO", false,-1);
        vcdp->declBus(c+2977,"top riscv_core_i ex_stage_i alu_i int_div div_i Res_DO", false,-1, 31,0);
        vcdp->declBus(c+5409,"top riscv_core_i ex_stage_i alu_i int_div div_i ResReg_DP", false,-1, 31,0);
        vcdp->declBus(c+1617,"top riscv_core_i ex_stage_i alu_i int_div div_i ResReg_DN", false,-1, 31,0);
        vcdp->declBus(c+3033,"top riscv_core_i ex_stage_i alu_i int_div div_i ResReg_DP_rev", false,-1, 31,0);
        vcdp->declBus(c+5417,"top riscv_core_i ex_stage_i alu_i int_div div_i AReg_DP", false,-1, 31,0);
        vcdp->declBus(c+1625,"top riscv_core_i ex_stage_i alu_i int_div div_i AReg_DN", false,-1, 31,0);
        vcdp->declBus(c+5425,"top riscv_core_i ex_stage_i alu_i int_div div_i BReg_DP", false,-1, 31,0);
        vcdp->declBus(c+1633,"top riscv_core_i ex_stage_i alu_i int_div div_i BReg_DN", false,-1, 31,0);
        vcdp->declBit(c+1641,"top riscv_core_i ex_stage_i alu_i int_div div_i RemSel_SN", false,-1);
        vcdp->declBit(c+5433,"top riscv_core_i ex_stage_i alu_i int_div div_i RemSel_SP", false,-1);
        vcdp->declBit(c+1649,"top riscv_core_i ex_stage_i alu_i int_div div_i CompInv_SN", false,-1);
        vcdp->declBit(c+5441,"top riscv_core_i ex_stage_i alu_i int_div div_i CompInv_SP", false,-1);
        vcdp->declBit(c+1657,"top riscv_core_i ex_stage_i alu_i int_div div_i ResInv_SN", false,-1);
        vcdp->declBit(c+5449,"top riscv_core_i ex_stage_i alu_i int_div div_i ResInv_SP", false,-1);
        vcdp->declBus(c+1249,"top riscv_core_i ex_stage_i alu_i int_div div_i AddMux_D", false,-1, 31,0);
        vcdp->declBus(c+1665,"top riscv_core_i ex_stage_i alu_i int_div div_i AddOut_D", false,-1, 31,0);
        vcdp->declBus(c+1257,"top riscv_core_i ex_stage_i alu_i int_div div_i AddTmp_D", false,-1, 31,0);
        vcdp->declBus(c+1673,"top riscv_core_i ex_stage_i alu_i int_div div_i BMux_D", false,-1, 31,0);
        vcdp->declBus(c+3041,"top riscv_core_i ex_stage_i alu_i int_div div_i OutMux_D", false,-1, 31,0);
        vcdp->declBus(c+5457,"top riscv_core_i ex_stage_i alu_i int_div div_i Cnt_DP", false,-1, 5,0);
        vcdp->declBus(c+1681,"top riscv_core_i ex_stage_i alu_i int_div div_i Cnt_DN", false,-1, 5,0);
        vcdp->declBit(c+5465,"top riscv_core_i ex_stage_i alu_i int_div div_i CntZero_S", false,-1);
        vcdp->declBit(c+1265,"top riscv_core_i ex_stage_i alu_i int_div div_i ARegEn_S", false,-1);
        vcdp->declBit(c+1273,"top riscv_core_i ex_stage_i alu_i int_div div_i BRegEn_S", false,-1);
        vcdp->declBit(c+1281,"top riscv_core_i ex_stage_i alu_i int_div div_i ResRegEn_S", false,-1);
        vcdp->declBit(c+3049,"top riscv_core_i ex_stage_i alu_i int_div div_i ABComp_S", false,-1);
        vcdp->declBit(c+1689,"top riscv_core_i ex_stage_i alu_i int_div div_i PmSel_S", false,-1);
        vcdp->declBit(c+1289,"top riscv_core_i ex_stage_i alu_i int_div div_i LoadEn_S", false,-1);
        vcdp->declBus(c+1297,"top riscv_core_i ex_stage_i alu_i int_div div_i State_SN", false,-1, 1,0);
        vcdp->declBus(c+5473,"top riscv_core_i ex_stage_i alu_i int_div div_i State_SP", false,-1, 1,0);
        vcdp->declBus(c+6009,"top riscv_core_i ex_stage_i mult_i SHARED_DSP_MULT", false,-1, 31,0);
        vcdp->declBit(c+5913,"top riscv_core_i ex_stage_i mult_i clk", false,-1);
        vcdp->declBit(c+5921,"top riscv_core_i ex_stage_i mult_i rst_n", false,-1);
        vcdp->declBit(c+4265,"top riscv_core_i ex_stage_i mult_i enable_i", false,-1);
        vcdp->declBus(c+4233,"top riscv_core_i ex_stage_i mult_i operator_i", false,-1, 2,0);
        vcdp->declBit(c+4273,"top riscv_core_i ex_stage_i mult_i short_subword_i", false,-1);
        vcdp->declBus(c+4281,"top riscv_core_i ex_stage_i mult_i short_signed_i", false,-1, 1,0);
        vcdp->declBus(c+4241,"top riscv_core_i ex_stage_i mult_i op_a_i", false,-1, 31,0);
        vcdp->declBus(c+4249,"top riscv_core_i ex_stage_i mult_i op_b_i", false,-1, 31,0);
        vcdp->declBus(c+4257,"top riscv_core_i ex_stage_i mult_i op_c_i", false,-1, 31,0);
        vcdp->declBus(c+4289,"top riscv_core_i ex_stage_i mult_i imm_i", false,-1, 4,0);
        vcdp->declBus(c+4321,"top riscv_core_i ex_stage_i mult_i dot_signed_i", false,-1, 1,0);
        vcdp->declBus(c+4297,"top riscv_core_i ex_stage_i mult_i dot_op_a_i", false,-1, 31,0);
        vcdp->declBus(c+4305,"top riscv_core_i ex_stage_i mult_i dot_op_b_i", false,-1, 31,0);
        vcdp->declBus(c+4313,"top riscv_core_i ex_stage_i mult_i dot_op_c_i", false,-1, 31,0);
        vcdp->declBit(c+4633,"top riscv_core_i ex_stage_i mult_i is_clpx_i", false,-1);
        vcdp->declBus(c+4329,"top riscv_core_i ex_stage_i mult_i clpx_shift_i", false,-1, 1,0);
        vcdp->declBit(c+4337,"top riscv_core_i ex_stage_i mult_i clpx_img_i", false,-1);
        vcdp->declBus(c+1137,"top riscv_core_i ex_stage_i mult_i result_o", false,-1, 31,0);
        vcdp->declBit(c+3673,"top riscv_core_i ex_stage_i mult_i multicycle_o", false,-1);
        vcdp->declBit(c+2593,"top riscv_core_i ex_stage_i mult_i ready_o", false,-1);
        vcdp->declBit(c+377,"top riscv_core_i ex_stage_i mult_i ex_ready_i", false,-1);
        vcdp->declBus(c+1697,"top riscv_core_i ex_stage_i mult_i short_op_a", false,-1, 16,0);
        vcdp->declBus(c+1705,"top riscv_core_i ex_stage_i mult_i short_op_b", false,-1, 16,0);
        vcdp->declQuad(c+3057,"top riscv_core_i ex_stage_i mult_i short_op_c", false,-1, 32,0);
        vcdp->declQuad(c+1713,"top riscv_core_i ex_stage_i mult_i short_mul", false,-1, 33,0);
        vcdp->declQuad(c+1305,"top riscv_core_i ex_stage_i mult_i short_mac", false,-1, 33,0);
        vcdp->declBus(c+5481,"top riscv_core_i ex_stage_i mult_i short_round", false,-1, 31,0);
        vcdp->declBus(c+5489,"top riscv_core_i ex_stage_i mult_i short_round_tmp", false,-1, 31,0);
        vcdp->declQuad(c+1321,"top riscv_core_i ex_stage_i mult_i short_result", false,-1, 33,0);
        vcdp->declBit(c+1729,"top riscv_core_i ex_stage_i mult_i short_mac_msb1", false,-1);
        vcdp->declBit(c+1737,"top riscv_core_i ex_stage_i mult_i short_mac_msb0", false,-1);
        vcdp->declBus(c+3073,"top riscv_core_i ex_stage_i mult_i short_imm", false,-1, 4,0);
        vcdp->declBus(c+3081,"top riscv_core_i ex_stage_i mult_i short_subword", false,-1, 1,0);
        vcdp->declBus(c+3089,"top riscv_core_i ex_stage_i mult_i short_signed", false,-1, 1,0);
        vcdp->declBit(c+3097,"top riscv_core_i ex_stage_i mult_i short_shift_arith", false,-1);
        vcdp->declBus(c+3105,"top riscv_core_i ex_stage_i mult_i mulh_imm", false,-1, 4,0);
        vcdp->declBus(c+3113,"top riscv_core_i ex_stage_i mult_i mulh_subword", false,-1, 1,0);
        vcdp->declBus(c+3121,"top riscv_core_i ex_stage_i mult_i mulh_signed", false,-1, 1,0);
        vcdp->declBit(c+3129,"top riscv_core_i ex_stage_i mult_i mulh_shift_arith", false,-1);
        vcdp->declBit(c+5497,"top riscv_core_i ex_stage_i mult_i mulh_carry_q", false,-1);
        vcdp->declBit(c+3137,"top riscv_core_i ex_stage_i mult_i mulh_active", false,-1);
        vcdp->declBit(c+3145,"top riscv_core_i ex_stage_i mult_i mulh_save", false,-1);
        vcdp->declBit(c+3153,"top riscv_core_i ex_stage_i mult_i mulh_clearcarry", false,-1);
        vcdp->declBit(c+2593,"top riscv_core_i ex_stage_i mult_i mulh_ready", false,-1);
        vcdp->declBus(c+5505,"top riscv_core_i ex_stage_i mult_i mulh_CS", false,-1, 2,0);
        vcdp->declBus(c+1337,"top riscv_core_i ex_stage_i mult_i mulh_NS", false,-1, 2,0);
        vcdp->declBus(c+5513,"top riscv_core_i ex_stage_i mult_i int_op_a_msu", false,-1, 31,0);
        vcdp->declBus(c+5521,"top riscv_core_i ex_stage_i mult_i int_op_b_msu", false,-1, 31,0);
        vcdp->declBus(c+5529,"top riscv_core_i ex_stage_i mult_i int_result", false,-1, 31,0);
        vcdp->declBit(c+5537,"top riscv_core_i ex_stage_i mult_i int_is_msu", false,-1);
        vcdp->declBus(c+3161,"top riscv_core_i ex_stage_i mult_i dot_char_result", false,-1, 31,0);
        vcdp->declQuad(c+3169,"top riscv_core_i ex_stage_i mult_i dot_short_result", false,-1, 32,0);
        vcdp->declBus(c+3185,"top riscv_core_i ex_stage_i mult_i accumulator", false,-1, 31,0);
        vcdp->declBus(c+3193,"top riscv_core_i ex_stage_i mult_i clpx_shift_result", false,-1, 15,0);
        vcdp->declQuad(c+3201,"top riscv_core_i ex_stage_i mult_i genblk1 dot_char_op_a", false,-1, 35,0);
        vcdp->declQuad(c+3217,"top riscv_core_i ex_stage_i mult_i genblk1 dot_char_op_b", false,-1, 35,0);
        vcdp->declArray(c+3233,"top riscv_core_i ex_stage_i mult_i genblk1 dot_char_mul", false,-1, 71,0);
        vcdp->declQuad(c+3257,"top riscv_core_i ex_stage_i mult_i genblk1 dot_short_op_a", false,-1, 33,0);
        vcdp->declQuad(c+3273,"top riscv_core_i ex_stage_i mult_i genblk1 dot_short_op_b", false,-1, 33,0);
        vcdp->declArray(c+3289,"top riscv_core_i ex_stage_i mult_i genblk1 dot_short_mul", false,-1, 67,0);
        vcdp->declBus(c+3313,"top riscv_core_i ex_stage_i mult_i genblk1 dot_short_op_a_1_neg", false,-1, 16,0);
        vcdp->declBus(c+3321,"top riscv_core_i ex_stage_i mult_i genblk1 dot_short_op_b_ext", false,-1, 31,0);
        vcdp->declBit(c+5913,"top riscv_core_i load_store_unit_i clk", false,-1);
        vcdp->declBit(c+5921,"top riscv_core_i load_store_unit_i rst_n", false,-1);
        vcdp->declBit(c+313,"top riscv_core_i load_store_unit_i data_req_o", false,-1);
        vcdp->declBit(c+313,"top riscv_core_i load_store_unit_i data_gnt_i", false,-1);
        vcdp->declBit(c+5849,"top riscv_core_i load_store_unit_i data_rvalid_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i load_store_unit_i data_err_i", false,-1);
        vcdp->declBus(c+3617,"top riscv_core_i load_store_unit_i data_addr_o", false,-1, 31,0);
        vcdp->declBit(c+5873,"top riscv_core_i load_store_unit_i data_we_o", false,-1);
        vcdp->declBus(c+3601,"top riscv_core_i load_store_unit_i data_be_o", false,-1, 3,0);
        vcdp->declBus(c+3609,"top riscv_core_i load_store_unit_i data_wdata_o", false,-1, 31,0);
        vcdp->declBus(c+5857,"top riscv_core_i load_store_unit_i data_rdata_i", false,-1, 31,0);
        vcdp->declBit(c+5873,"top riscv_core_i load_store_unit_i data_we_ex_i", false,-1);
        vcdp->declBus(c+5897,"top riscv_core_i load_store_unit_i data_type_ex_i", false,-1, 1,0);
        vcdp->declBus(c+5889,"top riscv_core_i load_store_unit_i data_wdata_ex_i", false,-1, 31,0);
        vcdp->declBus(c+4497,"top riscv_core_i load_store_unit_i data_reg_offset_ex_i", false,-1, 1,0);
        vcdp->declBus(c+4489,"top riscv_core_i load_store_unit_i data_sign_ext_ex_i", false,-1, 1,0);
        vcdp->declBus(c+3689,"top riscv_core_i load_store_unit_i data_rdata_ex_o", false,-1, 31,0);
        vcdp->declBit(c+4505,"top riscv_core_i load_store_unit_i data_req_ex_i", false,-1);
        vcdp->declBus(c+4161,"top riscv_core_i load_store_unit_i operand_a_ex_i", false,-1, 31,0);
        vcdp->declBus(c+4169,"top riscv_core_i load_store_unit_i operand_b_ex_i", false,-1, 31,0);
        vcdp->declBit(c+4121,"top riscv_core_i load_store_unit_i addr_useincr_ex_i", false,-1);
        vcdp->declBit(c+5905,"top riscv_core_i load_store_unit_i data_misaligned_ex_i", false,-1);
        vcdp->declBit(c+3665,"top riscv_core_i load_store_unit_i data_misaligned_o", false,-1);
        vcdp->declBus(c+4065,"top riscv_core_i load_store_unit_i data_atop_ex_i", false,-1, 5,0);
        vcdp->declBus(c+4065,"top riscv_core_i load_store_unit_i data_atop_o", false,-1, 5,0);
        vcdp->declBit(c+409,"top riscv_core_i load_store_unit_i lsu_ready_ex_o", false,-1);
        vcdp->declBit(c+401,"top riscv_core_i load_store_unit_i lsu_ready_wb_o", false,-1);
        vcdp->declBit(c+393,"top riscv_core_i load_store_unit_i ex_valid_i", false,-1);
        vcdp->declBit(c+1441,"top riscv_core_i load_store_unit_i busy_o", false,-1);
        vcdp->declBus(c+3617,"top riscv_core_i load_store_unit_i data_addr_int", false,-1, 31,0);
        vcdp->declBus(c+5545,"top riscv_core_i load_store_unit_i data_type_q", false,-1, 1,0);
        vcdp->declBus(c+5553,"top riscv_core_i load_store_unit_i rdata_offset_q", false,-1, 1,0);
        vcdp->declBus(c+5561,"top riscv_core_i load_store_unit_i data_sign_ext_q", false,-1, 1,0);
        vcdp->declBit(c+5569,"top riscv_core_i load_store_unit_i data_we_q", false,-1);
        vcdp->declBus(c+4009,"top riscv_core_i load_store_unit_i wdata_offset", false,-1, 1,0);
        vcdp->declBus(c+3601,"top riscv_core_i load_store_unit_i data_be", false,-1, 3,0);
        vcdp->declBus(c+3609,"top riscv_core_i load_store_unit_i data_wdata", false,-1, 31,0);
        vcdp->declBit(c+5905,"top riscv_core_i load_store_unit_i misaligned_st", false,-1);
        vcdp->declBus(c+5577,"top riscv_core_i load_store_unit_i CS", false,-1, 1,0);
        vcdp->declBus(c+1345,"top riscv_core_i load_store_unit_i NS", false,-1, 1,0);
        vcdp->declBus(c+5585,"top riscv_core_i load_store_unit_i rdata_q", false,-1, 31,0);
        vcdp->declBus(c+4017,"top riscv_core_i load_store_unit_i data_rdata_ext", false,-1, 31,0);
        vcdp->declBus(c+5801,"top riscv_core_i load_store_unit_i rdata_w_ext", false,-1, 31,0);
        vcdp->declBus(c+4025,"top riscv_core_i load_store_unit_i rdata_h_ext", false,-1, 31,0);
        vcdp->declBus(c+4033,"top riscv_core_i load_store_unit_i rdata_b_ext", false,-1, 31,0);
        vcdp->declBit(c+6033,"top riscv_core_i load_store_unit_i load_err_o", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i load_store_unit_i store_err_o", false,-1);
        vcdp->declBus(c+6113,"top riscv_core_i cs_registers_i N_HWLP", false,-1, 31,0);
        vcdp->declBus(c+6121,"top riscv_core_i cs_registers_i N_HWLP_BITS", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i cs_registers_i N_EXT_CNT", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i cs_registers_i APU", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i cs_registers_i A_EXTENSION", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i cs_registers_i FPU", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i cs_registers_i PULP_SECURE", false,-1, 31,0);
        vcdp->declBus(c+6009,"top riscv_core_i cs_registers_i USE_PMP", false,-1, 31,0);
        vcdp->declBus(c+6097,"top riscv_core_i cs_registers_i N_PMP_ENTRIES", false,-1, 31,0);
        vcdp->declBit(c+5913,"top riscv_core_i cs_registers_i clk", false,-1);
        vcdp->declBit(c+5921,"top riscv_core_i cs_registers_i rst_n", false,-1);
        vcdp->declBus(c+6041,"top riscv_core_i cs_registers_i core_id_i", false,-1, 3,0);
        vcdp->declBus(c+6049,"top riscv_core_i cs_registers_i cluster_id_i", false,-1, 5,0);
        vcdp->declBus(c+4473,"top riscv_core_i cs_registers_i mtvec_o", false,-1, 23,0);
        vcdp->declBus(c+4481,"top riscv_core_i cs_registers_i mtvecx_o", false,-1, 23,0);
        vcdp->declBus(c+6177,"top riscv_core_i cs_registers_i utvec_o", false,-1, 23,0);
        vcdp->declBus(c+6401,"top riscv_core_i cs_registers_i boot_addr_i", false,-1, 30,0);
        vcdp->declBit(c+4457,"top riscv_core_i cs_registers_i csr_access_i", false,-1);
        vcdp->declBus(c+1881,"top riscv_core_i cs_registers_i csr_addr_i", false,-1, 11,0);
        vcdp->declBus(c+4161,"top riscv_core_i cs_registers_i csr_wdata_i", false,-1, 31,0);
        vcdp->declBus(c+4465,"top riscv_core_i cs_registers_i csr_op_i", false,-1, 1,0);
        vcdp->declBus(c+1889,"top riscv_core_i cs_registers_i csr_rdata_o", false,-1, 31,0);
        vcdp->declBus(c+6153,"top riscv_core_i cs_registers_i frm_o", false,-1, 2,0);
        vcdp->declBus(c+6081,"top riscv_core_i cs_registers_i fprec_o", false,-1, 4,0);
        vcdp->declBus(c+6081,"top riscv_core_i cs_registers_i fflags_i", false,-1, 4,0);
        vcdp->declBit(c+6033,"top riscv_core_i cs_registers_i fflags_we_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i cs_registers_i irq_software_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i cs_registers_i irq_timer_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i cs_registers_i irq_external_i", false,-1);
        vcdp->declBus(c+6065,"top riscv_core_i cs_registers_i irq_fast_i", false,-1, 14,0);
        vcdp->declBit(c+6033,"top riscv_core_i cs_registers_i irq_nmi_i", false,-1);
        vcdp->declBus(c+6073,"top riscv_core_i cs_registers_i irq_fastx_i", false,-1, 31,0);
        vcdp->declBit(c+4521,"top riscv_core_i cs_registers_i m_irq_enable_o", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i cs_registers_i u_irq_enable_o", false,-1);
        vcdp->declBit(c+1953,"top riscv_core_i cs_registers_i irq_pending_o", false,-1);
        vcdp->declBus(c+1961,"top riscv_core_i cs_registers_i irq_id_o", false,-1, 5,0);
        vcdp->declBit(c+1905,"top riscv_core_i cs_registers_i csr_irq_sec_i", false,-1);
        vcdp->declBit(c+6025,"top riscv_core_i cs_registers_i sec_lvl_o", false,-1);
        vcdp->declBus(c+4529,"top riscv_core_i cs_registers_i mepc_o", false,-1, 31,0);
        vcdp->declBus(c+6073,"top riscv_core_i cs_registers_i uepc_o", false,-1, 31,0);
        vcdp->declBit(c+4545,"top riscv_core_i cs_registers_i debug_mode_i", false,-1);
        vcdp->declBus(c+441,"top riscv_core_i cs_registers_i debug_cause_i", false,-1, 2,0);
        vcdp->declBit(c+449,"top riscv_core_i cs_registers_i debug_csr_save_i", false,-1);
        vcdp->declBus(c+4537,"top riscv_core_i cs_registers_i depc_o", false,-1, 31,0);
        vcdp->declBit(c+4553,"top riscv_core_i cs_registers_i debug_single_step_o", false,-1);
        vcdp->declBit(c+4561,"top riscv_core_i cs_registers_i debug_ebreakm_o", false,-1);
        vcdp->declBit(c+4569,"top riscv_core_i cs_registers_i debug_ebreaku_o", false,-1);
        vcdp->declArray(c+6233,"top riscv_core_i cs_registers_i pmp_addr_o", false,-1, 511,0);
        vcdp->declArray(c+6361,"top riscv_core_i cs_registers_i pmp_cfg_o", false,-1, 127,0);
        vcdp->declBus(c+6185,"top riscv_core_i cs_registers_i priv_lvl_o", false,-1, 1,0);
        vcdp->declBus(c+3625,"top riscv_core_i cs_registers_i pc_if_i", false,-1, 31,0);
        vcdp->declBus(c+5881,"top riscv_core_i cs_registers_i pc_id_i", false,-1, 31,0);
        vcdp->declBus(c+4137,"top riscv_core_i cs_registers_i pc_ex_i", false,-1, 31,0);
        vcdp->declBit(c+3697,"top riscv_core_i cs_registers_i csr_save_if_i", false,-1);
        vcdp->declBit(c+425,"top riscv_core_i cs_registers_i csr_save_id_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i cs_registers_i csr_save_ex_i", false,-1);
        vcdp->declBit(c+3705,"top riscv_core_i cs_registers_i csr_restore_mret_i", false,-1);
        vcdp->declBit(c+3713,"top riscv_core_i cs_registers_i csr_restore_uret_i", false,-1);
        vcdp->declBit(c+3721,"top riscv_core_i cs_registers_i csr_restore_dret_i", false,-1);
        vcdp->declBus(c+433,"top riscv_core_i cs_registers_i csr_cause_i", false,-1, 6,0);
        vcdp->declBit(c+417,"top riscv_core_i cs_registers_i csr_save_cause_i", false,-1);
        vcdp->declQuad(c+4577,"top riscv_core_i cs_registers_i hwlp_start_i", false,-1, 63,0);
        vcdp->declQuad(c+4593,"top riscv_core_i cs_registers_i hwlp_end_i", false,-1, 63,0);
        vcdp->declQuad(c+4609,"top riscv_core_i cs_registers_i hwlp_cnt_i", false,-1, 63,0);
        vcdp->declBus(c+1929,"top riscv_core_i cs_registers_i hwlp_data_o", false,-1, 31,0);
        vcdp->declBus(c+1913,"top riscv_core_i cs_registers_i hwlp_regid_o", false,-1, 0,0);
        vcdp->declBus(c+1921,"top riscv_core_i cs_registers_i hwlp_we_o", false,-1, 2,0);
        vcdp->declBit(c+385,"top riscv_core_i cs_registers_i id_valid_i", false,-1);
        vcdp->declBit(c+4097,"top riscv_core_i cs_registers_i is_compressed_i", false,-1);
        vcdp->declBit(c+3657,"top riscv_core_i cs_registers_i is_decoding_i", false,-1);
        vcdp->declBit(c+457,"top riscv_core_i cs_registers_i imiss_i", false,-1);
        vcdp->declBit(c+337,"top riscv_core_i cs_registers_i pc_set_i", false,-1);
        vcdp->declBit(c+465,"top riscv_core_i cs_registers_i jump_i", false,-1);
        vcdp->declBit(c+4129,"top riscv_core_i cs_registers_i branch_i", false,-1);
        vcdp->declBit(c+1849,"top riscv_core_i cs_registers_i branch_taken_i", false,-1);
        vcdp->declBit(c+473,"top riscv_core_i cs_registers_i ld_stall_i", false,-1);
        vcdp->declBit(c+1937,"top riscv_core_i cs_registers_i jr_stall_i", false,-1);
        vcdp->declBit(c+3729,"top riscv_core_i cs_registers_i pipeline_stall_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i cs_registers_i apu_typeconflict_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i cs_registers_i apu_contention_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i cs_registers_i apu_dep_i", false,-1);
        vcdp->declBit(c+6033,"top riscv_core_i cs_registers_i apu_wb_i", false,-1);
        vcdp->declBit(c+1809,"top riscv_core_i cs_registers_i mem_load_i", false,-1);
        vcdp->declBit(c+1817,"top riscv_core_i cs_registers_i mem_store_i", false,-1);
        vcdp->declBus(c+6105,"top riscv_core_i cs_registers_i ext_counters_i", false,-1, -1,0);
        vcdp->declBus(c+6009,"top riscv_core_i cs_registers_i N_APU_CNT", false,-1, 31,0);
        vcdp->declBus(c+6849,"top riscv_core_i cs_registers_i N_PERF_COUNTERS", false,-1, 31,0);
        vcdp->declBus(c+6849,"top riscv_core_i cs_registers_i PERF_EXT_ID", false,-1, 31,0);
        vcdp->declBus(c+6849,"top riscv_core_i cs_registers_i PERF_APU_ID", false,-1, 31,0);
        vcdp->declBus(c+6857,"top riscv_core_i cs_registers_i MTVEC_MODE", false,-1, 1,0);
        vcdp->declBus(c+6857,"top riscv_core_i cs_registers_i MTVECX_MODE", false,-1, 1,0);
        vcdp->declBus(c+6097,"top riscv_core_i cs_registers_i MAX_N_PMP_ENTRIES", false,-1, 31,0);
        vcdp->declBus(c+6409,"top riscv_core_i cs_registers_i MAX_N_PMP_CFG", false,-1, 31,0);
        vcdp->declBus(c+6409,"top riscv_core_i cs_registers_i N_PMP_CFG", false,-1, 31,0);
        vcdp->declBus(c+6849,"top riscv_core_i cs_registers_i N_PERF_REGS", false,-1, 31,0);
        vcdp->declBus(c+6857,"top riscv_core_i cs_registers_i MXL", false,-1, 1,0);
        vcdp->declBus(c+6865,"top riscv_core_i cs_registers_i MISA_VALUE", false,-1, 31,0);
        vcdp->declBus(c+1929,"top riscv_core_i cs_registers_i csr_wdata_int", false,-1, 31,0);
        vcdp->declBus(c+3329,"top riscv_core_i cs_registers_i csr_rdata_int", false,-1, 31,0);
        vcdp->declBit(c+3337,"top riscv_core_i cs_registers_i csr_we_int", false,-1);
        vcdp->declBus(c+6873,"top riscv_core_i cs_registers_i frm_q", false,-1, 2,0);
        vcdp->declBus(c+3345,"top riscv_core_i cs_registers_i frm_n", false,-1, 2,0);
        vcdp->declBus(c+6881,"top riscv_core_i cs_registers_i fflags_q", false,-1, 4,0);
        vcdp->declBus(c+3353,"top riscv_core_i cs_registers_i fflags_n", false,-1, 4,0);
        vcdp->declBus(c+6889,"top riscv_core_i cs_registers_i fprec_q", false,-1, 4,0);
        vcdp->declBus(c+3361,"top riscv_core_i cs_registers_i fprec_n", false,-1, 4,0);
        vcdp->declBus(c+4529,"top riscv_core_i cs_registers_i mepc_q", false,-1, 31,0);
        vcdp->declBus(c+1353,"top riscv_core_i cs_registers_i mepc_n", false,-1, 31,0);
        vcdp->declBus(c+6073,"top riscv_core_i cs_registers_i uepc_q", false,-1, 31,0);
        vcdp->declBus(c+6897,"top riscv_core_i cs_registers_i uepc_n", false,-1, 31,0);
        vcdp->declBus(c+5593,"top riscv_core_i cs_registers_i dcsr_q", false,-1, 31,0);
        vcdp->declBus(c+1361,"top riscv_core_i cs_registers_i dcsr_n", false,-1, 31,0);
        vcdp->declBus(c+4537,"top riscv_core_i cs_registers_i depc_q", false,-1, 31,0);
        vcdp->declBus(c+1369,"top riscv_core_i cs_registers_i depc_n", false,-1, 31,0);
        vcdp->declBus(c+5601,"top riscv_core_i cs_registers_i dscratch0_q", false,-1, 31,0);
        vcdp->declBus(c+3369,"top riscv_core_i cs_registers_i dscratch0_n", false,-1, 31,0);
        vcdp->declBus(c+5609,"top riscv_core_i cs_registers_i dscratch1_q", false,-1, 31,0);
        vcdp->declBus(c+3377,"top riscv_core_i cs_registers_i dscratch1_n", false,-1, 31,0);
        vcdp->declBus(c+5617,"top riscv_core_i cs_registers_i mscratch_q", false,-1, 31,0);
        vcdp->declBus(c+3385,"top riscv_core_i cs_registers_i mscratch_n", false,-1, 31,0);
        vcdp->declBus(c+1377,"top riscv_core_i cs_registers_i exception_pc", false,-1, 31,0);
        vcdp->declBus(c+5625,"top riscv_core_i cs_registers_i mstatus_q", false,-1, 6,0);
        vcdp->declBus(c+1385,"top riscv_core_i cs_registers_i mstatus_n", false,-1, 6,0);
        vcdp->declBus(c+5633,"top riscv_core_i cs_registers_i mcause_q", false,-1, 6,0);
        vcdp->declBus(c+1393,"top riscv_core_i cs_registers_i mcause_n", false,-1, 6,0);
        vcdp->declBus(c+6905,"top riscv_core_i cs_registers_i ucause_q", false,-1, 6,0);
        vcdp->declBus(c+6913,"top riscv_core_i cs_registers_i ucause_n", false,-1, 6,0);
        vcdp->declBus(c+3393,"top riscv_core_i cs_registers_i mtvec_n", false,-1, 23,0);
        vcdp->declBus(c+4473,"top riscv_core_i cs_registers_i mtvec_q", false,-1, 23,0);
        vcdp->declBus(c+3401,"top riscv_core_i cs_registers_i mtvecx_n", false,-1, 23,0);
        vcdp->declBus(c+4481,"top riscv_core_i cs_registers_i mtvecx_q", false,-1, 23,0);
        vcdp->declBus(c+6921,"top riscv_core_i cs_registers_i utvec_n", false,-1, 23,0);
        vcdp->declBus(c+6177,"top riscv_core_i cs_registers_i utvec_q", false,-1, 23,0);
        vcdp->declBus(c+89,"top riscv_core_i cs_registers_i mip", false,-1, 18,0);
        vcdp->declBus(c+6073,"top riscv_core_i cs_registers_i mipx", false,-1, 31,0);
        vcdp->declBus(c+5641,"top riscv_core_i cs_registers_i mie_q", false,-1, 18,0);
        vcdp->declBus(c+3409,"top riscv_core_i cs_registers_i mie_n", false,-1, 18,0);
        vcdp->declBus(c+5649,"top riscv_core_i cs_registers_i miex_q", false,-1, 31,0);
        vcdp->declBus(c+3417,"top riscv_core_i cs_registers_i miex_n", false,-1, 31,0);
        vcdp->declBus(c+3425,"top riscv_core_i cs_registers_i menip", false,-1, 18,0);
        vcdp->declBus(c+6073,"top riscv_core_i cs_registers_i menipx", false,-1, 31,0);
        vcdp->declBit(c+1401,"top riscv_core_i cs_registers_i is_irq", false,-1);
        vcdp->declBus(c+1409,"top riscv_core_i cs_registers_i priv_lvl_n", false,-1, 1,0);
        vcdp->declBus(c+6929,"top riscv_core_i cs_registers_i priv_lvl_q", false,-1, 1,0);
        vcdp->declBus(c+6937,"top riscv_core_i cs_registers_i priv_lvl_reg_q", false,-1, 1,0);
        vcdp->declArray(c+6945,"top riscv_core_i cs_registers_i pmp_reg_q", false,-1, 767,0);
        vcdp->declArray(c+97,"top riscv_core_i cs_registers_i pmp_reg_n", false,-1, 767,0);
        vcdp->declBus(c+7137,"top riscv_core_i cs_registers_i pmpaddr_we", false,-1, 15,0);
        vcdp->declBus(c+7137,"top riscv_core_i cs_registers_i pmpcfg_we", false,-1, 15,0);
        vcdp->declBit(c+5657,"top riscv_core_i cs_registers_i id_valid_q", false,-1);
        vcdp->declBus(c+1793,"top riscv_core_i cs_registers_i PCCR_in", false,-1, 11,0);
        vcdp->declBus(c+1417,"top riscv_core_i cs_registers_i PCCR_inc", false,-1, 11,0);
        vcdp->declBus(c+5665,"top riscv_core_i cs_registers_i PCCR_inc_q", false,-1, 11,0);
        vcdp->declArray(c+5673,"top riscv_core_i cs_registers_i PCCR_q", false,-1, 383,0);
        vcdp->declArray(c+3433,"top riscv_core_i cs_registers_i PCCR_n", false,-1, 383,0);
        vcdp->declBus(c+3529,"top riscv_core_i cs_registers_i PCMR_n", false,-1, 1,0);
        vcdp->declBus(c+5769,"top riscv_core_i cs_registers_i PCMR_q", false,-1, 1,0);
        vcdp->declBus(c+3537,"top riscv_core_i cs_registers_i PCER_n", false,-1, 11,0);
        vcdp->declBus(c+5777,"top riscv_core_i cs_registers_i PCER_q", false,-1, 11,0);
        vcdp->declBus(c+3545,"top riscv_core_i cs_registers_i perf_rdata", false,-1, 31,0);
        vcdp->declBus(c+3553,"top riscv_core_i cs_registers_i pccr_index", false,-1, 4,0);
        vcdp->declBit(c+3561,"top riscv_core_i cs_registers_i pccr_all_sel", false,-1);
        vcdp->declBit(c+3569,"top riscv_core_i cs_registers_i is_pccr", false,-1);
        vcdp->declBit(c+3577,"top riscv_core_i cs_registers_i is_pcer", false,-1);
        vcdp->declBit(c+3585,"top riscv_core_i cs_registers_i is_pcmr", false,-1);
        vcdp->declBus(c+289,"top riscv_core_i cs_registers_i irq_req", false,-1, 18,0);
        vcdp->declBus(c+6073,"top riscv_core_i cs_registers_i irq_reqx", false,-1, 31,0);
        vcdp->declBus(c+7145,"top riscv_core_i cs_registers_i unnamedblk1 i", false,-1, 31,0);
        vcdp->declBus(c+5785,"top riscv_core_i cs_registers_i unnamedblk3 i", false,-1, 31,0);
        vcdp->declBus(c+5793,"top riscv_core_i cs_registers_i unnamedblk2 i", false,-1, 31,0);
        vcdp->declBus(c+7153,"fpnew_pkg NUM_FP_FORMATS", false,-1, 31,0);
        vcdp->declBus(c+7161,"fpnew_pkg FP_FORMAT_BITS", false,-1, 31,0);
        vcdp->declArray(c+7169,"fpnew_pkg FP_ENCODINGS", false,-1, 319,0);
        vcdp->declBus(c+7249,"fpnew_pkg CPK_FORMATS", false,-1, 0,4);
        vcdp->declBus(c+7257,"fpnew_pkg NUM_INT_FORMATS", false,-1, 31,0);
        vcdp->declBus(c+7265,"fpnew_pkg INT_FORMAT_BITS", false,-1, 31,0);
        vcdp->declBus(c+7257,"fpnew_pkg NUM_OPGROUPS", false,-1, 31,0);
        vcdp->declBus(c+7257,"fpnew_pkg OP_BITS", false,-1, 31,0);
        vcdp->declQuad(c+7273,"fpnew_pkg RV64D", false,-1, 42,0);
        vcdp->declQuad(c+7289,"fpnew_pkg RV32D", false,-1, 42,0);
        vcdp->declQuad(c+7305,"fpnew_pkg RV32F", false,-1, 42,0);
        vcdp->declQuad(c+7321,"fpnew_pkg RV64D_Xsflt", false,-1, 42,0);
        vcdp->declQuad(c+7337,"fpnew_pkg RV32F_Xsflt", false,-1, 42,0);
        vcdp->declQuad(c+7353,"fpnew_pkg RV32F_Xf16alt_Xfvec", false,-1, 42,0);
        vcdp->declArray(c+7369,"fpnew_pkg DEFAULT_NOREGS", false,-1, 681,0);
        vcdp->declArray(c+7545,"fpnew_pkg DEFAULT_SNITCH", false,-1, 681,0);
        vcdp->declBit(c+6025,"fpnew_pkg DONT_CARE", false,-1);
        vcdp->declBus(c+7721,"top ram_i ADDR_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+5913,"top ram_i clk", false,-1);
        vcdp->declBit(c+297,"top ram_i instr_req_i", false,-1);
        vcdp->declBus(c+1425,"top ram_i instr_addr_i", false,-1, 19,0);
        vcdp->declArray(c+5817,"top ram_i instr_rdata_o", false,-1, 127,0);
        vcdp->declBit(c+5809,"top ram_i instr_rvalid_o", false,-1);
        vcdp->declBit(c+297,"top ram_i instr_gnt_o", false,-1);
        vcdp->declBit(c+313,"top ram_i data_req_i", false,-1);
        vcdp->declBus(c+4041,"top ram_i data_addr_i", false,-1, 19,0);
        vcdp->declBit(c+5873,"top ram_i data_we_i", false,-1);
        vcdp->declBus(c+3601,"top ram_i data_be_i", false,-1, 3,0);
        vcdp->declBus(c+3609,"top ram_i data_wdata_i", false,-1, 31,0);
        vcdp->declBus(c+5857,"top ram_i data_rdata_o", false,-1, 31,0);
        vcdp->declBit(c+5849,"top ram_i data_rvalid_o", false,-1);
        vcdp->declBit(c+313,"top ram_i data_gnt_o", false,-1);
        vcdp->declBus(c+6009,"apu_core_package SHARED_INT_MULT", false,-1, 31,0);
        vcdp->declBus(c+6009,"apu_core_package WAPUTYPE", false,-1, 31,0);
        vcdp->declBus(c+6417,"apu_core_package APU_NARGS_CPU", false,-1, 31,0);
        vcdp->declBus(c+6425,"apu_core_package APU_WOP_CPU", false,-1, 31,0);
        vcdp->declBus(c+6433,"apu_core_package APU_NDSFLAGS_CPU", false,-1, 31,0);
        vcdp->declBus(c+6441,"apu_core_package APU_NUSFLAGS_CPU", false,-1, 31,0);
        vcdp->declBus(c+6113,"apu_core_package APU_FLAGS_FP", false,-1, 31,0);
        vcdp->declBus(c+6417,"apu_core_package APU_FLAGS_FPNEW", false,-1, 31,0);
        vcdp->declBus(c+6121,"apu_core_package PIPE_REG_DSP_MULT", false,-1, 31,0);
        vcdp->declBus(c+6009,"apu_core_package APU_FLAGS_DSP_MULT", false,-1, 31,0);
        vcdp->declBus(c+6121,"apu_core_package APU_FLAGS_INT_MULT", false,-1, 31,0);
        vcdp->declBus(c+6121,"apu_core_package PIPE_REG_ADDSUB", false,-1, 31,0);
        vcdp->declBus(c+6121,"apu_core_package PIPE_REG_MULT", false,-1, 31,0);
        vcdp->declBus(c+6121,"apu_core_package PIPE_REG_CAST", false,-1, 31,0);
        vcdp->declBus(c+6113,"apu_core_package PIPE_REG_MAC", false,-1, 31,0);
        vcdp->declBus(c+6409,"apu_core_package PIPE_REG_DIV", false,-1, 31,0);
        vcdp->declBus(c+6441,"apu_core_package PIPE_REG_SQRT", false,-1, 31,0);
        vcdp->declBus(c+7729,"riscv_defines OPCODE_SYSTEM", false,-1, 6,0);
        vcdp->declBus(c+7737,"riscv_defines OPCODE_FENCE", false,-1, 6,0);
        vcdp->declBus(c+7745,"riscv_defines OPCODE_OP", false,-1, 6,0);
        vcdp->declBus(c+7753,"riscv_defines OPCODE_OPIMM", false,-1, 6,0);
        vcdp->declBus(c+7761,"riscv_defines OPCODE_STORE", false,-1, 6,0);
        vcdp->declBus(c+7769,"riscv_defines OPCODE_LOAD", false,-1, 6,0);
        vcdp->declBus(c+7777,"riscv_defines OPCODE_BRANCH", false,-1, 6,0);
        vcdp->declBus(c+7785,"riscv_defines OPCODE_JALR", false,-1, 6,0);
        vcdp->declBus(c+7793,"riscv_defines OPCODE_JAL", false,-1, 6,0);
        vcdp->declBus(c+7801,"riscv_defines OPCODE_AUIPC", false,-1, 6,0);
        vcdp->declBus(c+7809,"riscv_defines OPCODE_LUI", false,-1, 6,0);
        vcdp->declBus(c+7817,"riscv_defines OPCODE_OP_FP", false,-1, 6,0);
        vcdp->declBus(c+7825,"riscv_defines OPCODE_OP_FMADD", false,-1, 6,0);
        vcdp->declBus(c+7833,"riscv_defines OPCODE_OP_FNMADD", false,-1, 6,0);
        vcdp->declBus(c+7841,"riscv_defines OPCODE_OP_FMSUB", false,-1, 6,0);
        vcdp->declBus(c+7849,"riscv_defines OPCODE_OP_FNMSUB", false,-1, 6,0);
        vcdp->declBus(c+7857,"riscv_defines OPCODE_STORE_FP", false,-1, 6,0);
        vcdp->declBus(c+7865,"riscv_defines OPCODE_LOAD_FP", false,-1, 6,0);
        vcdp->declBus(c+7873,"riscv_defines OPCODE_AMO", false,-1, 6,0);
        vcdp->declBus(c+7881,"riscv_defines OPCODE_LOAD_POST", false,-1, 6,0);
        vcdp->declBus(c+7889,"riscv_defines OPCODE_STORE_POST", false,-1, 6,0);
        vcdp->declBus(c+7897,"riscv_defines OPCODE_PULP_OP", false,-1, 6,0);
        vcdp->declBus(c+7905,"riscv_defines OPCODE_VECOP", false,-1, 6,0);
        vcdp->declBus(c+7913,"riscv_defines OPCODE_HWLOOP", false,-1, 6,0);
        vcdp->declBus(c+7921,"riscv_defines REGC_S1", false,-1, 1,0);
        vcdp->declBus(c+6057,"riscv_defines REGC_S4", false,-1, 1,0);
        vcdp->declBus(c+6857,"riscv_defines REGC_RD", false,-1, 1,0);
        vcdp->declBus(c+7929,"riscv_defines REGC_ZERO", false,-1, 1,0);
        vcdp->declBus(c+7937,"riscv_defines OPCODE_STORE_ACTIVE_LOGIC", false,-1, 6,0);
        vcdp->declBus(c+7945,"riscv_defines OPCODE_LOAD_MASK", false,-1, 6,0);
        vcdp->declBus(c+6153,"riscv_defines FUNCT_NONE", false,-1, 2,0);
        vcdp->declBus(c+7953,"riscv_defines FUNCT_XOR", false,-1, 2,0);
        vcdp->declBus(c+7961,"riscv_defines FUNCT_AND", false,-1, 2,0);
        vcdp->declBus(c+7969,"riscv_defines FUNCT_OR", false,-1, 2,0);
        vcdp->declBus(c+7977,"riscv_defines FUNCT_MIN", false,-1, 2,0);
        vcdp->declBus(c+7985,"riscv_defines FUNCT_MAX", false,-1, 2,0);
        vcdp->declBus(c+7993,"riscv_defines ALU_OP_WIDTH", false,-1, 31,0);
        vcdp->declBus(c+8001,"riscv_defines ALU_ADD", false,-1, 6,0);
        vcdp->declBus(c+8009,"riscv_defines ALU_SUB", false,-1, 6,0);
        vcdp->declBus(c+8017,"riscv_defines ALU_ADDU", false,-1, 6,0);
        vcdp->declBus(c+7945,"riscv_defines ALU_SUBU", false,-1, 6,0);
        vcdp->declBus(c+8025,"riscv_defines ALU_ADDR", false,-1, 6,0);
        vcdp->declBus(c+8033,"riscv_defines ALU_SUBR", false,-1, 6,0);
        vcdp->declBus(c+8041,"riscv_defines ALU_ADDUR", false,-1, 6,0);
        vcdp->declBus(c+8049,"riscv_defines ALU_SUBUR", false,-1, 6,0);
        vcdp->declBus(c+7873,"riscv_defines ALU_XOR", false,-1, 6,0);
        vcdp->declBus(c+8057,"riscv_defines ALU_OR", false,-1, 6,0);
        vcdp->declBus(c+8065,"riscv_defines ALU_AND", false,-1, 6,0);
        vcdp->declBus(c+8073,"riscv_defines ALU_SRA", false,-1, 6,0);
        vcdp->declBus(c+8081,"riscv_defines ALU_SRL", false,-1, 6,0);
        vcdp->declBus(c+8089,"riscv_defines ALU_ROR", false,-1, 6,0);
        vcdp->declBus(c+7857,"riscv_defines ALU_SLL", false,-1, 6,0);
        vcdp->declBus(c+8097,"riscv_defines ALU_BEXT", false,-1, 6,0);
        vcdp->declBus(c+8105,"riscv_defines ALU_BEXTU", false,-1, 6,0);
        vcdp->declBus(c+8113,"riscv_defines ALU_BINS", false,-1, 6,0);
        vcdp->declBus(c+7889,"riscv_defines ALU_BCLR", false,-1, 6,0);
        vcdp->declBus(c+8121,"riscv_defines ALU_BSET", false,-1, 6,0);
        vcdp->declBus(c+8129,"riscv_defines ALU_BREV", false,-1, 6,0);
        vcdp->declBus(c+8137,"riscv_defines ALU_FF1", false,-1, 6,0);
        vcdp->declBus(c+7809,"riscv_defines ALU_FL1", false,-1, 6,0);
        vcdp->declBus(c+8145,"riscv_defines ALU_CNT", false,-1, 6,0);
        vcdp->declBus(c+8153,"riscv_defines ALU_CLB", false,-1, 6,0);
        vcdp->declBus(c+8161,"riscv_defines ALU_EXTS", false,-1, 6,0);
        vcdp->declBus(c+8169,"riscv_defines ALU_EXT", false,-1, 6,0);
        vcdp->declBus(c+6905,"riscv_defines ALU_LTS", false,-1, 6,0);
        vcdp->declBus(c+8177,"riscv_defines ALU_LTU", false,-1, 6,0);
        vcdp->declBus(c+8185,"riscv_defines ALU_LES", false,-1, 6,0);
        vcdp->declBus(c+8193,"riscv_defines ALU_LEU", false,-1, 6,0);
        vcdp->declBus(c+8201,"riscv_defines ALU_GTS", false,-1, 6,0);
        vcdp->declBus(c+8209,"riscv_defines ALU_GTU", false,-1, 6,0);
        vcdp->declBus(c+8217,"riscv_defines ALU_GES", false,-1, 6,0);
        vcdp->declBus(c+7881,"riscv_defines ALU_GEU", false,-1, 6,0);
        vcdp->declBus(c+8225,"riscv_defines ALU_EQ", false,-1, 6,0);
        vcdp->declBus(c+8233,"riscv_defines ALU_NE", false,-1, 6,0);
        vcdp->declBus(c+8241,"riscv_defines ALU_SLTS", false,-1, 6,0);
        vcdp->declBus(c+7769,"riscv_defines ALU_SLTU", false,-1, 6,0);
        vcdp->declBus(c+8249,"riscv_defines ALU_SLETS", false,-1, 6,0);
        vcdp->declBus(c+7865,"riscv_defines ALU_SLETU", false,-1, 6,0);
        vcdp->declBus(c+8257,"riscv_defines ALU_ABS", false,-1, 6,0);
        vcdp->declBus(c+8265,"riscv_defines ALU_CLIP", false,-1, 6,0);
        vcdp->declBus(c+7801,"riscv_defines ALU_CLIPU", false,-1, 6,0);
        vcdp->declBus(c+8273,"riscv_defines ALU_INS", false,-1, 6,0);
        vcdp->declBus(c+8281,"riscv_defines ALU_MIN", false,-1, 6,0);
        vcdp->declBus(c+8289,"riscv_defines ALU_MINU", false,-1, 6,0);
        vcdp->declBus(c+8297,"riscv_defines ALU_MAX", false,-1, 6,0);
        vcdp->declBus(c+7753,"riscv_defines ALU_MAXU", false,-1, 6,0);
        vcdp->declBus(c+8305,"riscv_defines ALU_DIVU", false,-1, 6,0);
        vcdp->declBus(c+8313,"riscv_defines ALU_DIV", false,-1, 6,0);
        vcdp->declBus(c+8321,"riscv_defines ALU_REMU", false,-1, 6,0);
        vcdp->declBus(c+7745,"riscv_defines ALU_REM", false,-1, 6,0);
        vcdp->declBus(c+8329,"riscv_defines ALU_SHUF", false,-1, 6,0);
        vcdp->declBus(c+7937,"riscv_defines ALU_SHUF2", false,-1, 6,0);
        vcdp->declBus(c+8337,"riscv_defines ALU_PCKLO", false,-1, 6,0);
        vcdp->declBus(c+8345,"riscv_defines ALU_PCKHI", false,-1, 6,0);
        vcdp->declBus(c+8353,"riscv_defines ALU_FKEEP", false,-1, 6,0);
        vcdp->declBus(c+8361,"riscv_defines ALU_FSGNJ", false,-1, 6,0);
        vcdp->declBus(c+8369,"riscv_defines ALU_FSGNJN", false,-1, 6,0);
        vcdp->declBus(c+8377,"riscv_defines ALU_FSGNJX", false,-1, 6,0);
        vcdp->declBus(c+7825,"riscv_defines ALU_FEQ", false,-1, 6,0);
        vcdp->declBus(c+8385,"riscv_defines ALU_FLT", false,-1, 6,0);
        vcdp->declBus(c+8393,"riscv_defines ALU_FLE", false,-1, 6,0);
        vcdp->declBus(c+8401,"riscv_defines ALU_FMAX", false,-1, 6,0);
        vcdp->declBus(c+7841,"riscv_defines ALU_FMIN", false,-1, 6,0);
        vcdp->declBus(c+8409,"riscv_defines ALU_FCLASS", false,-1, 6,0);
        vcdp->declBus(c+6153,"riscv_defines MUL_MAC32", false,-1, 2,0);
        vcdp->declBus(c+7953,"riscv_defines MUL_MSU32", false,-1, 2,0);
        vcdp->declBus(c+7961,"riscv_defines MUL_I", false,-1, 2,0);
        vcdp->declBus(c+7969,"riscv_defines MUL_IR", false,-1, 2,0);
        vcdp->declBus(c+8417,"riscv_defines MUL_DOT8", false,-1, 2,0);
        vcdp->declBus(c+7977,"riscv_defines MUL_DOT16", false,-1, 2,0);
        vcdp->declBus(c+7985,"riscv_defines MUL_H", false,-1, 2,0);
        vcdp->declBus(c+6057,"riscv_defines VEC_MODE32", false,-1, 1,0);
        vcdp->declBus(c+7921,"riscv_defines VEC_MODE16", false,-1, 1,0);
        vcdp->declBus(c+7929,"riscv_defines VEC_MODE8", false,-1, 1,0);
        vcdp->declBus(c+6057,"riscv_defines CSR_OP_NONE", false,-1, 1,0);
        vcdp->declBus(c+6857,"riscv_defines CSR_OP_WRITE", false,-1, 1,0);
        vcdp->declBus(c+7921,"riscv_defines CSR_OP_SET", false,-1, 1,0);
        vcdp->declBus(c+7929,"riscv_defines CSR_OP_CLEAR", false,-1, 1,0);
        vcdp->declBus(c+7161,"riscv_defines CSR_MSIX_BIT", false,-1, 31,0);
        vcdp->declBus(c+8425,"riscv_defines CSR_MTIX_BIT", false,-1, 31,0);
        vcdp->declBus(c+8433,"riscv_defines CSR_MEIX_BIT", false,-1, 31,0);
        vcdp->declBus(c+8441,"riscv_defines CSR_MFIX_BIT_LOW", false,-1, 31,0);
        vcdp->declBus(c+8449,"riscv_defines CSR_MFIX_BIT_HIGH", false,-1, 31,0);
        vcdp->declBus(c+8457,"riscv_defines CSR_NMIX_BIT", false,-1, 31,0);
        vcdp->declBus(c+8465,"riscv_defines SP_DVR0", false,-1, 15,0);
        vcdp->declBus(c+8473,"riscv_defines SP_DCR0", false,-1, 15,0);
        vcdp->declBus(c+8481,"riscv_defines SP_DMR1", false,-1, 15,0);
        vcdp->declBus(c+8489,"riscv_defines SP_DMR2", false,-1, 15,0);
        vcdp->declBus(c+8497,"riscv_defines SP_DVR_MSB", false,-1, 7,0);
        vcdp->declBus(c+8505,"riscv_defines SP_DCR_MSB", false,-1, 7,0);
        vcdp->declBus(c+8513,"riscv_defines SP_DMR_MSB", false,-1, 7,0);
        vcdp->declBus(c+8521,"riscv_defines SP_DSR_MSB", false,-1, 7,0);
        vcdp->declBus(c+6057,"riscv_defines SEL_REGFILE", false,-1, 1,0);
        vcdp->declBus(c+6857,"riscv_defines SEL_FW_EX", false,-1, 1,0);
        vcdp->declBus(c+7921,"riscv_defines SEL_FW_WB", false,-1, 1,0);
        vcdp->declBus(c+6153,"riscv_defines OP_A_REGA_OR_FWD", false,-1, 2,0);
        vcdp->declBus(c+7953,"riscv_defines OP_A_CURRPC", false,-1, 2,0);
        vcdp->declBus(c+7961,"riscv_defines OP_A_IMM", false,-1, 2,0);
        vcdp->declBus(c+7969,"riscv_defines OP_A_REGB_OR_FWD", false,-1, 2,0);
        vcdp->declBus(c+8417,"riscv_defines OP_A_REGC_OR_FWD", false,-1, 2,0);
        vcdp->declBus(c+8529,"riscv_defines IMMA_Z", false,-1, 0,0);
        vcdp->declBus(c+8537,"riscv_defines IMMA_ZERO", false,-1, 0,0);
        vcdp->declBus(c+6153,"riscv_defines OP_B_REGB_OR_FWD", false,-1, 2,0);
        vcdp->declBus(c+7953,"riscv_defines OP_B_REGC_OR_FWD", false,-1, 2,0);
        vcdp->declBus(c+7961,"riscv_defines OP_B_IMM", false,-1, 2,0);
        vcdp->declBus(c+7969,"riscv_defines OP_B_REGA_OR_FWD", false,-1, 2,0);
        vcdp->declBus(c+8417,"riscv_defines OP_B_BMASK", false,-1, 2,0);
        vcdp->declBus(c+6041,"riscv_defines IMMB_I", false,-1, 3,0);
        vcdp->declBus(c+8545,"riscv_defines IMMB_S", false,-1, 3,0);
        vcdp->declBus(c+8553,"riscv_defines IMMB_U", false,-1, 3,0);
        vcdp->declBus(c+8561,"riscv_defines IMMB_PCINCR", false,-1, 3,0);
        vcdp->declBus(c+8569,"riscv_defines IMMB_S2", false,-1, 3,0);
        vcdp->declBus(c+8577,"riscv_defines IMMB_S3", false,-1, 3,0);
        vcdp->declBus(c+8585,"riscv_defines IMMB_VS", false,-1, 3,0);
        vcdp->declBus(c+8593,"riscv_defines IMMB_VU", false,-1, 3,0);
        vcdp->declBus(c+8601,"riscv_defines IMMB_SHUF", false,-1, 3,0);
        vcdp->declBus(c+8609,"riscv_defines IMMB_CLIP", false,-1, 3,0);
        vcdp->declBus(c+8617,"riscv_defines IMMB_BI", false,-1, 3,0);
        vcdp->declBus(c+8625,"riscv_defines IMMB_LOGMEM", false,-1, 3,0);
        vcdp->declBus(c+8529,"riscv_defines BMASK_A_ZERO", false,-1, 0,0);
        vcdp->declBus(c+8537,"riscv_defines BMASK_A_S3", false,-1, 0,0);
        vcdp->declBus(c+6057,"riscv_defines BMASK_B_S2", false,-1, 1,0);
        vcdp->declBus(c+6857,"riscv_defines BMASK_B_S3", false,-1, 1,0);
        vcdp->declBus(c+7921,"riscv_defines BMASK_B_ZERO", false,-1, 1,0);
        vcdp->declBus(c+7929,"riscv_defines BMASK_B_ONE", false,-1, 1,0);
        vcdp->declBus(c+8529,"riscv_defines BMASK_A_REG", false,-1, 0,0);
        vcdp->declBus(c+8537,"riscv_defines BMASK_A_IMM", false,-1, 0,0);
        vcdp->declBus(c+8529,"riscv_defines BMASK_B_REG", false,-1, 0,0);
        vcdp->declBus(c+8537,"riscv_defines BMASK_B_IMM", false,-1, 0,0);
        vcdp->declBus(c+8529,"riscv_defines MIMM_ZERO", false,-1, 0,0);
        vcdp->declBus(c+8537,"riscv_defines MIMM_S3", false,-1, 0,0);
        vcdp->declBus(c+6057,"riscv_defines OP_C_REGC_OR_FWD", false,-1, 1,0);
        vcdp->declBus(c+6857,"riscv_defines OP_C_REGB_OR_FWD", false,-1, 1,0);
        vcdp->declBus(c+7921,"riscv_defines OP_C_JT", false,-1, 1,0);
        vcdp->declBus(c+7929,"riscv_defines OP_C_LIM_FUNCT", false,-1, 1,0);
        vcdp->declBus(c+6057,"riscv_defines BRANCH_NONE", false,-1, 1,0);
        vcdp->declBus(c+6857,"riscv_defines BRANCH_JAL", false,-1, 1,0);
        vcdp->declBus(c+7921,"riscv_defines BRANCH_JALR", false,-1, 1,0);
        vcdp->declBus(c+7929,"riscv_defines BRANCH_COND", false,-1, 1,0);
        vcdp->declBus(c+6857,"riscv_defines JT_JAL", false,-1, 1,0);
        vcdp->declBus(c+7921,"riscv_defines JT_JALR", false,-1, 1,0);
        vcdp->declBus(c+7929,"riscv_defines JT_COND", false,-1, 1,0);
        vcdp->declBus(c+8633,"riscv_defines AMO_LR", false,-1, 4,0);
        vcdp->declBus(c+8641,"riscv_defines AMO_SC", false,-1, 4,0);
        vcdp->declBus(c+8649,"riscv_defines AMO_SWAP", false,-1, 4,0);
        vcdp->declBus(c+6081,"riscv_defines AMO_ADD", false,-1, 4,0);
        vcdp->declBus(c+8657,"riscv_defines AMO_XOR", false,-1, 4,0);
        vcdp->declBus(c+8665,"riscv_defines AMO_AND", false,-1, 4,0);
        vcdp->declBus(c+8673,"riscv_defines AMO_OR", false,-1, 4,0);
        vcdp->declBus(c+8681,"riscv_defines AMO_MIN", false,-1, 4,0);
        vcdp->declBus(c+8689,"riscv_defines AMO_MAX", false,-1, 4,0);
        vcdp->declBus(c+8697,"riscv_defines AMO_MINU", false,-1, 4,0);
        vcdp->declBus(c+8705,"riscv_defines AMO_MAXU", false,-1, 4,0);
        vcdp->declBus(c+6153,"riscv_defines PC_BOOT", false,-1, 2,0);
        vcdp->declBus(c+7961,"riscv_defines PC_JUMP", false,-1, 2,0);
        vcdp->declBus(c+7969,"riscv_defines PC_BRANCH", false,-1, 2,0);
        vcdp->declBus(c+8417,"riscv_defines PC_EXCEPTION", false,-1, 2,0);
        vcdp->declBus(c+7953,"riscv_defines PC_FENCEI", false,-1, 2,0);
        vcdp->declBus(c+7977,"riscv_defines PC_MRET", false,-1, 2,0);
        vcdp->declBus(c+7985,"riscv_defines PC_URET", false,-1, 2,0);
        vcdp->declBus(c+8713,"riscv_defines PC_DRET", false,-1, 2,0);
        vcdp->declBus(c+6153,"riscv_defines EXC_PC_EXCEPTION", false,-1, 2,0);
        vcdp->declBus(c+7953,"riscv_defines EXC_PC_IRQ", false,-1, 2,0);
        vcdp->declBus(c+7961,"riscv_defines EXC_PC_DBD", false,-1, 2,0);
        vcdp->declBus(c+8721,"riscv_defines EXC_CAUSE_INSTR_FAULT", false,-1, 5,0);
        vcdp->declBus(c+8729,"riscv_defines EXC_CAUSE_ILLEGAL_INSN", false,-1, 5,0);
        vcdp->declBus(c+8737,"riscv_defines EXC_CAUSE_BREAKPOINT", false,-1, 5,0);
        vcdp->declBus(c+8745,"riscv_defines EXC_CAUSE_LOAD_FAULT", false,-1, 5,0);
        vcdp->declBus(c+8753,"riscv_defines EXC_CAUSE_STORE_FAULT", false,-1, 5,0);
        vcdp->declBus(c+8761,"riscv_defines EXC_CAUSE_ECALL_UMODE", false,-1, 5,0);
        vcdp->declBus(c+8769,"riscv_defines EXC_CAUSE_ECALL_MMODE", false,-1, 5,0);
        vcdp->declBus(c+8777,"riscv_defines IRQ_ID_BITS", false,-1, 31,0);
        vcdp->declBus(c+8785,"riscv_defines IRQ_LINES_NUM", false,-1, 31,0);
        vcdp->declBus(c+6057,"riscv_defines TRAP_MACHINE", false,-1, 1,0);
        vcdp->declBus(c+6857,"riscv_defines TRAP_USER", false,-1, 1,0);
        vcdp->declBus(c+7921,"riscv_defines TRAP_MACHINEX", false,-1, 1,0);
        vcdp->declBus(c+7953,"riscv_defines DBG_CAUSE_EBREAK", false,-1, 2,0);
        vcdp->declBus(c+7961,"riscv_defines DBG_CAUSE_TRIGGER", false,-1, 2,0);
        vcdp->declBus(c+7969,"riscv_defines DBG_CAUSE_HALTREQ", false,-1, 2,0);
        vcdp->declBus(c+8417,"riscv_defines DBG_CAUSE_STEP", false,-1, 2,0);
        vcdp->declBus(c+7977,"riscv_defines DBG_CAUSE_RSTHALTREQ", false,-1, 2,0);
        vcdp->declBus(c+6425,"riscv_defines DBG_SETS_W", false,-1, 31,0);
        vcdp->declBus(c+6441,"riscv_defines DBG_SETS_IRQ", false,-1, 31,0);
        vcdp->declBus(c+6409,"riscv_defines DBG_SETS_ECALL", false,-1, 31,0);
        vcdp->declBus(c+6417,"riscv_defines DBG_SETS_EILL", false,-1, 31,0);
        vcdp->declBus(c+6113,"riscv_defines DBG_SETS_ELSU", false,-1, 31,0);
        vcdp->declBus(c+6121,"riscv_defines DBG_SETS_EBRK", false,-1, 31,0);
        vcdp->declBus(c+6009,"riscv_defines DBG_SETS_SSTE", false,-1, 31,0);
        vcdp->declBus(c+8793,"riscv_defines DBG_CAUSE_HALT", false,-1, 5,0);
        vcdp->declBit(c+8801,"riscv_defines C_RVF", false,-1);
        vcdp->declBit(c+8809,"riscv_defines C_RVD", false,-1);
        vcdp->declBit(c+8809,"riscv_defines C_XF16", false,-1);
        vcdp->declBit(c+8809,"riscv_defines C_XF16ALT", false,-1);
        vcdp->declBit(c+8809,"riscv_defines C_XF8", false,-1);
        vcdp->declBit(c+8809,"riscv_defines C_XFVEC", false,-1);
        vcdp->declBus(c+8817,"riscv_defines C_FPNEW_OPBITS", false,-1, 31,0);
        vcdp->declBus(c+8825,"riscv_defines C_FPNEW_FMTBITS", false,-1, 31,0);
        vcdp->declBus(c+8833,"riscv_defines C_FPNEW_IFMTBITS", false,-1, 31,0);
        vcdp->declBus(c+8841,"riscv_defines C_LAT_FP64", false,-1, 31,0);
        vcdp->declBus(c+8841,"riscv_defines C_LAT_FP32", false,-1, 31,0);
        vcdp->declBus(c+8841,"riscv_defines C_LAT_FP16", false,-1, 31,0);
        vcdp->declBus(c+8841,"riscv_defines C_LAT_FP16ALT", false,-1, 31,0);
        vcdp->declBus(c+8841,"riscv_defines C_LAT_FP8", false,-1, 31,0);
        vcdp->declBus(c+8849,"riscv_defines C_LAT_DIVSQRT", false,-1, 31,0);
        vcdp->declBus(c+8841,"riscv_defines C_LAT_CONV", false,-1, 31,0);
        vcdp->declBus(c+8841,"riscv_defines C_LAT_NONCOMP", false,-1, 31,0);
        vcdp->declBus(c+6089,"riscv_defines C_FLEN", false,-1, 31,0);
        vcdp->declBus(c+6441,"riscv_defines C_FFLAG", false,-1, 31,0);
        vcdp->declBus(c+6417,"riscv_defines C_RM", false,-1, 31,0);
        vcdp->declBus(c+6441,"riscv_defines C_PC", false,-1, 31,0);
        vcdp->declBus(c+8857,"riscv_defines HWLoop0_START", false,-1, 11,0);
        vcdp->declBus(c+8865,"riscv_defines HWLoop0_END", false,-1, 11,0);
        vcdp->declBus(c+8873,"riscv_defines HWLoop0_COUNTER", false,-1, 11,0);
        vcdp->declBus(c+8881,"riscv_defines HWLoop1_START", false,-1, 11,0);
        vcdp->declBus(c+8889,"riscv_defines HWLoop1_END", false,-1, 11,0);
        vcdp->declBus(c+8897,"riscv_defines HWLoop1_COUNTER", false,-1, 11,0);
        vcdp->declBus(c+8905,"riscv_defines PCER_USER", false,-1, 11,0);
        vcdp->declBus(c+8913,"riscv_defines PCMR_USER", false,-1, 11,0);
        vcdp->declBus(c+8921,"riscv_defines PCER_MACHINE", false,-1, 11,0);
        vcdp->declBus(c+8929,"riscv_defines PCMR_MACHINE", false,-1, 11,0);
        vcdp->declBus(c+7721,"top ram_i dp_ram_i ADDR_WIDTH", false,-1, 31,0);
        vcdp->declBit(c+5913,"top ram_i dp_ram_i clk", false,-1);
        vcdp->declBit(c+297,"top ram_i dp_ram_i en_a_i", false,-1);
        vcdp->declBus(c+1425,"top ram_i dp_ram_i addr_a_i", false,-1, 19,0);
        vcdp->declBus(c+6073,"top ram_i dp_ram_i wdata_a_i", false,-1, 31,0);
        vcdp->declArray(c+5817,"top ram_i dp_ram_i rdata_a_o", false,-1, 127,0);
        vcdp->declBit(c+6033,"top ram_i dp_ram_i we_a_i", false,-1);
        vcdp->declBus(c+8937,"top ram_i dp_ram_i be_a_i", false,-1, 3,0);
        vcdp->declBit(c+313,"top ram_i dp_ram_i en_b_i", false,-1);
        vcdp->declBus(c+4041,"top ram_i dp_ram_i addr_b_i", false,-1, 19,0);
        vcdp->declBus(c+3609,"top ram_i dp_ram_i wdata_b_i", false,-1, 31,0);
        vcdp->declBus(c+5857,"top ram_i dp_ram_i rdata_b_o", false,-1, 31,0);
        vcdp->declBit(c+5873,"top ram_i dp_ram_i we_b_i", false,-1);
        vcdp->declBus(c+3601,"top ram_i dp_ram_i be_b_i", false,-1, 3,0);
        vcdp->declBus(c+8945,"top ram_i dp_ram_i bytes", false,-1, 31,0);
        vcdp->declBus(c+4049,"top ram_i dp_ram_i addr_b_int", false,-1, 19,0);
    }
}

void Vtop::traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Variables
    WData/*127:0*/ __Vtemp2[4];
    WData/*511:0*/ __Vtemp1[16];
    WData/*703:0*/ __Vtemp4[22];
    WData/*703:0*/ __Vtemp5[22];
    WData/*319:0*/ __Vtemp3[10];
    // Body
    {
        vcdp->fullArray(c+1,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__apu_master_operands_o),96);
        vcdp->fullArray(c+25,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__apu_operands),96);
        vcdp->fullArray(c+49,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_lut),160);
        vcdp->fullBus(c+89,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mip),19);
        vcdp->fullArray(c+97,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_n),768);
        vcdp->fullBus(c+289,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__irq_req),19);
        vcdp->fullBit(c+297,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_req_pmp));
        vcdp->fullBus(c+305,((0x3fffffU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp)),22);
        vcdp->fullBit(c+313,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_req_pmp));
        vcdp->fullBus(c+321,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp),32);
        vcdp->fullBit(c+329,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__clear_instr_valid));
        vcdp->fullBit(c+337,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_set));
        vcdp->fullBus(c+345,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id),3);
        vcdp->fullBus(c+353,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_wdata_fw),32);
        vcdp->fullBit(c+361,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__halt_if));
        vcdp->fullBit(c+369,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_ready));
        vcdp->fullBit(c+377,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_ready));
        vcdp->fullBit(c+385,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_valid));
        vcdp->fullBit(c+393,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_valid));
        vcdp->fullBit(c+401,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__lsu_ready_wb));
        vcdp->fullBit(c+409,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__lsu_ready_ex));
        vcdp->fullBit(c+417,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_save_cause));
        vcdp->fullBit(c+425,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_save_id));
        vcdp->fullBus(c+433,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_cause),7);
        vcdp->fullBus(c+441,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_cause),3);
        vcdp->fullBit(c+449,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_csr_save));
        vcdp->fullBit(c+457,((1U & ((~ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_valid)) 
                                    | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__branch_req)))));
        vcdp->fullBit(c+465,(((1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_in_id)) 
                              | (2U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_in_id)))));
        vcdp->fullBit(c+473,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__load_stall));
        vcdp->fullBit(c+481,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__offset_fsm_ns));
        vcdp->fullBit(c+489,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__if_valid));
        vcdp->fullBit(c+497,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__valid) 
                              & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_ready))));
        vcdp->fullBit(c+505,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__valid));
        vcdp->fullBit(c+513,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__branch_req));
        vcdp->fullBit(c+521,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_valid));
        vcdp->fullBit(c+529,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_ready));
        vcdp->fullBus(c+537,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_rdata),32);
        vcdp->fullBit(c+545,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_failed));
        vcdp->fullBus(c+553,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__instr_decompressed),32);
        vcdp->fullBit(c+561,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__illegal_c_insn));
        vcdp->fullBit(c+569,((3U != (3U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_rdata))));
        vcdp->fullBus(c+577,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__NS),3);
        vcdp->fullBus(c+585,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__hwlp_NS),3);
        vcdp->fullBit(c+593,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fetch_is_hwlp));
        vcdp->fullBit(c+601,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__addr_valid));
        vcdp->fullBit(c+609,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_valid));
        vcdp->fullBit(c+617,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_clear));
        vcdp->fullBit(c+625,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__hwloop_speculative));
        vcdp->fullBit(c+633,((3U != (3U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
                                           >> 0x10U)))));
        vcdp->fullArray(c+641,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_n),128);
        vcdp->fullArray(c+673,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_int),128);
        vcdp->fullArray(c+705,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_n),128);
        vcdp->fullArray(c+737,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_int),128);
        vcdp->fullBus(c+769,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_n),4);
        vcdp->fullBus(c+777,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_int),4);
        vcdp->fullBus(c+785,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__is_hwlp_n),2);
        vcdp->fullBus(c+793,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__is_hwlp_int),2);
        vcdp->fullBus(c+801,(((IData)(4U) + (0xfffffffcU 
                                             & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_int[0U]))),32);
        vcdp->fullBus(c+809,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata),32);
        vcdp->fullBit(c+817,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid));
        vcdp->fullBit(c+825,((3U != (3U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata))));
        vcdp->fullBus(c+833,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unnamedblk1__DOT__j),32);
        vcdp->fullBus(c+841,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unnamedblk2__DOT__i),32);
        vcdp->fullBus(c+849,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unnamedblk3__DOT__i),32);
        vcdp->fullBus(c+857,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unnamedblk4__DOT__i),32);
        vcdp->fullBit(c+865,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__deassert_we));
        vcdp->fullBus(c+873,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_in_id),2);
        vcdp->fullBit(c+881,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_mask));
        vcdp->fullBit(c+889,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__halt_id));
        vcdp->fullBit(c+897,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__exc_kill));
        vcdp->fullBit(c+905,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_alu_we_id));
        vcdp->fullBit(c+913,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_int_en) 
                              | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_dot_en))));
        vcdp->fullBit(c+921,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_int_en));
        vcdp->fullBit(c+929,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_dot_en));
        vcdp->fullBit(c+937,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_we_id));
        vcdp->fullBit(c+945,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__data_req_id));
        vcdp->fullBit(c+953,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regid));
        vcdp->fullBus(c+961,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_we),3);
        vcdp->fullBus(c+969,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_we_masked),3);
        vcdp->fullBus(c+977,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_cnt),32);
        vcdp->fullBus(c+985,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_cnt_int),32);
        vcdp->fullBit(c+993,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_valid));
        vcdp->fullBus(c+1001,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_a_fw_id),32);
        vcdp->fullBus(c+1009,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b_fw_id),32);
        vcdp->fullBus(c+1017,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c_fw_id),32);
        vcdp->fullBus(c+1025,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b),32);
        vcdp->fullBus(c+1033,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b_vec),32);
        vcdp->fullBus(c+1041,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c),32);
        vcdp->fullBus(c+1049,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_operand_a),32);
        vcdp->fullBus(c+1057,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_operand_b),32);
        vcdp->fullBus(c+1065,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns),5);
        vcdp->fullBit(c+1073,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__jump_done));
        vcdp->fullBit(c+1081,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__jump_in_dec));
        vcdp->fullBit(c+1089,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__branch_in_id));
        vcdp->fullBit(c+1097,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__irq_enable_int));
        vcdp->fullBit(c+1105,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_force_debug_mode));
        vcdp->fullBit(c+1113,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_n));
        vcdp->fullBit(c+1121,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__instr_valid_irq_flush_n));
        vcdp->fullBus(c+1129,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_result),32);
        vcdp->fullBus(c+1137,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_result),32);
        vcdp->fullBit(c+1145,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__div_ready));
        vcdp->fullBus(c+1153,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__div_shift),6);
        vcdp->fullBus(c+1161,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_amt_left),32);
        vcdp->fullBus(c+1169,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_amt),32);
        vcdp->fullBus(c+1177,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_amt_int),32);
        vcdp->fullBus(c+1185,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_result),32);
        vcdp->fullBus(c+1193,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_right_result),32);
        vcdp->fullBus(c+1201,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_left_result),32);
        vcdp->fullBus(c+1209,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bitop_result),6);
        vcdp->fullBus(c+1217,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bextins_result),32);
        vcdp->fullBus(c+1225,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__radix_2_rev),32);
        vcdp->fullBus(c+1233,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__radix_4_rev),32);
        vcdp->fullBus(c+1241,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__radix_8_rev),32);
        vcdp->fullBus(c+1249,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddMux_D),32);
        vcdp->fullBus(c+1257,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddTmp_D),32);
        vcdp->fullBit(c+1265,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ARegEn_S));
        vcdp->fullBit(c+1273,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BRegEn_S));
        vcdp->fullBit(c+1281,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResRegEn_S));
        vcdp->fullBit(c+1289,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S));
        vcdp->fullBus(c+1297,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__State_SN),2);
        vcdp->fullQuad(c+1305,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_mac),34);
        vcdp->fullQuad(c+1321,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_result),34);
        vcdp->fullBus(c+1337,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_NS),3);
        vcdp->fullBus(c+1345,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__NS),2);
        vcdp->fullBus(c+1353,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mepc_n),32);
        vcdp->fullBus(c+1361,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__dcsr_n),32);
        vcdp->fullBus(c+1369,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__depc_n),32);
        vcdp->fullBus(c+1377,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__exception_pc),32);
        vcdp->fullBus(c+1385,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mstatus_n),7);
        vcdp->fullBus(c+1393,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mcause_n),7);
        vcdp->fullBit(c+1401,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_cause) 
                                     >> 6U))));
        vcdp->fullBus(c+1409,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__priv_lvl_n),2);
        vcdp->fullBus(c+1417,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCCR_inc),12);
        vcdp->fullBus(c+1425,((0xfffffU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp)),20);
        vcdp->fullBit(c+1433,(((0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__CS)) 
                               | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_req_pmp))));
        vcdp->fullBit(c+1441,(((((1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS)) 
                                 | (2U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS))) 
                                | (3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS))) 
                               | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_req_pmp))));
        vcdp->fullBit(c+1449,(((((0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__CS)) 
                                 | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_req_pmp)) 
                                | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ctrl_busy)) 
                               | ((((1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS)) 
                                    | (2U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS))) 
                                   | (3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS))) 
                                  | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_req_pmp)))));
        vcdp->fullBit(c+1457,((1U & (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_Q) 
                                      >> 2U) | (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_Q) 
                                                 >> 3U) 
                                                & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_valid))))));
        vcdp->fullBus(c+1465,(((0xfffffff8U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c_fw_id 
                                               << 3U)) 
                               | (7U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                        >> 0xcU)))),32);
        vcdp->fullBus(c+1473,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__deassert_we)
                                ? 0U : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__hwloop_we))),3);
        vcdp->fullBus(c+1481,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__deassert_we)
                                ? 0U : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__csr_op))),2);
        vcdp->fullBus(c+1489,(((3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_vec_mode))
                                ? ((0xff000000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c 
                                                   << 0x18U)) 
                                   | ((0xff0000U & 
                                       (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c 
                                        << 0x10U)) 
                                      | ((0xff00U & 
                                          (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c 
                                           << 8U)) 
                                         | (0xffU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c))))
                                : ((0xffff0000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c 
                                                   << 0x10U)) 
                                   | (0xffffU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c)))),32);
        vcdp->fullBus(c+1497,((0x1fU & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_a_mux_sel)
                                         ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_a_id_imm)
                                         : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_a_mux_sel)
                                             ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_a_id_imm)
                                             : (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b_fw_id 
                                                >> 5U))))),5);
        vcdp->fullBus(c+1505,((0x1fU & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_b_mux_sel)
                                         ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_b_id_imm)
                                         : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_b_mux_sel)
                                             ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_b_id_imm)
                                             : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b_fw_id)))),5);
        vcdp->fullBus(c+1513,((0x3fU & ((0x1fU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0U]) 
                                        - (IData)(1U)))),6);
        vcdp->fullBus(c+1521,((0x1fU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0U])),5);
        vcdp->fullBit(c+1529,((1U & (~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__sel_nodes))));
        vcdp->fullBus(c+1537,((0x1fU & ((IData)(0x1fU) 
                                        - vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0U]))),5);
        vcdp->fullBit(c+1545,(((0x28U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
                               & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_result 
                                  >> (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex)))));
        vcdp->fullBus(c+1553,(((0U == (3U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex)))
                                ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__radix_2_rev
                                : ((1U == (3U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex)))
                                    ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__radix_4_rev
                                    : ((2U == (3U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex)))
                                        ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__radix_8_rev
                                        : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__radix_2_rev)))),32);
        vcdp->fullBus(c+1561,(((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__sel_nodes)
                                ? (0x3fU & ((0x1fU 
                                             & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0U]) 
                                            - (IData)(1U)))
                                : 0x1fU)),6);
        vcdp->fullBus(c+1569,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__sel_nodes),32);
        vcdp->fullArray(c+1577,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes),160);
        vcdp->fullBus(c+1617,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
                                ? 0U : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResRegEn_S)
                                         ? (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ABComp_S) 
                                             << 0x1fU) 
                                            | (0x7fffffffU 
                                               & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResReg_DP 
                                                  >> 1U)))
                                         : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResReg_DP))),32);
        vcdp->fullBus(c+1625,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ARegEn_S)
                                ? (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S) 
                                    & (~ ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex) 
                                          & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex 
                                              >> 0x1fU) 
                                             ^ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed)))))
                                    ? (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddTmp_D 
                                       + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddMux_D)
                                    : (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddTmp_D 
                                       - vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddMux_D))
                                : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AReg_DP)),32);
        vcdp->fullBus(c+1633,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BRegEn_S)
                                ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
                                    ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_left_result
                                    : (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__CompInv_SP) 
                                        << 0x1fU) | 
                                       (0x7fffffffU 
                                        & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BReg_DP 
                                           >> 1U))))
                                : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BReg_DP)),32);
        vcdp->fullBit(c+1641,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
                                      ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex) 
                                         >> 1U) : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__RemSel_SP)))));
        vcdp->fullBit(c+1649,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
                                ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed)
                                : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__CompInv_SP))));
        vcdp->fullBit(c+1657,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
                                      ? ((((0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cnt_result)) 
                                           | ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex) 
                                              >> 1U)) 
                                          & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
                                         & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex 
                                             >> 0x1fU) 
                                            ^ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed)))
                                      : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResInv_SP)))));
        vcdp->fullBus(c+1665,((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S) 
                                & (~ ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex) 
                                      & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex 
                                          >> 0x1fU) 
                                         ^ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed)))))
                                ? (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddTmp_D 
                                   + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddMux_D)
                                : (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddTmp_D 
                                   - vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddMux_D))),32);
        vcdp->fullBus(c+1673,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
                                ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_left_result
                                : (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__CompInv_SP) 
                                    << 0x1fU) | (0x7fffffffU 
                                                 & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BReg_DP 
                                                    >> 1U))))),32);
        vcdp->fullBus(c+1681,((0x3fU & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
                                         ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__div_shift)
                                         : ((0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__Cnt_DP))
                                             ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__Cnt_DP) 
                                                - (IData)(1U))
                                             : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__Cnt_DP))))),6);
        vcdp->fullBit(c+1689,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S) 
                               & (~ ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex) 
                                     & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex 
                                         >> 0x1fU) 
                                        ^ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed)))))));
        vcdp->fullBus(c+1697,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_a),17);
        vcdp->fullBus(c+1705,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_b),17);
        vcdp->fullQuad(c+1713,((VL_ULL(0x3ffffffff) 
                                & VL_MULS_QQQ(34,34,34, 
                                              (VL_ULL(0x3ffffffff) 
                                               & VL_EXTENDS_QI(34,17, vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_a)), 
                                              (VL_ULL(0x3ffffffff) 
                                               & VL_EXTENDS_QI(34,17, vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_b))))),34);
        vcdp->fullBit(c+1729,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_active)
                                      ? (IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_mac 
                                                 >> 0x21U))
                                      : (IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_mac 
                                                 >> 0x1fU))))));
        vcdp->fullBit(c+1737,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_active)
                                      ? (IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_mac 
                                                 >> 0x20U))
                                      : (IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_mac 
                                                 >> 0x1fU))))));
        vcdp->fullBus(c+1745,(((4U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_Q))
                                ? ((0xffff0000U & (
                                                   vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_Q[1U] 
                                                   << 0x10U)) 
                                   | (0xffffU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
                                                 >> 0x10U)))
                                : ((0xffff0000U & (
                                                   vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[0U] 
                                                   << 0x10U)) 
                                   | (0xffffU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
                                                 >> 0x10U))))),32);
        vcdp->fullBus(c+1753,(((4U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id))
                                ? ((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id))
                                    ? ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id))
                                        ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__depc_q
                                        : 0U) : ((1U 
                                                  & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id))
                                                  ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mepc_q
                                                  : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__exc_pc))
                                : ((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id))
                                    ? ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id))
                                        ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex
                                        : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_target)
                                    : ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id))
                                        ? ((IData)(4U) 
                                           + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_id)
                                        : 0x80U)))),32);
        vcdp->fullBus(c+1761,((0xfffffffeU & ((4U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id))
                                               ? ((2U 
                                                   & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id))
                                                    ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__depc_q
                                                    : 0U)
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id))
                                                    ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mepc_q
                                                    : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__exc_pc))
                                               : ((2U 
                                                   & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id))
                                                    ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex
                                                    : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_target)
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id))
                                                    ? 
                                                   ((IData)(4U) 
                                                    + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_id)
                                                    : 0x80U))))),32);
        vcdp->fullBus(c+1769,(((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_we_masked))
                                ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_start_int
                                : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__csr_wdata_int)),32);
        vcdp->fullBus(c+1777,(((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_we_masked))
                                ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_target
                                : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__csr_wdata_int)),32);
        vcdp->fullBus(c+1785,(((0x2aU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))
                                ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex
                                : VL_NEGATE_I((IData)(
                                                      ((0x28U 
                                                        == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
                                                       & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_result 
                                                          >> (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex))))))),32);
        vcdp->fullBus(c+1793,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCCR_in),12);
        vcdp->fullBit(c+1801,(((4U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id)) 
                               & (1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__exc_pc_mux_id)))));
        vcdp->fullBit(c+1809,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_req_pmp) 
                               & (~ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_we_ex)))));
        vcdp->fullBit(c+1817,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_req_pmp) 
                               & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_we_ex))));
        vcdp->fullBit(c+1825,(vlSymsp->TOP__top.irq_ack_o));
        vcdp->fullBit(c+1833,(vlSymsp->TOP__top.core_busy_o));
        vcdp->fullBit(c+1841,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__is_hwlp_id));
        vcdp->fullBit(c+1849,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cmp_result) 
                                     >> 3U))));
        vcdp->fullBit(c+1857,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ctrl_busy));
        vcdp->fullBit(c+1865,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_we_wb));
        vcdp->fullBit(c+1873,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_we_fw));
        vcdp->fullBus(c+1881,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr_int),12);
        vcdp->fullBus(c+1889,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_rdata),32);
        vcdp->fullBit(c+1897,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_req_int));
        vcdp->fullBit(c+1905,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_irq_sec));
        vcdp->fullBit(c+1913,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_hwlp_regid));
        vcdp->fullBus(c+1921,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_hwlp_we),3);
        vcdp->fullBus(c+1929,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__csr_wdata_int),32);
        vcdp->fullBit(c+1937,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jr_stall));
        vcdp->fullBit(c+1945,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__core_ctrl_firstfetch));
        vcdp->fullBit(c+1953,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__irq_pending));
        vcdp->fullBus(c+1961,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__irq_id),6);
        vcdp->fullBit(c+1969,((1U & (~ (IData)(vlSymsp->TOP__top.core_busy_o)))));
        vcdp->fullBit(c+1977,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_is_hwlp));
        vcdp->fullBit(c+1985,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__hwlp_branch));
        vcdp->fullBus(c+1993,(vlSymsp->TOP__top.riscv_core_i__DOT__if_stage_i__DOT____Vcellinp__hwloop_controller_i__hwlp_dec_cnt_id_i),2);
        vcdp->fullBit(c+2001,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_hwlp));
        vcdp->fullBit(c+2009,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__ebrk_insn));
        vcdp->fullBit(c+2017,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mret_insn_dec));
        vcdp->fullBit(c+2025,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__uret_insn_dec));
        vcdp->fullBit(c+2033,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__dret_insn_dec));
        vcdp->fullBit(c+2041,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__ecall_insn_dec));
        vcdp->fullBit(c+2049,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__pipe_flush_dec));
        vcdp->fullBit(c+2057,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__fencei_insn_dec));
        vcdp->fullBit(c+2065,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__rega_used_dec));
        vcdp->fullBit(c+2073,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regb_used_dec));
        vcdp->fullBit(c+2081,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regc_used_dec));
        vcdp->fullBus(c+2089,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__jump_in_id),2);
        vcdp->fullBit(c+2097,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__csr_access) 
                               & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_en_ex) 
                                  & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_lat_ex) 
                                     >> 1U)))));
        vcdp->fullBit(c+2105,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__instr_multicycle));
        vcdp->fullBus(c+2113,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_i_type),32);
        vcdp->fullBus(c+2121,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_vu_type),32);
        vcdp->fullBus(c+2129,(((3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_vec_mode))
                                ? ((0x3000000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                  >> 3U)) 
                                   | ((0x30000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                   >> 7U)) 
                                      | ((0x300U & 
                                          (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                           >> 0xdU)) 
                                         | ((2U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                   >> 0x13U)) 
                                            | (1U & 
                                               (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                >> 0x19U))))))
                                : ((0x10000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                >> 4U)) 
                                   | (1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                            >> 0x19U))))),32);
        vcdp->fullBus(c+2137,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_a_mux_sel)
                                ? 0U : (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                 >> 0xfU)))),32);
        vcdp->fullBit(c+2145,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__exc_ack));
        vcdp->fullBus(c+2153,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id),6);
        vcdp->fullBus(c+2161,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_alu_waddr_id),6);
        vcdp->fullBus(c+2169,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_data_ra_id),32);
        vcdp->fullBus(c+2177,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__mem[
                              (0x1fU & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id))]),32);
        vcdp->fullBus(c+2185,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_operator),7);
        vcdp->fullBus(c+2193,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regc_mux),2);
        vcdp->fullBit(c+2201,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_a_mux_sel));
        vcdp->fullBus(c+2209,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_target_mux_sel),2);
        vcdp->fullBus(c+2217,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_operator),3);
        vcdp->fullBit(c+2225,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_sel_subword));
        vcdp->fullBus(c+2233,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_signed_mode),2);
        vcdp->fullBus(c+2241,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_dot_signed),2);
        vcdp->fullBit(c+2249,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_alu_waddr_mux_sel));
        vcdp->fullBus(c+2257,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__data_sign_ext_id),2);
        vcdp->fullBit(c+2265,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__data_load_event_id));
        vcdp->fullBit(c+2273,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_target_mux_sel));
        vcdp->fullBit(c+2281,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_start_mux_sel));
        vcdp->fullBit(c+2289,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_cnt_mux_sel));
        vcdp->fullBit(c+2297,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__csr_access));
        vcdp->fullBit(c+2305,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_a_mux));
        vcdp->fullBus(c+2313,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_b_mux),2);
        vcdp->fullBit(c+2321,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_a_mux_sel));
        vcdp->fullBit(c+2329,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_b_mux_sel));
        vcdp->fullBit(c+2337,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_imm_mux));
        vcdp->fullBus(c+2345,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_a_id_imm),5);
        vcdp->fullBus(c+2353,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_b_id_imm),5);
        vcdp->fullBus(c+2361,((3U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_vu_type)),2);
        vcdp->fullBus(c+2369,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_imm_mux)
                                ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_imm_mux)
                                    ? (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                >> 0x19U))
                                    : 0U) : 0U)),5);
        vcdp->fullBus(c+2377,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_vec_mode),2);
        vcdp->fullBit(c+2385,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__reg_d_ex_is_reg_a_id));
        vcdp->fullBit(c+2393,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__reg_d_ex_is_reg_b_id));
        vcdp->fullBit(c+2401,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__reg_d_ex_is_reg_c_id));
        vcdp->fullBit(c+2409,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__reg_d_wb_is_reg_a_id));
        vcdp->fullBit(c+2417,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__regfile_waddr_lsu) 
                                 == (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                              >> 0x14U))) 
                                & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regb_used_dec)) 
                               & (0U != (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                  >> 0x14U))))));
        vcdp->fullBit(c+2425,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__regfile_waddr_lsu) 
                                 == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id)) 
                                & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regc_used_dec)) 
                               & (0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id)))));
        vcdp->fullBit(c+2433,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__reg_d_alu_is_reg_a_id));
        vcdp->fullBit(c+2441,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_waddr_ex) 
                                 == (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                              >> 0x14U))) 
                                & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regb_used_dec)) 
                               & (0U != (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                  >> 0x14U))))));
        vcdp->fullBit(c+2449,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_waddr_ex) 
                                 == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id)) 
                                & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regc_used_dec)) 
                               & (0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id)))));
        vcdp->fullBit(c+2457,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__is_clpx));
        vcdp->fullBit(c+2465,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__is_subrot));
        vcdp->fullBit(c+2473,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mret_dec));
        vcdp->fullBit(c+2481,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__uret_dec));
        vcdp->fullBit(c+2489,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__dret_dec));
        vcdp->fullBus(c+2497,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__we_a_dec),32);
        vcdp->fullBus(c+2505,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__we_b_dec),32);
        vcdp->fullBit(c+2513,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__regfile_mem_we));
        vcdp->fullBit(c+2521,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__data_req));
        vcdp->fullBus(c+2529,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__hwloop_we),3);
        vcdp->fullBus(c+2537,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__csr_op),2);
        vcdp->fullBit(c+2545,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__mult_int_en));
        vcdp->fullBit(c+2553,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__mult_dot_en));
        vcdp->fullBit(c+2561,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__boot_done));
        vcdp->fullBit(c+2569,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_n));
        vcdp->fullQuad(c+2577,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_counter_n),64);
        vcdp->fullBit(c+2593,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_ready));
        vcdp->fullBus(c+2601,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__operand_a_rev),32);
        vcdp->fullBus(c+2609,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__operand_a_neg_rev),32);
        vcdp->fullBit(c+2617,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__div_valid));
        vcdp->fullBus(c+2625,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask),32);
        vcdp->fullBit(c+2633,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_op_b_negate));
        vcdp->fullBus(c+2641,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_op_a),32);
        vcdp->fullBus(c+2649,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_op_b),32);
        vcdp->fullQuad(c+2657,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_in_a),36);
        vcdp->fullQuad(c+2673,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_in_b),36);
        vcdp->fullBus(c+2689,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_result),32);
        vcdp->fullQuad(c+2697,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_result_expanded),37);
        vcdp->fullBus(c+2713,((((((0x1cU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
                                  | (0x1dU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
                                 | (0x1eU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
                                | (0x1fU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)))
                                ? (0x7fffffffU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask 
                                                  >> 1U))
                                : 0U)),32);
        vcdp->fullBus(c+2721,((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_result 
                               + (((((0x1cU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
                                     | (0x1dU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
                                    | (0x1eU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
                                   | (0x1fU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)))
                                   ? (0x7fffffffU & 
                                      (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask 
                                       >> 1U)) : 0U))),32);
        vcdp->fullBit(c+2729,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_left));
        vcdp->fullBit(c+2737,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_use_round));
        vcdp->fullBit(c+2745,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_arithmetic));
        vcdp->fullBus(c+2753,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_op_a),32);
        vcdp->fullQuad(c+2761,(((0x26U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))
                                 ? (((QData)((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_op_a)) 
                                     << 0x20U) | (QData)((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_op_a)))
                                 : (((QData)((IData)(
                                                     VL_NEGATE_I((IData)(
                                                                         ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_arithmetic) 
                                                                          & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_op_a 
                                                                             >> 0x1fU)))))) 
                                     << 0x20U) | (QData)((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_op_a))))),64);
        vcdp->fullBus(c+2777,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_equal),4);
        vcdp->fullBus(c+2785,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_greater),4);
        vcdp->fullBus(c+2793,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__f_is_greater),4);
        vcdp->fullBus(c+2801,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cmp_signed),4);
        vcdp->fullBus(c+2809,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_equal_vec),4);
        vcdp->fullBus(c+2817,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_greater_vec),4);
        vcdp->fullBit(c+2825,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_equal_clip));
        vcdp->fullBus(c+2833,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cmp_result),4);
        vcdp->fullBus(c+2841,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__f_is_nan),4);
        vcdp->fullBus(c+2849,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__result_minmax),32);
        vcdp->fullBus(c+2857,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__sel_minmax),4);
        vcdp->fullBus(c+2865,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__minmax_b),32);
        vcdp->fullBus(c+2873,(((0x17U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))
                                ? ((1U & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex 
                                           >> 0x1fU) 
                                          | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_equal_clip)))
                                    ? 0U : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__result_minmax)
                                : ((1U & ((IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_result_expanded 
                                                   >> 0x24U)) 
                                          | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_equal_clip)))
                                    ? (~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex)
                                    : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__result_minmax))),32);
        vcdp->fullBus(c+2881,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_byte_sel),8);
        vcdp->fullBus(c+2889,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_reg_sel),4);
        vcdp->fullBus(c+2897,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_reg1_sel),2);
        vcdp->fullBus(c+2905,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_reg0_sel),2);
        vcdp->fullBus(c+2913,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_through),4);
        vcdp->fullBus(c+2921,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_r0),32);
        vcdp->fullBus(c+2929,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_r0_in),32);
        vcdp->fullBus(c+2937,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__ff_input),32);
        vcdp->fullBus(c+2945,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cnt_result),6);
        vcdp->fullBus(c+2953,((~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask)),32);
        vcdp->fullBus(c+2961,((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex 
                               & (~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask))),32);
        vcdp->fullBus(c+2969,((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex 
                               | vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask)),32);
        vcdp->fullBus(c+2977,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResInv_SP)
                                ? VL_NEGATE_I(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__OutMux_D)
                                : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__OutMux_D)),32);
        vcdp->fullBit(c+2985,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed));
        vcdp->fullBus(c+2993,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_popcnt_i__DOT__cnt_l1),32);
        vcdp->fullBus(c+3001,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_popcnt_i__DOT__cnt_l2),24);
        vcdp->fullBus(c+3009,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_popcnt_i__DOT__cnt_l3),16);
        vcdp->fullBus(c+3017,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_popcnt_i__DOT__cnt_l4),10);
        vcdp->fullBit(c+3025,((0U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cnt_result))));
        vcdp->fullBus(c+3033,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResReg_DP_rev),32);
        vcdp->fullBus(c+3041,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__OutMux_D),32);
        vcdp->fullBit(c+3049,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ABComp_S));
        vcdp->fullQuad(c+3057,((VL_ULL(0x1ffffffff) 
                                & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_active)
                                    ? (((QData)((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_carry_q)) 
                                        << 0x20U) | (QData)((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_c_ex)))
                                    : VL_EXTENDS_QI(33,32, vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_c_ex)))),33);
        vcdp->fullBus(c+3073,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_active)
                                ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_imm)
                                : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_imm_ex))),5);
        vcdp->fullBus(c+3081,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_subword),2);
        vcdp->fullBus(c+3089,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_signed),2);
        vcdp->fullBit(c+3097,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_shift_arith));
        vcdp->fullBus(c+3105,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_imm),5);
        vcdp->fullBus(c+3113,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_subword),2);
        vcdp->fullBus(c+3121,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_signed),2);
        vcdp->fullBit(c+3129,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_shift_arith));
        vcdp->fullBit(c+3137,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_active));
        vcdp->fullBit(c+3145,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_save));
        vcdp->fullBit(c+3153,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_clearcarry));
        vcdp->fullBus(c+3161,(((((VL_EXTENDS_II(32,18, 
                                                (0x3ffffU 
                                                 & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_mul[0U])) 
                                  + VL_EXTENDS_II(32,18, 
                                                  (0x3ffffU 
                                                   & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_mul[1U] 
                                                       << 0xeU) 
                                                      | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_mul[0U] 
                                                         >> 0x12U))))) 
                                 + VL_EXTENDS_II(32,18, 
                                                 (0x3ffffU 
                                                  & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_mul[2U] 
                                                      << 0x1cU) 
                                                     | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_mul[1U] 
                                                        >> 4U))))) 
                                + VL_EXTENDS_II(32,18, 
                                                (0x3ffffU 
                                                 & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_mul[2U] 
                                                     << 0xaU) 
                                                    | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_mul[1U] 
                                                       >> 0x16U))))) 
                               + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_op_c_ex)),32);
        vcdp->fullQuad(c+3169,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__dot_short_result),33);
        vcdp->fullBus(c+3185,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_is_clpx_ex)
                                ? (VL_EXTENDS_II(32,17, 
                                                 (0x1ffffU 
                                                  & (IData)(
                                                            (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_op_b 
                                                             >> 0x11U)))) 
                                   & VL_NEGATE_I((IData)(
                                                         (1U 
                                                          & (~ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_clpx_img_ex))))))
                                : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_op_c_ex)),32);
        vcdp->fullBus(c+3193,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__clpx_shift_result),16);
        vcdp->fullQuad(c+3201,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_op_a),36);
        vcdp->fullQuad(c+3217,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_op_b),36);
        vcdp->fullArray(c+3233,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_mul),72);
        vcdp->fullQuad(c+3257,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_op_a),34);
        vcdp->fullQuad(c+3273,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_op_b),34);
        vcdp->fullArray(c+3289,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_mul),68);
        vcdp->fullBus(c+3313,((0x1ffffU & ((IData)(
                                                   (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_op_a 
                                                    >> 0x11U)) 
                                           ^ VL_NEGATE_I((IData)(
                                                                 ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_is_clpx_ex) 
                                                                  & (~ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_clpx_img_ex)))))))),17);
        vcdp->fullBus(c+3321,(VL_EXTENDS_II(32,17, 
                                            (0x1ffffU 
                                             & (IData)(
                                                       (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_op_b 
                                                        >> 0x11U))))),32);
        vcdp->fullBus(c+3329,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__csr_rdata_int),32);
        vcdp->fullBit(c+3337,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__csr_we_int));
        vcdp->fullBus(c+3345,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__frm_n),3);
        vcdp->fullBus(c+3353,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__fflags_n),5);
        vcdp->fullBus(c+3361,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__fprec_n),5);
        vcdp->fullBus(c+3369,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__dscratch0_n),32);
        vcdp->fullBus(c+3377,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__dscratch1_n),32);
        vcdp->fullBus(c+3385,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mscratch_n),32);
        vcdp->fullBus(c+3393,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mtvec_n),24);
        vcdp->fullBus(c+3401,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mtvecx_n),24);
        vcdp->fullBus(c+3409,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mie_n),19);
        vcdp->fullBus(c+3417,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__miex_n),32);
        vcdp->fullBus(c+3425,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__menip),19);
        vcdp->fullArray(c+3433,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCCR_n),384);
        vcdp->fullBus(c+3529,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCMR_n),2);
        vcdp->fullBus(c+3537,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCER_n),12);
        vcdp->fullBus(c+3545,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__perf_rdata),32);
        vcdp->fullBus(c+3553,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pccr_index),5);
        vcdp->fullBit(c+3561,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pccr_all_sel));
        vcdp->fullBit(c+3569,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__is_pccr));
        vcdp->fullBit(c+3577,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__is_pcer));
        vcdp->fullBit(c+3585,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__is_pcmr));
        vcdp->fullBus(c+3593,((0x3fffffU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)),22);
        vcdp->fullBus(c+3601,(((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_type_ex))
                                ? ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                    ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                        ? 8U : 4U) : 
                                   ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                     ? 2U : 1U)) : 
                               ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_type_ex))
                                 ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned_ex)
                                     ? 1U : ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                              ? ((1U 
                                                  & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                                  ? 8U
                                                  : 0xcU)
                                              : ((1U 
                                                  & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                                  ? 6U
                                                  : 3U)))
                                 : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned_ex)
                                     ? ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                         ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                             ? 7U : 3U)
                                         : ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                             ? 1U : 0U))
                                     : ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                         ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                             ? 8U : 0xcU)
                                         : ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                             ? 0xeU
                                             : 0xfU)))))),4);
        vcdp->fullBus(c+3609,(((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset))
                                ? ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset))
                                    ? ((0xff000000U 
                                        & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                           << 0x18U)) 
                                       | (0xffffffU 
                                          & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                             >> 8U)))
                                    : ((0xffff0000U 
                                        & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                           << 0x10U)) 
                                       | (0xffffU & 
                                          (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                           >> 0x10U))))
                                : ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset))
                                    ? ((0xffffff00U 
                                        & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                           << 8U)) 
                                       | (0xffU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                   >> 0x18U)))
                                    : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex))),32);
        vcdp->fullBus(c+3617,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int),32);
        vcdp->fullBus(c+3625,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_addr),32);
        vcdp->fullBus(c+3633,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__exc_pc_mux_id),3);
        vcdp->fullBus(c+3641,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__exc_cause),6);
        vcdp->fullBus(c+3649,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__trap_addr_mux),2);
        vcdp->fullBit(c+3657,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__is_decoding));
        vcdp->fullBit(c+3665,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned));
        vcdp->fullBit(c+3673,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_multicycle));
        vcdp->fullBus(c+3681,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_target),32);
        vcdp->fullBus(c+3689,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__lsu_rdata),32);
        vcdp->fullBit(c+3697,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_save_if));
        vcdp->fullBit(c+3705,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_restore_mret_id));
        vcdp->fullBit(c+3713,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_restore_uret_id));
        vcdp->fullBit(c+3721,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_restore_dret_id));
        vcdp->fullBit(c+3729,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__perf_pipeline_stall));
        vcdp->fullBus(c+3737,((0x1fU & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__exc_cause))),5);
        vcdp->fullBus(c+3745,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__exc_pc),32);
        vcdp->fullBit(c+3753,((0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwloop_controller_i__DOT__pc_is_end_addr))));
        vcdp->fullBus(c+3761,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwlp_target),32);
        vcdp->fullBus(c+3769,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwlp_dec_cnt),2);
        vcdp->fullBus(c+3777,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__trap_base_addr),24);
        vcdp->fullBus(c+3785,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwloop_controller_i__DOT__pc_is_end_addr),2);
        vcdp->fullBus(c+3793,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwloop_controller_i__DOT__j),32);
        vcdp->fullBit(c+3801,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__valid_stored));
        vcdp->fullBit(c+3809,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__hwlp_masked));
        vcdp->fullBit(c+3817,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__illegal_insn_dec));
        vcdp->fullBit(c+3825,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__branch_taken_ex));
        vcdp->fullBus(c+3833,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_b),32);
        vcdp->fullBit(c+3841,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__regfile_alu_we));
        vcdp->fullBit(c+3849,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_en));
        vcdp->fullBus(c+3857,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_op_a_mux_sel),3);
        vcdp->fullBus(c+3865,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_op_b_mux_sel),3);
        vcdp->fullBus(c+3873,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_op_c_mux_sel),2);
        vcdp->fullBus(c+3881,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_b_mux_sel),4);
        vcdp->fullBit(c+3889,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__data_we_id));
        vcdp->fullBus(c+3897,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__data_type_id),2);
        vcdp->fullBus(c+3905,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_target),32);
        vcdp->fullBus(c+3913,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_start_int),32);
        vcdp->fullBit(c+3921,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__csr_status));
        vcdp->fullBit(c+3929,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__prepost_useincr));
        vcdp->fullBus(c+3937,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_a_fw_mux_sel),2);
        vcdp->fullBus(c+3945,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b_fw_mux_sel),2);
        vcdp->fullBus(c+3953,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c_fw_mux_sel),2);
        vcdp->fullBit(c+3961,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__scalar_replication));
        vcdp->fullBit(c+3969,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__csr_illegal));
        vcdp->fullBus(c+3977,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_r1),32);
        vcdp->fullBus(c+3985,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_r1_in),32);
        vcdp->fullBus(c+3993,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_result),32);
        vcdp->fullBus(c+4001,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__pack_result),32);
        vcdp->fullBus(c+4009,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset),2);
        vcdp->fullBus(c+4017,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_rdata_ext),32);
        vcdp->fullBus(c+4025,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_h_ext),32);
        vcdp->fullBus(c+4033,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_b_ext),32);
        vcdp->fullBus(c+4041,((0xfffffU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)),20);
        vcdp->fullBus(c+4049,((0xffffcU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)),20);
        vcdp->fullBus(c+4057,((0x1fU & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__int_controller_i__DOT__irq_id_q))),5);
        vcdp->fullBus(c+4065,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_atop_ex),6);
        vcdp->fullBus(c+4073,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__hwlp_dec_cnt_id),2);
        vcdp->fullBit(c+4081,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_valid_id));
        vcdp->fullBus(c+4089,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id),32);
        vcdp->fullBit(c+4097,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__is_compressed_id));
        vcdp->fullBit(c+4105,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__is_fetch_failed_id));
        vcdp->fullBit(c+4113,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__illegal_c_insn_id));
        vcdp->fullBit(c+4121,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__useincr_addr_ex));
        vcdp->fullBit(c+4129,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__branch_in_ex));
        vcdp->fullBus(c+4137,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_ex),32);
        vcdp->fullBit(c+4145,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_en_ex));
        vcdp->fullBus(c+4153,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex),7);
        vcdp->fullBus(c+4161,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex),32);
        vcdp->fullBus(c+4169,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex),32);
        vcdp->fullBus(c+4177,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex),5);
        vcdp->fullBus(c+4185,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_b_ex),5);
        vcdp->fullBus(c+4193,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__imm_vec_ext_ex),2);
        vcdp->fullBus(c+4201,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_vec_mode_ex),2);
        vcdp->fullBit(c+4209,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_is_clpx_ex));
        vcdp->fullBit(c+4217,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_is_subrot_ex));
        vcdp->fullBus(c+4225,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_clpx_shift_ex),2);
        vcdp->fullBus(c+4233,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex),3);
        vcdp->fullBus(c+4241,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_a_ex),32);
        vcdp->fullBus(c+4249,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_b_ex),32);
        vcdp->fullBus(c+4257,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_c_ex),32);
        vcdp->fullBit(c+4265,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_en_ex));
        vcdp->fullBit(c+4273,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_sel_subword_ex));
        vcdp->fullBus(c+4281,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_signed_mode_ex),2);
        vcdp->fullBus(c+4289,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_imm_ex),5);
        vcdp->fullBus(c+4297,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_op_a_ex),32);
        vcdp->fullBus(c+4305,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_op_b_ex),32);
        vcdp->fullBus(c+4313,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_op_c_ex),32);
        vcdp->fullBus(c+4321,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_signed_ex),2);
        vcdp->fullBus(c+4329,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_clpx_shift_ex),2);
        vcdp->fullBit(c+4337,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_clpx_img_ex));
        vcdp->fullBit(c+4345,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_en_ex));
        vcdp->fullBus(c+4353,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_type_ex),2);
        vcdp->fullBus(c+4361,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_flags_ex),15);
        vcdp->fullBus(c+4369,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_op_ex),6);
        vcdp->fullBus(c+4377,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_lat_ex),2);
        vcdp->fullArray(c+4385,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__id_stage_i__apu_operands_ex_o),96);
        vcdp->fullBus(c+4409,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_waddr_ex),6);
        vcdp->fullBus(c+4417,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_waddr_ex),6);
        vcdp->fullBit(c+4425,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_we_ex));
        vcdp->fullBus(c+4433,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__regfile_waddr_lsu),6);
        vcdp->fullBus(c+4441,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_waddr_ex),6);
        vcdp->fullBit(c+4449,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_we_ex));
        vcdp->fullBit(c+4457,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_access_ex));
        vcdp->fullBus(c+4465,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_op_ex),2);
        vcdp->fullBus(c+4473,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mtvec_q),24);
        vcdp->fullBus(c+4481,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mtvecx_q),24);
        vcdp->fullBus(c+4489,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_sign_ext_ex),2);
        vcdp->fullBus(c+4497,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_reg_offset_ex),2);
        vcdp->fullBit(c+4505,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_req_ex));
        vcdp->fullBit(c+4513,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_load_event_ex));
        vcdp->fullBit(c+4521,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mstatus_q) 
                                     >> 5U))));
        vcdp->fullBus(c+4529,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mepc_q),32);
        vcdp->fullBus(c+4537,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__depc_q),32);
        vcdp->fullBit(c+4545,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q));
        vcdp->fullBit(c+4553,((1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__dcsr_q 
                                     >> 2U))));
        vcdp->fullBit(c+4561,((1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__dcsr_q 
                                     >> 0xfU))));
        vcdp->fullBit(c+4569,((1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__dcsr_q 
                                     >> 0xcU))));
        vcdp->fullQuad(c+4577,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_start_q),64);
        vcdp->fullQuad(c+4593,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_end_q),64);
        vcdp->fullQuad(c+4609,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_counter_q),64);
        vcdp->fullBit(c+4625,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__core_busy_q));
        vcdp->fullBit(c+4633,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_is_clpx_ex));
        vcdp->fullBit(c+4641,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__offset_fsm_cs));
        vcdp->fullBit(c+4649,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__is_hwlp_id_q));
        vcdp->fullBus(c+4657,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwlp_dec_cnt_if),2);
        vcdp->fullBus(c+4665,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__CS),3);
        vcdp->fullBus(c+4673,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__hwlp_CS),3);
        vcdp->fullBus(c+4681,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__instr_addr_q),32);
        vcdp->fullBus(c+4689,(((IData)(4U) + (0xfffffffcU 
                                              & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__instr_addr_q))),32);
        vcdp->fullBit(c+4697,((1U & (~ ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_Q) 
                                        >> 1U)))));
        vcdp->fullArray(c+4705,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_Q),128);
        vcdp->fullArray(c+4737,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_Q),128);
        vcdp->fullBus(c+4769,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_Q),4);
        vcdp->fullBus(c+4777,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__is_hwlp_Q),2);
        vcdp->fullBit(c+4785,((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_Q) 
                                >> 3U) & (3U != (3U 
                                                 & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_Q[0U])))));
        vcdp->fullBit(c+4793,((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_Q) 
                                >> 3U) & (3U != (3U 
                                                 & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_Q[1U] 
                                                     << 0x10U) 
                                                    | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_Q[0U] 
                                                       >> 0x10U)))))));
        vcdp->fullBus(c+4801,((0xfffU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                         >> 0x14U))),32);
        vcdp->fullBus(c+4809,(((0xfffff000U & (VL_NEGATE_I((IData)(
                                                                   (1U 
                                                                    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                                       >> 0x1fU)))) 
                                               << 0xcU)) 
                               | ((0xfe0U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                             >> 0x14U)) 
                                  | (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                              >> 7U))))),32);
        vcdp->fullBus(c+4817,(((0xffffff80U & (VL_NEGATE_I((IData)(
                                                                   (1U 
                                                                    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                                       >> 0x1fU)))) 
                                               << 7U)) 
                               | (0x7fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                           >> 0x19U)))),32);
        vcdp->fullBus(c+4825,(((0xffffe000U & (VL_NEGATE_I((IData)(
                                                                   (1U 
                                                                    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                                       >> 0x1fU)))) 
                                               << 0xdU)) 
                               | ((0x1000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                              >> 0x13U)) 
                                  | ((0x800U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                << 4U)) 
                                     | ((0x7e0U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                   >> 0x14U)) 
                                        | (0x1eU & 
                                           (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                            >> 7U))))))),32);
        vcdp->fullBus(c+4833,((0xfffff000U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id)),32);
        vcdp->fullBus(c+4841,(((0xfff00000U & (VL_NEGATE_I((IData)(
                                                                   (1U 
                                                                    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                                       >> 0x1fU)))) 
                                               << 0x14U)) 
                               | ((0xff000U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id) 
                                  | ((0x800U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                >> 9U)) 
                                     | (0x7feU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                  >> 0x14U)))))),32);
        vcdp->fullBus(c+4849,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                        >> 0xfU))),32);
        vcdp->fullBus(c+4857,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                        >> 0x14U))),32);
        vcdp->fullBus(c+4865,(((0xffffffe0U & (VL_NEGATE_I((IData)(
                                                                   (1U 
                                                                    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                                       >> 0x18U)))) 
                                               << 5U)) 
                               | (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                           >> 0x14U)))),32);
        vcdp->fullBus(c+4873,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                        >> 0x19U))),32);
        vcdp->fullBus(c+4881,(((0xffffffc0U & (VL_NEGATE_I((IData)(
                                                                   (1U 
                                                                    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                                       >> 0x18U)))) 
                                               << 6U)) 
                               | ((0x3eU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                            >> 0x13U)) 
                                  | (1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                           >> 0x19U))))),32);
        vcdp->fullBus(c+4889,(((0x3000000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                              >> 3U)) 
                               | ((0x30000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                               >> 7U)) 
                                  | ((0x300U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                >> 0xdU)) 
                                     | ((2U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                               >> 0x13U)) 
                                        | (1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                 >> 0x19U))))))),32);
        vcdp->fullBus(c+4897,(((0x10000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                            >> 4U)) 
                               | (1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                        >> 0x19U)))),32);
        vcdp->fullBus(c+4905,((((IData)(1U) << (0x1fU 
                                                & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                   >> 0x14U))) 
                               - (IData)(1U))),32);
        vcdp->fullBit(c+4913,((1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__int_controller_i__DOT__exc_ctrl_cs))));
        vcdp->fullBit(c+4921,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__int_controller_i__DOT__irq_sec_q));
        vcdp->fullBus(c+4929,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__int_controller_i__DOT__irq_id_q),6);
        vcdp->fullBus(c+4937,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                        >> 0xfU))),6);
        vcdp->fullBus(c+4945,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                        >> 0x14U))),6);
        vcdp->fullBus(c+4953,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                        >> 7U))),6);
        vcdp->fullBus(c+4961,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__mem[
                              (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                        >> 0x14U))]),32);
        vcdp->fullBit(c+4969,((1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                     >> 7U))));
        vcdp->fullBus(c+4977,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__TestReadAddr_Q),6);
        vcdp->fullArray(c+4985,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__mem),1024);
        vcdp->fullBus(c+5241,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs),5);
        vcdp->fullBit(c+5249,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__jump_done_q));
        vcdp->fullBit(c+5257,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__boot_done_q));
        vcdp->fullBit(c+5265,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__data_err_q));
        vcdp->fullBit(c+5273,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_q));
        vcdp->fullBit(c+5281,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__instr_valid_irq_flush_q));
        vcdp->fullBus(c+5289,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__int_controller_i__DOT__exc_ctrl_cs),2);
        vcdp->fullBus(c+5297,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__i),32);
        vcdp->fullBit(c+5305,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__regfile_we_lsu));
        vcdp->fullBus(c+5313,((~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex)),32);
        vcdp->fullBus(c+5321,((~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex)),32);
        vcdp->fullBus(c+5329,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_is_clpx_ex)
                                ? (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_clpx_shift_ex) 
                                    << 0x10U) | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_clpx_shift_ex))
                                : (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_b_ex) 
                                    << 0x18U) | (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_b_ex) 
                                                  << 0x10U) 
                                                 | (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_b_ex) 
                                                     << 8U) 
                                                    | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_b_ex)))))),32);
        vcdp->fullBus(c+5337,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_clpx_shift_ex),16);
        vcdp->fullBus(c+5345,(((0x17U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))
                                ? 0U : (~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex))),32);
        vcdp->fullBit(c+5353,((((((0x10U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
                                  | (0x11U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
                                 | (0x16U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
                                | (0x17U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
                               | (0x47U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)))));
        vcdp->fullBit(c+5361,((0x28U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))));
        vcdp->fullBus(c+5369,(((IData)(0xfffffffeU) 
                               << (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex))),32);
        vcdp->fullBus(c+5377,((3U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex))),2);
        vcdp->fullBit(c+5385,((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))));
        vcdp->fullBit(c+5393,((1U & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex 
                                      >> 0x1fU) & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)))));
        vcdp->fullBus(c+5401,((3U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))),2);
        vcdp->fullBus(c+5409,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResReg_DP),32);
        vcdp->fullBus(c+5417,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AReg_DP),32);
        vcdp->fullBus(c+5425,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BReg_DP),32);
        vcdp->fullBit(c+5433,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__RemSel_SP));
        vcdp->fullBit(c+5441,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__CompInv_SP));
        vcdp->fullBit(c+5449,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResInv_SP));
        vcdp->fullBus(c+5457,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__Cnt_DP),6);
        vcdp->fullBit(c+5465,((1U & (~ (IData)((0U 
                                                != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__Cnt_DP)))))));
        vcdp->fullBus(c+5473,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__State_SP),2);
        vcdp->fullBus(c+5481,(((3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex))
                                ? (0x7fffffffU & (((IData)(1U) 
                                                   << (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_imm_ex)) 
                                                  >> 1U))
                                : 0U)),32);
        vcdp->fullBus(c+5489,(((IData)(1U) << (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_imm_ex))),32);
        vcdp->fullBit(c+5497,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_carry_q));
        vcdp->fullBus(c+5505,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_CS),3);
        vcdp->fullBus(c+5513,((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_a_ex 
                               ^ VL_NEGATE_I((IData)(
                                                     (1U 
                                                      == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex)))))),32);
        vcdp->fullBus(c+5521,((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_b_ex 
                               & VL_NEGATE_I((IData)(
                                                     (1U 
                                                      == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex)))))),32);
        vcdp->fullBus(c+5529,(((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_c_ex 
                                + (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_b_ex 
                                   & VL_NEGATE_I((IData)(
                                                         (1U 
                                                          == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex)))))) 
                               + VL_MULS_III(32,32,32, 
                                             (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_a_ex 
                                              ^ VL_NEGATE_I((IData)(
                                                                    (1U 
                                                                     == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex))))), vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_b_ex))),32);
        vcdp->fullBit(c+5537,((1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex))));
        vcdp->fullBus(c+5545,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_type_q),2);
        vcdp->fullBus(c+5553,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q),2);
        vcdp->fullBus(c+5561,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_sign_ext_q),2);
        vcdp->fullBit(c+5569,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_we_q));
        vcdp->fullBus(c+5577,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS),2);
        vcdp->fullBus(c+5585,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_q),32);
        vcdp->fullBus(c+5593,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__dcsr_q),32);
        vcdp->fullBus(c+5601,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__dscratch0_q),32);
        vcdp->fullBus(c+5609,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__dscratch1_q),32);
        vcdp->fullBus(c+5617,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mscratch_q),32);
        vcdp->fullBus(c+5625,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mstatus_q),7);
        vcdp->fullBus(c+5633,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mcause_q),7);
        vcdp->fullBus(c+5641,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mie_q),19);
        vcdp->fullBus(c+5649,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__miex_q),32);
        vcdp->fullBit(c+5657,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__id_valid_q));
        vcdp->fullBus(c+5665,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCCR_inc_q),12);
        vcdp->fullArray(c+5673,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCCR_q),384);
        vcdp->fullBus(c+5769,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCMR_q),2);
        vcdp->fullBus(c+5777,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCER_q),12);
        vcdp->fullBus(c+5785,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__unnamedblk3__DOT__i),32);
        vcdp->fullBus(c+5793,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__unnamedblk2__DOT__i),32);
        vcdp->fullBus(c+5801,(((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q))
                                ? ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q))
                                    ? ((0xffffff00U 
                                        & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
                                           << 8U)) 
                                       | (0xffU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_q 
                                                   >> 0x18U)))
                                    : ((0xffff0000U 
                                        & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
                                           << 0x10U)) 
                                       | (0xffffU & 
                                          (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_q 
                                           >> 0x10U))))
                                : ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q))
                                    ? ((0xff000000U 
                                        & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
                                           << 0x18U)) 
                                       | (0xffffffU 
                                          & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_q 
                                             >> 8U)))
                                    : vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o))),32);
        vcdp->fullBit(c+5809,(vlSymsp->TOP__top__ram_i.__PVT__instr_rvalid_o));
        vcdp->fullArray(c+5817,(vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o),128);
        vcdp->fullBit(c+5849,(vlSymsp->TOP__top__ram_i.__PVT__data_rvalid_o));
        vcdp->fullBus(c+5857,(vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o),32);
        vcdp->fullBus(c+5865,(vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[0U]),32);
        vcdp->fullBit(c+5873,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_we_ex));
        vcdp->fullBus(c+5881,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_id),32);
        vcdp->fullBus(c+5889,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex),32);
        vcdp->fullBus(c+5897,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_type_ex),2);
        vcdp->fullBit(c+5905,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned_ex));
        vcdp->fullBit(c+5913,(vlTOPp->clk_i));
        vcdp->fullBit(c+5921,(vlTOPp->rstn_i));
        vcdp->fullBit(c+5929,(vlTOPp->irq_i));
        vcdp->fullBus(c+5937,(vlTOPp->irq_id_i),5);
        vcdp->fullBit(c+5945,(vlTOPp->irq_ack_o));
        vcdp->fullBus(c+5953,(vlTOPp->irq_id_o),5);
        vcdp->fullBit(c+5961,(vlTOPp->debug_req_i));
        vcdp->fullBit(c+5969,(vlTOPp->fetch_enable_i));
        vcdp->fullBit(c+5977,(vlTOPp->core_busy_o));
        vcdp->fullBit(c+5985,((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__irq_pending) 
                                | (IData)(vlTOPp->debug_req_i)) 
                               | (IData)(vlSymsp->TOP__top.core_busy_o))));
        vcdp->fullBus(c+5993,(0x16U),32);
        vcdp->fullBus(c+6001,(0x80U),32);
        vcdp->fullBus(c+6009,(0U),32);
        vcdp->fullBus(c+6017,(0x1a110800U),32);
        vcdp->fullBit(c+6025,(1U));
        vcdp->fullBit(c+6033,(0U));
        vcdp->fullBus(c+6041,(0U),4);
        vcdp->fullBus(c+6049,(0U),6);
        vcdp->fullBus(c+6057,(0U),2);
        vcdp->fullBus(c+6065,(0U),15);
        vcdp->fullBus(c+6073,(0U),32);
        vcdp->fullBus(c+6081,(0U),5);
        vcdp->fullBus(c+6089,(0x20U),32);
        vcdp->fullBus(c+6097,(0x10U),32);
        vcdp->fullBus(c+6105,(0U),2);
        vcdp->fullBus(c+6113,(2U),32);
        vcdp->fullBus(c+6121,(1U),32);
        vcdp->fullBit(c+6129,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__lsu_load_err));
        vcdp->fullBit(c+6137,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__lsu_store_err));
        vcdp->fullBit(c+6145,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_is_clpx_ex_o));
        vcdp->fullBus(c+6153,(0U),3);
        vcdp->fullBus(c+6161,(0U),18);
        vcdp->fullBus(c+6169,(0U),12);
        vcdp->fullBus(c+6177,(0U),24);
        vcdp->fullBus(c+6185,(3U),2);
        vcdp->fullBit(c+6193,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__irq_software));
        vcdp->fullBit(c+6201,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__irq_timer));
        vcdp->fullBit(c+6209,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__irq_external));
        vcdp->fullBus(c+6217,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__irq_fast),15);
        vcdp->fullBit(c+6225,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__irq_nmi));
        __Vtemp1[0U] = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q[8U];
        __Vtemp1[1U] = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q[9U];
        __Vtemp1[2U] = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q[0xaU];
        __Vtemp1[3U] = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q[0xbU];
        __Vtemp1[4U] = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q[0xcU];
        __Vtemp1[5U] = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q[0xdU];
        __Vtemp1[6U] = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q[0xeU];
        __Vtemp1[7U] = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q[0xfU];
        __Vtemp1[8U] = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q[0x10U];
        __Vtemp1[9U] = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q[0x11U];
        __Vtemp1[0xaU] = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q[0x12U];
        __Vtemp1[0xbU] = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q[0x13U];
        __Vtemp1[0xcU] = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q[0x14U];
        __Vtemp1[0xdU] = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q[0x15U];
        __Vtemp1[0xeU] = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q[0x16U];
        __Vtemp1[0xfU] = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q[0x17U];
        vcdp->fullArray(c+6233,(__Vtemp1),512);
        __Vtemp2[0U] = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q[0U];
        __Vtemp2[1U] = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q[1U];
        __Vtemp2[2U] = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q[2U];
        __Vtemp2[3U] = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q[3U];
        vcdp->fullArray(c+6361,(__Vtemp2),128);
        vcdp->fullBit(c+6393,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_we_pmp));
        vcdp->fullBus(c+6401,(0x40U),31);
        vcdp->fullBus(c+6409,(4U),32);
        vcdp->fullBus(c+6417,(3U),32);
        vcdp->fullBus(c+6425,(6U),32);
        vcdp->fullBus(c+6433,(0xfU),32);
        vcdp->fullBus(c+6441,(5U),32);
        vcdp->fullBus(c+6449,(0U),3);
        vcdp->fullBus(c+6457,(2U),2);
        vcdp->fullBus(c+6465,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__apu_read_regs),18);
        vcdp->fullBus(c+6473,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__apu_read_regs_valid),3);
        vcdp->fullBus(c+6481,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__apu_write_regs),12);
        vcdp->fullBus(c+6489,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__apu_write_regs_valid),2);
        vcdp->fullBit(c+6497,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__CSN_T));
        vcdp->fullBit(c+6505,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__WEN_T));
        vcdp->fullBus(c+6513,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__A_T),6);
        vcdp->fullBus(c+6521,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__D_T),32);
        vcdp->fullArray(c+6529,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__mem_fp),1024);
        vcdp->fullBus(c+6785,(0x20U),32);
        vcdp->fullBus(c+6793,(6U),4);
        vcdp->fullBus(c+6801,(0U),2);
        vcdp->fullBit(c+6809,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__fpu_valid));
        vcdp->fullBus(c+6817,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__apu_result),32);
        vcdp->fullBit(c+6825,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__apu_req));
        vcdp->fullBit(c+6833,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__apu_ready));
        vcdp->fullBit(c+6841,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__apu_gnt));
        vcdp->fullBus(c+6849,(0xcU),32);
        vcdp->fullBus(c+6857,(1U),2);
        vcdp->fullBus(c+6865,(0x40801104U),32);
        vcdp->fullBus(c+6873,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__frm_q),3);
        vcdp->fullBus(c+6881,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__fflags_q),5);
        vcdp->fullBus(c+6889,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__fprec_q),5);
        vcdp->fullBus(c+6897,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__uepc_n),32);
        vcdp->fullBus(c+6905,(0U),7);
        vcdp->fullBus(c+6913,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__ucause_n),7);
        vcdp->fullBus(c+6921,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__utvec_n),24);
        vcdp->fullBus(c+6929,(3U),2);
        vcdp->fullBus(c+6937,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__priv_lvl_reg_q),2);
        vcdp->fullArray(c+6945,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_q),768);
        vcdp->fullBus(c+7137,(0U),16);
        vcdp->fullBus(c+7145,(0xcU),32);
        vcdp->fullBus(c+7153,(5U),32);
        vcdp->fullBus(c+7161,(3U),32);
        __Vtemp3[0U] = 0x17U;
        __Vtemp3[1U] = 8U;
        __Vtemp3[2U] = 0x34U;
        __Vtemp3[3U] = 0xbU;
        __Vtemp3[4U] = 0xaU;
        __Vtemp3[5U] = 5U;
        __Vtemp3[6U] = 2U;
        __Vtemp3[7U] = 5U;
        __Vtemp3[8U] = 7U;
        __Vtemp3[9U] = 8U;
        vcdp->fullArray(c+7169,(__Vtemp3),320);
        vcdp->fullBus(c+7249,(0x18U),5);
        vcdp->fullBus(c+7257,(4U),32);
        vcdp->fullBus(c+7265,(2U),32);
        vcdp->fullQuad(c+7273,(VL_ULL(0x20383)),43);
        vcdp->fullQuad(c+7289,(VL_ULL(0x20782)),43);
        vcdp->fullQuad(c+7305,(VL_ULL(0x10302)),43);
        vcdp->fullQuad(c+7321,(VL_ULL(0x207ff)),43);
        vcdp->fullQuad(c+7337,(VL_ULL(0x1077e)),43);
        vcdp->fullQuad(c+7353,(VL_ULL(0x10716)),43);
        __Vtemp4[0U] = 0x556aa554U;
        __Vtemp4[1U] = 0x2aaU;
        __Vtemp4[2U] = 0U;
        __Vtemp4[3U] = 0U;
        __Vtemp4[4U] = 0U;
        __Vtemp4[5U] = 0U;
        __Vtemp4[6U] = 0U;
        __Vtemp4[7U] = 0U;
        __Vtemp4[8U] = 0U;
        __Vtemp4[9U] = 0U;
        __Vtemp4[0xaU] = 0U;
        __Vtemp4[0xbU] = 0U;
        __Vtemp4[0xcU] = 0U;
        __Vtemp4[0xdU] = 0U;
        __Vtemp4[0xeU] = 0U;
        __Vtemp4[0xfU] = 0U;
        __Vtemp4[0x10U] = 0U;
        __Vtemp4[0x11U] = 0U;
        __Vtemp4[0x12U] = 0U;
        __Vtemp4[0x13U] = 0U;
        __Vtemp4[0x14U] = 0U;
        __Vtemp4[0x15U] = 0U;
        vcdp->fullArray(c+7369,(__Vtemp4),682);
        __Vtemp5[0U] = 0x55400554U;
        __Vtemp5[1U] = 0x6aaU;
        __Vtemp5[2U] = 0U;
        __Vtemp5[3U] = 0U;
        __Vtemp5[4U] = 0U;
        __Vtemp5[5U] = 0U;
        __Vtemp5[6U] = 0x400U;
        __Vtemp5[7U] = 0U;
        __Vtemp5[8U] = 0U;
        __Vtemp5[9U] = 0U;
        __Vtemp5[0xaU] = 0U;
        __Vtemp5[0xbU] = 0x400U;
        __Vtemp5[0xcU] = 0U;
        __Vtemp5[0xdU] = 0U;
        __Vtemp5[0xeU] = 0U;
        __Vtemp5[0xfU] = 0U;
        __Vtemp5[0x10U] = 0x400U;
        __Vtemp5[0x11U] = 0U;
        __Vtemp5[0x12U] = 0U;
        __Vtemp5[0x13U] = 0U;
        __Vtemp5[0x14U] = 0U;
        __Vtemp5[0x15U] = 0U;
        vcdp->fullArray(c+7545,(__Vtemp5),682);
        vcdp->fullBus(c+7721,(0x14U),32);
        vcdp->fullBus(c+7729,(0x73U),7);
        vcdp->fullBus(c+7737,(0xfU),7);
        vcdp->fullBus(c+7745,(0x33U),7);
        vcdp->fullBus(c+7753,(0x13U),7);
        vcdp->fullBus(c+7761,(0x23U),7);
        vcdp->fullBus(c+7769,(3U),7);
        vcdp->fullBus(c+7777,(0x63U),7);
        vcdp->fullBus(c+7785,(0x67U),7);
        vcdp->fullBus(c+7793,(0x6fU),7);
        vcdp->fullBus(c+7801,(0x17U),7);
        vcdp->fullBus(c+7809,(0x37U),7);
        vcdp->fullBus(c+7817,(0x53U),7);
        vcdp->fullBus(c+7825,(0x43U),7);
        vcdp->fullBus(c+7833,(0x4fU),7);
        vcdp->fullBus(c+7841,(0x47U),7);
        vcdp->fullBus(c+7849,(0x4bU),7);
        vcdp->fullBus(c+7857,(0x27U),7);
        vcdp->fullBus(c+7865,(7U),7);
        vcdp->fullBus(c+7873,(0x2fU),7);
        vcdp->fullBus(c+7881,(0xbU),7);
        vcdp->fullBus(c+7889,(0x2bU),7);
        vcdp->fullBus(c+7897,(0x5bU),7);
        vcdp->fullBus(c+7905,(0x57U),7);
        vcdp->fullBus(c+7913,(0x7bU),7);
        vcdp->fullBus(c+7921,(2U),2);
        vcdp->fullBus(c+7929,(3U),2);
        vcdp->fullBus(c+7937,(0x3bU),7);
        vcdp->fullBus(c+7945,(0x1bU),7);
        vcdp->fullBus(c+7953,(1U),3);
        vcdp->fullBus(c+7961,(2U),3);
        vcdp->fullBus(c+7969,(3U),3);
        vcdp->fullBus(c+7977,(5U),3);
        vcdp->fullBus(c+7985,(6U),3);
        vcdp->fullBus(c+7993,(7U),32);
        vcdp->fullBus(c+8001,(0x18U),7);
        vcdp->fullBus(c+8009,(0x19U),7);
        vcdp->fullBus(c+8017,(0x1aU),7);
        vcdp->fullBus(c+8025,(0x1cU),7);
        vcdp->fullBus(c+8033,(0x1dU),7);
        vcdp->fullBus(c+8041,(0x1eU),7);
        vcdp->fullBus(c+8049,(0x1fU),7);
        vcdp->fullBus(c+8057,(0x2eU),7);
        vcdp->fullBus(c+8065,(0x15U),7);
        vcdp->fullBus(c+8073,(0x24U),7);
        vcdp->fullBus(c+8081,(0x25U),7);
        vcdp->fullBus(c+8089,(0x26U),7);
        vcdp->fullBus(c+8097,(0x28U),7);
        vcdp->fullBus(c+8105,(0x29U),7);
        vcdp->fullBus(c+8113,(0x2aU),7);
        vcdp->fullBus(c+8121,(0x2cU),7);
        vcdp->fullBus(c+8129,(0x49U),7);
        vcdp->fullBus(c+8137,(0x36U),7);
        vcdp->fullBus(c+8145,(0x34U),7);
        vcdp->fullBus(c+8153,(0x35U),7);
        vcdp->fullBus(c+8161,(0x3eU),7);
        vcdp->fullBus(c+8169,(0x3fU),7);
        vcdp->fullBus(c+8177,(1U),7);
        vcdp->fullBus(c+8185,(4U),7);
        vcdp->fullBus(c+8193,(5U),7);
        vcdp->fullBus(c+8201,(8U),7);
        vcdp->fullBus(c+8209,(9U),7);
        vcdp->fullBus(c+8217,(0xaU),7);
        vcdp->fullBus(c+8225,(0xcU),7);
        vcdp->fullBus(c+8233,(0xdU),7);
        vcdp->fullBus(c+8241,(2U),7);
        vcdp->fullBus(c+8249,(6U),7);
        vcdp->fullBus(c+8257,(0x14U),7);
        vcdp->fullBus(c+8265,(0x16U),7);
        vcdp->fullBus(c+8273,(0x2dU),7);
        vcdp->fullBus(c+8281,(0x10U),7);
        vcdp->fullBus(c+8289,(0x11U),7);
        vcdp->fullBus(c+8297,(0x12U),7);
        vcdp->fullBus(c+8305,(0x30U),7);
        vcdp->fullBus(c+8313,(0x31U),7);
        vcdp->fullBus(c+8321,(0x32U),7);
        vcdp->fullBus(c+8329,(0x3aU),7);
        vcdp->fullBus(c+8337,(0x38U),7);
        vcdp->fullBus(c+8345,(0x39U),7);
        vcdp->fullBus(c+8353,(0x7fU),7);
        vcdp->fullBus(c+8361,(0x40U),7);
        vcdp->fullBus(c+8369,(0x41U),7);
        vcdp->fullBus(c+8377,(0x42U),7);
        vcdp->fullBus(c+8385,(0x44U),7);
        vcdp->fullBus(c+8393,(0x45U),7);
        vcdp->fullBus(c+8401,(0x46U),7);
        vcdp->fullBus(c+8409,(0x48U),7);
        vcdp->fullBus(c+8417,(4U),3);
        vcdp->fullBus(c+8425,(7U),32);
        vcdp->fullBus(c+8433,(0xbU),32);
        vcdp->fullBus(c+8441,(0x10U),32);
        vcdp->fullBus(c+8449,(0x1eU),32);
        vcdp->fullBus(c+8457,(0x1fU),32);
        vcdp->fullBus(c+8465,(0x3000U),16);
        vcdp->fullBus(c+8473,(0x3008U),16);
        vcdp->fullBus(c+8481,(0x3010U),16);
        vcdp->fullBus(c+8489,(0x3011U),16);
        vcdp->fullBus(c+8497,(0U),8);
        vcdp->fullBus(c+8505,(1U),8);
        vcdp->fullBus(c+8513,(2U),8);
        vcdp->fullBus(c+8521,(4U),8);
        vcdp->fullBit(c+8529,(0U));
        vcdp->fullBit(c+8537,(1U));
        vcdp->fullBus(c+8545,(1U),4);
        vcdp->fullBus(c+8553,(2U),4);
        vcdp->fullBus(c+8561,(3U),4);
        vcdp->fullBus(c+8569,(4U),4);
        vcdp->fullBus(c+8577,(5U),4);
        vcdp->fullBus(c+8585,(6U),4);
        vcdp->fullBus(c+8593,(7U),4);
        vcdp->fullBus(c+8601,(8U),4);
        vcdp->fullBus(c+8609,(9U),4);
        vcdp->fullBus(c+8617,(0xbU),4);
        vcdp->fullBus(c+8625,(0xcU),4);
        vcdp->fullBus(c+8633,(2U),5);
        vcdp->fullBus(c+8641,(3U),5);
        vcdp->fullBus(c+8649,(1U),5);
        vcdp->fullBus(c+8657,(4U),5);
        vcdp->fullBus(c+8665,(0xcU),5);
        vcdp->fullBus(c+8673,(8U),5);
        vcdp->fullBus(c+8681,(0x10U),5);
        vcdp->fullBus(c+8689,(0x14U),5);
        vcdp->fullBus(c+8697,(0x18U),5);
        vcdp->fullBus(c+8705,(0x1cU),5);
        vcdp->fullBus(c+8713,(7U),3);
        vcdp->fullBus(c+8721,(1U),6);
        vcdp->fullBus(c+8729,(2U),6);
        vcdp->fullBus(c+8737,(3U),6);
        vcdp->fullBus(c+8745,(5U),6);
        vcdp->fullBus(c+8753,(7U),6);
        vcdp->fullBus(c+8761,(8U),6);
        vcdp->fullBus(c+8769,(0xbU),6);
        vcdp->fullBus(c+8777,(6U),32);
        vcdp->fullBus(c+8785,(0x33U),32);
        vcdp->fullBus(c+8793,(0x1fU),6);
        vcdp->fullBit(c+8801,(1U));
        vcdp->fullBit(c+8809,(0U));
        vcdp->fullBus(c+8817,(4U),32);
        vcdp->fullBus(c+8825,(3U),32);
        vcdp->fullBus(c+8833,(2U),32);
        vcdp->fullBus(c+8841,(0U),32);
        vcdp->fullBus(c+8849,(1U),32);
        vcdp->fullBus(c+8857,(0x7c0U),12);
        vcdp->fullBus(c+8865,(0x7c1U),12);
        vcdp->fullBus(c+8873,(0x7c2U),12);
        vcdp->fullBus(c+8881,(0x7c4U),12);
        vcdp->fullBus(c+8889,(0x7c5U),12);
        vcdp->fullBus(c+8897,(0x7c6U),12);
        vcdp->fullBus(c+8905,(0xcc0U),12);
        vcdp->fullBus(c+8913,(0xcc1U),12);
        vcdp->fullBus(c+8921,(0x7e0U),12);
        vcdp->fullBus(c+8929,(0x7e1U),12);
        vcdp->fullBus(c+8937,(0xfU),4);
        vcdp->fullBus(c+8945,(0x100000U),32);
    }
}
