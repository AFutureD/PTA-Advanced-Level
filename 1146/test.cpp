// 用这个写代码

/* 
input 
6 8
1 2
1 3
5 2
5 4
2 3
2 6
3 4
6 4
5
1 5 2 3 6 4
5 1 2 6 3 4
5 1 2 3 6 4
5 2 1 6 3 4
1 2 3 4 5 6

output 
3 4
*/

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
// #define FILEIN(file) freopen((file),"r",stdin)
using namespace std;


int main(){
    // FILEIN("in.text");
    // start 
    //
	int n, m, t;
    cin >> n  >> m;
	vector<int> edges[1010]; // vector<int> a[10],b[20];
    // add an edge : 1 -> 2 edges[1].push_back(2)
	int in[1010], in2[1010];
	memset(in, 0, sizeof(in)); // 1B = 8bit; 00000000 int: 4B int 01111111 01111111 
	// memset((OBJ),0x7f,sizeof((OBJ)))
	// memset((OBJ),0xff,sizeof((OBJ)))
	for (int i = 0; i < m; i++)
	{
		int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
		in[b]++;
	}

    cin >> t;
    int que[1010];
	bool flag = 0;
	for (int i = 0; i < t; i++)
	{
		for(int j = 0; j < n; j++){
            cin >> que[j];
        }

        for(int j = 0; j <= n; j++){
            in2[j] = in[j];
        }

        // cout << n << endl;
        for(int j = 0; j < n; j++){
            // cout << in2[que[j]] << " " <<endl;
            if(in2[que[j]] == 0){
                // vector<int> tmp = edges[que[j]];
				for (int k = 0; k < edges[que[j]].size(); k++){
                    in2[edges[que[j]][k]]--;
				}
			}
            else{
				if(flag == 0){
					printf("%d", i);
					flag = 1;
				}
				else{
					printf(" %d", i);
				}
				break;
			}
		}

        // cout << i << ": success" << endl;
	}
	printf("\n");
	//cout << "end" <<endl;
	return 0;
}