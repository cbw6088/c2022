#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ABS(x) ( (x) > 0 ? (x) : (-x) )
#define MAX(x,y) ( (x) > (y) ? (x) : (y) ); 

int main(){
	int ar1[6] = {}, ar2[6] = {};
	for(int i = 0; i < 6; i++)
		scanf("%d", &ar1[i]);
	
	for(int i = 0; i < 6; i++)
		ar2[i] = ar1[i];
	
	int max = 0, abs = 0;

	max = ABS(ar1[0]) > ABS(ar1[1]) ? ar1[0] : ar1[1];
	max = ABS(max) > ABS(ar1[2]) ? max : ar1[2];
	max = ABS(max) > ABS(ar1[3]) ? max : ar1[3];
	max = ABS(max) > ABS(ar1[4]) ? max : ar1[4];
	max = ABS(max) > ABS(ar1[5]) ? max : ar1[5];
	abs = ABS(max);
	printf("%d %d", max, abs);
	
	return 0;
}

/*
-3 2 4 -5 1 7
-9 4 3 8 7 -1
*/