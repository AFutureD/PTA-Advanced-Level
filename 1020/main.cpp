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
vector<int > postOrder;
vector<int > inOrder;
map<int,int > level;

void search(int root,int start,int end, int l){
    if(start > end) return;
    level[l] = postOrder[root];

    int idx = 0;
    while(idx < end && inOrder[idx] != postOrder[root]) idx++;

    search(root-(end-idx)-1, start, idx-1, 2*l+1);
    search(root-1, idx+1, end, 2*l+2);
    return;
}

int main() {

    cin >> N;
    postOrder.resize(N);
    inOrder.resize(N);
    REP(i,N)
        cin >> postOrder[i];
    REP(i,N)
        cin >> inOrder[i];

    search(N-1, 0, N-1, 0);

    for(map<int,int>::iterator it = level.begin();it!=level.end();it++)
        printf("%s%d",it==level.begin()?"":" ",it->second);
    printf("\n");
    return 0;
}