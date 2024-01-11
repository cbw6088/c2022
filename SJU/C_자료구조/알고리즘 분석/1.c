#include <stdio.h>

int modulo(int a, int b);

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", modulo(a, b)); // 함수 반환 값 출력
    return 0;
}

int modulo(int a, int b){
    if(a < b) return a; //  종료 조건
    return modulo(a - b, b); // 재귀

}
