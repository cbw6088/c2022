#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define MAX_INT 210000000

int max_num(int N1, int N2);
int min_num(int N1, int N2);
void P(int A[], int idx);


int main(){
    //freopen("input.txt", "r", stdin);
    int idx = 0;
    int A[MAX_SIZE];
    while(1){
        int temp = 0;
        scanf("%d",&temp);
        if(temp == 0){break;}
        A[idx++] = temp;
    }

    int changeNum = 0;
    scanf("%d", &changeNum);

    for(int i=0; i<changeNum; i++){
        int N1,N2 = 0;
        scanf("%d %d", &N1, &N2);

        int temp = (N2-N1)/2;
        // printf("%d ",temp );
        int max = 0;
        int min = MAX_INT;
        for(int i=0; i<=temp; i++){
            int Swap = A[N1+i];
            A[N1+i] = A[N2-i];
            A[N2-i] = Swap;
            int temp_max = max_num(A[N1+i], A[N2-i]);
            int temp_min = min_num(A[N1+i], A[N2-i]);
            if(max <= temp_max){max = temp_max;}
            if(min >= temp_min){min = temp_min;}
        }
        P(A,idx);
        printf("%d %d \n", max, min);
    }//swap
    
    return 0;
}

int max_num(int N1, int N2){
    return N1>=N2?N1:N2;
}

int min_num(int N1, int N2){
   return N1>=N2?N2:N1;
}

void P(int A[], int idx){
    for(int i=0; i<idx; i++)
        printf("%d ",A[i]);
    printf("\n");
}