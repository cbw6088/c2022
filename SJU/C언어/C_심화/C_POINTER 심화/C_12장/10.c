#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N, M;
	scanf("%d", &N);
	M = N - 1;
	int *p = (int*)malloc(sizeof(int) * M);
	if(p == NULL){
		printf("Not enough memory!");
		return -1;
	}
	
	int cnt = 0, idx = 0;
	for(int i=0; i<N; i++){
		if(i == N/2){
			cnt++;
			continue;
		}
		p[idx++] = cnt;
		cnt++;
	}
	for(int i=0; i<M; i++)
		printf(" %d", p[i]);
	free(p);
	return 0;
}
