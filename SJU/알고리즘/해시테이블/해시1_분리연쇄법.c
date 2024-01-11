#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct bucket{
	int key;
	struct bucket *next;
}BUCKET;

int hash(int M, int x);
void initBucketArray(BUCKET *table, int M);
void insertBucketArray(BUCKET *table, int M, int x);
int searchBucketArray(BUCKET *table, int M, int x);
int deleteBucketArray(BUCKET *table, int M, int x);
void pirntBucketArray(BUCKET *table, int M);

int main(){
	int M, x;
	char ch;
	scanf("%d", &M);
	BUCKET *table = (BUCKET*)malloc(sizeof(BUCKET) * M);
	initBucketArray(table, M);

	while(1){
		scanf(" %c", &ch);
		switch(ch){
			case 'i' :
				scanf("%d", &x);
				insertBucketArray(table, M, x);
				break;
			case 's' :
				scanf("%d", &x);
				printf("%d\n", searchBucketArray(table, M, x));
				break;
			case 'd' :
				scanf("%d", &x);
				printf("%d\n", deleteBucketArray(table, M, x));
				break;
			case 'p' :
				pirntBucketArray(table, M);
				break;
			default :
				return 0;
		}
	}
	return 0;
}

int hash(int M, int x){
	return x % M;
}

void initBucketArray(BUCKET *table, int M){
	for(int i = 0; i < M; i++) (table + i)->next = NULL;
}

void insertBucketArray(BUCKET *table, int M, int x){
	BUCKET *copyTable = table + hash(M, x);
	BUCKET *newTable = (BUCKET*)malloc(sizeof(BUCKET) * M);
	newTable->key = x;
	newTable->next = copyTable->next;
	copyTable->next = newTable;
}

int searchBucketArray(BUCKET *table, int M, int x){
	int pos = 0;
	BUCKET *copyTable = (table + hash(M, x))->next;
	for(; copyTable != NULL; copyTable = copyTable->next, pos++){
		if(copyTable->key == x){
			pos++;
			break;
		}
		else if(copyTable->next == NULL){
			pos = 0;
			break;
		}
	}
	return pos;
}

int deleteBucketArray(BUCKET *table, int M, int x){
	int pos = 0;
	BUCKET *copyTable = table + hash(M, x);
	for(; copyTable->next != NULL; copyTable = copyTable->next, pos++){
		if(copyTable->next->key == x){
			pos++;
			copyTable->next = copyTable->next->next;
			break;
		}
		else if(copyTable->next->next == NULL){
			pos = 0;
			break;
		}
	}
	return pos;
}

void pirntBucketArray(BUCKET *table, int M){
	BUCKET *copyTable = (BUCKET*)malloc(sizeof(BUCKET) * M);
	for(int i = 0; i < M; i++){
		copyTable = (table + i)->next;
		for(; copyTable != NULL; copyTable = copyTable->next){
			printf(" %d", copyTable->key);
		}
	}
	printf("\n");
}

/*
13
i 34
i 23
i 26
i 21
s 36
s 26
s 34
s 21
p
d 21
s 34
d 8
e
*/