#include <stdio.h>

void Remove(char *ar1,char *ar2);

int main(){
    //freopen("4.txt" , "r" ,stdin);
    char ar1[100];
    char ar2[100];
    scanf("%[^\n]s",ar1);
    Remove(ar1, ar2);
    for(char *temp = ar2; *temp!='\0'; temp++){
        printf("%c",*temp);
    }
    printf("\n");
    
    // printf("%s\n",ar2);



    return 0;
}

void Remove(char *ar1,char *ar2){
    char *point = ar2;
    for(char *temp = ar1; *temp != '*'; temp++){
        if( (*temp >=65 && *temp <=90) || (*temp >=97 && *temp <=122) ){
            *point = *temp;
            point++;
        }
    }
}