#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct car{
   char num[5];
   int hour, min, payment;
}Car;

int main(){
   int N;
   scanf("%d", &N);
   Car *p = (Car*)malloc(sizeof(Car) * N);
   if(p == NULL) return -1;
   for(int i = 0; i < N; i++)
      scanf("%s %d", p[i].num, &p[i].hour);
   
   for(int i = 0; i < N - 1; i++){
      for(int j = i + 1; j < N; j++){
         if(strcmp(p[i].num, p[j].num) == 0){
            p[i].min = (p[j].hour - '0') - (p[i].hour - '0') - 40;
            p[i].payment = p[i].min * 100;
            printf("%s %d\n", p[i].num, p[i].payment);
         }
      }
   }

   
   return 0;
}

/*
5
1234 1030
9000 1040
0800 1045
1234 1130
9000 1150
*/