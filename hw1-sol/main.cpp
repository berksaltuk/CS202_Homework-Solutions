/*
* Title: Sorting and Algorithm Efficiency
* Author: Berk Saltuk Yilmaz
* ID: 21903419
* Section: 3
* Assignment: 1
* Description: This is the main function where I answer the questions in part-2.
*/

#include "sorting.h"
int main()
{
    int size = 16;
    sorting s;
    int arr1[16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};

    cout << "...Array contents before the sorting..."<< endl;
    displayArray(arr1, size);
    cout << endl;


    int moveCount = 0;
    int compCount = 0;

    s.selectionSort(arr1, size, compCount, moveCount);
    cout << "For the selection sort... Number of key comparisons: " << compCount << ", Number of data moves: " << moveCount << endl;
    displayArray(arr1, size);
    cout << endl;

    int arr2[16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    moveCount = 0;
    compCount = 0;

    s.mergeSort(arr2, size, compCount, moveCount);
    cout << "For the merge sort... Number of key comparisons: " << compCount << ", Number of data moves: " << moveCount << endl;
    displayArray(arr2, size);
    cout << endl;

    int arr3[16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    moveCount = 0;
    compCount = 0;

    s.quickSort(arr3, size, compCount, moveCount);
    cout << "For the quick sort... Number of key comparisons: " << compCount << ", Number of data moves: " << moveCount << endl;
    displayArray(arr3, size);
    cout << endl;

    int arr4[16] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    s.radixSort(arr4, size);
    cout << "After the Radix sort..." << endl;
    displayArray(arr4, size);
    cout << endl;

    s.performanceAnalysis();

    return 0;

}
