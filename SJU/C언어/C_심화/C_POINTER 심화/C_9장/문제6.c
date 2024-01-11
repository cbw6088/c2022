#include <stdio.h>

int main(){
	char ch[10];
	char *p = ch;
	int cnt=0,max=0;
	char tmpp;
	for(; p<ch+10; p++)
		scanf("%c",p);

	for(p=ch; p<ch+10; p++){
		for(char *tmp=ch; tmp<ch+10; tmp++){
			if(*p == *tmp)
				cnt++;
			if(cnt > max){
				max = cnt;
				tmpp = *p;
			}
		}
		cnt = 0;
	}
	printf("%c %d",tmpp,max);
	return 0;
}