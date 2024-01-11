#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int H[99];

void rBuildHeap(int i);
void buildHeap();
void downHeap(int i);
void printHeap();
void swap(int n1, int n2);

int main(){
   int k_cnt, key;
   scanf("%d",&k_cnt);
   for(int i=0; i<k_cnt; i++){
      scanf("%d",&key);
      n = n + 1;
      H[n] = key;
   }

   rBuildHeap(1);
   //buildHeap();
   printHeap();
   return 0;
}

void rBuildHeap(int i){
   if(i > n)
      return;

   rBuildHeap(2 * i);
   rBuildHeap((2 * i) + 1);
   downHeap(i);
   return;
}

void buildHeap(){
   for(int i=n/2; i>=1; i--)
      downHeap(i);
   return;
}

void downHeap(int i){
   int child = 2 * i;

   if(child > n)
      return;
   if(H[child] <= H[i] && H[child + 1] < H[i])
      return;

   if(H[child] <= H[child + 1])
      child = child + 1;
   
   swap(i, child);
   downHeap(child);
}

void printHeap(){
   for(int i=1; i<=n; i++)
      printf(" %d",H[i]);
   printf("\n");
}

void swap(int n1, int n2){
   int tmp = H[n1];
   H[n1] = H[n2];
   H[n2] = tmp;
}