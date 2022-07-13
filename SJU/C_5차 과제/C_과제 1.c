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


