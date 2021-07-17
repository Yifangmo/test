#include "count_leaves.h"

using namespace std;

Node Tree[MAXLEN];
int totalCount, noLeafCount, leaf[MAXLEN], levels;
queue<Node> nodes;

void CountLeaves()
{
    int id, childCount;
    cin >> totalCount >> noLeafCount;
    for(int i = 0; i<noLeafCount; i++)
    {
        cin >> id >> childCount;
        Tree[id].c_num = childCount;
        for(int j =0; j < childCount; j++)
        {
            cin >> Tree[id].childs[j];
        }
    }
    Tree[1].level=1;
    nodes.push(Tree[1]);
    while(!nodes.empty())
    {
        Node node = nodes.front();
        nodes.pop();
        if(node.level>levels)
            levels=node.level;
        if(node.c_num == 0)
        {
            leaf[node.level]++;
        }
        for(int i = 0; i< node.c_num; i++)
        {
            Tree[node.childs[i]].level=node.level+1;
            nodes.push(Tree[node.childs[i]]);
        }
    }

    for(int i = 1; i <= levels; i++)
    {
        cout << leaf[i] << (i==levels?"\n":" ");
    }
}
