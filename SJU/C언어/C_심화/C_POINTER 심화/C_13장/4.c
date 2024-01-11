#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
	unsigned int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	a = a * (256 * 256 * 256);
	b = b * (256 * 256);
	c = c * 256;
	d = d * 1;
	printf("%d", a + b + c + d);
	return 0;
}