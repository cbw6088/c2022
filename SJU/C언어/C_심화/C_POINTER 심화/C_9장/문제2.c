#include <stdio.h>

int main(){
	char ch[20];
	char *p = ch;
	scanf("%s",p);
	for(p=ch; p<ch+20; p++){
		if(*p == '#')
			break;
	}

	while(p != ch){
		p--;
		printf("%c",*p);
	}
	return 0;
}