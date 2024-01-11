#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int *ar,N,tmp,idx;
	ar = (int *)malloc(sizeof(int)*N);
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d",&ar[i]);

	for(int i=N-1; i>0; i--){
		idx = i;
		for(int j=i-1; j>=0; j--){
			if(ar[idx] < ar[j])
				idx = j;
		}
		tmp = ar[idx];
		ar[idx] = ar[i];
		ar[i] = tmp;	
	}

	for(int i=0; i<N; i++)
		printf(" %d",ar[i]);
		return 0;
}