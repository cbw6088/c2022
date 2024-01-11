#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
   int N, cnt = 1;
   scanf("%d", &N);
   char **p = (char**)malloc(sizeof(char*) * N);
   if(p == NULL) return -1;
   for(int i = 0; i < N; i++){
      p[i] = (char*)malloc(sizeof(char) * 101);
      if(p[i] == NULL) return -1;
      scanf("%s", p[i]);
   }

   for(int i = 0; i < N - 1; i++){
      for(int j = i + 1; j < N; j++){
         if(strcmp(p[i], p[j]) == 0){
            cnt++;
            p[j] = "!";
         }
      }
      if(cnt > 1 && p[i] != "!")
         printf("%s %d\n", p[i], cnt);
      cnt = 1;
   }

   for(int i = 0; i < N; i++)
      free(p[i]);
   free(p);
   return 0;
}

/*
6
lion
cat
tiger
lion
cat
lion
*/