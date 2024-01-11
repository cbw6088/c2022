#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str1[100] = {}, str2[100] = {}, str3[100][100] = {}; // 변수 지정
    int cnt = 0, ccnt = 0, check = 0, x_idx = 0, y_idx = 0;

    gets(str1); // 입력
    gets(str2);

    for(int i=0; i<strlen(str1); i++){ // 2차원 배열에 단어별로 저장
        if(str1[i] == ' ' || str1[i] == '.'){ // 공백이거나 . 인 경우
            if(str1[i-1] == ' ' || str1[i-1] == '.') // 공백이거나 .인 경우가 연속되는 경우
                continue;
            x_idx++; // x인덱스 ++
            y_idx = 0; // y인덱스 초기화
            cnt++; // 카운트 ++
            continue;
        }
        str3[x_idx][y_idx++] = str1[i]; // 2차원 배열에 문자 저장
    }

    if(str1[strlen(str1)-1] != ' ') // 문자열의 맨 뒤가 공백이 아닌 경우
        ccnt++;
    if(str1[strlen(str1)-1] != '.') // 문자열의 맨 뒤가 점이 아닌 경우
        ccnt++;
    if(ccnt == 2) // 문자열이 점이나 공백으로 안끝나는 경우
        cnt++;

    for(int i=0; i<cnt; i++){ 
        if(strlen(str2) != strlen(str3[i])) // 비교하는 두 문자의 길이가 다를 경우 컨티뉴
            continue;
        if(strncmp(str2,str3[i],strlen(str2)) == 0) // 두 문자 비교
            check++;
    }
    
    printf("%d",check); 
    return 0;
}