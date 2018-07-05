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

string number;
long long ans;
string mask[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

void printAns( long long n){
    if (n == 0)
        return;

    printAns(n/10);
    cout << mask[n%10] << (n == ans ? "\n" : " ");
    return;
}

int main() {
    cin >> number;
    ans = 0;
    REP(i,number.length()){
        int tmp = number[i] - '0';
        ans += tmp;
    }
    if (ans == 0) printf("zero\n");
    else printAns(ans);
    return 0;
}