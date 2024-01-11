#include <stdio.h>
int main(void)
{
  int N=0; int num=0; int even=0,odd=0;
  scanf("%d",&N);

  for(int i=N; i>0; i=i/10){
	  num = i % 10;
	  if(num%2 == 0){
		  even = even * 10;
		  even = even + num;
	  }
	  else if(num%2 != 0){
		  odd = odd * 10;
		  odd = odd + num;
	  }
  }
  printf("%d %d",even,odd);
  return 0;
}