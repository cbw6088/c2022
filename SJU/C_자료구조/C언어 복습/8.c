#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    char name[8]; // 규정된 범위의 배열
    int kor, eng, math;
    double avg;
}stu;

int main(){
    int N;
    scanf("%d", &N);
    stu *p = (stu*)malloc(sizeof(stu) * N); // 포인터 동적할당
    if(p == NULL)
        return -1;
    for(int i = 0; i < N; i++){ // 입력 및 평균 값 저장
        scanf("%s %d %d %d", p[i].name, &p[i].kor, &p[i].eng, &p[i].math);
        p[i].avg = (double)(p[i].kor + p[i].eng + p[i].math) / 3; // double형으로 저장
    }
    for(int i = 0; i < N; i++){ // 출력
        printf("%s %.1lf ", p[i].name, p[i].avg);
        if(p[i].kor >= 90 || p[i].eng >= 90 || p[i].math >= 90) // GREAT범위
            printf("GREAT ");
        if(p[i].kor < 70 || p[i].eng < 70 || p[i].math < 70) // BAD범위
            printf("BAD\n");
    }
    free(p);
    return 0;
}

