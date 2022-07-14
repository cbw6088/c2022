# Second C_TEST

### C_TEST 1-2.c
정수 N을 입력받는다.
(1) N개의 정수를 입력받아 0보다 큰 정수만 배열에 저장하고, 배열에 저장된 정수의 개수를 출력 한다. 단, N≦100이고, 입력되는 정수 중에 한 개 이상의 양의 정수가 있다고 가정한다.
(2) 배열에 저장된 정수의 개수가 홀수이면, 배열에 저장된 정수를 작은 수부터 큰 수까지 오름차 순으로 정렬하여 출력한다.
(3) 배열에 저장된 정수의 개수가 짝수이면, 배열에 저장된 정수를 큰 수부터 작은 수까지 내림차 순으로 정렬하여 출력한다.
(4) 정렬된 배열에서 홀수가 연속해서 나오는 횟수를 세어서, 이 중 최대 횟수를 출력한다. 예를 들어, 7 9 11과 같이 홀수 3개가 배열에 연속해서 저장된 경우, 홀수가 연속해서 나오는 횟수는 3 회로 센다. 배열에 저장된 정수 중 한 개 이상의 홀수가 있다고 가정한다.

<img width="838" alt="image" src="https://user-images.githubusercontent.com/99342700/178638957-1df01256-b5e1-449b-997e-44f9a867421f.png">

1. 필요한 변수와 배열 지정.
2. 배열에 N의 정수 크기만큼 값 저장.
3. 저장된 정수의 개수가 짝수이면 내림차순 공식 사용.
4. 저장된 정수의 개수가 홀수이면 오름차순 공식 사용.
5. 저장한 값 출력.
6. 저장한 값 중 홀수인 값이 연속으로 나오는 경우 카운트를 세고 카운트 수를 비교하여 가장 긴 카운트 출력.

```c++
#include <stdio.h>

int main(void){
	int N=0,M=0,temp=0,idx=0,cnt=0,cnt2=0,cnt3=0;
	scanf("%d",&N);
	int X[N];

	for(int i=0; i<N; i++){
		scanf("%d",&M);
		if(M > 0){
			X[idx++] = M;
		}
	}
	for(int i=0; i<idx; i++){
		cnt++;
	}
	printf("%d\n",cnt);

	if(cnt%2 == 0){
		for(int i=0; i<idx; i++){
			for(int j=0; j<idx-1; j++){
				if(X[j] <= X[j+1]){
					temp = X[j];
					X[j] = X[j+1];
					X[j+1] = temp;
				}
			}
		}
	}
	else if(cnt%2 != 0){
		for(int i=0; i<idx; i++){
			for(int j=0; j<idx-1; j++){
				if(X[j] >= X[j+1]){
					temp = X[j];
					X[j] = X[j+1];
					X[j+1] = temp;
				}
			}
		}
	}

	for(int i=0; i<idx; i++){
		printf("%d ",X[i]);
	}
	printf("\n");

	for(int i=0; i<idx; i++){
		if(X[i]%2 != 0){
			cnt2++;
		}
		else if(X[i]%2 == 0){
			if(cnt3 <= cnt2){
				cnt3 = cnt2;
			}
			cnt2=0;
		}
	}
	printf("%d",cnt3);
	return 0;
}
```



### C_TEST 2.2.c
정수 N과 M을 입력받고, N개의 양의 정수를 입력받아 배열에 저장한다. 단, 1≦N≦100이고, 1≦M≦N이다.
(1) 배열에 저장된 정수를 앞에서부터 M개씩 묶어서, M개 정수의 평균값보다 크거나 같은 정수를
차례로 출력한다.
(2) 배열에 저장된 정수를 앞에서부터 M개씩 묶어서, M개 정수 중 가장 큰 수를 차례로 출력한 다.
(3) 배열에 저장된 정수를 앞에서부터 M개씩 묶어서, M개 정수 중 가장 작은 수를 차례로 출력한 다.
(4) 배열의 원소를 M개씩 묶고, 마지막 남은 원소의 개수가 M보다 작은 경우, 남은 원소의 평균 보다 크거나 같은 정수, 가장 큰 수, 가장 작은 수를 출력한다. 마지막 남은 원소가 한 개인 경우, 이 원소값이 최대값이자 최소값이 된다.

<img width="846" alt="image" src="https://user-images.githubusercontent.com/99342700/178883321-c79ce229-5224-493a-940f-8fde6e63e3be.png">

1. 필요한 변수 및 배열 지정.
2. 평균값 연산을 이용하여 평균값보다 큰거나 같은 정수 출력.
3. 조건문을 이용하여 0으로 저장한 max값 보다 클 경우 max에 저장하여 출력.
4. 조건문을 이용하여 큰 값으로 저장한 min값 보다 작은 경우 min에 저장하여 출력.

```c++
#include <stdio.h>

int main(void){
	int N=0,M=0,max=0,min=110,idx=0,idx2=0,cnt=0;
	double avg=0,add=0;
	scanf("%d %d",&N,&M);
	int X[N],Y[N],max_cnt[N],min_cnt[N];
	for(int i=0; i<N; i++){
		scanf("%d",&X[i]);
	}

	for(int i=0; i<N; i=i+M){
		for(int j=i; j<i+M && j<N; j++){
			add = add + X[j];
			cnt++;
		}
		avg = add / cnt;

		for(int k=i; k<i+M && k<N; k++){
			if(avg <= X[k]){
				Y[idx++] = X[k];
			}
		}
		cnt=0;
		add=0;
		avg=0;
	}

	for(int i=0; i<idx; i++){
		printf("%d ",Y[i]);
	}
	printf("\n");

	for(int i=0; i<N; i=i+M){
		max = X[i];
		min = X[i];
		for(int j=i; j<i+M && j<N; j++){
			if(max <= X[j]){
				max = X[j];
			}
			if(min >= X[j]){
				min = X[j];
			}
		}
		max_cnt[idx2] = max;
		min_cnt[idx2++] = min;
	}

	for(int i=0; i<idx2; i++){
		printf(" %d",max_cnt[i]);
	}
	printf("\n");
	for(int i=0; i<idx2; i++){
		printf(" %d",min_cnt[i]);
	}
	return 0;
}

```

