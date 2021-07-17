#ifndef HEAD_OF_A_GANG_H_INCLUDED
#define HEAD_OF_A_GANG_H_INCLUDED
#include "utils_includes.h"
#define MAXLEN 1000

using namespace std;

struct Gang{
    string headName;
    int num;
};

bool comp(Gang g1, Gang g2);
void visit(int n);
void DSFTraverse();
void HeadOfGangs();

#endif // HEAD_OF_A_GANG_H_INCLUDED
