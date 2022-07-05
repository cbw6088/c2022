#include <stdio.h>
int main(void){
	char ch; int N=0; int M='Z'-'A'+1;
	scanf("%c %d",&ch,&N);

	if(ch >= 'a' && ch <= 'z'){
		ch = (ch - 'a' + N) % M + 'a';
		printf("%c",ch);
	}
	else if(ch >= 'A' && ch <= 'Z'){
		ch = (ch - 'A' + N) % M + 'A';
		printf("%c",ch);
	}
	else{
		printf("%c",ch);
	}
  	return 0;
}