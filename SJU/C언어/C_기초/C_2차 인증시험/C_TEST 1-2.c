#include <stdio.h>

int main(void){
	int N=0,M=0,temp=0,idx=0,cnt=0,cnt2=0,cnt3=0;
	scanf("%d",&N);
	int X[N];

	for(int i=0; i<N; i++){
		scanf("%d",&M);
		if(M > 0){
			X[idx++] = M;
		}
	}
	for(int i=0; i<idx; i++){
		cnt++;
	}
	printf("%d\n",cnt);

	if(cnt%2 == 0){
		for(int i=0; i<idx; i++){
			for(int j=0; j<idx-1; j++){
				if(X[j] <= X[j+1]){
					temp = X[j];
					X[j] = X[j+1];
					X[j+1] = temp;
				}
			}
		}
	}
	else if(cnt%2 != 0){
		for(int i=0; i<idx; i++){
			for(int j=0; j<idx-1; j++){
				if(X[j] >= X[j+1]){
					temp = X[j];
					X[j] = X[j+1];
					X[j+1] = temp;
				}
			}
		}
	}

	for(int i=0; i<idx; i++){
		printf("%d ",X[i]);
	}
	printf("\n");

	for(int i=0; i<idx; i++){
		if(X[i]%2 != 0){
			cnt2++;
		}
		else if(X[i]%2 == 0){
			if(cnt3 <= cnt2){
				cnt3 = cnt2;
			}
			cnt2=0;
		}
	}
	printf("%d",cnt3);
	return 0;
}
