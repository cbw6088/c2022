#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct test{
    char name[20][19];
    double num;
    char rank;
};

int main(){
    int N;
    double avg[20] = {}, add[20] = {};
    char alpha[20] = {};
    scanf("%d", &N);
    struct test student[20], exam[20][3];
    for(int i=0; i<N; i++){
        scanf("%s",student[i].name[i]);
        for(int j=0; j<3; j++)
            scanf("%lf",&exam[i][j].num);
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++)
            add[i] = add[i] + exam[i][j].num; 
    }
    for(int i=0; i<N; i++)
        avg[i] = add[i]/3;
    for(int i=0; i<N; i++)
        if(avg[i] >= 90)
            alpha[i] = 'A';
        else if(avg[i] >= 80)
            alpha[i] = 'B';
        else if(avg[i] >= 70)
            alpha[i] = 'C';
        else  
            alpha[i] = 'F';

    for(int i=0; i<N; i++)
        printf("%s %.1lf %c\n", student[i].name[i], avg[i], alpha[i]);



    
    
    return 0;
}