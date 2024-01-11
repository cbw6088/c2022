#include <stdio.h>
#include <string.h>

int main(){
	int N;
	scanf("%d",&N);
	getchar();
	char ch[101]={0},result[101]={0};
	int min = 101;
	for(int i=0; i<N; i++){
		gets(ch); 
		int cnt = 0;
		for(int j=0; j<strlen(ch); j++)
			cnt++;
		cnt = cnt - 1;
		if(min >= cnt){
			min = cnt;
			strcpy(result, ch);			
		}
	}
	printf("%s",result);
	return 0;
}