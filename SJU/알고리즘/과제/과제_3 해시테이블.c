#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct bucket{
	int element;
	int act; // 활성화 || 비활성화 판단 (1 || 0)
}BUK;

int getHash(int M, int k);
int getNextHash(int q, int k);
void initBucketArray(BUK *table, int M);
void insertItem(BUK *table, int M, int k, int q);
void findElement(BUK *table, int M, int k, int q);
void removeElement(BUK *table, int M, int k, int q);
void printElement(BUK *table, int M);

int main(){
	int M = 23, k, q;
	char cmd;
	BUK *table = (BUK*)malloc(sizeof(BUK) * M);
	initBucketArray(table, M);
	scanf("%d", &q);
	/*명령 실행*/
	while(1){
		scanf(" %c", &cmd);
		switch(cmd){
			case 'i' : 
				scanf("%d", &k);
				if(k < 0 || k >= 100){ // 해당 범위를 벗어나면 명령 수행 거절
					printf("ErrorKey\n");
					break;
				}
				insertItem(table, M, k, q);
				break;
			case 'f' :
				scanf("%d", &k);
				findElement(table, M, k, q);
				break;
			case 'r' :
				scanf("%d", &k);
				removeElement(table, M, k, q);
				break;
			case 'p' :
				printElement(table, M);
				break;
			case 'q' :
				return 0;
		}
	}
	return 0;
}

int getHash(int M, int k){ // 해시
	return k % M;
}

int getNextHash(int q, int k){
    int newKey = getHash(q, k);
    if (newKey == 0) return q - 1; // 0일 경우 값 변경 (반복되는 값 방지)
    return q - newKey; // 서로소를 유지하면서 다른 값을 반환
}


void initBucketArray(BUK *table, int M){
	for (int i = 0; i < M; i++) table[i].element = -1; // 원소 초기값 설정
	for (int i = 0; i < M; i++) table[i].act = 1; // 최초 모두 활성화
}

void insertItem(BUK *table, int M, int k, int q){
	int pos = getHash(M, k);
	int count = 0;
	for(int i = 0; i < M; i++, count++) {
		if (table[pos].element == k && table[pos].act == 1){ // 이미 해당값이 있는 경우
            printf("SameElementExists\n"); // 중복 키 존재
            return ;
        }
		if (table[pos].element == -1 || table[pos].act == 0){ // 비어있거나 비활성화인 경우
			table[pos].act = 1; // 다시 활성화
			table[pos].element = k;
			printf("InsertMove : [%d] InsertPosition : [%d]\n", count, pos); // 이동한 횟수와 위치 출력
			return ;
		}
		pos = (pos + getNextHash(q, k)) % M; // 값이 있는 경우 이중해싱
	}
	printf("overflowException\n"); // 자리가 없는 경우
}

void findElement(BUK *table, int M, int k, int q){
	int pos = getHash(M, k);
	for(int i = 0; i < M; i++){
		if (table[pos].element != -1 || table[pos].act == 0){ // 값이 있거나(활성) 비활성화인 경우
			if (table[pos].element == k){ // 찾고자하는 값인 경우
				printf("FindPosition : [%d] FindElement : [%d]\n", pos, k); // 찾는 값과 위치 출력
				return ;
			}
		}
		pos = (pos + getNextHash(q, k)) % M; // 이중해시
	}
	printf("NoSuchKey\n");
}

void removeElement(BUK *table, int M, int k, int q){
	int pos = getHash(M, k);
	for(int i = 0; i < M; i++){
		if(table[pos].element != -1 || table[pos].act == 0){ // 값이 있거나(활성) 비활성화인 경우
			if(table[pos].element == k){ // 제거하고자 하는 값인 경우
				table[pos].act = 0; // 비활성화
				table[pos].element = -1; // 현재 값 초기화
				printf("RemoveElement : [%d] RemovePosition : [%d]\n", k, pos); // 제거한 값과 위치 출력
				return;
			}
		}
		pos = (pos + getNextHash(q, k)) % M; // 이중해시
	}
	printf("NoSuchKey\n"); // 제거 할 값이 없는 경우
}

void printElement(BUK *table, int M){
	/*배열 첨자 출력*/
	printf("PrintIndex   : ");
	for(int i = 0; i < M; i++) {
		if(i < 10) printf(" %d ", i);
		else printf("%d ", i);
	}
	printf("\n");
	/*배열 원소 출력*/
	printf("PrintElement : ");
	for(int i = 0; i < M; i++){
		if(table[i].element != -1)
			if (table[i].element >= 10) printf("%d ", table[i].element);
			else printf(" %d ", table[i].element);
		else printf(" . ");
	}
	printf("\n");
}