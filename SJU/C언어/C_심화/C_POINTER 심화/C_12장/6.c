#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N;
	scanf("%d", &N);
	getchar();
	char *p = (char*)malloc(sizeof(char) * N);
	if(p == NULL){
		printf("Not enough memory!");
		return -1;
	}
	
	gets(p);
	int cnt = 0;
	for(int i=0; i<N-2; i++){
		if(strncmp((p+i), "cat", 3) == 0)
			cnt++;
	}
	printf("%d", cnt);
	
	free(p);
	return 0;
}
