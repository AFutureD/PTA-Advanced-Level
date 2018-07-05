#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
int treeNodes[1010];
int flag = 0;

void postOrder(int v){
    if(v >= m) return;
    postOrder(v * 2 + 1);
    postOrder(v * 2 + 2);
    printf("%d%s",treeNodes[v],v == 0 ? "\n" : " ");
}

int main()
{
    scanf("%d%d",&n,&m);
    while(n--){
        memset(treeNodes,0,sizeof(treeNodes));

        for(int i = 0; i < m; i++){
                scanf("%d",&treeNodes[i]);
        }

        flag = treeNodes[0] > treeNodes[1] ? 1 : -1;

        for(int i = 1;i < m;i++){
            int par = (i - 1) / 2;
            flag = flag == (treeNodes[par] > treeNodes[i] ? 1 : -1) ? flag : 0;
        }

        if( flag == 0) printf("Not Heap\n");
        else if(flag == 1)  printf("Max Heap\n");
        else if(flag == -1) printf("Min Heap\n");

        postOrder(0);
    }
    return 0;
}
