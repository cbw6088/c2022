#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char str1[21] = {}, str2[21] = {}; // 변수 선언
	char fn1[21] = {}, fn2[21] = {};
 	FILE *fp1, *fp2; // 파일 변수 선언
	scanf("%s", fn1); // 파일명 입력
	scanf("%s", fn2);
	getchar(); 
	fgets(str1, 21, stdin); // 파일에 담을 문장 입력
	fgets(str2, 21, stdin);
	fp1 = fopen(fn1, "w"); // 쓰기
	fp2 = fopen(fn2, "w");
	if(fp1 == NULL || fp2 == NULL){ // 에러 확인
		printf("Couldn't open file\n");
		return -1;
	}
	fputs(str1, fp1); // 담기
	fputs(str2, fp1);
	fp1 = fopen(fn1, "r"); // 읽기
		if(fp1 == NULL){ // 에러 확인
		printf("Couldn't open file\n");
		return -1;
	}
	for(int i = 0; i < strlen(str1); i++ ){
		fgetc(fp1); // 읽기
	}
	for(int i = 0; i < strlen(str2); i++ ){
		fgetc(fp1); // 읽기
	}
	while(!feof(fp1)){ 
		fgets(str1, sizeof(str1), fp1);
		fgets(str2, sizeof(str2), fp1);
	}

	for(int i = 0; i < strlen(str1); i++){ // 담기
		fputc(str1[i], fp2);
	}
	for(int i = 0; i < strlen(str2); i++){
		fputc(str2[i], fp2);
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
*/