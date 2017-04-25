#!/bin/bash

# Variables for setting timeout on test calls.
timeoutOccuredExitCode=124
timeoutLength=600
timeoutInMilliseconds=$(($timeoutLength * 1000000))

mkdir -p outputs
fileName=outputs/result
currentTime=$(date "+%s")
outputFileName=$fileName-$currentTime.data

# Run the script with timeout.
function runScript {

    timeout $timeoutLength ./sorting_benchmarks.out $1 data/input.txt data/output.txt $2
    if [ $? -eq $timeoutOccuredExitCode ]
    then
        echo $2,$1,"TIMEOUT"
    fi
}

# Number of elements and algorithms arrays.
elements=(10 100)
algorithms=(is ms qs)

# Loop over the elements and algorithms and run the tests for every combination.
for numberOfElements in "${elements[@]}"
do
    for algorithm in "${algorithms[@]}"
    do
        for count in {1..3}
        do
            runScript $numberOfElements $algorithm >> $outputFileName
        done
    done
done
