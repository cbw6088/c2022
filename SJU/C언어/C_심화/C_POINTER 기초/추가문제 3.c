#include <stdio.h>

void count(char *ar, int *info);

int main(){
    // freopen("3.txt" , "r" ,stdin);
    char ar[100];
    int info[4];
    int *p = info;

    scanf("%[^\n]s",ar);
    count(ar, info);

    printf("Vowels: %d\n", *p++);
    printf("Consonants: %d\n", *p++);
    printf("Digits: %d\n", *p++);
    printf("White spaces: %d\n", *p++);
    return 0;
}

void count(char *ar, int *info){
    int a =0;
    int b= 0;
    int c= 0;
    int d= 0;
    for(char *temp = ar; *ar != '*'; ar++){
        
        if(*ar =='a' || *ar =='A' || *ar =='e' || *ar =='E' || *ar =='i' || *ar =='I' || 
        *ar =='o' || *ar =='O' || *ar =='u' || *ar =='U'){
            a++;
        }
        else if(*ar>=48 && *ar<=59){
            c++;
        }
        else if(*ar ==' '){
            d++;
        }
        else {
            b ++;
        }
    }
    *info = a;
    info++;
    *info = b;
    info ++;
    *info = c;
    info++;
    *info = d;
    info ++;
}