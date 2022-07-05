#include <stdio.h>

int main(void){
    int N=0,idx=0,cnt=0,M=0,max=0,min=0;
	scanf("%d",&N);
	int arr[N],temp[N],X[N],Y[N],max_cnt[N],min_cnt[N];

	for(int i=0; i<N; i++){
		scanf("%d",&arr[i]);
		temp[i] = arr[i];
	}

	for(int i=N-1; i>=0; i--){
		printf(" %d",arr[i]);
	}
	printf("\n");

	while(1){
		idx=0;
		for(int i=0; i<N; i=i+3){
			max = arr[i];
			min = temp[i];
			for(int j=i; j<i+3 && j<N; j++){
				if(max < arr[j]){
					max = arr[j];
				}
				if(min > temp[j]){
					min = temp[j];
				}
			}
			max_cnt[idx] = max;
			min_cnt[idx] = min;
			idx++;
		}


		for(int i=0; i<idx; i++){
			printf(" %d",max_cnt[i]);
		}
		printf("\n");
		for(int i=0; i<idx; i++){
			printf(" %d",min_cnt[i]);
		}
		printf("\n");
		N = idx;
		if(N == 1){
			break;
		}
		for(int i=0; i<N; i++){
			arr[i] = max_cnt[i];
			temp[i] = min_cnt[i];
		}
	}
	return 0;
}