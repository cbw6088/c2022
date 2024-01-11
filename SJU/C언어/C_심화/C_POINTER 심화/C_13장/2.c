// 오일러

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double factorial(double N);

int main(){
	double N;
	scanf("%lf", &N);
	double t1 = 0, t2 = 1;
	for(int i = 1; i <= N; i++){
		t1 = 1 / factorial(i);
		t2 = t2 + t1;
	}
	printf("%.6lf", t2);
	return 0;
}

double factorial(double N){
	if(N == 1) return 1;
	else return N * factorial(N - 1);
}