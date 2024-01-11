#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct student{
	char name1[20], name2[20];
	int score, flag;
}student;

int main(){
	int N, cnt = 0, idx = 0;
	double avg = 0;
	char name[20] = {};
	int tmp[10] = {};
	student ar[10];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%s %s %d", ar[i].name1, ar[i].name2, &ar[i].score);
	scanf("%s", name);
	getchar();

	for(int i=0; i<N; i++){
		if(strcmp(name, ar[i].name1) == 0){
			ar[i].flag = 1;
			cnt++;
			tmp[idx++] = i;
		}
		else if(strcmp(name, ar[i].name2) == 0){
			ar[i].flag = 1;
			cnt++;
			tmp[idx++] = i;
		}
		else
			ar[i].flag = 0;
	}

	for(int i=0; i<cnt; i++)
		avg = avg + (double)ar[tmp[i]].score;
	avg = avg / cnt;
	
	int tmp2[10] = {}, min = 100, check = 0;
	idx = 0;
	for(int i=0; i<N; i++){
		if(ar[i].flag == 1){
			tmp2[idx] = avg - ar[i].score > 0 ? avg - ar[i].score : ar[i].score - avg; 
			if(min > tmp2[idx]){
				min = tmp2[idx];
				check = i;
			}
		}
	}

	printf("average = %.2lf\n", avg);
	printf("%s %s %d", ar[check].name1, ar[check].name2, ar[check].score);


	
	return 0;
}

/*
6
gildong hong 70
gildong kim 82
kim jack 65
gill kim 93
elvis kim 94
park lena 89
kim
*/