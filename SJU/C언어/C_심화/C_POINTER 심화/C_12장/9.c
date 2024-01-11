#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N, min = 9999999, idx = 0;
	scanf("%d", &N);
	getchar();
	char **p = (char**)malloc(sizeof(char*) * N);
	for(int i = 0; i < N; i++){
		*(p+i) = (char*)malloc(sizeof(char) * 100);
		if(p + i == NULL){
			printf("Not enough memory!");
			return -1;
		}
	}

	for(int i = 0; i < N; i++)
		gets(p[i]);
	
	for(int i = 0; i < N - 1; i++){
		for(int j = i + 1; j < N; j++){
			if(strlen(p[i]) < strlen(p[j])){
				char *tmp = NULL;
				tmp = *(p + i);
            	*(p + i) = *(p + j);
            	*(p + j) = tmp;
			}
		}
	
	}
	for(int i = 0; i < N; i++)
		printf("%s\n", p[i]);
	for(int i = 0; i < N; i++)
		free(p[i]);
	free(p);
	return 0;
}
