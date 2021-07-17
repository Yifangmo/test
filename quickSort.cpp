#include "quick_sort.h"
#define MAXLEN 110
using namespace std;

int arr[MAXLEN], arrLen, pivotNum;

void findPivotEle(){
    cin >> arrLen;
    for(int i =0; i < arrLen; i++){
        cin>>arr[i];
    }
    vector<int> ints(arr, arr+arrLen);
    sort(ints.begin(), ints.end());
    for(int i = 0; i< arrLen; i++){
        if(arr[i] == ints[i]){
            int j;
            for(j = pivotNum; j > 0&&ints[i]<ints[j-1]; j--){
               ints[j] = ints[j-1];
            }
            ints[j]=arr[i];
            pivotNum++;
        }
    }
    cout << pivotNum << endl;
    for(int i = 0; i<pivotNum; i++){
        cout << ints[i];
        if(i!=pivotNum)
            cout<<" ";
    }
}
