#include <stdio.h>
int main(void)
{
  int N=0; int M=0; int cnt=0; int max=0; int answer=0;
  scanf("%d %d",&N,&M);
  if( ( N < 1 || N > 1000 ) || ( M < 1 || M > 1000 ) ){return -1;}
      for(int i=N; i<=M; i++){ 
        for(int j=2; j<=i; j++){ 
          if(i%j==0){
           cnt++;
          }
          if(max<cnt){ 
          max=cnt;
          answer=i; 
          }
        } 
         cnt=0;
      }    
       printf("%d %d ",answer,max+1);
      int f=2; int exp=0;
      while(answer>1){
        if(answer%f==0){
          exp++;
          answer=answer/f; 
        } 
        else{ 
          f++;
          if(answer%f==0){
            exp++;
            answer=answer/f;
          }
        } 
      } 
      printf("%d",exp); 
  return 0;
}