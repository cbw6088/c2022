#include <stdio.h>

int main(){
    int cnt=0,check=0,idx=0;
    char str_a[101]={0};
    char str_b[101]={0};
    char *a = str_a;
    char *b = str_b;
    scanf("%s",str_a);
    scanf("%s",str_b);
    a = str_a;
    b = str_b;
    while(*a != 0){
       cnt++;
       a++;
    }
    a = str_a;
    while(*a != 0){
         if(*a == *b)
             check = 1;
         else{
            check = 0;
            break;
         }
         a++;
         b++;
     }
    printf("%d %d",cnt,check);

    return 0;
}