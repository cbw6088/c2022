#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
   int N, M1, M2;
   scanf("%d %d %d", &N, &M1, &M2);
   getchar();
   char str1[20][101] = {}, str2[20][101] = {}, str3[20][101] = {};
   for(int i = 0; i < N; i++)
      gets(str1[i]);

   char tmp[101] = {};
   for(int i = 0; i < N - 1; i++){
      for(int j = 0; j < N - 1 - i; j++){
         if(strlen(str1[j]) < strlen(str1[j+1])){
            strcpy(tmp, str1[j]);
            strcpy(str1[j], str1[j+1]);
            strcpy(str1[j+1], tmp);
         }
      }
   }
   printf("%s\n", str1[0]);
   printf("%s\n", str1[N-1]);

   char *p = str1[0];
   int idx1 = 0, len1 = strlen(str1[0]) + 1;
   for(int i = 0; i < len1; i++){
      if(str1[0][i] == ' ' || str1[0][i] == '\0'){
         str1[0][i] = '\0';
         strcpy(str2[idx1++], p);
         p = p + strlen(p) + 1;
      }
   }
   char *q = str1[N-1];
   int idx2 = 0, len2 = strlen(str1[N-1]) + 1;
   for(int i = 0; i < len2; i++){
      if(str1[N-1][i] == ' ' || str1[N-1][i] == '\0'){
         str1[N-1][i] = '\0';
         strcpy(str3[idx2++], q);
         q = q + strlen(q) + 1;
      }
   }
   char result[101] = {};
   if(strcmp(str2[M1], str3[M2]) < 0){
      strcpy(result, str2[M1]);
      strcat(result, str3[M2]);
   }
   else{
      strcpy(result, str3[M2]);
      strcat(result, str2[M1]);
   }
  
   printf("%s", result);
   return 0;
}

/*
5 4 2
book desk pencil paper
orange apple banana lemon grape
red yellow green orange blue white black
candy cake iceream
july august september october november december
*/