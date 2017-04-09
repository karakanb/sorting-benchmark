#include <iostream>
#include "QuickSort.h"
#include "MergeSort.h"

int main(int argc, char *argv[]) {

    if(argc != 4) {
        cout << "Error occured." << endl;
        return 0;
    }

    int arraySize = atoi(argv[1]);
    char* inputFile = argv[2];
    char* outputFile = argv[3];

    //QuickSort qs(arraySize, inputFile, outputFile);
    //qs.sort();
    MergeSort ms(arraySize, inputFile, outputFile);
    ms.sort();

    return 0;
}