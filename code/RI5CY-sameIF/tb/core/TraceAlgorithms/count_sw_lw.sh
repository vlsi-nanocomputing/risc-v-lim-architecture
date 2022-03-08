#!/bin/bash
for f in ./*.log; do
	echo $f
	n_sw=$(grep -E -o 'sw_*' $f | wc -l)
	n_lw=$(grep -E -o 'lw_*' $f | wc -l)
	echo "SW=$n_sw"
	echo "LW=$n_lw"
done
