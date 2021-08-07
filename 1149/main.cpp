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

int n,m;
vector <pair<int,int> > PList;

int main(){
    // FILEIN("../in.text");
    // FILEOUT("../out.text");

    scanf("%d%d",&n,&m);

    REP(i,n){
        int tmp1,tmp2;
        scanf("%d%d",&tmp1,&tmp2);
        PList.push_back(make_pair(tmp1,tmp2));

    }

    REP(i,m){
        map <int,int> l; int co;
        scanf("%d",&co);
        REP(j,co){
            int tmp; scanf("%d",&tmp);
            l[tmp] = 1;
        }

        int flag = 0;

        REP(j,PList.size()){
            if(l[PList[j].first] == 1 && l[PList[j].second] == 1){
                flag = 1;
                break;
            }
        }

        printf("%s\n",flag ? "No" : "Yes");
    }

    return 0;
}
