#include <stdio.h>

int main(void){
	int N=0,cnt1=1;
	scanf("%d",&N);
	int x[N],y[N],z[N],cnt[N];
	double avg[N];
	char ch[N];

	for(int i=0; i<N; i++){
		scanf("%d",&x[i]);
	}
	for(int i=0; i<N; i++){
		scanf("%d",&y[i]);
	}
	for(int i=0; i<N; i++){
		z[i] = i+1;
	}
	for(int i=0; i<N; i++){
		avg[i] = (x[i] * 0.4) + (y[i] * 0.6);
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(avg[i] < avg[j]){
				cnt1++;
			}
		}
		cnt[i] = cnt1;
		cnt1 = 1;
	}
	// for(int i=0; i<N; i++){
	// 	printf("%d ",cnt[i]);
	// }
	for(int i=0; i<N; i++){
		if(cnt[i] <= (N*0.7) || y[i] >= 80){
			ch[i] = 'P';
		}	
		else{
			ch[i] = 'F';
		}
	}

	for(int i=0; i<N; i++){
		printf("%d %d %d %.1lf %d %c\n", z[i], x[i], y[i], avg[i], cnt[i], ch[i]);
	}

	return 0;
}
