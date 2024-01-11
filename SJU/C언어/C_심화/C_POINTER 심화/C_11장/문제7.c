#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct arr{
    int ar;
    int cnt;
};

int main(){
    int cnt = 1;
    struct arr A[10];
    for(int i=0; i<10; i++){
        scanf("%d",&A[i].ar);
        A[i].cnt = cnt++;
    }
    struct arr tmp, *p = A;

    for(int i=0; i<9; i++){
        for(int j=i+1; j<10; j++){
            if((p+i)->ar < (p+j)->ar){
                tmp.ar = (p+i)->ar;
                (p+i)->ar = (p+j)->ar;
                (p+j)->ar = tmp.ar;
            }
        }
    }
    

    printf("%d %d\n",A[2].ar, A[6].ar);

    return 0;
}

// 78 65 23 43 82 95 31 15 8 54