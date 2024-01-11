#include <stdio.h>
int main(void){
	int N=0,M=0,cnt=0,last=0;
	scanf("%d",&N);

	for(int i=0; i<N; i++){
		scanf("%d",&M);

		for(int j=2; j<=M; j++){
			if(M%j == 0){
				cnt++;
			}
		}
		if(cnt==1){
			printf("%d ",M);
		}
		else{
			printf("*\n");
		}
		cnt=0;
	}
  	return 0;
}