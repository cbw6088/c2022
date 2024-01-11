#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
    char data[1001];
    int top;
}Stack;

void initStack(Stack *stack);
void push(Stack *stack, char value);
char pop(Stack *stack);

int main(){
    Stack stack;
    initStack(&stack);
    char arr[1001] = {};
    gets(arr);
    int cnt = strlen(arr), flag = 0, result = 0;
    char check;
    for(int i = 0; i < cnt; i++){
        // 여는 괄호일 경우 개수를 세면서 값 저장
        if(arr[i] == '{' || arr[i] == '[' || arr[i] == '('){
            result++;
            push(&stack, arr[i]);
        }
        // 닫는 괄호일 경우 개수를 세면서 여는 괄호와 짝이 맞는지 확인
        if(arr[i] == '}' || arr[i] == ']' || arr[i] == ')'){
            result++;
            check = pop(&stack);
            if(arr[i] == '}'){
                if('{' != check)
                    flag = 1;
            }
            else if(arr[i] == ']'){
                if('[' != check)
                    flag = 1;
            }
            else if(arr[i] == ')'){
                if('(' != check)
                    flag = 1;
            }
        }
    }
    // 반복문이 끝났는데 괄호의 개수가 맞지 않는 경우
    if(stack.top != -1) flag = 1;
    // flag == 1은 에러일 경우
    if(flag == 1) printf("Wrong_%d\n", result);
    else printf("OK_%d\n", result);
    return 0;
}

void initStack(Stack *stack){
    stack->top = -1;
}

void push(Stack *stack, char value){
    stack->top += 1;
    stack->data[stack->top] = value;
}

char pop(Stack *stack){
    char tmp = stack->data[stack->top];
    stack->top -= 1;
    return tmp;
}