#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int binSearch(int ar[], int key, int left, int right);

int main(){
	int n, key;
	scanf("%d %d", &n, &key);
	int *ar = (int*)malloc(sizeof(int)*n);

	for(int i=0; i<n; i++)
		scanf("%d", &ar[i]);

	printf("%d",binSearch(ar, key, 0, n-1));

	free(ar);
	
	return 0;
}

int binSearch(int ar[], int key, int left, int right){
	int mid = (left + right) / 2;

	if(key < ar[left]) 
		return -1;
	else if(key >= ar[right]) 
		return right;
	else if(key < ar[mid])
		return binSearch(ar, key, left, mid-1);
	else if(key >= ar[mid + 1])
		return binSearch(ar, key, mid+1, right);
	else
		return mid;
}