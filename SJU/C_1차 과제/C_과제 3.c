#include<stdio.h>

int main(void){
	int A=0; int B=0; int C=0; 
	char result;
	scanf("%d %d %d",&A, &B, &C);
	A = (A/100) % 10;
	B = (B/100) % 10;
	C = (C/100) % 10;

	result = (A == B && A == C) * 'T' +
	(A == B && A != C) * 'D' +
	(A != B && A == C) * 'D' +
	(B == C && B != A) * 'D' +
	( (A != B && A != C) && (B != C && B != A) ) * 'S';

	printf("%c",result);
	return 0;
}