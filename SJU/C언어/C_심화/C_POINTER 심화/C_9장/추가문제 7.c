#include <stdio.h>


int *center(int *p, int N);

int main(){
    // freopen("7.txt", "r" ,stdin);
    int N;
    scanf("%d", &N);
    int A[N];
    int *p;

    for(p=A; p<A+N; p++)
        scanf("%d", p);
    p = A;
    int * answer =center(p, N);
    printf("%d\n", *answer);
    printf("%ld\n", answer-A);
    
    return 0;
}
int *center(int *p, int N){
    double sum = 0;
    for(int *temp =p; temp<p+N; temp++)
        sum += *temp;
    sum = sum /N;
    printf("%.1f\n", sum);
    int check = 0;
    int min = *p - sum;
    if(min<0){min = min *-1;}
    int *find_idx;

    for(int *temp =p+1; temp<p+N; temp++){
        check = *temp - sum;
        if(check<0){check = check *-1;}
        if(min>=check){
            min = check;
            find_idx = temp;
        }
    }
    return find_idx;
}