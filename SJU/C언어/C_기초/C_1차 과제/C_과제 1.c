#include <stdio.h>

int main(void){
    int N = 0, result = 0;
    scanf("%d",&N);

    result = ( (N%15 == 0) && (N%5 == 0) && (N%3 == 0) ) * 15 +
    ( (N%15 != 0) && (N%5 != 0) && (N%3 == 0) ) * 3 +
    ( (N%15 != 0) && (N%3 != 0) && (N%5 == 0) ) * 5 +
    ( (N%15 != 0) && (N%5 != 0) && (N%3) != 0 ) * N;
    
    printf("%d is a multiple of %d.",N,result);
    
    return 0;
}