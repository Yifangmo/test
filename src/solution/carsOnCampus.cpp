#include "cars_on_campus.h"

using namespace std;

int recSize, qerSize, countSize, num;
RecInfo recs[MAXSIZE], valid[MAXSIZE];
map<string, int> result;

bool Comp(RecInfo c1, RecInfo c2){
    if(strcmp(c1.id, c2.id))
        return strcmp(c1.id, c2.id)<0;
    return c1.time<c2.time;
}

bool CompTime(RecInfo c1, RecInfo c2){
    return c1.time<c2.time;
}

int convert(char * time){
    int h,m,s;
    sscanf(time, "%d:%d:%d", &h, &m, &s);
    return h*3600 + m*60 + s;
}

void CarsOnCampus(){
    freopen("test_case4.txt", "r", stdin);
    cin >> recSize >> qerSize;

    char time[10], s[4];
    for(int i = 0; i< recSize; i++){
        cin >> recs[i].id >> time >> s;
        recs[i].time = convert(time);
        if(s[0]=='i')
            recs[i].status=true;
        else
            recs[i].status=false;
    }

    sort(recs, recs+recSize ,Comp);

    int maxtime = -1, timei;
    for(int i = 1; i < recSize; i++){
        if(!strcmp(recs[i].id,recs[i-1].id) && recs[i-1].status && !recs[i].status){
            timei = recs[i].time-recs[i-1].time;
            if(result[recs[i-1].id]==0)
                result[recs[i-1].id]=timei;
            else
                result[recs[i-1].id]+=timei;
            valid[countSize++]=recs[i-1];
            valid[countSize++]=recs[i];
            if(maxtime < result[recs[i].id])
                maxtime = result[recs[i].id];
        }
    }
    sort(valid, valid+countSize, CompTime);

    for(int i = 0; i<qerSize; i++){
        cin >> time;
        timei = convert(time);
        num = 0;
        for(int j = 0; j < countSize&&timei>=valid[j].time; j++){
            if(valid[j].status){
                num++;
            }else
                num--;
        }
        cout << num << endl;
    }

    for(map<string, int>::iterator curr = result.begin(); curr != result.end(); curr++){
        if(curr->second==maxtime){
            cout << curr->first << " ";
        }
    }

    printf("%02d:%02d:%02d", maxtime/3600, maxtime/60%60, maxtime%60);
}
