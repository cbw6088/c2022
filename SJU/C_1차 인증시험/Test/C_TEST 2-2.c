#include <stdio.h>
int main(void){
	int N=0; int mul=1,re=0,sub=0;

	while(1){
		sub = N;
		scanf("%d",&N);
		if(N < sub){return -1;}
		printf("%d ",N);

		for(int i=N; i>0; i=i/10){
			mul = mul * (i % 10);
		}
		printf("%d ",mul);

		for(int i=mul; i>0; i=i/10){
			re = re * 10;
			re = re + i % 10;
		}
		printf("%d ",re);

		printf("%d\n",N-sub);
		mul = 1;
		re = 0;
	}
  	return 0;
}