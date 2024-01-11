#include <stdio.h>
#include <string.h>

void reverse(char ch[]){
	char tmp;
	char *p=ch;
	int cnt=0;
	while(*p != 0){
		cnt++;
		p++;
	}
	p=ch;
	for(int i=0; i<cnt/2; i++){
		tmp = *(p+i);
		*(p+i) = *(p+cnt-1-i);
		*(p+cnt-1-i) = tmp;
	}
	//p = ch;
}

int main(){
    char str1[41]={0},str2[21]={0};
    int N,M,cnt=0,cnt2=0;
    char tmp;
	int idx=0;
    scanf("%s",str1);
    scanf("%s",str2);
    scanf("%d",&N);
	cnt = strlen(str1);
	if(N > cnt) return -1;
	scanf("%d",&M);

	if(M == 1) reverse(str2);

	cnt = strlen(str1) + strlen(str2) - 1;
	cnt2 = strlen(str1) - 1;

	for(int i=cnt; i>strlen(str2)+N-1; i--)
		str1[i] = str1[cnt2--];

	cnt2 = strlen(str1);

	for(int i=N; i<N+strlen(str2); i++)
		str1[i] = str2[idx++];

	printf("%s",str1);

    return 0;
}