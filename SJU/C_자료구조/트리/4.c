#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treeNode {
	int id; 
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* leftChild(treeNode* v) {
	return v->left;
}
treeNode* rightChild(treeNode* v) {
	return v->right;
}

treeNode* findID(treeNode* v, int id) {
	if (v != NULL) {
		if (v->id == id) return v;

		treeNode* p = (treeNode*)malloc(sizeof(treeNode) * 1);
		p = findID(leftChild(v), id);
		if (p != NULL) return p;
		p = findID(rightChild(v), id);
		if (p != NULL) return p;
	}
	return NULL;
}

treeNode* insertNode(treeNode* v, char type, int id) { 
	
	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode) * 1);
	
	newNode->id = id;

	
	newNode->right = NULL;
	newNode->left = NULL;

	if (type == 'R') v->right = newNode;
	else if (type == 'L') v->left = newNode;
	else { 
		printf("Check the type \n");
		exit(1);
	}
	return v;
}

treeNode* treeBuild() {
	int num = 0;
	int flag = 1;
	int id = 0, left_id = 0, right_id = 0;

	treeNode* root = (treeNode*)malloc(sizeof(treeNode)*1);
	root->right = NULL;
	root->left = NULL;

	scanf("%d", &num); 
	for(int i=0;i<num;i++){
		scanf("%d %d %d", &id, &left_id, &right_id);


		if (flag == 1) {
			root->id = id;
			if (right_id != 0) insertNode(root, 'R', right_id);
			if (left_id != 0) insertNode(root, 'L', left_id);
			flag = 0;
		}
		else {
			treeNode* vv = findID(root, id);
			if (right_id != 0) insertNode(vv, 'R', right_id);
			if (left_id != 0) insertNode(vv, 'L', left_id);
		}
	}
	return root;
}

int isInternal(treeNode* v) {
	return((v->left != NULL) && (v->right != NULL));
}

void visit(treeNode* v) {
	printf(" %d", v->id);
}

void binaryPreOrder(treeNode* v) {
	if (v != NULL) {
		visit(v);
		binaryPreOrder(leftChild(v));
		binaryPreOrder(rightChild(v));
	}
}

void treeSearch(treeNode* root) {
	int num = 0;
	scanf("%d", &num); 

	while (num--) {
		char str[100] = "";
		scanf("%s", str); 

		treeNode* v = root;
		printf(" %d", v->id); 

		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == 'R') v = rightChild(v);
			else if (str[i] == 'L') v = leftChild(v);
			printf(" %d", v->id); 
		}
		printf("\n");
	}
}

int main() {
	treeNode* root = treeBuild();
	treeSearch(root);

	return 0;
}
/*

9
5 3 9
3 8 15
8 0 2
2 0 0
15 0 0
9 7 10
7 12 0
12 0 0
10 0 0
3
RLL
LL
LR
*/