// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop_dp_ram__A14.h"
#include "Vtop__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(Vtop_dp_ram__A14) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vtop_dp_ram__A14::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop_dp_ram__A14::~Vtop_dp_ram__A14() {
}

uint32_t Vtop_dp_ram__A14::readByte(uint32_t byte_addr) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_dp_ram__A14::readByte\n"); );
    // Variables
    VL_OUT8(readByte__Vfuncrtn,7,0);
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    readByte__Vfuncrtn = vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
        [(0xfffffU & byte_addr)];
    // Final
    return (readByte__Vfuncrtn);
}

void Vtop_dp_ram__A14::writeByte(uint32_t byte_addr, uint32_t val) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_dp_ram__A14::writeByte\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem[(0xfffffU 
                                                   & byte_addr)] 
        = val;
}

VL_INLINE_OPT void Vtop_dp_ram__A14::_sequent__TOP__top__ram_i__dp_ram_i__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_dp_ram__A14::_sequent__TOP__top__ram_i__dp_ram_i__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdlyvval__mem__v0;
    CData/*0:0*/ __Vdlyvset__mem__v0;
    CData/*7:0*/ __Vdlyvval__mem__v1;
    CData/*0:0*/ __Vdlyvset__mem__v1;
    CData/*7:0*/ __Vdlyvval__mem__v2;
    CData/*0:0*/ __Vdlyvset__mem__v2;
    CData/*7:0*/ __Vdlyvval__mem__v3;
    CData/*0:0*/ __Vdlyvset__mem__v3;
    IData/*19:0*/ __Vdlyvdim0__mem__v0;
    IData/*19:0*/ __Vdlyvdim0__mem__v1;
    IData/*19:0*/ __Vdlyvdim0__mem__v2;
    IData/*19:0*/ __Vdlyvdim0__mem__v3;
    // Body
    __Vdlyvset__mem__v0 = 0U;
    __Vdlyvset__mem__v1 = 0U;
    __Vdlyvset__mem__v2 = 0U;
    __Vdlyvset__mem__v3 = 0U;
    vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[0U] 
        = ((0xffffff00U & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[0U]) 
           | vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
           [(0xfffffU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp)]);
    if (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_req_pmp) {
        if ((1U & (~ (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_we_ex)))) {
            vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
                = ((0xffffff00U & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o) 
                   | vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
                   [(0xffffcU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)]);
            vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
                = ((0xffff00ffU & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o) 
                   | (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
                      [(0xfffffU & ((IData)(1U) + (0xffffcU 
                                                   & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)))] 
                      << 8U));
            vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
                = ((0xff00ffffU & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o) 
                   | (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
                      [(0xfffffU & ((IData)(2U) + (0xffffcU 
                                                   & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)))] 
                      << 0x10U));
            vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o 
                = ((0xffffffU & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_b_o) 
                   | (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
                      [(0xfffffU & ((IData)(3U) + (0xffffcU 
                                                   & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)))] 
                      << 0x18U));
        }
    }
    vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[0U] 
        = ((0xffff00ffU & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[0U]) 
           | (0xffffff00U & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
                             [(0xfffffU & ((IData)(1U) 
                                           + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp))] 
                             << 8U)));
    vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[0U] 
        = ((0xff00ffffU & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[0U]) 
           | (0xffff0000U & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
                             [(0xfffffU & ((IData)(2U) 
                                           + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp))] 
                             << 0x10U)));
    vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[0U] 
        = ((0xffffffU & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[0U]) 
           | (0xff000000U & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
                             [(0xfffffU & ((IData)(3U) 
                                           + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp))] 
                             << 0x18U)));
    vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[1U] 
        = ((0xffffff00U & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[1U]) 
           | vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
           [(0xfffffU & ((IData)(4U) + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp))]);
    vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[1U] 
        = ((0xffff00ffU & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[1U]) 
           | (0xffffff00U & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
                             [(0xfffffU & ((IData)(5U) 
                                           + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp))] 
                             << 8U)));
    vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[1U] 
        = ((0xff00ffffU & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[1U]) 
           | (0xffff0000U & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
                             [(0xfffffU & ((IData)(6U) 
                                           + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp))] 
                             << 0x10U)));
    vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[1U] 
        = ((0xffffffU & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[1U]) 
           | (0xff000000U & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
                             [(0xfffffU & ((IData)(7U) 
                                           + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp))] 
                             << 0x18U)));
    vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[2U] 
        = ((0xffffff00U & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[2U]) 
           | vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
           [(0xfffffU & ((IData)(8U) + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp))]);
    vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[2U] 
        = ((0xffff00ffU & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[2U]) 
           | (0xffffff00U & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
                             [(0xfffffU & ((IData)(9U) 
                                           + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp))] 
                             << 8U)));
    vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[2U] 
        = ((0xff00ffffU & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[2U]) 
           | (0xffff0000U & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
                             [(0xfffffU & ((IData)(0xaU) 
                                           + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp))] 
                             << 0x10U)));
    vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[2U] 
        = ((0xffffffU & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[2U]) 
           | (0xff000000U & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
                             [(0xfffffU & ((IData)(0xbU) 
                                           + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp))] 
                             << 0x18U)));
    vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[3U] 
        = ((0xffffff00U & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[3U]) 
           | vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
           [(0xfffffU & ((IData)(0xcU) + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp))]);
    vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[3U] 
        = ((0xffff00ffU & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[3U]) 
           | (0xffffff00U & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
                             [(0xfffffU & ((IData)(0xdU) 
                                           + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp))] 
                             << 8U)));
    vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[3U] 
        = ((0xff00ffffU & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[3U]) 
           | (0xffff0000U & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
                             [(0xfffffU & ((IData)(0xeU) 
                                           + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp))] 
                             << 0x10U)));
    vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[3U] 
        = ((0xffffffU & vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__rdata_a_o[3U]) 
           | (0xff000000U & (vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem
                             [(0xfffffU & ((IData)(0xfU) 
                                           + vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__instr_addr_pmp))] 
                             << 0x18U)));
    if (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_req_pmp) {
        if (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_we_ex) {
            if ((1U & ((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_type_ex))
                        ? ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                            ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                ? 8U : 4U) : ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                               ? 2U
                                               : 1U))
                        : ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_type_ex))
                            ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned_ex)
                                ? 1U : ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                         ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                             ? 8U : 0xcU)
                                         : ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                             ? 6U : 3U)))
                            : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned_ex)
                                ? ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                    ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                        ? 7U : 3U) : 
                                   ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                     ? 1U : 0U)) : 
                               ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                 ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                     ? 8U : 0xcU) : 
                                ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                  ? 0xeU : 0xfU))))))) {
                __Vdlyvval__mem__v0 = (0xffU & ((2U 
                                                 & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset))
                                                  ? 
                                                 ((0xff000000U 
                                                   & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                      << 0x18U)) 
                                                  | (0xffffffU 
                                                     & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                        >> 8U)))
                                                  : 
                                                 ((0xffff0000U 
                                                   & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                      << 0x10U)) 
                                                  | (0xffffU 
                                                     & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                        >> 0x10U))))
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset))
                                                  ? 
                                                 ((0xffffff00U 
                                                   & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                      << 8U)) 
                                                  | (0xffU 
                                                     & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                        >> 0x18U)))
                                                  : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex)));
                __Vdlyvset__mem__v0 = 1U;
                __Vdlyvdim0__mem__v0 = (0xffffcU & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int);
            }
            if ((2U & ((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_type_ex))
                        ? ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                            ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                ? 8U : 4U) : ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                               ? 2U
                                               : 1U))
                        : ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_type_ex))
                            ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned_ex)
                                ? 1U : ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                         ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                             ? 8U : 0xcU)
                                         : ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                             ? 6U : 3U)))
                            : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned_ex)
                                ? ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                    ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                        ? 7U : 3U) : 
                                   ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                     ? 1U : 0U)) : 
                               ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                 ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                     ? 8U : 0xcU) : 
                                ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                  ? 0xeU : 0xfU))))))) {
                __Vdlyvval__mem__v1 = (0xffU & (((2U 
                                                  & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset))
                                                   ? 
                                                  ((0xff000000U 
                                                    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                       << 0x18U)) 
                                                   | (0xffffffU 
                                                      & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                         >> 8U)))
                                                   : 
                                                  ((0xffff0000U 
                                                    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                       << 0x10U)) 
                                                   | (0xffffU 
                                                      & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                         >> 0x10U))))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset))
                                                   ? 
                                                  ((0xffffff00U 
                                                    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                       << 8U)) 
                                                   | (0xffU 
                                                      & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                         >> 0x18U)))
                                                   : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex)) 
                                                >> 8U));
                __Vdlyvset__mem__v1 = 1U;
                __Vdlyvdim0__mem__v1 = (0xfffffU & 
                                        ((IData)(1U) 
                                         + (0xffffcU 
                                            & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)));
            }
            if ((4U & ((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_type_ex))
                        ? ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                            ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                ? 8U : 4U) : ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                               ? 2U
                                               : 1U))
                        : ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_type_ex))
                            ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned_ex)
                                ? 1U : ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                         ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                             ? 8U : 0xcU)
                                         : ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                             ? 6U : 3U)))
                            : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned_ex)
                                ? ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                    ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                        ? 7U : 3U) : 
                                   ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                     ? 1U : 0U)) : 
                               ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                 ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                     ? 8U : 0xcU) : 
                                ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                  ? 0xeU : 0xfU))))))) {
                __Vdlyvval__mem__v2 = (0xffU & (((2U 
                                                  & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset))
                                                   ? 
                                                  ((0xff000000U 
                                                    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                       << 0x18U)) 
                                                   | (0xffffffU 
                                                      & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                         >> 8U)))
                                                   : 
                                                  ((0xffff0000U 
                                                    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                       << 0x10U)) 
                                                   | (0xffffU 
                                                      & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                         >> 0x10U))))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset))
                                                   ? 
                                                  ((0xffffff00U 
                                                    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                       << 8U)) 
                                                   | (0xffU 
                                                      & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                         >> 0x18U)))
                                                   : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex)) 
                                                >> 0x10U));
                __Vdlyvset__mem__v2 = 1U;
                __Vdlyvdim0__mem__v2 = (0xfffffU & 
                                        ((IData)(2U) 
                                         + (0xffffcU 
                                            & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)));
            }
            if ((8U & ((2U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_type_ex))
                        ? ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                            ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                ? 8U : 4U) : ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                               ? 2U
                                               : 1U))
                        : ((1U & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_type_ex))
                            ? ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned_ex)
                                ? 1U : ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                         ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                             ? 8U : 0xcU)
                                         : ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                             ? 6U : 3U)))
                            : ((IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__data_misaligned_ex)
                                ? ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                    ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                        ? 7U : 3U) : 
                                   ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                     ? 1U : 0U)) : 
                               ((2U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                 ? ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                     ? 8U : 0xcU) : 
                                ((1U & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)
                                  ? 0xeU : 0xfU))))))) {
                __Vdlyvval__mem__v3 = (0xffU & (((2U 
                                                  & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset))
                                                   ? 
                                                  ((0xff000000U 
                                                    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                       << 0x18U)) 
                                                   | (0xffffffU 
                                                      & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                         >> 8U)))
                                                   : 
                                                  ((0xffff0000U 
                                                    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                       << 0x10U)) 
                                                   | (0xffffU 
                                                      & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                         >> 0x10U))))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__wdata_offset))
                                                   ? 
                                                  ((0xffffff00U 
                                                    & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                       << 8U)) 
                                                   | (0xffU 
                                                      & (vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex 
                                                         >> 0x18U)))
                                                   : vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__alu_operand_c_ex)) 
                                                >> 0x18U));
                __Vdlyvset__mem__v3 = 1U;
                __Vdlyvdim0__mem__v3 = (0xfffffU & 
                                        ((IData)(3U) 
                                         + (0xffffcU 
                                            & vlSymsp->TOP__top.__PVT__riscv_core_i__DOT__load_store_unit_i__DOT__data_addr_int)));
            }
        }
    }
    if (__Vdlyvset__mem__v0) {
        vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem[__Vdlyvdim0__mem__v0] 
            = __Vdlyvval__mem__v0;
    }
    if (__Vdlyvset__mem__v1) {
        vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem[__Vdlyvdim0__mem__v1] 
            = __Vdlyvval__mem__v1;
    }
    if (__Vdlyvset__mem__v2) {
        vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem[__Vdlyvdim0__mem__v2] 
            = __Vdlyvval__mem__v2;
    }
    if (__Vdlyvset__mem__v3) {
        vlSymsp->TOP__top__ram_i__dp_ram_i.__PVT__mem[__Vdlyvdim0__mem__v3] 
            = __Vdlyvval__mem__v3;
    }
}

void Vtop_dp_ram__A14::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_dp_ram__A14::_ctor_var_reset\n"); );
    // Body
    __PVT__clk = VL_RAND_RESET_I(1);
    __PVT__en_a_i = VL_RAND_RESET_I(1);
    __PVT__addr_a_i = VL_RAND_RESET_I(20);
    __PVT__wdata_a_i = VL_RAND_RESET_I(32);
    VL_RAND_RESET_W(128, __PVT__rdata_a_o);
    __PVT__we_a_i = VL_RAND_RESET_I(1);
    __PVT__be_a_i = VL_RAND_RESET_I(4);
    __PVT__en_b_i = VL_RAND_RESET_I(1);
    __PVT__addr_b_i = VL_RAND_RESET_I(20);
    __PVT__wdata_b_i = VL_RAND_RESET_I(32);
    __PVT__rdata_b_o = VL_RAND_RESET_I(32);
    __PVT__we_b_i = VL_RAND_RESET_I(1);
    __PVT__be_b_i = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<1048576; ++__Vi0) {
            __PVT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }}
}
