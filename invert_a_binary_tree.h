#ifndef INVERT_A_BINARY_TREE_H_INCLUDED
#define INVERT_A_BINARY_TREE_H_INCLUDED
#include "utils_includes.h"
#define MAXSIZE 10
struct Node{
    int data;
    int lChild;
    int rChild;
    int parent;
    Node(){
        data = -1;
        lChild = -1;
        rChild = -1;
        parent = -1;
    }
};
void invertBinaryTree();

#endif // INVERT_A_BINARY_TREE_H_INCLUDED
