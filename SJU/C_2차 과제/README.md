# C Programming 과제.2 (조건문)

### C_과제 1.c
세 과목 점수 (0~100점 사이 정수)를 입력받는다. 세 과목 평균점수가 ◌ 90점 이상이면 “A”출력
◌ 80점 이상이면 “B”출력
◌ 70점 이상이면 “C” 출력
◌ 60점 이상이면 “D” 출력
◌ 어느 조건에도 해당되지 않으면 “F”가 출력되도록 작성하시오. – 그다음, 입력된 값들 중 최대값과 최소값을 화면에 출력하시오.

<img width="298" alt="스크린샷 2022-06-29 오후 6 19 13" src="https://user-images.githubusercontent.com/99342700/176401223-471d2e30-7029-4eff-824e-8c52c1421356.png">

1. 입력 받을 세개의 정수와 평균값을 저장 할 변수 지정.
2. 세개의 정수를 모두 더한 후 정수의 갯수 만큼 나눠서 평균값 변수에 저장.
3. 조건문을 사용하여 해당 문제에 명시된 조건에 맞추어 각각 기준 점수를 지정한 후 해당 점수일 시 출력.
4. 조건문을 사용하여 가장 큰 정수를 찾아서 출력.
5. 조건문을 사용하여 가장 작은 정수를 찾아서 출력.

```c++
#include <stdio.h>
int main(void){
	int A=0,B=0,C=0,avg=0;
	scanf("%d %d %d",&A,&B,&C);

    avg = (A+B+C)/3;

    if(avg >= 90){
        printf("A\n");
    }
    else if(avg >= 80){
        printf("B\n");
    }
    else if(avg >= 70){
        printf("C\n");
    }
    else if(avg >= 60){
        printf("D\n");
    }
    else{
        printf("F\n");
    }

    if(A > B && A > C){
        printf("max : %d\n",A);
    }
    else if(B > A && B > C){
        printf("max : %d\n",B);
    }
    else if(C > A && C > B){
        printf("max : %d\n",C);
    }

    if(A < B && A < C){
        printf("min : %d\n",A);
    }
    else if(B < A && B < C){
        printf("min : %d\n",B);
    }
    else if(C < A && C < B){
        printf("min : %d\n",C);
    }
	
  	return 0;
}
```



### C_과제 2.c
변종 분식에는 아래와 같은 메뉴가 있다. 대한이는 민국이와 함께 만 원짜리 지폐 한 장으로 들고 3개의 메뉴를 시켜 먹었다. 총 금액과 잔돈을 계산하여 예시와 같이 출력하는 프로그 램을 작성하시오.
- 음식 값이 예산(만원)을 초과하는 경우에는 잔돈이 아닌 “Insufficient Money”를 출력한다. - 메뉴 중복 선택가능. (예시) 메뉴 입력이 2 2 2처럼 같은 메뉴 주문도 가능하다.
- 메뉴는 무조건 3개를 시킨다.

<img width="490" alt="스크린샷 2022-06-29 오후 6 41 51" src="https://user-images.githubusercontent.com/99342700/176405971-9ecd71c1-6866-4e50-bcfb-7261816aa039.png">
<img width="391" alt="스크린샷 2022-06-29 오후 6 42 16" src="https://user-images.githubusercontent.com/99342700/176406003-a82e316f-9bdf-445d-8835-1d22e09e2890.png">

1. 입력 받을 변수, 각 메뉴, 총 금액, 남은 금액 변수 지정.
2. 입력 받은 변수 별로 각 메뉴를 지정했을 때 값을 총 금액에 더해주고 남은 금액에서는 빼기.
3. 남은 금액이 음수일 시 "Insufficient Money" 출력 양수일 시 총 금액과 남은 금액 출력.

```c++
#include <stdio.h>
int main(void){
	int N=0,M=0,S=0;
	int A=5000,B=2500,C=2000,D=1500,E=1000;
	int total=0;
	int money=10000;

	scanf("%d %d %d",&N,&M,&S);

	if(N == 1){
		total = total + A;
		money = money - A;
	}
	else if(N == 2){
		total = total + B;
		money = money - B;
	}
	else if(N == 3){
		total = total + C;
		money = money - C;
	}
	else if(N == 4){
		total = total + D;
		money = money - D;
	}
	else if(N == 5){
		total = total + E;
		money = money - E;
	}

	if(M == 1){
		total = total + A;
		money = money - A;
	}
	else if(M == 2){
		total = total + B;
		money = money - B;
	}
	else if(M == 3){
		total = total + C;
		money = money - C;
	}
	else if(M == 4){
		total = total + D;
		money = money - D;
	}
	else if(M == 5){
		total = total + E;
		money = money - E;
	}

	if(S == 1){
		total = total + A;
		money = money - A;
	}
	else if(S == 2){
		total = total + B;
		money = money - B;
	}
	else if(S == 3){
		total = total + C;
		money = money - C;
	}
	else if(S == 4){
		total = total + D;
		money = money - D;
	}
	else if(S == 5){
		total = total + E;
		money = money - E;
	}

	if(money < 0){
		printf("Insufficient Money");
	}
	else{
		printf("Total:%d\nChange:%d",total,money);
	}



  	return 0;
}
```



### C_과제 3.c
문자 1개와 숫자 1개를 예시와 같이 입력할 경우, 문자를 입력한 숫자만큼 증가 (예시 1) 시키는 프로그램을 작성하라.
- 조건) 대문자 및 소문자에 대해서 적용되며 숫자 및 특수문자는 입력한 글자를 그대로 출력한 다. 대문자의 끝 'Z'에 도달 한 경우 앞 'A'로 이동한다. 소문자 'z' 다음에는 소문자 'a'로 이동 한다. (힌트: 나머지 연산자 ‘%’ 사용)

<img width="445" alt="스크린샷 2022-06-29 오후 7 06 44" src="https://user-images.githubusercontent.com/99342700/176411114-7ee3c149-5eec-4e7c-8a3d-355f17239327.png">

1. 입력 받을 변수와 연산 할 변수 지정.
2. 소문자 / 대문자 / 그 외 범위 별로 나누어 조건문 사용.
3. 입력 받은 문자의 아스키코드 값에서 해당 범위의 알파벳 만큼 뺀 후 이동 할 값을 더하기.
4. 위에서 계산한 값을 아스키코드 값으로 나누어서 'Z'값이 넘어갈 때 다시 알파벳 맨 처음으로 오도록 세팅.
5. 세팅된 값에서 처음에 뺀 범위 내의 알파벳 더하기.
6. 각각 나온 값을 출력. (알파벳이 아닌경우 그대로 출력)

```c++
#include <stdio.h>
int main(void){
	char ch; int N=0; int M='Z'-'A'+1;
	scanf("%c %d",&ch,&N);

	if(ch >= 'a' && ch <= 'z'){
		ch = (ch - 'a' + N) % M + 'a';
		printf("%c",ch);
	}
	else if(ch >= 'A' && ch <= 'Z'){
		ch = (ch - 'A' + N) % M + 'A';
		printf("%c",ch);
	}
	else{
		printf("%c",ch);
	}
  	return 0;
}
```



### C_과제 4.c
두 자리 10진 정수를 입력 받은 후 영어단어로 변환하는 프로그램을 작성하시오. 예) 45를 입력할 경우 “forty-five”를 출력한다. 단, 입력된 정수가 두 자리 10진 정수가 아닌 경우 "none"을 출력한다.
- 힌트: if문안에 switch문을 사용한다(중첩).

<img width="299" alt="스크린샷 2022-06-29 오후 7 26 50" src="https://user-images.githubusercontent.com/99342700/176415087-f70bace0-003f-47df-a1c4-d770de303898.png">

1. 입력 할 변수와 각 자릿수 별로 출력 할 변수 지정.
2. 10~19까지 스위치문을 입력하여 출력.
3. 20 이상이면 스위치문을 이용하여 10의자리와 1의자리 각각 출력.
4. 범위 내에 해당 안될 시 "none"출력.

```c++
#include <stdio.h>

int main(void){
    int N=0; int max=0; int min=0;
    scanf("%d",&N);
    if(N>=10 && N <100){
        if(N >= 10 && N < 20){
            switch (N)
            {
            case 10 : printf("ten");
                break;
            case 11 : printf("eleven");
                break;
            case 12 : printf("twelve");
                break;
            case 13 : printf("thirteen");
                break;
            case 14 : printf("fourteen");
                break;
            case 15 : printf("fifteen");
                break;
            case 16 : printf("sixteen");
                break;
            case 17 : printf("seventeen");
                break;
            case 18 : printf("eighteen");
                break;
            case 19 : printf("nineteen");
                break;
            }
        }
        else{
            max = N/10; 
            min = N%10; 
            switch (max) 
            {
            case 2 : printf("twenty");
                break;
            case 3 : printf("thirty");
                break;
            case 4 : printf("forty");
                break;
            case 5 : printf("fifty");
                break;
            case 6 : printf("sixty");
                break;
            case 7 : printf("seventy");
                break;
            case 8 : printf("eighty");
                break;
            case 9 : printf("ninety");
                break;
            } 
            switch (min)
            {
            case 1 : printf("-one");
                break;
            case 2 : printf("-two");
                break;
            case 3 : printf("-three");
                break;
            case 4 : printf("-four");
                break;
            case 5 : printf("-five"); 
                break;
            case 6 : printf("-six");
                break;
            case 7 : printf("-seven");
                break;
            case 8 : printf("-eight");
                break;
            case 9 : printf("-nine"); 
                break;
            }
        }
    }
    else{
        printf("none");
    }

    return 0;
}
```



### C_과제 5.c
5자리의 양의 정수를 입력 받아 앞의 세 자리로 지역을 구분하는 프로그램을 if 문(문 제 5)과 switch 문(문제 6)으로 각각 완성하시오. 마지막 두 자리는 00으로 가정한다. 서울은 100, 101, 102로 시작한다. 입력의 오류(20100, 10111, 100123, - 10100, 70000, ... 등 형식에 맞지 않 는 입력값)에 대하여 none을 출력한다.

<img width="439" alt="스크린샷 2022-06-29 오후 7 42 10" src="https://user-images.githubusercontent.com/99342700/176417964-b16dae38-a859-42b4-a4bc-0c10e9304518.png">

1. 입력 받을 변수와 100의자리로 나타낼 변수 지정.
2. 입력 받은 변수를 100으로 너누어 100의자리 정수로 만들기.
3. if문을 이용하여 변수 중 1의자리의 수를 케이스별로 나누어 출력. 
4. 해당 조건에 해당하지 않을 시 "none"출력.

```c++
#include <stdio.h>

int main(void){
    int N=0; int HND=0;
    scanf("%d",&N);
    HND = N/100;
    if(HND==100){
        printf("Seoul");
    }
    else if(HND==101){
        printf("Seoul");
    } 
    else if(HND==102){
        printf("Seoul");
    }
    else if(HND==103){ 
        printf("Busan");
    }
    else if(HND==104){
        printf("Busan");
    }
    else if(HND==105){
        printf("Gwangju");
    }
    else{
        printf("none");
    }

    return 0;
}
```

### C_과제 6.c
5자리의 양의 정수를 입력 받아 앞의 세 자리로 지역을 구분하는 프로그램을 if 문(문 제 5)과 switch 문(문제 6)으로 각각 완성하시오. 마지막 두 자리는 00으로 가정한다. 서울은 100, 101, 102로 시작한다. 입력의 오류(20100, 10111, 100123, - 10100, 70000, ... 등 형식에 맞지 않 는 입력값)에 대하여 none을 출력한다.

<img width="439" alt="스크린샷 2022-06-29 오후 7 42 10" src="https://user-images.githubusercontent.com/99342700/176417964-b16dae38-a859-42b4-a4bc-0c10e9304518.png">

1. 입력 받을 변수와 100의자리로 나타낼 변수 지정.
2. 입력 받은 변수를 100으로 너누어 100의자리 정수로 만들기.
3. switch문을 이용하여 변수 중 1의자리의 수를 케이스별로 나누어 출력. 
4. 해당 조건에 해당하지 않을 시 "none"출력.

```c++
#include <stdio.h>

int main(void){
    int N=0; int HND=0;
    scanf("%d",&N);
    HND = N/100; 
    switch (HND)
    {
    case 100 : printf("Seoul");
        break;
    case 101 : printf("Seoul");
        break;
    case 102 : printf("Seoul");
        break;
    case 103 : printf("Busan");
        break;
    case 104 : printf("Busan");
        break;
    case 105 : printf("Gwangju");
        break;
    
    default: printf("none");
        break;
    }
    return 0;
}
```