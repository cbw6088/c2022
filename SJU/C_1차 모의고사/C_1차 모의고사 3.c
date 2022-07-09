#include <stdio.h>

int main(void){
    char ch;
	int Acnt=0,acnt=0,cnt=0,ccnt=0,add=0;
	while(1){
		scanf("%c",&ch);
		if(ch == '*'){break;}

		if(ch >= 'A' && ch <= 'Z'){
			Acnt++;
		}
		else if(ch >= 'a' && ch <= 'z'){
			acnt++;
		}
		else if(ch >= '1' && ch <= '9'){
			add = add + ch-'0';
		}
		else{
			ccnt++;
		}
	}
	printf("%d %d %d %d",Acnt,acnt,add,ccnt);
    return 0;
}