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

vlog -work ./work ../tb/tb_top_dual_std_add_hello.sv

vsim  work.tb_mem_datapath_fast -voptargs="+acc"

add wave *

add wave -position insertpoint  \
sim:/tb_mem_datapath_fast/datapath/racetrack_memory/RT_array_controller/state
add wave -position insertpoint  \
sim:/tb_mem_datapath_fast/datapath/racetrack_memory/enabled_block
add wave -position insertpoint  \
{sim:/tb_mem_datapath_fast/datapath/racetrack_memory/genblk1[0]/RT_block_i/read_current_d_i}
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

add wave -position insertpoint  \
sim:/tb_mem_datapath_fast/datapath/racetrack_memory/mask_int
add wave -position insertpoint  \
sim:/tb_mem_datapath_fast/datapath/racetrack_memory/write_int
add wave -position insertpoint  \
sim:/tb_mem_datapath_fast/datapath/racetrack_memory/word_lines
add wave -position insertpoint  \
sim:/tb_mem_datapath_fast/datapath/ADDR_int
add wave -position insertpoint  \
sim:/tb_mem_datapath_fast/datapath/triplets \
sim:/tb_mem_datapath_fast/datapath/word_sel_tri
add wave -position insertpoint  \
sim:/tb_mem_datapath_fast/datapath/active_triplet
add wave -position insertpoint  \
sim:/tb_mem_datapath_fast/datapath/word_lines_tri
add wave -position insertpoint  \
sim:/tb_mem_datapath_fast/datapath/racetrack_memory/w_pulse_data \
sim:/tb_mem_datapath_fast/datapath/racetrack_memory/w_pulse_mask \
sim:/tb_mem_datapath_fast/datapath/racetrack_memory/w_pulse_program


#time units configauration
configure wave -timelineunits ns


run 3500ns 
