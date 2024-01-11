#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

/*리스트 구조체*/
typedef struct node{
    struct node *right;
    struct node *left;
    char elem[100];
}Node;

/*원형 함수*/
Node *getNode();
Node *buildDecisionTree();
void runDecisionTree(Node *root);
Node *makeExternalNode(int noCnt);
Node *makeInternalNode(int noCnt);
Node *buildDecisionTree();
void processNode(Node *root);

/*메인 함수*/
int main(){
    Node *root = buildDecisionTree();
    printf("Tree complete. Now Running!!\n");
    for(int i = 1; i <= 3; i++){
        runDecisionTree(root);
    }
    free(root);
    return 0;
}

/*노드 생성 및 초기화*/
Node *getNode(){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/*문항 등록*/
Node *buildDecisionTree(){
    printf("*** Let's build a dichotomous QA system\n");
    int Cnt = 0; // 문항 개수를 세기 위한 카운트
    Node *root = makeInternalNode(Cnt+1);
    return root;
}

/*메뉴 입력*/
Node *makeExternalNode(int Cnt){
    Node *newRoot = getNode();
    printf("Enter decision:");
    gets(newRoot->elem);
    return newRoot;
}

/*문항 입력*/
Node *makeInternalNode(int Cnt){
    Node *newRoot = getNode(); // init
    char answer[5] = {0}; // yes or no 입력 변수
    printf("Enter question:");
    gets(newRoot->elem);
    if(Cnt > 5) return newRoot; // 문항은 최대 5개
    /*Answer : YES*/
    printf("Question if yes to '%s'?", newRoot->elem);
    scanf("%s", answer);
    getchar();
    // 최소 3번의 질문이 나와야 하므로 3번째 까지 yes입력 시  Internal함수 그 이후는 yes입력 시 External함수
    if(strcmp(answer, "yes") == 0 && Cnt <= 2) newRoot->left = makeInternalNode(Cnt + 1);
    else if(strcmp(answer, "no") == 0 && Cnt <= 2) newRoot->left = makeExternalNode(Cnt + 1);
    else if(strcmp(answer, "yes") == 0 && Cnt > 2) newRoot->left = makeExternalNode(Cnt + 1);
    else if(strcmp(answer, "no") == 0 && Cnt > 2) newRoot->left = makeInternalNode(Cnt + 1);
    /*Answer : NO*/
    printf("Question if no to '%s'?", newRoot->elem);
    scanf("%s", answer);
    getchar();
    if(strcmp(answer, "yes") == 0) newRoot->right = makeExternalNode(Cnt + 1);
    else if(strcmp(answer, "no") == 0) newRoot->right = makeInternalNode(Cnt + 1);

    return newRoot;
}

/*문답 시작 함수*/
void runDecisionTree(Node *root){
    printf("***Please answer questions\n");
    processNode(root);
}

/*문답 함수*/
void processNode(Node *root){
    printf("%s", root->elem);
    if(root->left == NULL || root->right == NULL) return ;
    char answer[5] = {0};
    scanf("%s", answer);
    if(strcmp(answer, "yes") == 0) processNode(root->left);
    else processNode(root->right);
}