#include <stdio.h>

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int arr[N][M];
    int data = 1, k = 0, num = 0;
    while(data <= N * M){
        for(int i = k; i < N; i++){
            for(int j = k; j < M; j++){
                if(i + j == num) // 항상 i + j가 num 일 때 값이 들어감
                    arr[i][j] = data++;
            }
        }
        num++;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            printf(" %d", arr[i][j]);
        printf("\n");
    }
    return 0;
}