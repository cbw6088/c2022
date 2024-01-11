#include <stdio.h>

int main(void){
	int N=0,cnt1=1,check=0; double temp=0;
	scanf("%d",&N);
	int x[N],y[N],z[N],cnt[N];
	double avg[N];
	for(int i=0; i<N; i++){
		scanf("%d",&x[i]);
	}
	for(int i=0; i<N; i++){
		scanf("%d",&y[i]);
	}
	for(int i=0;i<N; i++){
		avg[i] = (x[i]*0.4) + (y[i]*0.6);
	}
	for(int i=0;i<N; i++){
		for(int j=0; j<N; j++){
			if(avg[i] < avg[j]){
				cnt[i] = ++cnt1;
				check = 1;
			}
		}
		if(check == 0){
			cnt[i] = 1;
		}
		check=0;
		cnt1=1;
	}
	
	for(int i=0;i<N; i++){
		if(cnt[i] <= N*0.3){
			z[i] = 'A';
		}
		else if( (cnt[i] > N*0.3 && cnt[i] <= N*0.7) || y[i] >= 60 ){
			z[i] = 'B';
		}
		else{
			z[i] = 'F';
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<N-1; j++){
			if(cnt[j] > cnt[j+1]){
				temp = cnt[j];
				cnt[j] = cnt[j+1];
				cnt[j+1] = temp;
				temp = x[j];
				x[j] = x[j+1];
				x[j+1] = temp;
				temp = y[j];
				y[j] = y[j+1];
				y[j+1] = temp;
				temp = z[j];
				z[j] = z[j+1];
				z[j+1] = temp;
				temp = avg[j];
				avg[j] = avg[j+1];
				avg[j+1] = temp;
			}
		}
	}
	for(int i=0; i<N; i++){
		printf("%d %d %.1lf %d %c\n",x[i],y[i],avg[i],cnt[i],z[i]);
	}
	return 0;
}

//32 30 92 70 70 68 12
//80 35 90 60 60 50 90
