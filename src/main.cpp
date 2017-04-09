#include <iostream>
#include "QuickSort.h"
#include "MergeSort.h"
#include "InsertionSort.h"

int main(int argc, char *argv[]) {

    if (argc != 5) {
        int arraySize = atoi(argv[1]);
        char *inputFile = argv[2];
        char *outputFile = argv[3];
        std::string algorithm = argv[4];
        std::transform(algorithm.begin(), algorithm.end(), algorithm.begin(), ::tolower);

        if (algorithm == QUICK_SORT) {
            QuickSort qs(arraySize, inputFile, outputFile);
            qs.sort();
        } else if (algorithm == MERGE_SORT) {
            MergeSort ms(arraySize, inputFile, outputFile);
            ms.sort();
        } else if (algorithm == INSERTION_SORT) {
            InsertionSort is(arraySize, inputFile, outputFile);
            is.sort();
        }
    }

    return 0;
}