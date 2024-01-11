#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ABC(int (*p)[20], int k1, int k2);

int main(){
	int N;
	scanf("%d", &N);
	int ar[20][20] = {};
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++)
			ABC(ar, i, j);
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			printf(" %d", ar[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void ABC(int (*p)[20], int k1, int k2){
	(*(p + k1))[k2] = k1 + k2;
}