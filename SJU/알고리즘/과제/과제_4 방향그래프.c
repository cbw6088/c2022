#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX 30
#define MIN_VALUE 2147483647
#ifndef MIN
#define MIN(a,b) ((a) > (b) ? (b) : (a)) // 두 값 중 작은 값을 반환하도록 정의
#endif

unsigned int airtelDC(int n, int s, int d, int A[], int H[]);
unsigned int airtelDP(int n, int s, int d, int A[], int H[]);
void printCPUTIME(clock_t start, char *version);

unsigned int memo[MAX][MAX];

int main(void){
    int A[MAX], H[MAX]; // 배열 A와 H 선언
    memset(memo, MIN_VALUE, sizeof(memo)); //  배열 초기화
    /*배열 A와 H 초기화*/
    A[0] = 0, A[1] = 1;
    for (int i = 2; i < MAX; i++)
        A[i] = A[i-1] + A[i-1] % 5 + 3;
    H[0] = 0, H[1] = 5;
    for (int i = 2; i < MAX; i++)
        H[i] = (H[i-1] + i) % 9 + 1;

    printf("n       s       d      mincost      version    cputime\n");
    int n = 6; // 문제에서 제시한 초기 사이즈
    int testArr[3][2] = {{0, 4}, {2, 5}, {2, 4}};
    for (int i = 0; i < 3; i++){
        int s = testArr[i][0];
        int d = testArr[i][1];

        /*airtelDC 함수 호출*/
        clock_t start = clock();
        unsigned int mincost = airtelDC(n, s, d, A, H);
        printf("%d\t%d\t%d\t%d\t      ", n, s, d, mincost);
        printCPUTIME(start, "DC");
        /*airtelDP 함수 호출*/
        start = clock();
        mincost = airtelDP(n, s, d, A, H);
        printf("%d\t%d\t%d\t%d\t      ", n, s, d, mincost);
        printCPUTIME(start, "DP");
    }

    /*n = MAX에 대해 코드 실행*/
    n = MAX;
    int s = 1, d = n - 2;
    clock_t start = clock();
    unsigned int mincost = airtelDC(n, s, d, A, H);
    printf("%d\t%d\t%d\t%d\t      ", n, s, d, mincost);
    printCPUTIME(start, "DC");
    
    start = clock();
    mincost = airtelDP(n, s, d, A, H);
    printf("%d\t%d\t%d\t%d\t      ", n, s, d, mincost);
    printCPUTIME(start, "DP");

    return 0;
}

/*분할 통치법을 이용한 최소 비용 계산 함수*/
unsigned int airtelDC(int n, int s, int d, int A[], int H[]){
    if (s >= d) return 0;
    if (memo[s][d] != MIN_VALUE) return memo[s][d];

    unsigned int mincost = MIN_VALUE;
    for (int i = s + 1; i < d; i++){
        /*중간 지점을 통한 최소 비용 계산*/
        unsigned int cost = airtelDC(n, s, i, A, H) + airtelDC(n, i, d, A, H) + H[d] - H[s];
        mincost = MIN(mincost, cost);
    }
    memo[s][d] = mincost; // 최소 비용 저장
    return mincost;
}

/*동적 프로그래밍을 이용한 최소 비용 계산 함수*/
unsigned int airtelDP(int n, int s, int d, int A[], int H[]){
    unsigned int dp[n + 1][n + 1];
    memset(dp, MIN_VALUE, sizeof(dp)); // dp 배열 초기화

    for (int i = 0; i <= n; i++)
        dp[i][i] = 0; // 자기 자신 비용 0
    for (int len = 2; len <= n; len++){
        for (int i = 0; i <= n - len; i++){
            int j = i + len - 1;
            for (int k = i + 1; k < j; k++){
                // 각 구간에 대한 최소 비용 계산
                unsigned int cost = dp[i][k] + dp[k][j] + H[j] - H[i];
                dp[i][j] = MIN(dp[i][j], cost);
            }
        }
    }
    return dp[s][d];
}

/*CPU 시간 측정 및 출력 함수*/
void printCPUTIME(clock_t start, char *version){
    double cputime = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("%s       %f\n", version, cputime);
}
