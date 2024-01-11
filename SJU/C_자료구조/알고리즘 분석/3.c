#include <stdio.h>
#include <stdlib.h>

int *prefixAverages1(int *X, int n);
int *prefixAverages2(int *X, int n);

int main(){
    int n;
    scanf("%d", &n);
    // 동적할당으로 선언
    int *X = (int*)malloc(sizeof(int) * n);
    if(X == NULL)
        return -1;
    // 입력
    for(int i = 0; i < n; i++)
        scanf("%d", &X[i]);
    // 함수 값 저장
    int *A = prefixAverages1(X, n);
    int *B = prefixAverages2(X, n);
    // 각각 출력
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    for(int i = 0; i < n; i++)
        printf("%d ", B[i]);
    free(X);
    free(A);
    free(B);
    return 0;
}

int *prefixAverages1(int *X, int n){
    int *A = (int*)malloc(sizeof(int) * n);
    if(A == NULL)
        return NULL;
    int sum;
    for(int i = 0; i < n; i++){
        sum = 0;
        // i인덱스까지 모두 합
        for(int j = 0; j <= i; j++)
            sum += X[j];
        // 반올림
        A[i] = (((double)sum / (i + 1)) + 0.5);
    }
    return A;
}

int *prefixAverages2(int *X, int n){
    int *B = (int*)malloc(sizeof(int) * n);
    if(B == NULL)
        return NULL;
    int sum = 0;
    for(int i = 0; i < n; i++)  {
        // 모두 합
        sum += X[i];
        // 반올림
        B[i] = (((double)sum / (i + 1)) + 0.5);
    }
    return B;
}