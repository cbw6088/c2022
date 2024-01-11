#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct study{
    char ch[10];
    double num[3];
    double avg;
};

void read_data(struct study *A);
void cal_avg(struct study *A);
void sort(struct study *A);
void print_score(struct study *A);

int main(){
    struct study name[10];
    struct study *p = name;
    read_data(p);  
    cal_avg(p);
    // for(int i=0; i<10; i++)
    //     printf("1. %s %.2lf\n", (p+i)->ch, (p+i)->avg);
    // printf("\n");
    p = name;
    sort(p);
    // for(int i=0; i<10; i++)
    //     printf("2. %s %.2lf\n", (p+i)->ch, (p+i)->avg);
    // printf("\n");
    p = name;

    print_score(p);

    
    return 0;
}

void read_data(struct study *A){
    for(int i=0; i<10; i++)
        scanf("%s %lf %lf %lf", (A+i)->ch, &(A+i)->num[0], &(A+i)->num[1], &(A+i)->num[2]);
}

void cal_avg(struct study *A){
    struct study *p = A;
    for(int i=0; i<10; i++)
        (p+i)->avg = ((p+i)->num[0] + (p+i)->num[1] + (p+i)->num[2]) / 3;
}

void sort(struct study *A){
    struct study *p = A;
    struct study tmp;
    for(int i=0; i<9; i++){
        for(int j=i+1; j<10; j++){
            if( (p+i)->avg < (p+j)->avg ){
                tmp = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = tmp;
            }
        }
    }
}

void print_score(struct study *A){
    printf("%s %.2lf\n",A[0].ch, A[0].avg);
    printf("%s %.2lf\n",A[9].ch, A[9].avg);
    printf("%s %.2lf\n",A[7].ch, A[7].avg);
    printf("%s %.2lf\n",A[8].ch, A[8].avg);
    printf("%s %.2lf\n",A[9].ch, A[9].avg);
}

/* 
AKim 80 80 80
BKim 90 90 90
CKim 81 81 81
ALee 82 82 82
BLee 83 83 83
CLee 84 84 84
APark 85 85 85
BPark 86 86 86
CPark 87 87 87
DPark 88 88 88
*/