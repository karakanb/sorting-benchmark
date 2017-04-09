#!/bin/bash

timeoutOccuredExitCode=124
timeoutLength=10
timeoutInMilliseconds=$(($timeoutLength * 1000000))

function runScript {

    timeout $timeoutLength ./sorting_benchmarks.out $1 data/input.txt data/output.txt $2
    if [ $? -eq $timeoutOccuredExitCode ]
    then
        echo $2,$1,$timeoutInMilliseconds
    fi
}

elements=(10 100 1000 10000 1000000 5000000)
algorithms=(is ms qs)
for numberOfElements in "${elements[@]}"
do
    for algorithm in "${algorithms[@]}"
    do
        runScript $numberOfElements $algorithm
    done

#	echo "Number of elements: $numberOfElements"
#	for resultNodes in "${closest[@]}"
#	do
#		./a.out $numberOfElements $resultNodes $1 123 123 >> runtime.txt 2>&1
#		echo " -- Number of result nodes: $resultNodes"
#	done
done
