# C Programing 1차 모의고사

### C_1차 모의고사 1.c
홍길동 교수는 두 번 응시한 C 프로그래밍 시험 성적에서 처음 본 시험의 40%, 두 번 째 본 시험의 60%를 합하여 최종 성적을 산출한 후, 다음과 같은 기준으로 학점을 준다고 한다. 최종 성적이 85.5 이상이면 학점 ‘A’를 출력,
85.5 미만 75.5 이상이면 학점 ‘B’를 출력, 75.5 미만 60.0 이상이면 학점 ‘C’를 출력, 그 미만 학생에게는 학점 ‘F’를 출력한다.
또한, 최종 성적이 60점 이상이거나, 두 번째 본 시험의 성적이 90점 이상이면, “PASS”를 출력하 고, 그렇지 않은 경우에는 “FAIL”을 출력한다.
- 시험 점수는 양수 정수 값으로 0~100점 사이 값으로 입력된다.
- 출력 시에, 학점을 먼저 출력한 후, 빈 칸을 한 칸 두고 메시지를 출력한다. - 이 기준에 따르면, “F PASS” 도 가능하다.

<img width="442" alt="스크린샷 2022-07-02 오후 6 17 15" src="https://user-images.githubusercontent.com/99342700/176994448-4832c41c-4c66-4e74-987f-7980ca71bc84.png">

1. 각각 필요한 변수 지정.
    - 평균 값은 소수점이 나올 수 있으므로 double형으로 지정.
2. 첫 번째 과목의 40%와 두 번째 과목의 60%의 합 저장.
3. 두 과목의 합이 제시된 점수의 범위일 경우 각각 점수 출력.

```c++
#include <stdio.h>

int main(void){
    int N=0; int M=0; double avg=0; double NN=0; double MM=0;
    scanf("%d %d",&N,&M);
    if( (N > 100 || N < 0) || (M > 100 || M < 0) ){return -1;}

    NN = N * 0.4;
    MM = M * 0.6;
    avg = NN + MM;

    //printf("%.1lf %.1lf %.1lf\n",NN,MM,avg);

    if(avg >= 85.5){
        printf("A");
    }
    else if(avg < 85.5 && avg >= 75.5){
        printf("B");
    }
    else if(avg < 75.5 && avg >= 60.0){
        printf("C");
    }
    else{
        printf("F");
    }

    if(avg >= 60 || M >= 90){
        printf(" PASS");
    }
    else{
        printf(" FAIL");
    }

    return 0;
}
```


### C_1차 모의고사 2-2.c
숫자 문자 ‘0’이 입력되기 전까지 알파벳 소문자만, 혹은 대문자만, 혹은 대소 문자 혼합 문자들을 지속적으로 입력받고, 입력된 소문자 중에서 가장 나중 문자와 입력된 대문자 중에서 가장 빠른 문자를 찾아서 출력하는 프로그램을 작성하시오. 입력된 문자 패턴에 따른 출력 방식은 아래 표의 규칙을 따른다.

<img width="431" alt="스크린샷 2022-07-02 오후 6 25 24" src="https://user-images.githubusercontent.com/99342700/176995055-a8efa250-b121-47ee-9567-9c1afd5fa25b.png">

 소문자/대문자는 한 개 이상 입력되며, 동일한 문자는 입력되지 않는다고 가정하시오. - 소문자, 대문자, 숫자 문자 ‘0’ 이외의 다른 문자는 입력되지 않는다고 가정하시오.

 <img width="478" alt="스크린샷 2022-07-02 오후 6 35 03" src="https://user-images.githubusercontent.com/99342700/176995092-15850d79-f809-444a-8fa7-8b91e40f81a9.png">

1. 필요한 변수 지정.
    - 알파벳 상 가장 뒤의 소문자와 가장 앞의 대문자를 나타내는 변수는 각각 범위에 벗어나는 특수기호로 저장.
2. 가장 먼저 입력된 알파벳이 대/소문자인 것에 따라 출력 순서가 바뀌기 때문에 가장 먼저 입력된 알파벳에 체크.
3. 조건문을 이용하여 대문자인 경우 가장 빠른 문자 / 소문자인 경우 가장 늦은 문자를 저장.
4. 순서에 맞추어 출력.

```c++
#include <stdio.h>

int main(void){
    char ch=0; char min = '^'; char max = '^'; int temp=0; int cnt=0;

    while(1){
        scanf("%c",&ch);
        if(ch == '0'){break;}

        if(cnt == 0){
            temp = ch;
            cnt = 1;
        }

        if(ch >= 'A' && ch <= 'Z'){
            if(min >= ch){
                min = ch;
            }
        }

        else if(ch >= 'a' && ch <= 'z'){
            if(max <= ch){
                max = ch;
            }
        }
    }

    if(temp >= 'a' && temp <= 'z'){
        if(max >= 'a' && max <= 'z'){
            printf("%c",max);
        }
        if(min >= 'A' && min <= 'Z'){
            printf("%c",min);
        }
    }
    else if(temp >= 'A' && temp <= 'Z'){
        if(min >= 'A' && min <= 'Z'){
            printf("%c",min);
        }
        if(max >= 'a' && max <= 'z'){
            printf("%c",max);
        }
    }
    return 0;
}
```
