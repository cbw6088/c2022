#include <stdio.h>

void input(int *a, int *b, int *c);
void output(int *a, int *b, int *c);

int main(){
	int a,b,c;
	input(&a,&b,&c);
	output(&a,&b,&c);
	return 0;
}

void input(int *a, int *b, int *c){
	scanf("%d %d %d",a,b,c);
}

void output(int *a, int *b, int *c){
	printf("%d %d %d",*a,*b,*c);
}