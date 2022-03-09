// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef _VTOP_RAM__A14_H_
#define _VTOP_RAM__A14_H_  // guard

#include "verilated_heavy.h"
#include "Vtop__Dpi.h"

//==========

class Vtop__Syms;
class Vtop_VerilatedVcd;
class Vtop_dp_ram__A14;


//----------

VL_MODULE(Vtop_ram__A14) {
  public:
    // CELLS
    Vtop_dp_ram__A14* dp_ram_i;
    
    // PORTS
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__instr_req_i,0,0);
    VL_OUT8(__PVT__instr_rvalid_o,0,0);
    VL_OUT8(__PVT__instr_gnt_o,0,0);
    VL_IN8(__PVT__data_req_i,0,0);
    VL_IN8(__PVT__data_we_i,0,0);
    VL_IN8(__PVT__data_be_i,3,0);
    VL_OUT8(__PVT__data_rvalid_o,0,0);
    VL_OUT8(__PVT__data_gnt_o,0,0);
    VL_IN(__PVT__instr_addr_i,19,0);
    VL_OUTW(__PVT__instr_rdata_o,127,0,4);
    VL_IN(__PVT__data_addr_i,19,0);
    VL_IN(__PVT__data_wdata_i,31,0);
    VL_OUT(__PVT__data_rdata_o,31,0);
    
    // INTERNAL VARIABLES
  private:
    Vtop__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop_ram__A14);  ///< Copying not allowed
  public:
    Vtop_ram__A14(const char* name = "TOP");
    ~Vtop_ram__A14();
    
    // INTERNAL METHODS
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _sequent__TOP__top__ram_i__3(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__top__ram_i__1(Vtop__Syms* __restrict vlSymsp);
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
