#ifndef TEKKOM_MERGESORT_H
#define TEKKOM_MERGESORT_H


#include "SortingBase.h"

class MergeSort : public SortingBase {
public:
    MergeSort(int arraySize, char *inputFile, char *outputFile, bool isVerbose);

    void sort();

private:
    void sortWithMergeSort(int leftIndex, int rightIndex);

    void mergeArrays(int leftMostIndex, int rightMostIndex, int middle);
};


#endif //TEKKOM_MERGESORT_H
