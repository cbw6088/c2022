#include <stdio.h>

void gcdlcm(int a,int b,int *c,int *d);

int main(void){
	int a=0,b=0,c=0,d=0;
	scanf("%d %d",&a,&b);
	gcdlcm(a,b,&c,&d);
	printf("%d %d",c,d);
	return 0;
}

void gcdlcm(int a,int b,int *c,int *d){
	int x=a;
	int y=b;
	int temp=0;
	while(y != 0){
		temp = y;
		y = x % y;
		x = temp;
	}
	*c = x;
	*d = a*b/(*c);
}