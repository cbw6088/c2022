#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int M, N;
	scanf("%d %d", &M, &N);
	getchar();
	char str1[100] = {}, str2[100] = {}, str3[20][100] = {}, str4[20][100] = {};
	gets(str1);
	gets(str2);

	int len = strlen(str1) + 1, idx1 = 0, idx2 = 0;
	char *p = str1;
	for(int i = 0; i < len; i++){
		if(str1[i] == ' ' || str1[i] == '\0'){
			str1[i] = '\0';
			strcpy(str3[idx1++], p);
			p = p + strlen(p) + 1;
		}
	}
	len = strlen(str2) + 1;
	char *q = str2;
	for(int i = 0; i < len; i++){
		if(str2[i] == ' ' || str2[i] == '\0'){
			str2[i] = '\0';
			strcpy(str4[idx2++], q);
			q = q + strlen(q) + 1;
		}
	}
	
	char result[100] = {};
	if(strcmp(str3[M], str4[N]) < 0){
		strcpy(result, str3[M]);
		strcat(result, str4[N]);
	}
	else if(strcmp(str3[M], str4[N]) > 0){
		strcpy(result, str4[N]);
		strcat(result, str3[M]);
	}
	
	printf("%s", result);
	return 0;
}

/*
2 4
book desk pencil paper
orange apple banana lemon grape

1 0
book desk pencil paper
orange apple banana lemon grape
*/
