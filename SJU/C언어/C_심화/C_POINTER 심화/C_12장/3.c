#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N;
	char ch1, ch2;
	scanf("%d", &N);
	getchar();
	char *p = (char*)malloc(sizeof(char)*N);
	if(p == NULL){
		printf("Not enough memory!");
		return -1;
	}
	
	for(int i=0; i<N; i++)
		scanf("%c", p+i); 
	getchar();
	scanf("%c %c", &ch1, &ch2);
	
	int cnt1 = 0, cnt2 = 0;
	for(int i=0; i<N; i++){
		if( *(p+i) == ch1 )
			cnt1++;
		if( *(p+i) == ch2 )
			cnt2++;
	}
	printf("%d %d",cnt1, cnt2);
	free(p);
	return 0;
}