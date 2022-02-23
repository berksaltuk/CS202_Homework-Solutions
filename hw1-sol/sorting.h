/*
* Title: Sorting and Algorithm Efficiency
* Author: Berk Saltuk Yilmaz
* ID: 21903419
* Section: 3
* Assignment: 1
* Description: This file includes the interface of the sorting class, i.e. prototypes of sorting algorithms,
* prototypes of helper methods written by me and prototypes of auxiliary global functions.
*
* In this class, none of the original function prototypes have been changed, only added other functions to make things easy.
*/

#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

class sorting
{
    public:
        void selectionSort(int *arr, const int size, int &compCount, int &moveCount);
        void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
        void quickSort(int *arr, const int size, int &compCount, int &moveCount);
        void radixSort(int *arr, const int size);

        void performanceAnalysis();

    private:
        //Helper Methods
        int indexMax( const int *arr, int size, int &compCount);
        void swap( int &x, int &y, int &moveCount);

        void mergeSort2(int *arr, int first, int last, int &compCount, int &moveCount, const int size);
        void merge( int *arr, int first, int mid, int last, int &moveCount, const int size);

        void quickSort2(int *arr, int first, int last, int &compCount, int &moveCount, const int size);
        int partition( int *arr, int first, int last, int &compCount, int &moveCount, const int size);

        int findMaxOfArray( int *arr, int size);
        void radixSort2( int *arr, const int size, int digitSize);

};


void displayArray(const int *arr, const int size);
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
#endif // SORTING_H
