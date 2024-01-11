#include <stdio.h>
#define SIZE 10

void ABC(int *point, int size);

int main(){
    //freopen("input.txt","r", stdin);
    int A[SIZE];
    int K = SIZE;
    int *point;
    for(point=A; point<A+SIZE; point++)
        scanf("%d ", point);
    point = A;

    while(K--){
        ABC(point, K);
        point++;
        if(K==1){break;}
    }

    for(point=A; point<A+SIZE; point++)
            printf(" %d", *point);
    printf("\n");



    return 0;
}

void ABC(int *point, int size){
    int max = *point;  
    int *find_max;
    for(int *temp = point; temp<=point+size; temp++){
        if(max <= *temp){
            max = *temp;
            find_max = temp;
        }
    }  // MAX 찾는 함수

    int swap = *point ;
    *point  = *find_max;
    *find_max = swap;
}