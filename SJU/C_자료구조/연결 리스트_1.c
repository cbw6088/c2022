#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList{ // 노드 세팅
    int data;
    struct LinkedList *next;
}List;

typedef struct HEAD{ // 최초 헤드 세팅
    List *head;
}Head;

void init(Head *H){ // 초기값
    H->head = NULL;
}

void insert_first(Head *H, int value){
    List *node = (List*)malloc(sizeof(List)); // default
    node->data = value; // default
    node->next = NULL; 
    List *p = H->head; // 헤드와 같은 곳을 가리키는 포인트 // default
    H->head = node;
    node->next = p;
}

void insert(Head *H, int value, int pos){
    List *node = (List*)malloc(sizeof(List)); // default
    node->data = value; // default
    node->next = NULL; // default
    List *p = H->head; // default
    if(pos == 1) // 위치가 1이면 최초
        insert_first(H,value);
    else{
        for(int i=2; i<pos; i++)
            p = p->next; // p 한칸 이동
        node->next = p->next;
        p->next = node;
    }
}

void delete_first(Head *H){
    List *p = H->head; // default
    H->head = p->next;
    free(p);
}

void delete(Head *H, int pos){
    List *p = H->head; // default
    if(pos == 1)
        delete_first(H);
    else{
        for(int i=2; i<pos; i++)
            p = p->next; // 해당 위치의 한칸 전 까지 이동
        
        List *q = p->next; // p 다음 으로 지정 (지우는 부분 전 위치와 후 위치 두 개 필요)
        p->next = q->next; // 삭제 할 부분을 제외하고 연결
        free(q); // 해당 부분 삭제
    }
}

void print(Head *H){
    List *p = H->head;
    while(p != NULL){ // 최초 head 부터 NULL이 될 때 까지
        printf("%d ----->",p->data);
        p = p->next;
    }
    printf("\n");
}

int find(Head *H, int value){ // 해당 값이 있는지 참 거짓 판단
    List *p = H->head; // default
    while(p != NULL){
        if(p->data == value) // 해당 값이 있으면 1 반환
            return 1;
        else 
            p = p->next; 
    }
    return 0;
}

int main(void){
    Head H; 
    List L; 
    init(&H);
    insert_first(&H,5);
    printf("%d\n",find(&H,5));
    print(&H);
    insert(&H,4,1);
    print(&H);
    insert(&H,3,2);
    print(&H);
    delete(&H,3);
    print(&H);
    printf("%d\n",find(&H,5));
    
    return 0;
}