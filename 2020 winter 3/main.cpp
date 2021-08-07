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
int n,k;
map<string,string> M;

int main(){
    FILEIN("in.text");
//    FILEOUT("../out.text");
    cin >> n; cin.get();
    int pre = 0;
    string pre_ID = "0000";
    while(n--){
        string ID;
        getline(cin, ID);
        int indent = 0;
        if (ID.rfind(" ")  != string::npos) indent = ID.rfind(" ") + 1;
        
        string tmp = ID.substr(indent, ID.length() - indent);
        int t = pre - indent + 1;
        string f_id = pre_ID;
        
        while(t--) f_id = M[f_id];
        
        M[tmp] = f_id;
        pre = indent;
        pre_ID = tmp;
        
    }
    cin >> k;
    while(k--){
        string ID;
        cin >> ID;
        if(M.find(ID) == M.end()){
            cout << "Error: " << ID << " is not found." << endl;
            continue;
        }
        stack<string> S;
        while(ID != "0000"){
            S.push(ID);
            ID = M[ID];
        }
        cout << "0000";
        while(!S.empty()){
            string tmp = S.top();
            S.pop();
            cout << "->" << tmp;
        }
        cout <<endl;
    }
    return 0;
}
