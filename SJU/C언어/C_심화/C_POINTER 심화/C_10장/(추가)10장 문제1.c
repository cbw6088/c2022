#include <stdio.h>

int main(){
    int N, A;
    scanf("%d", &N);
    char ar[100*N];
    for(int i = 0; i < 100*N; i = i + 100)
        scanf("%s", (ar+i));
    char *p = ar;
    for(int i=0; i<N; i++){
        scanf("%d", &A);
        A--;
        printf("%s ", p+(A*100));
    }
    return 0;
}