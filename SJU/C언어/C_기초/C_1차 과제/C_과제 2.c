#include<stdio.h>

int main(void){
	int N=0; char result=0;
	scanf("%d",&N);

	result = ( (N%4==0 || N%400==0) && (N%100!=0) ) ? 'L' : 'C';
	printf("%c",result);

	return 0;
}