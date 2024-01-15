#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct subject { // 구조체 정의
	char* name; // 구조체 변수 선언
	double score;
};

struct student { // 구조체 정의
	char* name; // 구조체 변수 선언
	char id[5];
	int numSubject;
	struct subject* psub;
	double avg;
};

double getScore(char* cursor); // 점수를 반환해주는 함수

int main(void) {
	int n;

	struct student* stu;

	char* info = (char*)malloc(sizeof(char) * 101); // 입력 받을 포인터 동적할당으로 선언
	if (info == NULL) return -1; // 오류 검사

	char* cursor = NULL; // 주소를 기억 할 포인터 선언

	int info_num = 0; // ' '의 인덱스를 기억 할 변수 선언

	scanf("%d", &n); // 입력
	getchar();

	stu = (struct student*)malloc(sizeof(struct student) * n); // 값을 저장 할 포인터 동적할당으로 선언
	if(stu == NULL) return -1; // 오류 검사

	for (int i = 0; i < n; i++) {
		gets(info); // 입력

		/* struct student 구조체 내용 동적 할당 및 초기화 */
		stu[i].name = (char*)malloc(sizeof(char) * 101);
		stu[i].psub = (struct subject*)malloc(sizeof(struct subject) * 10);
		stu[i].numSubject = 0;

		info_num = 0;
		
		/* cursor는 문자열을 띄어쓰기 기준으로 위치를 가르키는 포인터 */
		cursor = info; // 주소 저장

		int len = strlen(info); // 문자열의 크기 저장
		int index = 0;

		/* info 정보 띄어쓰기 기준으로 나누어 struct student 구조체에 저장 */
		for (int j = 0; j <= len; j++) {
			if (info[j] == ' ' || info[j] == '\0') { // 공백 혹은 NULL 일 경우
				info[j] = '\0'; // NULL값 저장

			if (info_num == 0) {
				/* 처음엔 name에 복사 */
				strcpy(stu[i].name, cursor);
			}
			else if (info_num == 1) {
				/* 두번째엔 id에 복사 */
				strcpy(stu[i].id, cursor);
			}
			else if (info_num % 2 == 0) {
				/* 이후 짝수번째라면, subject의 name에 복사 */
				stu[i].psub[index].name = (char*)malloc(sizeof(char) * 101); // 동적할당으로 선언
				if(stu[i].psub[index].name == NULL) return -1; // 오류 검사
				strcpy(stu[i].psub[index].name, cursor); // 과목 명 저장
				stu[i].numSubject++; // 과목 수 ++
				
			}
			else if (info_num % 2 == 1) {
				/* 이후 홀수번째라면, subject의 score에 정보 저장 */
				stu[i].psub[index++].score = getScore(cursor); // 점수 저장 (함수에서 char형을 double형으로 저장)           
			}
			info_num++; // 인덱스 추가

			cursor = info + j + 1; // 공백 다음으로 주소 저장

			}
		}
	}
	int K;
	double avg = 0;
	scanf("%d", &K); // 입력
	K = K - 1; 

	for(int i = 0; i < n; i++){
		for(int j = 0; j < stu[i].numSubject; j++)
			avg = avg + stu[i].psub[j].score; // 점수 모두 합
		avg = avg / stu[i].numSubject; // 평균값 구하기
		stu[i].avg = avg; // 평균값 저장
		avg = 0; // 초기화
	}

	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - 1 - i; j++){
			if(stu[j].avg < stu[j+1].avg){ // 평균값 비교
				struct student tmp = stu[j]; // 스왑
				stu[j] = stu[j+1];
				stu[j+1] = tmp;
			}
			else if(stu[j].avg == stu[j+1].avg){ // 같을 경우
				if(strcmp(stu[j].id, stu[j+1].id) > 0){ // 학번 비교
					struct student tmp =  stu[j]; // 스왑
					stu[j] = stu[j+1];
					stu[j+1] = tmp;
				}
			}
		}
	}

	printf("%s %s %.2lf ", stu[K].name, stu[K].id, stu[K].avg); // 출력

	double max = 0;
	int tidx = 0;
	for(int i = 0; i < stu[K].numSubject; i++){
		if(max < stu[K].psub[i].score){ // 가장 큰 점수 찾기
			max = stu[K].psub[i].score;
			tidx = i; // 인덱스 저장
		}
	}
	printf("%s %.2lf", stu[K].psub[tidx].name, stu[K].psub[tidx].score); // 출력


    for(int i = 0; i < n; i++){
        int len_s = strlen(stu[i].psub); // 길이 저장
        for(int j = 0; j < len_s; j++)
            free(stu[i].psub[j].name); // 제거
        free(stu[i].psub); // 제거
        free(stu[i].name);
    }
    free(stu); // 제거
    free(info);
    return 0;
}

/* cursor 주소로 부터 문자로 된 숫자를 double형태로 바꾸어 반환하는 함수 */
double getScore(char* cursor) {
	double num = 0.0; // 변수 선언
	char* temp = cursor; // 주소 저장
	while (*temp != ' ' && *temp != '\0') { // 공백 전까지
		num *= 10; 
		num += ((*temp) - '0'); // 문자를 수로 저장
		temp++;
	}

	return num;
}

/*
5
HongGilDong 1003 Math 85 C 80 AdvC 90
JeonWooChi 1001 English 60 C 75 Physics 80 Math 70
HeungBoo 1002 Economics 80 AdvC 90 Math 80 C 90
NolBoo 1004 Ethics 50 C 62
Euler 1005 Math 100 Physics 90 AdvC 85
2
*/