#include "binary_tree_structure.h"

using namespace std;

bool isFullTree=true;
int postArr[MAXLEN], inArr[MAXLEN], preArr[MAXLEN], len;
Node nodesArr[MAXLEN];

map<int, int> dataToIndex;

void BFS(Node * root){
    queue<Node*> nodes;
    nodes.push(root);
    root->level = 1;
    while(!nodes.empty()){
        Node* pnode = nodes.front();
        Node* lChild = pnode->lChild, *rChild = pnode->rChild;
        int index = dataToIndex[pnode->data], rIndex=-1, lIndex=-1;

        nodes.pop();
        nodesArr[index] = *pnode;

        if(lChild!=NULL){
            lIndex = dataToIndex[lChild->data];
            lChild->level=pnode->level+1;
            lChild->parent=index;
            nodes.push(lChild);
            nodesArr[lIndex]=*lChild;
            if(rChild!=NULL){
                rIndex = dataToIndex[rChild->data];
                rChild->level=pnode->level+1;
                rChild->parent = index;
                nodes.push(rChild);
                lChild->sibling=rIndex;
                rChild->sibling=lIndex;
                nodesArr[rIndex]=*rChild;
            }else{
                isFullTree=false;
            }
        }else if(rChild!=NULL){
            rIndex = dataToIndex[rChild->data];
            rChild->level=pnode->level+1;
            rChild->parent = index;
            nodes.push(rChild);
            nodesArr[rIndex]=*rChild;
            isFullTree=false;
        }
    }
}

Node* CreateTree(int lPost, int rPost, int lIn, int rIn)
{
    if(lIn >= rIn)
        return NULL;
    Node* root = new Node();
    int rootIndex = dataToIndex[postArr[rPost-1]];
    root->data = postArr[rPost-1];
    root->lChild = CreateTree(lPost, lPost+rootIndex-lIn, lIn, rootIndex);
    root->rChild = CreateTree(lPost+rootIndex-lIn, rPost-1, rootIndex+1, rIn);
    return root;
}

Node* CreateTree2(int lPre, int rPre, int lIn, int rIn){
    if(lIn >= rIn)
        return NULL;
    Node* root = new Node();
    int rootIndex = dataToIndex[preArr[lPre]];
    root->data = preArr[lPre];
    root->lChild=CreateTree2(lPre+1, lPre+1+rootIndex-lIn, lIn, rootIndex);
    root->rChild=CreateTree2(lPre+1+rootIndex-lIn, rPre, rootIndex+1, rIn);
    return root;
}

void BinatyTreeStructure(){
    int queNum;
    string que;
    cin >> len;
    for (int i = 0; i<len; i++){
        cin >> postArr[i];
//        cin >> preArr[i];
    }
    for (int i = 0; i<len; i++){
        cin >> inArr[i];
        dataToIndex[inArr[i]] = i;
    }
    Node* root = CreateTree(0,len,0,len);
    BFS(root);
    cin >> queNum;
    getline(cin, que);
    for(int i = 0; i < queNum; i++){
        getline(cin,que);
        const char* queCh = que.c_str();
        int data, ldata, rdata;
        if(que.find("root")!=string::npos){
            sscanf(queCh,"%d %*s",&data);
            cout <<(root->data==data ? "Yes":"No") << endl;
        }else if(que.find("siblings")!=string::npos){
            sscanf(queCh,"%d and %d", &ldata, &rdata);
            cout << (nodesArr[dataToIndex[ldata]].sibling == dataToIndex[rdata] ? "Yes":"No")<<endl;

        }else if(que.find("parent")!=string::npos){
            sscanf(queCh,"%d is the parent of %d", &ldata, &rdata);
            cout << (nodesArr[dataToIndex[rdata]].parent == dataToIndex[ldata] ? "Yes":"No")<<endl;

        }else if(que.find("left")!=string::npos){
            sscanf(queCh,"%d is the left child of %d", &ldata, &rdata);
            Node* p =nodesArr[dataToIndex[rdata]].lChild;
            cout << (p==NULL?"No":(p->data==ldata? "Yes":"No"))<<endl;

        }else if(que.find("right")!=string::npos){
            sscanf(queCh,"%d is the right child of %d", &ldata, &rdata);
            Node* p =nodesArr[dataToIndex[rdata]].rChild;
            cout << (p->data==NULL?"No":(p->data==ldata ? "Yes":"No"))<<endl;

        }else if(que.find("same")!=string::npos){
            sscanf(queCh,"%d and %d", &ldata, &rdata);
            cout << (nodesArr[dataToIndex[ldata]].level==nodesArr[dataToIndex[rdata]].level? "Yes":"No")<<endl;

        }else if(que.find("full")!=string::npos){
            cout << (isFullTree ? "Yes":"No") << endl;
        }
    }
}
void BinatyTreeStructure2(){

    FILE * f = fopen("test_case2.txt", "rt");
    if(f==NULL){
        perror("BinatyTreeStructure2");
        return;
    }

    fscanf(f,"%d",&len);

    for (int i = 0; i<len; i++){
//        fscanf(f,"%d", &postArr[i]);
        fscanf(f,"%d", &preArr[i]);
    }

    for (int i = 0; i<len; i++){
        fscanf(f, "%d", &inArr[i]);
        dataToIndex[inArr[i]] = i;
    }

    Node* root = CreateTree2(0,len,0,len);
    BFS(root);

    int queNum;
    fscanf(f, "%d", &queNum);

    char queCh[MAXLEN];
    fseek(f,2,SEEK_CUR);  //消去行尾换行符

    for(int i = 0; i < queNum; i++){
        fgets(queCh,MAXLEN,f);
        string que(queCh);

        int data, ldata, rdata;
        if(que.find("root")!=string::npos){
            sscanf(queCh,"%d %*s",&data);
            cout <<(root->data==data ? "Yes":"No") << endl;
        }else if(que.find("siblings")!=string::npos){
            sscanf(queCh,"%d and %d", &ldata, &rdata);
            cout << (nodesArr[dataToIndex[ldata]].sibling == dataToIndex[rdata] ? "Yes":"No")<<endl;

        }else if(que.find("parent")!=string::npos){
            sscanf(queCh,"%d is the parent of %d", &ldata, &rdata);
            cout << (nodesArr[dataToIndex[rdata]].parent == dataToIndex[ldata] ? "Yes":"No")<<endl;

        }else if(que.find("left")!=string::npos){
            sscanf(queCh,"%d is the left child of %d", &ldata, &rdata);
            Node* p =nodesArr[dataToIndex[rdata]].lChild;
            cout << (p==NULL?"No":(p->data==ldata? "Yes":"No"))<<endl;

        }else if(que.find("right")!=string::npos){
            sscanf(queCh,"%d is the right child of %d", &ldata, &rdata);
            Node* p =nodesArr[dataToIndex[rdata]].rChild;
            cout << (p->data==NULL?"No":(p->data==ldata ? "Yes":"No"))<<endl;

        }else if(que.find("same")!=string::npos){
            sscanf(queCh,"%d and %d", &ldata, &rdata);
            cout << (nodesArr[dataToIndex[ldata]].level==nodesArr[dataToIndex[rdata]].level? "Yes":"No")<<endl;

        }else if(que.find("full")!=string::npos){
            cout << (isFullTree ? "Yes":"No") << endl;
        }
    }
}
