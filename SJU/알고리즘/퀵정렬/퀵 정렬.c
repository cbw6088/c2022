#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
	int l, r;
}NODE;

void quickSort(int ar[], int l, int r);
NODE InPlacePartition(int ar[], int l, int r, int pivot);
int findPivot(int ar[], int l, int r);
void swap(int ar[], int n1, int n2);

int main(){
	int N;
	scanf("%d", &N);
	int *L = (int*)malloc(sizeof(int)*N);

	for(int i=0; i<N; i++)
		scanf("%d", &L[i]);

	quickSort(L, 0, N-1);

	for(int i=0; i<N; i++)
		printf(" %d", L[i]);

	free(L);
	return 0;
}

void quickSort(int ar[], int l, int r){
	if(l >= r) return;

	NODE pivIdx = InPlacePartition(ar, l, r, findPivot(ar, l, r));
	quickSort(ar, l, pivIdx.l - 1);
	quickSort(ar, pivIdx.r + 1, r);
}

NODE InPlacePartition(int ar[], int l, int r, int pivot){
	int tPivot = ar[pivot], left, right;
	NODE rPivot;

	swap(ar, pivot, r);

	left = l;
	right = r - 1;

	while(left <= right){

		while(left <= right && ar[left] <= tPivot)
			left++;
		
		while(left <= right && ar[right] >= tPivot)
			right--;
		
		if(left < right)
			swap(ar, left, right);

	}

	swap(ar,left, r);

	rPivot.l = left;
	rPivot.r = left;

	return rPivot;
}

int findPivot(int ar[], int l, int r){
	int tmp[3];
	srand(time(NULL));
	tmp[0] = l + (rand() % (r - l + 1));
	return tmp[0];
}

void swap(int ar[], int n1, int n2){
	int tmp = ar[n1];
	ar[n1] = ar[n2];
	ar[n2] = tmp;
}