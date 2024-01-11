#include <stdio.h>

int isPrime(int *p);

int main(){
    int N = 0;
    scanf("%d", &N);

    int A[N];
    int *p;
    int Num =1;
    for(p = A; p<A+N; p++)
        *p = Num++;

    int * T = A;
   
    for(p = A; p<A+(N/2); p++){
        if(isPrime(p)){
           int temp = N-*p;
           if(isPrime(T+(temp-1))){
            printf("%d %d\n", *p,temp);
           }
        }
    }
        
    return 0;
}

int isPrime(int *p){
    int cnt = 0;
    int temp = *p ;
    if(temp ==1){return 0;}
    
    for(int i=2; i<temp; i++){
        if( temp %i ==0){
            cnt++;
        }
        if(cnt !=0){return 0;}
    }
    return 1;
}