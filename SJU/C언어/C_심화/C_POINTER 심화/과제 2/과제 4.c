#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int s_check(char *p, char *q); // 원형 함수 선언

int main(){
    int testCase = 0; // M
    scanf("%d",&testCase); // M값 입력
    char str[200] = {}; // 배열 및 변수 선언
    int K1 = 0;
    int K2 = 0;

    scanf("%d %d",&K1, &K2); // K값 입력
    getchar();

    for(int i=0; i<testCase; i++){ // M만큼 반복
        gets(str);
        
        int cnt = 0;
        cnt = s_check(str+K1, str+K2); // 함수 반환값 저장
        if(cnt != 0) // 소문자가 있는 경우 출력
            printf("%d\n",cnt);
    }
    
    return 0;
}

int s_check(char *p, char *q){
    int cnt = 0, len = 0; // 변수 선언
    char *tmp1 = p, *tmp2 = q;

    len = strlen(tmp1)-strlen(tmp2) ; // p와 q의 차 

    for(tmp1=p; tmp1<=p+len; tmp1++){
        if(*tmp1 >= 'a' && *tmp1 <= 'z') // 소문자인 경우
            cnt++;
    }

    return cnt;
}