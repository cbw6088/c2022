#include <stdio.h>

int main(void){
    int N=0,M=0,cnt=0,ccnt=0,max=0;
	scanf("%d",&N);

	for(int i=0; i<N; i++){
		scanf("%d",&M);
		printf("%d:",M);
		for(int j=1; j<=M; j++){
			if(M%j==0){
				printf(" %d",j);
				cnt++;
			}
		}
		printf(" %d\n",cnt);
		if(ccnt < cnt){
			ccnt = cnt;
			max = M;
		}
		cnt=0;
	}
	printf("%d",max);
    return 0;
}
