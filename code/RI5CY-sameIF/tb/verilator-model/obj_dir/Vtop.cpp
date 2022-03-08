// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(top, Vtop_top);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop::~Vtop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vtop::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top.sv", 16, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top.sv", 16, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_settle__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->irq_id_o = (0x1fU & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__id_stage_i__DOT__int_controller_i__DOT__irq_id_q));
    vlTOPp->irq_ack_o = vlSymsp->TOP__top.irq_ack_o;
    vlTOPp->core_busy_o = vlSymsp->TOP__top.core_busy_o;
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__top__ram_i._settle__TOP__top__ram_i__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    if ((((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i))) 
         | ((~ (IData)(vlTOPp->rstn_i)) & (IData)(vlTOPp->__Vclklast__TOP__rstn_i)))) {
        vlSymsp->TOP__top._sequent__TOP__top__4(vlSymsp);
        vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
        vlTOPp->_settle__TOP__1(vlSymsp);
    }
    if (((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i)))) {
        vlSymsp->TOP__top__ram_i._sequent__TOP__top__ram_i__3(vlSymsp);
        vlTOPp->__Vm_traceActivity = (8U | vlTOPp->__Vm_traceActivity);
        vlSymsp->TOP__top__ram_i__dp_ram_i._sequent__TOP__top__ram_i__dp_ram_i__1(vlSymsp);
    }
    if (((~ (IData)(vlTOPp->clk_i)) & (IData)(vlTOPp->__Vclklast__TOP__clk_i))) {
        vlSymsp->TOP__top._sequent__TOP__top__5(vlSymsp);
    }
    vlSymsp->TOP__top._combo__TOP__top__6(vlSymsp);
    if ((((IData)(vlTOPp->clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_i))) 
         | ((~ (IData)(vlTOPp->rstn_i)) & (IData)(vlTOPp->__Vclklast__TOP__rstn_i)))) {
        vlSymsp->TOP__top._sequent__TOP__top__7(vlSymsp);
        vlTOPp->__Vm_traceActivity = (0x10U | vlTOPp->__Vm_traceActivity);
    }
    vlSymsp->TOP__top._combo__TOP__top__8(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk_i = vlTOPp->clk_i;
    vlTOPp->__Vclklast__TOP__rstn_i = vlTOPp->rstn_i;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__top._initial__TOP__top__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk_i = vlTOPp->clk_i;
    vlTOPp->__Vclklast__TOP__rstn_i = vlTOPp->rstn_i;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__top._settle__TOP__top__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
    vlSymsp->TOP__top__ram_i._settle__TOP__top__ram_i__1(vlSymsp);
    vlTOPp->_settle__TOP__1(vlSymsp);
    vlSymsp->TOP__top._settle__TOP__top__3(vlSymsp);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_ready ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_ready)
         | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__lsu_ready_ex ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__lsu_ready_ex)
         | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__lsu_ready_wb ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__lsu_ready_wb)
         | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_req_pmp ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__data_req_pmp)
         | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__valid ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__if_stage_i__DOT__valid)
         | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_valid ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__if_stage_i__DOT__fetch_valid)
         | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__sel_nodes ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__sel_nodes)
         | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0] ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0]) | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[1] ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[1]) | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[2] ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[2])|| (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[3] ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[3]) | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[4] ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[4])
         | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_a ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_a)
         | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_b ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_b));
    VL_DEBUG_IF( if(__req && ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_ready ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_ready))) VL_DBG_MSGF("        CHANGE: ../../rtl/include/../../rtl/riscv_core.sv:280: riscv_core_i.ex_ready\n"); );
    VL_DEBUG_IF( if(__req && ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__lsu_ready_ex ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__lsu_ready_ex))) VL_DBG_MSGF("        CHANGE: ../../rtl/include/../../rtl/riscv_core.sv:286: riscv_core_i.lsu_ready_ex\n"); );
    VL_DEBUG_IF( if(__req && ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__lsu_ready_wb ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__lsu_ready_wb))) VL_DBG_MSGF("        CHANGE: ../../rtl/include/../../rtl/riscv_core.sv:287: riscv_core_i.lsu_ready_wb\n"); );
    VL_DEBUG_IF( if(__req && ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_req_pmp ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__data_req_pmp))) VL_DBG_MSGF("        CHANGE: ../../rtl/include/../../rtl/riscv_core.sv:348: riscv_core_i.data_req_pmp\n"); );
    VL_DEBUG_IF( if(__req && ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__valid ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__if_stage_i__DOT__valid))) VL_DBG_MSGF("        CHANGE: ../../rtl/include/../../rtl/riscv_if_stage.sv:106: riscv_core_i.if_stage_i.valid\n"); );
    VL_DEBUG_IF( if(__req && ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_valid ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__if_stage_i__DOT__fetch_valid))) VL_DBG_MSGF("        CHANGE: ../../rtl/include/../../rtl/riscv_if_stage.sv:113: riscv_core_i.if_stage_i.fetch_valid\n"); );
    VL_DEBUG_IF( if(__req && ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__sel_nodes ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__sel_nodes))) VL_DBG_MSGF("        CHANGE: ../../rtl/include/../../rtl/riscv_alu.sv:1171: riscv_core_i.ex_stage_i.alu_i.alu_ff_i.sel_nodes\n"); );
    VL_DEBUG_IF( if(__req && ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0] ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0]) | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[1] ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[1]) | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[2] ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[2]) | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[3] ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[3]) | (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[4] ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[4]))) VL_DBG_MSGF("        CHANGE: ../../rtl/include/../../rtl/riscv_alu.sv:1172: riscv_core_i.ex_stage_i.alu_i.alu_ff_i.index_nodes\n"); );
    VL_DEBUG_IF( if(__req && ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_a ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_a))) VL_DBG_MSGF("        CHANGE: ../../rtl/include/../../rtl/riscv_mult.sv:76: riscv_core_i.ex_stage_i.mult_i.short_op_a\n"); );
    VL_DEBUG_IF( if(__req && ((vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_b ^ vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_b))) VL_DBG_MSGF("        CHANGE: ../../rtl/include/../../rtl/riscv_mult.sv:77: riscv_core_i.ex_stage_i.mult_i.short_op_b\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_ready 
        = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_ready;
    vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__lsu_ready_ex 
        = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__lsu_ready_ex;
    vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__lsu_ready_wb 
        = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__lsu_ready_wb;
    vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__data_req_pmp 
        = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_req_pmp;
    vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__if_stage_i__DOT__valid 
        = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__valid;
    vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__if_stage_i__DOT__fetch_valid 
        = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__if_stage_i__DOT__fetch_valid;
    vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__sel_nodes 
        = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__sel_nodes;
    vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0U] 
        = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[0U];
    vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[1U] 
        = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[1U];
    vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[2U] 
        = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[2U];
    vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[3U] 
        = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[3U];
    vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[4U] 
        = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes[4U];
    vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_a 
        = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_a;
    vlTOPp->__Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_b 
        = vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_b;
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((rstn_i & 0xfeU))) {
        Verilated::overWidthError("rstn_i");}
    if (VL_UNLIKELY((irq_i & 0xfeU))) {
        Verilated::overWidthError("irq_i");}
    if (VL_UNLIKELY((irq_id_i & 0xe0U))) {
        Verilated::overWidthError("irq_id_i");}
    if (VL_UNLIKELY((debug_req_i & 0xfeU))) {
        Verilated::overWidthError("debug_req_i");}
    if (VL_UNLIKELY((fetch_enable_i & 0xfeU))) {
        Verilated::overWidthError("fetch_enable_i");}
}
#endif  // VL_DEBUG

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk_i = VL_RAND_RESET_I(1);
    rstn_i = VL_RAND_RESET_I(1);
    irq_i = VL_RAND_RESET_I(1);
    irq_id_i = VL_RAND_RESET_I(5);
    irq_ack_o = VL_RAND_RESET_I(1);
    irq_id_o = VL_RAND_RESET_I(5);
    debug_req_i = VL_RAND_RESET_I(1);
    fetch_enable_i = VL_RAND_RESET_I(1);
    core_busy_o = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__riscv_core_i__DOT__ex_ready = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__riscv_core_i__DOT__lsu_ready_ex = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__riscv_core_i__DOT__lsu_ready_wb = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__riscv_core_i__DOT__data_req_pmp = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__riscv_core_i__DOT__if_stage_i__DOT__valid = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__riscv_core_i__DOT__if_stage_i__DOT__fetch_valid = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__sel_nodes = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(160, __Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__alu_i__DOT__alu_ff_i__DOT__index_nodes);
    __Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_a = VL_RAND_RESET_I(17);
    __Vchglast__TOP__top__riscv_core_i__DOT__ex_stage_i__DOT__mult_i__DOT__short_op_b = VL_RAND_RESET_I(17);
    __Vm_traceActivity = 0;
}
