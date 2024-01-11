#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N;
	scanf("%d", &N);
	int *p = (int*)malloc(sizeof(int)*N);
	int add = 0;
	if(p == NULL){
		printf("Not enough memory!");
		return -1;
	}
    
	for(int i=0; i<N; i++)
		scanf("%d", &p[i]);

	for(int i=0; i<N; i++)
		add = add + p[i];

	printf("%d",add);
	free(p);
	return 0;
}