#include <stdio.h>

#define MAX_SIZE 21000000

int add_digits(int N); // 각 자리수의 합을 계산하는 원형 함수 지정
int main(){
    int N = 0; // 각 변수 지정 및 초기화
    int min = MAX_SIZE;
    int answer = 0;
    int temp = 0;

    while(1){ // 종료조건 전까지 무한 반복
        scanf("%d", &N);
        if(N<0){break;} // 무한루프 입력받기 / 음수가 나오면 정지 
        else{       
            temp = add_digits(N); // 디지털 근 임시저장
            if(min> temp){ // 최소값 갱신 단 최소값이 같다면 제일 먼저 나온 최소값을 써야 하므로 = 제거
                min = temp; // 최소값 갱신
                answer = N; // 최소 디지털 근의 숫자
            }
        }
    }
    printf("%d %d\n",answer,min); // 출력
    return 0;
}

int add_digits(int N){ // 각 자릿수의 합을 구하는 함수 지정
    int sum = 0;
    while(N>0){ // 음수 전까지 반복
        sum = sum+ N%10;
        N = N/10;
    }
    // 모든 자릿수 합 구함

    while(sum>=10)
        sum = add_digits(sum);
    // 자릿수의 합이 10 이상이라면 다시한번 자릿수 구하기
    return sum;
    // 자릿수 반환
}