#include <stdio.h>
#include <string.h>

int main(){
	int N,tmp;
	int cnt=0;
	scanf("%d",&N);
	int ar[5];
	int *p = ar;
	tmp = N;
	while(tmp > 0){
		tmp = tmp / 10;
		cnt++;
	}
	p = ar + cnt - 1;
	for(int i=N; i>0; i=i/10){
		tmp = i % 10;
		*p = tmp;
		p--;
	}
	p = ar;
	for(int i=cnt; i>0; i--){
	switch(*p){
		case 1 : printf("one ");
		switch(i){
			case 4 : printf("THO ");
				break;
			case 3 : printf("HUN ");
				break;
			case 2 : printf("TEN ");
				break;
			default : break;
		}
			break;
		case 2 : printf("two ");
		switch(i){
			case 4 : printf("THO ");
				break;
			case 3 : printf("HUN ");
				break;
			case 2 : printf("TEN ");
				break;
			default : break;
		}
			break;
		case 3 : printf("three ");
		switch(i){
			case 4 : printf("THO ");
				break;
			case 3 : printf("HUN ");
				break;
			case 2 : printf("TEN ");
				break;
			default : break;
		}
			break;
		case 4 : printf("four ");
		switch(i){
			case 4 : printf("THO ");
				break;
			case 3 : printf("HUN ");
				break;
			case 2 : printf("TEN ");
				break;
			default : break;
		}
			break;
		case 5 : printf("five ");
		switch(i){
			case 4 : printf("THO ");
				break;
			case 3 : printf("HUN ");
				break;
			case 2 : printf("TEN ");
				break;
			default : break;
		}
			break;
		case 6 : printf("six ");
		switch(i){
			case 4 : printf("THO ");
				break;
			case 3 : printf("HUN ");
				break;
			case 2 : printf("TEN ");
				break;
			default : break;
		}
			break;
		case 7: printf("seven ");
		switch(i){
			case 4 : printf("THO ");
				break;
			case 3 : printf("HUN ");
				break;
			case 2 : printf("TEN ");
				break;
			default : break;
		}
			break;
		case 8 : printf("eight ");
		switch(i){
			case 4 : printf("THO ");
				break;
			case 3 : printf("HUN ");
				break;
			case 2 : printf("TEN ");
				break;
			default : break;
		}
			break;
		case 9 : printf("nine ");
		switch(i){
			case 4 : printf("THO ");
				break;
			case 3 : printf("HUN ");
				break;
			case 2 : printf("TEN ");
				break;
			default : break;
		}
			break;
		default : break;
	}
	p++;
	}
	return 0;
}