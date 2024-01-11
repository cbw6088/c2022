#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N, M;
	char n = 'a';
	scanf("%d %d", &N, &M);
	char **p = (char**)malloc(sizeof(char*) * M);
	for(int i=0; i<M; i++){
		p[i] = (char*)malloc(sizeof(char) * N);
		if(p[i] == NULL){
			printf("Not enough memory!");
			return -1;
		}
	}

	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			p[i][j] = n;
			printf("%c ", p[i][j]);
			if(n == 'z')
				n = 'A' - 1;
			else if(n == 'Z')
				n = 'a' - 1;
			n++;
		}
		printf("\n");
	}
	for(int i=0; i<M; i++)
		free(p[i]);
	free(p);
	return 0;
}
