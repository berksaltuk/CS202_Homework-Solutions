/*
* Title: Sorting and Algorithm Efficiency
* Author: Berk Saltuk Yilmaz
* ID: 21903419
* Section: 3
* Assignment: 1
* Description: This is the file where I implement the functions in the header class.
* Blocks are separated by header comments.
*/

#include "sorting.h"
#include <cstdlib>
#include <cmath>
/*
*
* Selection Sort Block
*
*/

void sorting::selectionSort(int *arr, const int size, int &compCount, int &moveCount)
{
    for( int last = size - 1; last >= 1; --last)
    {
        int largest = indexMax( arr, last + 1, compCount);
        swap( arr[largest], arr[last], moveCount);
    }
}

int sorting::indexMax( const int *arr, int size, int &compCount)
{
    int forNow = 0;

    for( int cur = 1; cur < size; ++cur)
    {
        if( arr[cur] > arr[forNow])
        {
            forNow = cur;
        }
        compCount++;
    }

    return forNow;
}

void sorting::swap( int &x, int &y, int &moveCount)
{

    int temp = x;
    x = y;
    y = temp;
    moveCount += 3;
}

/*
*
* Merge Sort Block
*
*/
void sorting::mergeSort(int *arr, const int size, int &compCount, int &moveCount)
{
    int last = size - 1;
    int first = 0;

    mergeSort2( arr, first, last, compCount, moveCount, size);
}

void sorting::mergeSort2(int *arr, int first, int last, int &compCount, int &moveCount, const int size)
{
    if( first < last)
    {
        compCount++;

        int mid = ( first + last )/2;
        mergeSort2( arr, first, mid, compCount, moveCount, size);
        mergeSort2( arr, mid + 1, last, compCount, moveCount, size);
        merge( arr, first, mid, last, moveCount, size);
    }
}

void sorting::merge( int *arr, int first, int mid, int last, int &moveCount, const int size)
{
    int tempArr[size];

    int firstSub1 = first;
    int lastSub1 = mid;
    int firstSub2 = mid + 1;
    int lastSub2 = last;

    int i = firstSub1;

    for( ; (firstSub1 <= lastSub1) && (firstSub2 <= lastSub2); ++i)
    {

        if( arr[firstSub1] < arr[firstSub2])
        {
            tempArr[i] = arr[firstSub1];
            ++firstSub1;
        }
        else
        {
            tempArr[i] = arr[firstSub2];
            ++firstSub2;
        }
    }

    for( ; firstSub1 <= lastSub1; ++firstSub1, ++i)
    {

        tempArr[i] = arr[firstSub1];
    }
    for( ; firstSub2 <= lastSub2; ++firstSub2, ++i)
    {

        tempArr[i] = arr[firstSub2];
    }

    for( i = first; i <= last; ++i)
    {
        moveCount++;
        arr[i] = tempArr[i];
    }
}

/*
*
* Quick Sort Block
*
*/
void sorting::quickSort(int *arr, const int size, int &compCount, int &moveCount)
{
    int last = size;
    int first = 0;

    quickSort2(arr, first, last, compCount, moveCount, size);
}

void sorting::quickSort2(int *arr, int first, int last, int &compCount, int &moveCount, const int size)
{
   int pivotIndex;

   if( first < last)
   {
       pivotIndex = partition(arr, first, last, compCount, moveCount, size);
       quickSort2( arr, first, pivotIndex - 1, compCount, moveCount, size);
       quickSort2( arr, pivotIndex + 1, last, compCount, moveCount, size);
   }
}

int sorting::partition( int *arr, int first, int last, int &compCount, int &moveCount, const int size)
{

    int unknown;

    int last1 = first + 1;


    for(unknown = first + 1; unknown < last; unknown++)
    {

        compCount++;
        if( arr[unknown] <= arr[ first ])
        {
            swap( arr[unknown], arr[last1], moveCount);
            last1++;
        }
    }

    swap( arr[first], arr[last1 - 1], moveCount);
    return last1;
}

/*
*
* Radix Sort Block
*
*/
void sorting::radixSort(int *arr, const int size)
{
    int maxNum = findMaxOfArray( arr, size);
    int digitNum = 0;
    for( int divide = 1; maxNum / divide > 0; divide *= 10)
    {
        digitNum++;
    }

    radixSort2( arr, size, digitNum);
}

int sorting::findMaxOfArray( int *arr, int size)
{
    int max = arr[0];

    for( int i = 1; i < size; i++)
    {
        if( max < arr[i])
        {
            max = arr[i];
        }
    }

    return max;
}

void sorting::radixSort2( int *arr, const int size, int digitSize)
{
    for ( int j = 1 ; j <= digitSize; j++ )
    {
        int digitGroup[ 10 ][size];

        for ( int x = 0; x < 10; x++)
        {
            for( int y = 0; y < size; y++)
            {
                digitGroup[x][y] = 0;
            }
        }
        int counter[10] = {0};


        for ( int i = 0; i < size; i++)
        {
            int k;

            k = (int)(arr[i] / pow(10, j-1));
            k = k % 10;

            digitGroup[k][counter[k]] = arr[i];
            counter[k]++;
        }

        int arrIndex = 0;
        for( int a = 0; a < 10; a++)
        {
            for( int b = 0; b < counter[a]; b++)
            {
                arr[ arrIndex ] = digitGroup[a][b];
                arrIndex++;
            }
        }
    }
}

/*
*
* Performance Analysis Block
*
*/
void sorting::performanceAnalysis()
{

for( int j = 0; j < 3; j++ )
{
    if (j == 0)
    {
        cout << "-----------------------------------------------------------------" << endl;
        cout << "----------------------- For Random Arrays -----------------------" << endl;
        cout << "-----------------------------------------------------------------" << endl;
    }
    else if( j == 1)
    {
        cout << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "---------------------- For Ascending Arrays ---------------------" << endl;
        cout << "-----------------------------------------------------------------" << endl;
    }
    else
    {
        cout << endl;
        cout << "-----------------------------------------------------------------" << endl;
        cout << "--------------------- For Descending Arrays ---------------------" << endl;
        cout << "-----------------------------------------------------------------" << endl;
    }

    for( int i = 0; i < 4; i++)
    {
        if( i == 0)
        {
            cout << "Analysis of Selection Sort\n";
        }
        else if( i == 1)
        {
            cout << "Analysis of Merge Sort\n";
        }
        else if( i == 2)
        {
            cout << "Analysis of Quick Sort\n";
        }
        else if( i == 3)
        {
            cout << "Analysis of Radix Sort\n";
        }

        if( i != 3)
        {
            cout << "Array Size" <<setw (20)  << setfill  (' ') << "Elapsed Time"<<setw (20)  << setfill  (' ')
        << "compCount" << setw (20)  << setfill  (' ') << "moveCount" << endl;
        }
        else
        {
             cout << "Array Size" <<setw (20)  << setfill  (' ') << "Elapsed Time" << endl;
        }
        for( int size = 6000; size < 34000; size += 4000)
        {
            double duration;
            int compCount = 0;
            int moveCount = 0;
            int *arr1;
            int *arr2;
            int *arr3;
            int *arr4;

            if( j == 0)
                createRandomArrays(arr1, arr2, arr3, arr4, size);
            else if( j == 1)
                createAscendingArrays(arr1, arr2,arr3,arr4, size);
            else if( j == 2)
                createDescendingArrays(arr1, arr2,arr3,arr4, size);


            clock_t startTime = clock();
            if( i == 0)
                selectionSort( arr1, size, compCount, moveCount);

            else if( i == 1)
                mergeSort( arr2, size, compCount, moveCount);

            else if ( i == 2)
                quickSort( arr3, size, compCount, moveCount);

            else if( i == 3)
                radixSort( arr4, size);

            duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            if(size == 6000)
                cout << size << setw (15)  << setfill  (' ');
            else
                cout << size << setw (14)  << setfill  (' ');

            if( i != 3)
                cout<< duration << " ms" <<setw (28)  << setfill  (' ')<< compCount << setw (20)  << setfill  (' ') << moveCount << endl;

            else
                cout<< duration << " ms" << endl;

            delete [] arr1;
            delete [] arr2;
            delete [] arr3;
            delete [] arr4;
        }

         cout << "-----------------------------------------------------------------" << endl;

    }
}
}

/*
*
* Auxiliary Global Functions
*
*/
void displayArray(const int *arr, const int size)
{
    cout << "The contents of your array have been listed below:\n[";

    for( int i = 0; i < size; i++)
    {
        if( i != size - 1)
            cout << " " << arr[i] <<  ",";
        else
            cout << " " << arr[i];
    }
    cout << " ]\n";
}
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];

    for( int i = 0; i < size; i++)
    {
        arr1[i] = rand();
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }

}
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];

    for( int i = 0; i < size; i++)
    {
        arr1[i] = i;
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }
}

void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];

    for( int i = 0; i < size; i++)
    {
        arr1[i] = size - i;
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }
}
