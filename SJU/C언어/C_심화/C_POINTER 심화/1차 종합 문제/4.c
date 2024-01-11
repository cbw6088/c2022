#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *center(int *p, int N);

int main(){
    int N, idx = 0;
    double avg = 0;
    scanf("%d", &N);
    int ar[100] = {};
    int *p = ar, *q;
    for(; p < ar + N; p++)
        scanf("%d", p);
    p = ar;
    q = center(p, N);
    printf("%d\n", *q);
    for(; p < ar + N; p++){
        if(*p == *q)
            break;
        idx++;
    }
    printf("%d", idx);
   

    return 0;
}

int *center(int *p, int N){
    int idx = 0, idx2 = 0;
    int *q = p;
    double avg = 0, tmp = 0, min = 9999999;
    for(; q < p + N; q++)
        avg = avg + (double)*q;
    avg = avg / N;
    printf("%.1lf\n", avg);
    q = p;
    for(; q < p + N; q++){
        if(avg > *q){
            tmp = avg - (double)*q;
            if(min > tmp){
                min = tmp;
                idx2 = idx;
            }         
        }
        else{
            tmp = (double)*q - avg;
            if(min > tmp){
                min = tmp;
                idx2 = idx;
            }
        }
        idx++;
    }
    q = p;
    return q + idx2;
}