//
// Created by burak on 09.04.2017.
//

#ifndef TEKKOM_SORTINGBASE_H
#define TEKKOM_SORTINGBASE_H

#include "globals.h"

class SortingBase {
public:
    SortingBase(int arraySize, char *inputFile, char *outputFile, bool isVerbose, string algorithm);

protected:
    int arraySize;
    int *numbers;
    char *inputFile;
    char *outputFile;
    bool isVerbose;
    time_t runningTime;
    string algorithm;

    void startTimer();

    void endTimer();

    void initializeNumbersArray();

    void writeNumbers();

    string getAlgorithmName();

};


#endif //TEKKOM_SORTINGBASE_H
