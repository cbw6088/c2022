#include <stdio.h>
int main(void)
{
  int N=0; int M=0; int num=0; int cnt=0,min=0,max=0;
  scanf("%d",&N);

  while(1){
	  scanf("%d",&M);
	  if(M == 0){break;}

	  for(int i=M; i>0; i=i/10){
		  num = i%10;
		  if(num == N){
			  cnt++;
		  }
		  else if(num > N){
			  max++;
		  }
		  else{
			  min++;
		  }
	  }	  
  }
  printf("%d %d %d",cnt,min,max);
  return 0;
}