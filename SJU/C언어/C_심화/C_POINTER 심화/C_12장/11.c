#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void size_add(int *len, int **p);

int main(){
	int size = 5, idx = 0;
	int *p = (int*)malloc(sizeof(int) * size);
	if(p == NULL){
		printf("Not enough memory!");
		return -1;
	}

	while(1){
		scanf("%d", &p[idx]);
		if(p[idx] == -1) break;
		if(idx + 1 == size)
			size_add(&size, &p);
		idx++;
	}
	for(int i=0; i<=idx; i++)
		printf(" %d", p[i]);
	free(p);
	return 0;
}

void size_add(int *len, int **p){
	int size = *len + 3;
	int *tmp = (int*)malloc(sizeof(int) * size);
	if(tmp == NULL){
		printf("Not enough memory!");
		return -1;
	}
	
	for(int i=0; i<*len; i++)
		tmp[i] = (*p)[i];
	free(*p);
	*p = tmp;
	*len = size;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void size_add(int *len, int *p);

int main(){
	int size = 5, idx = 0;
	int *p = (int*)malloc(sizeof(int) * size);
	if(p == NULL){
		printf("Not enough memory!");
		return -1;
	}

	while(1){
		scanf("%d", &p[idx]);
		if(p[idx] == -1) break;
		if(idx + 1 == size)
			size_add(&size, p);
		idx++;
	}
	for(int i=0; i<=idx; i++)
		printf(" %d", p[i]);
	free(p);
	return 0;
}

void size_add(int *len, int *p){
	int size = *len + 3;
	int *tmp = (int*)malloc(sizeof(int) * size);
	if(tmp == NULL){
		printf("Not enough memory!");
		return -1;
	}
	
	
	for(int i=0; i<*len; i++)
		tmp[i] = (p)[i];
	//free(p);
	p = tmp;
	*len = size;
}
*/