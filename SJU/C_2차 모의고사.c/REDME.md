# Second C_TEST

### C_2차 모의고사 1.c
N개의 양의 정수를 배열에 입력 받은 후, 배열의 각 요소가 몇 번 반복이 되었는지 배 열의 각 요소의 순서대로 반복횟수를 출력하는 프로그램을 작성하시오.
-N은10이상,50이하의양의정수, 10≦N≦50
- 입력되는 양의 정수는 중복 입력이 가능함
- 배열의 각 요소에 대해서, 반복되는 요소의 경우, 첫 번째로 나타난 요소를 기준으로 출력함, 즉 두 번째 부터 나타나는 배열의 요소는 출력하지 않음

<img width="814" alt="스크린샷 2022-07-08 오후 5 27 26" src="https://user-images.githubusercontent.com/99342700/177950980-a14151a8-64b1-420d-bbef-70b6f917444d.png">

1. 각 변수 지정
2. N의 크기만큼 배열을 만들어 값 입력.
3. 자기자신부터 인덱스 0까지 비교하여 같은 수가 자기자신 한개면 새로운 배열에 저장
4. 인덱스를 전체적으로 비교하면서 한번 비교한 인덱스에는 -1을 저장하여 다음 비교에 지장 않가게 세팅.
5. 저장한 배열 출력.

```c++
#include <stdio.h>

int main(void){
	int N=0,cnt=0,idx=0,ccnt=0,num=0,check=0;
	scanf("%d",&N);
	int X[N],Y[N],Z[N];
	for(int i=0; i<N; i++){
		scanf("%d",&X[i]);
	}

	for(int i=0; i<N; i++){
		for(int j=i; j>=0; j--){
			if(X[i] == X[j]){
				ccnt++;
			}
		}
		if(ccnt == 1){
			Z[num++] = X[i];
		}
		ccnt=0;
	}

	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			if(X[i] > 0){
				if(X[i] == X[j]){
					Y[idx] = cnt++; 
					X[j] = -1;
				}
				check = 1;
			}
		}
		if(check == 1){
			Y[idx] = cnt++;
			idx++;
		}
		cnt = 0;
		check = 0;
	}
	
	for(int i=0; i<num; i++){
		printf("%d %d\n",Z[i],Y[i]+1);
	}
	return 0;
}

```