#include <stdio.h>

int main(void){
    int arr[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; 
	int X[20] = {0};
	int F=0,R=0,M=0,N=0,next=0,idx=0,cnt=0; 
	scanf("%d %d %d",&F,&R,&M); 

	N = R - M + 1;
	next = R;

	for(int i=N; i<=R; i++){
		X[idx++] = arr[i]; 
		cnt++; 
	}
	idx = cnt-1;

	for(int i=N; i<=R; i++){
		arr[i] = X[idx++]; 
		if(idx == cnt){
			idx = 0;
		}
	}

	for(int i=0; i<20; i++){ 
		printf("%d ",arr[i]);
	}

    return 0;
}