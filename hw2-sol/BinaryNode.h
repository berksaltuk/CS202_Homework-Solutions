/*
* Title: Sorting and Algorithm Efficiency
* Author: Berk Saltuk Yilmaz
* ID: 21903419
* Section: 3
* Assignment: 2
* Description: This is the header (interface) file of
* BinaryNode class that contains the function prototypes
*/
#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <iostream>
class BinaryNode
{
    private:
        BinaryNode();
        BinaryNode( const int& oItem, BinaryNode *left = NULL,
                    BinaryNode *right = NULL);

        void setItem(const int& anItem);
        int getItem();

        BinaryNode* getRightChild();
        BinaryNode* getLeftChild();

        void setRightChild( BinaryNode *right);
        void setLeftChild( BinaryNode *right);

        int item;
        BinaryNode *leftChild;
        BinaryNode *rightChild;

        friend class BinarySearchTree;
};

#endif // BINARYNODE_H
