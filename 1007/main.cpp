#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    //freopen("a.txt","r",stdin);
    int n,flag = 0;
    long long arry[10010];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arry[i];
        if(flag == 0 && arry[i] > 0)
            flag=1;
    }

    long long  endd =0,maxAns = 0 ;
    int ed1 = 0,ed2 = n-1,td1=0,td2=0;
    for (int j = 0; j < n; j++)
    {
        if (maxAns >= 0 ){
            maxAns += arry[j];
            td2 = j;
        }
        else{
            maxAns = arry[j];
            td2 = td1 = j;
        }


        if(endd < maxAns || (maxAns == 0 && ed2 == n-1)){
            endd = maxAns;
            ed1 = td1; ed2 = td2;
        }
    }
    cout << endd <<" "<< arry[ed1] << " " << arry[ed2];
    return 0;
}
