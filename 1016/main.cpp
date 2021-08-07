#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <map>
#include <stack>
#include <iomanip>
#include <iterator>
#include <string>
#define REP(i,n) for(int i = 0; i < (n); i++)
#define REP_1(i,n) for(int i = 1; i < (n); i++)
using namespace std;

int rate[25] = {0},rate_sum[25];
int N;

struct Node{
    int M,d,h,m;
    string s;
};

map<string, vector<struct Node> > lines;
map<string, map<int,vector<struct Node> > > L;

int cmp(Node a,Node b){
    if(a.M != b.M)
        return a.M <= b.M;
    else
        if(a.d != b.d) return a.d <= b.d;
        else
            if(a.h != b.h) return a.h <= b.h;
            else return a.m <= b.m;
}

int main(){


    REP_1(i,25){
        cin >> rate[i];
        rate_sum[i] = rate[i] + rate_sum[i-1];
    }

    cin >> N;
    REP(i,N){
        string tmp_name;string status;
        int M,d,h,m;
        cin >> tmp_name;
        scanf("%d:%d:%d:%d",&M,&d,&h,&m);
        cin >> status;getchar();
        lines[tmp_name].push_back({M,d,h,m,status});
    }

    for(map<string, vector<struct Node> >::iterator it= lines.begin(); it!=lines.end(); ++it)
        sort(it->second.begin(),it->second.end(),cmp);

    for(map<string, vector<struct Node> >::iterator it= lines.begin(); it!=lines.end(); ++it){
        vector<struct Node> tmp = it->second;
        int p = 0,q = p + 1;
        while(p < tmp.size() && q < tmp.size()){
            struct Node a = tmp[p];struct Node b = tmp[q];
            if(a.M != b.M  || a.s.compare("on-line") != 0 ||  a.s.compare(b.s) == 0){
                p++; q++;
                continue;
            }
            L[it->first][b.M].push_back({b.M,b.d,b.h,b.m,b.s});
            p = p + 2;q = p + 1;

        }
    }

    for(map<string, map<int,vector<struct Node> > >::iterator person= L.begin(); person!=L.end(); ++person){
        map<int,vector<struct Node> > tmp = person->second;
        for(map<int,vector<struct Node> > ::iterator mon = tmp.begin();mon!=tmp.end();mon++){
            cout << person->first << " ";printf("%02d\n",mon->first);
            vector<struct Node> bills = mon->second;
            long  total = 0;
            for(int i = 0;i < bills.size();i = i+2){
                struct Node on = bills[i];struct Node off = bills[i+1];
                printf("%02d:%02d:%02d %02d:%02d:%02d ",on.d,on.h,on.m,off.d,off.h,off.m);
                int onB = on.d * rate_sum[24] * 60 + 60 * rate_sum[on.h] + on.m * rate[on.h +1];
                int offB = off.d * rate_sum[24] * 60 + 60 * rate_sum[off.h] + off.m * rate[off.h + 1];
                printf("%d $%.2f\n",(off.d-on.d)*24*60 + (off.h-on.h)*60 + (off.m-on.m),(offB-onB) * 1.0 /100);
                total += offB - onB;
            }
            printf("Total amount: $%.2f\n",total * 1.0 / 100);
        }
    }
    return 0;
}