#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void input(int *p, int M);
int *sel_max(int *p, int M);
void output(int *p, int N);

int main(){
	int in[100] = {}, out[100] = {};
	int *max, i, N, M;
	scanf("%d %d", &N, &M);
	for(i = 0; i < N; i++){
		input(in, M);
		max = sel_max(in, M);
		out[i] = *max;
	}
	output(out, N);
	return 0;
}

void input(int *p, int M){
	int *q = p;
	for(; q < p + M; q++)
		scanf("%d", q);
}

int *sel_max(int *p, int M){
	int *q = p;
	int cnt = 0, max = 0, idx1 = 0, idx2 = 0;
	for(; q < p + M; q++){
		for(int *f = q; f < p + M; f++){
			if(*q == *f)
				cnt++;
		}
		if(cnt > max){
			max = cnt;
			idx2 = idx1;
		}
		cnt = 0;
		idx1++;
	}
	q = p;
	return q + idx2;
}

void output(int *p, int N){
	int *q = p;
	for(; q < p + N; q++)
		printf(" %d", *q);
} 

/*
3 5
1 2 2 1 3
2 4 2 4 3
1 2 3 4 5
*/