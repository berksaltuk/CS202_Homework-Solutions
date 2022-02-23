#include "PriorityQueue.h"
/*
* Title: Priority Queue Class
* Author: Berk Saltuk Yilmaz
* ID: 21903419
* Section: 3
* Assignment: 3
* Description: Implementation of MaxHeap based Priority Queue
*/

bool PriorityQueue::pqEmpty() const //Nothing fancy, basically these are taken from the lecture slides in general.
{
    return h.heapIsEmpty();
}

void PriorityQueue::pqInsert(const PQItemType& item)
{
    h.heapInsert(item);
}

void PriorityQueue::pqDelete(PQItemType &priotyItem)
{
    h.heapDelete(priotyItem);
}

void PriorityQueue::pqDisplay()
{
    h.heapDisplay();
}

