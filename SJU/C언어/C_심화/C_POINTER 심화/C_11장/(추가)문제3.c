#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct rest{
	char name[99];
	int breakfast, lunch, dinner;
} rest;

int main(){
	int N, money = 0;
	scanf("%d", &N);
	rest ar[10];
	for(int i = 0; i < N; i++)
		scanf("%s %d %d %d", ar[i].name, &ar[i].breakfast, &ar[i].lunch, &ar[i].dinner);
	scanf("%d", &money);

	int breakfast = 0;
	int lunch = 0;
	int dinner = 0;
	int max = 0;
	int answer[3] = {};

	for(int i=0; i<N; i++){
		breakfast = ar[i].breakfast; // 아침 저장
		for(int j=0; j<N; j++){
			if(j!=i){ // 아침 먹은 레스토랑이 아닌경우
				lunch = ar[j].lunch; // 점심 저장
				for(int k=0; k<N; k++){
					if(k!=j && k!=i){ // 아침 , 점심 먹은 레스토랑이 아닌경우
						int sum = 0;
						dinner = ar[k].dinner;
						sum = breakfast + lunch + dinner ; // 총 합 저장
						if(max<sum && sum<=money){ //총합이 가장 예산과 근접한 경우
							max = sum; // 저장~
							answer[0] = i;
							answer[1] = j;
							answer[2] = k;
						}
						
					}
				}
			}
			
		}

	}

	printf("%s\n%s\n%s\n%d\n", ar[answer[0]].name, ar[answer[1]].name, ar[answer[2]].name, max);

	return 0;
}



/*
korean 1500 1200 1500
japanese 1000 1500 1500
chinese 1000 1200 2500
italy 1000 1200 3500
6000
*/