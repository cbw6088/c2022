#include <stdio.h>

int main(void){
	int idx=0,idx2=0,idx3=0,temp=0,M=0,cnt=0,cnt2=0,max=0,check=0,cnt3=0;
	char x[100],y[100],z[100],q[100]; char ch;
	while(1){
		scanf("%c",&ch);
		if(ch == '!')break;
		x[idx++] = ch;
	}

	scanf("%d",&M);

	for(int i=0; i<idx; i++){
		for(int j=i; j>=0; j--){
			if(x[i] == x[j]){
				cnt++;
			}
		}
		if(cnt == 1){
			y[idx2++] = x[i];
		}
		cnt = 0;
	} // 반복제거 for

	for(int i=0; i<idx2; i++){
		printf("%c",y[i]);
	}
	printf("\n");

	for(int i=0; i<idx2; i++){
		if(y[i] >= 'A' && y[i] <= 'Z'){
			temp = y[i] + 32 + M;
			if(temp > 'z'){
				y[i] = temp - 26;
			}
			else{
				y[i] = temp;
			}
		}
		else if(y[i] >= 'a' && y[i] <= 'z'){
			temp = y[i] - 32 + M;
			if(temp > 'Z'){
				y[i] = temp - 26;
			}
			else{
				y[i] = temp;
			}
		}
	} // 대소문자 변경 후 M만큼 이동 for

	for(int i=0; i<idx2; i++){
		printf("%c",y[i]);
	}
	printf("\n");

	for(int i=0; i<idx2; i++){
		if( (y[i] >= 'A' && y[i] <= 'Z') && (y[i+1] >= 'a' && y[i+1] <= 'z') ){
			z[idx3] = y[i];
			z[idx3+1] = y[i+1];
			idx3++;
			cnt2++;
			check = 1;
		}
		else if( (y[i] >= 'a' && y[i] <= 'z') && (y[i+1] >= 'A' && y[i+1] <= 'Z') ){
			z[idx3] = y[i];
			z[idx3+1] = y[i+1];
			idx3++;
			cnt2++;
			check = 1;
		}
		else{
			if(max < cnt2){
				max = cnt2;
				for(int i=0; i<idx3+1; i++){
					q[i] = z[i];
					cnt3 = i;
				}
			}
			idx3 = 0;
			cnt2=0;
		}
	}
	if(check == 1){
		for(int i=0; i<cnt3+1; i++){
			printf("%c",q[i]);
		}
	}
	else{
		printf("\nnone");
	}
	return 0;
}