#include "my_header.h"
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"

void print_all(Tel **tel_list, int count){ // 출력 함수
	Tel **p = tel_list;
	if(count == 0) return; // 출력 할 정보가 없는 경우
	for(int i = 0; i < count; i++) // 전체 출력
		printf("%s %s %s\n", p[i][0].name, p[i][0].tel, p[i][0].birth); 
}