#include <stdio.h>
#pragma warning (disable:4996)

void Read(char *c, int N);
void check(char *c1, char *c2, char ch);
void Write(char *c, int N);

int main() {
	int N, M;
	char ch;
	scanf("%d %d", &N, &M);
	getchar();
	char x[100] = { '\0' }, y[100] = { '\0' };
	for (int i = 0; i < N; i++)
		y[i] = '_';
	char *p = x, *q = y;
	Read(p, N);
	for (int i = 0; i < M; i++) {
		scanf("%c", &ch);
		getchar();
		//printf("N : %d\n", N);
		check(p, q, ch);
		Write(q, N);
	}
	return 0;
}

void Read(char *c, int N) {
	char *p = c;
	for (; p < c + N; p++)
		scanf("%c", p);
	getchar();
	//p++;
	//*p = '\0';
}

void check(char *c1, char *c2, char ch) {
	char *p = c1, *q = c2;
	int cnt = 0;
	while (1) {
		if (*p == ch)
			*(q + cnt) = ch;
		p++;
		cnt++;
		if (*p == '\0') break;
	}
}

void Write(char *c, int N) {
	char *p = c;
	for (; p < c + N; p++)
		printf(" %c", *p);
	printf("\n");
}

/*
6 4
abbccd
e
b
a
c
*/