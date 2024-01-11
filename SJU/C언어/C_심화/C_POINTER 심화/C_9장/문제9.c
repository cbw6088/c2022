#include <stdio.h>

int *mid(int arr[]);

int main(void){
	int arr[3];
	int *p;
	for(p=arr; p<arr+3; p++){
		scanf("%d",p);
	}
	p=arr;

	p=mid(arr);

	printf("%d",*p);
	return 0;
}

int *mid(int arr[]){
	int temp=0;
	int *p = arr;
	if((*p >= *(p+1) && *p <= *(p+2)) || (*p <= *(p+1) && *p >= *(p+2))){
		temp = 0;
	}
	else if((*(p+1) >= *p && *(p+1) <= *(p+2)) || (*(p+1) <= *p && *(p+1) >= *(p+2))){
		temp = 1;
	}
	else if((*(p+2) >= *p && *(p+2) <= *(p+1)) || (*(p+2) <= *p && *(p+2) >= *(p+1))){
		temp = 2;
	}
	return p+temp;
}