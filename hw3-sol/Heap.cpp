#include "Heap.h"
using namespace std;
#include <iostream>
/*
* Title: MaxHeap which is modified to work with print requests!
* Author: Berk Saltuk Yilmaz
* ID: 21903419
* Section: 3
* Assignment: 3
* Description: This is the modified heap implementation, it is a max heap but it is specifically
* modified for print requests, it decides insertion and deletion according to the print request properties.
* Additionally, it contains a dynamic array.
*/
Heap::Heap() // initialize everything to zero / null
{
    items = NULL;
    size = 0;
    curSize = 0;
}
Heap::~Heap()
{
    delete [] items; // I hate memory leaks...
}

bool Heap::heapIsEmpty() const
{
    return size == 0;
}

void Heap::heapInsert( const HeapItemType &item)
{
    if(  !(curSize < size) ) // Deallocates and allocates new array if size is not enough
    {
        HeapItemType *temp = new HeapItemType[size + 1];

        for( int i = 0; i < size; i++)
        {
            temp[i] = items[i];
        }

        delete [] items;

        size++;

        items = new HeapItemType[size];

        for( int i = 0; i < size - 1; i++)
        {
            items[i] = temp[i];
        }

        delete [] temp;

    }
        items[curSize] = item;

        // Mostly same instertion operation ----------------->         However, look down |
        int place = curSize;                                 //                           v
        int parent = ( place - 1)/2;

        while( (place > 0) )
        {
            if( items[place].getKey() > items[parent].getKey())
            {
                HeapItemType temp = items[place];
                items[place] = items[parent];
                items[parent] = temp;

            }                                                          // it also checks the arrival times if priorities are the same!
            else if( items[place].getKey() == items[parent].getKey() && items[place].getWhenRequested() < items[parent].getWhenRequested())
            {
                HeapItemType temp = items[place];
                items[place] = items[parent];
                items[parent] = temp;


            }
            place = parent;
            parent = (place - 1)/2;
        }

        curSize++;
}

void Heap::heapDelete(HeapItemType &root) // Same delete function but it also diminishes the array at each deletion
{
    if( heapIsEmpty())
    {
        cout << "Heap is empty, nothing to delete." << endl;
    }
    else
    {
        root = items[0];
        items[0] = items[curSize - 1];
        HeapItemType *temp = new HeapItemType[size - 1];

        for(int i = 0; i < size - 1; i++) // Dynamic array!!!
        {
            temp[i] = items[i];
        }
        delete [] items;
        size--;


        items = new HeapItemType[size];
        for(int i = 0; i < size; i++)
        {
            items[i] = temp[i];
        }

        delete [] temp;
        curSize--;



        heapRebuild(0);

    }
}

void Heap::heapRebuild( int root) // Again this is mostly the same rebuild function, but...
{
    int childSwap = 2 * root + 1;

    if( childSwap < curSize)
    {
        int rightChild = childSwap+ 1;
                                 // I am also checking the arrival times...
        if( (rightChild < curSize) && ((items[rightChild].getKey() > items[childSwap].getKey())
                                       || (items[rightChild].getKey() == items[childSwap].getKey() && items[rightChild].getWhenRequested() < items[childSwap].getWhenRequested())))
        {
            childSwap = rightChild;
        }
                                // I am also checking the arrival times...
        if( items[root].getKey() < items[childSwap].getKey() ||
           (items[root].getKey() == items[childSwap].getKey() && items[root].getWhenRequested() > items[childSwap].getWhenRequested()))
        {
            HeapItemType temp = items[root];
            items[root] = items[childSwap];
            items[childSwap] = temp;

            heapRebuild(childSwap);
        }

    }

}
void Heap::heapDisplay() // This is not being used in my program but this was here for the testing purposes.
{
    if( heapIsEmpty())
    {
        cout << "Nothing to display. " << endl;
    }
    else
    {

        for(int i = 0; i < curSize; i++)
        {
            cout << "Printing request with ID " << items[i].getID() << " and priority " << items[i].getKey() << " was requested "
                 << items[i].getWhenRequested() << " minutes ago and will take " << items[i].getTimetoProcess() << " minutes to process." << endl;
        }

        cout << endl;
    }

}

