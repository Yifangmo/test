#ifndef INSERTION_OR_HEAP_SORT_H_INCLUDED
#define INSERTION_OR_HEAP_SORT_H_INCLUDED
#include "utils_includes.h"
#define MAXLEN 100

void CpyArr();
bool Comp();
void InsertSort();
void AdjustHeap(int index, int end);
void HeapSort();
void InsertionOrHeapSort();
void print();
#endif // INSERTION_OR_HEAP_SORT_H_INCLUDED
