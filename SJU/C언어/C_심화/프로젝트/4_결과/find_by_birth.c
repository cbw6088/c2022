#include "my_header.h"
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"

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