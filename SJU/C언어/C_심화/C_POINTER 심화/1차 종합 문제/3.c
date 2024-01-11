#include <stdio.h>
#pragma warning (disable:4996)

typedef struct pp {
	int x, y;
}point;

int main() {
	int N, max = 0, min = 9999999, idx1 = 0, idx2 = 0;
	scanf("%d", &N);
	point p[4];
	for (int i = 0; i < N; i++) 
		scanf("%d %d", &p[i].x, &p[i].y);
	
	for (int i = 0; i < N; i++) {
		if (max < p[i].x) {
			max = p[i].x;
			idx1 = i;
		}
		if (min > p[i].x) {
			min = p[i].x;
			idx2 = i;
		}
	}
	printf("%d %d\n", p[idx2].x, p[idx2].y);
	printf("%d %d\n", p[idx1].x, p[idx1].y);
	return 0;
}