#ifndef TEKKOM_QUICKSORT_H
#define TEKKOM_QUICKSORT_H

#include "globals.h"
#include "SortingBase.h"

class QuickSort : public SortingBase {
public:
    void sort();

    QuickSort(int arraySize, char *inputFile, char *outputFile, bool isVerbose);

private:
    void sortNumbers(int numbers[], int beginning, int end);

    int partitionNumbers(int numbers[], int beginning, int end);

    void swapIntegers(int *numbers, int firstIndex, int secondIndex);

};


#endif //TEKKOM_QUICKSORT_H
