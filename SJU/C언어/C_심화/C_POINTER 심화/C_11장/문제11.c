#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct study{
    char ch[10];
    int num;
};

struct study *select_min(struct study *A);

int main(){
    struct study name[5];
    for(int i=0; i<5; i++)
        scanf("%s %d",name[i].ch, &(name[i].num));
    struct study *p = name, *q;
    
    q = select_min(p);

   printf("%s %d", q->ch, q->num);

    return 0;
}

struct study *select_min(struct study *A){
    struct study *p = A;
    struct study tmp;

    for(int i=0; i<4; i++){
        for(int j=i+1; j<5; j++){
            if((p+i)->num > (p+j)->num){
                tmp = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = tmp;
            }
        }
    }
    p = A;
    return p;
}