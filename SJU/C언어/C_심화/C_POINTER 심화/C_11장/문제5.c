#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct test{
    char name[50][9];
    int mul[50], kor[50], eng[50];
    double avg[50];
    double add[50];
    char rank[50];
};

int main(){
    int N;
    struct test student, exam, avg, add, alpha;
    struct test *Tstudent = &student, *Texam = &exam, *Tavg = &avg, *Talpha = &alpha, *Tadd = &add;

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%s %d %d %d",Tstudent->name[i], &Texam->mul[i], &Texam->kor[i], &Texam->eng[i]);
    // name , exam
    for(int i=0; i<N; i++){
        Tadd->add[i] = Texam->mul[i] + Texam->kor[i] + Texam->eng[i];
    } // add
    for(int i=0; i<N; i++)
        Tavg->avg[i] = (Tadd->add[i])/3;
    // avg
    for(int i=0; i<N; i++){
        if(Tavg->avg[i] >= 90)
            Talpha->rank[i] = 'A';
        else if(Tavg->avg[i] >= 80)
            Talpha->rank[i] = 'B';
        else if(Tavg->avg[i] >= 70)
            Talpha->rank[i] = 'C';
        else  
            Talpha->rank[i] = 'D';
    } // rank
    

    for(int i=0; i<N; i++)
        printf("%s %.1lf %c\n", Tstudent->name[i], Tavg->avg[i], Talpha->rank[i]);

    return 0;
}