#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char str1[21] = {}, str2[21] = {}, str3[21] = {}; // 변수 선언
	char fn1[21] = {}, fn2[21] = {};
 	FILE *fp1, *fp2; // 파일 변수 선언
	scanf("%s", fn1); // 파일명 입력
	scanf("%s", fn2);
	getchar(); 
	fgets(str1, 21, stdin); // 파일에 담을 문장 입력
	gets(str2);
	gets(str3);

	fp1 = fopen(fn1, "w"); // 쓰기
	fp2 = fopen(fn2, "w");
	if(fp1 == NULL || fp2 == NULL){ // 에러 확인
		printf("Couldn't open file\n");
		return -1;
	}
	fputs(str1, fp1); // 담기
	fputs(str2, fp1);
	fputs(str3, fp1);
	fputs(str3, fp2);

	fp1 = fopen(fn1, "r"); // 읽기
	fp2 = fopen(fn2, "r");
	if(fp1 == NULL || fp2 == NULL){ // 에러 확인
		printf("Couldn't open file\n");
		return -1;
	}
	fgets(str1, 21, fp1);
	fgets(str2, 21, fp1);
	fgets(str3, 21, fp2);

	while(!feof(fp1)){ 
		fgets(str1, sizeof(str1), fp1);
		fgets(str2, sizeof(str2), fp1);
		fgets(str3, sizeof(str3), fp2);
	}

	fclose(fp1); // 종료
	fclose(fp2);
	return 0;
}

/*
input.txt
output.txt
No pain no gain.
Time is gole.
The die is cast.
*/