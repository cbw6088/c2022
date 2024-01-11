#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct parking_info{ // 구조체 선언
	int num, HP, day ,min; // 구조체에 필요한 원소 선언
	char SD, YN;
	double won;
};

void input(struct parking_info *p, int N); // 원형함수 선언
void compute(struct parking_info *p);
void display(struct parking_info *p, int N);
void bike_info_sort(struct parking_info *p, int N);

int main(){
	int N; 
	scanf("%d", &N); // N 입력
	struct parking_info car[100] = {}; // 구조체 자료형 배열 선언
	struct parking_info *p = car; // 포인터 선언 및 배열과 연결
	input(p, N); // 입력 함수 선언
	p = car; // 포인터 초기화
	for(; p < car + N; p++)
		compute(p); // 요금 계산 함수 선언
	p = car;
	bike_info_sort(p, N); // 내림차수 함수 선언
	p = car;
	display(p, N); // 출력 함수 선언
	
	return 0;
}

void input(struct parking_info *p, int N){
	struct parking_info *q = p; // 포인터 선언 및 연결
	for(; q < p + N; q++){
		scanf("%d %d %c", &q->num, &q->HP, &q->SD); // 입력
		getchar();

		if(q->SD == 'S') // 상품이 S인 경우
			scanf("%c %d %d", &q->YN, &q->day, &q->min);

		else if(q->SD == 'D') // 상품잉 D인 경우
			scanf("%d", &q->min);

	}	
}

void compute(struct parking_info *p){
	int normal = 240; // 기본 시간 240분 
	int tmp = p->min - normal; // 240분을 넘는 만큼의 값
	if(p->SD == 'S' && p->YN == 'Y'){ // 상품이 S면서 정기권인 경우
		if(p->min <= normal) // 기본 시간인 경우
			p->won = 0;
		else // 기본 시간보다 초과한 경우
			p->won = 0;
			for(int i= tmp; i > 10; i = i - 10)
				p->won = p->won + 200; // 10분당 200원씩 추가
	}
	else if(p->SD == 'S' && p->YN == 'N'){ // 상품이 S면서 정기권이 아닌 경우
		if(p->day == 7){ // 7일권인 경우
			if(p->min <= normal) // 기본 시간인 경우
				p->won = 30000;
			else{ // 기본 시간보다 초과한 경우
				p->won = 30000;
				for(int i = tmp; i >= 10; i = i - 10)
					p->won = p->won + 200; // 10분당 200원씩 추가
			}
		}

		else if(p->day == 30){ // 30일권인 경우
			if(p->min <= normal) // 기본 시간인 경우
				p->won = 100000;
			else{ // 기본 시간보다 초과한 경우
				p->won = 100000;
				for(int i = tmp; i >= 10; i = i - 10)
					p->won = p->won + 200; // 10분당 200원씩 추가
			}
		}

		else if(p->day == 180){ // 180일권인 경우
			if(p->min <= normal) // 기본 시간인 경우
				p->won = 500000;
			else{ // 기본 시간보다 초과한 경우
				p->won = 500000;
				for(int i = tmp; i >= 10; i = i - 10)
					p->won = p->won + 200; // 10분당 200원씩 추가
			}
		}
	}
	else if(p->SD == 'D'){ // 상품이 D인 경우
		if(p->min <= normal) // 기본 시간인 경우
			p->won = 5000;
		else{ // 기본 시간보다 초과한 경우
			p->won = 5000;
			for(int i = tmp; i >= 10; i = i - 10)
				p->won = p->won + 200; // 10분당 200원씩 추가
		}
	}
}

void display(struct parking_info *p, int N){
	double D_add = 0, S_add = 0, SD_add = 0; // 변수 선언
	struct parking_info *q = p; // 포인터 선언 및 연결
	for(; q < p + N; q++)
		printf("%d %d %c %.lf\n", q->num, q->HP, q->SD, q->won); // 출력
	q = p;
	for(; q < p + N; q++){ 
		if(q->SD == 'D') // 상품이 D인 경우 값 모두 더하기
			D_add = D_add + q->won;
		else if(q->SD == 'S') // 상품이 S인 경우 값 모두 더하기
			S_add = S_add + q->won;
	}
	SD_add = S_add + D_add; // 상품 D 와 S 모두 더하기
	printf("%.lf %.lf %.lf", D_add, S_add, SD_add); // 출력
}

void bike_info_sort(struct parking_info *p, int N){
	struct parking_info *q = p; // 포인터 선언 및 출력
	struct parking_info tmp; // 스왑할 임의의 변수 선언
	for(; q < p + N - 1; q++){ 
		for(struct parking_info *qq = q + 1; qq < p + N; qq++){
			if(q->SD > qq->SD){ // 상품이 D인 경우 앞으로 보내기
				tmp = *q; // 스왑
				*q = *qq;
				*qq = tmp;
			}
		}
	}
	q = p;
	for(; q < p + N - 1; q++){ 
		for(struct parking_info *qq = q + 1; qq < p + N; qq++){
			if(q->SD == 'D' && qq->SD == 'D'){ // D인것 중에 차량 번호 순으로 정렬
				if(q->num > qq->num){
					tmp = *q;
					*q = *qq;
					*qq = tmp;
				}
			}
			else if(q->SD == 'S' && qq->SD == 'S'){
				if(q->num > qq->num){ // S인것 중에 차량 번호 순으로 정렬
					tmp = *q;
					*q = *qq;
					*qq = tmp;
				}
			}
		}
	}
	
}

/*
4
1111 12345678 S N 7 230
2222 22223333 D 240
3333 44445555 D 255
4444 66667777 S Y 30 200
*/

/*
6
3777 28171652 S Y 30 348
1989 97027706 D 429
7757 25158262 S Y 30 392
2714 15392245 D 560
8506 12389677 D 47
5113 59262609 S N 30 967
*/