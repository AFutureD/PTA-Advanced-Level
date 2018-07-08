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

long long tag, rad;
string n,m;

long long conc(string u, long long rad){
    long long ans = 0;
    REP(i,u.length())
        ans = ans * rad + (isdigit(u[i]) ? u[i] - '0' : u[i] -'a' +10);
    return ans;
}

long long find_rad(string v,long long cal){
    char max_dig = *max_element(v.begin(), v.end());
    long long low_rad = (isdigit(max_dig) ? max_dig - '0': max_dig - 'a' + 10) + 1;
    long long max_rad = max(low_rad,cal);
    while(low_rad <= max_rad){
        long long mid_rad = (low_rad + max_rad) / 2;
        long long tmp = conc(v,mid_rad);
        if(tmp < 0 || tmp > cal) max_rad = mid_rad - 1;
        else if(tmp < cal ) low_rad = mid_rad + 1;
        else return mid_rad;
    }
    return -1;
}

int main(){
    cin >> n >> m >> tag >> rad;

    long long ans = tag == 1 ? find_rad(m,conc(n,rad)) : find_rad(n,conc(m,rad));
    if(ans == -1) printf("Impossible\n");
    else printf("%lld\n",ans);
    return 0;
}