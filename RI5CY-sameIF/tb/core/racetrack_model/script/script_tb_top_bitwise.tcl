#compile SV files

vlog -work ./work ../rtl/include/racetrack_defines.sv
vlog -work ./work ../rtl/RT_cell.sv
vlog -work ./work ../rtl/RT_read_write_SOT.sv
vlog -work ./work ../rtl/pNML_NAND_NOR.sv
vlog -work ./work ../rtl/pNML_NAND_NOR_SOT.sv
vlog -work ./work ../rtl/RT_32_8_4_line.sv
vlog -work ./work ../rtl/RT_32_8_4_MU.sv
vlog -work ./work ../rtl/RT_block.sv
vlog -work ./work ../rtl/shifter.sv
vlog -work ./work ../rtl/FSM.sv
vlog -work ./work ../rtl/RT_memory.sv
vlog -work ./work ../rtl/mem_datapath.sv

#compile TB 

vlog -work ./work ../tb/tb_mem_datapath_tb_top_bitwise.sv

vsim  work.tb_mem_datapath_fast  -voptargs="+acc"

add wave *

add wave -position insertpoint  \
sim:/tb_mem_datapath_fast/datapath/racetrack_memory/RT_array_controller/state
add wave -position insertpoint  \
sim:/tb_mem_datapath_fast/datapath/racetrack_memory/enabled_block
add wave -position insertpoint  \
{sim:/tb_mem_datapath_fast/datapath/racetrack_memory/genblk1[0]/RT_block_i/r_data_o}
add wave -position insertpoint  \
{sim:/tb_mem_datapath_fast/datapath/racetrack_memory/genblk1[0]/RT_block_i/current_read_i}
add wave -position insertpoint  \
{sim:/tb_mem_datapath_fast/datapath/racetrack_memory/genblk1[0]/RT_block_i/out_select_i}
add wave -position insertpoint  \
sim:/tb_mem_datapath_fast/datapath/racetrack_memory/shift_pulses
add wave -position insertpoint  \
sim:/tb_mem_datapath_fast/datapath/racetrack_memory/data_d
add wave -position insertpoint  \
sim:/tb_mem_datapath_fast/datapath/racetrack_memory/en_lim_buf
add wave -position insertpoint  \
sim:/tb_mem_datapath_fast/datapath/racetrack_memory/lim_buf



#time units configauration
configure wave -timelineunits ns


run 3500ns 
