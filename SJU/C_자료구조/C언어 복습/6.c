#include <stdio.h>

typedef struct student{
    char name[10]; // 주어진 범위의 배열
    int score;
}stu;

int main(){
    stu arr[5];
    for(int i = 0; i < 5; i++)
        scanf("%s %d", arr[i].name, &arr[i].score);
    int avg = 0;
    for(int i = 0; i < 5; i++)
        avg = avg + arr[i].score;
    avg /= 5; // 평균값 구하기
    for(int i = 0; i < 5; i++){
        if (arr[i].score <= avg) // 평균값 보다 크거나 같은 경우
            printf("%s\n", arr[i].name);
    }
    return 0;
}
