#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    srand(time(NULL));
    int N,tmp;
    scanf("%d",&N);
    int ar[N];
    for(int i=0; i<N; i++)
        // scanf("%d",&ar[i]);
        ar[i] = rand()%100;

    for(int i=0; i<N; i++){
        for(int j=0; j<N-1-i; j++){ // 마지막 인덱스에는 가장 큰 값이 고정으로 가서 반복을 할 때 마다 마지막 인덱스 전까지 구하기 (굳이 마지막 인덱스 구할 필요 x)
            if(ar[j] > ar[j+1]){
                tmp = ar[j]; // 스왑
                ar[j] = ar[j+1];
                ar[j+1] = tmp;
            }
        }
    }
    for(int i=0; i<N; i++) // 추ㄹ력
        printf("%d ",ar[i]);
    
    return 0;
}