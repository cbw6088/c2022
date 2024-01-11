#include <stdio.h>

int main(){
	char ch[100]; // 배열 선언
	char *p = ch; // 포인터 선인 및 배열과 연결
	int cnt=0,cnt2=0,max=0,check=0; 
	for(; p<ch+100; p++){
		scanf("%c",p); // 배열에 입력
		cnt++; // 배열 크기 체크
		if(*p == '#') break; // 입력 종료 조건
	}
	p = ch; // 포인터 초기화
	for(; p<ch+cnt; p++){
		if(*p >= 'a' && *p <= 'z'){ // 알파벳 소문자인 경우
			cnt2++;
			check = 1;
		}
		else{
			if(check == 0) continue; // 알파벳 제외 연속 선언 방지
			if(max <= cnt2) // 최대값 구해기
				max = cnt2;
			for(char *q=p-cnt2; q<p; q++) // 알파벳이 아닌 경우 이전까지 단어 출력
				printf("%c",*q);
			printf("\n");
			cnt2=0;
			check = 0;
		}
	}
	printf("%d",max); // 최대값 출력
	return 0;
}