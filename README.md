# Benchmarking Sorting Algorithms
![OutputSS](http://i64.tinypic.com/xknbz4.png)

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
There is a bash script for testing the running times in the project root, called `runtime.sh`, which can be run as `./runtime.sh`. The script will output the running time results for the configurations it ran, in the aforementioned CSV format to a file under the `outputs` folder with `/outputs/result-timestamp.csv` format. It runs the program 3 times for the same configuration in order to be able to obtain an average result for each of the configurations. It basically runs the algorithms on 3 different versions of the same dataset, a sorted one, a reverse-sorted one and a randomly distributed one. 

The script has a timeout value as a hardcoded variable, which stops executing the program if it takes long time and prints the timeout value in *microseconds* as the running time. For now, the timeout is set to 100 seconds, which determines the bounds for insertion sort especially. An example output for test script is as follows:
```bash
burak@burak:~/sorting-benchmarks$ ./runtime.sh
-------------------- data/asc_input.txt --------------------
is,10,1
is,10,1
is,10,1
ms,10,2
ms,10,3
ms,10,3
qs,10,2
qs,10,1
qs,10,1
is,100,1
is,100,2
is,100,1
ms,100,12
ms,100,11
ms,100,12
qs,100,46
qs,100,46
qs,100,46
is,1000,5
is,1000,5
is,1000,6
ms,1000,139
ms,1000,123
ms,1000,123
qs,1000,4133
qs,1000,4131
qs,1000,4129
is,10000,50
is,10000,50
is,10000,49
ms,10000,1508
ms,10000,1775
ms,10000,1533
qs,10000,406368
qs,10000,408248
qs,10000,408633
is,1000000,5032
is,1000000,4865
is,1000000,4927
ms,1000000,205363
ms,1000000,207415
ms,1000000,205290
qs,1000000,TIMEOUT
qs,1000000,TIMEOUT
qs,1000000,TIMEOUT
is,5000000,25125
is,5000000,25898
is,5000000,25482
ms,5000000,1125933
ms,5000000,1132173
ms,5000000,1187662
qs,5000000,TIMEOUT
qs,5000000,TIMEOUT
qs,5000000,TIMEOUT
-------------------- data/desc_input.txt --------------------
is,10,2
is,10,1
is,10,1
ms,10,3
ms,10,2
ms,10,3
qs,10,1
qs,10,2
qs,10,1
is,100,19
is,100,19
is,100,19
ms,100,12
ms,100,11
ms,100,12
qs,100,31
qs,100,31
qs,100,32
is,1000,1777
is,1000,1762
is,1000,1847
ms,1000,123
ms,1000,124
ms,1000,125
qs,1000,2819
qs,1000,2818
qs,1000,2926
is,10000,180625
is,10000,176037
is,10000,182772
ms,10000,1513
ms,10000,1895
ms,10000,1975
qs,10000,284900
qs,10000,280666
qs,10000,277619
is,1000000,TIMEOUT
is,1000000,TIMEOUT
is,1000000,TIMEOUT
ms,1000000,200063
ms,1000000,204364
ms,1000000,206759
qs,1000000,TIMEOUT
qs,1000000,TIMEOUT
qs,1000000,TIMEOUT
is,5000000,TIMEOUT
is,5000000,TIMEOUT
is,5000000,TIMEOUT
ms,5000000,1148236
ms,5000000,1125092
ms,5000000,1134190
qs,5000000,TIMEOUT
qs,5000000,TIMEOUT
qs,5000000,TIMEOUT
-------------------- data/rand_input.txt --------------------
is,10,1
is,10,1
is,10,1
ms,10,3
ms,10,2
ms,10,3
qs,10,1
qs,10,1
qs,10,2
is,100,11
is,100,11
is,100,12
ms,100,16
ms,100,16
ms,100,16
qs,100,9
qs,100,9
qs,100,10
is,1000,893
is,1000,947
is,1000,1001
ms,1000,194
ms,1000,214
ms,1000,239
qs,1000,119
qs,1000,137
qs,1000,119
is,10000,88553
is,10000,89073
is,10000,87243
ms,10000,2476
ms,10000,2468
ms,10000,2346
qs,10000,1784
qs,10000,1570
qs,10000,1710
is,1000000,TIMEOUT
is,1000000,TIMEOUT
is,1000000,TIMEOUT
ms,1000000,351592
ms,1000000,341622
ms,1000000,340931
qs,1000000,231809
qs,1000000,231750
qs,1000000,231948
is,5000000,TIMEOUT
is,5000000,TIMEOUT
is,5000000,TIMEOUT
ms,5000000,1906215
ms,5000000,1899762
ms,5000000,1937818
qs,5000000,1361325
qs,5000000,1330921
qs,5000000,1348155
```
This data is intended to be used for running time analysis of the algorithms. The values `TIMEOUT` indicate that the program took more than 100 seconds, and therefore timed out and terminated. Further algorithms can be added to the source code, and in order to create meaningful results, this sort of an output seemed to be required.

## Why?
Because why not. It started as a course project, however I think this would be beneficial for understanding the running time complexities of these algorithms. A more detailed analysis may be generated based on this code, or it would be just a simple benchmark between these algorithms, or it may be helpful to someone searching for how to implement one of these algorithms in C++. This may even be useful for someone looking to test the boundaries of the insertion sort, which he/she doesn't know that **it may takes more than 7 hours for a few million numbers while quicksort takes a few seconds**, which would be a great lesson on time complexities. Btw, take a picture of me like I didn't try this before. :sunglasses: 

## License
The project is licensed under MIT License.