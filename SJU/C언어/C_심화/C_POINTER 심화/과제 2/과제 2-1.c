#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char str1[201] = {};
	gets(str1);
	char *p = str1;
	char str2[21][201] = {};
	int idx = 0, len = strlen(str1) + 1;
	for(int i = 0; i < len; i++){
		if(str1[i] == ' ' || str1[i] == '\0'){
			str1[i] = '\0';
			printf("%s\n", p);
			strcpy(str2[idx++], p);
			p = p + strlen(p) + 1;
		}
	}
	
	for(int i = 0; i < idx - 1; i++){
		for(int j = 0; j < idx - 1 - i; j++){
			if(strcmp(str2[j], str2[j+1]) > 0){
				char tmp[201] = {};
				strcpy(tmp, str2[j]);
				strcpy(str2[j], str2[j+1]);
				strcpy(str2[j+1], tmp);
			}
		}
	}

	for(int i = 0; i < idx; i++)
		printf("%s ", str2[i]);
	return 0;
}

// simple is best