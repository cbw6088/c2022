#include <stdio.h>

int main(void){
    int N=0,M=0,cnt=0,ccnt=0,temp=0,last=0,max=0,min=100;
	scanf("%d",&N);

	for(int i=0; i<N; i++){
		scanf("%d",&M);
		if(max < M){
			max = M;
		}
		else if(min > M){
			min = M;
		}
		if(M >= 100){
			cnt = 0;
			continue;
			}

		for(int j=1; j<=M; j++){
			if(M%j==0){
				temp++;
			}
		}

		if(temp == 2){
			cnt++;

			if(ccnt < cnt){
				last = M;
				ccnt = cnt;
			}
		}
		else{
			cnt=0;
		}
		temp=0;
	}
	printf("%d\n%d",ccnt,last);
	printf("\n%d %d",max,min);
    return 0;
}