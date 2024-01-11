#include <stdio.h>

int main(){
	int ar[5],rank[5];
	int *p = ar;
	int *pr = rank;
	int cnt=1;
	for(; p<ar+5; p++)
		scanf("%d",p);
	
	for(p=ar; p<ar+5; p++){
		for(int *tmp=ar; tmp<ar+5; tmp++){
			if(*p < *tmp)
				cnt++;
		}
		*pr = cnt;
		pr++;
		cnt=1;
	}
	p = ar;
	pr = rank;

	for(; p<ar+5; p++){
		printf("%d=r%d ",*p,*pr);
		pr++;
	}

	
}