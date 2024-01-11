#include <stdio.h>

void input(int *p, int N);
int *diff(int *p, int N);

int main(){
    int N;
    scanf("%d",&N);
    int ar[N];
    int *p = ar;
    input(p,N);
    int *Answer = diff(p,N);
    printf("%d %d",*Answer,*(Answer+1));
 
    return 0;
}

void input(int *p, int N){
    int *tmp = p;
    for(; tmp<p+N;tmp++)
        scanf("%d",tmp);
}

int *diff(int *p, int N){
    int max=0,sum=0;
    int *idx;
    for(int *tmp=p; tmp<p+N-1; tmp++){
        sum = *tmp - *(tmp+1);
        if(sum<0)
            sum = sum * (-1);
        if(max<=sum){
            idx = tmp;
            max = sum;
        }
    }
    return idx;
}