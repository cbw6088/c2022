#include <stdio.h>
#pragma warning (disable:4996)

int main() {
	char x[101] = { NULL }, y[50][101] = { NULL }, tmp[101] = { NULL };
	char *p = x, *q = x;
	int x_idx = 0, y_idx = 0, idx1 = 0, idx2 = 0;
	gets(x);
	int len = strlen(x);
	for (; p < x + len; p++) {
		if (*p == ' ') {
			*p = '\0';
			strcpy(y[x_idx++], q);
			q = p + 1;
		}
	}
	strcpy(y[x_idx], q);
	x_idx++;
	for (int i = 0; i < x_idx-1; i++) {
		for (int j = i + 1; j < x_idx; j++) {
			if (strcmp(y[i], y[j]) > 0) {
				strcpy(tmp, y[i]);
				strcpy(y[i], y[j]);
				strcpy(y[j], tmp);
			}
		}
	}
	for (int i = 0; i < x_idx; i++)
		printf("%s\n", y[i]);
	return 0;
}