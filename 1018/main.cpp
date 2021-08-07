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
#define FILEOUT(file) freopen((file),"w",stdout)
#define DEBUGB(block,message) cout << std::setw((block) * 4) << "" << "DEBUG Block " << (block) << ": BEGIN " << (message)<<endl
#define DEBUGE(block,message) cout << std::setw((block) * 4) << "" << "DEBUG Block " << (block) << ": END " << (message)<<endl
#define MEM0(OBJ) memset((OBJ),0,sizeof((OBJ)))
#define MEMINIT(OBJ,VALUE) memset((OBJ),(VALUE),sizeof((OBJ)))
const int INF = 0xffff;

using namespace std;

struct NODE{
    int u;
    int time;
};
int cmax,n,sp,m,minSend,minBack;
int bikes[510],vis[510],dis[510];
vector<struct NODE> M[510];
vector<int> ansPath,path[510],temppath;

void dfs(int v){
    temppath.push_back(v);
    if(v == 0) {
        int need = 0, back = 0;
        for(int i = temppath.size() - 1; i >= 0; i--) {
            int id = temppath[i];
            if(bikes[id] > 0) {
                back += bikes[id];
            } else {
                if(back > (0 - bikes[id])) {
                    back += bikes[id];
                } else {
                    need += ((0 - bikes[id]) - back);
                    back = 0;
                }
            }
        }
        if(need < minSend) {
            minSend = need;
            minBack = back;
            ansPath = temppath;
        } else if(need == minSend && back < minBack) {
            minBack = back;
            ansPath = temppath;
        }
        temppath.pop_back();
        return ;
    }
    for(int i = 0; i < path[v].size(); i++)
        dfs(path[v][i]);
    temppath.pop_back();
}

void pp(int v){
    cout << v << " " ;
    REP(i,path[v].size()){
        pp(path[v][i]);
    }
}

int main(){

    FILEIN("../in.text");
    FILEOUT("../out.text");

    scanf("%d%d%d%d",&cmax,&n,&sp,&m);

    DEBUGB(0,cmax);

    REP_1_N(i,n){
        scanf("%d",&bikes[i]);
        bikes[i] -= cmax/2;
    }

    REP(i,m){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        cout << a << b << c << endl;
        M[a].push_back({b,c});
        M[b].push_back({a,c});
    }

    // dijstra

    MEMINIT(vis,0);
    MEMINIT(dis,0x3f);
    dis[0] = 0;
    REP_N(i,n){
        int u = -1,min_dis = INF;

        REP_N(j,n){
            cout << "dis[j] " << dis[j] << endl;
            if(vis[j] == 0 && dis[j] < min_dis) {
                u = j;
                min_dis = dis[j];
                cout << u << " " << min_dis<<endl;
            }
        }
        if(u == -1) break; vis[u] = 1;
        cout << u << " ";
        REP_N(v,M[u].size()) {
            if(vis[v] == 0) {
                if(dis[v] > dis[u] + M[u][v].time) {
                    dis[v] = dis[u] + M[u][v].time;
                    path[v].clear();
                    path[v].push_back(u);
                }else if(dis[v] == dis[u] + M[u][v].time) {
                    path[v].push_back(u);
                }
            }
        }
    }

    cout << "dis"<< dis[sp] << endl;

    pp(0);
    cout << endl;

    //

    dfs(sp);

    printf("%d 0", minSend);
    for(int i = ansPath.size() - 2; i >= 0; i--)
        printf("->%d", ansPath[i]);
    printf(" %d", minBack);

    return 0;
}