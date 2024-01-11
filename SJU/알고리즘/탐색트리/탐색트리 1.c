#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree {
	int key;
	struct tree *lChild, *rChild, *parent;
}NODE;

bool isExternal();
bool isInternal();
bool isRoot();
void insertItem();
void expandExternal();
void printTree();
NODE *removeElement();
NODE *inOrderSucc();
NODE *treeSearch();
NODE *findRoot();

int main() {
	char ch;
	int key;
	NODE *tree = (NODE *)malloc(sizeof(NODE));
	tree->parent = NULL;
	tree->lChild = NULL;
	tree->rChild = NULL;

	NODE *tmp;
	while (1) {
		scanf("%c", &ch);
		switch (ch) {
		case 'i':
			scanf("%d", &key);
			insertItem(tree, key);
			break;
		case 'd':
			scanf("%d", &key);
			tmp = treeSearch(tree, key);
			if (isInternal(tmp)) {
				tree = removeElement(tmp);
				printf("%d\n", key);
			}
			else printf("X\n");
			break;
		case 's':
			scanf("%d", &key);
			tmp = treeSearch(tree, key);
			if (isInternal(tmp)) printf("%d\n", tmp->key);
			else printf("X\n");
			break;
		case 'p':
			printTree(tree);
			printf("\n");
			break;
		case 'q':
			return 0;
		default:
			break;
		}
		getchar();
		tree = findRoot(tree);
	}
}


bool isRoot(NODE *node) {
	if (node->parent == NULL) return true;
	return false;
}
NODE *findRoot(NODE *node) {
	while (!isRoot(node)) node = node->parent;
	return node;
}


void insertItem(NODE *root, int key) {
	NODE *tmp = treeSearch(root, key);
	if (isInternal(tmp)) return;
	tmp->key = key;
	expandExternal(tmp);
}

NODE *treeSearch(NODE *root_start, int key) {
	if (isExternal(root_start) || root_start->key == key) return root_start;
	else if (root_start->key > key) return treeSearch(root_start->lChild, key);
	else return treeSearch(root_start->rChild, key);
}


bool isExternal(NODE *node) {
	if (node->lChild == NULL) return true;
	return false;
}
bool isInternal(NODE *node) {
	return !isExternal(node);
}

void expandExternal(NODE *node) {
	NODE *R = (NODE *)malloc(sizeof(NODE));
	NODE *L = (NODE *)malloc(sizeof(NODE));
	node->rChild = R;
	node->lChild = L;
	R->parent = L->parent = node;
	R->lChild = R->rChild = L->lChild = L->rChild = NULL;
}


void printTree(NODE *root_start) {
	if (isInternal(root_start)) {
		printf(" %d", root_start->key);
		printTree(root_start->lChild);
		printTree(root_start->rChild);
	}
}


NODE *removeElement(NODE *node) { 
	if (isExternal(node->lChild) && isInternal(node->rChild)) { 
		NODE *root = node->rChild;
		node->rChild->parent = node->parent;
		if (!isRoot(node)) {
			if (node->parent->rChild == node)
				node->parent->rChild = node->rChild;
			else
				node->parent->lChild = node->rChild;
		}
		free(node->lChild);
		free(node);
		return root;
	}
	else if (isExternal(node->rChild)) { 
		NODE *root = node->lChild;
		node->lChild->parent = node->parent;
		if (!isRoot(node)) {
			if (node->parent->rChild == node)
				node->parent->rChild = node->lChild;
			else
				node->parent->lChild = node->lChild;
		}
		free(node->rChild);
		free(node);
		return root;
	}
	else {
		NODE *successor = inOrderSucc(node);
		node->key = successor->key;
		free(successor->lChild);
		successor->rChild->parent = successor->parent;
		if (successor->parent->rChild == successor)
			successor->parent->rChild = successor->rChild;
		else
			successor->parent->lChild = successor->rChild;
		free(successor);
		return node;
	}
}

NODE *inOrderSucc(NODE *node) {
	NODE *tmp = node->rChild;
	if (isExternal(tmp)) return NULL;
	while (isInternal(tmp)) tmp = tmp->lChild;
	return tmp->parent;
}

/*
i 3
i 2
i 7
s 4
i 6
p
i 5
s 6
q

i 9
i 2
i 15
i 1
i 7
i 11
i 5
i 8
i 3
i 4
p
d 2
d 13
p
q
*/