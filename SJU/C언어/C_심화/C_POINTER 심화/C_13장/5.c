#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pswap(int **ppx, int **ppy);

int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	int *px = &x;
	int *py = &y;
	pswap(&px, &py);
	printf("%d %d", *px, *py);
	return 0;
}

void pswap(int **ppx, int **ppy){
	int *tmp = NULL;
	tmp = *ppx;
	*ppx = *ppy;
	*ppy = tmp;
}