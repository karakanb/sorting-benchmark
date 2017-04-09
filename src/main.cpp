#include <iostream>
#include <getopt.h>
#include "QuickSort.h"
#include "MergeSort.h"
#include "InsertionSort.h"

bool getVerboseOption(int argc, char *argv[]);

std::string toLower(string algorithm);


int main(int argc, char *argv[]) {

    if (argc >= 5) {

        bool isVerbose = getVerboseOption(argc, argv);
        if (isVerbose) { argv++; }

        int arraySize = atoi(argv[1]);
        char *inputFile = argv[2];
        char *outputFile = argv[3];
        std::string algorithm = toLower(argv[4]);

        if (algorithm == QUICK_SORT) {
            QuickSort qs(arraySize, inputFile, outputFile, isVerbose);
            qs.sort();
        } else if (algorithm == MERGE_SORT) {
            MergeSort ms(arraySize, inputFile, outputFile, isVerbose);
            ms.sort();
        } else if (algorithm == INSERTION_SORT) {
            InsertionSort is(arraySize, inputFile, outputFile, isVerbose);
            is.sort();
        }
    }

    return 0;
}

bool getVerboseOption(int argc, char *argv[]) {
    bool isVerbose = false;
    int option = 0;
    while ((option = getopt(argc, argv, "v")) != -1) {
        switch (option) {
            case 'v' :
                isVerbose = true;
            default:
                break;
        }
    }

    return isVerbose;
}

std::string toLower(string algorithm) {
    std::transform(algorithm.begin(), algorithm.end(), algorithm.begin(), ::tolower);
    return algorithm;
}
