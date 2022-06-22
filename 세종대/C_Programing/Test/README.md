종료 조건까지 양의 정수 N을 반복해서 입력받아 다음의 계산 결과를 한 줄 에 차례로 출력하는 프로그램을 작성하시오.
(1) 정수 N 출력
(2) 정수 N의 각 자릿수의 곱을 M이라고 할 때, M을 출력
(3) M의 각 자릿수를 역순으로 바꾼 정수 출력. 단, 역순으로 바꾼 정수의 가장 높은 자릿수는 0이 아니어야 한다. ([ 문제2-1 ]의 출력 예시 2 참고)
(4) 현재 입력된 정수 N과 바로 직전에 입력된 정수의 차를 출력. 단, 첫 번째 입력된 정수의 경우, 이전 입력된 정수가 0이라고 가정하고 차를 계산한다.
- 종료 조건 : 입력된 정수 N이 바로 직전에 입력된 정수보다 작으면 종료한다. 즉, 현재 입력 된 정수가 앞서 입력된 정수보다 크거나 같은 경우 지속적으로 다음 정수를 입력받고, 현재 입력된 정수가 앞서 입력된 정수보다 작으면 “End”를 출력하고 종료된다.
- 최소 두 개 이상의 정수가 입력된다고 가정한다.

1. 입력 받은 정수 N을 출력
2. for문을 이용하여 각 자릿수 곱하기  
    - 시작하는 곱하기 변수는 <mark>0이 아닌 1로</mark> 초기화
3. 역순 변수에 10을 곱하며 누적해서 더하기
4. main 함수에서 저장된 이전 N의 값을 M의 값으로 저장 후 새로운 N의 값에서 빼기

### Test2.c
```c++
#include <stdio.h>

void Solution(int new, int old){
    int mul=1; int reverse=0;
    printf("%d ",new);
    
    for(int i=new; i>0; i=i/10){
    mul = mul * (i%10);
    }
    printf("%d ",mul);

    while(mul>0){
        reverse = reverse * 10;
        reverse = reverse + mul%10;
        mul = mul / 10;
    }
    printf("%d ",reverse);

    printf("%d\n",new-old);
    }

int main(void){
    int N=0; int M=0;
    while(1){
        M=N;
        scanf("%d",&N);
        if(N<M){
            printf("End");
            return -1;
        }
        Solution(N,M); 
    }
    return 0;
}
```


