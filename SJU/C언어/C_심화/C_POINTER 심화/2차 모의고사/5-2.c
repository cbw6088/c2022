#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct string{
	char *str;
	int words;
};

int main(){
	int N;
	scanf("%d", &N);
	getchar();
	struct string *p = (struct string*)malloc(sizeof(struct string) * N);
	for(int i = 0; i < N; i++){
		p[i].str = (char*)malloc(sizeof(char) * 100);
		if(p[i].str == NULL){
			printf("Not enough memory!!");
			return -1;
		}
	}
	
	for(int i = 0; i < N; i++)
		gets(p[i].str);

	for(int i = 0; i < N; i++){
		int cnt = 1;
		for(int j = 0; j < strlen(p[i].str); j++){
			if(p[i].str[j] == ' ')
				cnt++;
		}
		p[i].words = cnt;
	}
	struct string swap;
	for(int i = 0; i < N - 1; i++){
		for(int j = 0; j < N - 1 - i; j++){
			if(p[j].words < p[j+1].words){
				swap = p[j];
				p[j] = p[j+1];
				p[j+1] = swap;
			}
		}
	}
	for(int i = 0; i < N; i++){
		int xidx = 0, max = 0, idx = 0, cnt = 0;
		printf("%s %d ", p[i].str, p[i].words);
		char **q = (char**)malloc(sizeof(char*) * p[i].words);
		for(int j = 0; j < p[i].words; j++){
			q[j] = (char*)malloc(sizeof(char) * 100);
			if(q[j] == NULL){
				printf("Not enough memory!!");
				return -1;
			}
		}
		
		char *tmp = p[i].str;
		int len = strlen(p[i].str);
		for(int j = 0; j < len; j++){
			if(p[i].str[j] == ' ' || p[i].str[j] == '\0'){
				p[i].str[j] = '\0';
				strcpy(q[xidx++], tmp);
				tmp = tmp + strlen(tmp) + 1;
			}
		}
		strcpy(q[xidx++], tmp);

		for(int j = 0; j < xidx; j++){
			cnt = 0;
			for(int k = 0; k < xidx; k++){
				if(strcmp(q[j], q[k]) == 0)
					cnt++;
			}
			if(max < cnt){
				max = cnt;
				idx = j;
			}
			else if(max == cnt){
				if(strcmp(q[j], q[idx]) < 0){
					max = cnt;
					idx = j;
				}
			}
		}
		printf("%s %d\n", q[idx], max);
		for(int j = 0; j < p[i].words; j++)
			free(q[j]);
		free(q);
	}


	for(int i = 0; i < N; i++)
		free(p[i].str);
	free(p);
	return 0;
}

/*
5
why why why so so so serious
icecream makes everything better and better
you make me smile
c language exam and exam and exam and exam
see you later later later later

5
why so serious
icecream makes everything better
you make me smile
c language midterm and final
see you
*/