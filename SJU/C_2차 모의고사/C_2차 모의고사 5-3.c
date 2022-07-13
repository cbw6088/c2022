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
