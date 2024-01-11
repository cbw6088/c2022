#include <stdio.h>

int mian(){
	int N;
	int check2 = 0;
	scanf("%d",&N);
	if(N < 5){
		printf("-1");
		return -1;
	}
	int ar[22];
	int *p = ar;
	for(; p<ar+N; p++)
		scanf("%d",p);
	p = ar;
	for(; p<ar+N-1; p++){
		int check = 0;
		int cnt = 0;
		if(*p == '!')continue;
		for(int *q=p+1; q<ar+N; q++){
			if(*q == *p){
				cnt++;
				check = 1;
				check2 = 1;
				*q = '!';
			}
		}
		if(check == 1)
			printf("%d %d\n",*p, cnt);
	}
	if(check2 == 0)
		printf("0");
	
	return 0;
}