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
There is a bash script for testing the running times in the project root, called `runtime.sh`, which can be run as `./runtime.sh`. The script will output the running time results for the configurations it ran, in the aforementioned CSV format. It runs the program 3 times for the same configuration in order to be able to obtain an average result for each of the configurations.

The script has a timeout value as a hardcoded variable, which stops executing the program if it takes long time and prints the timeout value in *microseconds* as the running time. For now, the timeout is set to 20 seconds, which determines the bounds for insertion sort especially. An example output for test script is as follows:
```bash
burak@burak:~/sorting-benchmarks$ ./runtime.sh
is,10,2
is,10,2
is,10,3
ms,10,7
ms,10,5
ms,10,6
qs,10,3
qs,10,3
qs,10,3
is,100,20
is,100,22
is,100,21
ms,100,29
ms,100,29
ms,100,40
qs,100,17
qs,100,17
qs,100,16
is,1000,1447
is,1000,1365
is,1000,1299
ms,1000,352
ms,1000,287
ms,1000,297
qs,1000,156
qs,1000,156
qs,1000,156
is,10000,95042
is,10000,130499
is,10000,127997
ms,10000,2564
ms,10000,2450
ms,10000,2357
qs,10000,1524
qs,10000,1476
qs,10000,1536
is,1000000,20000000
is,1000000,20000000
is,1000000,20000000
ms,1000000,317632
ms,1000000,315556
ms,1000000,341633
qs,1000000,221509
qs,1000000,218456
qs,1000000,230148
is,5000000,20000000
is,5000000,20000000
is,5000000,20000000
ms,5000000,1751429
ms,5000000,1766259
ms,5000000,1790221
qs,5000000,1305036
qs,5000000,1295139
qs,5000000,1258507
```
This data is intended to be used for running time analysis of the algorithms. The values `20000000` indicate that the program took more than 20 seconds, and therefore terminated. Further algorithms can be added to the source code, and in order to create meaningful results, this sort of an output seemed to be required.

## Why?
Because why not. It started as a course project, however I think this would be beneficial for understanding the running time complexities of these algorithms. A more detailed analysis may be generated based on this code, or it would be just a simple benchmark between these algorithms, or it may be helpful to someone searching for how to implement one of these algorithms in C++. This may even be useful for someone looking to test the boundaries of the insertion sort, which he/she doesn't know that **it may takes more than 7 hours for a few million numbers while quicksort takes a few seconds**, which would be a great lesson on time complexities. Btw, take a picture of me like I didn't try this before. :sunglasses: 

## License
The project is licensed under MIT License.
