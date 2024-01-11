#include <stdio.h>

int main(){
    int N, M;
    scanf("%d", &N);
    int arr[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &M); // 뒤집을 배열의 수
    int from, to, len, tmp;
    for(int i = 0; i < M; i++){
        scanf("%d %d", &from, &to);
        len = to - from; // 앞과 뒤의 위치를 스왑 하기 위해 반복은 절반만 필요
        for(int j = 0; j <= len / 2; j++){
            tmp = arr[from + j]; // 스왑
            arr[from + j] = arr[to - j];
            arr[to - j] = tmp;
        }
    }
    for(int i = 0; i < N; i++)
        printf(" %d", arr[i]);
    return 0;
}