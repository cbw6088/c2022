#include <stdio.h>
#include <stdlib.h>

typedef struct term{
    int coef, exp;
    struct term *next;
}Term;

Term *getNode(int coef, int exp);
void appendTerm(Term *H, int coef, int exp);
Term *addPoly(Term *H_first, Term *H_second);
void printNode(Term *result);

int main(){
    int N, coef, exp;
    int cnt = 0;
    Term *H_first = getNode(-1, -1); // 최초에 임의의 값으로 초기화
    Term *H_second = getNode(-1, -1);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &coef, &exp);
        appendTerm(H_first, coef, exp);
    }
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){ // 반복하며 입력 받은 값 리스트에 연결
        scanf("%d %d", &coef, &exp);
        appendTerm(H_second, coef, exp);
    }
    Term *result = addPoly(H_first, H_second); // 최종 결과값 저장
    printNode(result); // 출력
    return 0;
}

Term *getNode(int coef, int exp){ // 새로운 노드 생성 함수
    Term *newNode = (Term*)malloc(sizeof(Term));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void appendTerm(Term *H, int coef, int exp){ // 리스트 연결 함수
    Term *node = getNode(coef, exp);
    Term *p = H;
    while(p->next != NULL)
        p = p->next;
    p->next = node;
}

Term *addPoly(Term *H_first, Term *H_second){
    Term *tmp = getNode(-1, -1); // 초기화
    Term *result = tmp;
    H_first = H_first->next; // 한 칸씩 전진
    H_second = H_second->next;
    while(H_first != NULL && H_second != NULL){
        if(H_first->exp == H_second->exp){ // 리스트의 차수가 같은 경우
            Term *newNode = getNode(H_first->coef + H_second->coef, H_first->exp);
            tmp->next = newNode;
            // 두 리스트 모두 한 칸씩 전진
            H_first = H_first->next;
            H_second = H_second->next;
        }
        else if(H_first->exp > H_second->exp){ // 앞의 리스트의 차수가 더 큰 경우
            Term *newNode = getNode(H_first->coef, H_first->exp);
            tmp->next = newNode;
            // 앞의 리스트만 한 칸 전진
            H_first = H_first->next;
        }
        else if(H_first->exp < H_second->exp){ // 뒤의 리스트의 차수가 더 큰 경우
            Term *newNode = getNode(H_second->coef, H_second->exp);
            tmp->next = newNode;
            // 뒤의 리스트만 한 칸 전진
            H_second = H_second->next;
        }
        tmp = tmp->next;
    }
    // 앞의 노드가 남아있는 경우
    while(H_first != NULL){
        Term *newNode = getNode(H_first->coef, H_first->exp);
        tmp->next = newNode;
        H_first = H_first->next;
        tmp = tmp->next;
    }
    // 뒤의 노드가 남아있는 경우
    while(H_second != NULL){
        Term *newNode = getNode(H_second->coef, H_second->exp);
        tmp->next = newNode;
        H_second = H_second->next;
        tmp = tmp->next;
    }
    return result;
}

void printNode(Term *result){ // 출력 함수
    result = result->next;
    while(result != NULL){
        if(result->coef == 0){
            result = result->next;
            continue ;
        }
        printf(" %d %d", result->coef, result->exp);
        result = result->next;
    }
}