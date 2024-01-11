#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check(char ar[], char ch[]); // 원형 함수 선언

int main() {
    char ar[21]; // 배열 선언
    char ch[21];
    gets(ar); // 입력
    gets(ch);
    if (check(ar, ch)) { // 정순이 참이면 1 반환 후 1 출력
        printf("1");
    }
    else if (check(ch, ar)) { // 역순이 참이면 1반환 후 2 출력
        printf("2");
    }
    else { // 그 외 0 출력
        printf("0");
    }
    return 0;
}

int check(char str1[], char str2[]) {
    int str1Index = 0, str2Index = 0, N, i; // 변수 선언
    char from = str1[0], to = str2[0]; 
    for (N = 1; N < 11; N++) { // N번 반복
        while (from != '\0') { // 1번 배열이 널이 될 때 까지
            from = str1[str1Index];
            to = str2[str2Index];
            if (from >= 'A' && from <= 'Z') {  //대문자
                if (from + N != to) { // 값이 다르면 종료
                    break;
                }
                str1Index++; // 인덱스 카운트
                str2Index++;
            }
            else if (from >= 'a' && from <= 'z') {  //소문자
                if (from - N != to) { // 값이 다르면 종료
                    break;
                }
                str1Index++; // 인덱스 카운트
                str2Index++;
            }
            else if (from > '0' && from <= '9') {  //숫자
                int number = from - '0'; // 아스키코드가 아닌 정수값 저장
                str1Index++; // 인덱스 카운트
                if (str1[str1Index] > '0' && str1[str1Index] <= '9') { // 다음 배열도 숫자인 경우
                    number = number * 10 + str1[str1Index++] - '0';
                }
                for (i = 0; i < N; i++) { // N번만큼 반복
                    if (number + 'A' - 1 != str2[str2Index++]) { // 값이 다르면 종료
                        break;
                    }
                }
            }
            else {  //그외
                if (to != ' ') {
                    break;
                }
                str1Index++; // 인덱스 카운트
                str2Index++;
            }
        }
        if (strlen(str1) == str1Index && strlen(str2) == str2Index) { // 인덱스가 같을시 1 반환
            return 1;
        }
    }
    return 0;
}