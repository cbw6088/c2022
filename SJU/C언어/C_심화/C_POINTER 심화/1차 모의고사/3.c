#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void StringAdd(char str[], int index);
int Convertor(char x);

int main(){
	char str[20] = {0};
	int result[20] = {};
	int idx = 0;
	scanf("%s",str);
	StringAdd(str, strlen(str));
	while(str[idx] != 0){
		result[idx] = Convertor(str[idx]);
		idx++;
	}
	printf("%s",str);
	return 0;
}

void StringAdd(char str[], int index){
	int idx = index - 1, cnt = 0, cnt2 = index - 1;

	for(int i = 0; i < index - 1; i++){		
		if(str[cnt] % 2 == 0 && str[cnt+1] % 2 == 0){
			for(int j = idx + 1; j > cnt + 1; j--)
				str[j] = str[cnt2--];
			str[++cnt] = '*';
			idx++;
		}
		else if(str[cnt] % 2 == 1 && str[cnt + 1] % 2 == 1){
			for(int j = idx + 1; j>cnt + 1; j--)
				str[j] = str[cnt2--];
			str[++cnt] = '+';
			idx++;
		}
		cnt2 = idx;
		cnt++;
	}
}

int Convertor(char x){
	int num = 0;
	num = atoi(&x);
	return num;
}