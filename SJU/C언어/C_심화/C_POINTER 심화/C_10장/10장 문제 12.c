#include <stdio.h>
#include <string.h>

int main(){
	char str1[101];
	char str2[101];
	int cnt=0;
	gets(str1);
	gets(str2);
	for(int i=0; i<strlen(str1); i++){
		int check = 0;
		int idx = i;
		int cnt2 = 0;
		for(int j=0; j<strlen(str2); j++){
			if(str1[idx++] == str2[j]){
				cnt2++;
				check = 1;
			}
			else{
				check = 0;
				break;
			}
		}
		if(check == 1){
			i = i + cnt2 - 1;
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}