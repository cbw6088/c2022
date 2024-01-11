#include <stdio.h>

int main(){
	int A[11],B[11]; // 배열 선언
	int cnt=0,cnt2=0; // 변수 선언
	int max=0,max2=0;
	int min=10000000,min2=10000000;
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
	printf("%d %d\n",cnt,cnt2); // 각 배열의 크기 출력
	for(; p<A+cnt; p++){
		if(max < *p) // 가장 큰 값
			max = *p;
		if(min > *p) // 가장 작은 값
			min = *p;
	}
	for(; q<B+cnt2; q++){
		if(max2 < *q) // 가장 큰 값
			max2 = *q;
		if(min2 > *q) // 가장 작은 값
			min2 = *q; 
	}
	max > max2 ? printf("%d ",max) : printf("%d ",max2); // 더 큰 수를 비교하여 출력
	min < min2 ? printf("%d",min) : printf("%d",min2); // 더 작은 수를 비교하여 출력

	return 0;
}