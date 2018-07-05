#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <map>
#include <stack>

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

using namespace std;

int toNum(string a){
    int ans = 0;
    ans += a[6] * 10 + a[7];
    ans += (a[3] * 10 + a[4] ) * 60;
    ans += (a[0] * 10 + a[1] ) * 3600;
    return ans;
}

int n;
string ansA,ansB;
int minn,maxx;

int main(){
    cin >> n;
    minn = 99999999;
    maxx = 0;
    while(n--){
        string tmpa,tmpb,tmpc;
        cin >> tmpa >> tmpb >> tmpc;
        int tma = toNum(tmpb) , tmb = toNum(tmpc);
        if(tma < minn){
            minn = tma;
            ansA = tmpa;
        }
        if(tmb > maxx){
            maxx = tmb;
            ansB = tmpa;
         }

    }

    cout << ansA << " " << ansB <<endl;
    return 0;
}