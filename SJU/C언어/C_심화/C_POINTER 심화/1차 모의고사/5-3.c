#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person{
    char name[20];
    char birth[20];
    double exam1, exam2, avg;
}men;

void swap(men *n1, men *n2);

int main(){
    int N, M;
    men st[20];
    men *p = st;
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%s %s %lf %lf", (p+i)->name, (p+i)->birth, &(p+i)->exam1, &(p+i)->exam2);

    for(int i=0; i<N; i++)
        (p+i)->avg = ((p+i)->exam1*0.8) + ((p+i)->exam2*0.2);

    p = st;
    for(; p < st + N - 1; p++){
        for(men *q = p + 1; q < st + N; q++){
            if(p->avg < q->avg)
                swap(p,q);
            else if(p->avg == q->avg){
                if(p->exam1 < q->exam1)
                    swap(p,q);
                else if(p->exam1 == q->exam1){
                    if(strcmp(p->birth,q->birth) < 0)
                        swap(p,q);
                }
            }
        }
    }
    p = st;
    for(; p < st + M; p++)
        printf("%s %.1lf\n", p->name, p->avg);
    return 0;
}

void swap(men *n1, men *n2){
    men tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

/*
7 3
Aaaaa 1995-10-07 75 85
Bbbbb 1991-11-15 90 64
Ccccc 1994-12-08 94 82
Ddddd 1993-07-17 78 70
Eeeee 1995-10-07 65 85
Fffff 1991-11-05 90 64
Ggggg 1990-08-21 90 64
*/