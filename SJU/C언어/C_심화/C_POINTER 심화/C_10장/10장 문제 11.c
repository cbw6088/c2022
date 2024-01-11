#include <stdio.h>
#include <string.h>

int main(){
	char str1[81];
	char str2[11];
	scanf("%s",str1);
	scanf("%s",str2);
	printf("%d ",strlen(str1));
	if(strstr(str1,str2) != NULL)
		printf("1");
	else
		printf("0");
	return 0;
}