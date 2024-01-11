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



### C_1차 모의고사 3.c
‘*’가입력될때까지문자를%c로계속입력을받고,입력된문자들중에영문대문 자의 개수, 소문자의 개수, 숫자의 합, 그리고 그 이외문자들의 개수를 차례로 출력하는 프로그램 을 작성하시오. ‘*’는 입력으로 간주하지 않는다.

<img width="346" alt="스크린샷 2022-07-03 오후 9 58 03" src="https://user-images.githubusercontent.com/99342700/177040777-ff828299-a37b-4c95-8d76-c31569e0fdbd.png">

1. 필요한 변수 지정.
2. 대/소문자 각각의 갯수, 숫자들의 합, 그 외의 문자 갯수를 조건문에 맞추어 연산.
3. 각각 출력.

```c++
#include <stdio.h>

int main(void){
    char ch;
	int Acnt=0,acnt=0,cnt=0,ccnt=0,add=0;
	while(1){
		scanf("%c",&ch);
		if(ch == '*'){break;}

		if(ch >= 'A' && ch <= 'Z'){
			Acnt++;
		}
		else if(ch >= 'a' && ch <= 'z'){
			acnt++;
		}
		else if(ch >= '1' && ch <= '9'){
			add = add + ch-'0';
		}
		else{
			ccnt++;
		}
	}
	printf("%d %d %d %d",Acnt,acnt,add,ccnt);
    return 0;
}
```



### C_1차 모의고사 4-2.c
종료조건(0 입력)까지 양의 정수 N을 반복해서 입력 받는다. 입력 받은 정수 N 뒤에, N의 자리수를 역순으로 바꾼 정수를 붙여서, 대칭이 되는 정수 M을 만들어 출력하고, 대 칭이 되는 정수 M의 각 자리수에서 3이 나오는 개수를 출력한다. 또한, 대칭되는 정수들 중 최소 값과 최대값을 찾아 출력하는 프로그램을 작성 하시오.

<img width="343" alt="스크린샷 2022-07-04 오후 3 36 48" src="https://user-images.githubusercontent.com/99342700/177095916-1d46ed4e-9289-4f9c-ad6b-d9d993535770.png">

1. 문제에 맞추어 변수 지정.
    - max값은 가장 작은 0, min값은 최대한 크게 저장해서 비교.
2. 무한루프를 이용하여 N이 0이 나오기 전까지 반복.
3. 새로운 변수에 입력받은 N을 저장하고 10씩 곱하면서 1의자리를 저장하여 대칭되는 수를 만들고 출력.
4. 한 자리수씩 해당 값이 3인지 비교 후 3이면 카운트.
5. 카운트 출력 후 최소/최대값 비교하여 출력.

```c++
#include <stdio.h>

int main(void){
    int N=0; int temp=0; int M=0; int cnt=0; int min=1000000; int max=0;

    while(1){
        cnt=0;
        scanf("%d",&N);
        if(N == 0){break;}
        M = N;

        for(int i=N; i>0; i=i/10){
            M = M * 10;
            M = M + i % 10;
        }
        printf("%d ",M);
        
        for(int i=M; i>0; i=i/10){
            temp = i % 10;
            if(temp == 3){
                cnt++;
            }
        }
        printf("%d ",cnt);

        if(min >= M){
            min = M;
        }
        if(max <= M){
            max = M;
        }
    }
    printf("\n%d %d",min,max);
    return 0;
}
```



### C_1차 모의고사 5-3.c
 양의 정수 N과 N개의 정수(음수도 가능) 를 입력받아 연속적으로 소수가 나온 최대 회수를 카운트하고 그 구간의 마지막 소수를 출력 하는 프로그램을 작성하여라. 또한 마지막 줄에는 전체 입력값들 중 최대값과 최소값을 출력한다.
- 단 100 이상인 수는 제외 한다 (소수로 생각하지 않음).
- 소수가 6번 연속 나온 구간이 제일 길다면 6을 출력한다. (입력예시 1)
- 만일 한 번도 소수가 없었다면 0 만을 출력한다. 최대값 최소값을 출력하지 않는다. (문제 4-2 의 입력예시 3)
- 최대 길이가 같은 구간이 있으면 제일 처음 나온 구간의 정보를 출력한다. (입력예시 3)
   N은 1 이상이다. ( N ≧ 1 )

<img width="380" alt="스크린샷 2022-07-04 오후 3 42 13" src="https://user-images.githubusercontent.com/99342700/177096689-a3353143-0577-4a56-9081-d31cee2deea4.png">

1. 필요한 변수 지정.
2. 입력받은 N번 만큼 반복.
3. 최소/최대값 저장.
4. 1부터 자기자신까지 나누었을때 1과 자기자신으로만 나눠지면 소수이므로 카운트값이 2이면 소수.
5. 소수확인 후 카운트를 세서 연속적으로 나온 가장 큰 소수 구간 찾기.
6. 가장 큰 소수 구간의 M값을 저장하여 범위 내의 마지막 소수를 저장.
7. 소수의 갯수와 범위 내의 마지막 소수, 최소/최대값 출력..

```c++
#include <stdio.h>

int main(void){
    int N=0,M=0,cnt=0,ccnt=0,temp=0,last=0,max=0,min=100;
	scanf("%d",&N);

	for(int i=0; i<N; i++){
		scanf("%d",&M);
		if(max < M){
			max = M;
		}
		else if(min > M){
			min = M;
		}
		if(M >= 100){
			cnt = 0;
			continue;
			}

		for(int j=1; j<=M; j++){
			if(M%j==0){
				temp++;
			}
		}

		if(temp == 2){
			cnt++;

			if(ccnt < cnt){
				last = M;
				ccnt = cnt;
			}
		}
		else{
			cnt=0;
		}
		temp=0;
	}
	printf("%d\n%d",ccnt,last);
	printf("\n%d %d",max,min);
    return 0;
}
```