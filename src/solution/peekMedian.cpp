#include "peek_median.h"
#include "string"

using namespace std;

stack<int> stk;
int treeArr[MAXN];

void Update(int begin, int x){  //index的一些元素之后加x
    for(int i  = begin; i < MAXN; i+=lowbit(i)){
        treeArr[i]+=x;
    }
}

int GetSum(int end){
    int sum = 0;
    for(int i = end; i>0; i-=lowbit(i)){
        sum+=treeArr[i];
    }
    return sum;
}

int GetMedian(){
    int i = 1, j = MAXN, k = (stk.size()+1)>>1;
    while(i < j){
        int mid = (i+j)>>1;
        int sum = GetSum(mid);
        if(sum < k){
            i = mid+1;
        }else{
            j=mid;
        }
    }
    return i;
}

void PeekMedian(){
    int N, x;
    string cmd;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> cmd;
        if(cmd[1]=='o'){
            if(stk.size()==0){
                cout << "Invalid" <<endl;
            }else{
                cout << stk.top() << endl;
                stk.pop();
                Update(x, -1);
            }
        }else if(cmd[1]=='u'){
            cin >> x;
            Update(x, 1);
            stk.push(x);
        }else{
            if(stk.size()==0){
                cout << "Invalid" << endl;
            }else{
                x = GetMedian();
                cout << x << endl;
            }
        }
    }
}
