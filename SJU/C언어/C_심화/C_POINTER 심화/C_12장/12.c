#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N, len;
	char ch[100] = {};
	scanf("%d", &N);
	getchar();
	char **p = (char**)malloc(sizeof(char*) * N);
	for(int i=0; i<N; i++){
		gets(ch);
		len = strlen(ch);
		p[i] = (char*)malloc(sizeof(char) * (len + 1));
		if(p[i] == NULL){
			printf("Not enough memory!");
			return -1;
		}
		strcpy(p[i], ch);
 	}
	char *tmp = (char*)malloc(sizeof(char) * 100);
	if(tmp == NULL){
		printf("Not enough memory!");
		return -1;
	}
	for(int i=0; i<N-1; i++){
		for(int j=i+1; j<N; j++){
			if(strcmp(p[i], p[j]) > 0){
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}

	for(int i=0; i<N; i++)
		printf("%s\n", p[i]);
	
	for(int i=0; i<N; i++)
		free(p[i]);
	//free(tmp);
	free(p);
	return 0;
}

/*
4
apricot
peach
willow
birch
*/