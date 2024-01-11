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
int cal_num(struct reserve *p, int N, int id);

int main(){
	int N;
	scanf("%d", &N);
	struct reserve *p = (struct reserve*)malloc(sizeof(struct reserve) * N);
	if(p == NULL){
		printf("Not enough memory!");
		return -1;
	}
	input(p, N);
	// for(int i=0; i<N; i++)
	// 	printf("%d %s %d\n", p[i].id, p[i].grade, p[i].price);
	struct tot_price tmp;
	scanf("%d", &tmp.id);
	printf("%d", cal_num(p, N, tmp.id));
	free(p);
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

int cal_num(struct reserve *p, int N, int id){
	   struct reserve *q = p;
	   struct tot_price tmp;
	   tmp.total_price = 0;
	   for(; q < p + N; q++){
		   if(q->id == id){
			   printf("%s %d\n", q->grade, q->price);
			   //printf("%d\n", tmp.total_price);
			   tmp.total_price = tmp.total_price + q->price;
		   }
	   }
	return tmp.total_price;
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
123
*/