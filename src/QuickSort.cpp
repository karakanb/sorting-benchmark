#include "QuickSort.h"

/**
 * Default constructor.
 * @return
 */
QuickSort::QuickSort(int arraySize, char *inputFile, char *outputFile)
        : SortingBase(arraySize, inputFile, outputFile) {}

/**
 * Quicksort wrapper for the numbers file.
 * @param arraySize
 */
void QuickSort::sort() {

    // Get the sort from the file.
    initializeNumbersArray();
    startTimer();

    // Sort the sort.
    sortNumbers(numbers, 0, arraySize - 1);

    // End the chronometer.
    endTimer();

    // Write the sorted sort into the file.
    writeNumbers();
}

/**
 * Recursive quicksort implementation for the integers.
 * @param numbers
 * @param beginning
 * @param end
 */
void QuickSort::sortNumbers(int numbers[], int beginning, int end) {
    if (beginning < end) {
        int pivot = partitionNumbers(numbers, beginning, end);
        sortNumbers(numbers, beginning, pivot - 1);
        sortNumbers(numbers, pivot + 1, end);
    }
}

/**
 * Partition the integer array and return the pivot.
 * @param numbers
 * @param beginning
 * @param end
 * @return
 */
int QuickSort::partitionNumbers(int numbers[], int beginning, int end) {

    // Set the pivot and counter.
    int pivot = numbers[end];
    int swapCounter = beginning;

    // Swap the values based on the comparison.
    for (int counter = beginning; counter < end; counter++) {
        if (numbers[counter] < pivot) {
            swapIntegers(numbers, counter, swapCounter);
            swapCounter++;
        }
    }

    // Place the pivot into the transition point.
    swapIntegers(numbers, swapCounter, end);

    return swapCounter;
}

/**
 * Swap the integers for the number sorting part.
 * @param numbers
 * @param firstIndex
 * @param secondIndex
 */
void QuickSort::swapIntegers(int numbers[], int firstIndex, int secondIndex) {
    int temp = 0;
    temp = numbers[firstIndex];
    numbers[firstIndex] = numbers[secondIndex];
    numbers[secondIndex] = temp;
}
