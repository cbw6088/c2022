/*Visual Studio Code에서 구현*/
#include <stdio.h>
#include <stdlib.h>

int countOnesButSlow(int **A, int n);
int countOnes(int **A, int n);

int main(){
    // 변수 및 포인터 생성 및 입력
    int n;
    scanf("%d", &n);
    int **A = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++)
        A[i] = (int*)malloc(sizeof(int) * n);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &A[i][j]);
        }
    }
    // 느린 버전
    printf("%d\n", countOnesButSlow(A, n));
    // 빠른 버전
    printf("%d\n", countOnes(A, n));
    // 포인터 제거
    for(int i = 0; i < n; i++)
        free(A[i]);
    free(A);
    return 0;
}

int countOnesButSlow(int **A, int n){
    int cnt = 0;
    // 2차원 배열 모두 접근
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(A[i][j] == 1) cnt++; // 원소가 1인 경우 카운트
    return cnt; // 반환
}

int countOnes(int **A, int n){
    int idx = 0, cnt = 0;
    for(int i = n - 1; i >= 0; i--){ // 행의 배열의 끝 부터 0인덱스가 될 때 까지 
        if(idx == n) break; // 또 다른 종료 조건
        if(A[idx][i] == 1){ // 1이 나온 경우
            idx++; // 열 한 칸 이동
            cnt = cnt + i + 1; // 1의 총 개수 (문제에선 사용 x)
            i++; // i가 반복문에서 내려가기 때문에 올려주며 보정
        }
    }
    return idx;
}

/*
8
1 1 1 1 1 1 1 1
1 1 1 1 1 1 0 0
1 1 1 1 1 1 0 0
1 1 1 1 1 0 0 0
1 1 1 1 1 0 0 0
1 1 1 1 1 0 0 0
1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0
*/