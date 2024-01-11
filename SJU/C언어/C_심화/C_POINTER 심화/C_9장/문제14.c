#include <stdio.h>

int add_to_k(int *a, int *b);

int main(void){
	int N=0,result=0;
	scanf("%d",&N);
	int arr[N];
	int *p;
	for(p=arr; p<arr+N; p++){
		scanf("%d",p);
	}
	p=arr;
	for(int i=0; i<N; i++){
		result = result + add_to_k(p,p+i);
	}
	printf("%d",result);
	return 0;
}

int add_to_k(int *a, int *b){
	int result = 0;
	for(; a!=b; a++){
		result = result + *a;
	}
	result = result + *b;
	return result;
}