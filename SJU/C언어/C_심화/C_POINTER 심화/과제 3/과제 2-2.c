#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student{ // 구조체 선언
	char name[21]; // 구조체 내부 원소
	int kor, eng, math;
	double avg;
}; // 구조체 자료형 이름 선언

void read_data(struct student *A, int N); // 원형함수
void sort_score(struct student *A, int N);
struct student *select_out(struct student *A, struct student *B, int N);

int main(){
	int N; // 변수 선언
	scanf("%d", &N); // N값 입력
	struct student ar1[N], ar2[N]; // 구조체 자료형으로 배열 선언
	struct student *p; // 결과로 나오는 배열의 주소를 받을 포인터 선언

	read_data(ar1, N); // 함수 선언
	read_data(ar2, N);

	sort_score(ar1, N); // 함수 선언
	sort_score(ar2, N);

	p = select_out(ar1, ar2, N); // 반환선언 및 반환되는 값 변수에 저장

	for(int i=0; i<N; i++) // 출력
		printf("%s %d %d %d %.1lf\n", (p+i)->name, (p+i)->kor, (p+i)->eng, (p+i)->math, (p+i)->avg);

	return 0;
}

void read_data(struct student *A, int N){
	struct student *p = A; // 배열을 받을 포인터 선언
	for(; p < A + N; p++){
		scanf("%s %d %d %d", p->name, &p->kor, &p->eng, &p->math); // 배열의 원소에 값 입력
		p->avg = (p->kor + p->eng + p->math) / 3.0; // 평균값 저장
	}
}

void sort_score(struct student *A, int N){
	struct student *p = A; // 배열을 받을 포인터 선언
	struct student tmp; // 스왑에 필요한 임시 포인터 선언
	for(; p < A + N - 1; p++){
		for(struct student *q = p + 1; q < A + N; q++){
			if(p->avg < q->avg){ // 뒤 배열의 평균 점수가 더 높은 경우
				tmp = *p; // 스왑
				*p = *q;
				*q = tmp;
			}
			else if(p->avg == q->avg){
				if(p->kor < q->kor){
					tmp = *p; // 스왑
					*p = *q;
					*q = tmp;
				}
				else if(p->kor == q->kor){
					if(p->eng < q->eng){
						tmp = *p; // 스왑
						*p = *q;
						*q = tmp;
					}
				}
			}
		}
	}
}

struct student *select_out(struct student *A, struct student *B, int N){
	struct student *p = A, *q = B; // 배열을 받을 포인터 선언
	p = A + (N/2); // 포인터 위치를 정렬된 배열의 중간 인덱스로 지정
	q = B + (N/2);
	double tmp1 = p->avg, tmp2 = q->avg; // 변수에 포인터의 평균값 저장
	p = A; // 포인터 초기화
	q = B;

	if(tmp1 > tmp2)
		return A; // 중간 인덱스의 값이 더 큰 값의 주소 반환
	else
		return B;
}

/*
5
Kim 100 85 80
Lee 88 94 92
Park 92 100 100
Hong 84 82 85
Nam 80 84 72
Song 100 90 97
Lee 92 82 93
Park 80 84 72
Choi 97 80 90
Chung 100 94 93
*/