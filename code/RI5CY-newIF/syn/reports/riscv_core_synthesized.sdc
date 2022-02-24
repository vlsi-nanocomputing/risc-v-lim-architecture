###################################################################

# Created by write_sdc on Tue Jun 16 01:35:05 2020

###################################################################
set sdc_version 2.1

set_units -time ps -resistance kOhm -capacitance fF -voltage V -current uA
create_clock -name clk_i  -period 5  -waveform {0 2.5}
set_max_delay 5  -from [list [get_ports clk_i] [get_ports rst_ni] [get_ports en_a_i]           \
[get_ports {addr_a_i[9]}] [get_ports {addr_a_i[8]}] [get_ports {addr_a_i[7]}]  \
[get_ports {addr_a_i[6]}] [get_ports {addr_a_i[5]}] [get_ports {addr_a_i[4]}]  \
[get_ports {addr_a_i[3]}] [get_ports {addr_a_i[2]}] [get_ports {addr_a_i[1]}]  \
[get_ports {addr_a_i[0]}] [get_ports {wdata_a_i[31]}] [get_ports               \
{wdata_a_i[30]}] [get_ports {wdata_a_i[29]}] [get_ports {wdata_a_i[28]}]       \
[get_ports {wdata_a_i[27]}] [get_ports {wdata_a_i[26]}] [get_ports             \
{wdata_a_i[25]}] [get_ports {wdata_a_i[24]}] [get_ports {wdata_a_i[23]}]       \
[get_ports {wdata_a_i[22]}] [get_ports {wdata_a_i[21]}] [get_ports             \
{wdata_a_i[20]}] [get_ports {wdata_a_i[19]}] [get_ports {wdata_a_i[18]}]       \
[get_ports {wdata_a_i[17]}] [get_ports {wdata_a_i[16]}] [get_ports             \
{wdata_a_i[15]}] [get_ports {wdata_a_i[14]}] [get_ports {wdata_a_i[13]}]       \
[get_ports {wdata_a_i[12]}] [get_ports {wdata_a_i[11]}] [get_ports             \
{wdata_a_i[10]}] [get_ports {wdata_a_i[9]}] [get_ports {wdata_a_i[8]}]         \
[get_ports {wdata_a_i[7]}] [get_ports {wdata_a_i[6]}] [get_ports               \
{wdata_a_i[5]}] [get_ports {wdata_a_i[4]}] [get_ports {wdata_a_i[3]}]          \
[get_ports {wdata_a_i[2]}] [get_ports {wdata_a_i[1]}] [get_ports               \
{wdata_a_i[0]}] [get_ports we_a_i] [get_ports {be_a_i[3]}] [get_ports          \
{be_a_i[2]}] [get_ports {be_a_i[1]}] [get_ports {be_a_i[0]}] [get_ports        \
en_b_i] [get_ports {addr_b_i[9]}] [get_ports {addr_b_i[8]}] [get_ports         \
{addr_b_i[7]}] [get_ports {addr_b_i[6]}] [get_ports {addr_b_i[5]}] [get_ports  \
{addr_b_i[4]}] [get_ports {addr_b_i[3]}] [get_ports {addr_b_i[2]}] [get_ports  \
{addr_b_i[1]}] [get_ports {addr_b_i[0]}] [get_ports {wdata_b_i[31]}]           \
[get_ports {wdata_b_i[30]}] [get_ports {wdata_b_i[29]}] [get_ports             \
{wdata_b_i[28]}] [get_ports {wdata_b_i[27]}] [get_ports {wdata_b_i[26]}]       \
[get_ports {wdata_b_i[25]}] [get_ports {wdata_b_i[24]}] [get_ports             \
{wdata_b_i[23]}] [get_ports {wdata_b_i[22]}] [get_ports {wdata_b_i[21]}]       \
[get_ports {wdata_b_i[20]}] [get_ports {wdata_b_i[19]}] [get_ports             \
{wdata_b_i[18]}] [get_ports {wdata_b_i[17]}] [get_ports {wdata_b_i[16]}]       \
[get_ports {wdata_b_i[15]}] [get_ports {wdata_b_i[14]}] [get_ports             \
{wdata_b_i[13]}] [get_ports {wdata_b_i[12]}] [get_ports {wdata_b_i[11]}]       \
[get_ports {wdata_b_i[10]}] [get_ports {wdata_b_i[9]}] [get_ports              \
{wdata_b_i[8]}] [get_ports {wdata_b_i[7]}] [get_ports {wdata_b_i[6]}]          \
[get_ports {wdata_b_i[5]}] [get_ports {wdata_b_i[4]}] [get_ports               \
{wdata_b_i[3]}] [get_ports {wdata_b_i[2]}] [get_ports {wdata_b_i[1]}]          \
[get_ports {wdata_b_i[0]}] [get_ports we_b_i] [get_ports {be_b_i[3]}]          \
[get_ports {be_b_i[2]}] [get_ports {be_b_i[1]}] [get_ports {be_b_i[0]}]        \
[get_ports gnt_b_i] [get_ports logic_in_memory_b_i] [get_ports                 \
{opcode_mem_b_i[2]}] [get_ports {opcode_mem_b_i[1]}] [get_ports                \
{opcode_mem_b_i[0]}] [get_ports {asize_mem_b_i[31]}] [get_ports                \
{asize_mem_b_i[30]}] [get_ports {asize_mem_b_i[29]}] [get_ports                \
{asize_mem_b_i[28]}] [get_ports {asize_mem_b_i[27]}] [get_ports                \
{asize_mem_b_i[26]}] [get_ports {asize_mem_b_i[25]}] [get_ports                \
{asize_mem_b_i[24]}] [get_ports {asize_mem_b_i[23]}] [get_ports                \
{asize_mem_b_i[22]}] [get_ports {asize_mem_b_i[21]}] [get_ports                \
{asize_mem_b_i[20]}] [get_ports {asize_mem_b_i[19]}] [get_ports                \
{asize_mem_b_i[18]}] [get_ports {asize_mem_b_i[17]}] [get_ports                \
{asize_mem_b_i[16]}] [get_ports {asize_mem_b_i[15]}] [get_ports                \
{asize_mem_b_i[14]}] [get_ports {asize_mem_b_i[13]}] [get_ports                \
{asize_mem_b_i[12]}] [get_ports {asize_mem_b_i[11]}] [get_ports                \
{asize_mem_b_i[10]}] [get_ports {asize_mem_b_i[9]}] [get_ports                 \
{asize_mem_b_i[8]}] [get_ports {asize_mem_b_i[7]}] [get_ports                  \
{asize_mem_b_i[6]}] [get_ports {asize_mem_b_i[5]}] [get_ports                  \
{asize_mem_b_i[4]}] [get_ports {asize_mem_b_i[3]}] [get_ports                  \
{asize_mem_b_i[2]}] [get_ports {asize_mem_b_i[1]}] [get_ports                  \
{asize_mem_b_i[0]}]]  -to [list [get_ports {rdata_a_o[31]}] [get_ports {rdata_a_o[30]}] [get_ports  \
{rdata_a_o[29]}] [get_ports {rdata_a_o[28]}] [get_ports {rdata_a_o[27]}]       \
[get_ports {rdata_a_o[26]}] [get_ports {rdata_a_o[25]}] [get_ports             \
{rdata_a_o[24]}] [get_ports {rdata_a_o[23]}] [get_ports {rdata_a_o[22]}]       \
[get_ports {rdata_a_o[21]}] [get_ports {rdata_a_o[20]}] [get_ports             \
{rdata_a_o[19]}] [get_ports {rdata_a_o[18]}] [get_ports {rdata_a_o[17]}]       \
[get_ports {rdata_a_o[16]}] [get_ports {rdata_a_o[15]}] [get_ports             \
{rdata_a_o[14]}] [get_ports {rdata_a_o[13]}] [get_ports {rdata_a_o[12]}]       \
[get_ports {rdata_a_o[11]}] [get_ports {rdata_a_o[10]}] [get_ports             \
{rdata_a_o[9]}] [get_ports {rdata_a_o[8]}] [get_ports {rdata_a_o[7]}]          \
[get_ports {rdata_a_o[6]}] [get_ports {rdata_a_o[5]}] [get_ports               \
{rdata_a_o[4]}] [get_ports {rdata_a_o[3]}] [get_ports {rdata_a_o[2]}]          \
[get_ports {rdata_a_o[1]}] [get_ports {rdata_a_o[0]}] [get_ports               \
{rdata_b_o[31]}] [get_ports {rdata_b_o[30]}] [get_ports {rdata_b_o[29]}]       \
[get_ports {rdata_b_o[28]}] [get_ports {rdata_b_o[27]}] [get_ports             \
{rdata_b_o[26]}] [get_ports {rdata_b_o[25]}] [get_ports {rdata_b_o[24]}]       \
[get_ports {rdata_b_o[23]}] [get_ports {rdata_b_o[22]}] [get_ports             \
{rdata_b_o[21]}] [get_ports {rdata_b_o[20]}] [get_ports {rdata_b_o[19]}]       \
[get_ports {rdata_b_o[18]}] [get_ports {rdata_b_o[17]}] [get_ports             \
{rdata_b_o[16]}] [get_ports {rdata_b_o[15]}] [get_ports {rdata_b_o[14]}]       \
[get_ports {rdata_b_o[13]}] [get_ports {rdata_b_o[12]}] [get_ports             \
{rdata_b_o[11]}] [get_ports {rdata_b_o[10]}] [get_ports {rdata_b_o[9]}]        \
[get_ports {rdata_b_o[8]}] [get_ports {rdata_b_o[7]}] [get_ports               \
{rdata_b_o[6]}] [get_ports {rdata_b_o[5]}] [get_ports {rdata_b_o[4]}]          \
[get_ports {rdata_b_o[3]}] [get_ports {rdata_b_o[2]}] [get_ports               \
{rdata_b_o[1]}] [get_ports {rdata_b_o[0]}] [get_ports rvalid_b_o]]
