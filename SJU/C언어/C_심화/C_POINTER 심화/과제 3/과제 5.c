#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
	char name[30], subject[10][30];
	int id, sub_num;
	double score[10];
}student;

void sort_s(student S[], int cnt);
void print_s(student S[], int cnt);

int main(){
	char code;
	char name2[30] = {};
	int idx = 0, idx2 = 0;
	student ar[100];
	for(int i=0; i<100; i++){
		scanf("%c", &code);
		if(code == 'I'){
			scanf("%s %d %d", ar[idx].name, &ar[idx].id, &ar[idx].sub_num);
			for(int j=0; j<ar[idx].sub_num; j++)
				scanf("%s %lf", ar[idx].subject[j], &ar[idx].score[j]);
			idx++;
		}
		else if(code == 'S')
			sort_s(ar, idx);
		else if(code == 'D'){
			scanf("%s", name2);
			for(int j=0; j<i; j++){
				if(strcmp(ar[j].name, name2) == 0){
					student tmp;
					for(int k=j; k<i; k++){
						tmp = ar[k];
						ar[k] = ar[k+1];
						ar[k+1] = tmp;
					}
					i--;
				}
			}
		}
		else if(code == 'P')
			print_s(ar, idx);

		else if(code == 'Q')
			return 0;
	}
	return 0;
}

void sort_s(student S[], int cnt){
	student tmp;
	for(int i=0; i<cnt-1; i++){
		for(int j=0; j<cnt-1-i; j++){
			if(strcmp(S[j].name, S[j+1].name) > 0){
			tmp = S[j];
			S[j] = S[j+1];
			S[j+1] = tmp;
			}
		}
	}
	for(int i=0; i<cnt; i++)
		printf("%s %d %d %.2lf %.2lf %.2lf %.2lf\n", S[i].name, S[i].id, S[i].sub_num, S[i].score[0], S[i].score[1], S[i].score[2], S[i].score[3] );
}

void print_s(student S[], int cnt){
	student *tmp = S;
	double avg = 0;

	for(int i = 0; i < cnt; i++){
		for(int j = 0; j < (tmp+i)->sub_num; j++)
			avg = avg + (tmp+i)->score[j];
		// printf("%d ", (tmp+i)->sub_num);
		// printf("%.2lf\n", avg);

		avg = avg / (tmp+i)->sub_num;
		//printf("%s %d %d %.2lf\n", (tmp+i)->name, (tmp+i)->id, (tmp+i)->sub_num, avg);
	}
}

/*
I
Kim 18011001 3 Korean 3.5 English 4.0 Math 2.0
I
Park 18011003 1 Korean 4.0
I
Lee 17012031 4 English 2.0 Math 4.5 Programming 3.8 Korean 3.2
P
S
D Lee
P
Q
*/