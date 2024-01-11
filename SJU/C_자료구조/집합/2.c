#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *getNode(int value);
void addNode(Node *H, int pos, int value);
Node *unionCal(Node *aNode, Node *bNode, int A, int B);
Node *intersectCal(Node *aNode, Node *bNode, int A, int B);
void printNode(Node *uniNode);

int main(){
    int A, B, value;
    // 최초 초기화
    Node *aNode = getNode(0);
    Node *bNode = getNode(0);
    scanf("%d", &A);
    for(int i = 0; i < A; i++){
        scanf("%d", &value);
        addNode(aNode, i, value);
    }
    scanf("%d", &B);
    for(int i = 0; i < B; i++){
        scanf("%d", &value);
        addNode(bNode, i, value);
    }
    Node *uniNode = unionCal(aNode, bNode, A, B);
    printNode(uniNode);
    Node *interNode = intersectCal(aNode, bNode, A, B);
    printNode(interNode);
    return 0;
}

Node *getNode(int value){ // 노드 생성 및 초기화 함수
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node *H, int pos, int value){ // 노드 연결 함수
    Node *newNode = getNode(value);
    Node *p = H;
    for(int i = 0; i < pos; i++)
        p = p->next;
    p->next = newNode;
}

Node *unionCal(Node *aNode, Node *bNode, int A, int B){ // 합집합 함수
    int pos = 0, idx = 0, A_flag = 0, B_flag = 0;
    Node *newNode = getNode(0);
    // A B 둘 다 0일 경우 0의 값 넣은 노드 연결 후 반환
    if(A == 0 && B == 0) return newNode;
    Node *A_tmp = aNode;
    Node *B_tmp = bNode;
    if(A != 0) A_tmp = A_tmp->next;
    else A_flag = 1;
    if(B != 0) B_tmp = B_tmp->next;
    else B_flag = 1;
    while(1){
        if(A_tmp->data < B_tmp->data && A_flag == 0){
            addNode(newNode, pos ,A_tmp->data);
            if(A_tmp->next == NULL){
                // 다음이 NULL이면 더이상 해당 조건문은 들어오지 못함 A_flag
                A_flag = 1;
                pos++;
                continue;
            }
            A_tmp = A_tmp->next;
        }
        else if(A_tmp->data > B_tmp->data && B_flag == 0){
            addNode(newNode, pos, B_tmp->data);
            if(B_tmp->next == NULL){
                // 다음이 NULL이면 더이상 해당 조건문은 들어오지 못함 B_flag
                B_flag = 1;
                pos++;
                continue;
            }
            B_tmp = B_tmp->next;
        }
        else if(A_tmp->data == B_tmp->data && A_flag == 0 && B_flag == 0){
            addNode(newNode, pos, A_tmp->data);
            if(A_tmp->next == NULL && B_tmp->next == NULL) break; // 종료 조건
            if(A_tmp->next != NULL) A_tmp = A_tmp->next;
            else A_flag = 1;
            if(B_tmp->next != NULL) B_tmp = B_tmp->next;
            else B_flag = 1;
            pos++;
            continue;
        }
        if(A_flag == 1){ // 남은 B_tmp 순서대로 저장
            addNode(newNode, pos, B_tmp->data);
            if(B_tmp->next == NULL) break;
            B_tmp = B_tmp->next;
        }
        else if(B_flag == 1){ // 남은 A_tmp 순서대로 저장
            addNode(newNode, pos, A_tmp->data);
            if(A_tmp->next == NULL) break;
            A_tmp = A_tmp->next;
        }
        pos++;
    }
    return newNode;
}

Node *intersectCal(Node *aNode, Node *bNode, int A, int B){ // 교집합 함수
    int pos = 0, flag = 0;
    Node *newNode = getNode(0);
    // A B 둘 중 하나라도 0일 경우 0의 값 넣은 노드 연결 후 반환
    if(A == 0 || B == 0) return newNode;
    Node *A_tmp = aNode->next;
    Node *B_tmp = bNode->next;
    while(1){
        B_tmp = bNode->next;
        while(1){
            if(A_tmp->data == B_tmp->data){
                flag = 1; // 한 번이라도 들어오면 공집합 아님을 표시
                addNode(newNode, pos, A_tmp->data);
                pos++;
                break;
            }
            // 종료조건
            if(B_tmp->next == NULL) break;
            B_tmp = B_tmp->next;
        }
        // 종료조건
        if(A_tmp->next == NULL) break;
        A_tmp = A_tmp->next;
    }
    if(flag == 0) // 공집합인 경우
        addNode(newNode, 0, 0);
    return newNode;
}

void printNode(Node *uniNode){ // 출력 함수
    Node *newNode = uniNode;
    if(newNode->next != NULL)
        newNode = newNode->next;
    while(1){
        printf(" %d", newNode->data);
        if(newNode->next == NULL) break;
        newNode = newNode->next;
    }
    printf("\n");
}