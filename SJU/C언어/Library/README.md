### <strong>시간함수</strong>
<strong>시간함수란?</strong>
매 순간 흐르는 시간을 반환해주는 함수이다.
<br>사용 예시는 밑에 난수발생함수와 같이 쓰인다.

### <strong>난수발생함수</strong>
<strong>난수발생함수란?</strong>
<br>난수란 주사위 눈수처럼 특정한 나열 순서나 규칙이 없이 생성된 무작위 수를 말하며 영어로는 random number라고 한다. 그리고 난수발생 함수란 난수를 자동생성시켜 공급해주는 함수를 말한다.
<strong><br>Tip!!</strong>
<br>rand() % n
- 0 ~ (n – 1) 범위의 난수를 생성한다.
- 예 1: 0 ~ 1 사이의 정수 난수를 발생시키고 싶다면, rand() % 2로 호출.
- 예 2: 0 ~ 10000 사이의 정수 난수를 발생시키고 싶다면, rand() % 10001로 호출.
rand() % n + m
- m ~ (n – 1 + m) 범위의 난수를 생성한다.
- 예 1: 1 ~ 6 사이의 정수 난수(예: 주사위 눈수)를 발생시키고 싶다면, rand() % 6 + 1로 호출.
- 예 2: 1000 ~ 9999 사이의 정수 난수를 발생시키고 싶다면, rand() % 9000 + 1000으로 호출.

```c++
#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
int main(void) { 
    srand(time(NULL)); //NULL을 넣으면 1970년 1월 1일 0시(UTC타임존) 이후 현재까지 흐른 초 수를 반환
    printf(“%d\n”, rand()); 
    return 0;
}
```

### <strong>시간측정함수</strong>
<strong>시간측정함수란?</strong>
<br>라이브러리 함수 가운데 일반적인 시간측정 함수인 clock()을 사용하면 시간이 정밀하게 나오지 않는 문제가 발생한다. 대안으로 QueryPerformanceCounter() 함수를 사용하면 정밀한 시간을 출력할 수 있다. 구체적인 사용 방법은 다음과 같다.
- 헤더파일로 windows.h를 추가한 후,
- LARGE_INTEGER 변수 선언하고,
- QueryPerformanceFrequency() 함수를 통해 타이머의 주파수를 변수에 저장한 후,
- 시간을 측정하고 싶은 작업의 전후에 QueryPerformanceCounter()를 호출하고 그 반환값들을 이용하여 계산, 출력하면 된다.

```c++
#include <stdio.h>
#include <Windows.h>

int main(void){
    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start,end,diff;

    QueryPerformanceFrequency(&tickPerSec);
    QueryPerformanceCounter(&start); // 시간을 측정하고 싶은 작업을 이곳에 삽입
    QueryPerformanceCounter(&end);

    //측정값으로부터 실행시간 계산
    diff.QuaPart = end.Quapart - start.QuadPart;
    printf("time : %.12f sec\n\n",((double)diff.QuadPart/(double)ticksPerSec.QuadPart));
    return 0;
}
```