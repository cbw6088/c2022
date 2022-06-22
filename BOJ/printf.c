#include <stdio.h>
int main(void)
{
int A=0;
int B=0;
scanf("%d %d", &A,&B);
if( (-10000<=A && A<=10000) && (B>=-10000 && B<=10000) )
{
    if(A<B)
    {
        printf("<\n");
    }
    else if(A>B)
    {
        printf(">\n");
    }
    else
    {
        printf("=\n");
    }
}
else
{
    printf("input error \n");
    return -1;
}
return 0;
}
