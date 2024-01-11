#include "my_header.h"
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"

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