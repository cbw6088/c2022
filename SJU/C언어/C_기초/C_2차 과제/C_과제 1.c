#include <stdio.h>
int main(void){
	int A=0,B=0,C=0,avg=0;
	scanf("%d %d %d",&A,&B,&C);

    avg = (A+B+C)/3;

    if(avg >= 90)
        printf("A\n");
    else if(avg >= 80)
        printf("B\n");
    else if(avg >= 70)
        printf("C\n");
    else if(avg >= 60)
        printf("D\n");
    else
        printf("F\n");

    if(A > B && A > C)
        printf("max : %d\n",A);
    else if(B > A && B > C)
        printf("max : %d\n",B);
    else if(C > A && C > B)
        printf("max : %d\n",C);
    if(A < B && A < C)
        printf("min : %d\n",A);
    else if(B < A && B < C)
        printf("min : %d\n",B);
    else if(C < A && C < B)
        printf("min : %d\n",C);
	
  	return 0;
}