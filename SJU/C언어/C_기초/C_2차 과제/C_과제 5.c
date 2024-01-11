#include <stdio.h>

int main(void){
    int N=0; int HND=0;
    scanf("%d",&N);
    HND = N/100;
    if(HND==100){
        printf("Seoul");
    }
    else if(HND==101){
        printf("Seoul");
    } 
    else if(HND==102){
        printf("Seoul");
    }
    else if(HND==103){ 
        printf("Busan");
    }
    else if(HND==104){
        printf("Busan");
    }
    else if(HND==105){
        printf("Gwangju");
    }
    else{
        printf("none");
    }

    return 0;
}