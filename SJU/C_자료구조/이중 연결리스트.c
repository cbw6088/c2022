#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLinkedList{
    int data;
    struct DoublyLinkedList *next;
    struct DoublyLinkedList *prev;
}DL;

typedef struct HEAD{
    DL *head;
}Head;

void init(Head *H){
    H->head = NULL;
}

int posError(Head *H, int pos){
    int cnt=1;
    DL *p = H->head;
    while(p != NULL){
        p = p->next;
        cnt++;
    }

    if(pos <= 0 || pos > cnt)
        return 1;
    else   
        return 0;
}

void insert_first(Head *H, int value){
    DL *node = (DL*)malloc(sizeof(DL));
    DL *p = H->head;
    node->data = value;
    node->prev = NULL;
    node->next = NULL;

    if(H->head == NULL){
        H->head = node;
        node->prev = H->head;
    }
    else{
        H->head = node;
        node->prev = H->head;
        p->prev = node;
        node->next = p;
    }
}

void insert(Head *H, int value, int pos){
    if(posError(H,pos)) // 삽입이 가능 확인
        printf("POS_ERROR!!\n");
    else{
        if(pos == 1)
            insert_first(H,value);
        else{
            DL *node = (DL*)malloc(sizeof(DL));
            DL *p = H->head;
            node->data = value;
            node->prev = NULL;
            node->next = NULL;

            for(int i=2; i<pos; i++){
                p = p->next;
            }
            node->prev = p; // 순서 중요!
            node->next = p->next; // 순서 중요!
            p->next->prev = node; // 순서 중요!
            p->next = node; // 순서 중요!
        }
    }
}

void delete_first(Head *H){
    DL *p = H->head;
    if(H->head == NULL)
        printf("DELETE ERROR!!\n");
    else{
        if(p->next != NULL){
            p->next->prev = H->head;
            H->head = p->next;
            free(p);
        }
        else{
            init(H); // head를 NULL로 만다는 행위
            free(p);
        }
    }
}

void delete_last(Head *H){
    DL *p = H->head;
    while(p->next != NULL){ // next위치 중요
        p = p->next;
    }
    p->prev->next = NULL;
    free(p);
}

void delete(Head *H,int pos){
    int cnt = 1;
    if(posError(H,pos))
        printf("POS_ERROR!!\n");
    else{
        if(pos == 1)
            delete_first(H);
        else{
            DL *p = H->head;
            for(int i=2; i<=pos; i++){
                p = p->next;
                cnt++;
            }
            if(pos == cnt){
                delete_last(H);
            }
            else{
                DL *q = p->next;
                p->prev->next = q;
                q->prev = p->prev;
                free(p);
            }
        }
    }

}

void print(Head *H){
    DL *p = H->head;
    while(p != NULL){
        printf("%d -----> ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    Head H;
    init(&H);
    insert_first(&H,3);
    insert_first(&H,4);
    print(&H);
    getchar();
    insert(&H,5,2);
    insert(&H,6,3);
    print(&H);
    getchar();
    delete_first(&H);
    print(&H);
    getchar();
    delete(&H,2);
    print(&H);
    getchar();
    delete(&H,2);
    print(&H);
    delete(&H,1);
    print(&H);
    return 0;
}