#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N;
	scanf("%d", &N);
	float *p = (float*)malloc(sizeof(float)*N);
	float max = -9999999;
	if(p == NULL){
		printf("Not enough memory!");
		return -1;
	}
	
	for(int i=0; i<N; i++)
		scanf("%f", p+i);

	for(int i=0; i<N; i++){
		if(max < *(p+i))
			max = *(p+i);
	}

	printf("%.2f",max);
	free(p);
	return 0;
}