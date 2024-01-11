#include <stdio.h>
#include <string.h>

int front(char *p, int idx);
int back(char *p, int idx);

int main(){
    char ch[101] = {};

    gets(ch);

    for(int i=0; i<strlen(ch); i++){
        if(front(ch, i) == 1 && back(ch, i) == 1)
            ch[i] = ch[i] - 32;
    }
    printf("%s",ch);
    return 0;
}

int front(char *p, int idx){
    char str = *(p+idx);
    int cnt = 0;
    for(char *q = p+idx+1; q < p+strlen(p); q++){
        if(*q == str)
            cnt++;
    }
    if(cnt >= 1)
        return 1;
    else
        return 0;
}

int back(char *p, int idx){
    int cnt = 0, i = idx-1;
    char str = *(p+idx);
    char *q = p;
    while(idx != 0){
        if(*(q+i) == str)
            cnt++;
        idx--;
        i--;
    }
    if(cnt >= 1)
        return 1;
    else
        return 0;
}