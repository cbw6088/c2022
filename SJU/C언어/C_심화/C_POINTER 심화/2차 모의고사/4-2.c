#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct reserve{
	int id;
	char grade[4];
	int price;
};

struct tot_price{
	int id;
	int total_price;
};

void input(struct reserve *p, int N);
int cal_num(struct reserve *p, int N);
void cal_sum(struct reserve *p, int N, struct tot_price *q);

int main(){
	int N;
	scanf("%d", &N);
	struct reserve *p = (struct reserve*)malloc(sizeof(struct reserve) * N);
	if(p == NULL){
		printf("Not enough memory!");
		return -1;
	}
	input(p, N);
	int cnt = cal_num(p, N);
	struct tot_price *q = (struct tot_price*)malloc(sizeof(struct tot_price) * cnt);
	cal_sum(p, N, q);
	for(int i=0; i<cnt; i++)
		printf("%d %d\n", (q+i)->id, (q+i)->total_price);

	free(p);
	free(q);
	return 0;
}

void input(struct reserve *p, int N){
	struct reserve *q = p;
	for(; q < p + N; q++){
		scanf("%d %s", &q->id, q->grade);
		if(strcmp(q->grade, "VIP") == 0)
			q->price = 140000;
		else if(strcmp(q->grade, "R") == 0)
			q->price = 110000;
		else if(strcmp(q->grade, "S") == 0)
			q->price = 85000;
		else if(strcmp(q->grade, "A") == 0)
			q->price = 55000;
	}
}

int cal_num(struct reserve *p, int N){
	struct reserve *q = p;
	int cnt = 1, check = 0;
	for(; q < p + N - 1; q++){
		for(struct reserve *l = q + 1; l < p + N; l++){
			if(q->id == l->id)
				check = 1;
		}
		if(check == 0)
			cnt++;
		check = 0;
	}   
	return cnt;
}

void cal_sum(struct reserve *p, int N, struct tot_price *q){
	struct reserve *pp = p;
	struct tot_price *qq = q;
	int cnt = 0, check = 0;
	for(; pp < p + N; pp++){
		for(qq = q; qq < q + N; qq++){
			if(qq->id == pp->id)
				check = 1;
		}
		qq = q;
		if(check == 0){
			qq = q + cnt;
			qq->id = pp->id;
			cnt++;
		}
		check = 0;
	}
	qq = q;
	pp = p;
	for(; qq < q + cnt; qq++){
		for(pp = p; pp < p + N; pp++){
			if(pp->id == qq->id)
				qq->total_price = qq->total_price + pp->price;
		}
	}

}

/*
10
123 A
210 VIP
123 A
123 R
210 S
210 VIP
123 A
523 A
123 R
523 VIP
*/