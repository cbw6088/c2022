/*Visual Studio Code에서 구현*/
/*Visual Studio에서 메모리 문제로 코드 에러 나와서 0점*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RATIO 0.9
#define MAX_SIZE 3000

void print_arr(int **arr, int n);
int fixed_arr(int **arr, int n, int k, int min);
int countOnesButSlow(int **arr, int n);
int countOnes(int **arr, int n);

int main()
{
   srand(time(NULL));

   /////////////////// 빠른 버전 수행 결과 ///////////////////
   
   /* n = 3000 */
   double cputime;

   /* 변수 지정 */
    int n = MAX_SIZE;
    int **A = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < MAX_SIZE; i++)
        A[i] = (int*)malloc(sizeof(int) * n);
    int min = (n * RATIO);
    int k = rand()% (n + 1 - min) + min;
    int kTotal = 0, ones = 0;

    /* 값 저장 */
    kTotal = fixed_arr(A, n, k, min);
    clock_t start = clock(); // start 
    ones = countOnes(A, n);
    cputime = (double)(clock() - start) / CLOCKS_PER_SEC; //end

    printf("%d, %d, %lf\n", kTotal, ones, cputime);
    /* 제거 */
    for(int i = 0; i < n; i++)
        free(A[i]);
    free(A);

    /* n = 1000 */

    /* 변수 지정 */
    n = MAX_SIZE / 3;
        int **B = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < MAX_SIZE; i++)
        B[i] = (int*)malloc(sizeof(int) * n);
    min = (n * RATIO);
    k = rand()% (n + 1 - min) + min;

    /* 값 저장 */
    kTotal = fixed_arr(B, n, k, min);
    start = clock(); // start 
    ones = countOnes(B, n);
    cputime = (double)(clock() - start) / CLOCKS_PER_SEC; //end

    printf("%d, %d, %lf\n", kTotal, ones, cputime);
    /* 제거 */
    for(int i = 0; i < n; i++)
        free(B[i]);
    free(B);

    /* n = 2000 */

    /* 변수 지정 */
    n = MAX_SIZE / 1.5;
    int **C = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < MAX_SIZE; i++)
        C[i] = (int*)malloc(sizeof(int) * n);
    min = (n * RATIO);
    k = rand()% (n + 1 - min) + min;

    /* 값 저장 */
    kTotal = fixed_arr(C, n, k, min);
    start = clock(); // start 
    ones = countOnes(C, n);
    cputime = (double)(clock() - start) / CLOCKS_PER_SEC; //end

    printf("%d, %d, %lf\n", kTotal, ones, cputime);
    /* 제거 */
    for(int i = 0; i < n; i++)
        free(C[i]);
    free(C);

    /////////////////// 느린 버전 수행 결과 ///////////////////

    /* n = 3000 */

    /* 변수 지정 */
    n = MAX_SIZE;
    int **D = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < MAX_SIZE; i++)
        D[i] = (int*)malloc(sizeof(int) * n);
    min = (n * RATIO);
    k = rand()% (n + 1 - min) + min;

    /* 값 저장 */
    kTotal = fixed_arr(D, n, k, min);
    start = clock(); // start 
    ones = countOnesButSlow(D, n);
    cputime = (double)(clock() - start) / CLOCKS_PER_SEC; //end

    printf("%d, %d, %lf\n", kTotal, ones, cputime);
    /* 제거 */
    for(int i = 0; i < n; i++)
        free(D[i]);
    free(D);

    /* n = 1000 */

    /* 변수 지정 */
    n = MAX_SIZE / 3;
    int **E = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < MAX_SIZE; i++)
        E[i] = (int*)malloc(sizeof(int) * n);
    min = (n * RATIO);
    k = rand()% (n + 1 - min) + min;

    /* 값 저장 */
    kTotal = fixed_arr(E, n, k, min);
    start = clock(); // start 
    ones = countOnesButSlow(E, n);
    cputime = (double)(clock() - start) / CLOCKS_PER_SEC; //end

    printf("%d, %d, %lf\n", kTotal, ones, cputime);
    /* 제거 */
    for(int i = 0; i < n; i++)
        free(E[i]);
    free(E);

    /* n = 2000 */

    /* 변수 지정 */
    n = MAX_SIZE / 1.5;
    int **F = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < MAX_SIZE; i++)
        F[i] = (int*)malloc(sizeof(int) * n);
    min = (n * RATIO);
    k = rand()% (n + 1 - min) + min;

    /* 값 저장 */
    kTotal = fixed_arr(F, n, k, min);
    start = clock(); // start 
    ones = countOnesButSlow(F, n);
    cputime = (double)(clock() - start) / CLOCKS_PER_SEC; //end

    printf("%d, %d, %lf\n", kTotal, ones, cputime);
    /* 제거 */
    for(int i = 0; i < n; i++)
        free(F[i]);
    free(F);
    return 0;
}

void print_arr(int **arr, int n){
    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int fixed_arr(int **arr, int n, int k, int min){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j < k){
            arr[i][j] = 1;
            cnt++;
            }
            else
            arr[i][j] = 0;
        }
        min = (k * RATIO);
        if(min > n) break;
        int temp = rand() % (k - min + 1) + min ;
        k = temp;
    }
    return cnt;
}

int countOnesButSlow(int **arr, int n){
    int cnt = 0;
    // 2차원 배열 모두 접근
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(arr[i][j] == 1) cnt++; // 원소가 1인 경우 카운트
    return cnt; // 반환
}

int countOnes(int **arr, int n){
    int idx = 0, cnt = 0;
    for(int i = n - 1; i >= 0; i--){ // 행의 배열의 끝 부터 0인덱스가 될 때 까지 
        if(idx == n) break; // 또 다른 종료 조건
        if(arr[idx][i] == 1){ // 1이 나온 경우
            idx++; // 열 한 칸 이동
            cnt = cnt + i + 1; // 1의 총 개수 (문제에선 사용 x)
            i++; // i가 반복문에서 내려가기 때문에 올려주며 보정
        }
    }
    return idx;
}