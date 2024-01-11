#include <stdio.h>

int main(){
    int N, M;
    scanf("%d", &N);
    int arr[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &M);

    int idx, tmp, out;
    for(int i = 0; i < M; i++){
        scanf("%d", &idx);
        if(i == 0){
            tmp = arr[idx];
            continue;
        }
        out = arr[idx];
        arr[idx] = tmp;
        tmp = out;
    }
    for(int i = 0; i < N; i++)
        printf(" %d", arr[i]);
    return 0;
}