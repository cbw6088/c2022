#include <stdio.h>

int gcd(int a, int b);

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
    return 0;
}

int gcd(int a, int b){
    if (b == 0) // 최종적으로 b가 0이 될 때 a 반환
        return a;
    return (gcd(b, a % b)); 
}

/* 사용 예시 */
/*
gcd(1788, 16)
1788 % 16 = 12
기존값 b인 16과 나머지 연산으로 나온 12의 최대공약수 다시 구하기
gcd(16, 12)
16 % 12 = 4
기존값 b인 12과 나머지 연산으로 나온 4의 최대공약수 다시 구하기
gcd(12, 4)
12 % 4 = 0
0이 나왔을 때, b의 값
*/