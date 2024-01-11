#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int binSearch(int a, int b, int n);

int main(){
	int a, b, n;
	scanf("%d %d %d", &a, &b, &n);
	printf("%d", binSearch(a, b, n));
	return 0;
}

int binSearch(int a, int b, int n){
	int mid = (a + b) / 2;
	char ch;
	if(n == 0) return mid;
	scanf(" %c", &ch);
	
	if(ch == 'Y') return binSearch(mid+1, b, n-1);
	else return binSearch(a, mid, n-1);
}