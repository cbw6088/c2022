#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student{ // 구조체 선언
    char name[10], year[11], rank; // 구조체에 필요한 변수 선언
};

int main(){
    struct student A[5], name, number; // 구조체를 자료형으로 둔 변수 선언
    int cnt = 0, check = 0;
    for(int i=0; i<5; i++) // 구조체 각각 입력
        scanf("%s %s %c",A[i].name, A[i].year, &A[i].rank);
    scanf("%s",name.name); // 기준이 되는 값 입력

    for(int i=0; i<5; i++){ // 기준이 되는 값의 인덱스 위치를 파악하고, 그 외의 변수에 값을 카피
        if(strncmp(name.name, A[i].name,4) == 0){
            strcpy(name.year, A[i].year);
            name.rank = A[i].rank;
            break; // 찾으면 반복문 종료
        }
        cnt++; // 기준값 인덱스 확인
    }
    strncpy(number.year, A[cnt].year,4); // 입학년도 저장
     int num = atoi(number.year) % 131; // 자료형으로 131의 나머지값 저장
    for(int i=0; i<5; i++){ // 기준값과 같은 년도면서 등급이 같은 값 찾기
        if(cnt == i) continue; // 기준값과 같은 이름은 패스
        if(strncmp(number.year, A[i].year, 4) == 0 && name.rank == A[i].rank){
            printf("%s ", A[i].name); // 출력
            check = 1; // 조건에 맞는 학생이 없는 경우를 확인하기 위한 체크
        }
    }
    if(check == 0) // 기준에 맞는 학생이 없을 경우
        printf("0");
    printf("\n%s %d", number.year, num); // 출력


    return 0;
}

/*
lee1 2017102656 A
lee2 2018111823 A
kwon 2018111888 A
park 2018059961 A
choi 2018010101 B
park
*/