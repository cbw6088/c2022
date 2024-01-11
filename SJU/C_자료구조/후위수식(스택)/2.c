#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct stack{
    int arr[MAX_SIZE];
    int top;
}Stack;

void init(Stack *st);
int isEmpty(Stack *st);
int isFull(Stack *st);
void push(Stack *st, char elem);
void convert(char *str);
char pop(Stack *st);
char peek(Stack *st);

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

void convert(char *str){
    int prev = 0, next = 0;
    Stack st;
    init(&st);
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(str[i] >= '0' && str[i] <= '9')
            push(&st, str[i] - '0');
        else{
            if(isEmpty(&st)) break;
            prev = pop(&st);
            next = pop(&st);
            if(isFull(&st)) break;
            if(str[i] == '*')
                push(&st, prev * next);
            else if(str[i] == '/')
                push(&st, next / prev);
            else if(str[i] == '+')
                push(&st, prev + next);
            else if(str[i] == '-')
                push(&st, next - prev);
        }
    }
    printf("%d\n", st.arr[st.top]);
}

int isEmpty(Stack *st){
    if(st->top == -1) return 1;
    return 0;
}

int isFull(Stack *st){
    if(st->top == 100) return 1;
    return 0;
}

void push(Stack *st, char elem){
    st->top += 1;
    st->arr[st->top] = elem;
}

char pop(Stack *st){
    char tmp = st->arr[st->top];
    st->arr[st->top] = '\0';
    st->top -= 1;
    return tmp;
}

char peek(Stack *st){
    return st->arr[st->top];
}

/*
4
53*2+63+2*+
234*+
72/3-42*+21*-
923*1+2*+
*/