#include <stdio.h>

int recursion(int *arr, int N);

int main(){
    int N;
    scanf("%d", &N);
    int arr[20] = {};
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    printf("%d", recursion(arr, N));
}

int recursion(int *arr, int N){
    if(N == 1) // 마지막의 경우 첫 번째 인덱스 반환
        return arr[0];
    /* 현재 배열의 값과 1~N-2 사이의 값 중 큰 수 반환 */
    int num = recursion(arr, N - 1);
    return (num > arr[N - 1] ? num : arr[N - 1]);
}