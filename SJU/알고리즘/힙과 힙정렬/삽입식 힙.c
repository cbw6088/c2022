#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int H[99];

void insertitem(int key);
int removeMax();
void upHeap(int i);
void downHeap(int i);
void printHeap();
void swap(int x, int y);

int main(){
   char ch;
   int key;

   while(1){
      scanf("%c",&ch);
      if(ch == 'i'){
         if(n > 99){
            printf("Heap-index is Full!!\n");
            break;
         }            
         scanf("%d",&key);
         insertitem(key);
         printf("0\n");
      }
      else if(ch == 'p'){
         if(n < 1){
            getchar();
            printf("Heap-index is Empty!!\n");
            break;
         }
         printHeap();
      }
      else if(ch == 'd'){
         printf("%d\n",removeMax());
      }
      else 
         return 0;
      getchar();
   }
   return 0;
}

void insertitem(int key){
   n = n + 1;
   H[n] = key;
   upHeap(n);
}

int removeMax(){
   if(n == 0)
      return 0;
   int key = H[1];
   H[1] = H[n];
   n = n - 1;
   downHeap(1);
   return key;
}

void upHeap(int i){
   if(i == 1 || H[i] <= H[i/2])
      return;
   swap(i, i/2);
   upHeap(i/2);
}

void downHeap(int i){
   int child = i * 2;
   if(child > n)
      return;
   if(H[child] < H[i] && H[child+1] < H[i])
      return;
   if(H[child] <= H[child+1])
      child = child + 1;
   swap(i,child);
   downHeap(child);
}

void printHeap(){
   for(int i=1; i<=n; i++)
      printf(" %d",H[i]);
   printf("\n");
}

void swap(int x, int y){
   int tmp = H[x];
   H[x] = H[y];
   H[y] = tmp;
}