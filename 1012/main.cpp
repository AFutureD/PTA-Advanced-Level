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
#define FILEIN freopen("in.text","r",stdin)
#define FILEOUT freopen("out.text","w",stdin)
#define DEBUGB(block,message) cout << std::setw(block * 4) << "" << "DEBUG Block " << (block) << ": BEGIN " << (message)<<endl
#define DEBUGE(block,message) cout << std::setw(block * 4) << "" << "DEBUG Block " << (block) << ": END " << (message)<<endl

using namespace std;

int n,m;
struct grade{
    int c;
    int m;
    int e;
    int a;
    int c_ind;
    int m_ind;
    int e_ind;
    int a_ind;
};
map<string,struct grade> stu;



int main(){

//    freopen("../in.text","r",stdin);

    cin >> n >> m;
    while(n--){
        string id;
        struct grade tmp;
        cin >> id >> tmp.c >> tmp.m >> tmp.e;
        double tt= 0.5 + (tmp.c + tmp.m + tmp.e) / 3.0;
        tmp.a = (int )tt;
        tmp.c_ind = tmp.m_ind =tmp.e_ind = tmp.a_ind = 0;

        for(map<string,struct grade>::iterator it = stu.begin();it!=stu.end();++it) {
            if((it->second).c < tmp.c){
                (it->second).c_ind++;
            } else if((it->second).c > tmp.c) tmp.c_ind++;
            if((it->second).m < tmp.m){
                (it->second).m_ind++;
            } else if((it->second).m > tmp.m) tmp.m_ind++;
            if((it->second).e < tmp.e){
                (it->second).e_ind++;
            } else if((it->second).e > tmp.e) tmp.e_ind++;
            if((it->second).a < tmp.a){
                (it->second).a_ind++;
            } else if((it->second).a > tmp.a) tmp.a_ind++;
        }
        stu[id] = tmp;
    }

    while(m--){
        string mm;
        cin >> mm;
        map<string,struct grade>::iterator it = stu.find(mm);
        if(it == stu.end()){
            printf("N/A\n");
            continue;
        }

        struct grade tmp = it->second;

        if(tmp.a_ind <= tmp.c_ind && tmp.a_ind <= tmp.m_ind && tmp.a_ind <= tmp.e_ind){
            cout << stu[mm].a_ind + 1 << " A\n";
            continue;
        }
        else {
            if(tmp.c_ind <= tmp.m_ind && tmp.c_ind <= tmp.e_ind){
                cout << stu[mm].c_ind + 1 << " C\n";
                continue;
            }else{
                if(tmp.m_ind <= tmp.e_ind){
                    cout << stu[mm].m_ind + 1 << " M\n";
                    continue;
                } else{
                    cout << stu[mm].e_ind + 1 << " E\n";
                    continue;
                }
            }
        }

    }
    return 0;
}