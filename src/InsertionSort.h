#ifndef SORTING_BENCHMARKS_INSERTIONSORT_H
#define SORTING_BENCHMARKS_INSERTIONSORT_H

#include "SortingBase.h"

class InsertionSort : SortingBase{
public:
    InsertionSort(int arraySize, char *inputFile, char *outputFile);
    void sort();

private:
    void sortWithInsertionSort();
};


#endif //SORTING_BENCHMARKS_INSERTIONSORT_H
