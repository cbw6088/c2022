#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)
#pragma warning(disable:4013)


int findKthSmallest(int* L, int len, int k);
int* buildList(int n, int min, int max);
void writeList(int* L);
void minHeapify(int* L, int i, int len);
void buildMinheap(int* L, int len);
int sizeofList(int* L);
void copylist(int* A, int* B, int len);

int main() {
    // srand(time(NULL));
    int* L = (int*)malloc(sizeof(int));
    L = buildList(10, 1, 100); // #case 1
    int output[3] = {0};
    int len = sizeofList(L);
    int* copyL = (int*)malloc(sizeof(int) * len);
    writeList(L); // 초기 리스트 출력
    // clock_t start_time = clock();
    buildMinheap(L, len);

    printf("output is "); // 첫 번째 output 출력
    for (int k = 1; k <= 3; k++) {
        copylist(L, copyL, len);
        output[k - 1] = findKthSmallest(copyL, 10, k);
        printf("[%d] ", output[k - 1]);
    }
    printf("\n");
    // clock_t end_time = clock();
    // float processtime = (float)(end_time - start_time) / CLOCKS_PER_SEC;
    // printf("process time is %lf\n\n", processtime);
    L = buildList(100000, 1, 1000000); // #case 2
    int output2[4] = {0}; // #case 2
    int len2 = sizeofList(L);
    int* copyL2 = (int*)malloc(sizeof(int) * len2);

    // clock_t start_time2 = clock();
    buildMinheap(L, len2);
    copylist(L, copyL2, len2);

    output2[0] = findKthSmallest(copyL2, 100000, 1);
    copylist(L, copyL2, len2);
    output2[1] = findKthSmallest(copyL2, 100000, 100);
    copylist(L, copyL2, len2);
    output2[2] = findKthSmallest(copyL2, 100000, 99900);
    copylist(L, copyL2, len2);
    output2[3] = findKthSmallest(copyL2, 100000, 99999);

    // clock_t end_time2 = clock();
    // float processtime2 = (float)(end_time2 - start_time2) / CLOCKS_PER_SEC;

    for (int i = 0; i < 4; i++) // 두 번째 output 출력
        printf("output2 is [%d]\n", output2[i]);

    // printf("process time2 is %lf", processtime2);
    return 0;
}

int findKthSmallest(int* L, int len, int k) {
    int kmin = 0;
    // 가장 작은 값 저장 후 다시 heapify
    for (int i = 1; i <= k; i++) {
        kmin = L[1];
        L[1] = L[len - (i - 1)];
        minHeapify(L, 1, len - (i - 1));
    }
    return kmin;
}

int* buildList(int n, int min, int max) {
    int* random = (int*)malloc(sizeof(int)*(n + 1));
    *random = 0;
    for (int i = 1;i <= n; i++) {
        random++
        *random = rand() % max + min; // 범위 내의 랜덤값 저장
    }
    return random - n;
}

void writeList(int* L) {
    L++;
    while (*L != '\0') { // 리스트 모두 출력
        printf(" %d", *L);
        L++;
    }
    printf("\n");
}

int sizeofList(int* L) {
    int size = 0;
    int* temp = L;
    temp++;
    while (*temp != 0) { // size 체크
        size++;
        temp++;
    }
    return size;
}

void minHeapify(int* L, int i, int len) {
    if (i * 2 <= len) { //자식이 있다면
        int minKey = i * 2;
        if (i * 2 + 1 <= len) //우측 자식이 있는경우 둘 중 더 작은 값 삽입
            minKey = L[i * 2] < L[(i * 2) + 1] ? i * 2 : (i * 2) + 1;

        if (L[i] > L[minKey]) { //swap 후 재귀
            int temp = L[i];
            L[i] = L[minKey];
            L[minKey] = temp;
            minHeapify(L, minKey, len);
        }
    }
}

void buildMinheap(int* L, int len) {
    for (int i = len / 2; i >= 0; i--) {
        minHeapify(L, i, len);
    }
}

void copylist(int* A, int* B, int len) {
    for (int i = 1; i <= len; i++) {
        B[i] = A[i];
    }
}
