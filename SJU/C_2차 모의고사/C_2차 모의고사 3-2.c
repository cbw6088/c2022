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
