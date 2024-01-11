#include "my_header.h"
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"


int main(){
	int max; // 최대 개수 변수
	printf("Max_num:"); // 지정 출력문
	scanf("%d", &max); // 입력
	Tel **tel_list = (Tel**)malloc(sizeof(Tel*) * 100); // 구조체 배열 동적할당으로 선언
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
					 if(count == max || count == 100) break;
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