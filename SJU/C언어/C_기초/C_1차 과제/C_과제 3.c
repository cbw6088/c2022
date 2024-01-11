#include<stdio.h>

int main(void){
	int A=0; int B=0; int C=0; 
	char result;
	scanf("%d %d %d",&A, &B, &C);
	A = A / 100;
	B = B / 100;
	C = C / 100;

	printf("A [%d] B [%d] C [%d]\n", A, B, C);

	result = (A == B && A == C) * 'T' +
	(A == B && A != C) * 'D' +
	(A != B && A == C) * 'D' +
	(B == C && B != A) * 'D' +
	( (A != B && A != C) && (B != C && B != A) ) * 'S';

	printf("result [%c]",result);
	return 0;
}