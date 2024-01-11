#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct record{
	int month, day, sale[10][20];
}record;

int main(){
	int N, buy;
	int cnt = 0;
	record M = {};
	int num[10] = {};
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int j = 0;
		scanf("%d ", &num[i]);
		while(1){
			scanf("%d", &M.sale[i][j]);
			if(M.sale[i][j] == 0) break;
			j++;
		}
	}
	scanf("%d %d %d", &M.month, &M.day, &buy);
	
	for(int i=0; i<N; i++){
		if(num[i] / 100 == M.month){
			if(num[i] % 100 == M.day){
				int j = 0;
				while(M.sale[i][j] != 0){
					if(buy == M.sale[i][j++])
						cnt++;
				}
			}
		}
	}
	
	printf("%d",cnt);
	return 0;
}
/*
3
0901 2 3 2 1 4 0
0902 12 5 4 12 12 1 0
0903 2 3 5 6 0
*/