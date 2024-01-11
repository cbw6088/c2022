#include <stdio.h>

int max_num(int N1,int N2);
int min_num(int N1,int N2);

int main(void){
	int N=0,idx=0,S=0,E=0,T=0,cnt=0,temp=0;
	int A[100],B[100];
	int temp_max, temp_min;
	while(1){
		scanf("%d",&N);
		if(N == 0)break;
		A[idx++] = N;
	}
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		int max=0,min=1000000000;
		scanf("%d %d",&S,&E);
		cnt = E - S;
		cnt = cnt / 2;

		for(int i=0; i<=cnt; i++){
			temp = A[S+i];
			A[S+i] = A[E-i];
			A[E-i] = temp;
			temp_max = max_num(A[S+i],A[E-i]);
			temp_min = min_num(A[S+i],A[E-i]);
			if(max <= temp_max){max = temp_max;}
			if(min >= temp_min){min = temp_min;}
		}

		for(int i=0; i<idx; i++){
			printf("%d ",A[i]);
		}
		printf("\n%d %d\n",max,min);
	}
	return 0;
}

int max_num(int N1,int N2){
	if(N1 >= N2){
		return N1;
	}
	else{
		return N2;
	}
}

int min_num(int N1, int N2){
	if(N1 <= N2){
		return N1;
	}
	else{
		return N2;
	}
}