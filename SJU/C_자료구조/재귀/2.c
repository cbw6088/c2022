#include <stdio.h>

void recursion(int N);

int main(){
    int N;
    scanf("%d", &N);
    recursion(N);
    return 0;
}

void recursion(int N){
    if(N == 0)
        return;
    recursion(N / 10);
    printf("%d\n", N % 10);
}