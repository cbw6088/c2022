#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char str1[251] = {}, str2[11] = {}, str3[11] = {}, tmp[251] = {};
	gets(str1);
	scanf("%s %s", str2, str3);

	int N = strlen(str2);
	for(int i = 0; i < strlen(str1); i++){
		if(strncmp(str1 + i, str2, N) == 0){
			strcpy(tmp, str1);
			strcpy(tmp + i, str3);
			strcat(tmp, str1 + i + N);
			strcpy(str1, tmp);
		}
	}
	
	printf("%s", str1);
 	return 0;
}

/*
I have a pen. I have an applepen. PPAP.
pen
mouse

Sequence GTCGTCG
GTCG
CAGC
*/