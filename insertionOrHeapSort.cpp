#include "insertion_or_heap_sort.h"
using namespace std;

int iniArr[MAXLEN], outArr[MAXLEN], arr[MAXLEN], len;
bool isInsertion;

void CpyArr(){
    for(int i = 0; i < len; i++){
        outArr[i] = iniArr[i];
    }
}

bool Comp(){
    for(int i = 0; i < len; i++){
        if(arr[i]!=outArr[i])
            return false;
    }
    return true;
}

void InsertSort(){
    CpyArr();
    bool flag = false;
    for(int i = 1; i<len;i++){
        int ele = outArr[i];
        int j;
        for(j = i; j>0&&outArr[j-1]>ele; j--){
            outArr[j] = outArr[j-1];
        }
        outArr[j] = ele;
        if(flag)
            break;
        flag = Comp();
    }
    isInsertion = flag;
}


void HeapSort(){
    CpyArr();
    for(int i = len/2-1; i>=0; i--){
        AdjustHeap(i, len);
    }
    bool flag = false;
    for(int i = len-1; i>0; i--){
        int tmp = outArr[i];
        outArr[i] = outArr[0];
        outArr[0] = tmp;
        AdjustHeap(0, i);
        if(flag)
            break;
        flag = Comp();
    }
}

void AdjustHeap(int index, int end){
    int ele = outArr[index];
    for(int i = index*2+1; i < end; i=i*2+1){
        if(i+1<end && outArr[i+1]>outArr[i])
            i++;
        if(outArr[i]>ele){
            outArr[index] = outArr[i];
            index = i;
        }
    }
    outArr[index] = ele;
}

void print(){
    for(int i = 0; i<len;i++){
        cout << outArr[i];
        if(i != len-1)
            cout << " ";
    }
}

void InsertionOrHeapSort(){
    freopen("test_case3.txt","r",stdin);
    cin>>len;
    for(int i = 0; i < len; i++){
        cin>>iniArr[i];
    }
    for(int i = 0; i<len;i++){
        cin>>arr[i];
    }

    InsertSort();
    if(isInsertion){
        cout << "Insertion Sort" << endl;
        print();
    }else{
        HeapSort();
        cout << "Heap Sort" << endl;
        print();
    }
}
