#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N;
	scanf("%d", &N);
	// getchar();
	int *p = (int*)malloc(sizeof(int)*N);
	if(p == NULL){
		printf("Not enough memory!");
		return -1;
	}
	
	for(int i=0; i<N; i++)
		scanf("%d", (p+i));
	for(int i=0; i<N-1; i++){
		if(*(p+i) > *(p+i+1)){
			int tmp = *(p+i);
			*(p+i) = *(p+i+1);
			*(p+i+1) = tmp;
		}
	}

	for(int i=0; i<N; i++)
		printf("%d\n", *(p+i));

	
	free(p);
	return 0;
}
