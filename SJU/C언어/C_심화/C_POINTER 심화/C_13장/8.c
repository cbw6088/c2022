#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int add(int x, int y);
int sub(int x, int y);
int multiply(int x, int y);

int main(void) {

   int x, y;
   scanf("%d %d", &x, &y);
   int (*ar[3])(int, int);
   ar[0] = add;
   ar[1] = sub;
   ar[2] = multiply;

   printf("%d %d %d", ar[0](x, y), ar[1](x, y), ar[2](x, y));


   return 0;
}


int add(int x, int y) {
   return x + y;
}
int sub(int x, int y) {
   return x - y;
}
int multiply(int x, int y) {
   return x * y;
}