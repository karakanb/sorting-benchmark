#!/bin/bash
elements=(10 100 1000)
for numberOfElements in "${elements[@]}"
do
    echo "Number of elements: $numberOfElements"
    ./sorting_benchmarks.out $numberOfElements data/input.txt data/output.txt is
#	echo "Number of elements: $numberOfElements"
#	for resultNodes in "${closest[@]}"
#	do
#		./a.out $numberOfElements $resultNodes $1 123 123 >> runtime.txt 2>&1
#		echo " -- Number of result nodes: $resultNodes"
#	done
done
