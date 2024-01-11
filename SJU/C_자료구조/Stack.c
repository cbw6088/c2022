// 연결리스트를 이용한 스택
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int data;
    struct Stack *next;
}stack; // 스텍 구조 형성

typedef struct Head{
    stack *head;
}Head; // 헤드 형성

void init(Head *H){
    H->head = NULL;
} // 헤드 초기화

int empty(Head *H){
    if(H->head == NULL) // 최초의 헤드일 경우
        return 1;
    else    
        return 0;
}

void push(Head *H, int value){
    stack *node = (stack*)malloc(sizeof(stack));
    node->data = value; 
    node->next = NULL; 
    if(H->head == NULL){ // 맨 처음인 경우엔 노드와 연결
        stack *p = H->head;
        H->head = node;
	}
    else{ // 처음이 아니면 포인트의 위치를 마지막으로 이동 후 노드와 연결
        stack *p = H->head;
        while(p->next != NULL)
            p = p->next;
            
        p->next = node;
    }
}

void pop(Head *H){
    if(empty(H))
        printf("Stact is Empty!!");
    else{
        stack *p = H->head;
		if(p->next == NULL){ // 노드가 하나 남아있을 경우
			free(p);
			H->head = NULL;
		}
		else{
        	while(p->next->next != NULL)
            	p = p->next; // 포인트는 지울 위치의 한 칸 전
		
			stack *q = p->next; // 새로운 포인트는 지울 위치
        	free(q);
			p->next = NULL;
		}
    }
}

int peek(Head *H){
    if(empty(H)){
		printf("Stact is Empty!!");
		return 0;
	}
    else{
        stack *p = H->head;
        while(p->next != NULL)
            p = p->next;
		
        return p->data;
    }
}

void print(Head *H){
    if(empty(H))
        printf("Stact is Empty!!\n");
    else{
        stack *p = H->head;
        while(p != NULL){
			printf("%d -----> ",p->data); // 순차적으로 출력
            p = p->next;
        }
		printf("\n"); 
    }
}

int main(){
    Head H;
    init(&H);
	print(&H);
    push(&H,3);
	push(&H,5);
	print(&H);
	pop(&H);
	print(&H);
	push(&H,7);
	push(&H,9);
	print(&H);
	pop(&H);
	print(&H);
	pop(&H);
	print(&H);
	pop(&H);
	print(&H);
    return 0;
}