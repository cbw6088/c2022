#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
   char *name;
   int kor, prime;
}stu;

void prime(stu *p);

int main(){
   int N;
   char tmp[100] = {};
   scanf("%d", &N);
   stu *p = (stu*)malloc(sizeof(stu) * N);
   if(p == NULL) return -1;

   for(int i = 0; i < N; i++){
      scanf("%s", tmp);
      (p+i)->name = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
      if((p+i)->name == NULL) return -1;
      strcpy((p+i)->name, tmp);
      scanf("%d", &(p+i)->kor);
   }

   for(int i = 0 ; i < N; i++)
      prime(p+i);

   for(int i = 0; i < N; i++){
      if((p+i)->prime == 1)
         printf("%s %d\n", (p+i)->name, (p+i)->kor);
   }

   for(int i = 0 ; i < N; i++)
      free((p+i)->name);
   free(p);
   return 0;
}

void prime(stu *p){
   int cnt = 0, idx = 0;
   p->prime = 1;
   for(int i = 2; i < p->kor; i++){
      if(p->kor % i == 0)
         p->prime = 0;
   }
}

/*
5
jacob 31
kim 41
lee 51
park 61
jane 71
*/