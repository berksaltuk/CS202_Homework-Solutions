#ifndef KEYEDITEM_H
#define KEYEDITEM_H
/*
* Title: KeyedItem a.k.a. Print Request
* Author: Berk Saltuk Yilmaz
* ID: 21903419
* Section: 3
* Assignment: 3
* Description: This keyed item's KeyType is integer and it keeps all of the data of a single print request
* such as priority, id, when the print request has arrived and how long it will tkae the process this request.
* Heap is modified according to this.
*/
typedef int KeyType;

class KeyedItem {
public:
    //Constructors
KeyedItem();

KeyedItem(const KeyType& id, const KeyType& priority, const KeyType& createdAgo, const KeyType& time);

//setters
void setKey(KeyType key)
{
    priority = key;
}
void setID(KeyType key)
{
    id = key;
}
void setWhenRequested(KeyType key)
{
    createdAgo = key;
}
void setTimetoProcess(KeyType key)
{
    time = key;
}

void setAll(KeyType id2, KeyType priority2, KeyType created2, KeyType process2)
{
    id = id2;
    priority = priority2;
    createdAgo = created2;
    time = process2;
}

// getters
KeyType getKey() const {
    return priority;
}
KeyType getID() const {
    return id;
}
KeyType getWhenRequested() const {
    return createdAgo;
}
KeyType getTimetoProcess() const {
    return time;
}

// Properties of a print request...
private:

    KeyType id;
    KeyType priority;
    KeyType createdAgo;
    KeyType time;
};

#endif // KEYEDITEM_H
