#include <stdio.h>

void sort(int *ar, int * p);
void merge(int *ar1, int *ar2, int *ar3, int *p, int *q);

int main(){
    //freopen("5.txt", "r", stdin);

    int ar1[100];
    int ar2[100];
    int ar3[100];

    int N = 0;
    scanf("%d", &N);
    int *p1 = ar1;
    for(; p1< ar1+N; p1++)
        scanf("%d", p1);

    int M = 0;
    scanf("%d", &M);
    int *p2 = ar2;
    for(; p2< ar2+M; p2++)
        scanf("%d", p2);

    int *p = &N;
    int *q = &M;

    p1 = ar1;
    p2 = ar2;

    sort(p1,p);
    sort(p2,q);

    // for(int *temp = ar1; temp<ar1+N; temp++)
    //     printf("%d ",*temp);
    // printf("\n");

    // for(int *temp = ar2; temp<ar2+M; temp++)
    //     printf("%d ",*temp);
    // printf("\n");
    
    p1 = ar1;
    p2 = ar2;
    int *p3 = ar3;

    merge(p1,p2,p3,p,q);
    
    for(int *temp = ar3; temp <ar3+(*p+*q); temp++){
        printf("%d ", *temp);
    }
    

    return 0;
}


void sort(int *ar, int * p){
    int * find_index;
    for(int *temp =ar ; temp<ar+*p; temp++){
        int min = *temp; 
        for(int *T=temp; T<ar+*p; T++){
            if(min>=*T){
                min = *T;
                find_index = T;
            }
        }
        int swap = *find_index;
        *find_index = *temp;
        *temp = swap;
    }
}



void merge(int *ar1, int *ar2, int *ar3, int *p, int *q){
    int N = *p;
    int M= *q;
    while(1){
        if(*ar1 >*ar2){
            *ar3 = *ar2;
            ar3++;
            ar2++;
            M--;
            if(M==0)
                break;
        }
        else{
            *ar3 = *ar1;
            ar3++;
            ar1++;
            N--;
            if(N==0)
                break;
        }
    }

    if(N!=0){
        *ar3 = *ar1;
        ar3++;
        ar1++;
        N--;
    }
    else{
        *ar3 = *ar2;
        ar3++;
        ar2++;
        M--;
    }    
}