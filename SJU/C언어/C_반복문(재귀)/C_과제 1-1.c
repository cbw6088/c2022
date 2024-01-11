#include <stdio.h>
void re(int M,int S);

int main(void){
	int N=0,M=0,S=1;
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		scanf("%d",&M);
		printf("%d:",M);
		re(M,S);
		printf(" %d",M);
		printf("\n");
	}
	return 0;
}

void re(int M,int S){
	if(M != S){
		if(M%S == 0){
			printf(" %d",S);
		}
		S++;
		re(M,S);
	}
}