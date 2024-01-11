// 피보나치

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fibonacci(int N);

int main(){
	int N;
	scanf("%d", &N);
	printf("%d", fibonacci(N));
	return 0;
}

int fibonacci(int N){
	if(N <= 0) return 0;
	else if(N == 1) return 1;
	else return fibonacci(N - 2) + fibonacci(N - 1);
}