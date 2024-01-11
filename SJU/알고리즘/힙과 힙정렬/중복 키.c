#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int H[99];
int n = 0;

void inPlaceHeapSort();
void printArray();
void downHeap(int i);
void insertitem(int key);
void upHeap(int i);
void rBuildHeap(int i);
void buildHeap();
void swap(int x, int y);

int main(){
   int key_cnt, key;
   scanf("%d",&key_cnt);
   for(int i=0; i<key_cnt; i++){
      scanf("%d",&key);
      insertitem(key);
   }
   
   rBuildHeap(1);
   inPlaceHeapSort();
   printArray();

   return 0;
}

void inPlaceHeapSort(){
   int tmp = n;

   for(int i=n; i>=1; i--){
      swap(1, i);
      n -= 1;
      downHeap(1);
   }

   n = tmp;
}

void printArray(){
   for(int i=1; i<=n; i++)
      printf(" %d",H[i]);
}

void downHeap(int i){
   int child = i * 2;
   
   if(child > n)
      return;

   if( child < n && H[child] < H[child + 1] )
      child++;

   if(H[child] > H[i])
      swap(child,i);

   downHeap(child);
}

void insertitem(int key){
   n++;
   H[n] = key;
   upHeap(n);
}

void upHeap(int i){
   if(i == 1 || H[i] <= H[i/2])
      return;

   swap(i, i/2);
   upHeap(i/2);
}

void rBuildHeap(int i){
   if(i > n)
      return;

   rBuildHeap(i * 2);
   rBuildHeap((i * 2) + 1);
   downHeap(i);
}

void buildHeap(){
   for(int i=n/2; i>=1; i--)
      buildHeap(i);
}

void swap(x,y){
   int tmp = H[x];
   H[x] = H[y];
   H[y] = tmp;
}