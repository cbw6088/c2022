#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int  N;
	scanf("%d", &N);
	getchar();
	char tmp[101] = {};
	gets(tmp);
	char **p = (char**)malloc(sizeof(char*) * N);
	for(int i = 0; i < N; i++){
		p[i] = (char*)malloc(sizeof(char) * 101);
		if(p[i] == NULL){
			printf("Not enough memory");
			return -1;
		}
	}
	for(int i = 0; i < N; i++)
		gets(p[i]);

	int max = 0, idx = 0, check = 0;
	
	for(int i = 0; i < N; i++){
		int cnt = 0;
		for(int j = 0; j < strlen(p[i]); j++){
			if(strncmp(&p[i][j], tmp, strlen(tmp)) == 0){
				cnt++;
				check = 1;
				j = j + strlen(tmp) - 1;
			}
		}
		//printf("%d cnt : %d\n", i, cnt);
		if(max < cnt){
			max = cnt;
			idx = i;
			check = 1;
		}
	}
	if(check == 0)
		printf("NONE");
	else
		printf("%s", p[idx]);
	for(int i = 0; i < N; i++)
		free(p[i]);
	free(p);
	return 0;
}

/*
3 abc
abcabc abcabc
ABCabc ABCabc
abc abc abc abc

3 abc
ab cab c abd
ABCab cABC
a bca bca bcd

3 aaa
aaaaaa aaa aaaa
aaa aaa aaa
aaaaa aaaaa aaaaa

3 abc
ab cab c abd
ABCab cABC
a bca bca bcd
*/