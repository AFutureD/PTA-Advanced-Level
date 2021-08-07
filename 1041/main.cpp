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

int num;
int a[100100];
map<int,pair<int ,int > > MP;

bool cmp(pair<int,pair<int,int> > a, pair<int,pair<int,int> > b){
    if(a.second.second < b.second.second){
        return true;
    }
    else{
        if(a.second.first < b.second.first)
            return true;
    }
    return false;
}

int main(){
    // FILEIN("in.text");
    // FILEOUT("out.text");

    scanf("%d",&num);
    REP(i,num){
        scanf("%d",&a[i]);
        if(MP.find(a[i]) != MP.end()){
            MP[a[i]].second++;
        }
        else{
            MP[a[i]] = make_pair(i,1);
        }
    }


    vector<pair<int,pair<int,int> > > V(MP.begin(),MP.end());

    sort(V.begin(),V.end(), cmp);

    int flag = 0;
    for(int i = 0;i < V.size();i++){
        // cout << V[i].first << " " << V[i].second.first << " " << V[i].second.second <<endl;
        if(V[i].second.second == 1){
            cout << V[i].first << endl;
            flag = 1;
            break;
        }
    }

    if(!flag){
        cout << "None" <<endl;
    }

    return 0;
}