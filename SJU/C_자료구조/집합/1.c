#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *getNode(int value);
void addNode(Node *H, int pos, int value);
int compareNode(Node *A_p, Node *B_p, int A, int B);
int minNode(Node *A_p, int A, int cnt);

int main(){
    int A, B, value;
    scanf("%d", &A);
    Node *A_p = (Node*)malloc(sizeof(Node));
    A_p->next = NULL;
    for(int i = 0; i < A; i++){
        scanf("%d", &value);
        addNode(A_p, i, value);
    }
    scanf("%d", &B);
    Node *B_p = (Node*)malloc(sizeof(Node));
    B_p->next = NULL;
    for(int i = 0; i < B; i++){
        scanf("%d", &value);
        addNode(B_p, i, value);
    }
    printf("%d", compareNode(A_p, B_p, A, B));
    
    return 0;
}

Node *getNode(int value){ // 노드 생성 및 초기화 함수
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node *H, int pos, int value){ // 노드 연결 함수
    Node *node = (Node*)malloc(sizeof(Node));
    node = getNode(value);
    Node *p = H;
    for(int i = 0; i < pos; i++){
        p = p->next;
    }
    p->next = node; 
}

int compareNode(Node *A_p, Node *B_p, int A, int B){ // 비교 함수
    int min = 0, cnt = 0, A_idx = -1, B_idx = -1;
    if(A == 0) // 예외 처리
        return 0;
    Node *A_tmp = A_p->next;
    while(++A_idx < A){
        if(A_idx == A || B_idx == B) break; // 종료 조건
        B_idx = -1;
        Node *B_tmp = B_p->next;
        while(++B_idx < B){
            if(A_tmp->data == B_tmp->data){ // 같을 경우
                cnt++; // 같은 경우의 개수 카운트
                break;
            }
            B_tmp = B_tmp->next;
        }
       A_tmp = A_tmp->next;
    }
    if(cnt == A) // A가 B에 모두 포함되어 있는 경우
        return 0;
    return minNode(A_p, A, cnt);
}

int minNode(Node *A_p, int A, int cnt){
    Node *tmp = A_p->next;
    int min = tmp->data;
    for(int i = 0; i < cnt; i++)
        tmp = tmp->next;
    min = tmp->data;
    return min;
}
/*
3
4 6 13
6
1 3 4 6 8 13
결과 -> 0

3
7 10 53
4
7 10 15 45
결과 -> 53
*/