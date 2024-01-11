#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word{
   char *name;
   int num;
}Word;

int main(){
   char tmp[100] = {};
   gets(tmp);
   int cnt = 1;
   for(int i = 0 ; i < strlen(tmp); i++){
      if(tmp[i] == ' ')
         cnt++;
   }
   Word *p = (Word*)malloc(sizeof(Word) * cnt);
   if(p == NULL) return -1;

   int len = strlen(tmp) + 1, idx = 0;
   char *q = tmp;
   for(int i = 0; i < len; i++){
      if(tmp[i] == ' ' || tmp[i] == '\0'){
         tmp[i] = '\0';
         p[idx].name = (char*)malloc(sizeof(char) * (strlen(q) + 1));
         if(p[idx].name == NULL) return -1;
         strcpy(p[idx++].name, q);
         q = q + strlen(q) + 1;
       }
   }


   int cnt2 = 0;
   for(int i = 0; i < idx; i++){
      for(int j = 0; j < strlen(p[i].name); j++){
         if(p[i].name[j] == 'a' || p[i].name[j] == 'e' || p[i].name[j] == 'i' || p[i].name[j] == 'o' || p[i].name[j] == 'u' || p[i].name[j] == 'A' || p[i].name[j] == 'E' || p[i].name[j] == 'I' || p[i].name[j] == 'O' || p[i].name[j] == 'U'){
            cnt2++;
         }
      }
      p[i].num = cnt2;
      cnt2 = 0;
   }
   
   for(int i = 0; i < idx - 1; i++){
      for(int j = 0; j < idx - 1 - i; j++){
         if(p[j].num < p[j+1].num){
            Word tmp = p[j];
            p[j] = p[j+1];
            p[j+1] = tmp;
         }
      }
   }

   for(int i = 0; i < idx; i++)
      printf("%s %d\n", p[i].name, p[i].num);
   return 0;
}

// happy good onion