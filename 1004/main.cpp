#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <map>
#include <stack>
using namespace std;


struct ND{
    int v;
    int level;
};
const int MAXX = 100 + 10;
vector<ND> Node[MAXX];
queue<ND> Q;
int cc[MAXX];
int n,m,MAXNODE;

int main() {
    cin >> n >> m;
    for(int i = 0;i < m; i++){
        int ID,k;
        cin >> ID >> k;
        for(int j = 0;j < k; j++){
            int tmp;
            cin >> tmp;
            Node[ID].push_back({tmp,0});
        }
    }

    Q.push({1,0});
    while(!Q.empty()){
        ND nodeNum = Q.front();
        Q.pop();
        if(Node[nodeNum.v].size() == 0){
            cc[nodeNum.level]++;
//            cout << nodeNum.v << " " << nodeNum.level <<endl;
            continue;
        }
        for(int i = 0;i < Node[nodeNum.v].size(); i++) {
            ND tmp = Node[nodeNum.v][i];
            tmp.level = nodeNum.level + 1;
            MAXNODE = max(MAXNODE, tmp.level);
            Q.push(tmp);
        }
    }

    for(int i = 0;i <= MAXNODE;i++){
        if(!i) cout << cc[i];
        else cout << " " << cc[i];
    }
    return 0;
}