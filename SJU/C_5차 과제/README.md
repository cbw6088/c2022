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
3. 

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
