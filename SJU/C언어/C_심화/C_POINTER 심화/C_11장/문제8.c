#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct complex{
    double A[2];
};

int main(){
    struct complex num1, num2;
    for(int i=0; i<2; i++)
        scanf("%lf %lf", &num1.A[i], &num2.A[i]);
    printf("%.1lf + %.1lfi", num1.A[0] + num1.A[1], num2.A[0] + num2.A[1]);
    return 0;
}