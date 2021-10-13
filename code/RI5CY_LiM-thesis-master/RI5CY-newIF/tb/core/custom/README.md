RI5CY Custom Programs for Logic-In-Memory
=========================================
Meaningful test program have been created to demonstrate the validity of 
the Logic-In-Memory architecture:
- bitwise.c
- max_min.c

Programs supported by the compiler
--------------------------------------
RISCV compiler still doesn't support the LIM instructions. In fact, the
compiler gives as result:
- bitwise.hex
- max_min.hex

Programs not supported by the compiler
--------------------------------------
In order to verify the new LIM instructions, the .hex files have been 
manually changed to replace some instructions with the new ones:
- bitwise_lim.hex
- max_min_lim.hex
