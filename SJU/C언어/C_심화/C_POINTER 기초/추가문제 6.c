#include <stdio.h>

void change(char *ar1);

int main(){
    //freopen("6.txt" , "r" ,stdin);
    char ar1[100];
    scanf("%[^\n]s",ar1);
    change(ar1);
    char *temp = ar1;
    while(*temp != '*'){
        printf("%c", *temp);
        temp++;
    }
    printf("\n");



    return 0;
}
void change(char *ar1){
    int check = 0;
    int seq = 0;
    char *temp = ar1;
    char ch[100];
    char *str = ch;
    int cnt= 0;

    while(1){
        if(*temp=='*'){
            temp++;
            while(*temp !='*'){
                *str = *temp;
                str++;
                temp ++;
                check++;
            }
            break;
        } 
        temp ++;
    }
    temp = ar1;
    str = ch;
    char *find;
    
    while(*temp!='*'){
        if(*temp == *str){
            cnt++;
            seq =1;
            str++;
        }
        else{seq =0; cnt = 0; str= ch;}
        temp++;

        if(seq==1 && cnt ==check){
            find = temp-check;
            seq = 0; cnt =0; str =ch;
        }
    }
    for(int i=0; i<check; i++){
        * find -= 32;
        find++;
    }
}