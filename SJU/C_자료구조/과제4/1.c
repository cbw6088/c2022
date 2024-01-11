#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXSIZE 1100000
#define MILLIONSIZE 1000000

int* mainQ; // 메인 Queue
int Check;

int isEmpty(int front, int rear);
int isFull(int rear);
int topQueue(int* Queue, int rear);
void enqueue(int* Queue, int* rear, int item);
void enqueueMillion(int* Queue, int* rear);
int dequeue(int* Queue, int* front);

int main() {
    double cputime;
    clock_t start;
    char str[2] = {0};
    int item = 0, mainRear = 0, mainFnt = 0, subRear = 0, subFnt = 0;
    mainQ = (int*)malloc(sizeof(int) * MAXSIZE);

    while (1) {
        scanf("%s", str);
        if (strcmp(str, "S") == 0) { // size 출력
            srand(time(NULL));
            start = clock(); // start 

            if (isEmpty(mainFnt, mainRear)) printf("Empty (0), "); // 비어있을 경우
            else printf("Nonempty (%d), ", mainRear); //비어있지 않을 경우 현재 size 출력

            cputime = (double)(clock() - start) / CLOCKS_PER_SEC; //end
            printf("cputime = %lf\n", cputime);
        }
        else if (strcmp(str, "t") == 0) { // 스택의 top 출력
            srand(time(NULL));
            start = clock(); // start 

            if (isEmpty(mainFnt, mainRear)) printf("Empty Stack Exceptio!! (0), "); // 비어있을 경우
            else printf("%d (%d), ", topQueue(mainQ, mainRear), mainRear - mainFnt); // top과 크기 출력

            cputime = (double)(clock() - start) / CLOCKS_PER_SEC; //end
            printf("cputime = %lf\n", cputime);
        }
        else if (strcmp(str, "p") == 0) {
            srand(time(NULL));
            start = clock(); // start 

            char* mainStr = (char*)malloc(sizeof(char) * MAXSIZE); // 입력 받을 문자열 선언
            char* subStr = (char*)malloc(sizeof(char) * MAXSIZE);
            scanf("%[^\n]s", subStr); // 정수 값 문자열로 입력
            mainStr = strtok(subStr, " "); // 입력 받은 문자열 공백 기준으로 자르기
            while (mainStr != NULL) {
                item = atoi(mainStr); // 입력받은 문자열 정수로 저장
                enqueue(mainQ, &mainRear, item); // 메인 스택에 값 저장
                mainRear += 1; // rear 증가
                if (isFull(mainRear)) break;
                mainStr = strtok(NULL, " "); // 입력 받은 문자열 다음 공백 뒤 문자로 이동
            }
            printf("OK (%d), ", mainRear - mainFnt); // 출력
            free(mainStr); // 문자열 메모리 제거
            free(subStr);
            cputime = (double)(clock() - start) / CLOCKS_PER_SEC; //end
            printf("cputime = %lf\n", cputime);
        }
        else if (strcmp(str, "P") == 0) {
            srand(time(NULL));
            start = clock(); // start 

            enqueueMillion(mainQ, &mainRear); // 함수 이동
            printf("OK (%d), ", mainRear - mainFnt); // 사이즈 출력

            cputime = (double)(clock() - start) / CLOCKS_PER_SEC; //end
            printf("cputime = %lf\n", cputime);
        }
        else if (strcmp(str, "o") == 0) {
            srand(time(NULL));
            start = clock(); // start 

            int* subQ = (int*)malloc(sizeof(int) * MAXSIZE); // 임의로 담을 큐 선언
            if (isEmpty(mainFnt, mainRear)) printf("Empty Stack Exception!! (0), "); // 가득 차있을 경우
            else {
                while (mainRear != mainFnt + 1) { // 한 개 남을 때 까지 반복
                    enqueue(subQ, &subRear, dequeue(mainQ, &mainFnt)); // 서브큐에 메인큐 값을 순서대로 저장
                    subRear += 1; // rear 증가
                    Check = 1; // 체크
                }
                printf("%d (%d), ", dequeue(mainQ, &mainFnt), subRear - subFnt); // 현재 메인큐에 남아있는 값 출력 및 pop
                if (Check == 1) { // 위의 while을 방문 했을 경우
                    mainRear = 0; // 메인큐는 비어있으므로 rear, front 모두 초기화
                    mainFnt = 0;
                    Check = 0; // 체크 초기화
                }
                while (subRear != subFnt) { // 서브큐를 한 번 반복
                    enqueue(mainQ, &mainRear, dequeue(subQ, &subFnt)); // 메인큐에 서브큐 값 저장
                    mainRear += 1; // rear 증가
                }
                subRear = 0; // 서브큐를 모두 사용했으므로 초기화
                subFnt = 0;
            }
            free(subQ); // 서브큐 메모리 제거

            cputime = (double)(clock() - start) / CLOCKS_PER_SEC; //end
            printf("cputime = %lf\n", cputime);
        }
        else if (strcmp(str, "q") == 0) break; // 종료 조건
    }
    return 0;
}

int isEmpty(int front, int rear) {
    if (front == rear) return 1; // front와 rear이 같으면 빈 경우
    else return 0;
}

int isFull(int rear) {
    if (rear == MAXSIZE) return 1; // 배열의 최대 범위만큼 찬 경우
    else return 0;
}

int topQueue(int* Queue, int rear) {
    return Queue[rear - 1]; // 가장 위의 top값 반환
}

void enqueue(int* Queue, int* rear, int item) {
    Queue[*rear] = item; // 해당 큐에 값 저장
}

void enqueueMillion(int* Queue, int* rear) {
    int random;
    for (int i = 1; i <= MILLIONSIZE; i++) { // push 100만번 반복
        random = rand() % 90 + 10; // 1000 ~ 9999 사이의 난수
        enqueue(Queue, rear, random); //반복하며 랜덤 값 push
        *rear += 1; // rear 증가
    }
}

int dequeue(int* Queue, int* front) {
    *front += 1; // front 증가
    return Queue[*front - 1]; // 증가 전 기존의 값 반환
}