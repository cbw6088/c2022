#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct point{
   double x, y, mid;
}Point;

double center(double n1, double n2);

int main(){
   Point *p = (Point*)malloc(sizeof(Point) * 2);
   if(p == NULL) return -1;

   scanf("%lf %lf", &p[0].x, &p[1].x);
   scanf("%lf %lf", &p[0].y, &p[1].y);

   for(int i = 0; i < 2; i++){
      p[i].mid = center(p[i].x, p[i].y);
   }
   
   printf("%.2lf %.2lf", p[0].mid, p[1].mid);
   return 0;
}

double center(double n1, double n2){
   double mid = (n1 + n2) / 2.0;
   return mid;
}


/*
1.0 1.0
2.0 2.0
*/