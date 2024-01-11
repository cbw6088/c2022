#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 배열의 크기 및 값이 들어간 위치 전역변수로 선언
int N;
int top;

int Empty_check();
int Full_check();
void push(char *stack, char value);
char pop(char *stack);
char peek(char *stack);
void duplicate(char *stack);
void upRotate(char *stack, int n);
void downRotate(char *stack, int n);
void print(char *stack);

int main(){
    int n, cnt;
    scanf("%d %d", &N, &cnt);
    getchar();
    char str[10] = {};
    char value;
    char *stack = (char*)malloc(sizeof(char) * (N + 1));
    top = - 1; // top = -1 부터 시작
    for(int i = 0; i < cnt; i++){
        scanf("%s", str);
        getchar();
        // 연산
        if(strcmp(str, "PUSH") == 0){
            scanf("%c", &value);
            getchar();
            if(Full_check()) printf("Stack FULL\n");
            else push(stack, value);
        }
        else if(strcmp(str, "POP") == 0){
            if(Empty_check()) printf("Stack Empty\n");
            else pop(stack);
        }
        else if(strcmp(str, "PEEK") == 0){
            if(Empty_check()) printf("Stack Empty\n");
            else printf("%c\n", peek(stack));
        }
        else if(strcmp(str, "DUP") == 0){
            if(Full_check()) printf("Stack FULL\n");
            else if(Empty_check()) printf("Stack Empty\n");
            else duplicate(stack);
        }
        else if(strcmp(str, "UpR") == 0){
            scanf("%d", &n);
            getchar();
            upRotate(stack, n);
        }
        else if(strcmp(str, "DownR") == 0){
            scanf("%d", &n);
            getchar();
            downRotate(stack, n);
        }
        else if(strcmp(str, "PRINT") == 0){
            print(stack);
        }
    }
    free(stack);
    return 0;
}

int Full_check(){ // 가득 찬 경우
    return top == N - 1;
}

int Empty_check(){ // 빈 경우
    return top == -1;
}

void push(char *stack, char value){
    stack[++top] = value; // top를 올리며 값 저장
}

char pop(char *stack){
    return stack[top--]; // 가장 위의 값 반환하고 top개수 하나 줄이기
}

char peek(char *stack){
    return stack[top]; // 가장 위에 값 반환
}

void duplicate(char *stack){
    char tmp = pop(stack); // pop의 반환 값을 받은 후
    push(stack, tmp); // push 두 번 연산
    push(stack, tmp);
}

void upRotate(char *stack, int n){
    if(n > top + 1) return ; // 종료 조건
    char tmp;
    for(int i = 0; i < n - 1; i++){ // 해당 범위 까지 스왑
        tmp = stack[top - i];
        stack[top - i] = stack[top - 1 - i];
        stack[top - 1 - i] = tmp;
    }
}

void downRotate(char *stack, int n){
    if(n > top + 1) return ; // 종료 조건
    char tmp;
    for(int i = 1; i < n; i++){ // 해당 범위 까지 스왑
        tmp = stack[top - n + i];
        stack[top - n + i] = stack[top - n + i + 1];
        stack[top - n + i + 1] = tmp;
    }
}

void print(char *stack){
    for(int i = top; i >= 0; i--)
        printf("%c", stack[i]);
    printf("\n");
}

/*
4
10
POP
PUSH s
PUSH t
PUSH a
PUSH r
PRINT
UpR 3
PRINT
PUSH s
PEEK
*/