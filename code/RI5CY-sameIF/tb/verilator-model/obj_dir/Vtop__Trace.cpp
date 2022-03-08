// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t = (Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vtop::traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
                                | (vlTOPp->__Vm_traceActivity 
                                   >> 1U)) | (vlTOPp->__Vm_traceActivity 
                                              >> 2U))))) {
            vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (((vlTOPp->__Vm_traceActivity 
                                 | (vlTOPp->__Vm_traceActivity 
                                    >> 1U)) | (vlTOPp->__Vm_traceActivity 
                                               >> 2U)) 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 3U))))) {
            vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (((vlTOPp->__Vm_traceActivity 
                                 | (vlTOPp->__Vm_traceActivity 
                                    >> 1U)) | (vlTOPp->__Vm_traceActivity 
                                               >> 2U)) 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 4U))))) {
            vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
                                | (vlTOPp->__Vm_traceActivity 
                                   >> 1U)) | (vlTOPp->__Vm_traceActivity 
                                              >> 4U))))) {
            vlTOPp->traceChgThis__7(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 2U))))) {
            vlTOPp->traceChgThis__8(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 4U))))) {
            vlTOPp->traceChgThis__9(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__10(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
                                >> 2U) | (vlTOPp->__Vm_traceActivity 
                                          >> 3U))))) {
            vlTOPp->traceChgThis__11(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((8U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__12(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((0x10U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__13(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__14(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgArray(c+1,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__ex_stage_i__apu_master_operands_o),96);
        vcdp->chgArray(c+25,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__apu_operands),96);
        vcdp->chgArray(c+49,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_lut),160);
        vcdp->chgBus(c+89,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mip),19);
        vcdp->chgArray(c+97,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pmp_reg_n),768);
        vcdp->chgBus(c+289,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__irq_req),19);
    }
}

void Vtop::traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+297,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_req_pmp));
        vcdp->chgBus(c+305,((0x3fffffU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp)),22);
        vcdp->chgBit(c+313,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_req_pmp));
        vcdp->chgBus(c+321,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp),32);
        vcdp->chgBit(c+329,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__clear_instr_valid));
        vcdp->chgBit(c+337,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_set));
        vcdp->chgBus(c+345,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id),3);
        vcdp->chgBus(c+353,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_wdata_fw),32);
        vcdp->chgBit(c+361,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__halt_if));
        vcdp->chgBit(c+369,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_ready));
        vcdp->chgBit(c+377,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_ready));
        vcdp->chgBit(c+385,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_valid));
        vcdp->chgBit(c+393,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_valid));
        vcdp->chgBit(c+401,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__lsu_ready_wb));
        vcdp->chgBit(c+409,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__lsu_ready_ex));
        vcdp->chgBit(c+417,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_save_cause));
        vcdp->chgBit(c+425,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_save_id));
        vcdp->chgBus(c+433,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_cause),7);
        vcdp->chgBus(c+441,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_cause),3);
        vcdp->chgBit(c+449,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__debug_csr_save));
        vcdp->chgBit(c+457,((1U & ((~ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_valid)) 
                                   | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__branch_req)))));
        vcdp->chgBit(c+465,(((1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_in_id)) 
                             | (2U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_in_id)))));
        vcdp->chgBit(c+473,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__load_stall));
        vcdp->chgBit(c+481,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__offset_fsm_ns));
        vcdp->chgBit(c+489,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__if_valid));
        vcdp->chgBit(c+497,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__valid) 
                             & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_ready))));
        vcdp->chgBit(c+505,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__valid));
        vcdp->chgBit(c+513,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__branch_req));
        vcdp->chgBit(c+521,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_valid));
        vcdp->chgBit(c+529,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_ready));
        vcdp->chgBus(c+537,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_rdata),32);
        vcdp->chgBit(c+545,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_failed));
        vcdp->chgBus(c+553,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__instr_decompressed),32);
        vcdp->chgBit(c+561,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__illegal_c_insn));
        vcdp->chgBit(c+569,((3U != (3U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_rdata))));
        vcdp->chgBus(c+577,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__NS),3);
        vcdp->chgBus(c+585,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__hwlp_NS),3);
        vcdp->chgBit(c+593,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fetch_is_hwlp));
        vcdp->chgBit(c+601,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__addr_valid));
        vcdp->chgBit(c+609,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_valid));
        vcdp->chgBit(c+617,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_clear));
        vcdp->chgBit(c+625,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__hwloop_speculative));
        vcdp->chgBit(c+633,((3U != (3U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
                                          >> 0x10U)))));
        vcdp->chgArray(c+641,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_n),128);
        vcdp->chgArray(c+673,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_int),128);
        vcdp->chgArray(c+705,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_n),128);
        vcdp->chgArray(c+737,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_int),128);
        vcdp->chgBus(c+769,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_n),4);
        vcdp->chgBus(c+777,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_int),4);
        vcdp->chgBus(c+785,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__is_hwlp_n),2);
        vcdp->chgBus(c+793,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__is_hwlp_int),2);
        vcdp->chgBus(c+801,(((IData)(4U) + (0xfffffffcU 
                                            & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_int[0U]))),32);
        vcdp->chgBus(c+809,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata),32);
        vcdp->chgBit(c+817,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid));
        vcdp->chgBit(c+825,((3U != (3U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata))));
        vcdp->chgBus(c+833,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unnamedblk1__DOT__j),32);
        vcdp->chgBus(c+841,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unnamedblk2__DOT__i),32);
        vcdp->chgBus(c+849,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unnamedblk3__DOT__i),32);
        vcdp->chgBus(c+857,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__unnamedblk4__DOT__i),32);
        vcdp->chgBit(c+865,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__deassert_we));
        vcdp->chgBus(c+873,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_in_id),2);
        vcdp->chgBit(c+881,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_mask));
        vcdp->chgBit(c+889,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__halt_id));
        vcdp->chgBit(c+897,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__exc_kill));
        vcdp->chgBit(c+905,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_alu_we_id));
        vcdp->chgBit(c+913,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_int_en) 
                             | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_dot_en))));
        vcdp->chgBit(c+921,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_int_en));
        vcdp->chgBit(c+929,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_dot_en));
        vcdp->chgBit(c+937,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_we_id));
        vcdp->chgBit(c+945,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__data_req_id));
        vcdp->chgBit(c+953,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regid));
        vcdp->chgBus(c+961,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_we),3);
        vcdp->chgBus(c+969,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_we_masked),3);
        vcdp->chgBus(c+977,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_cnt),32);
        vcdp->chgBus(c+985,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_cnt_int),32);
        vcdp->chgBit(c+993,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_valid));
        vcdp->chgBus(c+1001,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_a_fw_id),32);
        vcdp->chgBus(c+1009,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b_fw_id),32);
        vcdp->chgBus(c+1017,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c_fw_id),32);
        vcdp->chgBus(c+1025,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b),32);
        vcdp->chgBus(c+1033,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b_vec),32);
        vcdp->chgBus(c+1041,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c),32);
        vcdp->chgBus(c+1049,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_operand_a),32);
        vcdp->chgBus(c+1057,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_operand_b),32);
        vcdp->chgBus(c+1065,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_ns),5);
        vcdp->chgBit(c+1073,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__jump_done));
        vcdp->chgBit(c+1081,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__jump_in_dec));
        vcdp->chgBit(c+1089,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__branch_in_id));
        vcdp->chgBit(c+1097,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__irq_enable_int));
        vcdp->chgBit(c+1105,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__ebrk_force_debug_mode));
        vcdp->chgBit(c+1113,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_n));
        vcdp->chgBit(c+1121,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__instr_valid_irq_flush_n));
        vcdp->chgBus(c+1129,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_result),32);
        vcdp->chgBus(c+1137,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_result),32);
        vcdp->chgBit(c+1145,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__div_ready));
        vcdp->chgBus(c+1153,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__div_shift),6);
        vcdp->chgBus(c+1161,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_amt_left),32);
        vcdp->chgBus(c+1169,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_amt),32);
        vcdp->chgBus(c+1177,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_amt_int),32);
        vcdp->chgBus(c+1185,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_result),32);
        vcdp->chgBus(c+1193,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_right_result),32);
        vcdp->chgBus(c+1201,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_left_result),32);
        vcdp->chgBus(c+1209,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bitop_result),6);
        vcdp->chgBus(c+1217,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bextins_result),32);
        vcdp->chgBus(c+1225,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__radix_2_rev),32);
        vcdp->chgBus(c+1233,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__radix_4_rev),32);
        vcdp->chgBus(c+1241,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__radix_8_rev),32);
        vcdp->chgBus(c+1249,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddMux_D),32);
        vcdp->chgBus(c+1257,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddTmp_D),32);
        vcdp->chgBit(c+1265,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ARegEn_S));
        vcdp->chgBit(c+1273,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BRegEn_S));
        vcdp->chgBit(c+1281,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResRegEn_S));
        vcdp->chgBit(c+1289,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S));
        vcdp->chgBus(c+1297,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__State_SN),2);
        vcdp->chgQuad(c+1305,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_mac),34);
        vcdp->chgQuad(c+1321,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_result),34);
        vcdp->chgBus(c+1337,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_NS),3);
        vcdp->chgBus(c+1345,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__NS),2);
        vcdp->chgBus(c+1353,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mepc_n),32);
        vcdp->chgBus(c+1361,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__dcsr_n),32);
        vcdp->chgBus(c+1369,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__depc_n),32);
        vcdp->chgBus(c+1377,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__exception_pc),32);
        vcdp->chgBus(c+1385,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mstatus_n),7);
        vcdp->chgBus(c+1393,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mcause_n),7);
        vcdp->chgBit(c+1401,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_cause) 
                                    >> 6U))));
        vcdp->chgBus(c+1409,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__priv_lvl_n),2);
        vcdp->chgBus(c+1417,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCCR_inc),12);
        vcdp->chgBus(c+1425,((0xfffffU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp)),20);
    }
}

void Vtop::traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1433,(((0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__CS)) 
                              | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_req_pmp))));
        vcdp->chgBit(c+1441,(((((1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS)) 
                                | (2U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS))) 
                               | (3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS))) 
                              | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_req_pmp))));
        vcdp->chgBit(c+1449,(((((0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__CS)) 
                                | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_req_pmp)) 
                               | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ctrl_busy)) 
                              | ((((1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS)) 
                                   | (2U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS))) 
                                  | (3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS))) 
                                 | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_req_pmp)))));
        vcdp->chgBit(c+1457,((1U & (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_Q) 
                                     >> 2U) | (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_Q) 
                                                >> 3U) 
                                               & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_valid))))));
        vcdp->chgBus(c+1465,(((0xfffffff8U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c_fw_id 
                                              << 3U)) 
                              | (7U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                       >> 0xcU)))),32);
        vcdp->chgBus(c+1473,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__deassert_we)
                               ? 0U : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__hwloop_we))),3);
        vcdp->chgBus(c+1481,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__deassert_we)
                               ? 0U : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__csr_op))),2);
        vcdp->chgBus(c+1489,(((3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_vec_mode))
                               ? ((0xff000000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c 
                                                  << 0x18U)) 
                                  | ((0xff0000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c 
                                                   << 0x10U)) 
                                     | ((0xff00U & 
                                         (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c 
                                          << 8U)) | 
                                        (0xffU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c))))
                               : ((0xffff0000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c 
                                                  << 0x10U)) 
                                  | (0xffffU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c)))),32);
        vcdp->chgBus(c+1497,((0x1fU & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_a_mux_sel)
                                        ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_a_id_imm)
                                        : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_a_mux_sel)
                                            ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_a_id_imm)
                                            : (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b_fw_id 
                                               >> 5U))))),5);
        vcdp->chgBus(c+1505,((0x1fU & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_b_mux_sel)
                                        ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_b_id_imm)
                                        : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_b_mux_sel)
                                            ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_b_id_imm)
                                            : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b_fw_id)))),5);
        vcdp->chgBus(c+1513,((0x3fU & ((0x1fU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0U]) 
                                       - (IData)(1U)))),6);
        vcdp->chgBus(c+1521,((0x1fU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0U])),5);
        vcdp->chgBit(c+1529,((1U & (~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__sel_nodes))));
        vcdp->chgBus(c+1537,((0x1fU & ((IData)(0x1fU) 
                                       - vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0U]))),5);
        vcdp->chgBit(c+1545,(((0x28U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
                              & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_result 
                                 >> (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex)))));
        vcdp->chgBus(c+1553,(((0U == (3U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex)))
                               ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__radix_2_rev
                               : ((1U == (3U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex)))
                                   ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__radix_4_rev
                                   : ((2U == (3U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex)))
                                       ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__radix_8_rev
                                       : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__radix_2_rev)))),32);
        vcdp->chgBus(c+1561,(((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__sel_nodes)
                               ? (0x3fU & ((0x1fU & 
                                            vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0U]) 
                                           - (IData)(1U)))
                               : 0x1fU)),6);
        vcdp->chgBus(c+1569,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__sel_nodes),32);
        vcdp->chgArray(c+1577,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes),160);
        vcdp->chgBus(c+1617,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
                               ? 0U : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResRegEn_S)
                                        ? (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ABComp_S) 
                                            << 0x1fU) 
                                           | (0x7fffffffU 
                                              & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResReg_DP 
                                                 >> 1U)))
                                        : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResReg_DP))),32);
        vcdp->chgBus(c+1625,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ARegEn_S)
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
        vcdp->chgBus(c+1633,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BRegEn_S)
                               ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
                                   ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_left_result
                                   : (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__CompInv_SP) 
                                       << 0x1fU) | 
                                      (0x7fffffffU 
                                       & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BReg_DP 
                                          >> 1U))))
                               : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BReg_DP)),32);
        vcdp->chgBit(c+1641,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
                                     ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex) 
                                        >> 1U) : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__RemSel_SP)))));
        vcdp->chgBit(c+1649,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
                               ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed)
                               : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__CompInv_SP))));
        vcdp->chgBit(c+1657,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
                                     ? ((((0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cnt_result)) 
                                          | ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex) 
                                             >> 1U)) 
                                         & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
                                        & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex 
                                            >> 0x1fU) 
                                           ^ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed)))
                                     : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResInv_SP)))));
        vcdp->chgBus(c+1665,((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S) 
                               & (~ ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex) 
                                     & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex 
                                         >> 0x1fU) 
                                        ^ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed)))))
                               ? (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddTmp_D 
                                  + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddMux_D)
                               : (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddTmp_D 
                                  - vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AddMux_D))),32);
        vcdp->chgBus(c+1673,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
                               ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_left_result
                               : (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__CompInv_SP) 
                                   << 0x1fU) | (0x7fffffffU 
                                                & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BReg_DP 
                                                   >> 1U))))),32);
        vcdp->chgBus(c+1681,((0x3fU & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S)
                                        ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__div_shift)
                                        : ((0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__Cnt_DP))
                                            ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__Cnt_DP) 
                                               - (IData)(1U))
                                            : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__Cnt_DP))))),6);
        vcdp->chgBit(c+1689,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__LoadEn_S) 
                              & (~ ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex) 
                                    & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex 
                                        >> 0x1fU) ^ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed)))))));
        vcdp->chgBus(c+1697,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_a),17);
        vcdp->chgBus(c+1705,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_b),17);
        vcdp->chgQuad(c+1713,((VL_ULL(0x3ffffffff) 
                               & VL_MULS_QQQ(34,34,34, 
                                             (VL_ULL(0x3ffffffff) 
                                              & VL_EXTENDS_QI(34,17, vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_a)), 
                                             (VL_ULL(0x3ffffffff) 
                                              & VL_EXTENDS_QI(34,17, vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_b))))),34);
        vcdp->chgBit(c+1729,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_active)
                                     ? (IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_mac 
                                                >> 0x21U))
                                     : (IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_mac 
                                                >> 0x1fU))))));
        vcdp->chgBit(c+1737,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_active)
                                     ? (IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_mac 
                                                >> 0x20U))
                                     : (IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_mac 
                                                >> 0x1fU))))));
    }
}

void Vtop::traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1745,(((4U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_Q))
                               ? ((0xffff0000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_Q[1U] 
                                                  << 0x10U)) 
                                  | (0xffffU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
                                                >> 0x10U)))
                               : ((0xffff0000U & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[0U] 
                                                  << 0x10U)) 
                                  | (0xffffU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata 
                                                >> 0x10U))))),32);
    }
}

void Vtop::traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1753,(((4U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id))
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
        vcdp->chgBus(c+1761,((0xfffffffeU & ((4U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id))
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
        vcdp->chgBus(c+1769,(((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_we_masked))
                               ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_start_int
                               : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__csr_wdata_int)),32);
        vcdp->chgBus(c+1777,(((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_we_masked))
                               ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_target
                               : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__csr_wdata_int)),32);
        vcdp->chgBus(c+1785,(((0x2aU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))
                               ? vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex
                               : VL_NEGATE_I((IData)(
                                                     ((0x28U 
                                                       == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
                                                      & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_result 
                                                         >> (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex))))))),32);
        vcdp->chgBus(c+1793,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCCR_in),12);
    }
}

void Vtop::traceChgThis__7(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1801,(((4U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_mux_id)) 
                              & (1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__exc_pc_mux_id)))));
        vcdp->chgBit(c+1809,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_req_pmp) 
                              & (~ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_we_ex)))));
        vcdp->chgBit(c+1817,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_req_pmp) 
                              & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_we_ex))));
    }
}

void Vtop::traceChgThis__8(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1825,(vlSymsp->TOP__top.irq_ack_o));
        vcdp->chgBit(c+1833,(vlSymsp->TOP__top.core_busy_o));
        vcdp->chgBit(c+1841,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__is_hwlp_id));
        vcdp->chgBit(c+1849,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cmp_result) 
                                    >> 3U))));
        vcdp->chgBit(c+1857,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ctrl_busy));
        vcdp->chgBit(c+1865,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_we_wb));
        vcdp->chgBit(c+1873,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_we_fw));
        vcdp->chgBus(c+1881,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_addr_int),12);
        vcdp->chgBus(c+1889,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_rdata),32);
        vcdp->chgBit(c+1897,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_req_int));
        vcdp->chgBit(c+1905,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_irq_sec));
        vcdp->chgBit(c+1913,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_hwlp_regid));
        vcdp->chgBus(c+1921,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_hwlp_we),3);
        vcdp->chgBus(c+1929,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__csr_wdata_int),32);
        vcdp->chgBit(c+1937,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jr_stall));
        vcdp->chgBit(c+1945,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__core_ctrl_firstfetch));
        vcdp->chgBit(c+1953,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__irq_pending));
        vcdp->chgBus(c+1961,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__irq_id),6);
        vcdp->chgBit(c+1969,((1U & (~ (IData)(vlSymsp->TOP__top.core_busy_o)))));
        vcdp->chgBit(c+1977,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_is_hwlp));
        vcdp->chgBit(c+1985,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__hwlp_branch));
        vcdp->chgBus(c+1993,(vlSymsp->TOP__top.riscv_core_i__DOT__if_stage_i__DOT____Vcellinp__hwloop_controller_i__hwlp_dec_cnt_id_i),2);
        vcdp->chgBit(c+2001,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_hwlp));
        vcdp->chgBit(c+2009,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__ebrk_insn));
        vcdp->chgBit(c+2017,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mret_insn_dec));
        vcdp->chgBit(c+2025,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__uret_insn_dec));
        vcdp->chgBit(c+2033,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__dret_insn_dec));
        vcdp->chgBit(c+2041,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__ecall_insn_dec));
        vcdp->chgBit(c+2049,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__pipe_flush_dec));
        vcdp->chgBit(c+2057,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__fencei_insn_dec));
        vcdp->chgBit(c+2065,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__rega_used_dec));
        vcdp->chgBit(c+2073,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regb_used_dec));
        vcdp->chgBit(c+2081,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regc_used_dec));
        vcdp->chgBus(c+2089,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__jump_in_id),2);
        vcdp->chgBit(c+2097,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__csr_access) 
                              & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_en_ex) 
                                 & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_lat_ex) 
                                    >> 1U)))));
        vcdp->chgBit(c+2105,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__instr_multicycle));
        vcdp->chgBus(c+2113,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_i_type),32);
        vcdp->chgBus(c+2121,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_vu_type),32);
        vcdp->chgBus(c+2129,(((3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_vec_mode))
                               ? ((0x3000000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                 >> 3U)) 
                                  | ((0x30000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                  >> 7U)) 
                                     | ((0x300U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
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
        vcdp->chgBus(c+2137,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_a_mux_sel)
                               ? 0U : (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                >> 0xfU)))),32);
        vcdp->chgBit(c+2145,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__exc_ack));
        vcdp->chgBus(c+2153,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id),6);
        vcdp->chgBus(c+2161,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_alu_waddr_id),6);
        vcdp->chgBus(c+2169,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_data_ra_id),32);
        vcdp->chgBus(c+2177,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__mem[
                             (0x1fU & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id))]),32);
        vcdp->chgBus(c+2185,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_operator),7);
        vcdp->chgBus(c+2193,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regc_mux),2);
        vcdp->chgBit(c+2201,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_a_mux_sel));
        vcdp->chgBus(c+2209,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_target_mux_sel),2);
        vcdp->chgBus(c+2217,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_operator),3);
        vcdp->chgBit(c+2225,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_sel_subword));
        vcdp->chgBus(c+2233,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_signed_mode),2);
        vcdp->chgBus(c+2241,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_dot_signed),2);
        vcdp->chgBit(c+2249,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_alu_waddr_mux_sel));
        vcdp->chgBus(c+2257,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__data_sign_ext_id),2);
        vcdp->chgBit(c+2265,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__data_load_event_id));
        vcdp->chgBit(c+2273,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_target_mux_sel));
        vcdp->chgBit(c+2281,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_start_mux_sel));
        vcdp->chgBit(c+2289,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_cnt_mux_sel));
        vcdp->chgBit(c+2297,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__csr_access));
        vcdp->chgBit(c+2305,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_a_mux));
        vcdp->chgBus(c+2313,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_b_mux),2);
        vcdp->chgBit(c+2321,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_a_mux_sel));
        vcdp->chgBit(c+2329,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_bmask_b_mux_sel));
        vcdp->chgBit(c+2337,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_imm_mux));
        vcdp->chgBus(c+2345,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_a_id_imm),5);
        vcdp->chgBus(c+2353,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__bmask_b_id_imm),5);
        vcdp->chgBus(c+2361,((3U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_vu_type)),2);
        vcdp->chgBus(c+2369,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_imm_mux)
                               ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mult_imm_mux)
                                   ? (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                               >> 0x19U))
                                   : 0U) : 0U)),5);
        vcdp->chgBus(c+2377,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_vec_mode),2);
        vcdp->chgBit(c+2385,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__reg_d_ex_is_reg_a_id));
        vcdp->chgBit(c+2393,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__reg_d_ex_is_reg_b_id));
        vcdp->chgBit(c+2401,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__reg_d_ex_is_reg_c_id));
        vcdp->chgBit(c+2409,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__reg_d_wb_is_reg_a_id));
        vcdp->chgBit(c+2417,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__regfile_waddr_lsu) 
                                == (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                             >> 0x14U))) 
                               & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regb_used_dec)) 
                              & (0U != (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                 >> 0x14U))))));
        vcdp->chgBit(c+2425,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__regfile_waddr_lsu) 
                                == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id)) 
                               & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regc_used_dec)) 
                              & (0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id)))));
        vcdp->chgBit(c+2433,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__reg_d_alu_is_reg_a_id));
        vcdp->chgBit(c+2441,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_waddr_ex) 
                                == (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                             >> 0x14U))) 
                               & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regb_used_dec)) 
                              & (0U != (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                 >> 0x14U))))));
        vcdp->chgBit(c+2449,(((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_waddr_ex) 
                                == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id)) 
                               & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regc_used_dec)) 
                              & (0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__regfile_addr_rc_id)))));
        vcdp->chgBit(c+2457,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__is_clpx));
        vcdp->chgBit(c+2465,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__is_subrot));
        vcdp->chgBit(c+2473,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__mret_dec));
        vcdp->chgBit(c+2481,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__uret_dec));
        vcdp->chgBit(c+2489,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__dret_dec));
        vcdp->chgBus(c+2497,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__we_a_dec),32);
        vcdp->chgBus(c+2505,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__we_b_dec),32);
        vcdp->chgBit(c+2513,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__regfile_mem_we));
        vcdp->chgBit(c+2521,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__data_req));
        vcdp->chgBus(c+2529,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__hwloop_we),3);
        vcdp->chgBus(c+2537,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__csr_op),2);
        vcdp->chgBit(c+2545,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__mult_int_en));
        vcdp->chgBit(c+2553,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__mult_dot_en));
        vcdp->chgBit(c+2561,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__boot_done));
        vcdp->chgBit(c+2569,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_n));
        vcdp->chgQuad(c+2577,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_counter_n),64);
        vcdp->chgBit(c+2593,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_ready));
        vcdp->chgBus(c+2601,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__operand_a_rev),32);
        vcdp->chgBus(c+2609,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__operand_a_neg_rev),32);
        vcdp->chgBit(c+2617,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__div_valid));
        vcdp->chgBus(c+2625,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask),32);
        vcdp->chgBit(c+2633,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_op_b_negate));
        vcdp->chgBus(c+2641,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_op_a),32);
        vcdp->chgBus(c+2649,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_op_b),32);
        vcdp->chgQuad(c+2657,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_in_a),36);
        vcdp->chgQuad(c+2673,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_in_b),36);
        vcdp->chgBus(c+2689,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_result),32);
        vcdp->chgQuad(c+2697,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_result_expanded),37);
        vcdp->chgBus(c+2713,((((((0x1cU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
                                 | (0x1dU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
                                | (0x1eU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
                               | (0x1fU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)))
                               ? (0x7fffffffU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask 
                                                 >> 1U))
                               : 0U)),32);
        vcdp->chgBus(c+2721,((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_result 
                              + (((((0x1cU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
                                    | (0x1dU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
                                   | (0x1eU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
                                  | (0x1fU == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)))
                                  ? (0x7fffffffU & 
                                     (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask 
                                      >> 1U)) : 0U))),32);
        vcdp->chgBit(c+2729,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_left));
        vcdp->chgBit(c+2737,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_use_round));
        vcdp->chgBit(c+2745,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_arithmetic));
        vcdp->chgBus(c+2753,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_op_a),32);
        vcdp->chgQuad(c+2761,(((0x26U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))
                                ? (((QData)((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_op_a)) 
                                    << 0x20U) | (QData)((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_op_a)))
                                : (((QData)((IData)(
                                                    VL_NEGATE_I((IData)(
                                                                        ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_arithmetic) 
                                                                         & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_op_a 
                                                                            >> 0x1fU)))))) 
                                    << 0x20U) | (QData)((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shift_op_a))))),64);
        vcdp->chgBus(c+2777,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_equal),4);
        vcdp->chgBus(c+2785,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_greater),4);
        vcdp->chgBus(c+2793,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__f_is_greater),4);
        vcdp->chgBus(c+2801,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cmp_signed),4);
        vcdp->chgBus(c+2809,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_equal_vec),4);
        vcdp->chgBus(c+2817,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_greater_vec),4);
        vcdp->chgBit(c+2825,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_equal_clip));
        vcdp->chgBus(c+2833,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cmp_result),4);
        vcdp->chgBus(c+2841,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__f_is_nan),4);
        vcdp->chgBus(c+2849,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__result_minmax),32);
        vcdp->chgBus(c+2857,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__sel_minmax),4);
        vcdp->chgBus(c+2865,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__minmax_b),32);
        vcdp->chgBus(c+2873,(((0x17U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))
                               ? ((1U & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex 
                                          >> 0x1fU) 
                                         | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_equal_clip)))
                                   ? 0U : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__result_minmax)
                               : ((1U & ((IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__adder_result_expanded 
                                                  >> 0x24U)) 
                                         | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__is_equal_clip)))
                                   ? (~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex)
                                   : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__result_minmax))),32);
        vcdp->chgBus(c+2881,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_byte_sel),8);
        vcdp->chgBus(c+2889,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_reg_sel),4);
        vcdp->chgBus(c+2897,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_reg1_sel),2);
        vcdp->chgBus(c+2905,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_reg0_sel),2);
        vcdp->chgBus(c+2913,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_through),4);
        vcdp->chgBus(c+2921,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_r0),32);
        vcdp->chgBus(c+2929,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_r0_in),32);
        vcdp->chgBus(c+2937,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__ff_input),32);
        vcdp->chgBus(c+2945,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cnt_result),6);
        vcdp->chgBus(c+2953,((~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask)),32);
        vcdp->chgBus(c+2961,((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex 
                              & (~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask))),32);
        vcdp->chgBus(c+2969,((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex 
                              | vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__bmask)),32);
        vcdp->chgBus(c+2977,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResInv_SP)
                               ? VL_NEGATE_I(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__OutMux_D)
                               : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__OutMux_D)),32);
        vcdp->chgBit(c+2985,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_op_a_signed));
        vcdp->chgBus(c+2993,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_popcnt_i__DOT__cnt_l1),32);
        vcdp->chgBus(c+3001,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_popcnt_i__DOT__cnt_l2),24);
        vcdp->chgBus(c+3009,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_popcnt_i__DOT__cnt_l3),16);
        vcdp->chgBus(c+3017,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_popcnt_i__DOT__cnt_l4),10);
        vcdp->chgBit(c+3025,((0U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__cnt_result))));
        vcdp->chgBus(c+3033,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResReg_DP_rev),32);
        vcdp->chgBus(c+3041,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__OutMux_D),32);
        vcdp->chgBit(c+3049,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ABComp_S));
        vcdp->chgQuad(c+3057,((VL_ULL(0x1ffffffff) 
                               & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_active)
                                   ? (((QData)((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_carry_q)) 
                                       << 0x20U) | (QData)((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_c_ex)))
                                   : VL_EXTENDS_QI(33,32, vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_c_ex)))),33);
        vcdp->chgBus(c+3073,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_active)
                               ? (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_imm)
                               : (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_imm_ex))),5);
        vcdp->chgBus(c+3081,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_subword),2);
        vcdp->chgBus(c+3089,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_signed),2);
        vcdp->chgBit(c+3097,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_shift_arith));
        vcdp->chgBus(c+3105,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_imm),5);
        vcdp->chgBus(c+3113,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_subword),2);
        vcdp->chgBus(c+3121,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_signed),2);
        vcdp->chgBit(c+3129,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_shift_arith));
        vcdp->chgBit(c+3137,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_active));
        vcdp->chgBit(c+3145,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_save));
        vcdp->chgBit(c+3153,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_clearcarry));
        vcdp->chgBus(c+3161,(((((VL_EXTENDS_II(32,18, 
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
        vcdp->chgQuad(c+3169,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__dot_short_result),33);
        vcdp->chgBus(c+3185,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_is_clpx_ex)
                               ? (VL_EXTENDS_II(32,17, 
                                                (0x1ffffU 
                                                 & (IData)(
                                                           (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_op_b 
                                                            >> 0x11U)))) 
                                  & VL_NEGATE_I((IData)(
                                                        (1U 
                                                         & (~ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_clpx_img_ex))))))
                               : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_op_c_ex)),32);
        vcdp->chgBus(c+3193,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__clpx_shift_result),16);
        vcdp->chgQuad(c+3201,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_op_a),36);
        vcdp->chgQuad(c+3217,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_op_b),36);
        vcdp->chgArray(c+3233,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_char_mul),72);
        vcdp->chgQuad(c+3257,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_op_a),34);
        vcdp->chgQuad(c+3273,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_op_b),34);
        vcdp->chgArray(c+3289,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_mul),68);
        vcdp->chgBus(c+3313,((0x1ffffU & ((IData)((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_op_a 
                                                   >> 0x11U)) 
                                          ^ VL_NEGATE_I((IData)(
                                                                ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_is_clpx_ex) 
                                                                 & (~ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_clpx_img_ex)))))))),17);
        vcdp->chgBus(c+3321,(VL_EXTENDS_II(32,17, (0x1ffffU 
                                                   & (IData)(
                                                             (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__genblk1__DOT__dot_short_op_b 
                                                              >> 0x11U))))),32);
        vcdp->chgBus(c+3329,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__csr_rdata_int),32);
        vcdp->chgBit(c+3337,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__csr_we_int));
        vcdp->chgBus(c+3345,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__frm_n),3);
        vcdp->chgBus(c+3353,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__fflags_n),5);
        vcdp->chgBus(c+3361,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__fprec_n),5);
        vcdp->chgBus(c+3369,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__dscratch0_n),32);
        vcdp->chgBus(c+3377,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__dscratch1_n),32);
        vcdp->chgBus(c+3385,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mscratch_n),32);
        vcdp->chgBus(c+3393,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mtvec_n),24);
        vcdp->chgBus(c+3401,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mtvecx_n),24);
        vcdp->chgBus(c+3409,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mie_n),19);
        vcdp->chgBus(c+3417,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__miex_n),32);
        vcdp->chgBus(c+3425,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__menip),19);
        vcdp->chgArray(c+3433,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCCR_n),384);
        vcdp->chgBus(c+3529,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCMR_n),2);
        vcdp->chgBus(c+3537,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCER_n),12);
        vcdp->chgBus(c+3545,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__perf_rdata),32);
        vcdp->chgBus(c+3553,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pccr_index),5);
        vcdp->chgBit(c+3561,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__pccr_all_sel));
        vcdp->chgBit(c+3569,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__is_pccr));
        vcdp->chgBit(c+3577,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__is_pcer));
        vcdp->chgBit(c+3585,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__is_pcmr));
    }
}

void Vtop::traceChgThis__9(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+3593,((0x3fffffU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)),22);
        vcdp->chgBus(c+3601,(((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_type_ex))
                               ? ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                   ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                       ? 8U : 4U) : 
                                  ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                    ? 2U : 1U)) : (
                                                   (1U 
                                                    & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_type_ex))
                                                    ? 
                                                   ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned_ex)
                                                     ? 1U
                                                     : 
                                                    ((2U 
                                                      & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                                      ? 
                                                     ((1U 
                                                       & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                                       ? 8U
                                                       : 0xcU)
                                                      : 
                                                     ((1U 
                                                       & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                                       ? 6U
                                                       : 3U)))
                                                    : 
                                                   ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned_ex)
                                                     ? 
                                                    ((2U 
                                                      & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                                      ? 
                                                     ((1U 
                                                       & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                                       ? 7U
                                                       : 3U)
                                                      : 
                                                     ((1U 
                                                       & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                                       ? 1U
                                                       : 0U))
                                                     : 
                                                    ((2U 
                                                      & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                                      ? 
                                                     ((1U 
                                                       & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                                       ? 8U
                                                       : 0xcU)
                                                      : 
                                                     ((1U 
                                                       & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                                       ? 0xeU
                                                       : 0xfU)))))),4);
        vcdp->chgBus(c+3609,(((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset))
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
                                          << 8U)) | 
                                      (0xffU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                >> 0x18U)))
                                   : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex))),32);
        vcdp->chgBus(c+3617,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int),32);
        vcdp->chgBus(c+3625,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_addr),32);
        vcdp->chgBus(c+3633,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__exc_pc_mux_id),3);
        vcdp->chgBus(c+3641,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__exc_cause),6);
        vcdp->chgBus(c+3649,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__trap_addr_mux),2);
        vcdp->chgBit(c+3657,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__is_decoding));
        vcdp->chgBit(c+3665,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned));
        vcdp->chgBit(c+3673,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_multicycle));
        vcdp->chgBus(c+3681,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__jump_target),32);
        vcdp->chgBus(c+3689,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__lsu_rdata),32);
        vcdp->chgBit(c+3697,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_save_if));
        vcdp->chgBit(c+3705,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_restore_mret_id));
        vcdp->chgBit(c+3713,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_restore_uret_id));
        vcdp->chgBit(c+3721,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_restore_dret_id));
        vcdp->chgBit(c+3729,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__perf_pipeline_stall));
        vcdp->chgBus(c+3737,((0x1fU & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__exc_cause))),5);
        vcdp->chgBus(c+3745,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__exc_pc),32);
        vcdp->chgBit(c+3753,((0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwloop_controller_i__DOT__pc_is_end_addr))));
        vcdp->chgBus(c+3761,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwlp_target),32);
        vcdp->chgBus(c+3769,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwlp_dec_cnt),2);
        vcdp->chgBus(c+3777,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__trap_base_addr),24);
        vcdp->chgBus(c+3785,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwloop_controller_i__DOT__pc_is_end_addr),2);
        vcdp->chgBus(c+3793,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwloop_controller_i__DOT__j),32);
        vcdp->chgBit(c+3801,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__valid_stored));
        vcdp->chgBit(c+3809,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__hwlp_masked));
        vcdp->chgBit(c+3817,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__illegal_insn_dec));
        vcdp->chgBit(c+3825,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__branch_taken_ex));
        vcdp->chgBus(c+3833,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_b),32);
        vcdp->chgBit(c+3841,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__regfile_alu_we));
        vcdp->chgBit(c+3849,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_en));
        vcdp->chgBus(c+3857,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_op_a_mux_sel),3);
        vcdp->chgBus(c+3865,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_op_b_mux_sel),3);
        vcdp->chgBus(c+3873,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__alu_op_c_mux_sel),2);
        vcdp->chgBus(c+3881,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__imm_b_mux_sel),4);
        vcdp->chgBit(c+3889,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__data_we_id));
        vcdp->chgBus(c+3897,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__data_type_id),2);
        vcdp->chgBus(c+3905,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_target),32);
        vcdp->chgBus(c+3913,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_start_int),32);
        vcdp->chgBit(c+3921,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__csr_status));
        vcdp->chgBit(c+3929,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__prepost_useincr));
        vcdp->chgBus(c+3937,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_a_fw_mux_sel),2);
        vcdp->chgBus(c+3945,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_b_fw_mux_sel),2);
        vcdp->chgBus(c+3953,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__operand_c_fw_mux_sel),2);
        vcdp->chgBit(c+3961,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__scalar_replication));
        vcdp->chgBit(c+3969,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__decoder_i__DOT__csr_illegal));
        vcdp->chgBus(c+3977,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_r1),32);
        vcdp->chgBus(c+3985,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_r1_in),32);
        vcdp->chgBus(c+3993,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__shuffle_result),32);
        vcdp->chgBus(c+4001,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__pack_result),32);
        vcdp->chgBus(c+4009,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset),2);
        vcdp->chgBus(c+4017,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_rdata_ext),32);
        vcdp->chgBus(c+4025,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_h_ext),32);
        vcdp->chgBus(c+4033,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_b_ext),32);
        vcdp->chgBus(c+4041,((0xfffffU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)),20);
        vcdp->chgBus(c+4049,((0xffffcU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)),20);
    }
}

void Vtop::traceChgThis__10(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+4057,((0x1fU & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__int_controller_i__DOT__irq_id_q))),5);
        vcdp->chgBus(c+4065,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_atop_ex),6);
        vcdp->chgBus(c+4073,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__hwlp_dec_cnt_id),2);
        vcdp->chgBit(c+4081,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_valid_id));
        vcdp->chgBus(c+4089,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id),32);
        vcdp->chgBit(c+4097,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__is_compressed_id));
        vcdp->chgBit(c+4105,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__is_fetch_failed_id));
        vcdp->chgBit(c+4113,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__illegal_c_insn_id));
        vcdp->chgBit(c+4121,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__useincr_addr_ex));
        vcdp->chgBit(c+4129,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__branch_in_ex));
        vcdp->chgBus(c+4137,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_ex),32);
        vcdp->chgBit(c+4145,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_en_ex));
        vcdp->chgBus(c+4153,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex),7);
        vcdp->chgBus(c+4161,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex),32);
        vcdp->chgBus(c+4169,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex),32);
        vcdp->chgBus(c+4177,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex),5);
        vcdp->chgBus(c+4185,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_b_ex),5);
        vcdp->chgBus(c+4193,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__imm_vec_ext_ex),2);
        vcdp->chgBus(c+4201,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_vec_mode_ex),2);
        vcdp->chgBit(c+4209,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_is_clpx_ex));
        vcdp->chgBit(c+4217,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_is_subrot_ex));
        vcdp->chgBus(c+4225,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_clpx_shift_ex),2);
        vcdp->chgBus(c+4233,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex),3);
        vcdp->chgBus(c+4241,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_a_ex),32);
        vcdp->chgBus(c+4249,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_b_ex),32);
        vcdp->chgBus(c+4257,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_c_ex),32);
        vcdp->chgBit(c+4265,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_en_ex));
        vcdp->chgBit(c+4273,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_sel_subword_ex));
        vcdp->chgBus(c+4281,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_signed_mode_ex),2);
        vcdp->chgBus(c+4289,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_imm_ex),5);
        vcdp->chgBus(c+4297,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_op_a_ex),32);
        vcdp->chgBus(c+4305,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_op_b_ex),32);
        vcdp->chgBus(c+4313,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_op_c_ex),32);
        vcdp->chgBus(c+4321,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_dot_signed_ex),2);
        vcdp->chgBus(c+4329,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_clpx_shift_ex),2);
        vcdp->chgBit(c+4337,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_clpx_img_ex));
        vcdp->chgBit(c+4345,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_en_ex));
        vcdp->chgBus(c+4353,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_type_ex),2);
        vcdp->chgBus(c+4361,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_flags_ex),15);
        vcdp->chgBus(c+4369,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_op_ex),6);
        vcdp->chgBus(c+4377,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_lat_ex),2);
        vcdp->chgArray(c+4385,(vlSymsp->TOP__top.riscv_core_i__DOT____Vcellout__id_stage_i__apu_operands_ex_o),96);
        vcdp->chgBus(c+4409,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__apu_waddr_ex),6);
        vcdp->chgBus(c+4417,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_waddr_ex),6);
        vcdp->chgBit(c+4425,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_we_ex));
        vcdp->chgBus(c+4433,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__regfile_waddr_lsu),6);
        vcdp->chgBus(c+4441,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_waddr_ex),6);
        vcdp->chgBit(c+4449,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__regfile_alu_we_ex));
        vcdp->chgBit(c+4457,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_access_ex));
        vcdp->chgBus(c+4465,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__csr_op_ex),2);
        vcdp->chgBus(c+4473,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mtvec_q),24);
        vcdp->chgBus(c+4481,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mtvecx_q),24);
        vcdp->chgBus(c+4489,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_sign_ext_ex),2);
        vcdp->chgBus(c+4497,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_reg_offset_ex),2);
        vcdp->chgBit(c+4505,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_req_ex));
        vcdp->chgBit(c+4513,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_load_event_ex));
        vcdp->chgBit(c+4521,((1U & ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mstatus_q) 
                                    >> 5U))));
        vcdp->chgBus(c+4529,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mepc_q),32);
        vcdp->chgBus(c+4537,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__depc_q),32);
        vcdp->chgBit(c+4545,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__debug_mode_q));
        vcdp->chgBit(c+4553,((1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__dcsr_q 
                                    >> 2U))));
        vcdp->chgBit(c+4561,((1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__dcsr_q 
                                    >> 0xfU))));
        vcdp->chgBit(c+4569,((1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__dcsr_q 
                                    >> 0xcU))));
        vcdp->chgQuad(c+4577,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_start_q),64);
        vcdp->chgQuad(c+4593,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_end_q),64);
        vcdp->chgQuad(c+4609,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__hwlp_counter_q),64);
        vcdp->chgBit(c+4625,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__core_busy_q));
        vcdp->chgBit(c+4633,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_is_clpx_ex));
        vcdp->chgBit(c+4641,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__offset_fsm_cs));
        vcdp->chgBit(c+4649,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__is_hwlp_id_q));
        vcdp->chgBus(c+4657,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__hwlp_dec_cnt_if),2);
        vcdp->chgBus(c+4665,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__CS),3);
        vcdp->chgBus(c+4673,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__hwlp_CS),3);
        vcdp->chgBus(c+4681,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__instr_addr_q),32);
        vcdp->chgBus(c+4689,(((IData)(4U) + (0xfffffffcU 
                                             & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__instr_addr_q))),32);
        vcdp->chgBit(c+4697,((1U & (~ ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_Q) 
                                       >> 1U)))));
        vcdp->chgArray(c+4705,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__addr_Q),128);
        vcdp->chgArray(c+4737,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_Q),128);
        vcdp->chgBus(c+4769,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_Q),4);
        vcdp->chgBus(c+4777,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__is_hwlp_Q),2);
        vcdp->chgBit(c+4785,((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_Q) 
                               >> 3U) & (3U != (3U 
                                                & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_Q[0U])))));
        vcdp->chgBit(c+4793,((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__valid_Q) 
                               >> 3U) & (3U != (3U 
                                                & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_Q[1U] 
                                                    << 0x10U) 
                                                   | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__prefetch_32__DOT__prefetch_buffer_i__DOT__fifo_i__DOT__rdata_Q[0U] 
                                                      >> 0x10U)))))));
        vcdp->chgBus(c+4801,((0xfffU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                        >> 0x14U))),32);
        vcdp->chgBus(c+4809,(((0xfffff000U & (VL_NEGATE_I((IData)(
                                                                  (1U 
                                                                   & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                                      >> 0x1fU)))) 
                                              << 0xcU)) 
                              | ((0xfe0U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                            >> 0x14U)) 
                                 | (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                             >> 7U))))),32);
        vcdp->chgBus(c+4817,(((0xffffff80U & (VL_NEGATE_I((IData)(
                                                                  (1U 
                                                                   & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                                      >> 0x1fU)))) 
                                              << 7U)) 
                              | (0x7fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                          >> 0x19U)))),32);
        vcdp->chgBus(c+4825,(((0xffffe000U & (VL_NEGATE_I((IData)(
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
                                       | (0x1eU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                   >> 7U))))))),32);
        vcdp->chgBus(c+4833,((0xfffff000U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id)),32);
        vcdp->chgBus(c+4841,(((0xfff00000U & (VL_NEGATE_I((IData)(
                                                                  (1U 
                                                                   & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                                      >> 0x1fU)))) 
                                              << 0x14U)) 
                              | ((0xff000U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id) 
                                 | ((0x800U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                               >> 9U)) 
                                    | (0x7feU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                 >> 0x14U)))))),32);
        vcdp->chgBus(c+4849,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                       >> 0xfU))),32);
        vcdp->chgBus(c+4857,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                       >> 0x14U))),32);
        vcdp->chgBus(c+4865,(((0xffffffe0U & (VL_NEGATE_I((IData)(
                                                                  (1U 
                                                                   & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                                      >> 0x18U)))) 
                                              << 5U)) 
                              | (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                          >> 0x14U)))),32);
        vcdp->chgBus(c+4873,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                       >> 0x19U))),32);
        vcdp->chgBus(c+4881,(((0xffffffc0U & (VL_NEGATE_I((IData)(
                                                                  (1U 
                                                                   & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                                      >> 0x18U)))) 
                                              << 6U)) 
                              | ((0x3eU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                           >> 0x13U)) 
                                 | (1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                          >> 0x19U))))),32);
        vcdp->chgBus(c+4889,(((0x3000000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                             >> 3U)) 
                              | ((0x30000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                              >> 7U)) 
                                 | ((0x300U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                               >> 0xdU)) 
                                    | ((2U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                              >> 0x13U)) 
                                       | (1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                >> 0x19U))))))),32);
        vcdp->chgBus(c+4897,(((0x10000U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                           >> 4U)) 
                              | (1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                       >> 0x19U)))),32);
        vcdp->chgBus(c+4905,((((IData)(1U) << (0x1fU 
                                               & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                                  >> 0x14U))) 
                              - (IData)(1U))),32);
        vcdp->chgBit(c+4913,((1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__int_controller_i__DOT__exc_ctrl_cs))));
        vcdp->chgBit(c+4921,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__int_controller_i__DOT__irq_sec_q));
        vcdp->chgBus(c+4929,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__int_controller_i__DOT__irq_id_q),6);
        vcdp->chgBus(c+4937,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                       >> 0xfU))),6);
        vcdp->chgBus(c+4945,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                       >> 0x14U))),6);
        vcdp->chgBus(c+4953,((0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                       >> 7U))),6);
        vcdp->chgBus(c+4961,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__mem[
                             (0x1fU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                       >> 0x14U))]),32);
        vcdp->chgBit(c+4969,((1U & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_rdata_id 
                                    >> 7U))));
        vcdp->chgBus(c+4977,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__TestReadAddr_Q),6);
        vcdp->chgArray(c+4985,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__registers_i__DOT__riscv_register_file_i__DOT__mem),1024);
        vcdp->chgBus(c+5241,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__ctrl_fsm_cs),5);
        vcdp->chgBit(c+5249,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__jump_done_q));
        vcdp->chgBit(c+5257,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__boot_done_q));
        vcdp->chgBit(c+5265,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__data_err_q));
        vcdp->chgBit(c+5273,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__illegal_insn_q));
        vcdp->chgBit(c+5281,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__controller_i__DOT__instr_valid_irq_flush_q));
        vcdp->chgBus(c+5289,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__int_controller_i__DOT__exc_ctrl_cs),2);
        vcdp->chgBus(c+5297,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__hwloop_regs_i__DOT__i),32);
        vcdp->chgBit(c+5305,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__regfile_we_lsu));
        vcdp->chgBus(c+5313,((~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_a_ex)),32);
        vcdp->chgBus(c+5321,((~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex)),32);
        vcdp->chgBus(c+5329,(((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_is_clpx_ex)
                               ? (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_clpx_shift_ex) 
                                   << 0x10U) | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_clpx_shift_ex))
                               : (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_b_ex) 
                                   << 0x18U) | (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_b_ex) 
                                                 << 0x10U) 
                                                | (((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_b_ex) 
                                                    << 8U) 
                                                   | (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_b_ex)))))),32);
        vcdp->chgBus(c+5337,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_clpx_shift_ex),16);
        vcdp->chgBus(c+5345,(((0x17U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))
                               ? 0U : (~ vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex))),32);
        vcdp->chgBit(c+5353,((((((0x10U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)) 
                                 | (0x11U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
                                | (0x16U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
                               | (0x17U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))) 
                              | (0x47U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)))));
        vcdp->chgBit(c+5361,((0x28U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))));
        vcdp->chgBus(c+5369,(((IData)(0xfffffffeU) 
                              << (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex))),32);
        vcdp->chgBus(c+5377,((3U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__bmask_a_ex))),2);
        vcdp->chgBit(c+5385,((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))));
        vcdp->chgBit(c+5393,((1U & ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_b_ex 
                                     >> 0x1fU) & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex)))));
        vcdp->chgBus(c+5401,((3U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operator_ex))),2);
        vcdp->chgBus(c+5409,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResReg_DP),32);
        vcdp->chgBus(c+5417,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__AReg_DP),32);
        vcdp->chgBus(c+5425,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__BReg_DP),32);
        vcdp->chgBit(c+5433,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__RemSel_SP));
        vcdp->chgBit(c+5441,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__CompInv_SP));
        vcdp->chgBit(c+5449,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__ResInv_SP));
        vcdp->chgBus(c+5457,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__Cnt_DP),6);
        vcdp->chgBit(c+5465,((1U & (~ (IData)((0U != (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__Cnt_DP)))))));
        vcdp->chgBus(c+5473,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__int_div__DOT__div_i__DOT__State_SP),2);
        vcdp->chgBus(c+5481,(((3U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex))
                               ? (0x7fffffffU & (((IData)(1U) 
                                                  << (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_imm_ex)) 
                                                 >> 1U))
                               : 0U)),32);
        vcdp->chgBus(c+5489,(((IData)(1U) << (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_imm_ex))),32);
        vcdp->chgBit(c+5497,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_carry_q));
        vcdp->chgBus(c+5505,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__mulh_CS),3);
        vcdp->chgBus(c+5513,((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_a_ex 
                              ^ VL_NEGATE_I((IData)(
                                                    (1U 
                                                     == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex)))))),32);
        vcdp->chgBus(c+5521,((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_b_ex 
                              & VL_NEGATE_I((IData)(
                                                    (1U 
                                                     == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex)))))),32);
        vcdp->chgBus(c+5529,(((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_c_ex 
                               + (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_b_ex 
                                  & VL_NEGATE_I((IData)(
                                                        (1U 
                                                         == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex)))))) 
                              + VL_MULS_III(32,32,32, 
                                            (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_a_ex 
                                             ^ VL_NEGATE_I((IData)(
                                                                   (1U 
                                                                    == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex))))), vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operand_b_ex))),32);
        vcdp->chgBit(c+5537,((1U == (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__mult_operator_ex))));
        vcdp->chgBus(c+5545,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_type_q),2);
        vcdp->chgBus(c+5553,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q),2);
        vcdp->chgBus(c+5561,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_sign_ext_q),2);
        vcdp->chgBit(c+5569,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_we_q));
        vcdp->chgBus(c+5577,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__CS),2);
        vcdp->chgBus(c+5585,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_q),32);
        vcdp->chgBus(c+5593,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__dcsr_q),32);
        vcdp->chgBus(c+5601,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__dscratch0_q),32);
        vcdp->chgBus(c+5609,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__dscratch1_q),32);
        vcdp->chgBus(c+5617,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mscratch_q),32);
        vcdp->chgBus(c+5625,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mstatus_q),7);
        vcdp->chgBus(c+5633,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mcause_q),7);
        vcdp->chgBus(c+5641,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__mie_q),19);
        vcdp->chgBus(c+5649,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__miex_q),32);
        vcdp->chgBit(c+5657,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__id_valid_q));
        vcdp->chgBus(c+5665,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCCR_inc_q),12);
        vcdp->chgArray(c+5673,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCCR_q),384);
        vcdp->chgBus(c+5769,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCMR_q),2);
        vcdp->chgBus(c+5777,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__PCER_q),12);
        vcdp->chgBus(c+5785,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__unnamedblk3__DOT__i),32);
        vcdp->chgBus(c+5793,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__cs_registers_i__DOT__unnamedblk2__DOT__i),32);
    }
}

void Vtop::traceChgThis__11(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+5801,(((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q))
                               ? ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_offset_q))
                                   ? ((0xffffff00U 
                                       & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
                                          << 8U)) | 
                                      (0xffU & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__rdata_q 
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
    }
}

void Vtop::traceChgThis__12(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+5809,(vlSymsp->TOP__top__ram_i.__PVT__instr_rvalid_o));
        vcdp->chgArray(c+5817,(vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o),128);
        vcdp->chgBit(c+5849,(vlSymsp->TOP__top__ram_i.__PVT__data_rvalid_o));
        vcdp->chgBus(c+5857,(vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o),32);
        vcdp->chgBus(c+5865,(vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[0U]),32);
    }
}

void Vtop::traceChgThis__13(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+5873,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_we_ex));
        vcdp->chgBus(c+5881,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__pc_id),32);
        vcdp->chgBus(c+5889,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex),32);
        vcdp->chgBus(c+5897,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_type_ex),2);
        vcdp->chgBit(c+5905,(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned_ex));
    }
}

void Vtop::traceChgThis__14(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+5913,(vlTOPp->clk_i));
        vcdp->chgBit(c+5921,(vlTOPp->rstn_i));
        vcdp->chgBit(c+5929,(vlTOPp->irq_i));
        vcdp->chgBus(c+5937,(vlTOPp->irq_id_i),5);
        vcdp->chgBit(c+5945,(vlTOPp->irq_ack_o));
        vcdp->chgBus(c+5953,(vlTOPp->irq_id_o),5);
        vcdp->chgBit(c+5961,(vlTOPp->debug_req_i));
        vcdp->chgBit(c+5969,(vlTOPp->fetch_enable_i));
        vcdp->chgBit(c+5977,(vlTOPp->core_busy_o));
        vcdp->chgBit(c+5985,((((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__irq_pending) 
                               | (IData)(vlTOPp->debug_req_i)) 
                              | (IData)(vlSymsp->TOP__top.core_busy_o))));
    }
}
