#include <stdio.h>
#include <string.h>

void eliminate(char ar[]);

int main(){
	char ch[100]={};
	char *p = ch;
	scanf("%s",p);
	p = ch;
	eliminate(p);
	return 0;
}

void eliminate(char ar[]){
	char *p = ar;
	int cnt=0;
	while(*p != '*'){
		p++;
		cnt++;
	}
	p = ar;
	for(; p<ar+cnt-1; p++){
		for(char *q=p+1; q<ar+cnt; q++){
			if(*p == '!') break;
			if(*p == *q){
				*q = '!';
			}
		}
	}
	p = ar;
	for(; p<ar+cnt+1; p++){
		if(*p == '!')continue;
		printf("%c",*p);
	}
}