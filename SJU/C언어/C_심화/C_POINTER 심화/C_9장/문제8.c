#include <stdio.h>

void swap(int *a,int *b);

int main(){
	int N,a,b;
	scanf("%d",&N);
	int ar[N];
	int *p = ar;
	for(; p<ar+N; p++)
		scanf("%d",p);
	scanf("%d %d",&a,&b);
	p = ar;
	swap(p+a, p+b);
	for(p=ar; p<ar+N; p++)
		printf(" %d",*p);
	return 0;
}

void swap(int *a,int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}