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