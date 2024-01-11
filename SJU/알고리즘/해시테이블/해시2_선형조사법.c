#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hash();
void initBucketArray();
void insertItem();
int searchItem();


int main() {
	int M, n, value, *table;
	char ch;

	scanf("%d %d", &M, &n);
	table = (int *)malloc(sizeof(int)*M);
	initBucketArray(table, M);

	while (1) {
		scanf(" %c", &ch);
		switch (ch) {
		case 'i':
			scanf("%d", &value);
			insertItem(table, M, value);
			break;
		case 's':
			scanf("%d", &value);
			searchItem(table, M, value);
			break;
		default:
			return 0;
		}
	}
    free(table);
    return 0;
}

int hash(int m, int key) {
	return key % m;
}

void initBucketArray(int *table, int m) {
	for (int i = 0; i < m; i++) table[i] = 0;
}

void insertItem(int *table, int m, int key) {
	int index = hash(m, key);

	while (table[index] != 0) {
		printf("C");
		index = hash(m, ++index);
	}

	table[index] = key;
	printf("%d\n", index);
}

int searchItem(int *table, int m, int key) {
	for (int index = hash(m, key); 1; index = hash(m, ++index))
		if (table[index] == key) {
			printf("%d %d\n", index, key);
			return 0;
		}

		else if (table[index] == 0) {
			printf("-1\n");
			return 0;
		}
		
		else if (index == hash(m, m + hash(m, key) - 1)) {
			printf("-1\n");
			return 0;
		}
}

/*
7 3
i 17011112
i 17012345
i 17012687
s 17011111
e

13 10
i 16110243
i 17011111
i 17012354
i 17013672
i 16012342
s 17012354
i 15013986
i 102067
i 113478
i 14012322
s 16110243
e
*/
