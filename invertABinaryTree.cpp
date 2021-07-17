#include "invert_a_binary_tree.h"

using namespace std;

int nodeNum;
Node tree[MAXSIZE];

void levelOrder(int rootIndex){
    Node* node;
    int lIndex, rIndex;
    queue<Node*> nodes;
    nodes.push(&tree[rootIndex]);
    cout << rootIndex;
    while(!nodes.empty()){
        node = nodes.front();
        nodes.pop();
        lIndex = node->lChild;
        rIndex = node->rChild;
        if(lIndex != -1){
            cout << " " << lIndex;
            nodes.push(&tree[lIndex]);
        }
        if(rIndex != -1){
            cout << " " << rIndex;
            nodes.push(&tree[rIndex]);
        }
    }
}

void inOrder(int rootIndex){
    stack<Node*> stk;
    int p = rootIndex, counter = 0;
    Node * node;

    while(p!=-1 || !stk.empty()){
        if(p!=-1){
            stk.push(&tree[p]);
            p = tree[p].lChild;
        }else{
            node = stk.top();
            counter++;
            cout << node->data;
            if(counter<nodeNum)
                cout << " ";
            stk.pop();
            p = node->rChild;
        }
    }
}

void invertBinaryTree(){
    freopen("test_case5.txt","r",stdin);
    cin >> nodeNum;

    int rootIndex;
    char l,r;
    for(int i = 0; i<nodeNum; i++){
        tree[i].data = i;
        scanf("\n%c %c", &l, &r);
        if(l != '-'){
            tree[i].rChild=l-'0';
            tree[l-'0'].parent=i;
        }
        if(r != '-'){
            tree[i].lChild=r-'0';
            tree[r-'0'].parent=i;
        }
    }
    for(int i =0; i<nodeNum; i++){
        if(tree[i].parent==-1){
            rootIndex = i;
            break;
        }
    }
    levelOrder(rootIndex);
    cout << endl;
    inOrder(rootIndex);
}
