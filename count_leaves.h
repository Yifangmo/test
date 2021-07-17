#ifndef COUNT_LEAVES_H_INCLUDED
#define COUNT_LEAVES_H_INCLUDED
#include"utils_includes.h"
#define MAXLEN 100

struct Node
{
    int c_num;
    int level;
    int childs[MAXLEN];
    Node(){
        memset(childs,0,sizeof(childs));
		c_num=0;
    }
};
void CountLeaves();

#endif // COUNT_LEAVES_H_INCLUDED
