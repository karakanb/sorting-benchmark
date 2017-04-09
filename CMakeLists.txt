cmake_minimum_required(VERSION 3.4)
project(sorting_benchmarks)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/QuickSort.cpp src/QuickSort.h src/globals.h src/SortingBase.cpp src/SortingBase.h src/MergeSort.cpp src/MergeSort.h src/InsertionSort.cpp src/InsertionSort.h)
add_executable(sorting_benchmarks.out ${SOURCE_FILES})