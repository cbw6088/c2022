#include <stdio.h>
int main(void){
int N=0;

while(1){
  	scanf("%d",&N);
  	if(N <= 1 || N%3 == 0){return -1;}
  	for(int i=0; i<N; i++){
	  	for(int j=0; j<N*2-1; j++){
		  	if(i+j < N-1){
				  printf(" ");
		  	}
		  	else if(j-i > N-1){
				  printf(" ");
		  	}
		  	else if(i+j == N-1){
				  printf("O");
		  	}
		  	else if(j-i == N-1){
				  printf("O");
		 	}
		  	else if(i == N-1){
				  printf("O");
		  	}
		  	else if(i+j >= N){
				  printf("X");
		  	}
	 	}
	  	printf("\n");
  	}
  }	  
  return 0;
}