#include <stdio.h>

int main(void){
    char X[100],Y[100],Z[100];
	int idx=0,cnt=0,ccnt=0,temp=0,M=0,a=0,b=0,c=0;

	while(1){
		scanf("%c",&X[idx++]);
		if(X[idx-1] == '!'){break;}
	} 

	for(int i=0; i<idx; i++){
		for(int j=i; j>=0; j--){
			if(X[i] == X[j]){
				cnt++;
			}
		}
		if(cnt == 1){
			Y[temp++] = X[i];
		}
		cnt=0;
	}

	for(int i=0; i<temp-1; i++){
		printf("%c",Y[i]);
	}

	scanf("%d",&M);
	getchar();

	for(int i=0; i<M; i++){
		scanf("%c",&Z[i]);
	}

	for(int i=0; i<temp; i++){
		for(int j=0; j<M; j++){
			if(Y[i] == Z[j]){
				a = i;
				b = j;
				for(int k=0; k<M-1; k++){
					if(Y[++a] == Z[++b]){
						ccnt++;
					}
				}
			}
		}
		if(ccnt == M-1){
			printf("\n%d",i);
			c = 1;
		}
		ccnt=0;
	}
	if(c == 0){
		printf("\nnone");
	}

    return 0;
}
