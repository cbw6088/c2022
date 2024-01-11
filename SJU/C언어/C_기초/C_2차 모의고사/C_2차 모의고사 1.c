#include <stdio.h>

int main(void){
	int N=0,cnt=0,idx=0,ccnt=0,num=0,check=0;
	scanf("%d",&N);
	int X[N],Y[N],Z[N];
	for(int i=0; i<N; i++){
		scanf("%d",&X[i]);
	}

	for(int i=0; i<N; i++){
		for(int j=i; j>=0; j--){
			if(X[i] == X[j]){
				ccnt++;
			}
		}
		if(ccnt == 1){
			Z[num++] = X[i];
		}
		ccnt=0;
	}

	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			if(X[i] > 0){
				if(X[i] == X[j]){
					Y[idx] = cnt++; 
					X[j] = -1;
				}
				check = 1;
			}
		}
		if(check == 1){
			Y[idx] = cnt++;
			idx++;
		}
		cnt = 0;
		check = 0;
	}
	
	for(int i=0; i<num; i++){
		printf("%d %d\n",Z[i],Y[i]+1);
	}
	return 0;
}
