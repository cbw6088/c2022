#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 1100000
#define MILLIONSIZE 1000000

/*스택 구조체 선언*/
typedef struct stack {
    int top;
    int* data;
}Stack;

/*전역변수 선언*/
int minCheck;
int minSize;
int firstSize;
Stack stackFirst;
Stack stackSecond;

/*원형함수 선언*/
int fullCheck(int size);
int emptyCheck(int size);
void push(int value);
void pushMillion();
void pop();
void popMillion();
int findMin();

int main() {
    /*변수 선언*/
    char ch;
    int value, min;
    double cputime;
    clock_t start;
    minCheck = 0;
    minSize = 2;
    firstSize = 1;
    stackFirst.top = 0;
    stackSecond.top = 0;
    /*스택 공간 할당*/
    stackFirst.data = (int*)malloc(sizeof(int) * MAXSIZE);
    stackSecond.data = (int*)malloc(sizeof(int));
    /*종료조건(q) 입력 전까지 혹은 스택 에러까지 무한 루프*/
    while (1) {
        scanf("%c", &ch);
        getchar();
        if (ch == 'p') { // push
            /*cputime을 세기 위한 코드*/
            srand(time(NULL));
            start = clock(); // start 

            scanf("%d", &value);
            getchar();
            push(value);

            cputime = (double)(clock() - start) / CLOCKS_PER_SEC; //end
            printf("push %d (%d), cputime = %lf\n", value, stackFirst.top, cputime);
        }
        else if (ch == 'P') { // pushMillion
            srand(time(NULL));
            start = clock(); // start 

            pushMillion();

            cputime = (double)(clock() - start) / CLOCKS_PER_SEC; //end
            printf("pushMillion (%d), cputime = %lf\n", stackFirst.top, cputime);
        }
        else if (ch == 'o') { // pop
            srand(time(NULL));
            start = clock(); // start 

            pop();

            cputime = (double)(clock() - start) / CLOCKS_PER_SEC; //end
            printf("pop %d (%d), cputime = %lf\n", stackFirst.data[stackFirst.top + 1], stackFirst.top, cputime);
        }
        else if (ch == 'O') { // popMillion
            srand(time(NULL));
            start = clock(); // start 

            popMillion();

            cputime = (double)(clock() - start) / CLOCKS_PER_SEC; //end
            printf("popMillion (%d), cputime = %lf\n", stackFirst.top, cputime);
        }
        else if (ch == 'f') { // findMin
            srand(time(NULL));
            start = clock(); // start

            min = findMin();

            cputime = (double)(clock() - start) / CLOCKS_PER_SEC; //end
            printf("min %d (%d), cputime = %lf\n", min, stackFirst.top, cputime);
        }
        else if (ch == 'q') {
            free(stackFirst.data);
            free(stackSecond.data);
            break; // 종료 조건
        }
    }
    return 0;
}

int fullCheck(int size) {
    /*최대 사이즈인 경우*/
    if (size == MAXSIZE) return 1;
    else return 0;
}

int emptyCheck(int size) {
    /*최소 사이즈인 경우*/
    if (size == 0) return 1;
    else return 0;
}


void push(int value) {
    if (fullCheck(stackFirst.top)) { // 스택이 가득 찬 경우
        firstSize += 1;
        stackFirst.data = (int*)realloc(stackFirst.data, (sizeof(int) * (MAXSIZE + firstSize))); // 스택 사이즈 1칸 증가
    }
    stackFirst.data[++stackFirst.top] = value;
    if (minCheck == 0) { // 최소값 지정이 안된 경우 최초의 값을 최소값으로 지정
        stackSecond.data[++stackSecond.top] = value;
        minCheck += 1;
    }
    if (stackSecond.data[stackSecond.top] >= value) { // 최소값 보다 더 작거나 같은 값인 경우
        minSize += 1;
        stackSecond.data = (int*)realloc(stackSecond.data, (sizeof(int) * minSize)); // 동적할당 사이즈 1칸 증가
        stackSecond.data[++stackSecond.top] = value; // 최소값 설정
    }
}

void pushMillion() {

    int random;
    for (int i = 1; i <= MILLIONSIZE; i++) { // push 100만번 반복
        random = rand() % 9000 + 1000; // 1000 ~ 9999 사이의 난수
        push(random);
        if (minCheck == 0) { // 최소값 지정이 안된 경우 최초의 값을 최소값으로 지정
            stackSecond.data[++stackSecond.top] = random;
            minCheck += 1;
        }
        if (stackSecond.data[stackSecond.top] >= random) { // 최소값 보다 더 작거나 같은 값인 경우
            minSize += 1;
            stackSecond.data = (int*)realloc(stackSecond.data, (sizeof(int) * minSize)); // 동적할당 사이즈 1칸 증가
            stackSecond.data[++stackSecond.top] = random; // 최소값 설정
        }
    }
}

void pop() {
    if (emptyCheck(stackFirst.top)) return ; // 스택이 빈 경우
    if (stackFirst.data[stackFirst.top] == stackSecond.data[stackSecond.top]) stackSecond.top -= 1; // pop이 되는 stack가 최소값과 같은 경우 최소값 stack도 한 칸 제거
    stackFirst.top -= 1; // 스택 한 칸 제거
}

void popMillion() {
    for (int i = 1; i <= MILLIONSIZE; i++) pop(); // pop 100만번 반복
}

int findMin() {
    return stackSecond.data[stackSecond.top]; // 최소값 반환
}