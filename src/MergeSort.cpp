#include "MergeSort.h"

/**
 * Split the array recursively, then send both parts to the merger function.
 * @param allNodes
 * @param leftIndex
 * @param rightIndex
 */
void MergeSort::sortWithMergeSort(int leftIndex, int rightIndex) {

    // If not the base case, call the method recursively.
    if (leftIndex < rightIndex) {

        // Get the middle index.
        int middle = (leftIndex + rightIndex) / 2;

        // Send both parts of the array into a recursive call to split again.
        sortWithMergeSort(leftIndex, middle);
        sortWithMergeSort(middle + 1, rightIndex);

        // Merge splitted arrays.
        mergeArrays(leftIndex, rightIndex, middle);
    }
}

/**
 * Merge the given arrays according to their distance to the desired node in an increasing order.
 * @param allNodes
 * @param leftMostIndex
 * @param rightMostIndex
 * @param middle
 */
void MergeSort::mergeArrays(int leftMostIndex, int rightMostIndex, int middle) {

    // Parameters to hold the initial indexes, which will be modified through the merging process.
    int leftCounter = leftMostIndex;
    int rightCounter = middle + 1;
    int *sortedNodes = new int[rightMostIndex - leftMostIndex + 1];

    // Loop until the given part is sorted and inserted back into its original place.
    for (int counter = 0; counter < (rightMostIndex - leftMostIndex); counter++) {

        // If the node at the left is closer to the desired node, insert it. If not, do the otherwise.
        if (numbers[leftCounter] <= numbers[rightCounter]) {
            sortedNodes[counter] = numbers[leftCounter];

            // Increment the counter.
            leftCounter++;
        } else {
            sortedNodes[counter] = numbers[rightCounter];

            // Increment the counter.
            rightCounter++;
        }

        // If all the nodes at the left inserted to the temporary array, get the remaining values one by one.
        if (rightCounter == rightMostIndex + 1) {
            for (int i = leftCounter; i <= middle; i++) {
                counter++;
                sortedNodes[counter] = numbers[i];

            }
            break;
        } else if (leftCounter == middle + 1) {
            for (int i = rightCounter; i <= rightMostIndex; i++) {
                counter++;
                sortedNodes[counter] = numbers[i];
            }
            break;
        }
    }

    // Insert the sorted values back into their places.
    for (int counter = leftMostIndex; counter <= rightMostIndex; counter++) {
        numbers[counter] = sortedNodes[counter - leftMostIndex];
    }
}

MergeSort::MergeSort(int arraySize, char *inputFile, char *outputFile) : SortingBase(arraySize, inputFile,
                                                                                     outputFile) {}

void MergeSort::sort() {
    initializeNumbersArray();
    startTimer();
    sortWithMergeSort(0, arraySize - 1);
    endTimer();
    writeNumbers();
}

