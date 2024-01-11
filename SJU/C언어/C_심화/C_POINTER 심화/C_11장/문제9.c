#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct result{
    int max, min, minus;
    char ch;
};

void passorfail(struct result *A);

int main(){
    struct result n, *p = &n;
    scanf("%d %d %d",&n.max, &n.min, &n.minus);
    passorfail(p);
    printf("%d %c", p->max - p->min, p->ch);
    return 0;
}

void passorfail(struct result *A){
    struct result *p = A;
    int minus;
    minus = p->max - p->min;
    if(minus <= p->minus)
        p->ch = 'P';
    else   
        p->ch = 'F';
}