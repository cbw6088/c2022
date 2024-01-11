#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int binSearch(int ar[], int key, int size);

int main(){
	int n, key;
	scanf("%d %d", &n, &key);
	int *ar = (int*)malloc(sizeof(int)*n);

	for(int i=0; i<n; i++)
		scanf("%d", &ar[i]);

	printf("%d",binSearch(ar, key, n));

	free(ar);
	return 0;
}

int binSearch(int ar[], int key, int size){
	int left = 0, right = size-1, mid;

	while(1){
		mid = (left + right) / 2;
		if(key > ar[right])
			return size;
		else if(key <= ar[left])
			return left;
		else if(key > ar[mid])
			left = mid + 1;
		else if(key <= ar[mid-1])
			right = mid - 1;
		else
			return mid;
	}
}