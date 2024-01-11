#include <stdio.h>

int sum(int n);

int main(){
    int n = 0;
    scanf("%d", &n);
    printf("%d", sum(n)); // 반환 값 출력
    return 0;   
}

int sum(int n){
    if (n == 1) // 재귀 종료 조건
        return 1;
    int total = 0;
    for(int i = 1; i <= n; i++) // 1부터 현재 값 까지 더하기
        total += i;
    return (total + sum(n - 1)); // 재귀 이용
}