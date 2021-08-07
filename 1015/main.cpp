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
#include <cstdlib>

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

int n,d;

long long conc(string u, long long rad){
    long long ans = 0;
    REP(i,u.length()){
        ans = ans * rad + (isdigit(u[i]) ? u[i] - '0' : u[i] -'a' +10);
    }

    return ans;
}

string toRad(long long u, long long rad){
    string ans;
    while(u){
        int p = (int)(u%rad);
        if(p<10) ans.push_back(p + '0');
        else if( p >= 10) ans.push_back(p + 'a');
        u/=rad;
    }
    return ans;
}

int isPrime(long long n){
    for(int i=2; i * i <= n; ++i)
        if(n % i == 0) return 0;
    return 1;
}

int main(){
    while( scanf("%d",&n) && n > 0 ){

        scanf("%d",&d);
        if(!isPrime(n)){
            printf("No\n");
            continue;
        }

        long long ans  = conc(toRad(n,d),d);
        if(ans == 1) printf("No\n");
        else printf("%s",isPrime(ans) ? "Yes\n" : "No\n");
    }

    return 0;
}