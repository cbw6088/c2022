#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct stack{
    char arr[MAX_SIZE];
    int top;
}Stack;

void init(Stack *st);
int isEmpty(Stack *st);
int isFull(Stack *st);
int priority(char elem);
int compareStack(char op1, char op2);
void convert(char *str);
void push(Stack *st, char elem);
char pop(Stack *st);
char peek(Stack *st);
void print(Stack *prev, Stack *next);

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        char str[MAX_SIZE] = {};
        scanf("%s", str);
        convert(str);
    }
    return 0;
}

void init(Stack *st){
    st->top = -1;
}

int isEmpty(Stack *st){
    if(st->top == -1) return 1;
    else return 0;
}

int isFull(Stack *st){
    if(st->top == MAX_SIZE) return 1;
    else return 0;
}

int priority(char elem){
    if(elem == '!' || elem == '1' || elem == '2') return 6;
    else if(elem == '*' || elem == '/') return 5;
    else if(elem == '+' || elem == '-') return 4;
    else if(elem == '>' || elem == '<') return 3;
    else if(elem == '&') return 2;
    else if(elem == '|') return 1;
    return 0;
}

int compareStack(char op1, char op2){
    if(priority(op1) >= priority(op2)) return 1;
    else return 0;
}

void convert(char *str){
    int len = strlen(str);
    Stack nowStack, tmpStack;
    init(&nowStack);
    init(&tmpStack);
    for(int i = 0; i <= len; i++){
        // 값의 연산자인지 값의 부호인지 구분
        if(str[i] == '+' || str[i] == '-'){
            // 값의 부호인 경우 ex) -A + B
            if(i == 0)
                str[i] = str[i] == '+' ? '1' : '2';
            // 값의 연산자인 경우 ex) A + B
            else if(!(str[i - 1] >= 'A' && str[i - 1] <= 'Z') && str[i - 1] != ')')
                str[i] = str[i] == '+' ? '1' : '2';
        }

        if(str[i] >= 'A' && str[i] <= 'Z')
            push(&nowStack, str[i]);
        // 열린 괄호인 경우
        else if(str[i] == '('){
            push(&tmpStack, str[i]);
        }
        // 닫힌 괄호인 경우
        else if(str[i] == ')'){
            while(1){
                char operator;
                // 스택이 빈 경우
                if(isEmpty(&tmpStack)) break;
                operator = pop(&tmpStack);
                // 열린 괄호가 나오면 반복문 종료
                if(operator == '(') break;
                // 우선순위가 높은 P와 M 따로 처리
                else if(operator == '1') push(&nowStack, '+');
                else if(operator == '2') push(&nowStack, '-');
                else push(&nowStack, operator);
            }
        }
        else if(str[i] == '&' || str[i] == '|'){
            while(!isEmpty(&tmpStack) && compareStack(peek(&tmpStack), str[i]) > 0){
                char operator = pop(&tmpStack);
                // 우선순위가 높은 P와 M 따로 처리
                if(operator == '1') push(&nowStack, '+');
                else if(operator == '2') push(&nowStack, '-');
                else push(&nowStack, operator);
            }
            push(&tmpStack, str[i]);
            push(&tmpStack, str[i]);
            // 같은 기호 두 번 반복 함으로 i + 1
            i += 1;
        }
        else{
            while(!isEmpty(&tmpStack) && compareStack(peek(&tmpStack), str[i]) > 0){
                char operator = pop(&tmpStack);
                if(operator == '1') push(&nowStack, '+');
                else if(operator == '2') push(&nowStack, '-');
                else push(&nowStack, operator);
            }
            push(&tmpStack, str[i]);
        }
    }
    print(&nowStack, &tmpStack);
}

void push(Stack *st, char elem){
    st->top += 1;
    st->arr[st->top] = elem;
}

char pop(Stack *st){
    char tmp = st->arr[st->top];
    st->top -= 1;
    return tmp;
}

char peek(Stack *st){
    return st->arr[st->top];
}

void print(Stack *prev, Stack *next){
    int idx = 0;
    for(int i = 0; i <= prev->top; i++)
        printf("%c", prev->arr[i]);
    printf("\n");
}

/*
5
A*B+C+(D+E)*F
A+B*C
A/B-C+D*E-F*G
A+(B*C+D)*E
A&&B||C||!(E>F)
*/