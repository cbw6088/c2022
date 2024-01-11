#include <stdio.h>

int recursion(int N);

int main(){
    int N;
    scanf("%d", &N);
    printf("%d\n", recursion(N));
    return 0;
}

int recursion(int N){
    if(N == 1) // 종료 조건
        return 1;
    return (recursion(N - 1) + N); // 함수가 끝나면서 반환되는 값 + N
}