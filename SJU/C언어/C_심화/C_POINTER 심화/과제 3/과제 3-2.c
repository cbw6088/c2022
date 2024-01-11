#include<stdio.h>#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct hotel_info{ // 구조체 선언
	char name[30]; // 구조체 내부 원소
	int G;
	double RP;
	double D;
	char BF;
};

int in_hotel_info(struct hotel_info *p); // 원형함수 선언
void out_hotel_info(struct hotel_info *p, int N, int G, double D);


int main(){
	int N, G; // 변수 선언
	double D;
	struct hotel_info ch[100];
	N = in_hotel_info(ch); // 배열의 길이 저장 및 구조체 배열 입력
	scanf("%d %lf", &G, &D); // 등급과 거리 입력
	out_hotel_info(ch, N ,G, D); // 기준에 맞춰 출력
	return 0;
}

int in_hotel_info(struct hotel_info *p){
	struct hotel_info *q = p; // 포안터 선언 및 연결
	int cnt = 0;
	for(; q < p + 100; q++){ // 최대 100번까지 반복
		scanf("%s", q->name); 
		if(q->name[0] == '0') break; // 0 입력시 브레이크
		getchar();
		scanf("%d %lf %lf %c", &q->G, &q->RP, &q->D, &q->BF);
		cnt++; // 카운트 (배열의 길이)
	}
	return cnt;
}

void out_hotel_info(struct hotel_info *p, int N, int G, double D){
	struct hotel_info *q = p; // 포인터 선언 및 연결
	struct hotel_info tmp; // 스왑 할 변수 선언
	for(; q < p + N - 1; q++){ // 
		for(struct hotel_info *qq = q + 1; qq < p + N; qq++){
			if(q->RP < qq->RP){ // 내림차순으로 정렬
				tmp = *q; // 스왑
				*q = *qq;
				*qq = tmp;
			}
			else if(q->RP == qq->RP){ // 같을 경우
				if(strcmp(q->name, qq->name) > 0){ // 사전상 앞에 있는 문자열로 비교
					tmp = *q; // 스왑
					*q = *qq;
					*qq = tmp;
				}
			}
		}
	}
	q = p;

	for(; q < p + N; q++){
		if(q->G >= G && q->D <= D){ // 기준에 맞는 값 출력 후 종료
			printf("%s %d %.1lf %.1lf %c\n", q->name, q->G, q->RP, q->D, q->BF);
			//break;
		}
	}
}

/*
marriott 4 4.7 12.5 Y
ibis 2 3.5 5.6 N
novotel 3 3.0 2.7 N
renaissance 3 3.5 4.8 N
hyatt 5 3.5 7.4 Y
bestwestern 2 2.5 3.8 Y
0
3 7.5
*/