//
// Created by burak on 09.04.2017.
//

#ifndef TEKKOM_SORTINGBASE_H
#define TEKKOM_SORTINGBASE_H

#include "globals.h"

class SortingBase {
public:
    SortingBase(int arraySize, char* inputFile, char* outputFile);

protected:
    int arraySize;
    int *numbers;
    char* inputFile;
    char* outputFile;
    time_t runningTime;

    void startTimer();
    void endTimer();
    void initializeNumbersArray();
    void writeNumbers(int *sortedNumbers);

};


#endif //TEKKOM_SORTINGBASE_H
