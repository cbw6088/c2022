#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100

int main(){
	int cnt = 0, add = 0;
	double avg = 0;
	char ar[MAX_SIZE] = {};
	
	FILE *fp = fopen("data.txt", "w");

	int count = 0, num = 0;
	while(!(feof(stdin))){
		fscanf(stdin, "%d", &num);
		if(feof(stdin) == 1) break;
		fprintf(fp, "%d\n", num);
		count++;
	}
	fclose(fp);

	int sum = 0;
	fp = fopen("data.txt", "r");
	for(int i = 0; i < count; i++){
		fgets(ar, MAX_SIZE, fp);
		int len = strlen(ar);
		sum = 0;
		for(int j = 0; j < len - 1; j++){
			sum = sum * 10;
			sum = sum + ar[k] - '0';
		}
		add = add + sum;
		cnt++;
	}

	avg = (double)(add / cnt);
	printf("%d\n", cnt);
	printf("%d\n", add);
	printf("%.2lf\n", avg);
	return 0;
}

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100

int main(){
	int cnt = 0, add = 0;
	double avg = 0;
	char ar[MAX_SIZE] = {};
	FILE *fp = fopen("data.txt", "w");
	if(fp == NULL) return -1;

	int count = 0, num = 0;
	while(!(feof(stdin))){
		fscanf(stdin, "%d", &num);
		if(feof(stdin) == 1) break;
		fprintf(fp, "%d\n", num);
		count++;
	}
	fclose(fp);

	int sum = 0;
	fp = fopen("data.txt", "r");
	if(fp == NULL) return -1;
	for(int i = 0; i < count; i++){
		fgets(ar, 100, fp);
		int len = strlen(ar);
		sum = 0;
		for(int j = 0; j < len - 1; j++){
			sum = sum * 10;
			sum = sum + ar[j] - '0';
		}
		add = add + sum;
		cnt++;
	}

	avg = (double)(add / cnt);
	printf("%d\n", cnt);
	printf("%d\n", add);
	printf("%.2lf\n", avg);
	fclose(fp);
	return 0;
}
*/