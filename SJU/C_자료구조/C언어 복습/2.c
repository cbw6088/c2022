#include <stdio.h>

void ABC(int *arr, int k);

int main(){
    int arr[10];
    for(int i = 0; i < 10; i++)
        scanf("%d", &arr[i]);
    for(int i = 0; i < 9; i++){
        ABC(arr, i);
    }
    for(int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}

void ABC(int *arr, int k){
    int tmp = 0;
    for(int i = k + 1; i < 10; i++){
        if (arr[k] < arr[i]){
            tmp = arr[k];
            arr[k] = arr[i];
            arr[i] = tmp;
        }
    }
}