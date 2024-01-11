#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct parking_info{
	int num, HP, day ,min;
	char SD, YN;
	double won;
};

void input(struct parking_info *p, int N);
void compute(struct parking_info *p);
void display(struct parking_info *p, int N);

int main(){
	int N;
	scanf("%d", &N);
	struct parking_info car[100] = {};
	struct parking_info *p = car;
	input(p, N);
	p = car;
	for(; p < car + N; p++)
		compute(p);
	p = car;
	display(p, N);
	
	return 0;
}

void input(struct parking_info *p, int N){
	struct parking_info *q = p;
	for(; q < p + N; q++){
		scanf("%d %d %c", &q->num, &q->HP, &q->SD);
		getchar();

		if(q->SD == 'S') // 입력
			scanf("%c %d %d", &q->YN, &q->day, &q->min);

		else if(q->SD == 'D')
			scanf("%d", &q->min);

	}	
}

void compute(struct parking_info *p){
	int normal = 240;
	int tmp = p->min - normal;
	if(p->SD == 'S' && p->YN == 'Y'){
		if(p->min <= normal)
			p->won = 0;
		else
			p->won = 0;
			for(int i= tmp; i > 10; i = i - 10)
				p->won = p->won + 200;
	}
	else if(p->SD == 'S' && p->YN == 'N'){
		if(p->day == 7){
			if(p->min <= normal)
				p->won = 30000;
			else{
				p->won = 30000;
				for(int i = tmp; i >= 10; i = i - 10)
					p->won = p->won + 200;
			}
		}

		else if(p->day == 30){
			if(p->min <= normal)
				p->won = 100000;
			// else if(p->min >= normal + 60){
			// 	p->won = 100000;
			// 	for(int i = tmp; i >= 5; i = i - 5)
			// 		p->won = p->won + 200;
			// }
			else{
				p->won = 100000;
				for(int i = tmp; i >= 10; i = i - 10)
					p->won = p->won + 200;
			}
		}

		else if(p->day == 180){
			if(p->min <= normal)
				p->won = 500000;
			else{
				p->won = 500000;
				for(int i = tmp; i >= 10; i = i - 10)
					p->won = p->won + 200;
			}
		}
	}
	else if(p->SD == 'D'){
		if(p->min <= normal)
			p->won = 5000;
		else{
			p->won = 5000;
			for(int i = tmp; i >= 10; i = i - 10)
				p->won = p->won + 200;
		}
	}
}

void display(struct parking_info *p, int N){
	struct parking_info *q = p;
	for(; q < p + N; q++)
		printf("%d %d %c %.lf\n", q->num, q->HP, q->SD, q->won);
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