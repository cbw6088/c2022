#include "my_header.h"
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h"

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