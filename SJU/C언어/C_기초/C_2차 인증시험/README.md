# Second C_TEST

### C_TEST 1-2.c
정수 N을 입력받는다.

(1) N개의 정수를 입력받아 0보다 큰 정수만 배열에 저장하고, 배열에 저장된 정수의 개수를 출력 한다. 단, N≦100이고, 입력되는 정수 중에 한 개 이상의 양의 정수가 있다고 가정한다.

(2) 배열에 저장된 정수의 개수가 홀수이면, 배열에 저장된 정수를 작은 수부터 큰 수까지 오름차 순으로 정렬하여 출력한다.

(3) 배열에 저장된 정수의 개수가 짝수이면, 배열에 저장된 정수를 큰 수부터 작은 수까지 내림차 순으로 정렬하여 출력한다.

(4) 정렬된 배열에서 홀수가 연속해서 나오는 횟수를 세어서, 이 중 최대 횟수를 출력한다. 예를 들어, 7 9 11과 같이 홀수 3개가 배열에 연속해서 저장된 경우, 홀수가 연속해서 나오는 횟수는 3 회로 센다. 배열에 저장된 정수 중 한 개 이상의 홀수가 있다고 가정한다.

<img width="838" alt="image" src="https://user-images.githubusercontent.com/99342700/178638957-1df01256-b5e1-449b-997e-44f9a867421f.png">

1. 필요한 변수와 배열 지정.
2. 배열에 N의 정수 크기만큼 값 저장.
3. 저장된 정수의 개수가 짝수이면 내림차순 공식 사용.
4. 저장된 정수의 개수가 홀수이면 오름차순 공식 사용.
5. 저장한 값 출력.
6. 저장한 값 중 홀수인 값이 연속으로 나오는 경우 카운트를 세고 카운트 수를 비교하여 가장 긴 카운트 출력.

```c++
#include <stdio.h>

int main(void){
	int N=0,M=0,temp=0,idx=0,cnt=0,cnt2=0,cnt3=0;
	scanf("%d",&N);
	int X[N];

	for(int i=0; i<N; i++){
		scanf("%d",&M);
		if(M > 0){
			X[idx++] = M;
		}
	}
	for(int i=0; i<idx; i++){
		cnt++;
	}
	printf("%d\n",cnt);

	if(cnt%2 == 0){
		for(int i=0; i<idx; i++){
			for(int j=0; j<idx-1; j++){
				if(X[j] <= X[j+1]){
					temp = X[j];
					X[j] = X[j+1];
					X[j+1] = temp;
				}
			}
		}
	}
	else if(cnt%2 != 0){
		for(int i=0; i<idx; i++){
			for(int j=0; j<idx-1; j++){
				if(X[j] >= X[j+1]){
					temp = X[j];
					X[j] = X[j+1];
					X[j+1] = temp;
				}
			}
		}
	}

	for(int i=0; i<idx; i++){
		printf("%d ",X[i]);
	}
	printf("\n");

	for(int i=0; i<idx; i++){
		if(X[i]%2 != 0){
			cnt2++;
		}
		else if(X[i]%2 == 0){
			if(cnt3 <= cnt2){
				cnt3 = cnt2;
			}
			cnt2=0;
		}
	}
	printf("%d",cnt3);
	return 0;
}
```



### C_TEST 2-2.c
정수 N과 M을 입력받고, N개의 양의 정수를 입력받아 배열에 저장한다. 단, 1≦N≦100이고, 1≦M≦N이다.

(1) 배열에 저장된 정수를 앞에서부터 M개씩 묶어서, M개 정수의 평균값보다 크거나 같은 정수를
차례로 출력한다.

(2) 배열에 저장된 정수를 앞에서부터 M개씩 묶어서, M개 정수 중 가장 큰 수를 차례로 출력한 다.

(3) 배열에 저장된 정수를 앞에서부터 M개씩 묶어서, M개 정수 중 가장 작은 수를 차례로 출력한 다.

(4) 배열의 원소를 M개씩 묶고, 마지막 남은 원소의 개수가 M보다 작은 경우, 남은 원소의 평균 보다 크거나 같은 정수, 가장 큰 수, 가장 작은 수를 출력한다. 마지막 남은 원소가 한 개인 경우, 이 원소값이 최대값이자 최소값이 된다.

<img width="846" alt="image" src="https://user-images.githubusercontent.com/99342700/178883321-c79ce229-5224-493a-940f-8fde6e63e3be.png">

1. 필요한 변수 및 배열 지정.
2. 평균값 연산을 이용하여 평균값보다 큰거나 같은 정수 출력.
3. 조건문을 이용하여 0으로 저장한 max값 보다 클 경우 max에 저장하여 출력.
4. 조건문을 이용하여 큰 값으로 저장한 min값 보다 작은 경우 min에 저장하여 출력.

```c++
#include <stdio.h>

int main(void){
	int N=0,M=0,max=0,min=110,idx=0,idx2=0,cnt=0;
	double avg=0,add=0;
	scanf("%d %d",&N,&M);
	int X[N],Y[N],max_cnt[N],min_cnt[N];
	for(int i=0; i<N; i++){
		scanf("%d",&X[i]);
	}

	for(int i=0; i<N; i=i+M){
		for(int j=i; j<i+M && j<N; j++){
			add = add + X[j];
			cnt++;
		}
		avg = add / cnt;

		for(int k=i; k<i+M && k<N; k++){
			if(avg <= X[k]){
				Y[idx++] = X[k];
			}
		}
		cnt=0;
		add=0;
		avg=0;
	}

	for(int i=0; i<idx; i++){
		printf("%d ",Y[i]);
	}
	printf("\n");

	for(int i=0; i<N; i=i+M){
		max = X[i];
		min = X[i];
		for(int j=i; j<i+M && j<N; j++){
			if(max <= X[j]){
				max = X[j];
			}
			if(min >= X[j]){
				min = X[j];
			}
		}
		max_cnt[idx2] = max;
		min_cnt[idx2++] = min;
	}

	for(int i=0; i<idx2; i++){
		printf(" %d",max_cnt[i]);
	}
	printf("\n");
	for(int i=0; i<idx2; i++){
		printf(" %d",min_cnt[i]);
	}
	return 0;
}
```



### C_TEST 3-2.c
학생 N명의 1차 인증점수와 2차 인증점수를 입력받아 평균 점수와 등수, 학 점을 내림차순으로 정렬하여 출력하는 프로그램을 다음과 같이 작성 하시오.

(1) 정수 N을 입력받고, N명 학생의 1차 인증점수를 입력받아 배열에 저장하고, 다시 N명 학생의
2차 인증점수를 입력받아 배열에 저장한다. 단, N≤20이다.

(2) 학생의 평균 점수를 1차 인증점수의 40%와 2차 인증점수의 60%를 합산한 점수로 계산하여 배열에 저장한다.

(3) 평균 점수 순서대로 학생의 1차 인증점수, 2차 인증점수, 평균 점수를 내림차순으로 정렬한다. 1차 인증점수와 2차 인증점수도 평균 점수 기준으로 정렬해야 한다.

(4) 각 학생의 등수를 평균 점수를 기준으로 계산한다. 단, 동점인 학생의 등수는 같다. 같은 등수 의 학생이 여러 명이면, 없는 등수가 있을 수 있다. (입출력 예시1 참고)

(5) 다음과 같이 평균 점수를 기준으로 학점을 부여한다.
- N명의 학생 중 상위 30% 이내의 학생에게 A 학점을 부여한다. 예를 들어, 총 7명 중 30%는 2.1명이며, 이 경우 2명까지 A 학점을 받는다.
- 상위 70% 이내의 학생 중 A학점을 받지 못한 학생들에게 B학점을 부여한다. 예를 들어, 총 7명 중 70%는 4명(4.9명 이내)이며, 이 중 A학점을 부여받은 2명을 제외한 2명의 학생이 B 학점을 받는다.
- A학점과 B학점을 부여받지 못한 나머지 학생들에게 F학점을 부여한다.
- 단, 동점인 학생들은 인원수에 상관없이 같은 학점을 받는다. 예를 들어, 7명 중 2등인 동점 자 학생이 2명이라면, 1등 한 명과 2등 두 명, 모두 A학점을 받고, B학점을 받게 되는 학생 은 1명이 된다.
- 동점자가 다수인 경우, B학점 또는 F학점을 받는 학생이 없을 수도 있다.
- 평균 점수가 상위 70%에 들지 못하더라도, 2차 인증점수가 60점 이상인 경우 B학점을 부여 한다.

(6) 학생의 1차 인증점수, 2차 인증점수, 평균 점수, 등수, 학점을 출력한다. 평균 점수는 소수점
이하 첫째 자리까지 출력한다. 출력 순서는 평균 점수에 따라 내림차순으로 정렬된 순서이다.

<img width="828" alt="image" src="https://user-images.githubusercontent.com/99342700/179162859-176b65c3-ee3a-4853-955e-1fb5280c23df.png">

1. 필요한 변수 지정 및 크기에 맞추어 배열 값 저장.
2. 반복문을 이용하여 x배열의 40%와 y배열의 60%의 합을 구하기.
3. 배열의 합을 크기 비교하여 각 인덱스 위치에 맞게 새로운 배열에 순서 저장.
4. 저장한 순위의 순서대로 조건에 맞추어 새로운 배열에 등급 저장.
5. 배열의 합 순서에 맞추어 점수의 합 내림차순으로 정렬 후 출력.

```c++
#include <stdio.h>

int main(void){
	int N=0,cnt1=1,check=0; double temp=0;
	scanf("%d",&N);
	int x[N],y[N],z[N],cnt[N];
	double avg[N];
	for(int i=0; i<N; i++){
		scanf("%d",&x[i]);
	}
	for(int i=0; i<N; i++){
		scanf("%d",&y[i]);
	}
	for(int i=0;i<N; i++){
		avg[i] = (x[i]*0.4) + (y[i]*0.6);
	}
	for(int i=0;i<N; i++){
		for(int j=0; j<N; j++){
			if(avg[i] < avg[j]){
				cnt[i] = ++cnt1;
				check = 1;
			}
		}
		if(check == 0){
			cnt[i] = 1;
		}
		check=0;
		cnt1=1;
	}
	
	for(int i=0;i<N; i++){
		if(cnt[i] <= N*0.3){
			z[i] = 'A';
		}
		else if( (cnt[i] > N*0.3 && cnt[i] <= N*0.7) || y[i] >= 60 ){
			z[i] = 'B';
		}
		else{
			z[i] = 'F';
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<N-1; j++){
			if(cnt[j] > cnt[j+1]){
				temp = cnt[j];
				cnt[j] = cnt[j+1];
				cnt[j+1] = temp;
				temp = x[j];
				x[j] = x[j+1];
				x[j+1] = temp;
				temp = y[j];
				y[j] = y[j+1];
				y[j+1] = temp;
				temp = z[j];
				z[j] = z[j+1];
				z[j+1] = temp;
				temp = avg[j];
				avg[j] = avg[j+1];
				avg[j+1] = temp;
			}
		}
	}
	for(int i=0; i<N; i++){
		printf("%d %d %.1lf %d %c\n",x[i],y[i],avg[i],cnt[i],z[i]);
	}
	return 0;
}
```



### C_TEST 4-2.c
종료조건까지영어소문자또는대문자를반복해서입력받아,배열X에저 장하고, 정수 M(0≤M≤25)을 입력받는다.

(1) 배열 X에 저장된 문자 중 중복된 문자를 제외하고 배열 Y에 저장한 후, 배열 Y에 저장된 문자 를 출력한다. 배열 X에 중복되어 나타나는 문자의 경우, 처음 나타난 문자를 배열 Y에 저장한다.

(2) 배열 Y에 저장된 각 문자에 대해 대문자는 M만큼 증가된 소문자로 변환하고, 소문자는 M만큼 증가된 대문자로 변환하여 배열 Y에 저장한 후, 출력한다. 문자의 증가 중, 끝 문자 (‘z’ 혹은 ‘Z’)에 도달하면 처음 문자 (‘a’ 혹은 ‘A’)로 다시 돌아간다. 예를 들어, 대문자 ‘Y’를 4 만큼 증가 시키면, Y Z A B C 순서이므로, ‘C’가 되고, ‘C’를 소문자 변환한 ‘c’가 배열 Y에 저장된다.

(3) 배열 Y에 저장된 문자 중 소문자-대문자 또는 대문자-소문자가 교대로 나오는 부분 배열을 찾 는다. 이러한 부분 배열 중에서 가장 긴 부분 배열의 원소를 출력한다. 부분 배열 중에서 가장 긴 부분 배열의 크기를 가지는 부분 배열이 여러 개인 경우, 제일 처음 나온 부분 배열을 출력한다. (4) 만약 조건을 만족하는 부분 배열이 없으면 “none”을 출력한다.
- 종료 조건 : 문자 ‘!’ 입력 (문자 ‘!’는 배열에 저장하지 않는다.)
- ‘A’와 ‘a’처럼 동일한 문자의 대문자와 소문자는 서로 다른 문자로 간주한다. - 입력되는 문자의 최대 개수는 100이다.

<img width="502" alt="스크린샷 2022-07-17 오후 6 08 51" src="https://user-images.githubusercontent.com/99342700/179391703-7b3eda84-62a5-4ac3-bb2b-f6c1531368ca.png">

1. 필요한 변수 지정.
2. x배열에 저장한 문자열 중 중복된 부분을 제외한 문자열을 y배열에 저장 후 출력.
    - j for문 부터 0까지 자기자신만 같은 경우 저장.
3. 입력받은 M만큼 알파벳 이동 및 대/소문자 변경 후 출력.
    - z(Z)를 넘어가는 경우 알파벳의 아스키코드 차이 만큼인 26을 빼기.
    - 대문자인 경우 아스키코드 값을 적용하여 32를 더해서 소문자로 만들기.
    - 소문자인 경우 반대로 32를 빼서 대문자로 만들기.
4. 대/소문자가 교차로 나오는 경우 새로운 배열에 저장하고 가장 긴 문자열 출력.
    - 아닌 경우를 기준으로 새로운 변수에 크기를 비교하여 가장 긴 문자열 구하기.
5. 대/소문자 교차가 없는 경우 "none" 출력.

```c++
#include <stdio.h>

int main(void){
	int idx=0,idx2=0,idx3=0,temp=0,M=0,cnt=0,cnt2=0,max=0,check=0,cnt3=0;
	char x[100],y[100],z[100],q[100]; char ch;
	while(1){
		scanf("%c",&ch);
		if(ch == '!')break;
		x[idx++] = ch;
	}

	scanf("%d",&M);

	for(int i=0; i<idx; i++){
		for(int j=i; j>=0; j--){
			if(x[i] == x[j]){
				cnt++;
			}
		}
		if(cnt == 1){
			y[idx2++] = x[i];
		}
		cnt = 0;
	} // 반복제거 for

	for(int i=0; i<idx2; i++){
		printf("%c",y[i]);
	}
	printf("\n");

	for(int i=0; i<idx2; i++){
		if(y[i] >= 'A' && y[i] <= 'Z'){
			temp = y[i] + 32 + M;
			if(temp > 'z'){
				y[i] = temp - 26;
			}
			else{
				y[i] = temp;
			}
		}
		else if(y[i] >= 'a' && y[i] <= 'z'){
			temp = y[i] - 32 + M;
			if(temp > 'Z'){
				y[i] = temp - 26;
			}
			else{
				y[i] = temp;
			}
		}
	} // 대소문자 변경 후 M만큼 이동 for

	for(int i=0; i<idx2; i++){
		printf("%c",y[i]);
	}
	printf("\n");

	for(int i=0; i<idx2; i++){
		if( (y[i] >= 'A' && y[i] <= 'Z') && (y[i+1] >= 'a' && y[i+1] <= 'z') ){
			z[idx3] = y[i];
			z[idx3+1] = y[i+1];
			idx3++;
			cnt2++;
			check = 1;
		}
		else if( (y[i] >= 'a' && y[i] <= 'z') && (y[i+1] >= 'A' && y[i+1] <= 'Z') ){
			z[idx3] = y[i];
			z[idx3+1] = y[i+1];
			idx3++;
			cnt2++;
			check = 1;
		}
		else{
			if(max < cnt2){
				max = cnt2;
				for(int i=0; i<idx3+1; i++){
					q[i] = z[i];
					cnt3 = i;
				}
			}
			idx3 = 0;
			cnt2=0;
		}
	}
	if(check == 1){
		for(int i=0; i<cnt3+1; i++){
			printf("%c",q[i]);
		}
	}
	else{
		printf("\nnone");
	}
	return 0;
}
```



### C_TEST 5-2.c
회문수(palindromic number)는 순서대로 읽은 수와 거꾸로 읽은 수가 일치 하는 수를 말한다. 즉, 회문수는 대칭인 수를 의미하며, 예를 들어 34543은 회문수이고, 34567은 회문수가 아니다.

(1) 양의 정수 N과 삭제할 자릿수를 나타내는 정수 T를 입력받는다. N은 최대 9자리 정수이고, T 는 (N의 전체 자릿수)/2 보다 작거나 같다. 즉, N이 7자리 정수일 경우, T는 1, 2 또는 3이다.

(2) reverse_num 함수를 호출하여, N의 각 자릿수를 역순으로 하여 만든 정수를 반환받고, is_palindromic 함수를 호출하여, N이 회문수인지 판단한다.

(3) del_digit 함수를 호출하여, N이 회문수이면, N에서 오른쪽으로부터 T번째 자릿수와 T와 대칭 되는 곳에 위치한 자릿수를 삭제한 정수를, N이 회문수가 아니면, N에서 오른쪽으로부터 T번째 자릿수만 삭제된 정수를 반환받는다. 여기서 자릿수는 정수의 오른쪽부터 센다. 즉, 일의 자리가 1 번째 자리, 십의 자리가 2번째 자리, ... 이다.
예시 1) N=34543, T=1이면, 1번째와 5번째 자리의 숫자 3을 모두 삭제한 454를 반환 예시 2) N=345543, T=3이면, 3번째와 4번째 자리의 숫자 5를 모두 삭제한 3443을 반환 예시 3) N=34567, T=1이면, 1번째 자리의 숫자 7을 삭제한 3456을 반환

(4) 정수 N과 N을 거꾸로 읽은 수 M, 그리고 N이 회문수 인지 여부를 나타내는 1 또는 0(N이 회 문수이면 1, 회문수가 아니면 0)과 N에서 T번째 자릿수(N이 회문수이면, T와 대칭되는 곳의 자릿수도 포함)를 삭제한 수를 차례로 main 함수에서 화면에 출력한다.

(5) main 함수 위에 함수원형선언을 하고, 함수의 정의는 main함수 아래에 오도록 작성 한다.

- reverse_num 함수
◦ 함수 원형 : int reverse_num(int N)
◦ 인자 : 정수 N
◦ 반환 값 : 정수 N의 각 자릿수의 숫자를 역순으로 하여 만든 정수를 반환
- is_palindromic 함수
◦ 함수 원형 : int is_palindromic(int N)
◦ 인자 : 정수 N
◦ 반환값 : N이 회문수이면 1을, 그렇지 않으면 0을 반환
◦ N의 회문 여부를 판단하기 위해, reverse_num 함수를 호출하여 사용한다.
- del_digit 함수
◦ 함수 원형 : int del_digit(int N, int T)
◦ 인자 : 정수 N과 T
◦ 반환값 : N이 회문수이면, N의 T번째 자릿수와 T번째 자리와 대칭되는 자릿수를 삭제한
수를, N이 회문수가 아니면, N의 T번째 자릿수만 삭제한 수를 반환한다.
◦ N의 회문 여부를 판단하기 위해 is_palindromic 함수를 호출하여 사용한다.

<img width="864" alt="스크린샷 2022-07-18 오전 1 15 35" src="https://user-images.githubusercontent.com/99342700/179411040-4fa8a4ba-f88c-43cd-af58-ed08f40fa34a.png">

1. 함수 원형 선인 및 변수 지정.
2. 입력 받은 값 출력 및 역수로 만들어주는 함수 지정 후 출력.
    - 역수 공식 이용.
3. 회문수인지 판단.
    - 뒤집은 값이 N과 같으면 1 반환 아니면 0 반환.
4. 회문수인 경우 앞 뒤로 T의 자릿수 삭제.
    - T의 자릿수일 때 계산 건너뛰기.
5. 회문수가 아닌경우 뒤만 부터 T의 자릿수 삭제.
    - 해당 공식 암기.
6. 회문수인지 판단 및 자릿수를 제거한 값 출력.

```c++
#include <stdio.h>

int reverse_num(int N);
int is_palindromic(int N);
int del_digit(int N,int T);

int main(void){
	int N=0,T=0,re=0,num=0;
	scanf("%d",&N);
	scanf("%d",&T);

	printf("%d ",N);

	re = reverse_num(N);

	printf("%d ",re);

	printf("%d ",is_palindromic(N));

	printf("%d ",del_digit(N,T));

	return 0;
}

int reverse_num(int N){
	int re=0;
	for(int i=N; i>0; i=i/10){
		re = re * 10;
		re = re + i % 10;
	}
	//printf("%d",re);
	return re;
}

int is_palindromic(int N){
	int re=0;
	re = reverse_num(N);
	if(re == N){
		return 1;
	}
	else{
		return 0;
	}
}

int del_digit(int N,int T){
	int temp=N,cnt=0;
	while(temp){
		temp = temp / 10;
		cnt++;
	}
	if(is_palindromic(N) == 1){
		for(int i=0; i<cnt; i++){
			if(i+1 == T){
				N = N /10;
			}                           
			else if(cnt-i == T){
				N = N /10;
			}
			else{
				temp = temp * 10;
				temp = temp + N % 10;
				N = N /10;
			}
		}	
	}
	else{
		for(int i=cnt; i>0; i--){
        	int pow=10; // 10설정  
            	if(i-1 == 0)pow=1; 
            	for(int j=1; j<i-1; j++)
                	pow = pow * 10;
             	// 제곱 계산
			if(i != T){ 
            	temp = temp * 10;
				temp = temp + (N/pow)%10;     
			} // 타겟 제외 추가
		}
	}
	return temp;
}

for(int i=cnt; i>0; i--){
    int pow = 10;
    if(i-1 == 0)pow = 1;
    for(int j=1; j<j-1; j++){
        pow = pow * 10;
    }
    if(i != T){
        temp = temp * 10;
        temp = temp + (N/pow)%10;
    }
}
```