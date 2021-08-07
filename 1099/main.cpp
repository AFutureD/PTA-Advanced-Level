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

struct node{
    int left,right;
    int value;
    int index;
    int level;
};

struct node tree[110];
int val[110];
int N;
int val_idx = 0;
void search(int v,int l,int idx){
//    cout << v << " " << l << " " << idx << endl;
//    cout << "- " << tree[v].left << " " << tree[v].right << endl;
    if(tree[v].right == -1 && tree[v].left == -1){
        tree[v] = {tree[v].left,tree[v].right,val[val_idx++],idx,l};
//        cout << "= " << v << " " << tree[v].value<<endl;
        return;
    }
    if(tree[v].left != -1) search(tree[v].left, l+1, 2*idx+1);
    tree[v] = {tree[v].left,tree[v].right, val[val_idx++], idx, l};
//    cout << "= " << v << " " << tree[v].value<<endl;
    if(tree[v].right != -1) search(tree[v].right, l+1, 2*idx+2);

}
int cmp(struct node a, struct node b){
    if(a.level == b.level)
        return a.index < b.index;
    else
        return a.level < b.level;
}

int main() {

    cin >> N;
    REP(i,N){
        int a,b;
        cin >> tree[i].left >> tree[i].right;
    }
    REP(i,N)
        cin >> val[i];
//    cout << "end" <<endl;

    sort(val,val+N);
    search(0,0,0);

    sort(tree,tree+N,cmp);

    REP(i,N){
        printf("%d%s",tree[i].value,i == N-1?"\n":" ");

//        cout << tree[i].value << " ";
    }
    return 0;
}
