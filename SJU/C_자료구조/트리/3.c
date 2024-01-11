#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int id = 0;
int sum = 0;

typedef struct treeNode {
	int data; //노드에 저장되는 값
	int id;
	struct treeNode* left; //좌측 child 노드를 가리키는 링크
	struct treeNode* right; //우측 child 노드를 가리키는 링크
}treeNode;

treeNode* insertNode(int id,int data, treeNode* left, treeNode* right) {
	treeNode* v = (treeNode*)malloc(sizeof(treeNode) * 1);
	//노드 값 채우기
	v->data = data;
	v->id = id;

	//노드 연결
	v->left = left;
	v->right = right;
	return v;
}

treeNode* treeBuild() {
	//leaf node
	treeNode* F7 = insertNode(7,130, NULL, NULL);
	treeNode* F8 = insertNode(8,80, NULL, NULL);
	treeNode* F6 = insertNode(6,120, F7, F8);

	treeNode* F4 = insertNode(4,70, NULL, NULL);
	treeNode* F5 = insertNode(5,90, NULL, NULL);
	treeNode* F2 = insertNode(2,30, F4, F5);

	treeNode* F3 = insertNode(3,50, NULL, F6);
	treeNode* F1 = insertNode(1, 20, F2, F3);
	return F1;
}

void visit(treeNode* v) {
	printf(" %d", v->data);
}

int isInternal(treeNode* v) { //1:내부노드, 0:외부노드
	return((v->left != NULL) && (v->right != NULL));
}

treeNode* leftChild(treeNode* v) {
	return v->left;
}
treeNode* rightChild(treeNode* v) {
	return v->right;
}

void SumPreOrder(treeNode* v) {
	if (v != NULL) {
		//visit(v);
		sum = sum + v->data; //출력 대신 sum에 더하기
		SumPreOrder(leftChild(v));
		SumPreOrder(rightChild(v));
	}
}
treeNode* findID(treeNode*v) {
	if (v != NULL) {
		if (v->id == id) return v;

		treeNode* p = (treeNode*)malloc(sizeof(treeNode) * 1);
		p = findID(leftChild(v));
		if (p != NULL) return p;
		p = findID(rightChild(v));
		if (p != NULL) return p;
	}
	return NULL;
}

int main() {
	scanf("%d",&id);

	treeNode* root = treeBuild();
	treeNode* select;

	if (id >= 1 && id <= 8) {
		select = findID(root); //노드 번호 저장
		SumPreOrder(select); //용량 합 구하기
		printf("%d", sum); //출력
	}

	else {
		printf("-1");
	}
	return 0;
}

