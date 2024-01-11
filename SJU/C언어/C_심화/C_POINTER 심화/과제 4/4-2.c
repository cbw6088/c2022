#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{ // 구조체 선언
	char *name;  // 구조체 변수 선언
	int firstStage;
	int interview;
	double sum;
};

double num(int n1, int n2); // 원형 함수 지정

int main(){
	int N, M; // 변수 선언
	scanf("%d %d", &N, &M); // 입력
	getchar();
	struct student *p = (struct student*)malloc(sizeof(struct student) * N); // 포인터 동적할당으로 선언
	if(p == NULL) return -1; // 오류 검사

	for(int i = 0; i < N; i++){
		char tmp[11] = {};
		scanf("%s %d %d", tmp, &p[i].firstStage, &p[i].interview); // 입력
		p[i].name = (char*)malloc(sizeof(char) * (strlen(tmp) + 1)); // 구조체 안의 포인터 동적할당으로 선언
      if(p[i].name == NULL) return -1; // 오류 검사
		strcpy(p[i].name, tmp);
		p[i].sum = num(p[i].firstStage, p[i].interview); // 점수의 합을 반환하는 함수 값 저장
	}

	for(int i = 0; i < N - 1; i++){
		for(int j = 0; j < N - 1 - i; j++){
			if(p[j].sum < p[j+1].sum){ // 점수의 합 크기 비교
				struct student tmp = p[j]; // 스왑
				p[j] = p[j+1];
				p[j+1] = tmp;
			}
			else if(p[j].sum == p[j+1].sum){ // 크기가 같을 경우
				if(p[j].firstStage < p[j+1].firstStage){ // 첫 번째 점수 비교
					struct student tmp = p[j];  // 스왑
					p[j] = p[j+1];
					p[j+1] = tmp;
				}
				else if(p[j].firstStage == p[j+1].firstStage){ // 점수가 같을 경우
					if(strcmp(p[j].name, p[j+1].name) > 0){  // 사전순으로 정렬
						struct student tmp = p[j]; // 스왑
						p[j] = p[j+1];
						p[j+1] = tmp;
					}
				}
			}
		}
	}

	int cnt = 0, idx = 0;
	while(1){
		if( (p[idx+1].sum == p[idx].sum) && (p[idx+1].firstStage == p[idx].firstStage) ) // 다음 인덱스와 값이 같은 경우
			cnt--; 
		printf("%s %d %d %.1lf\n", p[idx].name, p[idx].firstStage, p[idx].interview, p[idx].sum); // 출력
		cnt++; 
		idx++;
		if(cnt == M || idx == N) break; // 종료 조건
	}
	printf("%d", idx); // 출력 개수 출력

	for(int i = 0; i < N; i++)
		free(p[i].name); // 제거
	free(p); // 제거

	return 0;
}

double num(int n1, int n2){
	double avg = 0, A = 0, B = 0;
	A = (double)(n1 * 0.7); // 첫 번째 점수의 70%
	B = (double)(n2 * 0.3); // 두 번째 점수의 30%
	avg = ((int)((A + B + 0.05) * 10)) * 0.1;
	return avg;
}

/*
7 3
Kim 75 85
Lee 93 63
Park 94 82
Choi 78 70
Jung 65 85
Kang 83 90
Cho 90 70

7 3
Kim 75 85
Lee 96 56
Park 94 82
Choi 78 70
Jung 65 85
Kang 93 63
Cho 93 63
*/