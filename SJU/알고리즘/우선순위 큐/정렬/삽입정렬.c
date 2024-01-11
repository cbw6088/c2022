#include <stdio.h>
#include <string.h>

int main(){
	int ar[5];
	for(int idx=1; idx<strlen(ar); idx++){ // 1.
		int tmp = ar[idx];
		int prev = idx - 1;
		while( (prev >= 0) && (ar[prev] > tmp) ){ // 2.
			ar[prev+1] = ar[prev];
			prev--;
		}
		arr[prev+1] = tmp; // 3.
	}
	printf("%s",ar);
	return 0;