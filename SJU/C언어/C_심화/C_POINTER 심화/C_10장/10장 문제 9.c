#include <stdio.h>
#include <string.h>

int check(char *p);

int main(){
	char ar[30];
	int cnt;
	scanf("%s",ar);
	char *p = ar;
	cnt = strlen(p);
	//check(p);
	printf("%d %d",cnt,check(p));
	return 0;
}

int check(char *p){
	int cnt = strlen(p);
	char arr[30]={};
	int tmp=cnt;
	char *p2=arr;
	//printf(" %d",cnt);
	for(int i=0; i<cnt; i++){
		*p2 = *(p+tmp-1);
		tmp--;
		p2++;
	}
	p2 = arr;
	// printf("%s %s\n",p,p2);
	if(strcmp(p,p2) == 0){
		//printf("회문!!");
		return 1;
	}
	else{
		//printf("회문 아님!!");
		return 0;
	}
}