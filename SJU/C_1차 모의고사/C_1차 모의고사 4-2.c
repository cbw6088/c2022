#include <stdio.h>

int main(void){
    int N=0; int temp=0; int M=0; int cnt=0; int min=1000000; int max=0;

    while(1){
        cnt=0;
        scanf("%d",&N);
        if(N == 0){break;}
        M = N;

        for(int i=N; i>0; i=i/10){
            M = M * 10;
            M = M + i % 10;
        }
        printf("%d ",M);
        
        for(int i=M; i>0; i=i/10){
            temp = i % 10;
            if(temp == 3){
                cnt++;
            }
        }
        printf("%d ",cnt);

        if(min >= M){
            min = M;
        }
        if(max <= M){
            max = M;
        }
    }
    printf("\n%d %d",min,max);
    return 0;
}