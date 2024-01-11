#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_row(int **p, int M, int N);
int check_col(int **p, int M, int N);

int main(){
	int M, N;
	scanf("%d %d", &M, &N);
	int **p = (int**)calloc(M, sizeof(int*));
	for(int i=0; i<M; i++){
		p[i] = (int*)calloc(N, sizeof(int));
		if(p == NULL){
            printf("Not enough memory!!");
			return -1;
        }
	}
	int x, y, z;
	while(1){
		scanf("%d %d %d", &x, &y, &z);
		if( (x == 0 && y == 0) && z == 0 )
			break;
		p[x][y] = z;
	}
	int tmp1, tmp2;
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++)
			printf(" %d", p[i][j]);
		printf("\n");
	}
	tmp1 = check_row(p, M, N);
	tmp2 = check_col(p, M, N);
	if(tmp1 > tmp2)
		printf("%d", tmp1);
	else
		printf("%d", tmp2);

	for(int i=0; i<M; i++)
		free(p[i]);
	free(p);
	return 0;
}

int check_row(int **p, int M, int N){
	int max = 0, cnt1 = 0,cnt2 = 0, idx = 0;
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			if(p[i][j] == 0)
				cnt1++;
			if(p[i][j] != 0){
				if(cnt2 < cnt1)
					cnt2 = cnt1;
				cnt1 = 0;
			}
		}
		if(cnt2 < cnt1)
			cnt2 = cnt1;
		if(max < cnt2)
			max = cnt2;
		cnt1 = 0;
		cnt2 = 0;
	}
	return max;
}

int check_col(int **p, int M, int N){
	int max = 0, cnt1 = 0,cnt2 = 0, idx = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(p[j][i] == 0)
				cnt1++;
			if(p[j][i] != 0){
				if(cnt2 < cnt1)
					cnt2 = cnt1;
				cnt1 = 0;
			}
		}
		if(cnt2 < cnt1)
			cnt2 = cnt1;
		if(max < cnt2)
			max = cnt2;
		cnt1 = 0;
		cnt2 = 0;
	}
	return max;
}

/*
3 5
0 0 5
0 1 15
0 3 25
1 2 35
2 1 45
2 3 55
0 0 0

4 4
0 1 1
0 3 3
1 0 1
1 2 3
2 2 0
2 3 6
3 1 2
0 0 0
*/