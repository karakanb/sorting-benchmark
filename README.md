# Benchmarking Sorting Algorithms

This project aims to provide a basic view over the performances of the most well-knowns sorting algorithms: insertion sort, merge sort and quicksort.  The program is written in C++ with the most basic data structures, no STL data structure is used. Every algorithm is implemented using the plain old arrays. 
   
It basically takes the input set with the input size, and outputs the sorted numbers to the given output file. After execution, the program outputs the running times of the algorithm. If the program is ran with the `-v` option, it prints the 
displays the running time of the program as well as the percentage loader for the file output.

## Building the Project

The project root contains a `CMakeLists.txt` file, which allows creating the builder configurations for various systems. In order to create a `Makefile` in order to use with `make`, you can simply use the following command to create the makefile:
  
`cmake CMakeLists.txt`

After this command, the makefile will be generated, which can be used to build the project with the simple `make` command only. Create the makefile with the `cmake` command, then type `make` and hit enter, the project will be built and an executable called `sorting_benchmarks.out` will be created in the project root.


## Program Arguments

The program can be run in the following format basically:
 
 `./sorting_benchmarks.out inputSize inputFile outputFile algorithm -v
`

In this command, the arguments are:
- `inputSize`: The number of rows that will be read from the input file.
- `inputFile`: The input file containing the numbers to be sorted line by line. An example input file can be found in `data/input.txt`.
- `outputFile`: The output file that the sorted numbers will be printed to.
- `algorithm`: The algorithm that will be used to sort the numbers. Available options are `is` for **insertion sort**, `ms` for **merge sort** and `qs` for **quicksort**.
- `-v`: Optional flag in order to denote the verbose output. If not given, a simple line will be outputted, displaying the algorithm, input size and running time in microseconds. E.g. `qs,1000000,221119`.

## Test Script
There is a bash script for testing the running times in the project root, called `runtime.sh`, which can be run as `./runtime.sh`. The script will output the running time results for the configurations it ran, in the aforementioned CSV format. The script has a timeout value as a hardcoded variable, which stops executing the program if it takes long time and prints the timeout value in *microseconds* as the running time. For now, the timeout is set to 20 seconds, which determines the bounds for insertion sort especially. An example output for test script is as follows:
```bash
burak@burak:~/sorting-benchmarks$ ./runtime.sh
is,10,3
ms,10,5
qs,10,3
is,100,25
ms,100,42
qs,100,18
is,1000,1682
ms,1000,370
qs,1000,217
is,10000,115591
ms,10000,2439
qs,10000,1611
is,1000000,20000000
ms,1000000,320849
qs,1000000,214726
is,5000000,20000000
ms,5000000,1778186
qs,5000000,1222198
```
This data is intended to be used for running time analysis of the algorithms. Further algorithms can be added to the source code, and in order to create meaningful results, this sort of an output seemed to be required.
