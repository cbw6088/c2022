#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
int main(void) { 
    srand(time(NULL)); //NULL을 넣으면 1970년 1월 1일 0시(UTC타임존) 이후 현재까지 흐른 초 수를 반환
    printf(“%d\n”, rand()); 
    return 0;
}