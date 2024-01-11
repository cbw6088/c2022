#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input(int *p);
int *sel_next(int *p);
int number(int *p, int *q);

int main(){
    int ar[100] = {};
    int *p = ar;
    int cnt = 0;
    cnt = input(p);
    int *q = p;
    while(*(p+1) != -1){
        q = sel_next(p);
        printf("%d\n", number(p, q));
        p = q;
    }
    return 0;
}

int input(int *p){
    int *q = p;
    int cnt = 0;
    for(; q < p + 100; q++){
        scanf("%d", q);
        if(*q == -1)
            break;
        cnt++;
    }
    return cnt;
}

int *sel_next(int *p){
    int *q = p;
    if(*q < *(q+1)){
        while(*q < *(q+1)){
            if(*(q+1) == -1) return q;
            q++;
        }
    }
    else if(*q > *(q+1)){
        while(*q > *(q+1)){
            if(*(q+1) == -1) return q;
            q++;
        }
    }
    return q;
}

int number(int *p, int *q){
    int result = 0;
    while(*p != *q){
        result = result * 10;
        result = result + *p;
        p++;
    }
    result = result * 10;
    result = result + *p;
    return result;
}