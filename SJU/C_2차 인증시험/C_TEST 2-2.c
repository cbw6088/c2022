#include <stdio.h>

int main(void){
	int N=0,M=0,max=0,min=110,idx=0,idx2=0,cnt=0;
	double avg=0,add=0;
	scanf("%d %d",&N,&M);
	int X[N],Y[N],max_cnt[N],min_cnt[N];
	for(int i=0; i<N; i++){
		scanf("%d",&X[i]);
	}

	for(int i=0; i<N; i=i+M){
		for(int j=i; j<i+M && j<N; j++){
			add = add + X[j];
			cnt++;
		}
		avg = add / cnt;

		for(int k=i; k<i+M && k<N; k++){
			if(avg <= X[k]){
				Y[idx++] = X[k];
			}
		}
		cnt=0;
		add=0;
		avg=0;
	}

	for(int i=0; i<idx; i++){
		printf("%d ",Y[i]);
	}
	printf("\n");

	for(int i=0; i<N; i=i+M){
		max = X[i];
		min = X[i];
		for(int j=i; j<i+M && j<N; j++){
			if(max <= X[j]){
				max = X[j];
			}
			if(min >= X[j]){
				min = X[j];
			}
		}
		max_cnt[idx2] = max;
		min_cnt[idx2++] = min;
	}

	for(int i=0; i<idx2; i++){
		printf(" %d",max_cnt[i]);
	}
	printf("\n");
	for(int i=0; i<idx2; i++){
		printf(" %d",min_cnt[i]);
	}
	return 0;
}
