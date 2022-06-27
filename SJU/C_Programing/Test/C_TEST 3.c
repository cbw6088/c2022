#include <stdio.h>

int main() { 
int N=0; int M=0; int cnt=0; int cnt2=0;
scanf("%d",&N);
while(N){
    scanf("%d",&M);
    cnt=0;
    for(int i=1; i<=M; i++){
        if(M%i==0){
            cnt++;
        }
    }

    if(cnt==2){

        if(cnt2!=0){
            printf(" *");
            printf("\n");
            cnt2=0;
        }

        printf("%d ",M);
    }
    else if(cnt>2){
        cnt2++;
    }
    N--;
}
printf("*");
return 0; 
}