#include <stdio.h>
#include <string.h>

void sort(int N, int id[], double avg[]);

int main(){
   int N;
   scanf("%d",&N);
   int A[N],B[N],C[N];
   double avg[N];
   int *p1 = A, *p2 = B, *p3 = C;
   double *p4 = avg;
   for(; p1<A+N; p1++){
      scanf("%d %d %d",p1,p2,p3);
      p2++;
      p3++;
   }


   p1 = A;
   p2 = B;
   p3 = C;
   for(int i=0; i<N; i++){
      *(p4+i) = (double)(*p2 + *p3)/2;
      p2++;
      p3++;
   }
   p4 = avg;
   sort(N,p1,avg);
   
   return 0;
}

void sort(int N, int id[], double avg[]){
   int *p1 = id;
   int cnt=0,cnt2=0,check=0;
   int tmp;
   double *q1 = avg;
   for(; q1<avg+N-1; q1++){
      	for(double *q2=q1+1; q2<avg+N; q2++){
        	if(*q2 > *q1){
            	tmp = *q2;
            	*q2 = *q1;
            	*q1 = tmp;

            	tmp = *(p1+cnt2+1);
				*(p1+cnt2+1) = *p1;
				*p1 = tmp;
        	}
			cnt2++;
    	}
		cnt2=0;
    	p1++;
   }
   p1 = id;
   q1 = avg;
   for(; p1<id+N; p1++){
      printf("%d %.1lf\n",*p1,*q1);
      q1++;
   }
}