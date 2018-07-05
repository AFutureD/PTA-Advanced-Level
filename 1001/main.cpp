#include <iostream>
#include "cmath"
using namespace std;

void mdzz(long long num, int lenth){
    if(num / 10 != 0){
        mdzz(num/10,lenth+1);
    }
    if(lenth%3==0 && num/10 != 0){
        printf(",");
    }
    printf("%lld",num%10);
}

int main() {
    long long a = 0,b = 0;
    cin >> a >> b;
    long long ans = a + b;
    if (ans < 0){
        cout << "-";
    }
    ans = abs(ans);
    mdzz(ans,1);

    return 0;
}



