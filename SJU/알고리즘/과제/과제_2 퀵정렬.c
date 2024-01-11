#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// 전역 변수 정의
int n = 100000; 
int Limits[4] = { 1, 100, 500, 1000 };
int Limit;
char modes[4][100] = { "deterministic1", "deterministic3", "randomized1", "randomized3" }; 
char* mode;
double proccesTime; 

// 함수 원형 선언
int* createArray();
void quickSort(int* arr, int N); 
void checkArray(int* arr); 
void rQuickSort(int* A, int left, int right);
int findPivot(int* A, int left, int right);
int findIndexOfMedianOfThree(int* A, int a, int b, int c); 
void copyArray(int* a, int* b, int size); 
void insertionSort(int* arr, int N);
void printCPUTime();
int inplacePartition(int* A, int left, int right, int key); 
void swap(int* arr, int n1, int n2);  

int main() {
    int* A = NULL;
    A = createArray();
    // 출력 틀
    printf("Limit          결정적1        결정적3         무작위1        무작위3\n");
    for (int i = 0; i < 4; i++) {
        Limit = Limits[i];
        printf("%4.d  ", Limit);
        for (int j = 0; j < 4; j++) {
            mode = modes[j];
            int* cpArray = (int*)malloc(n * sizeof(int));
            copyArray(A, cpArray, n);
            clock_t startTime = clock();
            quickSort(cpArray, n);
            clock_t endTime = clock();
            proccesTime = (double)(endTime - startTime);
            printCPUTime();
            free(cpArray);
        }
        printf("\n");
    }
    free(A);
    return 0;
}

int* createArray() {
    int* Arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        Arr[i] = rand() % n + 1; // 배열 요소를 1부터 n까지의 난수로 초기화
    }
    return Arr;
}

void checkArray(int* arr) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void quickSort(int* arr, int N) {
    rQuickSort(arr, 0, N - 1);
    if (Limit > 1) {
        insertionSort(arr, N);
    }
    return;
}

void rQuickSort(int* A, int left, int right) {
    // 분할 크기가 Limit를 넘어서면 퀵 정렬을 수행
    if ((right - left) >= Limit) {
        int key = findPivot(A, left, right);
        int pos = inplacePartition(A, left, right, key);
        rQuickSort(A, left, pos);
        rQuickSort(A, pos + 1, right);
    }
}

int findIndexOfMedianOfThree(int* A, int a, int b, int c) {
    if ((A[b] >= A[a] && A[c] <= A[a]) || (A[b] <= A[a] && A[c] >= A[a]))
        return a;
    if ((A[a] >= A[b] && A[c] <= A[b]) || (A[a] <= A[b] && A[c] >= A[b]))
        return b;
    else
        return c;
}

int findPivot(int* A, int left, int right) {
    if (strcmp(mode, "deterministic1") == 0) {
        return right;  // 오른쪽 끝 요소를 피봇으로 선택
    }
    if (strcmp(mode, "randomized1") == 0) {
        return (rand() % (right + 1 - left)) + left;  // 무작위로 피봇 선택
    }
    if (right - left == 1) {
        return left;  // 두 요소 중 작은 값을 피봇으로 선택
    }
    int a = 0;
    int b = 0;
    int c = 0;
    if (strcmp(mode, "deterministic3") == 0) {
        a = left;
        b = (left + right) / 2;
        c = right;
    }
    else if (strcmp(mode, "randomized3") == 0) {
        a = (rand() % (right + 1 - left)) + left;
        b = (rand() % (right + 1 - left)) + left;
        c = (rand() % (right + 1 - left)) + left;
    }
    int idx = findIndexOfMedianOfThree(A, a, b, c);
    return idx;
}

void copyArray(int* a, int* b, int size) {
    for (int i = 0; i < size; i++) {
        b[i] = a[i];
    }
}

void insertionSort(int* arr, int N) {
    int tmp, idx;
    for (int i = 1; i < N; i++) {
        idx = i;
        // 현재 원소를 정렬된 부분에 삽입하는 과정
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] < arr[j])
                idx = j;
        }
        tmp = arr[i];
        // 삽입 위치에 맞게 배열을 이동
        for (int k = i; k > idx; k--)
            arr[k] = arr[k - 1];
        arr[idx] = tmp;
    }
}

void printCPUTime() {
    // 현재 실행 모드에 따라 CPU 실행 시간을 출력
    if (strcmp(mode, "deterministic1") == 0) {
        printf("        %10.6lf  ", proccesTime);
    }
    else if (strcmp(mode, "deterministic3") == 0) {
        printf("  %10.6lf  ", proccesTime);
    }
    else if (strcmp(mode, "randomized1") == 0) {
        printf("  %10.6lf  ", proccesTime);
    }
    else if (strcmp(mode, "randomized3") == 0) {
        printf("  %10.6lf  ", proccesTime);
    }
}

int inplacePartition(int* A, int left, int right, int key) {
    int pivot = A[key];
    int i = left - 1;
    int j = right + 1;
    swap(A, left, key);

    while (1) {
        while (A[++i] < pivot) continue; // pivot보다 작은 요소를 찾을 때까지 i를 증가시킴
        while (A[--j] > pivot) continue; // pivot보다 큰 요소를 찾을 때까지 j를 감소시킴
        if (i < j) swap(A, i, j); // i가 j보다 작으면 두 요소를 교환
        else return j;  // 파티션 포인트 반환
    }
}

void swap(int* arr, int n1, int n2) { // 스왑
    int tmp = arr[n1];
    arr[n1] = arr[n2];
    arr[n2] = tmp;
}
