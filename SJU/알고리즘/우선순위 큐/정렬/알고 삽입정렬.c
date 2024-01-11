#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *swapPointer(int result[],int N);

int main(){
	int N;
	scanf("%d",&N);
	int *result = (int*)malloc(sizeof(int) * N);

	for(int i=0; i<N; i++)
		scanf("%d",&result[i]); // 배열 값  입력

	swapPointer(result,N);

	for(int i=0; i<N; i++)
		printf(" %d",result[i]);

	free(result);
	return 0;
}

int *swapPointer(int result[],int N){
	int tmpData, idx;
	for(int i=1; i<N; i++){
		idx = i;
		for(int j=i-1; j>=0; j--)
			if(result[i] < result[j]) idx = j; // 위치 찾기

		tmpData = result[i];
		for(int k=i; k>idx; k--)
			result[k] = result[k-1];
		result[idx] = tmpData;
	}
	return result;
}