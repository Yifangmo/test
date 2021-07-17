#include "head_of_gangs.h"
using namespace std;

map<string, int> nameToId;
map<int, string> idToName;
Gang gangs[MAXLEN];
int id=1, N, K; //id从1开始是为了map判断是否存在这样的id的需要
int weight[MAXLEN], visited[MAXLEN];
int edge[MAXLEN][MAXLEN];
int gangsNum, aGangTotalWeight, aGangTotalMemsNum, maxWeightInAGang, maxId;

void HeadOfGangs()
{
    string name1, name2;
    int time;
    cin >> N >> K;

    for(int i=1;i<=N;i++){
        cin >> name1 >> name2 >> time;
        int m = nameToId[name1], n = nameToId[name2];

        if(m==0){
            nameToId[name1]=id;
            idToName[id]=name1;
            m=id;
            id++;
        }

        if(n==0){
            nameToId[name2]=id;
            idToName[id]=name2;
            n=id;
            id++;
        }

        edge[m][n]=time;
        edge[n][m]=time;

        weight[m]+=time;
        weight[n]+=time;
    }
    DSFTraverse();
}

void DSFTraverse(){
    for(int i = 1; i < id; i++){
        aGangTotalWeight=0;
        aGangTotalMemsNum=0;
        maxWeightInAGang=0;
        maxId=0;
        if(visited[i]==0){
            visit(i);
        }
        if(aGangTotalMemsNum > 2 && aGangTotalWeight > 2*K){
            gangs[gangsNum].headName=idToName[maxId];
            gangs[gangsNum].num=aGangTotalMemsNum;
            gangsNum++;
        }
    }
    cout << gangsNum << endl;
    sort(gangs, gangs+gangsNum, comp);
    for(int i =0; i<gangsNum; i++){
        cout << gangs[i].headName << " " << gangs[i].num << endl;
    }
}

void visit(int n){
    visited[n]=1;

    aGangTotalWeight += weight[n];
    aGangTotalMemsNum ++;

    if(weight[n] > maxWeightInAGang){
        maxWeightInAGang = weight[n];
        maxId = n;
    }

    for(int i = 1; i < id; i++){
        if(edge[n][i]>0&&visited[i]==0)
            visit(i);
    }

}

bool comp(Gang g1, Gang g2){
    return g1.headName<g2.headName;
}
