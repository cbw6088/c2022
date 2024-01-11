#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *swapPointer(int result[],int N);

int main(){
	int N;
	scanf("%d",&N);
	int *result = (int *)malloc(sizeof(int)*N);

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
	for(int i=N-1; i>0; i--){
		idx = i; // 인덱스 설정

		for(int j=i-1; j>=0; j--)
			if(result[idx] < result[j]) idx = j; // 크기 비교 후 인덱스 교환

		tmpData = result[idx]; // 스왑
		result[idx] = result[i];
		result[i] = tmpData;
	}
	return result;
}