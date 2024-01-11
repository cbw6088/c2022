/*다중연결리스트가 아닌 이중연결리스트로 작성하여 50점*/
/*혹여나, 해당 주석 부분이 문제가 될 수 있는지 명확하게 알지 못하여 따로 적어두었습니다.*/
/*문제에 표기된 (순서 무관)이라는 문구로 인하여 출력 순서는 신경쓰지 않았습니다.*/
/*가입자 명과 쿠폰 명이 지정되어 있어서 그 외의 입력 값이 나오면 에러 문구를 표기하였습니다.*/
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/*노드 구조체 선언*/
typedef struct node {
    char group;
    int elem;
    struct node* next;
    struct node* prev;
}Node;

/*리스트 구조체 선언*/
typedef struct list {
    Node* head;
    Node* tail;
}List;

/*원형 함수 선언*/
void initNode(List* list);
Node* getNode(char group, int elem);
void addShare(List* list, int elem, char group);
void removeShare(List* list, int elem, char group);
void groupView(List* list, int elem);
void elemView(List* list, char group);

int main() {
    /*리스트 할당 및 초기화*/
    List* list = (List*)malloc(sizeof(List));
    if (list == NULL) return -1;
    char ch, name;
    int value;
    initNode(list);
    /*무한루프로 반복하며 종료조건이 나올면 브레이크*/
    while (1) {
        scanf("%c", &ch);
        getchar();
        /*값 저장 함수*/
        if (ch == 'a') {
            scanf("%d %c", &value, &name);
            getchar();
            /*문제에서 제시된 정보 외에 값이 들어간 경우*/
            if (!((value >= 1 && value <= 4) && (name >= 'A' && name <= 'E'))) {
                printf("DATA ERROR\n");
                break;
            }
            /*함수 이동*/
            addShare(list, value, name);
        }
        /*값 삭제 함수*/
        else if (ch == 'r') {
            scanf("%d %c", &value, &name);
            getchar();
            /*문제에서 제시된 정보 외에 값이 들어간 경우*/
            if (!((value >= 1 && value <= 4) && (name >= 'A' && name <= 'E'))) {
                printf("DATA ERROR\n");
                break;
            }
            /*함수 이동*/
            removeShare(list, value, name);
        }
        /*가입자 명으로 쿠폰 명 찾기 함수*/
        else if (ch == 'e') {
            scanf("%c", &name);
            getchar();
            /*문제에서 제시된 정보 외에 값이 들어간 경우*/
            if (!(name >= 'A' && name <= 'E')) {
                printf("DATA ERROR\n");
                break;
            }
            /*함수 이동*/
            elemView(list, name);
        }
        /*쿠폰 명으로 가입자 명 찾기 함수*/
        else if (ch == 'g') {
            scanf("%d", &value);
            getchar();
            /*문제에서 제시된 정보 외에 값이 들어간 경우*/
            if (!(value >= 1 && value <= 4)) {
                printf("DATA ERROR\n");
                break;
            }
            /*함수 이동*/
            groupView(list, value);
        }
        /*종료 조건*/
        else if (ch == 'q') break;
    }
    return 0;
}

void initNode(List* list) {
    /*0과 널의 값을 넣으면서 리스트 초기화*/
    list->head = getNode(0, 0);
    list->tail = getNode(0, 0);
    list->head->next = list->tail;
    list->tail->prev = list->head;
}

Node* getNode(char group, int elem) {
    /*인자로 받은 값을 저장하여 반환*/
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->group = group;
    newNode->elem = elem;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addShare(List* list, int elem, char group) {
    Node* newNode = getNode(group, elem);
    int cnt = 0;
    Node* H = list->head;
    /*최초의 경우*/
    if (H->next == list->tail) {
        newNode->next = H->next;
        newNode->prev = H;
        H->next->prev = newNode;
        H->next = newNode;
        printf("OK\n");
        return;
    }
    /*그 외의 경우*/
    while (H->next->elem != 0) {
        H = H->next;
    }
    newNode->next = H->next;
    newNode->prev = H;
    H->next->prev = newNode;
    H->next = newNode;
    printf("OK\n");
}

void removeShare(List* list, int elem, char group) {
    Node* H = list->head->next;
    /*노드의 앞 뒤를 연결하며 현재 노드 제거*/
    while (H != list->tail) {
        if (H->elem == elem && H->group == group) {
            H->prev->next = H->next;
            H->next->prev = H->prev;
        }
        H = H->next;
    }
    printf("OK\n");
}

void groupView(List* list, int elem) {
    Node* H = list->head->next;
    int check = 0;
    while (H != NULL) {
        /*전달 받은 인자와 같은 값이 있는 경우*/
        if (H->elem == elem) {
            printf("%c ", H->group);
            check = 1;
        }
        H = H->next;
    }
    /*전달 받은 인자와 같은 값이 없는 경우*/
    if (check == 0) printf("0");
    printf("\n");
}

void elemView(List* list, char group) {
    Node* H = list->head->next;
    int check = 0;
    /*전달 받은 인자와 같은 값이 있는 경우*/
    while (H != NULL) {
        if (H->group == group) {
            printf("%d ", H->elem);
            check = 1;
        }
        H = H->next;
    }
    /*전달 받은 인자와 같은 값이 없는 경우*/
    if (check == 0) printf("0");
    printf("\n");
}

/*
a 1 C
a 4 A
a 4 E
a 4 D
e A
g 4
a 2 A
e A
r 4 A
g 4
e A
g 1
r 1 C
e C
g 1
g 3
*/