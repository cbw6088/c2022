#include <stdio.h>
#include <string.h>

int main(){
	char A[51],B[51];
	scanf("%s",A);
	scanf("%s",B);
	if(strcmp(A,B) > 0)
		printf("%s%s",A,B);
	else
		printf("%s%s",B,A);
	return 0;
}