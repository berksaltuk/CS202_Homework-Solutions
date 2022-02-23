#ifndef HEAP_H
#define HEAP_H
#include "KeyedItem.h"// definition of KeyedItem
typedef KeyedItem HeapItemType;
/*
* Title: MaxHeap's Interface
* Author: Berk Saltuk Yilmaz
* ID: 21903419
* Section: 3
* Assignment: 3
* Description: This interface more or less the same with the implementation in the course book
* However, it contains a dynamic array to keep items
*/
class Heap
{
    public:
        Heap();
        ~Heap();

        bool heapIsEmpty() const;

        void heapInsert( const HeapItemType& item);
        void heapDelete(HeapItemType &root);
        void heapDisplay();
        void heapRebuild( int root);

        //int items[MAX_HEAP];
        HeapItemType *items; // DYNAMIC!!!
        int size;
        int curSize;
};

#endif // HEAP_H
