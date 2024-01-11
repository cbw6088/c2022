#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char elem;
    struct node *next;
    struct node *prev;
}Node;

typedef struct list{
    Node *head;
    Node *tail;
}List;

Node *getNode(int elem);
void init(List *list);
int add_error_check(List *list, int pos);
int other_error_check(List *list, int pos);
void add(List *list, int pos, char elem);
void delete(List *list, int pos);
char get_entry(List *list, int pos);
void print(List *list);

int main(){
    List *list = (List*)malloc(sizeof(List)); // 최초 생성
    init(list); // 리스트 초기화
    int N, pos;
    char ch, elem, tmp_elem;
    scanf("%d", &N);
    getchar();
    for(int i = 0; i < N; i++){
        scanf("%c", &ch);
        getchar();
        if(ch == 'A'){
            scanf("%d %c", &pos, &elem);
            getchar();
            if(add_error_check(list, pos)) // 에러 체크
                printf("invalid position\n");
            else
                add(list, pos, elem);
        }
        else if(ch == 'D'){
            scanf("%d", &pos);
            getchar();
            if(other_error_check(list, pos)) // 에러 체크
                printf("invalid position\n");
            else
                delete(list, pos);
        }
        else if(ch == 'G'){
            scanf("%d", &pos);
            getchar();
            if(other_error_check(list, pos)) // 에러 체크
                printf("invalid position\n");
            else
                tmp_elem = get_entry(list, pos);
        }
        else if(ch == 'P'){
            print(list);
        }
    }
    return 0;
}

Node *getNode(int elem){ // 값을 넣고 새로운 노드 반환
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->elem = elem;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void init(List *list){ // 최초에 값 0으로 노드 생성
    list->head = getNode(0);
    list->tail = getNode(0);
    list->head->next = list->tail;
    list->tail->prev = list->head;
}

int add_error_check(List *list, int pos){ // 삽입 에러 체크 함수
    int cnt = 0;
    Node *ptr = list->head; // 삽입 시 에러를 확인 할 시 가장 앞 부터
    while(ptr != list->tail){
        ptr = ptr->next;
        cnt++;
    }
    return (pos <= 0 || pos > cnt);
}

int other_error_check(List *list, int pos){ // 그 외 에러 체크 함수
    int cnt = 0;
    Node *ptr = list->head->next; // 삽입이 아닌 경우엔 에러를 확인 할 시 next 부터
    while(ptr != list->tail){
        ptr = ptr->next;
        cnt++;
    }
    return (pos <= 0 || pos > cnt);
}

void add(List *list, int pos, char elem){ // 삽입 함수
    Node *node = getNode(elem);
    Node *ptr = list->head;
    for(int i = 1; i < pos; i++) // 해당 위치까지 이동
        ptr = ptr->next;
    // 다음 노드와 이전 노드 연결
    node->next = ptr->next;
    node->prev = ptr;
    ptr->next->prev = node;
    ptr->next = node;
}

void delete(List *list, int pos){ // 삭제 함수
    Node *ptr = list->head;
    for(int i = 0; i < pos; i++) // 해당 위치까지 이동
        ptr = ptr->next;
    // 현재 노드의 앞 뒤를 연결하며 현재 노드 삭제
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    // 불필요해진 주소 제거
    free(ptr);
}

char get_entry(List *list, int pos){ // 원하는 위치의 값 출력 함수
    Node *ptr = list->head;
    for(int i = 0; i < pos; i++) // 해당 위치까지 이동
        ptr = ptr->next;
    printf("%c\n", ptr->elem);
    return ptr->elem;
}

void print(List *list){ // 출력 함수
    Node *ptr = list->head->next;
    while(ptr->next != NULL){
        printf("%c", ptr->elem);
        ptr = ptr->next;
    }
    printf("\n");
}