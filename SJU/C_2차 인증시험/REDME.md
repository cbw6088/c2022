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
