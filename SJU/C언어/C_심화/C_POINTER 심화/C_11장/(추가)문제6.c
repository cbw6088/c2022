#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
	char name[11];
	double kor, eng, math;
}student;

typedef struct subject{
	double koravg, engavg, mathavg;
	char top[11];
}subject;

struct subject average(struct student st[], int N);

int main(){
	int N;
	scanf("%d", &N);
	student ar[10];
	subject ar2;
	for(int i=0; i<N; i++)
		scanf("%s %lf %lf %lf", ar[i].name, &ar[i].kor, &ar[i].eng, &ar[i].math);

	ar2 = average(ar, N);
	printf("kor=%.1lf\n", ar2.koravg);
	printf("eng=%.1lf\n", ar2.engavg);
	printf("math=%.1lf\n", ar2.mathavg);
	printf("top=%s\n",ar2.top);
	return 0;
}

struct subject average(struct student st[], int N){
	double max = 0, avg = 0, avg1 = 0, avg2 = 0, avg3 = 0;
	int idx = 0, cnt;
	student *p = st;
	subject q;
	for(; p < st + N; p++){
		avg1 = avg1 + p->kor;
		avg2 = avg2 + p->eng;
		avg3 = avg3 + p->math;
	}
	q.koravg = avg1 / (double)N;
	q.engavg = avg2 / (double)N;
	q.mathavg = avg3 / (double)N;

	p = st;
	for(; p < st + N; p++){
		avg = (p->kor + p->eng + p->math) / 3.0;
		if(max < avg){
			max = avg;
			cnt = idx;
		}
		idx++;
	}
	p = st;
	strcpy(q.top, (p+cnt)->name);

	return q;
}

/*
3
kim 90 95 90
tom 80 85 80
john 70 75 75
*/