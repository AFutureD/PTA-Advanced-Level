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
#include <iterator>
#define REP(i,n) for(int i = 0; i < (n); i++)
#define REP_1(i,n) for(int i = 1; i < (n); i++)
#define REP_N(i,n) for(int i = 0; i <= (n); i++)
#define REP_1_N(i,n) for(int i = 1; i <= (n); i++)
#define DWN(i,n) for(int i = (n); i > 0; i--)
#define DWN_1(i,n) for(int i = (n); i > 1; i--)
#define DWN_N(i,n) for(int i = (n); i >= 0; i--)
#define DWN_1_N(i,n) for(int i = (n); i >= 1; i--)
#define FOR(i,A,B) for(int i = (A); i < (B); i++)
#define FOR_N(i,A,B) for(int i = A; i <= (B); i++)
#define FOR_D(i,A,B) for(int i = (A); i > (B); i--)
#define FOR_D_N(i,A,B) for(int i = (A); i >= (B); i--)
#define FILEIN(file) freopen((file),"r",stdin)
#define FILEOUT(file) freopen((file),"w",stdout)
#define DEBUGB(block,message) cout << std::setw((block) * 4) << "" << "DEBUG Block " << (block) << ": BEGIN " << (message)<<endl
#define DEBUGE(block,message) cout << std::setw((block) * 4) << "" << "DEBUG Block " << (block) << ": END " << (message)<<endl
#define MEM0(OBJ) memset((OBJ),0,sizeof((OBJ)))
#define MEMINIT(OBJ,VALUE) memset((OBJ),(VALUE),sizeof((OBJ)))

using namespace std;
int N,M,K;
map<int,bool> reactants;
vector<int> product;
map<int, vector<int> > ans;
vector<vector<int> > equations[105];

int cmp(vector<int> a, vector<int > b){
    int len = min(a.size(),b.size());
    for(int i = 0; i < len; i++){
        if(a[i] != b[i])
            return a[i] < b[i];
    }
    if(a.size() != b.size())
        return a.size() < b.size();
    return 0;
}

int dfs(int cur){
    if(cur == M)
        return 1;
    int cur_product = product[cur];
    
    for(int i = 0; i < equations[cur_product].size(); i++){
        vector<int> tmp = equations[cur_product][i];
        int if_good = 1;
        for(int j = 0; j < tmp.size(); j++){
            if(reactants[tmp[j]] == 0){
                if_good = 0;
                break;
            }
        }
        if(!if_good)
            continue;
        for(int j = 0; j < tmp.size(); j++){
            reactants[tmp[j]] = false;
        }
        ans[cur_product] = tmp;
        if( dfs(cur + 1) == 1)
            return 1;
        for(int j = 0; j < tmp.size(); j++){
            reactants[tmp[j]] = true;
        }
        ans.erase(cur_product);
    }
    return 0;
}

int main(){
    FILEIN("in.text");
//    FILEOUT("../out.text");
    scanf("%d",&N);
    REP(i, N){
        int tmp;
        scanf("%d", &tmp);
        reactants[tmp] = true;
        vector<int> tmpv;
        tmpv.push_back(tmp);
        equations[tmp].push_back(tmpv);
    }
    
    scanf("%d",&M);
    REP(i, M){
        int tmp;
        scanf("%d", &tmp);
        product.push_back( tmp);
    }
    
    scanf("%d",&K);
    getchar();
    REP(i, K){
        string tmp; getline(cin, tmp); int len = tmp.length();
        vector<int>  tmpv;
        int last = (tmp[len - 2] - '0') * 10 + tmp[len - 1]-'0';
        
        REP(j, len){
            if(tmp[j] >= '0' && tmp[j] <= '9'){
                int num =  (tmp[j] - '0') * 10 + tmp[j + 1]-'0';
                j += 2;
                tmpv.push_back(num);
            } else {
                if(tmp[j] == '+'){
                    j += 1;
                } else if(tmp[j] == '-'){
                    j += 2; break;
                }
            }
        }
//        cout << tmpv[tmpv.size()-1] <<endl;
        equations[last].push_back(tmpv);
    }
    
    REP(i, 105){
        sort(equations[i].begin(), equations[i].end(), cmp);
    }
    
    dfs(0);
    
    REP(i, M){
        vector<int> tmp = ans[product[i]];
        for (int i = 0; i < tmp.size(); i++) {
//            cout << (i ? " + " : "") <<  tmp[i] ;
            printf("%s%02d",(i ? " + " : ""),tmp[i]);
        }
//        cout <<  " -> " <<product[i] << endl;
        printf(" -> %02d\n",product[i]);
    }
    
    return 0;
}


