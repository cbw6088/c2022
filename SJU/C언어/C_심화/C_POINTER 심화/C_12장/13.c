#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N, M, len;
	scanf("%d", &N);
	int *id = (int*)malloc(sizeof(int) * N);
	if(id == NULL){
		printf("Not enough memory!");
		return -1;
	}

	for(int i=0; i<N; i++)
		scanf("%d", &id[i]);
		
	scanf("%d", &M);
	int new_size = N - M;
	id = (int*)realloc(id, sizeof(int) * new_size);

	for(int i=0; i<new_size; i++)
		printf("%d\n", id[i]);

	free(id);
	return 0;
}

/*
3
16011111
16011123
16011145
2
*/