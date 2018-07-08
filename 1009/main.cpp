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


int n,m;
map<int,float> a,b,ans;

bool cmp(const pair<int,float>& x, const pair<int,float>& y){
    return x.first>y.first;
}

int main(){
    freopen("a.txt","r",stdin);

    cin >> n;
    REP(i,n){
        int tmpa = 0; float tmpb = 0;
        scanf("%d%f",&tmpa,&tmpb);
        a[tmpa] = tmpb;
    }

    cin >> m;
    REP(i,m){
        int tmpa = 0; float tmpb = 0;
        scanf("%d%f",&tmpa,&tmpb);
        b[tmpa] = tmpb;
    }

    for(map<int,float>::iterator i = a.begin(); i != a.end();i++){
        for(map<int,float>::iterator j = b.begin(); j != b.end();j++){
            int num = i->first + j->first;
            float count = i->second * j->second;
            map<int,float>::iterator ser = ans.find(num);
            if(ser == ans.end()){
                ans[num] = count;
            } else{
                ser->second += count;
            }
        }
    }
    vector < pair<int,float> > tmpAns(ans.begin(),ans.end() );
    sort(tmpAns.begin(),tmpAns.end(),cmp);

    int pl = 0;
    for(int i = 0;i < tmpAns.size();i++){
        if(tmpAns[i].second != 0.0)
            pl++;
    }

    cout << pl;
    for(int i = 0;i < tmpAns.size();i++){
        if(tmpAns[i].second != 0.0)
            printf(" %d %.1f",tmpAns[i].first,tmpAns[i].second);
    }

    return 0;
}
