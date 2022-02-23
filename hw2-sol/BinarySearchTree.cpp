/*
* Title: Sorting and Algorithm Efficiency
* Author: Berk Saltuk Yilmaz
* ID: 21903419
* Section: 3
* Assignment: 2
* Description: This is the implementation of BinarySearchTree class
* which contains given methods and helper methods written by me.
* There are numerous additional methods but believe me, I need them!
*/
#include "BinarySearchTree.h"
using namespace std;

BinarySearchTree::BinarySearchTree()
{
    root = NULL; // Setting root to null to make things correct
    noOfNodes = 0;
}

BinarySearchTree::~BinarySearchTree()
{
    destructTree( root); // giving root to this function and taking a deep breath: no leaks anymore!
}

bool BinarySearchTree::isEmpty()
{
    return root == NULL; // no comment...
}

int BinarySearchTree::getHeight()
{
    return getHeight2(root); // calling related helper
}

int BinarySearchTree::getNumberOfNodes()
{
    return noOfNodes; // simply returning the numberOfNodes
}

bool BinarySearchTree::add(const int newEntry)
{
    if( !contains(newEntry)) // If this node does not exist returns true
    {
        ++noOfNodes; //increment number of nodes, to print on the getNumberOfNodes() method if necessary
        add2( root, newEntry); // calling related helper
        return true;
    }

    return false; // false otherwise
}

bool BinarySearchTree::remove(const int anEntry)
{
    if( contains(anEntry)) // if we have that node exist, delete it, return true
    {
        --noOfNodes; //decrement number of nodes, to print on the getNumberOfNodes() method if necessary
        remove2( root, anEntry); // calling related helper
        return true;
    }

    return false; // false otherwise
}

bool BinarySearchTree::contains(const int anEntry)
{
    return contains2( root, anEntry); // calling related helper
}

void BinarySearchTree::preorderTraverse()
{
    preorderTraverse2( root); // calling related helper
}

void BinarySearchTree::inorderTraverse()
{
    inorderTraverse2( root); // calling related helper
}

void BinarySearchTree::postorderTraverse()
{
    postorderTraverse2( root); // calling related helper
}

void BinarySearchTree::levelorderTraverse()
{
    int height = getHeight();

    for( int i = 1; i <= height; i++) // getting height and calling the related helper "height" times
    {
        cout << "Data of level " << i << ": "<<endl; // printing current level each time
        levelorderTraverse2( root, i); // calling related helper
    }
}

int BinarySearchTree::span(const int a, const int b)
{
    return span2( root, a, b); // calling related helper
}

void BinarySearchTree::mirror()
{
    mirror2( root); // calling related helper
}

//HELPERS

int BinarySearchTree::getHeight2(BinaryNode *&cur)
{
    if( cur == NULL) // if null, no node no height
    {
        return 0;
    }
    else
    {
        return 1 + std::max( getHeight2(cur->leftChild), getHeight2(cur->rightChild)); // 1 + call itself for each side and finally get the max to see the height
    }
}

bool BinarySearchTree::contains2(BinaryNode *&cur, const int anEntry)
{
    if( cur == NULL) // if null do not contain
    {
        return false;
    }
    if( anEntry == cur->item)
    {
        return true; // found it!
    }

    if( anEntry < cur->item) // if cur > given, look for the left side (smaller elements guaranteed)
    {
        return contains2( cur->leftChild, anEntry);
    }
    else
    {
        return contains2( cur->rightChild, anEntry); // do the contrary otherwise
    }
}

void BinarySearchTree::add2(BinaryNode *&cur, const int newEntry)
{
    if( cur == NULL) // if no node, create the new
    {
        cur = new BinaryNode(newEntry);
    }
    else
    {
        if( newEntry < cur->item) // recursively call the children according to the magnitude of the element and find the appropriate place for new node
        {
            add2(cur->leftChild, newEntry);
        }
        else
        {
            add2(cur->rightChild, newEntry);
        }
    }
}
void BinarySearchTree::remove2(BinaryNode *&cur, const int anEntry)
{
    if( cur->item == anEntry) // found it!
    {
        BinaryNode *holdNode;
        int itemToReplace;

        if((cur->leftChild == NULL)&&(cur->rightChild == NULL))
        {
            delete cur; // if both children null delete it and do not look back
            cur = NULL;
        }
        else if(cur->leftChild == NULL)
        {
            holdNode = cur; // if only one child is empty get the other child
            cur = cur->rightChild;

            holdNode->rightChild = NULL;
            delete holdNode;
        }
        else if(cur->rightChild == NULL)
        {
            holdNode = cur;
            cur = cur->leftChild;
            holdNode->leftChild = NULL;
            delete holdNode;
        }

        else // if both children exist, process to find appropriate node
        {
            processLeftMost( cur->rightChild, itemToReplace);
            cur->item = itemToReplace; // replace with found item
        }
    }
    else if( cur->item < anEntry) // look for children according to the magnitude
    {
        remove2(cur->leftChild, anEntry);
    }
    else
    {
        remove2(cur->rightChild, anEntry);
    }
}

void BinarySearchTree::processLeftMost(BinaryNode *&cur, int& itemToReplace)
{
    if( cur->leftChild == NULL) // finding the leftmost to replace
    {
        itemToReplace = cur->item;

        BinaryNode *holdNode = cur;
        cur = cur->rightChild;

        holdNode->rightChild = NULL;
        delete holdNode;
    }
    else // not leftmost yet!
    {
        processLeftMost( cur->leftChild, itemToReplace);
    }
}

void BinarySearchTree::destructTree( BinaryNode *& cur)
{
    if( cur != NULL)
    {
        destructTree( cur->leftChild); // processing to the bottom of the BST and deleting bottom to top
        destructTree( cur->rightChild);
        delete cur;
        cur = NULL;
    }
}

void BinarySearchTree::preorderTraverse2(BinaryNode *& cur)
{
    if( cur != NULL)
    {
        cout << cur->item << endl; // traverse and print which is currently root
        preorderTraverse2( cur->leftChild);
        preorderTraverse2( cur->rightChild);
    }
}

void BinarySearchTree::inorderTraverse2(BinaryNode *& cur)
{
    if( cur!= NULL)
    {
        inorderTraverse2(cur->leftChild);
        cout << cur->item << endl; // traverse and print which is left child root
        inorderTraverse2(cur->rightChild);
    }
}

void BinarySearchTree::postorderTraverse2(BinaryNode *& cur)
{
    if( cur!= NULL)
    {
        postorderTraverse2(cur->leftChild);
        postorderTraverse2(cur->rightChild);
        cout << cur->item << endl; // traverse and print which is right child root
    }
}

void BinarySearchTree::levelorderTraverse2( BinaryNode *& cur, int curLv)
{
    if( cur == NULL)
    {
        return;
    }
    if( curLv == 1)
    {
        cout << cur->item << endl; // we are at the right level, print
    }
    else
    {
        levelorderTraverse2( cur->leftChild, curLv - 1); // process until finding the correct level to print
        levelorderTraverse2( cur->rightChild, curLv - 1);
    }
}

int BinarySearchTree::span2(BinaryNode *&cur, const int a, const int b)
{
    if( cur == NULL)
    {
        return 0;
    }
    if( cur->item >= a && cur->item <= b)
    {
        return 1 + span2( cur->leftChild, a, b) + span2(cur->rightChild, a, b); // if item is within the span 1 + process children
    }
    else if( cur->item > b)
    {
        return span2( cur->leftChild, a, b); // if item is greater than higher bound, go for lesser elements
    }
    else
    {
        return span2( cur->rightChild, a, b); // do the contrary otherwise
    }
}

void BinarySearchTree::mirror2( BinaryNode *&cur)
{
    if( cur == NULL)
    {
        return;
    }
    else
    {
        mirror2( cur->leftChild); // process until the bottom leaves
        mirror2( cur->rightChild);

        BinaryNode* temporary; // swap by starting bottom to top

        temporary = cur->leftChild;
        cur->leftChild = cur->rightChild;
        cur->rightChild = temporary;
    }
}


