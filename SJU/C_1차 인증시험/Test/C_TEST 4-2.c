#include <stdio.h>
int main(void){
	char ch,temp; int al=0,dl=0; char first='Z'; char second='Z'; char one,two;

	while(1){
		al = 0;
		temp = ch;
		scanf("%c",&ch);
		if(ch == '!'){return -1;}

		if( (temp >= 'A' && temp <='Z') || (temp >= 'a' && temp <= 'z') ){
			if( (ch < 'A' || ch > 'Z') && (ch < 'a' || ch > 'z') ){
				printf("%c%c\n",one,two);
				first='Z';
				second='Z';
			}
		}

		if( (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')){
			if(ch >= 'a' && ch <= 'z'){
				ch = ch - 32;
				al = 1;
			}

			if(first >= ch){
				if(al == 1){
					ch = ch + 32;
					if(first == ch-32){
						second = ch-32;
						two = ch;
					}
					else{
						second = first;
						first = ch-32;
						two = one;
						one = ch;
					}	
				}
				else{
					second = first;
					first = ch;
					two = one;
					one = ch;
				}
			}
			else if(second >= ch){
				if(al == 1){
					ch = ch + 32;
					second = ch-32;
					two = ch;
				}
				else{
					second = ch;
					two = ch;
				}
			}
		}
	}
  	return 0;
}