#include <stdio.h>

int main(void){
    int A[101],B[101],C[101],D[101],E[202],F[101],G[101];
	int idx=0,idx2=0,idx3=0,idx4=0,idx5=0,cnt=0,num1=0,num2=0,add=0,min=99999999,n=0,temp=0;

	while(1){
		scanf("%d",&temp);
		if(temp < 0){break;}
		A[num1++] = temp;
	} 
	
	while(1){
		scanf("%d",&temp);
		if(temp < 0){break;}
		B[num2++] = temp;
	}

	for(int i=0; i<num1; i++){
		for(int j=i; j>=0; j--){
			if(A[i] == A[j]){
				cnt++;
			}
		}
		if(cnt==1){
			C[idx++] = A[i]; 
		}
		cnt=0;
	}
	cnt=0;
	for(int i=0; i<num2; i++){
		for(int j=i; j>=0; j--){
			if(B[i]==B[j]){
				cnt++;
			}
		}
		if(cnt==1){
			D[idx2++] = B[i];
		}
		cnt=0;
	}
	cnt=0;

	add = idx + idx2;

	for(int i=0; i<idx; i++){
		E[idx3++] = C[i]; 
	}

	for(int i=0; i<idx2; i++){
		E[idx3++] = D[i];
	}

	for(int i=0; i<add; i++){
		for(int j=i; j>=0; j--){
			if(E[i] == E[j]){
				cnt++;
			}
		}
		if(cnt == 1){
			F[idx4++] = E[i];
		}
		cnt=0;
	}

	for(int i=0; i<idx4; i++){
		for(int j=0; j<idx4-1; j++){
			if(F[j] > F[j+1]){
				min = F[j];
				F[j] = F[j+1];
				F[j+1] = min;
			}
		}
	}

	for(int i=0; i<idx4; i++){
		printf("%d ",F[i]);
	}


	return 0;
}

// 2 4 6 7 8 1 2 3 4 -1
// 1 2 3 4 2 4 6 7 8 -1 