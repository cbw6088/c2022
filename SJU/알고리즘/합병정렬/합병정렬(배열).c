#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mergeSort(int A[], int n);
void rmergeSort(int A[], int l, int r);
void merge(int A[], int l, int m, int r);

int main(){
   int n;
   scanf("%d", &n);
   int *A = (int*)malloc(sizeof(int)*n);

   for(int i=0; i<n; i++)
      scanf("%d", &A[i]);

   mergeSort(A, n);

   for(int i=0; i<n; i++)
      printf(" %d", A[i]);

   free(A);
}


void mergeSort(int A[], int n){
   rmergeSort(A, 0, n-1);
}

void rmergeSorbt(int A[], int l, int r){
   if(l < r){
      int m = (l + r) / 2;
      
      rmergeSort(A, l, m);
      rmergeSort(A, m + 1, r);
      merge(A, l, m ,r);
   }
}


void merge(int A[], int l, int m, int r){

   int i = l, j = m + 1, k = l;
   int *B = (int*)malloc(sizeof(int) * (r + 1));
   
   while(i <= m && j <= r){

      if(A[i] <= A[j])
         B[k++] = A[i++];

      else
         B[k++] = A[j++];

   }

   while(i <= m)
      B[k++] = A[i++];

   while(j <= r)
      B[k++] = A[j++];
   
   for(int k=l; k<=r; k++)
      A[k] = B[k];

   free(B);
}