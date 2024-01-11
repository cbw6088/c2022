#include <stdio.h>
#include <string.h>

int main(void) {
	char arr[100];
	char temp;
	int idx=0;
	
	scanf("%s",arr);

	while(arr[idx] != 0){
		idx++;
	}

	for(int i=0; i<idx; i++){
		printf("%s\n",arr);

		for(int j=0; j<idx-1; j++){
			temp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = temp;
		}
	}

	return 0;
}