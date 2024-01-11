#include <stdio.h>

int frequency(char * ar, char* p);

int main(){
    // freopen("2.txt", "r", stdin);
    char alpha[26];
    char str[100];
    char * ar = str;
    char * p;
    int idx =0;

    scanf("%[^\n]s",ar);


    for(p=alpha; p<alpha+26; p++){
        *p = 'a'+idx++;
    }


    for(p=alpha; p<alpha+26; p++){
        int answer  = 0;
        answer = frequency(ar, p);
        if(answer !=0){
            printf("%c %d\n",*p, answer);
        }
    }




    return 0;
}

int frequency(char * ar, char* p){
    // 최초 p -> 'a'
    // ar -> fascinates me.
    int result = 0;
    char *q = ar;
    while(*q!='.'){
        if(*q == *p){
            result++;
        }
        q ++;
    }
    return result;
}