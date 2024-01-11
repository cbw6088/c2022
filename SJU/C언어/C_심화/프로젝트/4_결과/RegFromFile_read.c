#include "my_header.h"
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"

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