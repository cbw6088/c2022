#include <stdio.h>
#include <string.h>
#define MAX_NUM 100 // 최대값 고정

typedef struct tel{ // 구조체 선언
	char name[21]; 
	char tel[16];
	char birth[9];
} Tel; // 자료형 이름 지정

int menu(Tel *tel_list); // 원형함수 선언
void insert(Tel *tel_list, int count);
void print_all(Tel *tel_list, int count);
int delete_tel(Tel *tel_list, int count);
void find_by_birth(Tel *tel_list, int count);

int main(){
	Tel tel_list[MAX_NUM]; // 구조체 배열 선언
	menu(tel_list); // 함수 선언
	return 0;
}

int menu(Tel *tel_list){
	Tel *p = tel_list; // 포인터와 연결
	int count = 0, n, check = 0; // 변수 지정
	while(1){ // 무한루프
		scanf("%d", &n); // n의 값 입력
		switch(n){ // n의 값에 따라
			case 1 : insert(p, count); // 1일 경우 삽입
					count++; // 카운트 + 1
					if(count == 101) return 0; // 최대 카운트 종료조건
				break;
			case 2 : print_all(p, count); // 전체 출력
				break;
			case 3 : check = delete_tel(p, count); // 삭제
					 if(check == 1) count--; // 삭제된 경우 카운트 - 1
				break;
			case 4 : find_by_birth(p, count); // 생일 찾기
				break;
			default : 
				printf("*****Menu*****\n"); // 종료
				printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n"); 
				printf("Enter_the_menu_number:\n");
				return 0;
		}
		check = 0; // 체크 초기화
	}
}

void insert(Tel *tel_list, int count){ // 삽입 함수
	Tel *p = tel_list;
	printf("*****Menu*****\n"); // 지정 프린트문
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n"); 
	printf("Enter_the_menu_number:");
	if(count == 100){ // 카운트가 100일 경우
		printf("OVERFLOW\n");
		return;
	}
	printf("Name:");
	scanf("%s", p[count].name); // 각 정보 입력
	printf("Phone_number:");
	scanf("%s", p[count].tel);
	printf("Birth:");
	scanf("%s", p[count].birth);
	count++; // 카운트 + 1
	if(count == 1) // 첫 입력인 경우
		printf("<<%d>>\n", count); // 단어 개수 출력
	else if(count == 2){ // 두 번째 입력인 경우
		if(strcmp(p[0].name, p[1].name) > 0){ // 크기 비교
			Tel tmp = p[0]; // 스왑
			p[0] = p[1];
			p[1] = tmp;
		}
		printf("<<%d>>\n", count); // 단어 개수 출력
	}
	else{ // 그 외 입력인 경우
		for(int i = 0; i < count - 1; i++){
			if(strcmp(p[i].name, p[count - 1].name) > 0){ // 맨 앞 인덱스 부터 더 뒤의 순서의 이름이 나올 경우
				Tel tmp = p[count - 1]; // 입력 받은 이름 저장
				for(int j = count - 1; j > i; j--){ // 맨 뒤 부터 현재 인덱스 까지
					p[j] = p[j - 1]; // 한 칸씩 뒤로 이동
				}
				p[i] = tmp; // 해당 인덱스에 입력 값 저장
			}
		}
		printf("<<%d>>\n", count); // 단어 개수 출력
	}
}

void print_all(Tel *tel_list, int count){ // 출력 함수
	Tel *p = tel_list;
	printf("*****Menu*****\n"); // 지정 프린트문
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n"); 
	printf("Enter_the_menu_number:");
	if(count == 0) return; // 출력 할 정보가 없는 경우
	for(int i = 0; i < count; i++) // 전체 출력
		printf("%s %s %s\n", p[i].name, p[i].tel, p[i].birth);
}

int delete_tel(Tel *tel_list, int count){ // 삭제 함수
	Tel *p = tel_list;
	printf("*****Menu*****\n"); // 지정 프린트문
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n"); 
	printf("Enter_the_menu_number:");
	if(count == 0){ // 지울 정보가 없는 경우
		printf("NO MEMBER\n"); // 지정 프린트문
		return 0; // 종료
	}
	char name[21] = {}; // 이름을 입력 받을 변수 선언
	printf("Name:"); // 지정 프린트문
	scanf("%s", name); // 입력
	for(int i = 0; i < count; i++){
		if(strcmp(p[i].name, name) == 0){ // 입력 받은 이름과 같은 이름
			for(int j = i; j < count - 1; j++) // 현재 인덱스 부터 마지막 까지
				p[j] = p[j + 1]; // 한 칸씩 앞으로 이동
			return 1; // 종료
		}
	}
	printf("NO MEMBER\n"); // 지울 정보가 없으면 지정 프린트문 출력
	return 0; // 종료
}

void find_by_birth(Tel *tel_list, int count){ // 찾기 함수
	Tel *p = tel_list;
	printf("*****Menu*****\n"); // 지정 프린트문
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n"); 
	printf("Enter_the_menu_number:");
	char birth[2] = {}, tmp[2] = {}; // 변수 선언
	printf("Birth:"); // 지정 프린트문
	scanf("%s", birth); // 입력
	strcpy(tmp, birth); // 새로운 변수에 카피
	int mul = 0; // 계산 할 변수 선언
	for(int i = 0; tmp[i]; i++){
		tmp[i] = tmp[i] - '0'; // 문자열을 정수화
		mul = mul * 10;
		mul = mul + tmp[i];
	}
	if(mul >= 10){ // 10~12월 까지
		for(int i = 0; i < count; i++){
			if(birth[0] == p[i].birth[4] && birth[1] == p[i].birth[5]){ // 두 인덱스를 비교하여 같은 경우
				printf("%s %s %s\n", p[i].name, p[i].tel, p[i].birth); // 출력
			}
		}
	}
	else{ // 1~9월 까지
		for(int i = 0; i < count; i++){
			if(birth[0] == p[i].birth[5]){ // 한 자릿수 인덱스를 비교하여 같은 경우
				printf("%s %s %s\n", p[i].name, p[i].tel, p[i].birth); // 출력
			}
		}
	}
}

/*
KimEunJoo
0101112222
19960101
LeeEunJoo
0103332222
19960202
HangEunJoo
0114445555
20000101
*/