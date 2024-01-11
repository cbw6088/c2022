#include <stdio.h>
int main(void){
	int N = 0, a = 0, b = 0, c = 0, result=0;
	scanf("%d",&N);

	a = (N/100) % 10;
	b = (N/10) % 10;
	c = N % 10;

	result = ( (a < b && a > c) || (a > b && a < c) ) * a +
	( (b < a && b > c) || (b > a && b < c) ) * b +
	( (c < a && c > b) || (c > a && c < b) ) * c;

	printf("%d",result);

  	return 0;
}