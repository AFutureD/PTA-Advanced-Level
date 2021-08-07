#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <string>

#define REP(i,n) for(int i = 0; i < (n); i++)
#define REP_1(i,n) for(int i = 1; i < (n); i++)
#define FOR(i,A,B) for(int i = (A); i < (B); i++)
#define REP_N(i,n) for(int i = 0; i <= (n); i++)
#define REP_1_N(i,n) for(int i = 1; i <= (n); i++)
#define FOR_N(i,A,B) for(int i = A; i <= (B); i++)
#define DWN(i,n) for(int i = (n); i > 0; i--)
#define DWN_1(i,n) for(int i = (n); i > 1; i--)
#define FOR_D(i,A,B) for(int i = (A); i > (B); i--)
#define DWN_0(i,n) for(int i = (n) - 1; i >= 0; i--)
#define DWN_1_N(i,n) for(int i = (n); i >= 1; i--)
#define FOR_D_N(i,A,B) for(int i = (A); i >= (B); i--)
#define FILEIN(file) freopen((file),"r",stdin)
#define FILEOUT freopen("out.text","w",stdin)
#define DEBUGB(block,message) cout << std::setw((block) * 4) << "" << "DEBUG Block " << (block) << ": BEGIN " << (message)<<endl
#define DEBUGE(block,message) cout << std::setw((block) * 4) << "" << "DEBUG Block " << (block) << ": END " << (message)<<endl
#define MEM0(OBJ) memset((OBJ),0,sizeof((OBJ)))
#define MEMINIT(OBJ,VALUE) memset((OBJ),(VALUE),sizeof((OBJ)))

using namespace std;

int M,N,L,T;
int bra[61][1300][130];

int vis[61][1300][130];
int d[6][3] ={ 0, 0,-1,
               0, 1, 0,
               0,-1, 0,
               0, 0, 1,
              -1, 0, 0,
               1, 0, 0};
struct node{
    int x,y,z;
};
stack<struct node> que;
vector<int> ans;
void search(struct node idx){
//    cout << "START" <<endl;
    while(!que.empty()) que.pop();
    que.push(idx);
    int cunt = 0;
    vis[idx.z][idx.y][idx.x] = 1;
    while(!que.empty()){
        struct node tmp = que.top(); que.pop();
//        vis[tmp.z][tmp.y][tmp.x] = 1;
        cunt++;
//        cout << tmp.z << " " << tmp.y << " " << tmp.x << endl;
        for(int i = 0;i < 6;i++){
            struct node s;
            s.z = tmp.z + d[i][0];
            s.y = tmp.y + d[i][1];
            s.x = tmp.x + d[i][2];
//            cout << " 1 " << s.z << " " << s.y << " " << s.x << endl;
            if(s.z >=0 && s.z < L &&
            s.y >=0 && s.y < M &&
            s.x >=0 && s.x < N){
                if(bra[s.z][s.y][s.x] == 1 &&
                   vis[s.z][s.y][s.x] != 1){
//                    cout << " - " << s.z << " " << s.y << " " << s.x << endl;
                    que.push(s);
                    vis[s.z][s.y][s.x] = 1;
                }
            }
        }
    }
    ans.push_back(cunt);
//    cout << "END" <<endl;
}

int main() {

    scanf("%d%d%d%d",&M,&N,&L,&T);
    REP(i,L){
        REP(j,M){
            REP(k,N){
                scanf("%d",&bra[i][j][k]);
            }
        }
    }

    REP(i,L){
        REP(j,M){
            REP(k,N){
                if(vis[i][j][k] == 0 && bra[i][j][k] == 1){
                    struct node tmp;
                    tmp.z=i;tmp.y=j;tmp.x=k;
                    search(tmp);
                }
            }
        }
    }

//    REP(i,6)
////        REP(j,6)
//        cout << d[i][0] << " " << d[i][1] << " " << d[i][2] <<endl;
    int cunt  = 0;
    REP(i,ans.size()){
        if(ans[i] >= T)
            cunt += ans[i];
    }
//        cout << ans[i] << " ";
//    cout << endl;
    cout << cunt <<endl;
    return 0;
}

