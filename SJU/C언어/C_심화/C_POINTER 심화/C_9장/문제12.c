#include <stdio.h>

void addArray(int *a, int *b, int *c, int N);

int main(){
	int N;
	scanf("%d",&N);
	int aar[N],bar[N],car[N];

	int *a = aar;
	int *b = bar;
	int *c = car;
	for(; a<aar+N; a++)
		scanf("%d",a);
	for(; b<bar+N; b++)
		scanf("%d",b);
	a = aar;
	b = bar;

	addArray(a,b,c,N);
	a = aar;
	b = bar;
	c = car;
	for(; c<car+N; c++)
		printf("%d ",*c);
	return 0;
}

void addArray(int *a, int *b, int *c, int N){
	int tmp = N-1;
	for(int i=0; i<N; i++){
		*c = *(a+i) + *(b+tmp);
		c++;
		tmp--;
	}
}