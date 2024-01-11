#include <stdio.h>

int main(){
	int A[11],B[11]; // 배열 선언
	int cnt=0,cnt2=0; // 변수 선언
	int *p = A, *q = B; // 포인터 선언 및 배열과 연결
	while(1){ // 무한루프를 이용하여 입력을 받고 종료조건 지정
		scanf("%d",p);
		if(*p == -1) break;
		p++;
		cnt++; // 배열의 크기 체크
	}
	while(1){
		scanf("%d",q);
		if(*q == -1) break; // 종료조건 지정
		q++;
		cnt2++; // 배열의 크기 체크
	}
	p = A; // 포인터 초기화
	q = B;
	for(; p<A+cnt-1; p++){
		for(int *pp=p+1; pp<A+cnt; pp++){ // 이중 포문을 이용하여 내림차순 만들기
			if(*p <*pp){ // 스왑
				int tmp = *p;
				*p = *pp;
				*pp = tmp;
			}
		}
	}
	for(; q<B+cnt2-1; q++){ // 이중 포문을 이용하여 내림차순 만들기
		for(int *qq=q+1; qq<B+cnt2; qq++){
			if(*q<*qq){ // 스왑
				int tmp = *q;
				*q = *qq;
				*qq = tmp;
			}
		}
	}
	p = A; // 초기화
	q = B;
	for(; p<A+cnt; p++){ //포인터 p를 기준으로 q를 반복적으로 비교
		for(q=B; q<B+cnt2; q++){
			if(*p < *q){ // q가 더 클 시 스왑
				int tmp = *p;
				*p = *q;
				*q = tmp;
			}
		}
	}
	p = A; // 포인터 초기화
	q = B;
	for(; q<B+cnt2-1; q++){ // 정리가 안된 q포인터를 오름 차순으로 저장
		for(int *qq=q+1; qq<B+cnt2; qq++){
			if(*q>*qq){
				int tmp = *q;
				*q = *qq;
				*qq = tmp;
			}
		}
	}
	q = B;
	for(; p<A+cnt; p++) // 각 포인터 출력
		printf("%d ",*p);
	printf("\n");
	for(; q<B+cnt2; q++)
		printf("%d ",*q);

	return 0;
}