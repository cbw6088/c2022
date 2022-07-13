#include <stdio.h>

int multiple(int x,int y);
int maximum(int x,int y);
int digit_maximum(int x);

int main(void){
	int N=0,M=0,K=0,idx=0,max=0,temp=0,MAX=0,digit_max=0;
	int X[100];
	scanf("%d %d %d",&N,&M,&K);

	for(int i=N; i<=M; i++){
		if(multiple(i,K) == 1){
			temp = digit_maximum(i);
			digit_max = maximum(digit_max,temp);
		}
		else{
			temp = i % K;
			MAX = maximum(MAX,temp);
		}
	}

	printf("%d",maximum(digit_max,MAX));


	return 0;
}

int multiple(int x,int y){
	return x%y==0;
}

int maximum(int x,int y){
	return x<=y ? y : x;
}

int digit_maximum(int x){
	int max=0,temp=0;
	for(int j=x; j>0; j=j/10){
		temp = j % 10;
		max = maximum(max,temp);
	}
	return max;
}