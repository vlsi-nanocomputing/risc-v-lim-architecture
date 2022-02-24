#=================================
# Timing constraints
#=================================
# Create clock
set CLK_PERIOD   5
set CLK_PORT clk_i
create_clock -name $CLK_PORT -period $CLK_PERIOD

# Set max delay on combinational IO paths
set_max_delay $CLK_PERIOD -from [all_inputs] -to [all_outputs]

#=================================
# Area constraints
#=================================


#=================================
# Power constraints
#=================================
