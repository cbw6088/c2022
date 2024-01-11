#include <stdio.h>

int main(void){
    int N=0; int HND=0;
    scanf("%d",&N);
    HND = N/100; 
    switch (HND)
    {
    case 100 : printf("Seoul");
        break;
    case 101 : printf("Seoul");
        break;
    case 102 : printf("Seoul");
        break;
    case 103 : printf("Busan");
        break;
    case 104 : printf("Busan");
        break;
    case 105 : printf("Gwangju");
        break;
    
    default: printf("none");
        break;
    }
    return 0;
}