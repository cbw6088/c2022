#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *add(int *x, int *y);

int main(){
	int A, x, y;
	scanf("%d", &A);
	void *p = &A;
	printf("%d\n",*(int*)p);

	scanf("%d %d", &x, &y);
	int *fp = NULL;
	fp = add(&x, &y);
	printf("%d", *fp);
	return 0;
}

int *add(int *x, int *y){
	int *p = NULL;
	int sum = *x + *y;
	p = &sum;
	return p;
}