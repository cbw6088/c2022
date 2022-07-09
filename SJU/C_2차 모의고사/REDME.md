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



### 2차 모의고사 2.c
첫번째‘*’가입력될때까지영어소문자를%c로계속입력받아배열x에저장하 고, 두 번째 ‘*’가 입력될 때 까지 영어 소문자를 %c로 계속 입력 받아 배열 y에 저장한다.
- 즉 두 단어 (first_word, second_word)를 다음과 같이 입력받는다. first_word*second_word*
- ‘*’를 단어에 포함하지 않는다.
- 저장된 두 영어 단어 중에서 사전에서 먼저 나타나는 단어를 출력하시오. - 입력되는 문자수는 최대 100 이다. 각 단어는 문자 1개 이상이다.
- 두 단어가 같은 경우 둘 중 하나를 출력한다.
- 주의: 사전에서 aa 는 aaa 보다 먼저 나타난다.

<img width="567" alt="스크린샷 2022-07-09 오후 6 26 20" src="https://user-images.githubusercontent.com/99342700/178099997-12bb61ce-344f-481a-8bb0-46260b5f0348.png">

1. 필요한 변수 지정.
2. 조건에 맞춰 X,Y배열을 각각 저장.
3. 두 배열을 앞 자리부터 비교하여 두 인덱스 중 작은 크기의 배열이 끝날 때 까지 반복.
4. 큰 배열에 체크를 하고 같으면 다음 인덱스로 넘어가 다시 비교.
5. 체크한 부분의 배열을 출력.
6. 비교한 배열까지 모두 같은 경우 인덱스 차이로 결정이 남으로 인덱스 큰 부분에 체크하고 출력.

```c++
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
```