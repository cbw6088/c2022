#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    char name[31];
    int kor;
}st;

st *center(st *p, int N);

int main(){
    int N;
    st A[100];
    st *p = A, *q;
    scanf("%d", &N);
    for(; p < A + N; p++)
        scanf("%s %d", p->name, &p->kor);
    p = A;
    q = center(p, N);
    printf("%s %d", q->name, q->kor);

    return 0;
}

st *center(st *p, int N){
    st *q = p;
    int avg = 0, tmp = 0, idx1 = 0, idx2 = 0, min = 9999999;
    for(; q < p + N; q++)
        avg = avg + q->kor;
    avg = avg / N;
    q = p;
    for(; q < p + N; q++){
        if(avg > q->kor)
            tmp = avg - q->kor;
        else
            tmp = q->kor - avg;
        if(min > tmp){
            min = tmp;
            idx1 = idx2;
        }
        idx2++;
    }
    q = p;
    return q + idx1;
}