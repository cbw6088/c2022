#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int arr[N][N];
    int data = 1;
    for(int i = 0; i < N; i++){
        if(i == 0 || i % 2 == 0){
            for(int j = 0; j < N; j++)
                arr[i][j] = data++;
        }
        else{
            for(int j = N - 1; j >= 0; j--)
                arr[i][j] = data++;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            printf(" %d", arr[i][j]);
        printf("\n");
    }
    return 0;
}