#ifndef BINARY_TREE_STRUCTURE_H_INCLUDED
#define BINARY_TREE_STRUCTURE_H_INCLUDED

#include "utils_includes.h"
#define MAXLEN 100

struct Node{
    int data, level, sibling, parent;
    Node* lChild, *rChild;
    Node(){
        data = 0;
        level = 0;
        lChild = NULL;
        rChild = NULL;
        sibling = -1;
        parent = -1;
    }
};

Node* CreateTree(int lPost, int rPost, int lIn, int rIn);
void BFS(Node* root);
void BinatyTreeStructure();
void BinatyTreeStructure2();

#endif // BINARY_TREE_STRUCTURE_H_INCLUDED
