# C_Programming 5차 과제

### C_과제1.c
입출금한 금액에 대해 계좌 거래내역 및 잔액을 출력 예시와 같이 출력하는 프로그램을 작성하시오.
- 총 입출금 횟수 N 과 이자 M (%) 을 맨 처음 입력한다 (N과 M은 양의 정수).
- 입금은 양의정수, 인출은 음의정수를 입력하며, 최초 잔액은 0이라 가정한다.
- 이자는 입금한 경우에 대해서만 즉시 발생한다. 예) M=5 일 때, 100 입금 -> 계좌잔액: 105.00
- 입력값 등을 넘겨받아 입금값 출금값을 화면에 출력하고 잔액을 반환하는 함수를 구현 한다.
- 출금액이 잔액보다 많을 경우, 남은 잔액만큼만 출금 되며, 이 경우 출금값은 소수점 둘째자리까
지 출력한다. (입출력 예시 2 참고)
- 잔액은 항상 소수점 둘째자리까지 출력한다.
- main 함수 위에 함수원형선언을 하고, 함수 본체를 main 함수 아래에 작성 하시오.
- Cal 함수
◦ 함수 원형: double Cal(int cash, int inter, double balance)
◦ 인자: 정수형 금액 cash, 정수형 이자 inter, double형 부동소수형 잔액 balance
◦ 입력값, 이자, 잔액을 넘겨받아 입금값 출금값을 화면에 출력하는 함수를 구현하여 활용한 다. (잔액은 main 함수에서 화면에 출력한다)
◦ 반환 값 : 잔액을 반환한다.

<img width="822" alt="image" src="https://user-images.githubusercontent.com/99342700/179680441-bd036648-8838-4077-9f5f-db9372b17521.png">
<img width="822" alt="image" src="https://user-images.githubusercontent.com/99342700/179680552-d8bd1a45-d098-47ec-be0b-c7ea3898a8a4.png">

1. 함수원형 및 필요한 변수 선언.
2. 입력 금액이 양수인 경우 입력한 값의 수수료만큼 더하기.
3. 입력 금액이 음수인 경우 잔돈이 0이 아니면 플래그 표시 후 차감된 값만큼 연산.
4. 연산한 금액이 음수가 되는 경우 출력값에 음수가 나오면 안되므로 임시값에 저장 후 0으로 저장.
5. 함수 출력.
    - 양수인 경우 그대로 출력.
    - 음수인 경우 플래그가 0이면 입력받은 값을 0으로 만든 후 출력하고 잔돈 반환.
    - 플래그가 1인 경우 잔액이 0이면 입력값 초기화 후 출력 및 잔돈 반환.
    - 잔액이 양수인 경우 출금값에서 양수를 뺀 후 저장 및 출력, 잔돈 반환.

```c++
#include <stdio.h>
double Cal(int cash,int inter,double balance); // 원형 함수 지정.

double temp,balance; // 전역 변수 지정.
int flag;
int cash,inter;

int main(void){
	int N=0,M=0; // 입력 받은 변수 지정.
	scanf("%d %d",&N,&M); // N,M을 입력 받기.

	for(int i=0; i<N; i++){ // 입력 받은 N까지 반복.
		flag = 0;
		scanf("%d",&cash); // 입금 할 금액 입력.
		if(cash >= 0){ // 입력값이 양수인 경우
			balance = (balance + cash) + ( (balance + cash) * (0.01 * M) ); // 잔액에 수수료 M%만큼 증가.
		}	
		else if(cash < 0){ // 입력값이 음수인 경우.

			if(balance>0){ // 남은 잔액이 양수인 경우.
			flag = 1; // 플래그에 1을 넣어 표시.
			double compare = balance + cash; // 실수형 변수에 잔액과 현재 금액을 더하기.
			if(compare <=0){ // 그 값이 0이하인 경우.
				temp = balance; // 템프값에 남은 잔액 저장.
				balance = 0; // 남은 잔액 0 저장.
			}
			else balance = compare; // 양수인 경우 잔액에 입력한 금액을 더한 값 저장.
			}
		}
		printf("%.2lf\n",Cal(cash,inter,balance)); // 함수 값 출력.
	}
	return 0;
}

double Cal(int cash,int inter,double balance){
	if(cash >= 0){ // 입력받은 값이 양수인 경우
		printf("%d %d ",cash,inter); // 그대로 출력.
	}

	else{ // 입력받은 값이 음수인 경우
		if(flag==0){ // 플래그가 0인 경우.
		cash = 0; // 입력받은 값 초기화.
		printf("%d %d ",cash,inter); //출력.
		return balance; // 잔액 반환.
		}
		
		if(balance == 0){ // 잔액이 0원인 경우.
			cash = 0; // 입력받은 값 초기화.
			printf("%d %.2lf ",cash,temp); //출력.
			return balance; // 잔액 반환.
		}

		else{ // 잔액이 양수인 경우.
			inter = inter - cash; //출금 값에 양수를 뺀 값 저장.
		}
		cash = 0; // 입금액 0 고정
		printf("%d %d ",cash,inter); // 출력.
	}
	return balance; // 잔액 반환.
}
```



### C_과제 2-2.c
0이 입력될 때까지 양의정수 N개를 입력받아 배열 A에 저장하고, 두 개의 정수 S와 E를 T개 입력받아 [문제1-1]의 과정을 T번 반복하는 프로그램을 작성하시오. 또한, 각 반 복에서 주어진 배열에서 최대값과 최소값을 구하는 함수 max_num, min_num 함수를 [문제 2-1]에 서 주어진 정의를 사용하여 작성하시오.

<img width="803" alt="스크린샷 2022-07-20 오후 3 52 26" src="https://user-images.githubusercontent.com/99342700/179916381-186daa6b-23f9-4ef1-9119-07b881f4aa0d.png">

1. 원형함수 및 변수 지정.
2. for문을 이용하여 입력받은 S와E의 인덱스에 있는 값을 교환.
3. 교환한 값 중 최대 최소를 함수를 이용하여 구하기.
4. 인덱스를 교환한 배열과 최대/최소값 출력.

```c++
#include <stdio.h>

int max_num(int N1,int N2);
int min_num(int N1,int N2);

int main(void){
	int N=0,idx=0,S=0,E=0,T=0,cnt=0,temp=0;
	int A[100],B[100];
	int temp_max, temp_min;
	while(1){
		scanf("%d",&N);
		if(N == 0)break;
		A[idx++] = N;
	}
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		int max=0,min=1000000000;
		scanf("%d %d",&S,&E);
		cnt = E - S;
		cnt = cnt / 2;

		for(int i=0; i<=cnt; i++){
			temp = A[S+i];
			A[S+i] = A[E-i];
			A[E-i] = temp;
			temp_max = max_num(A[S+i],A[E-i]);
			temp_min = min_num(A[S+i],A[E-i]);
			if(max <= temp_max){max = temp_max;}
			if(min >= temp_min){min = temp_min;}
		}

		for(int i=0; i<idx; i++){
			printf("%d ",A[i]);
		}
		printf("\n%d %d\n",max,min);
	}
	return 0;
}

int max_num(int N1,int N2){
	if(N1 >= N2){
		return N1;
	}
	else{
		return N2;
	}
}

int min_num(int N1, int N2){
	if(N1 <= N2){
		return N1;
	}
	else{
		return N2;
	}
}
```



### C_과제 3.c
세 정수 N, M, K를 입력받아 N부터 M까지의 수중에서 

(1) K의 배수 이면, 해당 수의 각 자릿수 중 최대값을 구하고

(2) K의 배수가 아니면, K로 나눈 나머지 중에서 최대값을 구한 후

(1) 과 (2) 중에서 제일 큰 수를 출력하시오.

-multiple, maximum, digit_maximum 세 개의 함수를 사용하여 작성하시오. 1 < N < M < 1000 이고, 1 < K < 1000 이다.
- multiple 함수의 정의 및 사용
◦ 인자: 정수 x와 정수 y
◦ 반환형: int
◦ 반환값: 정수 x가 정수 y의 배수이면 1, 아니면 0을 return
- maximum 함수의 정의 및 사용
◦ 인자: 정수 x와 정수 y
◦ 반환형: int
◦ 반환값: 정수 x와 정수 y 중 큰 수를 return
- digit_maximum 함수의 정의 및 사용
◦ 인자는 정수 x
◦ 반환형: int
◦ 반환값: 정수 x의 각 자릿수를 계산하고 maximum 함수를 이용하여 그 중 가장 큰 수를
계산하고 return

<img width="780" alt="스크린샷 2022-07-23 오후 8 05 55" src="https://user-images.githubusercontent.com/99342700/180602507-4d5a298b-dc34-49bf-885e-f3ddd0ee6a4f.png">
<img width="778" alt="스크린샷 2022-07-23 오후 8 06 22" src="https://user-images.githubusercontent.com/99342700/180602506-52a1f3c8-397d-4b1a-bec3-0e0ec315e3ae.png">

1. 원형함수 및 변수 지정.
2. 입력받은 N부터 M의 값이 K의 배수인지 알아보는 함수 설정.
3. 배수일 시 더 큰 값을 반환해주는 함수를 각 자릿수 중 가장 큰 값을 저장하는 함수에 저장.
4. 배수가 아닐 시 K로 나눈 값 중 나머지가 가장 큰 값을 MAX값에 저장.
5. 출력할 때 가장 큰 값을 비교하는 맥시멈 함수를 이용하여 출력.

```c++
#include <stdio.h>

int multiple(int x,int y);
int maximum(int x,int y);
int digit_maximum(int x);

int main(void){
	int N=0,M=0,K=0,idx=0,max=0,temp=0,MAX=0,digit_max=0;
	int X[100];
	scanf("%d %d %d",&N,&M,&K);

	for(int i=N; i<=M; i++){
		if(multiple(i,K) == 1){
			temp = digit_maximum(i);
			digit_max = maximum(digit_max,temp);
		}
		else{
			temp = i % K;
			MAX = maximum(MAX,temp);
		}
	}

	printf("%d",maximum(digit_max,MAX));
	return 0;
}

int multiple(int x,int y){
	return x%y==0;
}

int maximum(int x,int y){
	return x<=y ? y : x;
}

int digit_maximum(int x){
	int max=0,temp=0;
	for(int j=x; j>0; j=j/10){
		temp = j % 10;
		max = maximum(max,temp);
	}
	return max;
}
```



### C_과제 4-2.c
양의 정수 N과 N개의 양의 정수를 입력받아 연속적으로 소수가 나온 최대 횟수를 카운트하고 그 구간의 마지막 소수를 출력 하는 프로그램을 count_prime_number() 함수와 is_prime_number() 함수를 이용하여 작성하시오. 단, 100 이상인 수는 연속적인 소수 횟수의 카운 트에서 제외 한다(소수로 생각하지 않음). 입력된 정수 중 소수가 하나도 없으면 0을 출력한다. 소 수연속구간 최대 회수를 출력하고, 다음 줄에 그 구간의 소수들 중 가장 마지막 소수를 출력한다.
- count_prime_number 함수
◦ 함수 원형: int count_prime_number(int cnt, int num)
◦ 연속된 소수의 개수를 세는 cnt 값과 양의 정수 num을 전달 받아, num이 소수이면,cnt+1한 값을 반환하고, num이 소수가 아니거나 100이상의 정수이면, 0을 반환한다. 
◦ num 값이 소수인지 확인하기 위해 is_prime_number() 함수를 호출한다.
- is_prime_number 함수
◦ 함수 원형: int is_prime_number(int num)
◦ 양의 정수 num이 소수이면 1을 반환하고, 소수가 아니면 0을 반환한다.
- 소수가 6번 연속 나온 구간이 제일 길면 6을 출력한다. (입력 예시 1)
- 입력 중간에 100이상의 소수가 나와도 100이상의 수이므로 소수 구간은 새로 시작해야한다.
(입력 예시 2)
- 한 번도 소수가 없었다면 0을 출력한다. (입력 예시 3)
- 최대 길이가 같은 구간이 있으면 제일 처음 나온 구간의 정보를 출력한다.

<img width="818" alt="image" src="https://user-images.githubusercontent.com/99342700/180651162-30ee32e7-908b-4408-b70b-ce1a1787683e.png">

1. 함수원형 및 필요한 변수 선언.
2. 배열 A에 N번 만큼 반복 입력.
3. for문을 이용하여 만약 count_prime_number함수가 참일 경우 카운트 길이 1개 증가와 임의의 값에 마지막 소수 저장.
    - 값이 100 이상이거나 소수면 0 반환 그게 아니면 카운트 한개 증가.
    - 소수는 새로운 함수를 만들어서 1부터 자기자신 전까지 나누어보고 카운트가 2 이상이면 0반환 그게 아니면 카운트 반환.
4. count_prime_number함수가 참이 아닐 경우 맥스값을 비교하여 가장 길이가 긴 연속된 구간 구하고 마지막 소수 갱신.
5. 만약 맥스값이 0이면 0출력 그게 아니면 가장 긴 구간의 길이와 그 구간에서 마지막 소수 출력.

```c++
#include <stdio.h>

int is_prime_number(int num);
int count_prime_number(int cnt, int num);

int main(){
    // freopen("input2.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    int A[N];
    
    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);

    int prime = 0;
    int temp = 0;
    int cnt = 0;
    int max_len = 0;

    for(int i=0; i<=N; i++){
        if(count_prime_number(cnt,A[i])!=0){
            cnt = count_prime_number(cnt,A[i]); // 길이 1개 증가
            temp = A[i]; // 마지막 소수 기억
        }// 소수인 경우
        else{
            if(max_len< cnt){ // 이전 소수의 연속 길이보다 현재 소수의 길이가 더 길면
                max_len = cnt; // 길이 갱신
                prime = temp; // 소수 갱신
                cnt = 0;
            }
            else {cnt = 0;}
        }//소수가 아니거나 100이상
    }
    if(max_len == 0){ printf("%d\n", max_len) ;}
    else
        printf("%d\n%d\n", max_len, prime);
    
    return 0;
}

int is_prime_number(int num){
    int cnt = 0;
        for(int i=1; i<num; i++){
            if(num%i == 0)
                cnt++;
            if(cnt>=2){
                return 0;
            }
        } //for
    return cnt;
}
int count_prime_number(int cnt, int num){
    return (num >=100 || is_prime_number(num)==0)?0:++cnt;
    // 만약 100이상이거나 소수라면 0을 반환하고 그게 아니면 카운터+1 리턴
}
```



### C_과제 5-3.c
종료 조건 시까지 0 혹은 양의 정수 N을 반복해서 입력 받아, 입력받은 정 수 중 디지털근의 값이 가장 작은 정수와 해당 정수의 디지털근의 값을 출력하는 프로그램을 위 문제에서 정의된 add_digits 함수를 이용하여 작성하시오.
- 종료 조건 : 음수 입력 (단, 첫 번째 입력된 정수는 음수가 아니라고 가정한다.)

<img width="662" alt="image" src="https://user-images.githubusercontent.com/99342700/180700325-9c8e11a2-9e52-410a-a847-9d046ad64c22.png">

1. define을 사용하여 고정 사이즈 지정.(따로 변수에 지정해도 무방)
2. 원형함수 및 필요한 변수 선언.
3. 음수가 나오기 전까지 반복하여 임의의 값에 디지털근 저장.
	- N이 음수가 되기 전까지 각 자릿수의 합을 모두 더하고 다 더한 값이 10이 넘으면 함수 한번 더 호출 그게 아니면 더한값 반환.
4. 임의의 값에 저장한 디지털근을 최소값과 비교하여 저장.
5. 디지털근 구하기 전 초기 정수와 디지털근 출력.

```c++
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
```