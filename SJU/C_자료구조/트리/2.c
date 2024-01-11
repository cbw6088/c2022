#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int id, data;
    struct node *left;
    struct node *right;
}Node;

Node *getNode(int id, int data);
void addNode(Node *root, Node *left, Node *right);
void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);
void serchNode(Node *root, int num1, int num2);

int main(){
    Node *root  = getNode(1, 20);

    Node *left  = getNode(2, 30);
    Node *right = getNode(3, 50);
    addNode(root, left, right);

    left    = getNode(4, 70);
    right   = getNode(5, 90);
    addNode(root->left, left, right);

    left    = 0;
    right   = getNode(6, 120);
    addNode(root->right, left, right);

    left    = getNode(7, 130);
    right   = getNode(8, 80);
    addNode(root->right->right, left, right);
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    if(num1 >3 || num1 < 1 || num2 > 8 || num2 < 1) printf("-1");
    else serchNode(root, num1, num2);

    return 0;
}

Node *getNode(int id, int data){
    Node *newNode   = (Node*)malloc(sizeof(Node));
    newNode->id        = id;
    newNode->data      = data;
    newNode->left      = NULL;
    newNode->right     = NULL;
    return newNode;
}

void addNode(Node *root, Node *left, Node *right){
    root->left  = left;
    root->right = right;
}

void inorder(Node *root){
    if(root == NULL) return ;
    inorder(root->left);
    printf(" %d", root->data);
    inorder(root->right);
}

void preorder(Node *root){
    if(root == NULL) return ;
    printf(" %d", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root){
    if(root == NULL) return ;
    postorder(root->left);
    postorder(root->right);
    printf(" %d", root->data);
}

void serchNode(Node *root, int num1, int num2){
    if(root == NULL) return;
    if(root->id == num2){
        if(num1 == 1) preorder(root);
        else if(num1 == 2) inorder(root);
        else if(num1 == 3) postorder(root);
    }
    else{
        serchNode(root->left, num1, num2);
        serchNode(root->right, num1, num2);
    }
}