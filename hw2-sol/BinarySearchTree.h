/*
* Title: Sorting and Algorithm Efficiency
* Author: Berk Saltuk Yilmaz
* ID: 21903419
* Section: 3
* Assignment: 2
* Description: This is the header (interface) file of BinarySearchTree
* class and it contains all the function prototypes.
* No changes made on the given prototypes but many new function prototypes has been added.
*/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "BinaryNode.h"

class BinarySearchTree
{
    public:
        BinarySearchTree();                 //DONE
        ~BinarySearchTree();                //DONE

        bool isEmpty();                     //DONE

        int getHeight();                    //DONE
        int getNumberOfNodes();             //DONE

        bool add(const int newEntry);       //DONE
        bool remove(const int anEntry);     //DONE
        bool contains(const int anEntry);   //DONE

        void preorderTraverse();            //DONE
        void inorderTraverse();             //DONE
        void postorderTraverse();           //DONE
        void levelorderTraverse();          //DONE
        int span(const int a, const int b); //DONE
        void mirror();                      //DONE

        //HELPERS IF ANY NEEDED
        int getHeight2( BinaryNode *&cur);

        bool contains2(BinaryNode *&cur, const int anEntry);

        void add2(BinaryNode *&cur, const int newEntry);
        void remove2(BinaryNode *&cur, const int anEntry);
        void processLeftMost(BinaryNode *&cur, int& itemToReplace);
        void destructTree( BinaryNode *&cur);

        void preorderTraverse2( BinaryNode *&cur);
        void inorderTraverse2( BinaryNode *&cur);
        void postorderTraverse2( BinaryNode *&cur);
        void levelorderTraverse2( BinaryNode *&cur, int curLv);
        int span2(BinaryNode *&cur, const int a, const int b);
        void mirror2( BinaryNode *&cur);

    private:
        BinaryNode *root;
        int noOfNodes;

};

#endif // BINARYSEARCHTREE_H
