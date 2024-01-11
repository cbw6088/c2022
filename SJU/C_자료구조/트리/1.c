#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    struct node *right;
    struct node *left;
    int data;
}Node;

Node *childNode(int data);
Node *rootNode(int data, Node *left, Node *right);
void serchNode(Node **tree, int n);


int main(){
    Node *tree[9] = {0};
    tree[4] = childNode(70);
    tree[5] = childNode(90);
    tree[2] = rootNode(30, tree[4], tree[5]);

    tree[7] = childNode(130);
    tree[8] = childNode(80);
    tree[6] = rootNode(120, tree[7], tree[8]);

    tree[3] = rootNode(50, NULL, tree[6]);

    tree[1] = rootNode(20, tree[2], tree[3]);

    int n = 0;
    scanf("%d", &n);
    
    if(n < 1 || n > 8) printf("-1");
    else serchNode(tree, n);
    return 0;
}

Node *childNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->data = data;
    return newNode;
}

Node *rootNode(int data, Node *left, Node *right){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->right = right;
    newNode->left = left;
    newNode->data = data;
    return newNode;
}

void serchNode(Node **tree, int n){
    Node *tmp = tree[n];
    printf("%d ", tmp->data);
    if(tmp->left) printf("%d ", tmp->left->data);
    if(tmp->right) printf("%d ", tmp->right->data);
}