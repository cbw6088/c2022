#include <stdio.h>
#include <string.h>

int main(void) {
	int N=0,temp=0,idx=0;
	char arr[9];
	scanf("%d",&N);
	for(int i=N; i>0; i=i/10){
		arr[idx++] = i%10+48;
	}
	printf("%s",arr);
	return 0;
}