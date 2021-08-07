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
#define REP(i,n) for(int i = 0; i < (n); i++)
#define REP_1(i,n) for(int i = 1; i < (n); i++)
#define REP_N(i,n) for(int i = 0; i <= (n); i++)
#define REP_1_N(i,n) for(int i = 1; i <= (n); i++)
#define DWN(i,n) for(int i = (n); i > 0; i--)
#define DWN_1(i,n) for(int i = (n); i > 1; i--)
#define DWN_N(i,n) for(int i = (n); i >= 0; i--)
#define DWN_1_N(i,n) for(int i = (n); i >= 1; i--)
#define FOR(i,A,B) for(int i = (A); i < (B); i++)
#define FOR_N(i,A,B) for(int i = A; i <= (B); i++)
#define FOR_D(i,A,B) for(int i = (A); i > (B); i--)
#define FOR_D_N(i,A,B) for(int i = (A); i >= (B); i--)
#define FILEIN(file) freopen((file),"r",stdin)
#define FILEOUT(file) freopen((file),"w",stdout)
#define DEBUGB(block,message) cout << std::setw((block) * 4) << "" << "DEBUG Block " << (block) << ": BEGIN " << (message)<<endl
#define DEBUGE(block,message) cout << std::setw((block) * 4) << "" << "DEBUG Block " << (block) << ": END " << (message)<<endl
#define MEM0(OBJ) memset((OBJ),0,sizeof((OBJ)))
#define MEMINIT(OBJ,VALUE) memset((OBJ),(VALUE),sizeof((OBJ)))

using namespace std;

int n,m,t;
vector <int> edges[1010]; // edges[1].push_back(2) 
                          // edges[2].push_back(1)
                          // edges[i] i -> index 
                          // i -> j
int in[1010],in2[1010];
int que[1010];

int main(){
    // FILEIN("../in.text");
    // FILEOUT("../out.text");

    scanf("%d%d",&n,&m);
    
    MEM0(in);
    REP(i,m){
        int a,b;
        scanf("%d%d",&a,&b);
        edges[a].push_back(b);
        in[b]++;
    }

    scanf("%d",&t);
    int flag = 0;
    REP(i,t){
        
        REP(j,n) scanf("%d",&que[j]); 

        REP_N(j,n) in2[j] = in[j]; 

        REP(j,n)
            if(in2[que[j]] == 0) 
                REP(k,edges[que[j]].size()) in2[edges[que[j]][k]]--; 
            else{
                printf("%s%d",flag == 1 ? " " : "",i);
                flag = 1;
                break;
            }
    }

    printf("\n");
    

    return 0;
}