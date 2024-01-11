#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str1[200] = {} ,str2[200] = {}, result[200] = {}, tmp[200] = {}; // 변수 지정
    char tmp_str[20][200] = {};
    int idx = 0, xidx = 0, yidx = 0, cnt = 1,check = 0;

    gets(str1); // 문자열 입력
    gets(str2); 
    
    str2[strlen(str2)] = ' '; // 비교를 위해 뒤에 공백 추가

    for(int i=0; i<strlen(str1); i++){ // 배열의 길이만큼 반복
        if(str1[i] == ' '){ // 공백일 경우
            tmp_str[xidx][yidx++] = ' '; // 공백 추가
            xidx++; // x인덱스 ++
            cnt++;
            yidx = 0; // y인덱스 초기화
            continue;
        }
        tmp_str[xidx][yidx++] = str1[i]; // 2차원 배열에 단어 저장
    }
    tmp_str[xidx][yidx++] = ' '; // 마지막 단어 뒤에 공백 추가


    for(int i=0; i<cnt; i++){ // 두 번째 입력값 중복 비교
        if(strcmp(str2,tmp_str[i]) == 0){ // 중복일시 체크
            check = 1;
            break;
        }
    }


    if(check == 0){ // 중복이 아닌경우

        cnt++; // 카운트 추가
        xidx++;
        for(int i=0; i<strlen(str2); i++) // 두 번째 단어 2차원 배열에 저장
            tmp_str[xidx][i] = str2[i];
    
    }
    
    for(int i=0; i<cnt; i++) // 단어 하나씩 출력
        printf("%s\n",tmp_str[i]);

    for(int i=0; i<cnt-1; i++){ // 사전순 비교를 위한 반복문

        for(int j=i+1; j<cnt; j++){

            if(strcmp(tmp_str[i],tmp_str[j]) > 0){ // 앞에 단어가 사전상 늦으면 스왑
                strcpy(tmp,tmp_str[i]);
                strcpy(tmp_str[i],tmp_str[j]);
                strcpy(tmp_str[j],tmp);
            }

        }

        strcat(result, tmp_str[i]); // 인덱스 i는 사전상 가장 빠른 단어 고정이므로 새로운 배열에 접합

    }
    strcat(result, tmp_str[cnt-1]); // 마지막 단어 접합

    for(int i=0; i<strlen(result); i++) // 출력
        printf("%c", result[i]);


   return 0;
}