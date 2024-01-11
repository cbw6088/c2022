// 유쿨리드

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Euclidean(int A, int B);

int main(){
	int A,B;
	scanf("%d %d", &A, &B);
	printf("%d", Euclidean(A,B));
	return 0;
}

int Euclidean(int A, int B){
	if(B == 0) return A;
	else return Euclidean(B, A % B);
}