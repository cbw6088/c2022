#include <stdio.h>

int main(){
	int ar[3];
	int tmp,max=-10000000;
	int *p = ar;
	for( ; p<ar+3; p++)
		scanf("%d",p);
	p = ar;

	if( (*p >= *(p+1)) && (*p <= *(p+2)) || (*p <= *(p+1)) && (*p >= *(p+2)) )
		tmp = 0;
	else if( (*(p+1) >= *p) && (*(p+1) <= *(p+2)) || (*(p+1) <= *p) && (*(p+1) >= *(p+2)) )
		tmp = 1;
	else if( (*(p+2) >= *p) && (*(p+2) <= *(p+1)) || (*(p+2) <= *p) && (*(p+2) >= *(p+1)) )
		tmp = 2;
	printf("%d",*(p+tmp));
}