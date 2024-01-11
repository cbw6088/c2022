#include <stdio.h>
int main(void){
	int N=0; int a=0,b=0,c=0; int result=0;
	scanf("%d",&N);

	a = (N/100) % 10;
	b = (N/10) % 10;
	c = N % 10;

	result = ( (a == b) && (a == c)) * 3 +
	( (a == b) && (a != c) ) * 2 +
	( (a != b) && (a == c) ) * 2 +
	( (b == c) && (b != a) ) * 2 +
	( (a != b) && (a != c) ) * 1;

	printf("%d",result);

  	return 0;
}