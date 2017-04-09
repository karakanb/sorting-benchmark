//
// Created by burak on 09.04.2017.
//

#include "SortingBase.h"


SortingBase::SortingBase(int arraySize, char *inputFile, char *outputFile, bool isVerbose, string algorithm) {
    this->arraySize = arraySize;
    this->inputFile = inputFile;
    this->outputFile = outputFile;
    this->isVerbose = isVerbose;
    this->algorithm = algorithm;
}

/**
 * Initialize the numbers array for the runtime tests.
 * @return
 */
void SortingBase::initializeNumbersArray() {

    // Declare and define the parameters.
    int *numbers = new int[arraySize];
    int temporaryNumber = 0;
    int counter = 0;

    ifstream ReadFromFile(inputFile);

    // Read from the file until the end of file.
    while (ReadFromFile >> temporaryNumber && counter < arraySize) {
        numbers[counter] = temporaryNumber;
        counter++;
    }

    ReadFromFile.close();

    // If the number of elements is less than the input parameter, kill the program.
    if (counter < arraySize) {
        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\t" << UNDERLINE_ON << "There are not that much sort in records." << UNDERLINE_OFF << endl;
        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl << endl;
        exit(0);
    }

    this->numbers = numbers;

}

void SortingBase::writeNumbers() {

    int percentage = 0;

    // File writer.
    ofstream WriteToFile(outputFile);

    if (isVerbose) {

        // Pretty print the algorithm runtime.
        cout << endl;
        cout << "--------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\t\t" << UNDERLINE_ON << "Running time of the algorithm" << UNDERLINE_OFF << endl;
        cout << "\t\t    " << runningTime << " microseconds - "
             << runningTime / 1000 << " milliseconds." << endl << endl;
        cout << "--------------------------------------------------------------------------------" << endl << endl;

        cout << "--------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\t\tWriting the sort:   %";

        // Write all of the sort, and display a simple loading bar.
        for (int i = 0; i < arraySize; i++) {

            WriteToFile << numbers[i] << endl;

            // Pretty print the loading view.
            percentage = 100 * i / arraySize;
            cout << "\b";
            if (percentage >= 10) {
                cout << "\b\b" << percentage << "%";
            } else {
                cout << "\b" << percentage << "%";
            }
        }
        WriteToFile.close();

        cout << "\b\b\b" << "100% - Success";
        cout << endl << "\tThe sort have successfully been sorted and written into " << this->outputFile;
        cout << endl << endl;
        cout << "--------------------------------------------------------------------------------" << endl << endl;
    } else {
        // Write sorted numbers.
        for (int i = 0; i < arraySize; i++) {
            WriteToFile << numbers[i] << endl;
        }
        WriteToFile.close();

        cout << algorithm << "," << arraySize << "," << runningTime << endl;

    }

}

void SortingBase::startTimer() {
    runningTime = clock();
}

void SortingBase::endTimer() {
    runningTime = (clock() - runningTime) / (CLOCKS_PER_SEC / 1000000);
}
