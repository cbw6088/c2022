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