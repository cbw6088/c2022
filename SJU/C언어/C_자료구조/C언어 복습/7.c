#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    scanf("%d", &N);
    // 각 포인터 동적할당
    int *p = (int*)malloc(sizeof(int) * N);
    if(p == NULL)
        printf("Error\n");
    int *q = (int*)malloc(sizeof(int) * N);
    int *result = (int*)malloc(sizeof(int) * N);
    if (p == NULL || q == NULL) // 할당 오류
        return -1;
    // 포인터 각각 입력
    for(int i = 0; i < N; i++) 
        scanf("%d", &p[i]);
     for(int i = 0; i < N; i++)
        scanf("%d", &q[i]);
    // 결과 포인터에 각 포인터 위치 값 더하기
    for(int i = 0; i < N; i++)
        result[i] = p[i] + q[N -1 -i];
    // 출력
    for(int i = 0; i < N; i++)
        printf(" %d", result[i]);
    free(p);
    free(q);
    free(result);
}
