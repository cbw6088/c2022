#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
	int id, n1, n2, n3;
	double avg;
}student;

void average(student A[], int i);

int main(){
	int N;
	scanf("%d", &N);
	student ar[10] = {};
	student tmp;

	for(int i=0; i<N; i++){
		scanf("%d", &ar[i].id);
		average(ar, i);
	}

	for(int i=0; i<N-1; i++){
		for(int j=i+1; j<N; j++){
			if(ar[i].id > ar[j].id){
				tmp = ar[i];
				ar[i] = ar[j];
				ar[j] = tmp;
			}
		}
	}


	for(int i=0; i<N; i++)
		printf("%04d %.1lf\n", ar[i].id, ar[i].avg);
	return 0;
}

void average(student A[], int i){
	student *p = A + i;
	scanf("%d %d %d", &p->n1, &p->n2, &p->n3);
	p->avg = (double)(p->n1 + p->n2 + p->n3) / 3;
}

/*
3
0011 90 95 90
0005 80 85 80
0003 70 75 70
*/