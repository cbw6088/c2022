#include <stdio.h>
double Cal(int cash,int inter,double balance);
double change=0,temp=0;

int main(void){
	// freopen("input.txt","r",stdin);
	
	int N=0,M=0,plus=0,minus=0,money=0;
	scanf("%d %d",&N,&M);

	for(int i=0; i<N; i++){
		scanf("%d",&plus);
		if(plus > 0){ // 입력값이 양수인 경우
			change = change + plus; // 잔액 = 전역 변수 + 입력값
			change = change + (change * (0.01 * M));	// 잔액 = 잔액 + 수수려
		}	
		else if(plus < 0){ // 입력값이 음수인 경우
			temp = plus; // 임의의 값에 음수 저장.
			double compare = change + temp;
			if(compare <=0){ 
				temp = change;
				change =0;
			}
			else change = compare;
		}
		Cal(plus,minus,money);
		printf("%.2lf\n",change);
	}
	return 0;
}

double Cal(int cash,int inter,double balance){
	if(cash >= 0){ // 입력받은 값이 양수인 경우
		printf("%d %d ",cash,inter);
	}

	else if(cash < 0){ // 입력받은 값이 음수인 경우
		
		if(change > 0){
			inter = inter - cash; // 출금액 = 출금액 - 음수
		}
		else if(change <= 0){
			inter = temp;
			cash = 0;
			printf("%d %.2lf ",cash,temp);
			return change;
		}
		cash = 0; // 입금액 0 고정
		printf("%d %d ",cash,inter);
	}
	return change;
}


