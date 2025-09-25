#! /bin/bash
if [[ -f ./cordic_bm ]]; then
	time ./cordic_bm
else
	time cordic_bm
fi
if [[ -f ./math_bm ]]; then
	time ./math_bm
else
	time math_bm
fi


