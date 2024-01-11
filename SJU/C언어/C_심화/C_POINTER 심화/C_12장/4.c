#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
	char name[8];
	double kor, eng, math;
	double avg;
}st;

int main(){
	int N;
	scanf("%d", &N);
	//getchar();
	st *p = (st*)malloc(sizeof(st)*N);
	if(p == NULL){
		printf("Not enough memory!");
		return -1;
	}
	
	for(int i=0; i<N; i++)
		scanf("%s %lf %lf %lf", (p+i)->name, &(p+i)->kor, &(p+i)->eng, &(p+i)->math);

	for(int i=0; i<N; i++)
		(p+i)->avg = ((p+i)->kor + (p+i)->eng + (p+i)->math) / 3;
	
	for(int i=0; i<N; i++){
		printf("%s %.1lf ",(p+i)->name, (p+i)->avg);
		if((p+i)->kor >= 90 || (p+i)->eng >= 90 || (p+i)->math >= 90)
			printf("GREAT ");
		if((p+i)->kor < 70 || (p+i)->eng < 70 || (p+i)->math < 70)
			printf("BAD");
		printf("\n");
	}
	free(p);
	return 0;
}

/*
2
Kim 100 82 34
Young 90 100 99
*/