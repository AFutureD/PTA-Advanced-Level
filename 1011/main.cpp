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

double a[3][3];
char mask[4] = "WTL";

int main(){
    int m[3];
    double ans = 1.0;
    REP(i,3){
//        cin >> a[i][0] >> a[i][1] >> a[i][2];
        scanf("%lf%lf%lf",&a[i][0],&a[i][1],&a[i][2]);
        m[i] = max_element(&a[i][0],&a[i][0]+3) - &a[i][0];
        cout << mask[m[i]] << " ";
        ans *= a[i][m[i]];
    }

    ans = (ans * 0.65 - 1) * 2;
    printf("%0.2f\n",ans);
	return 0;
}