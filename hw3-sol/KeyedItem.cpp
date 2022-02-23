#include "KeyedItem.h"
/*
* Title: KeyedItem Class
* Author: Berk Saltuk Yilmaz
* ID: 21903419
* Section: 3
* Assignment: 3
* Description: Implementation of KeyedItem class which basically keeps the data for print requests
*/
KeyedItem::KeyedItem(){}

KeyedItem::KeyedItem(const KeyType& id, const KeyType& priority, const KeyType& createdAgo, const KeyType& time) :  id(id), priority(priority), createdAgo(createdAgo), time(time) { }
