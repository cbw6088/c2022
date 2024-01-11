#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char ch[10] = {}; // 변수 선언
 	FILE *fp1, *fp2;
	fp1 = fopen("test1.txt", "r"); // 오픈
	fp2 = fopen("test2.txt", "w");
	if(fp1 == NULL || fp2 == NULL){ // 에러 확인
		printf("Couldn't open file\n");
		return -1;
	}
	fgets(ch, 10, fp1); // 읽기
	while(!feof(fp1)){ 
		fgets(ch, sizeof(ch), fp1);
	}
	for(int i = 0; i < strlen(ch); i++){ // 대소문자 변경 반복문
		if(ch[i] >= 'A' && ch[i] <= 'Z'){
			ch[i] = ch[i] + 32;
		}
		else if(ch[i] >= 'a' && ch[i] <= 'z'){
			ch[i] = ch[i] - 32;
		}
	}
	fputs(ch, fp2); // 쓰기
	fclose(fp1); // 종료
	fclose(fp2);
	return 0;
}