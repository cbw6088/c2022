#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree {
	int key, height;
	struct tree *lChild, *rChild, *parent;
}AVL;

AVL *findRoot();
AVL *treeSearch();
AVL *removeElement();
AVL *inOrderSucc();
AVL *restructure();
bool isRoot();
bool isExternal();
bool isInternal();
bool isBalanced();
void insertItem();
void expandExternal();
void updateHeightToRoot();
void searchAndFixAfterInsertion();
void searchAndFixAfterRemoval();
void printTree();
int searchHeight();

// 트리 서치, 인서트 아이템, 이즈 인터널, 리무브 엘리멘트, 프린트 트리

int main() {
	char ch;
	int key;
	AVL *tree = (AVL*)malloc(sizeof(AVL));
	tree->parent = NULL;
	tree->lChild = NULL;
	tree->rChild = NULL;

	AVL *tmp;
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

AVL *findRoot(AVL *node) {
	while (!isRoot(node)) node = node->parent;
	return node;
}
bool isRoot(AVL *node) {
	if (node->parent == NULL) return true;
	return false;
}

void insertItem(AVL *root, int key) {
	AVL *tmp = treeSearch(root, key);
	if (isInternal(tmp)) return;
	tmp->key = key;
	expandExternal(tmp);
	updateHeightToRoot(tmp);
	searchAndFixAfterInsertion(tmp);
}

void updateHeightToRoot(AVL *node) {
	for (; node != NULL; node = node->parent)
		node->height = searchHeight(node);
}
int searchHeight(AVL *node) {
	if (isExternal(node)) return 0;
	int lChildHeight = searchHeight(node->lChild), rChildHeight = searchHeight(node->rChild);
	if (lChildHeight > rChildHeight) return lChildHeight + 1;
	else return rChildHeight + 1;
}

void searchAndFixAfterInsertion(AVL *node) {
	AVL *nodeX, *nodeY, *nodeZ;
	for (nodeZ = node; isBalanced(nodeZ); nodeZ = nodeZ->parent)
		if (isRoot(nodeZ)) return;
	if (nodeZ->lChild->height > nodeZ->rChild->height) nodeY = nodeZ->lChild;
	else nodeY = nodeZ->rChild;

	if (nodeY->lChild->height > nodeY->rChild->height) nodeX = nodeY->lChild;
	else nodeX = nodeY->rChild;
	restructure(nodeX, nodeY, nodeZ);
}

AVL *treeSearch(AVL *root_start, int key) {
	if (isExternal(root_start) || root_start->key == key) return root_start;
	else if (root_start->key > key) return treeSearch(root_start->lChild, key);
	else return treeSearch(root_start->rChild, key);
}


bool isExternal(AVL *node) {
	if (node->lChild == NULL) return true;
	return false;
}
bool isInternal(AVL *node) {
	return !isExternal(node);
}

void expandExternal(AVL *node) {
	AVL *R = (AVL *)malloc(sizeof(AVL));
	AVL *L = (AVL *)malloc(sizeof(AVL));
	node->rChild = R;
	node->lChild = L;
	R->parent = L->parent = node;
	R->lChild = R->rChild = L->lChild = L->rChild = NULL;
	R->height = L->height = 0;
}


void printTree(AVL *root_start) {
	if (isInternal(root_start)) {
		printf(" %d", root_start->key);
		printTree(root_start->lChild);
		printTree(root_start->rChild);
	}
}


AVL *removeElement(AVL *node) {
	AVL *parentOfRemoved;

	if (isExternal(node->lChild) && isInternal(node->rChild)) {
		AVL *root = node->rChild;
		node->rChild->parent = node->parent;

		if (!isRoot(node)) {
			if (node->parent->rChild == node)
				node->parent->rChild = node->rChild;
			else
				node->parent->lChild = node->rChild;
		}
		free(node->lChild);
		parentOfRemoved = node->parent;
		free(node);
		updateHeightToRoot(parentOfRemoved);
		searchAndFixAfterRemoval(parentOfRemoved);
		return root;
	}
	else if (isExternal(node->rChild)) {
		AVL *root = node->lChild;
		node->lChild->parent = node->parent;

		if (!isRoot(node)) {
			if (node->parent->rChild == node)
				node->parent->rChild = node->lChild;
			else
				node->parent->lChild = node->lChild;
		}

		free(node->rChild);
		parentOfRemoved = node->parent;
		free(node);
		updateHeightToRoot(parentOfRemoved);
		searchAndFixAfterRemoval(parentOfRemoved);
		return root;
	}
	else {
		AVL *successor = inOrderSucc(node);
		node->key = successor->key;
		free(successor->lChild);
		successor->rChild->parent = successor->parent;
		if (successor->parent->rChild == successor)
			successor->parent->rChild = successor->rChild;
		else
			successor->parent->lChild = successor->rChild;
		parentOfRemoved = successor->parent;
		free(successor);
		updateHeightToRoot(parentOfRemoved);
		searchAndFixAfterRemoval(parentOfRemoved);
		return node;
	}
}

void searchAndFixAfterRemoval(AVL *node) {
	if (node == NULL) return;
	AVL *nodeX, *nodeY, *nodeZ = node;

	while (1) {
		while (isBalanced(nodeZ)) {
			if (isRoot(nodeZ)) return;
			nodeZ = nodeZ->parent;
		}
		if (nodeZ->lChild->height > nodeZ->rChild->height) {
			nodeY = nodeZ->lChild;
			nodeX = nodeY->lChild;
		}
		else {
			nodeY = nodeZ->rChild;
			nodeX = nodeY->rChild;
		}
		if (nodeY->lChild->height > nodeY->rChild->height) nodeX = nodeY->lChild;
		else if (nodeY->lChild->height < nodeY->rChild->height) nodeX = nodeY->rChild;
		nodeZ = restructure(nodeX, nodeY, nodeZ);
	}
}



AVL *inOrderSucc(AVL *node) {
	AVL *tmp = node->rChild;
	if (isExternal(tmp)) return NULL;
	while (isInternal(tmp)) tmp = tmp->lChild;
	return tmp->parent;
}

bool isBalanced(AVL *node) {
	if (isExternal(node)) return true;
	int bal = node->lChild->height - node->rChild->height;
	if (bal >= -1 && bal <= 1) return true;
	else return false;
}



AVL *restructure(AVL *nodeX, AVL *nodeY, AVL *nodeZ) {
	AVL *nodeA, *nodeB, *nodeC, *subtree0, *subtree1, *subtree2, *subtree3;
	if (nodeZ->key > nodeY->key) {
		nodeC = nodeZ;
		subtree3 = nodeZ->rChild;
		if (nodeY->key > nodeX->key) {
			nodeA = nodeX;
			nodeB = nodeY;
			subtree0 = nodeX->lChild;
			subtree1 = nodeX->rChild;
			subtree2 = nodeY->rChild;
		}
		else {
			nodeA = nodeY;
			nodeB = nodeX;
			subtree0 = nodeY->lChild;
			subtree1 = nodeX->lChild;
			subtree2 = nodeX->rChild;
		}
	}
	else {
		nodeA = nodeZ;
		subtree0 = nodeZ->lChild;
		if (nodeY->key > nodeX->key) {
			nodeB = nodeX;
			nodeC = nodeY;
			subtree1 = nodeX->lChild;
			subtree2 = nodeX->rChild;
			subtree3 = nodeY->rChild;
		}
		else {
			nodeB = nodeY;
			nodeC = nodeX;
			subtree1 = nodeY->lChild;
			subtree2 = nodeX->lChild;
			subtree3 = nodeX->rChild;
		}
	}
	if (!isRoot(nodeZ)) {
		if (nodeZ->parent->rChild == nodeZ)
			nodeZ->parent->rChild = nodeB;
		else
			nodeZ->parent->lChild = nodeB;
	}
	nodeB->parent = nodeZ->parent;
	nodeB->lChild = nodeA;
	nodeB->rChild = nodeC;
	nodeA->parent = nodeC->parent = nodeB;
	nodeA->lChild = subtree0;
	nodeA->rChild = subtree1;
	subtree0->parent = subtree1->parent = nodeA;
	nodeC->lChild = subtree2;
	nodeC->rChild = subtree3;
	subtree2->parent = subtree3->parent = nodeC;
	nodeA->height = searchHeight(nodeA);
	nodeC->height = searchHeight(nodeC);
	updateHeightToRoot(nodeB);
	return nodeB;
}

/*
i 44
i 17
i 78
i 32
i 50
i 88
i 48
i 62
s 88
p
q
*/