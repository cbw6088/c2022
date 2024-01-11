#include <stdio.h>
#include <string.h>

void print(char *ch, int N);

int main(){
	char ch[100]={};
	char *p = ch;
	int cnt=0,cnt2=0,idx=0,iidx=0,max=0,cnt_max=0;
	scanf("%[^\n]s",p);
	while(1){
		if(*p == '*')
			break;
		p++;
		cnt++;
	} // 배열의 크기 지정

	cnt = cnt+1;
	p = ch;
	for(p=ch; p<ch+cnt; p++){
		idx++;
		if( (*p == ' ') || (*p == '*') ){
			printf("%d\n",cnt2); // 단어별 글자 개수 출력
			if(cnt2 > max){ // 가장 긴 단어의 인덱스 저장
				max = cnt2;
				iidx = idx;
				cnt_max = cnt2;
			}
			cnt2 = 0;
		}
		else
			cnt2++;
	}
	cnt2=0;
	p = ch+iidx-cnt_max-1;
	//printf("%s\n",p);
	
	//printf("%d\n",cnt_max);

	print(p,cnt_max);
	return 0;
}

void print(char *ch, int N){
	char *p = ch;
	int cnt=0;
	for(; p<ch+N; p++){
		if((*p >= 'a') && (*p <= 'z'))
			*p = *p - 32;
			cnt++;
	}
	p = ch;
	for(int i=0; i<N; i++){
		printf("%c",*(p+i));
	}
}