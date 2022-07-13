#include <stdio.h>

int main(void){
	int N=0,idx=0,idx2=0,check=0,cnt=0;
	char ch,dh;
	char X[100],Y[100];
	while(1){
		scanf("%c",&ch);
		if(ch == '*'){break;}
		X[idx++] = ch;
	}

	while(1){
		scanf("%c",&dh);
		if(dh == '*'){break;}
		Y[idx2++] = dh;
	}

	for(int i=0; i<idx && i<idx2; i++){
		if(X[i] < Y[i]){
			check = 1;
			break;
		}
		else if(X[i] > Y[i]){
			check = 2;
			break;
		}
		else{
			check = 3;
			continue;
		}
	}
	if(idx <= idx2){
		cnt=1;
	}
	else{
		cnt=2;
	}

	if(check == 1){
		for(int i=0; i<idx; i++){
			printf("%c",X[i]);
		}
	}
	if(check == 2){
		for(int i=0; i<idx2; i++){
			printf("%c",Y[i]);
		}
	}
	if(check == 3){
		if(cnt == 1){
			for(int i=0; i<idx; i++){
				printf("%c",X[i]);
			}
		}
		else if(cnt == 2){
			for(int i=0; i<idx2; i++){
				printf("%c",Y[i]);
			}
		}
	}
	return 0;
}
