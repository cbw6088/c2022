#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NUM 100

typedef struct tel{ // 구조체 선언
	char *name, *tel, *birth;
}Tel; // 자료형 명 지정

int menu(Tel **tel_list, int max); // 원형함수 선언
void insert(Tel **tel_list, int max, int count);
void print_all(Tel **tel_list, int count);
int delete_user(Tel **tel_list, int count);
void find_by_birth(Tel **tel_list, int count);
int RegFromFile_read(Tel **tel_list, int count);
void RegFromFile_write(Tel **tel_list, int count);
void sort(Tel **tel_list, int count);

int main(){
	int max; // 최대 개수 변수
	printf("Max_num:"); // 지정 출력문
	scanf("%d", &max); // 입력
	Tel **tel_list = (Tel**)malloc(sizeof(Tel*) * MAX_NUM); // 구조체 배열 동적할당으로 선언
	if(tel_list == NULL) return -1; // 에러 확인
	menu(tel_list, max); // 함수 선언
	free(tel_list); // 제거
	return 0;
}

int menu(Tel **tel_list, int max){
	Tel **p = tel_list; // 포인터와 연결
	for(int i = 0; i < max; i++){ 
		p[i] = (Tel*)malloc(sizeof(Tel)); // 배열 동적할당으로 선언
		if(p[i] == NULL) return -1; // 에러 확인
	}
	int count = 0, n, check = 0; // 변수 지정
	while(1){ // 무한루프
		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.RegFromFi le><6.Exit>\n");
		printf("Enter_the_menu_number:");
		scanf("%d", &n); // n의 값 입력
		switch(n){ // n의 값에 따라
			case 1 : insert(p, max, count); // 1일 경우 삽입
					 if(count == max || count == MAX_NUM) break;
					 count++; // 카운트 + 1
				break;
			case 2 : print_all(p, count); // 전체 출력
				break;
			case 3 : check = delete_user(p, count); // 삭제
					 if(check == 1) count--; // 삭제된 경우 카운트 - 1
				break;
			case 4 : find_by_birth(p, count); // 생일 찾기
				break;
			case 5 : count = RegFromFile_read(p, count); // 읽기 함수
				break;
			default : RegFromFile_write(p, count); // 쓰기 함수
				return 0;
		}
		check = 0; // 체크 초기화
	}
	for(int i = 0; i < max; i++){ // 할당 받은 만큼 반복
		free(p[i][0].name); // 제거
		free(p[i][0].tel);
		free(p[i][0].birth);
	}
	for(int i = 0; i < max; i++) // 할당 받은 만큼 반복
		free(p[i]); // 제거
}

void insert(Tel **tel_list, int max, int count){ // 삽입 함수
	Tel **p = tel_list; // 새로운 포인터와 연결
 	char ntmp[100] = {}, ttmp[100] = {}, btmp[100] = {}; // 변수 선언

	if(count == max || count == MAX_NUM){ // 인덱스 초과시 종료
		printf("OVERFLOW\n"); // 지정 출력문
		return; // 종료
	}

	printf("Name:"); // 지정 출력문
	scanf("%s", ntmp); // 각 정보 입력
	p[count][0].name = (char*)malloc(sizeof(char) * (strlen(ntmp) + 1)); // 해당 포인터 동적할당 선언
	if(p[count][0].name == NULL) return; // 에러 확인
	strcpy(p[count][0].name, ntmp); // 카피

	printf("Phone_number:"); // 지정 출력문
	scanf("%s", ttmp);
	p[count][0].tel = (char*)malloc(sizeof(char) * (strlen(ttmp) + 1)); // 해당 포인터 동적할당 선언
	if(p[count][0].tel == NULL) return; // 에러 확인
	strcpy(p[count][0].tel, ttmp); // 카피

	printf("Birth:"); // 지정 출력문
	scanf("%s", btmp);
	p[count][0].birth = (char*)malloc(sizeof(char) * (strlen(btmp) + 1)); // 해당 포인터 동적할당 선언
	if(p[count][0].birth == NULL) return; // 에러 확인
	strcpy(p[count][0].birth, btmp); // 카피
    count++;
	sort(p, count);
	printf("<<%d>>\n", count); // 단어 개수 출력
}

void print_all(Tel **tel_list, int count){ // 출력 함수
	Tel **p = tel_list;
	if(count == 0) return; // 출력 할 정보가 없는 경우
	for(int i = 0; i < count; i++) // 전체 출력
		printf("%s %s %s\n", p[i][0].name, p[i][0].tel, p[i][0].birth); 
}

int delete_user(Tel **tel_list, int count){ // 삭제 함수
	Tel **p = tel_list;
	if(count == 0){ // 지울 정보가 없는 경우
		printf("NO MEMBER\n"); // 지정 출력문
		return 0; // 종료
	}
	char name[21] = {}; // 이름을 입력 받을 변수 선언
	printf("Name:"); // 지정 프린트문
	scanf("%s", name); // 입력
	for(int i = 0; i < count; i++){
		if(strcmp(p[i][0].name, name) == 0){ // 입력 받은 이름과 같은 이름
			for(int j = i; j < count - 1; j++) // 현재 인덱스 부터 마지막 까지
				p[j][0] = p[j + 1][0]; // 한 칸씩 앞으로 이동
			return 1; // 종료
		}
	}
	printf("NO MEMBER\n"); // 지울 정보가 없으면 지정 출력문 출력
	return 0; // 종료
}

void find_by_birth(Tel **tel_list, int count){ // 찾기 함수
	Tel **p = tel_list;
	int birth = 0;
	printf("Birth:"); // 지정 출력문
	scanf("%d", &birth);
	for(int i = 0; i < count; i++){
		int tmp = p[i][0].birth[4] - '0'; // 정수화
		tmp = tmp * 10; // 자릿수 증가
		tmp = tmp + p[i][0].birth[5] - '0'; // 정수화
		if(tmp == birth) // 정수화한 값과 같을 경우
			printf("%s %s %s\n", p[i][0].name, p[i][0].tel, p[i][0].birth); // 출력
	}
}

int RegFromFile_read(Tel **tel_list, int count){ // 읽기 함수
    int cnt = 0;
	Tel **p = tel_list; // 포인터 연결

	FILE *fp = fopen("PHONE_BOOK.txt", "r"); // 읽기
	if(fp == NULL) return cnt; // 에러 확인

    char name[100] = {}, tel[100] = {}, birth[100] = {}; // 읽은값을 입력 받을 변수
	while(1){ // 무한루프
		fscanf(fp, "%s %s %s", name, tel, birth); // 읽기
        if(feof(fp)) break; // 종료 조건
		p[cnt][0].name = (char*)malloc(sizeof(char) * (strlen(name) + 1)); // 동적할당
		p[cnt][0].tel = (char*)malloc(sizeof(char) * (strlen(tel) + 1));
		p[cnt][0].birth = (char*)malloc(sizeof(char) * (strlen(birth) + 1));
        if(p[cnt][0].name == NULL || p[cnt][0].tel == NULL || p[cnt][0].birth == NULL) return cnt;

		strcpy(p[cnt][0].name, name); // 배열에 값 옮기기
		strcpy(p[cnt][0].tel, tel);
		strcpy(p[cnt][0].birth, birth);
		cnt++; // 카운트
	}
	
	sort(p, cnt); // 정렬
	for(int i = 0; i < cnt; i++) // 순차적으로 읽기
		fscanf(fp, "%s %s %s", p[i][0].name, p[i][0].tel, p[i][0].birth);

	fclose(fp); // 제거
    return cnt;
}

void RegFromFile_write(Tel **tel_list, int count){ // 쓰기 함수
	Tel **p = tel_list; // 포인터 연결
	FILE * fp = fopen("PHONE_BOOK.txt", "w"); // 쓰기
	if(fp == NULL) return; // 에러 확인
	for(int i = 0; i < count; i++){
		fputs(p[i][0].name, fp); // 쓰기
		fputs(" ", fp); // 공백 추가
		fputs(p[i][0].tel, fp); // 쓰기
		fputs(" ", fp); // 공백 추가
		fputs(p[i][0].birth, fp); // 쓰기
		fputs("\n", fp); // 공백 추가
	}
	fclose(fp); // 제거
}

void sort(Tel **tel_list, int count){ // 스왑 함수
	Tel **p = tel_list; // 포인터 연결
	for(int i = 0; i < count; i++){
		if(strcmp(p[i][0].name, p[count - 1][0].name) > 0){ // 맨 앞 인덱스 부터 더 뒤의 순서의 이름이 나올 경우
			Tel tmp = p[count - 1][0]; // 입력 받은 이름 저장
			for(int j = count; j > i; j--){ // 맨 뒤 부터 현재 인덱스 까지
				p[j][0] = p[j-1][0]; // 한 칸씩 뒤로 이동
			}
			p[i][0] = tmp; // 해당 인덱스에 입력 값 저장
			break; // 반복문 종료
		}
	}
}
/*
5
1
Kim
00000000000
19980101
1
Gang
11101010101
19940101
1
Park
2223333330101
20000101
2
6





5
1
KimEunJoo
0001112222
2001010
1
Park
+820010101013211221321321
19900101
1
LeeEunJoo_Ms
3401222
19950101
2
3
LeeEunJoo_Ms
2
5
*/