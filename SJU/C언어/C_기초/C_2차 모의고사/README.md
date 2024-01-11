# Second C_TEST

### C_2차 모의고사 1.c
N개의 양의 정수를 배열에 입력 받은 후, 배열의 각 요소가 몇 번 반복이 되었는지 배 열의 각 요소의 순서대로 반복횟수를 출력하는 프로그램을 작성하시오.
-N은10이상,50이하의양의정수, 10≦N≦50
- 입력되는 양의 정수는 중복 입력이 가능함
- 배열의 각 요소에 대해서, 반복되는 요소의 경우, 첫 번째로 나타난 요소를 기준으로 출력함, 즉 두 번째 부터 나타나는 배열의 요소는 출력하지 않음

<img width="814" alt="스크린샷 2022-07-08 오후 5 27 26" src="https://user-images.githubusercontent.com/99342700/177950980-a14151a8-64b1-420d-bbef-70b6f917444d.png">

1. 각 변수 지정
2. N의 크기만큼 배열을 만들어 값 입력.
3. 자기자신부터 인덱스 0까지 비교하여 같은 수가 자기자신 한개면 새로운 배열에 저장
4. 인덱스를 전체적으로 비교하면서 한번 비교한 인덱스에는 -1을 저장하여 다음 비교에 지장 않가게 세팅.
5. 저장한 배열 출력.

```c++
#include <stdio.h>

int main(void){
	int N=0,cnt=0,idx=0,ccnt=0,num=0,check=0;
	scanf("%d",&N);
	int X[N],Y[N],Z[N];
	for(int i=0; i<N; i++){
		scanf("%d",&X[i]);
	}

	for(int i=0; i<N; i++){
		for(int j=i; j>=0; j--){
			if(X[i] == X[j]){
				ccnt++;
			}
		}
		if(ccnt == 1){
			Z[num++] = X[i];
		}
		ccnt=0;
	}

	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			if(X[i] > 0){
				if(X[i] == X[j]){
					Y[idx] = cnt++; 
					X[j] = -1;
				}
				check = 1;
			}
		}
		if(check == 1){
			Y[idx] = cnt++;
			idx++;
		}
		cnt = 0;
		check = 0;
	}
	
	for(int i=0; i<num; i++){
		printf("%d %d\n",Z[i],Y[i]+1);
	}
	return 0;
}

```



### 2차 모의고사 2.c
첫번째‘*’가입력될때까지영어소문자를%c로계속입력받아배열x에저장하 고, 두 번째 ‘*’가 입력될 때 까지 영어 소문자를 %c로 계속 입력 받아 배열 y에 저장한다.
- 즉 두 단어 (first_word, second_word)를 다음과 같이 입력받는다. first_word*second_word*
- ‘*’를 단어에 포함하지 않는다.
- 저장된 두 영어 단어 중에서 사전에서 먼저 나타나는 단어를 출력하시오. - 입력되는 문자수는 최대 100 이다. 각 단어는 문자 1개 이상이다.
- 두 단어가 같은 경우 둘 중 하나를 출력한다.
- 주의: 사전에서 aa 는 aaa 보다 먼저 나타난다.

<img width="567" alt="스크린샷 2022-07-09 오후 6 26 20" src="https://user-images.githubusercontent.com/99342700/178099997-12bb61ce-344f-481a-8bb0-46260b5f0348.png">

1. 필요한 변수 지정.
2. 조건에 맞춰 X,Y배열을 각각 저장.
3. 두 배열을 앞 자리부터 비교하여 두 인덱스 중 작은 크기의 배열이 끝날 때 까지 반복.
4. 큰 배열에 체크를 하고 같으면 다음 인덱스로 넘어가 다시 비교.
5. 체크한 부분의 배열을 출력.
6. 비교한 배열까지 모두 같은 경우 인덱스 차이로 결정이 남으로 인덱스 큰 부분에 체크하고 출력.

```c++
#include <stdio.h>

int main(void){
	int N=0,idx=0,idx2=0,check=0,cnt=0;
	char ch,dh;
	char X[100],Y[100];
	while(1){
		scanf("%c",&ch);
		if(ch == '*'){break;}
		X[idx++] = ch;
	}

	while(1){
		scanf("%c",&dh);
		if(dh == '*'){break;}
		Y[idx2++] = dh;
	}

	for(int i=0; i<idx && i<idx2; i++){
		if(X[i] < Y[i]){
			check = 1;
			break;
		}
		else if(X[i] > Y[i]){
			check = 2;
			break;
		}
		else{
			check = 3;
			continue;
		}
	}
	if(idx <= idx2){
		cnt=1;
	}
	else{
		cnt=2;
	}

	if(check == 1){
		for(int i=0; i<idx; i++){
			printf("%c",X[i]);
		}
	}
	if(check == 2){
		for(int i=0; i<idx2; i++){
			printf("%c",Y[i]);
		}
	}
	if(check == 3){
		if(cnt == 1){
			for(int i=0; i<idx; i++){
				printf("%c",X[i]);
			}
		}
		else if(cnt == 2){
			for(int i=0; i<idx2; i++){
				printf("%c",Y[i]);
			}
		}
	}
	return 0;
}
```



### C_2차 모의고사 3-2.c
양의 정수 N을 입력받은 후, N개의 정수를 입력받는다(N < 100). 입력받은 정수들 중에서 정수의 부호가 교대로 나오는 부분 배열을 찾는다 (즉, 음수-양수-음수 혹은 양수- 음수-양수 패턴을 가지는 부분 배열). 이러한 부분 배열 중에서 가장 긴 배열의 크기와 해당 부분 배열을 출력하는 프로그램을 작성하시오. 단, 입력받는 정수는 중복될 수 있으며, 부분 배열 중에 서 가장 긴 배열의 크기를 가지는 배열이 여러 개인 경우 가장 마지막 배열을 출력한다.

<img width="818" alt="스크린샷 2022-07-10 오후 9 09 35" src="https://user-images.githubusercontent.com/99342700/178144347-815b6f78-fda1-4ada-a394-04559ad5bd72.png">

1. 필요한 변수 지정 및 N값 입력.
2. 크기 N만큼의 배열을 만들고 값 저장.
3. 곱하기 연산을 이용하여 연속하는 두 정수가 음수인지 양수인지 판단.
4. 음수이면 부호가 반대이므로 두 정수를 다른 배열에 순서대로 저장.
5. 아닐 시 인덱스 크기를 비교하여 가장 큰 인덱스 구하기.
6. 구한 인덱스 만큼 새로운 배열에 저장.
7. 현재 값과 다음 값을 계산하는 연산이므로, 마지막 인덱스 따로 구하기.
8. 모든 부호가 같은 경우는 체크 0으로 저장하여 갯수는 1개 값은 마지막 값 출력.
9. 그게 아니면 가장 길게 이어진 인덱스의 갯수와 배열 출력.

```c++
#include <stdio.h>

int main(void){
	int N=0,cnt=0,idx=0,max=0,check=0; 
	scanf("%d",&N);
	if(N >= 100){return -1;}
		int x[N],y[N],z[N];

	for(int i=0; i<N; i++){ // N번 반복
		scanf("%d",&x[i]);  
	}

	for(int i=0; i<N-1; i++){ 
		if((x[i] * x[i+1]) < 0){ // 부호가 반대인 경우
			y[idx] = x[i];
			y[idx+1] = x[i+1];
			idx++;
		} //if
		else{ // 부호가 같은 경우
			if(idx > 0){
				check = 1;
				if(max <= idx){
					max = idx;
					for(int i=0; i<idx+1; i++){
						z[i] = y[i];
					}
				}
				idx=0;	
			}
		} //else

		if(i == N-2){ // 마지막 인덱스 계산
			if(idx > 0){
				check=1;
				if(max <= idx){
					max = idx;
					for(int i=0; i<idx+1; i++){
						z[i] = y[i];
					} 
				idx=0;
				}	
			}
		} 

	} //for

	if(check == 0){ // 부호가 반대인 경우가 없는 경우
		if(N != 0){
			printf("%d\n",max+1);
			printf(" %d",x[N-1]);
		}
	}

	if(check == 1){ // 부호가 반대인 경우가 있는 경우
		printf("%d\n",max+1);
		for(int i=0; i<max+1; i++){
			printf(" %d",z[i]);
		}
	}
	return 0;
}

```



### C_2차 모의고사 4-2.c
학생 수 N을 입력받고, N명 학생에 대한 두 번의 인증시험 점수에 대해서 학생별로 학번, 1차인증점수, 2차인증점수, 평균, 등수, 그리고 인증시험의 PASS/FAIL 여부를 P/F로 출력하는 프로그램을 작성하시오. 단, 4≦ N ≦20.
- 인증시험 점수는 정수형 데이터이다.
- 학번은 입력된 순서대로 1번부터 N번까지 부여한다.
- 학생별 평균 점수는 1차 점수의 40%와 2차 점수의 60%를 합산한 점수이다.
(학생별 평균은 소수점 1자리까지 표시한다.)
- 동점인 학생은 같은 등수를 부여받는다. (출력 예시 1 참고)
- N명의 학생 중 상위 70%의 학생에게 'P'를 부여하고, 나머지 학생들에게 'F'를 부여한다.
(예를 들어, 총 9명의 학생 중 70%는 6.3명이며, 이는 6명으로 간주되어, 6등까지 ‘P’를 받는 다. 소숫점 이하 반올림하지 않고 버린다.)
- 동점인 학생들은 같은 학점을 받는다.
(예를 들어, 총 9명중 6등인 학생이 2명 이상이면, 6등은 모두 ‘P’를 받는다.)
- 동점자가 다수인 경우, ‘F’가 없는 경우도 생길 수도 있다.
- 두 번째 시험점수가 80점 이상인 경우, 상위 70%에 들지 않더라도 'P'를 출력한다.

<img width="833" alt="스크린샷 2022-07-11 오후 11 35 05" src="https://user-images.githubusercontent.com/99342700/178289436-769fe44a-ab47-430e-9558-c6633029b532.png">


1. 각 변수 지정.
2. 두 성적 모두 입력 받기.
3. 순서를 나타내기 위해 카운트 1씩 더해서 1~10까지 지정.
4. x배열의 40% y배열의 60%만큼의 값을 더해서 최종 값 구하기.
5. 각각 순위 구하기.
6. 인원수에서 점수 조건에 맞는 만큼 최종 값과 연산하여 각자 필요한 등급 저장.
7. 각각 출력.

```c++
#include <stdio.h>

int main(void){
	int N=0,cnt1=1;
	scanf("%d",&N);
	int x[N],y[N],z[N],cnt[N];
	double avg[N];
	char ch[N];

	for(int i=0; i<N; i++){
		scanf("%d",&x[i]);
	}
	for(int i=0; i<N; i++){
		scanf("%d",&y[i]);
	}
	for(int i=0; i<N; i++){
		z[i] = i+1;
	}
	for(int i=0; i<N; i++){
		avg[i] = (x[i] * 0.4) + (y[i] * 0.6);
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(avg[i] < avg[j]){
				cnt1++;
			}
		}
		cnt[i] = cnt1;
		cnt1 = 1;
	}
	// for(int i=0; i<N; i++){
	// 	printf("%d ",cnt[i]);
	// }
	for(int i=0; i<N; i++){
		if(cnt[i] <= (N*0.7) || y[i] >= 80){
			ch[i] = 'P';
		}	
		else{
			ch[i] = 'F';
		}
	}

	for(int i=0; i<N; i++){
		printf("%d %d %d %.1lf %d %c\n", z[i], x[i], y[i], avg[i], cnt[i], ch[i]);
	}

	return 0;
}
```



### C_2차 모의고사 5-3
종료 조건 시까지 정수 N을 반복해서 입력받아, 아래의 작업을 순차적으로 수행하는 프로그램을 작성하시오. 정수 N은 최대 9자리 수라고 가정한다.
- 종료 조건: 음수 입력 (입력된 음수에 대해서는 아래 작업을 수행하지 않음)
1) [ 문제 5-1 ]의 reverse_num()함수를 이용하여 정수 N을 거꾸로 변경한다. (출력은 안함)
2) 1단계 결과로 만들어진 정수에 대해, [ 문제 5-2 ]의 del_dupnum()함수를 이용하여 중복된
숫자들을 제외한 정수 M을 만들어 main함수에서 출력한다.
3) 입력된 정수 N과 1, 2단계를 거쳐 만들어진 정수 M의 차이가 가장 큰 수를 찾아 입력 정수 N과 함께 그 차이를 main함수에서 출력한다. N과 M의 차이는 N-M의 절대값으로 계산한다. 만일 차이가 같은 경우가 있으면 제일 먼저 입력된 정수와 차이를 출력한다.
4) 함수원형선언을 하여, reverse_num() 함수와 del_dupnum() 함수의 정의는 main함수 뒤에 오 도록 작성 한다.

<img width="824" alt="image" src="https://user-images.githubusercontent.com/99342700/178408799-c6b52271-572e-4e19-94dd-0694e80f2e19.png">

1. 원형 함수 지정 및 변수 지정.
2. reverse_num함수를 이용하여 입력 받은 값을 뒤집기.
3. del_dupnum함수를 이용하여 뒤집은 값에 중복되는 값 제거.
	- 중복 제거는 공식처럼 암기.
4. 해당 값 순차적으로 출력.
5. 입력 받은 값과 뒤집은 값의 차이가 가장 많이나는 값을 저장하고 초기 값과 뺀 값을 절대값으로 출력.

```c++
#include <stdio.h>

int reverse_num(int x);
int del_dupnum(int x);
int main(void){
	int N=0,M=0,re=0,num=0,idx=0,result=0,max=0,sub=0,a=0,idx2=0;
	int arr[100]={0}; int x[100];
	while(1){
		scanf("%d",&N);
		if(N < 0)break;

		re = reverse_num(N);
		M = del_dupnum(re);

		x[idx2++] = M;

		num = N - M;
		result = num > 0 ? N-M : M-N;

		if(max < result){
			max = result;
			a = N;
			sub = result;
		}
	}
	for(int i=0; i<idx2; i++){
		printf(" %d",x[i]);
	}
	printf("\n");
	printf("%d %d",a, sub);
	return 0;
}

int reverse_num(int x){
	int re=0;
	for(int i=x; i>0; i=i/10){
		re = re * 10;
		re = re + i % 10;
	}
	return re;
}

int del_dupnum(int x){
	int a[100],b[100],c[100];
	int idx=0,cnt=0,idx2=0,result=0;
	for(int i=x; i>0; i=i/10){
		a[idx++] = i%10;
	}
	for(int i=0; i<idx; i++){
		c[i] = a[idx-1-i];
	}

	for(int i=0; i<idx; i++){
		for(int j=i; j>=0; j--){
			if(c[i] == c[j]){
				cnt++;
			}
		}
		if(cnt == 1){
			b[idx2++] = c[i];
		}
		cnt=0;
	}
	for(int i=0; i<idx2; i++){
		result = result * 10;
		result = result + b[i];
	}
	return result;
}

```