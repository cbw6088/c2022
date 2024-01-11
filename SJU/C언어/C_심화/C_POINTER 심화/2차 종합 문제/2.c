#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
   char tmp[100] = {};
   gets(tmp);
   char *q = tmp;
   int cnt = 1;
   for(int i = 0 ; i < strlen(tmp); i++){
      if(tmp[i] == ' ')
         cnt++;
   }
   char **p = (char**)malloc(sizeof(char*) * cnt);
   if(p == NULL) return -1;

   int len = strlen(q) + 1, idx = 0;
   for(int i = 0; i < len; i++){
      if(tmp[i] == ' ' || tmp[i] == '\0'){
         tmp[i] = '\0';
         p[idx] = (char*)malloc(sizeof(char) * (strlen(q) + 1));
         if(p[idx] == NULL) return -1;
         strcpy(p[idx++], q);
         q = q + strlen(q) + 1;
      }
   }

   int idx2 = 0, idx3 = 0, idx4 = 0; 
   for(int i = 0; i < idx; i++){
      if(idx2 < 2){
         printf("%s\n", p[idx4]);
         idx4++;
      }
      else if(idx2 >= 2 && idx2 < 4){
         printf("%s\n", p[idx - 1 - idx3]);
         idx3++;
      }
      idx2++;
      if(idx2 == 4)
         idx2 = 0;
   }

 
   for(int i = 0; i < idx; i++)
      free(p[i]);
   free(p);
   return 0;
}

// lion cat tiger snake bear