[![DOI](https://zenodo.org/badge/469124769.svg)](https://zenodo.org/badge/latestdoi/469124769)

# RISC-Vlim, a RISC-V Framework for Logic-in-Memory Architectures

The aim of the project is to propose a RISC-Vlim microprocessor that supports Logic-in-Memory operations. The RISC-Vlim is based on the RISC-V ISA where the data memory is replaced with a memory capable of doing simple operations on the data stored inside it. The preliminary results demonstrate how the use of such memories can improve the algorithm execution speed, reducing the need of complex solutions and saving energy.\
The project uses the available RISC-V IP and the Logic-in-memory concept in order to improve the average execution time of the RISC-V memory operations and then to reduce the overall execution time in programs.
The goal has been reached by introducing a new memory model, capable to perform logic operations additionally to the simple reads or writes. To exploit this new memory capabilities the RISC-V ISA has been enlarged.

## RISC-V IP Overview
[CV32E40P](https://github.com/openhwgroup/cv32e40p) is a small and efficient, 32-bit, in-order RISC-V core with a 4-stage pipeline that implements
the RV32IM\[F\]C instruction set architecture, and the Xpulp custom extensions for achieving
higher code density, performance, and energy efficiency \[[1](https://doi.org/10.1109/TVLSI.2017.2654506)\], \[[2](https://doi.org/10.1109/PATMOS.2017.8106976)\].
It started its life as a fork of the OR10N CPU core that is based on the OpenRISC ISA.
Then, under the name of RI5CY, it became a RISC-V core (2016), and it has been maintained
by the [PULP platform](https://www.pulp-platform.org/) team until February 2020,
when it has been contributed to [OpenHW Group](https://www.openhwgroup.org/).

## RISC-V with the same interface
The RI5CY-sameIF repository contains the CV32E40P/RISC-V IP that supports Logic-in-memory operations, that mantains the same original interface in order to prioritise the flexibility of the core.

## RISC-V with the new interface
The RI5CY-newIF repository contains the CV32E40P/RISC-V IP that supports Logic-in-memory operations, that has a new interface to maximise the efficiency of the memory operations.


# Prerequisites
Clone the current repository

    $git clone https://github.com/vlsi-nanocomputing/risc-v-lim-architecture.git

Enter the repository directory and run

    $git submodule update --init --recursive

Enter the directory `riscv-gnu-toolchain` and run the configuration script:

    $./configure --prefix=<tool_chain_install_path> --with-arch=rv32ima --with-abi=ilp32

Build the toolchain:

    $make -j N

Where N is the number of threads.

# Usage
Enter the directory `RI5CY-sameIF/tb/core` and modify the Makefile. In particular, change the variable `RISCV_LIB` with your `<tool_chain_install_path>` previously used in the configuration.

Modify variable `MEM_TYPE` inside the Makefile to build the desired memory type.
Available memories:
- Standard memory
- Standard memory with LiM functionalities
- Racetrack memory with LiM functionalities

Racetrack memory supports two different modes:
- Memory mode
- LiM mode

Set the correct parameter MEM_MODE in file `RI5CY-sameIF/tb/core/tb_tob.sv` to choose the wanted configuration.

For executing a sample program run:

    $make custom-vsim-run





