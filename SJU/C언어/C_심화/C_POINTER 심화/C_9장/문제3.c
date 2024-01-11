#include <stdio.h>

int main(){
	int N,cnt=0;
	scanf("%d",&N);
	int ar[N];
	int *p=ar;
	for(p=ar; p<ar+N; p++)
		scanf("%d",p);
	p=ar;
	for(p=ar; p<ar+N; p++){
		if(*p == 0)
			break;
		cnt++;
	}
	printf("%d",cnt);
}