/*
* Title: Sorting and Algorithm Efficiency
* Author: Berk Saltuk Yilmaz
* ID: 21903419
* Section: 3
* Assignment: 2
* Description: This is the BinaryNode implementation contains
* Constructors and get, set methods.
*/
#include "BinaryNode.h"

//CONSTRUCTORS
BinaryNode::BinaryNode()
{}

BinaryNode::BinaryNode( const int& oItem, BinaryNode *left,
                    BinaryNode *right)
            : item(oItem), leftChild(left), rightChild(right){}

//BASIC GETTER AND SETTERS
void BinaryNode::setItem(const int& anItem)
{
    item = anItem;
}

int BinaryNode::getItem()
{
    return item;
}

BinaryNode* BinaryNode::getRightChild()
{
    return rightChild;
}

BinaryNode* BinaryNode::getLeftChild()
{
    return leftChild;
}

void BinaryNode::setRightChild( BinaryNode *right)
{
    rightChild = right;
}

void BinaryNode::setLeftChild( BinaryNode *left)
{
    leftChild = left;
}
