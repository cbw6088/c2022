#include "my_header.h"
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"

void insert(Tel **tel_list, int max, int count){ // 삽입 함수
	Tel **p = tel_list; // 새로운 포인터와 연결
 	char ntmp[100] = {}, ttmp[100] = {}, btmp[100] = {}; // 변수 선언

	if(count == max || count == 100){ // 인덱스 초과시 종료
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