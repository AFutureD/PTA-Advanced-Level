#include<cstdio>

using namespace std;
int heap[1010];
int m,n;
void postorder (int k){
	if(k > n){
		return;
	}
	postorder(2 * k);
	postorder(2 * k +1);
	if(k == 1){
		printf("%d\n", heap[k]);
	}
	else{
		printf("%d ", heap[k]);
	}

}


int main(){
	
	scanf("%d%d",&m,&n);
	
	for (int i = 0; i < m;i++){
		for  (int j = 1; j < n + 1;j++){
			scanf("%d",&heap[j]);
		}
		int flag;
		if(heap[1]>heap[2]){
			flag = 1;
		}
		else{
			flag = 0;
		}
		for (int j = 2; j <= n;j++){

			// if(flag == 1 && heap[j] > heap[2 * j] && heap[j] > heap[2*j +1]){
			// 	flag = 1;
			// }else if(flag == 0 && heap[j] < heap[2 * j] && heap[j] < heap[2*j +1]){
            //     flag = 0;
            // }
            // else {
            //     flag = -1;
            //     break;
            // }

            // 
            int tmp;
            if(heap[j] > heap[j/2]){
                tmp = 0;
            }
            else tmp = 1;

            if(flag != tmp){
                flag = -1;
                break;
            }
		}
		if(flag == 1){
			printf("Max Heap\n");
		}else if(flag ==0){
			printf("Min Heap\n");

		}else{
			printf("Not Heap\n");
		}
		postorder(1);
	}
	return 0;
}