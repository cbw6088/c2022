#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct st{ // 구조체 선언
	char *str; // 구조체 내에 문자열을 담을 포인터 선언
	int cnt1, cnt2, num, pos, result; // 구조체 변수 선언
};

int main(){
	int N;
	scanf("%d", &N); // N 입력
	getchar();
	struct st *p = (struct st*)malloc(sizeof(struct st) * N); // 구조체 동적할당 선언
	for(int i = 0; i < N; i++){
		char tmp[101] = {};
		gets(tmp); // 입력
		p[i].str = (char*)malloc(sizeof(char) * (strlen(tmp) + 1)); // 구조체 내에 포인터 동적할당으로 선언
		if(p[i].str == NULL){ // 에러 검사
			printf("Not enough memory!");
			return -1;
		}
		strcpy(p[i].str, tmp); // 카피
	}

	int len = 0, cnt = 0;
	for(int i = 0; i < N; i++){ // N번 반복
		len = strlen(p[i].str); // 문자열의 크기 저장
		cnt = 0; // 카운트 초기화 
		p[i].cnt2 = len; // 문자열의 크기 저장
		for(int j = 0; j < len; j++){ // 문자열의 크기 만큼 반복
			if(p[i].str[j] >= '0' && p[i].str[j] <= '9'){ // 숫자일 경우
				p[i].num = atoi(&p[i].str[j]); // 정수로 저장
				p[i].pos = j + 1; // 위치 저장
				continue;
			}
			else if(p[i].str[j] != 'a' && p[i].str[j] !=  'e' && p[i].str[j] != 'i' && p[i].str[j] != 'o' && p[i].str[j] != 'u'){
				if(p[i].str[j] != 'A' && p[i].str[j] !=  'E' && p[i].str[j] != 'I' && p[i].str[j] != 'O' && p[i].str[j] != 'U')
					cnt++; // 자음일 경우 카운트
			}
		}
		p[i].cnt1 = cnt; // 자음 수 저장
		p[i].result = p[i].cnt1 * p[i].cnt2 * p[i].num * p[i].pos; // 값들의 곱 저장
	}

	struct st tmp; // 스왑 할 임의의 변수
	for(int i = 0; i < N - 1; i++){ // 버블정렬
		for(int j = 0; j < N - 1 - i; j++){
			if(p[j].result < p[j+1].result){ // 내림차순을 하기 위한 조건
				tmp = p[j]; // 스왑
				p[j] = p[j+1];
				p[j+1] = tmp;
			}
		}
	}

	for(int i = 0; i < N; i++) // 출력
		printf("%s\n", p[i].str);

	for(int i = 0; i < N; i++) // 제거
		free(p[i].str);
	free(p); // 제거
	return 0;
}

/*
5
His0tory
3Politics
2DonQuixote
LaPest9e
Chaos5
*/