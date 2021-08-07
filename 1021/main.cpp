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

int N;
vector<int> tree[10010];
int vis[10010],vh[10010];
vector<int> roots;
int maxheigt = -1;
set<int> ans;

void search(int u,int v,int heigh){
    if(heigh > maxheigt){
        maxheigt = heigh;
        roots.clear();
        roots.push_back(v);
    }
    else if(heigh == maxheigt)
        roots.push_back(v);

    vis[v] = 1;
    vh[v] = 1;

    for(int i = 0;i < tree[v].size();i++){
        if(tree[v][i] == u ||  vis[tree[v][i]] == 1)
            continue;
        search(v,tree[v][i],heigh+1);
//        ans[v] = max(ans[v],heigh+1);
    }
}

int main() {

    cin >> N;
    REP(i,N-1){
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    MEM0(vis);
    MEM0(vh);
    int cnt = 0;

    REP_1_N(i,N){
        if(vh[i] == 0){
            vh[i] = 1;
            ans.clear();
            search(-1,i,1);
            REP(j,roots.size()) ans.insert(roots[j]);

            roots.clear();
            maxheigt = -1;
            MEM0(vis);
            search(-1,roots[0],1);
            REP(j,roots.size()) ans.insert(roots[j]);

            cnt++;
        }
    }

    if(cnt > 1)
        printf("Error: %d components\n", cnt);
    else
        for(auto it : ans)
            cout << it << endl;


    return 0;
}
