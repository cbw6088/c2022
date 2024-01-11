#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct test{
    char name[5][10];
    int num;
};

int main(){
    struct test student[5], exam[5];
    int add = 0, avg = 0, idx = 0;

    for(int i=0; i<5; i++)
        scanf("%s %d", student[i].name[i], &exam[i].num);

    for(int i=0; i<5; i++)
        add = add + exam[i].num;

    avg = add / 5;

    for(int i=0; i<5; i++){
        if(exam[i].num <= avg)
            printf("%s\n", student[i].name[i]);
    }
    
    return 0;
}