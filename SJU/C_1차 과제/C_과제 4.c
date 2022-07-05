#include <stdio.h>
int main(void){
  	int a=0; int b=0; int c=0; int d=0;
  	int n=0; int result=0; int add=0;
	scanf("%d", &n);

	a = n/1000;
	b = ((n/100)%10) * 10;
	c = ((n/10)%10) * 100;
	d = (n%10) * 1000;
	
	add = a+b+c+d;
	result = n - add;

	result > 0 ? printf("%d",n-add) : printf("%d",add-n);

  	return 0;
}