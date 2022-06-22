#include <stdio.h>

void Solution(int new, int old){
    int mul=1; int reverse=0;
    printf("%d ",new);
    
    for(int i=new; i>0; i=i/10){
    mul = mul * (i%10);
    }
    printf("%d ",mul);

    while(mul>0){
        reverse = reverse * 10;
        reverse = reverse + mul%10;
        mul = mul / 10;
    }
    printf("%d ",reverse);

    printf("%d\n",new-old);
    }

int main(void){
    int N=0; int M=0;
    while(1){
        M=N;
        scanf("%d",&N);
        if(N<M){
            printf("End");
            return -1;
        }
        Solution(N,M); 
    }
    return 0;
}