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

#define REP(i,n) for(int i = 0; i < (n); i++)
#define REP_1(i,n) for(int i = 1; i < (n); i++)
#define FOR(i,A,B) for(int i = (A); i < (B); i++)
#define REP_N(i,n) for(int i = 0; i <= (n); i++)
#define REP_1_N(i,n) for(int i = 1; i <= (n); i++)
#define FOR_N(i,A,B) for(int i = A; i <= (B); i++)
#define DWN(i,n) for(int i = (n); i > 0; i--)
#define DWN_1(i,n) for(int i = (n); i > 1; i--)
#define FOR_D(i,A,B) for(int i = (A); i > (B); i--)
#define DWN_N(i,n) for(int i = (n); i >= 0; i--)
#define DWN_1_N(i,n) for(int i = (n); i >= 1; i--)
#define FOR_D_N(i,A,B) for(int i = (A); i >= (B); i--)
#define FILEIN(file) freopen((file),"r",stdin)
#define FILEOUT freopen("out.text","w",stdin)
#define DEBUGB(block,message) cout << std::setw((block) * 4) << "" << "DEBUG Block " << (block) << ": BEGIN " << (message)<<endl
#define DEBUGE(block,message) cout << std::setw((block) * 4) << "" << "DEBUG Block " << (block) << ": END " << (message)<<endl
#define MEM0(OBJ) memset((OBJ),0,sizeof((OBJ)))
#define MEMINIT(OBJ,VALUE) memset((OBJ),(VALUE),sizeof((OBJ)))

using namespace std;

int n,m,k;
vector<int > node[1010];
int vis[1010];

void graph(int u){
//    DEBUGB(2,"IN Graph");
//    cout << u <<endl;
    vis[u] = 1;
    REP(i,node[u].size()){
        if(vis[node[u][i]] == 0){
            graph(node[u][i]);
        }
    }
//    DEBUGE(2,"IN Graph");
}

int main(){
    FILEIN("../in.text");

    scanf("%d%d%d",&n,&m,&k);

    REP(i,m){
        int a,b;
        scanf("%d%d",&a,&b);
        node[a].push_back(b);
        node[b].push_back(a);
    }

    while(k--){
        int p,count;
        scanf("%d",&p);
        MEM0(vis);
        vis[p] = 1;
        count = 0;
//        DEBUGB(0,"Start");
//        cout << p <<endl;
        REP_1_N(i,n){
            if(vis[i] == 0){
//                DEBUGB(1,"LOOP IN");
                graph(i);
                count++;
//                DEBUGE(1,"LOOP OUT");
            }

        }
        cout << count - 1 <<endl;

    }
    return 0;
}