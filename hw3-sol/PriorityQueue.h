#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
/*
* Title: Priority Queue's interface
* Author: Berk Saltuk Yilmaz
* ID: 21903419
* Section: 3
* Assignment: 3
* Description: This is the interface of heap-based priority queue.
*/
#include "Heap.h"
typedef HeapItemType PQItemType; // takes the KeyedItem as item type from the heap
class PriorityQueue
{
    public:

        bool pqEmpty() const;
        void pqInsert(const PQItemType& item);
        void pqDelete(PQItemType &priotyItem);
        void pqDisplay();

    private:
        Heap h; // heap based...
};

#endif // PRIORITYQUEUE_H
