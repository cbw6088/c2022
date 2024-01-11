#include <stdio.h>

void strcopy(char a[],char b[]);

int main(void){
	char arr[6],ch[6];
	char *p;
	for(p=arr; p<arr+6; p++){
		scanf("%c",p);
	}

	strcopy(arr,ch);

	for(p=ch; p<ch+6; p++){
		printf("%c",*p);
	}


	return 0;
}

void strcopy(char a[],char b[]){
	for(int i=0; i<6; i++){
		b[i] = a[i];
	}
}