#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person{
	char name[11];
	double exam1, exam2, avg;
};

void swap(struct person *p, struct person *q);

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	struct person str[100];
	struct person *p = str;
	for(p = str; p < str + N; p++){
		scanf("%s %lf %lf", p->name, &p->exam1, &p->exam2);
		p->avg = (p->exam1 * 0.8) + (p->exam2 * 0.2);
	}
	
	for(p = str; p < str + N - 1; p++){
		for(struct person *q = p + 1; q < str + N; q++){
			if(p->avg < q->avg)
				swap(p, q);
		}
	}

	for(p = str; p < str + M; p++){
		printf("%s %.1lf\n", p->name, p->avg);
	}
	return 0;
}

void swap(struct person *p, struct person *q){
	struct person tmp = *p;
	*p = *q;
	*q = tmp;
}

/*
7 3
Aaaaa 75 85
Bbbbb 86 77
Ccccc 94 82
Ddddd 78 70
Eeeee 65 85
Fffff 83 90
Ggggg 90 70
*/