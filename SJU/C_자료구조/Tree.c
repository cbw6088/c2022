#include <stdio.h>
#include <stdlib.h>
#include <time.h> // main함수 랜덤값 넣는 테스트 코드에 사용

typedef struct TreeNode{
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
}Node;

Node *insert(Node *Root, int value){
    if(Root == NULL){
        Node *node = (Node*)malloc(sizeof(Node));
        node->key = value;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    if(Root->key < value){
        Root->right = insert(Root->right,value);
    }
    else if(Root->key > value){
        Root->left = insert(Root->left,value);
    }
    return Root;
}

void preOrder(Node *Root){ // 전위순회 VLR (기준은 루트)
    if(Root){
        printf("%d------>",Root->key);
        preOrder(Root->left);
        preOrder(Root->right);
    }
}

void postOrder(Node *Root){ // 후위순회 LRV
    if(Root){
        postOrder(Root->left);
        postOrder(Root->right);
        printf("%d------>",Root->key);
    }
}

void inOrder(Node *Root){ // 중위순회 LVR
    if(Root){
        inOrder(Root->left);
        printf("%d----->\n",Root->key);
        inOrder(Root->right);
    }
}

int main(){
    Node *Root = NULL; // init대체
   
    int N,temp;
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d",&temp);
        Root = insert(Root,temp);
    }
    
    inOrder(Root);
    
    return 0;
}