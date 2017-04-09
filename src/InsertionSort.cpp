#include "InsertionSort.h"

InsertionSort::InsertionSort(int arraySize, char *inputFile, char *outputFile, bool isVerbose)
        : SortingBase(arraySize, inputFile, outputFile, isVerbose, INSERTION_SORT) {}

void InsertionSort::sort() {
    initializeNumbersArray();
    startTimer();
    sortWithInsertionSort();
    endTimer();
    writeNumbers();
}

void InsertionSort::sortWithInsertionSort() {
    for (int counter = 0; counter < arraySize; counter++) {
        int currentNumber = numbers[counter];
        int j = counter - 1;
        while (j >= 0 && numbers[j] > currentNumber) {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = currentNumber;
    }
}
