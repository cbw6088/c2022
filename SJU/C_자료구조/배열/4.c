#include <stdio.h>

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int arr[N][M];
    int data = 1;
    int x_idx = N, y_idx = M;
    int i = 0, j = 0, k = 0;
    while(data <= N * M){
        for(j = k; j < y_idx; j++)
            arr[i][j] = data++;
        j--;
        for(i = k + 1; i < x_idx; i++)
            arr[i][j] = data++;
        i--;
        if(data > N * M)
            break;
        for(j = y_idx - 2; j >= k; j--)
            arr[i][j] = data++;
        j++;
        k++;
        for(i = x_idx - 2; i >= k; i--)
            arr[i][j] = data++;
        i++;
        x_idx--;
        y_idx--;
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            printf(" %d", arr[i][j]);
        printf("\n");
    }
    return 0;
}