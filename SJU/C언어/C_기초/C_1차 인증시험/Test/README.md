# First C_TEST

### C_TEST 1-2.c
세 학과가 공동으로 사용하는 건물의 출입을 위한 비밀번호는 학과 학생들 이 개별 설정할 수 있다. 단, 비밀번호는 [ 문제 1-1 ]의 비밀번호 생성규칙에 의해 생성된다.
정수 N을 입력받고, N명 학생이 건물 출입을 위해 입력한 비밀번호를 입력받아,
(1) 비밀번호를 입력한 학생의 학과명을 출력한다. 단, 비밀번호 생성규칙에 맞지 않는 입력에
대해서는 “none”을 출력한다.

(2) 학과별 건물 출입을 한 학생의 수를 출력한다. 출력 순서는 CE, SW, DS 순이다.

(3) 비밀번호 오류 없이 한 번에 출입이 허용된 학생의 수를 출력한다. 출력 순서는 CE, SW, DS 순이다.

- 단, 비밀번호 오류 발생 후, 건물 출입을 포기한 학생은 없다고 가정한다. 즉, 비밀번호 오류 가 발생한 학생은 정확한 비밀번호를 입력할 때까지 입력을 반복한다고 가정한다.
- 동일한 학생이 두 번 이상 건물 출입을 한 경우도 없다고 가정한다.
- CE 학생이 11200 대신 11300을 오류로 입력하는 경우와 같이, 오류로 입력된 비밀번호가 우
연히 생성 규칙에 맞는 비밀번호인 경우도 없다고 가정한다. 즉, 생성 규칙에 맞는 비밀번호 입력은 모두 오류가 없는 입력이라고 가정한다.

<img width="833" alt="스크린샷 2022-06-27 오후 3 53 21" src="https://user-images.githubusercontent.com/99342700/175877792-1bcfa9f6-3631-4382-b127-848908aefd36.png">

1. 각 변수 선언 후 입력 받기.
2. 조건에 맞추어 변수 값 세팅.
3. CE,SW,DE 해당 값이 나올 때 카운트를 올려주기.
4. "none"가 나오면 표시를 한 후 정상적인 출력이 될 때 따로 표시 후 새로운 카운트 올리기.
5. 마지막에 출력 하면서 올린 카운트 출력과 카운트에서 잘못된 카운트를 뺀 후 출력.

```c++
#include <stdio.h>
int main(void){
    int N=0; int M=0; int HND=0; int c=0; int s=0; int d=0;
    int cnt=0; int cc=0; int sc=0; int dc=0; int x=0; int y=0; int z=0;
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d",&M);
        x = M/10000;
        y = (M/1000)%10;
        z = (M/100)%10;

        if(M>=10000 && M<100000 && M%100==0 && M%10==0){

            if( (x != y && x != z && y != z) || (x == y && x == z && y == z)){
            printf("none\n");
            cnt=1;
            }

            else{
            HND = M/100;
            HND = HND%10;
                if(HND>=0 && HND<3){
                    printf("CE\n");
                    c++;
                    if(cnt != 0){
                        cc++;
                        cnt=0;
                    }
                }    
                else if(HND>=3 && HND<5){
                    printf("SW\n");
                    s++;
                    if(cnt != 0){
                        sc++;
                        cnt=0;
                    }
                }
                else if(HND==5){
                    printf("DS\n");
                    d++;
                    if(cnt != 0){
                        dc++;
                        cnt=0;
                    }
                }
                else{
                    printf("none\n");
                    cnt=1;
                }
            }
        }

        else{
            printf("none\n");
            cnt=1;
        }
    }
    printf("%d %d %d\n",c,s,d);
    printf("%d %d %d",c-cc,s-sc,d-dc);
  return 0;
}
```



### C_TEST 2-2.c
종료 조건까지 양의 정수 N을 반복해서 입력받아 다음의 계산 결과를 한 줄 에 차례로 출력하는 프로그램을 작성하시오.
(1) 정수 N 출력

(2) 정수 N의 각 자릿수의 곱을 M이라고 할 때, M을 출력

(3) M의 각 자릿수를 역순으로 바꾼 정수 출력. 단, 역순으로 바꾼 정수의 가장 높은 자릿수는 0이 아니어야 한다. ([ 문제2-1 ]의 출력 예시 2 참고)

(4) 현재 입력된 정수 N과 바로 직전에 입력된 정수의 차를 출력. 단, 첫 번째 입력된 정수의 경우, 이전 입력된 정수가 0이라고 가정하고 차를 계산한다.
- 종료 조건 : 입력된 정수 N이 바로 직전에 입력된 정수보다 작으면 종료한다. 즉, 현재 입력 된 정수가 앞서 입력된 정수보다 크거나 같은 경우 지속적으로 다음 정수를 입력받고, 현재 입력된 정수가 앞서 입력된 정수보다 작으면 “End”를 출력하고 종료된다.
- 최소 두 개 이상의 정수가 입력된다고 가정한다.

<img width="801" alt="스크린샷 2022-06-27 오후 3 52 24" src="https://user-images.githubusercontent.com/99342700/175877625-514a1d21-b3e8-4b2d-b4c1-520126103a2c.png">

1. 입력 받은 정수 N을 출력
2. for문을 이용하여 각 자릿수 곱하기  
    - 시작하는 곱하기 변수는 <mark>0이 아닌 1로</mark> 초기화
3. 역순 변수에 10을 곱하며 누적해서 더하기
4. main 함수에서 저장된 이전 N의 값을 M의 값으로 저장 후 새로운 N의 값에서 빼기

```c++
#include <stdio.h>
int main(void){
	int N=0; int mul=1,re=0,sub=0;

	while(1){
		sub = N;
		scanf("%d",&N);
		if(N < sub){return -1;}
		printf("%d ",N);

		for(int i=N; i>0; i=i/10){
			mul = mul * (i % 10);
		}
		printf("%d ",mul);

		for(int i=mul; i>0; i=i/10){
			re = re * 10;
			re = re + i % 10;
		}
		printf("%d ",re);

		printf("%d\n",N-sub);
		mul = 1;
		re = 0;
	}
  	return 0;
}
```



### C_TEST 3.c
정수 N을 입력받고, N개의 양의 정수를 입력받아, 입력된 정수 중 소수만을 출력한다. 출력 방식은 연속적으로 소수가 나오는 경우 같은 줄에 출력하고, 소수가 아닌 정수가 입력되다가 다시 소수가 나오면 줄을 바꾸어 출력하도록 프로그램을 작성하시오.
- 연속적으로 나오는 소수는 개수에 관계없이 모두 한 줄에 출력한다. - 각 줄 마지막에 별표(*)를 출력하시오.
- N개의 양의 정수 중, 소수가 최소 1개 이상이라고 가정한다.

<img width="834" alt="스크린샷 2022-06-27 오후 3 51 29" src="https://user-images.githubusercontent.com/99342700/175877451-4064ddd4-d586-4fbc-acd9-bccd511d6b3b.png">

1. N을 입력 받은 후 N번 만큼의 반목문 실행.
2. 나눠질 경우 카운트를 올리고 카운트가 1이라면 소수.
3. 소수일 시 입력 받은 값을 출력 하고 아닐 시 별과 줄바꿈 출력.

```c++
#include <stdio.h>
int main(void){
	int N=0,M=0,cnt=0,last=0;
	scanf("%d",&N);

	for(int i=0; i<N; i++){
		scanf("%d",&M);

		for(int j=2; j<=M; j++){
			if(M%j == 0){
				cnt++;
			}
		}
		if(cnt==1){
			printf("%d ",M);
		}
		else{
			printf("*\n");
		}
		cnt=0;
	}
  	return 0;
}
```



### C_TEST 4-1.c
종료 조건까지 문자를 연속해서 입력받아, 영문 대문자 또는 영문 소문자 중 알파벳 순서상 가장 빠른 문자와 가장 나중 문자를 출력하는 프로그램을 작성하시오.
- 종료 조건 : ‘!’ 입력
- ‘A’와 ‘a’처럼 알파벳 순서가 동일한 두 문자가 입력된 경우에는 대문자 ‘A’가 소문자 ‘a’보다 빠르다고 가정한다. 즉, 이 문제에서 영문자의 빠른 순서는 A, a, B, b, C, c, D, d, E, e ... 순 서이다.
- 입력되는 문자 중에는 영문자가 한 개 이상 있다고 가정한다. 영문자가 한 개 입력되는 경우, 가장 빠른 문자와 가장 나중 문자는 동일한 문자이다.

<img width="821" alt="스크린샷 2022-06-27 오후 6 27 42" src="https://user-images.githubusercontent.com/99342700/175907703-b7af616c-ad29-4b9e-8bc1-592b0f2e2537.png">

1. 변수 지정 (max,min의 최초 값은 가장 작은 값, 가장 큰 값 저장)
2. 입력된 값이 알파벳인 경우에만 실행.
3. 입력되는 소문자는 모두 대문자로 바꾸고 비교가 후 다시 소문자로 바꾸어 변수에 값 저장.
4. 입력된 값이 크거나 같을 시 max에 값 저장.
5. 입력된 값이 작거나 같을 시 min에 값 저장.
6. 반복문이 끝날 때 max와 min을 제외한 변수 초기화.
7. max,min값 출력.

```c++
#include <stdio.h>

int main(void){
    char new; char max='A'; char min='Z';
    int cnt1=0; int cnt2=0; int cnt3=0;

    while(1){
        scanf("%c",&new);
        if(new == '!'){break;}

        if( (new >= 'A' && new <= 'Z') || (new >= 'a' && new <= 'z') ){

            if(new >= 'a' && new <= 'z'){
                new = new - 32;
                cnt1 = 1;
            }
            if(max >= 'a' && max <= 'z'){
                max = max - 32;
                cnt2 = 1;
            }
            if(min >= 'a' && min <= 'z'){
                min = min - 32;
                cnt3 = 1;
            }

            if(max <= new){
                if(cnt1 == 1){
                    new = new + 32;
                }
                max = new;
                if(cnt1 == 1){
                    new = new - 32;
                }
            }
            else{
                if(cnt2 == 1){
                    max = max + 32;
                }
            }

            if(min >= new){
                if(cnt1 == 1){
                    new = new + 32;
                }
                min = new;
            }
            else{
                if(cnt3 == 1){
                    min = min + 32;
                }
            }
            
            cnt1=0;
            cnt2=0;
            cnt3=0;
        }
        
    }
    printf("%c\n%c",min,max);
    return 0;
}
```



### C_TEST 4-2.c
종료 조건까지 문자를 연속해서 입력받는다. 영문 대문자 또는 영문 소문자 의 연속된 입력을 하나의 구간이라고 한다. 예를 들어, (입력 예시 1)의 첫 번째 구간은 “sAd”이고, 두 번째 구간은 “Ijfgh”이며, 세 번째 구간은 “Kup” 이다. 각 구간에서 알파벳 순서상 가장 빠른 문자와 두 번째로 빠른 문자를 출력하는 프로그램을 작성하시오.
- 종료 조건 : ‘!’ 입력
- ‘A’와 ‘a’처럼 알파벳 순서가 동일한 두 문자가 입력된 경우에는 대문자 ‘A’가 소문자 ‘a’보다 빠르다고 가정한다. 즉, 이 문제에서 영문자의 빠른 순서는 A, a, B, b, C, c, D, d, E, e ... 순 서이다.
- 입력되는 문자의 각 구간마다 영문자가 두 개 이상 있다고 가정하고, 한 구간에서 같은 문자 가 두 번 이상 나오는 경우는 없다고 가정한다.

<img width="817" alt="스크린샷 2022-06-27 오후 3 50 27" src="https://user-images.githubusercontent.com/99342700/175877306-be0a9655-d70e-4908-9ee2-db9771817c94.png">

1. 입력 받을 변수와 비교 할 변수 등등 지정.
    - 비교 할 first / second 는 초기값을 크게 잡아 최초 비교시 바로 값이 저장되게 설정.
2. 이전 값인 temp가 알파벳이고 현재 값인 ch가 알파벳이 아닐 때 출력 및 변수 초기화.
3. 입력 받은 문자가 알파벳인 경우에서 소문자인 경우에는 대문자로 바꾸어 대소 비교.
4. 문자가 빠르면 소문자에서 대문자로 바뀌었는지 확인 후 바뀌었으면 비교값엔 대문자 출력값엔 소문자 저장.
5. 바뀌지 않았으면 그대로 저장.

```c++
#include <stdio.h>
int main(void){
	char ch,temp; int al=0,dl=0; char first='Z'; char second='Z'; char one,two;

	while(1){
		al = 0;
		temp = ch;
		scanf("%c",&ch);
		if(ch == '!'){return -1;}

		if( (temp >= 'A' && temp <='Z') || (temp >= 'a' && temp <= 'z') ){
			if( (ch < 'A' || ch > 'Z') && (ch < 'a' || ch > 'z') ){
				printf("%c%c\n",one,two);
				first='Z';
				second='Z';
			}
		}

		if( (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')){
			if(ch >= 'a' && ch <= 'z'){
				ch = ch - 32;
				al = 1;
			}

			if(first >= ch){
				if(al == 1){
					ch = ch + 32;
					if(first == ch-32){
						second = ch-32;
						two = ch;
					}
					else{
						second = first;
						first = ch-32;
						two = one;
						one = ch;
					}	
				}
				else{
					second = first;
					first = ch;
					two = one;
					one = ch;
				}
			}
			else if(second >= ch){
				if(al == 1){
					ch = ch + 32;
					second = ch-32;
					two = ch;
				}
				else{
					second = ch;
					two = ch;
				}
			}
		}
	}
  	return 0;
}
```



### C_TEST 5-1.c
영문 소문자 C1과 C2를 입력받아, C1과 C2를 포함한 C1과 C2 사이의 소문 자 세 개로 이루어진 단어 중 다음의 조건을 만족하는 단어를 출력하는 프로그램을 작성하시오.

<img width="786" alt="스크린샷 2022-06-27 오후 3 21 42" src="https://user-images.githubusercontent.com/99342700/175872879-d8c5921b-8b20-47c2-b989-68b2825d3c17.png">

- 출력 순서는 단어가 사전에 나오는 순서이다. 사전에 나오는 순서란 알파벳 순서가 빠른 문 자로 이루어진 단어가 먼저 출력된다는 의미이다. 예를 들어, aab와 abc를 비교해보면, 첫 번 째 문자는 ‘a’로 동일하지만, 두 번째 문자인 aab의 ‘a’가 abc의 ‘b’보다 빠르기 때문에 aab가 abc보다 사전 순서 상 빠른 단어이다.
- C1과 C2 사이의 문자로 조건에 맞는 단어가 만들어지지 않는 경우에는 “none”을 출력한다.
- C1은 C2 보다 알파벳 순서 상 빠른 문자라고 가정한다.

<img width="829" alt="스크린샷 2022-06-27 오후 3 49 17" src="https://user-images.githubusercontent.com/99342700/175877074-c0263f0c-f1e2-4322-ab56-22c00f2d7e9e.png">

1. 변수 지정 후 변수에 알파벳 범위 입력.
2. i,j,k 를 반복하며 출력.
    - 중간값 모음 지정.
    - 모음이 아닐 시 에러 표시 후 "none" 출력.
    - i와 k의 값이 서로 달라야 범위 내에서 알파벳들이 모두 같은 문자가 나오지 않음.
    - 중간값에 들어가는 모음은 언제나 첫 번째와 세 번째 사이의 값으로 지정.
3. 조건을 충족시키지 못할 시 "none" 출력

```c++
#include <stdio.h>

int main(void){
    char N; char M;
    int err=0;
    scanf("%c%c",&N,&M);
    for(char i = N; i <= M; i++){
        for(char j = N; j <= M; j++){
            for(char k = N; k <= M; k++){
                if(j=='a' || j=='e' || j=='i' || j=='o' || j=='u'){
                    if(i != k){
                        if(i <= j && k >= j){
                            printf("%c%c%c\n",i,j,k);
                        }
                        else if(i >= j && k <= j){
                            printf("%c%c%c\n",i,j,k);
                        }
                    }
                }
                else{
                    err=1;
                }
            }
        }
    }
    if(err==1){
        printf("none");
    }
    return 0;
}
```



### C_TEST 5-2.c
영문 소문자 C1, C2와 영문 소문자 세 개로 이루어진 단어 T를 C1C2-T의 형식으로 입력받아,
(1) C1과 C2를 포함한 C1과 C2 사이의 소문자 세 개로 이루어진 단어 중 [ 문제5-1 ]의 단어 생성 조건을 만족하는 단어를 사전에 나오는 순서로 출력한다.

(2) (1)에서 출력된 단어 중에서, 단어 T보다 사전순서상 빠른 가장 마지막으로 출력된 단어를 출력한다.
- (1)의 출력 순서는 단어가 사전에 나오는 순서이다. 사전에 나오는 순서란 알파벳 순서가 빠 른 문자로 이루어진 단어가 먼저 출력된다는 의미이다. 예를 들어, aab와 abc를 비교해보면, 첫 번째 문자는 ‘a’로 동일하지만, 두 번째 문자인 aab의 ‘a’가 abc의 ‘b’보다 빠르기 때문에 aab가 abc보다 사전 순서 상 빠른 단어이다.
- C1과 C2 사이의 문자로 조건에 맞는 단어가 만들어지지 않는 경우에는 “none”을 출력한다.
- 사전순서상 T보다 빠른 단어를 찾을 수 없는 경우에도 “none”을 출력한다. (출력 예시 2와 3 참고)
- C1은 C2 보다 알파벳 순서 상 빠른 문자라고 가정한다.

<img width="821" alt="스크린샷 2022-06-27 오후 3 47 44" src="https://user-images.githubusercontent.com/99342700/175876886-35ffd97c-2a54-44e0-8242-345c80469875.png">

1. 변수 지정 후 변수에 알파벳 범위와 T값 입력.
2. i,j,k 를 반복하며 출력.
    - 중간값 모음 지정.
    - 모음이 아닐 시 에러 표시 후 "none" 출력.
    - i와 k의 값이 서로 달라야 범위 내에서 알파벳들이 모두 같은 문자가 나오지 않음.
    - 중간값에 들어가는 모음은 언제나 첫 번째와 세 번째 사이의 값으로 지정.
3. i와 T1, j와 T2, k와 T3의 크기를 비교하여 T값보다 사전 순서상 빠르면 값 저장.
4. 알파벳 범위와 T값 각각 조건을 충족시키지 못할 시 "none"출력

```c++
#include <stdio.h>

int main(void){
    char N; char M; char T1,T2,T3; char t1,t2,t3;
    int err=0; int T=0;
    scanf("%c%c-%c%c%c",&N,&M,&T1,&T2,&T3);
    for(char i = N; i <= M; i++){
        for(char j = N; j <= M; j++){
            for(char k = N; k <= M; k++){
                if(j=='a' || j=='e' || j=='i' || j=='o' || j=='u'){
                    err=1;
                    if(i != k){
                        if( (i <= j && k >= j) || (i >= j && k <= j) ){
                            printf("%c%c%c\n",i,j,k);
                            if(i < T1){
                            T=1;
                            t1 = i;
                            t2 = j;
                            t3 = k;
                        }
                        else if(i == T1){
                            if(j < T2){
                                t1 = i;
                                t2 = j;
                                t3 = k;
                            }
                            else if(j == T2){
                                if(k < T3){
                                    t1 = i;
                                    t2 = j;
                                    t3 = k;
                                }
                            }
                        }
                        }
                        
                    }
                }
            }
        }
    }
    if(err==0){
        printf("none\n");
    }
    if(T==1){
        printf("%c%c%c",t1,t2,t3);
    }
    else if(T==0){
        printf("none");
    }
    return 0;
}
```