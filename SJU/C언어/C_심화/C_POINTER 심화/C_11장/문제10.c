#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct day{
    int year, month, day;
};

struct day *select_min(struct day *A, struct day *B);

int main(){
    struct day n1, n2, *p;
    scanf("%d/%d/%d",&n1.year, &n1.month, &n1.day);
    scanf("%d/%d/%d",&n2.year, &n2.month, &n2.day);
    p = select_min(&n1, &n2);
    printf("%d/%d/%d",p->year, p->month, p->day);

    return 0;
}

struct day *select_min(struct day *A, struct day *B){
    struct day *pre = A, *next = B;
    if(pre->year < next->year)
        return A;
    else if(pre->year > next->year)
        return B;
    else{
        if(pre->month < next->month)
            return A;
        else if(pre->month > next->month)
            return B;
        else{
            if(pre->day < next->day)
                return A;
            else
                return B;
        }
    }
}