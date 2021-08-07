#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <string>

#define REP(i,n) for(int i = 0; i < (n); i++)
#define REP_1(i,n) for(int i = 1; i < (n); i++)
#define FOR(i,A,B) for(int i = (A); i < (B); i++)
#define REP_N(i,n) for(int i = 0; i <= (n); i++)
#define REP_1_N(i,n) for(int i = 1; i <= (n); i++)
#define FOR_N(i,A,B) for(int i = A; i <= (B); i++)
#define DWN(i,n) for(int i = (n); i > 0; i--)
#define DWN_1(i,n) for(int i = (n); i > 1; i--)
#define FOR_D(i,A,B) for(int i = (A); i > (B); i--)
#define DWN_0(i,n) for(int i = (n) - 1; i >= 0; i--)
#define DWN_1_N(i,n) for(int i = (n); i >= 1; i--)
#define FOR_D_N(i,A,B) for(int i = (A); i >= (B); i--)
#define FILEIN(file) freopen((file),"r",stdin)
#define FILEOUT freopen("out.text","w",stdin)
#define DEBUGB(block,message) cout << std::setw((block) * 4) << "" << "DEBUG Block " << (block) << ": BEGIN " << (message)<<endl
#define DEBUGE(block,message) cout << std::setw((block) * 4) << "" << "DEBUG Block " << (block) << ": END " << (message)<<endl
#define MEM0(OBJ) memset((OBJ),0,sizeof((OBJ)))
#define MEMINIT(OBJ,VALUE) memset((OBJ),(VALUE),sizeof((OBJ)))

using namespace std;

int N;
int a[110],b[110];

void downAdjust(int p){
    swap(b[0],b[p]);
    int i = 0,j = 2 * i + 1;
    while(j <= p-1){
        if(b[j+1] > b[j] && j+1 <= p-1)
            j++;
        if(b[i] < b[j]){
            swap(b[i],b[j]);
            i = j; j = j *2 + 1;
        }else
            break;
    }
}

int main() {

    cin >> N;
    REP(i,N)
        cin >> a[i];
    REP(i,N)
        cin >> b[i];
    int p = 1;
    while(b[p] >= b[p-1] && p++ < N);
    int tmp_idx = p;
    while(a[p] == b[p] && p++ < N);

    if(p == N + 1){
        printf("Insertion Sort\n");
        sort(b,b+tmp_idx+1);
        REP(i,N)
            printf("%d%s",b[i],i==N-1?"\n":" ");
    }
    else{
        printf("Heap Sort\n");
        p = N-1;
        while(b[p]>=b[p-1] && p-- >=2 );
        downAdjust(p);
        REP(i,N)
            printf("%d%s",b[i],i==N-1?"\n":" ");
    }
    return 0;
}
