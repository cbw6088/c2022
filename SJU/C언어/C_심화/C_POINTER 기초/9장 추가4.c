#include <stdio.h>
#include <string.h>

void repeat(char ar[], int N);

int main(){
	int N;
	char ar[100]={};
	char *p = ar;
	scanf("%s",p);
	getchar();
	p = ar;
	scanf("%d",&N);
	p = ar;
	repeat(p,N);
	return 0;
}

void repeat(char ar[], int N){
	char *p = ar;
	int cnt=0,idx=0;
	while(1){
		if(*(p+idx) == '*')
			break;
		idx++;
		cnt++;
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<cnt; j++){
			printf("%c",*p);
			p++;
		}
		p = ar;
	}
	printf("*");
}