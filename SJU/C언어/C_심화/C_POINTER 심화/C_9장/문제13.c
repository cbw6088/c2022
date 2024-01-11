#include <stdio.h>

int arrsum(int *a,int *b);

int main(void){
	int N=0,S=0,E=0,result=0;
	scanf("%d %d %d",&N,&S,&E);
	int arr[N];
	int *p;
	for(p=arr; p<arr+N; p++){
		scanf("%d",p);
	}
	p=arr;

	result = arrsum(p+S,p+E);

	printf("%d",result);

	return 0;
}

int arrsum(int *a,int *b){
	int result=0;
	for(; a != b; a++){
		result = result + *a;
	}
	result = result + *b;
	return result;
}