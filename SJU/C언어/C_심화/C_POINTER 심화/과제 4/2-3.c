#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char *A = (char*)malloc(sizeof(char) * 101); // 문자열을 입력 받는 변수 선언
	char *B = (char*)malloc(sizeof(char) * 101);
	if(A == NULL || B == NULL){ // 에러 확인
		printf("Not enough memory!!");
		return -1;
	}
	gets(A); // 입력
	gets(B);

	int A_cnt = 1, B_cnt = 1; // 단어의 개수 변수
	for(int i = 0; ; i++){ // A배열 단어의 개수
		if(*(A+i) == '\0') break;
		if(*(A+i) == ' ')
			A_cnt++;
	}
	for(int i = 0; ; i++){ // B배열 단어의 개수
		if(*(B+i) == '\0') break;
		if(*(B+i) == ' ')
			B_cnt++;
	}

	char **p = (char**)malloc(sizeof(char*) * A_cnt); // 단어를 담을 더블 포인터를 동적할당으로 선언
	char **q = (char**)malloc(sizeof(char*) * B_cnt);
	if(p == NULL || q == NULL){ // 에러 확인
		printf("Not enough memory!");
		return -1;
	}

	int len1 = strlen(A) + 1; // 문자열의 길이
	char *p_tmp = A; // 임의의 포인터에 배열 위치 저장
	int idx1 = 0;
	for(int i = 0; i < len1; i++){
		if(A[i] == ' ' || A[i] == '\0'){ // ' '인 경우
			A[i] = '\0'; // NULL로 저장
			p[idx1] = (char*)malloc(sizeof(char) * (strlen(p_tmp) + 1)); // 단어를 저장 할 공간
			if(p[idx1] == NULL) return -1; // 에러 확인
			strcpy(p[idx1++], p_tmp); // 단어 저장
			p_tmp = p_tmp + strlen(p_tmp) + 1; // 주소 위치 변경
		}
	}

	int len2 = strlen(B) + 1; // 문자열의 길이
	char *q_tmp = B; // 임의의 포인터에 배열 위치 저장
	int idx2 = 0;
	for(int i = 0; i < len2; i++){
		if(B[i] == ' ' || B[i] == '\0'){ // ' '인 경우
			B[i] = '\0'; // NULL로 저장
			q[idx2] = (char*)malloc(sizeof(char) * (strlen(q_tmp) + 1)); // 단어를 저장 할 공간
			if(q[idx2] == NULL) return -1; // 에러 확인
			strcpy(q[idx2++], q_tmp); // 단어 저장
			q_tmp = q_tmp + strlen(q_tmp) + 1; // 주소 위치 변경
		}
	}

	char **ar_result = (char**)malloc(sizeof(char*) * 101); // 최종 단어 저장 할 공간
	int idx3 = 0; 
	for(int i = 0; i < idx1 - 1; i++){ // 2중 for문으로 단어를 접합
		for(int j = 0; j < idx1; j++){
			if(p[i] == p[j]) continue; // 자기자신이 나올 경우 건너뛰기
			char *ar_tmp = NULL; // 임의의 포인터 선언
			ar_tmp = (char*)malloc(sizeof(char) * 101);
			if(ar_tmp == NULL) return -1; // 에러 확인
			strcpy(ar_tmp, p[i]); // 앞에 단어 저장
			strcat(ar_tmp, p[j]); // 뒤에 단어 접합
			
			for(int k = 0; k < idx2; k++){ // 두 번째 배열과 같은 단어가 있는지 확인하는 반복문
				if(strcmp(ar_tmp, q[k]) == 0){ // 같은 단어일 경우
					ar_result[idx3] = (char*)malloc(sizeof(char) * (strlen(ar_tmp) + 1)); // 단어를 담을 공간
					if(ar_result[idx3] == NULL) return -1; // 에러 확인
					strcpy(ar_result[idx3++], ar_tmp); // 단어 저장
					q[k] = "!"; // 단어가 겹치지 않게 변경
					break;
				}
			}
			free(ar_tmp); // 할당 받은 메모리 제거
		}
	}

	for(int i = 0; i < idx3 - 1; i++){ // 버블정렬로 내림차순
		for(int j = 0; j < idx3 - 1 - i; j++){
			if(strlen(ar_result[j]) < strlen(ar_result[j+1])){ // 뒤에 단어의 길이가 클 경우
				char *tmp = ar_result[j]; // 스왑
				ar_result[j] = ar_result[j+1];
				ar_result[j+1] = tmp;
			}
			else if(strlen(ar_result[j]) == strlen(ar_result[j+1])){ // 같을 경우
				if(strcmp(ar_result[j], ar_result[j+1]) > 0){ // 사전순으로
					char *tmp = ar_result[j]; // 스왑
					ar_result[j] = ar_result[j+1];
					ar_result[j+1] = tmp;
				}
			}
		}
	}

	for(int i = 0; i < idx3; i++) // 출력
		printf("%s\n", ar_result[i]);

	for(int i = 0; i < idx3; i++) // 메모리 제거
		free(ar_result[i]);
	free(ar_result);

	free(q); // 메모리 제거
	free(p);

	free(A); // 메모리 제거
	free(B);
	return 0;
}

/*
red orange yellow green blue purple
pink red redorange orangered yellow black bluegreen white purple

apple or ange pineapple coconuts lemons ora nge
appleapple orange orlemons
*/