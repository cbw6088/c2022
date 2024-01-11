#include <stdio.h>
#include <string.h>

int main(){
    char str1[1001] = {}, str2[100][1001] = {}; // 배열 선언
    int K, cnt = 0, max = 0, idx = 0, x_idx = 0, y_idx = 0;
    gets(str1); // 배열 입력
    scanf("%d",&K); // K값 입력

    int size = strlen(str1); // 반복문 횟수를 위한 사이즈 지정
    for(int i=0; i<size; i++){ // 사이즈만큼 반복
        if(str1[i] == ' '){ // 공백일 때 이중 포문에 저장
            str1[i] = 0; // 공백 인덱스 값을 널로 변경
            strcpy(str2[x_idx++], str1 + idx); // 널 전까지의 단어 복사
            idx = i + 1; // 단어의 처음 시작부분 인덱스 저장
        }
    }
    strcpy(str2[x_idx], str1 + idx); // 마지막 단어 저장


    for(int i=0; i<x_idx; i++){ // 이중포문의 단어 갯수 만큼 반복

        char tmp[1001] = {}; // 스왑을 위한 임의의 배열 선언
        for(int j=i+1; j<x_idx+1; j++){ 

            if( strlen(str2[i]) < strlen(str2[j]) ){ // 단어 길이 순으로 저장
                strcpy(tmp, str2[i]); // 스왑
                strcpy(str2[i], str2[j]);
                strcpy(str2[j], tmp);
            }

            else if( strlen(str2[i]) == strlen(str2[j]) ){ // 길이가 같은 경우
                if( strcmp(str2[i], str2[j]) > 0 ){ // 사전순으로 저장
                    strcpy(tmp, str2[i]); // 스왑
                    strcpy(str2[i], str2[j]);
                    strcpy(str2[j], tmp);
                }
            }

        }

    }

    printf("%s",str2[K-1]); // 출력

    return 0;
}