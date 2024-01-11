#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to);

int main(){
    int n;
    scanf("%d", &n);
    hanoi_tower(n, 'A', 'B', 'C');
    return 0;
}

void hanoi_tower(int n, char from, char tmp, char to){
    if(n == 1) // 마지막 한 개 남았을 경우 시작점에서 목적지로 이동
        printf("%c %c\n", from, to);
    else{
        /* 여러 연산을 거쳐서 가장 밑에 있는 원반을 제외하고 n-1개의 원반 모두 임시 기둥으로 보내기 */
        hanoi_tower(n - 1, from, to, tmp);
        printf("%c %c\n", from, to);
        hanoi_tower(n - 1, tmp, from, to);
    }
}
