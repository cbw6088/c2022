# C Programming 4차 과제

### 1. C_과제 1-2.c
회문수는 순서대로 읽은 수와 거꾸로 읽은 수가 일치하는 수를 말한다. 예를 들면
34543은 회문수이고, 34567은 회문수가 아니다. 정수 M1과 M2를 먼저 입력받고, 종료 조건까지 정수
N을 반복해서 입력받는다. (1) 정수 N을 한 자리씩 나누어, 가장 마지막 자릿수부터 순차적으로 배열 Y에 저장한다. (정수 N
의 일의 자릿수가 Y[0]의 원소가, 십의 자릿수가 Y[1]의 원소가 되는 방식이다.) (2) 배열 Y의 원소 중 인덱스 M1과 M2 위치의 원소를 삭제한다. 단, M1 또는 M2가 배열 Y의 원소의 수보다 큰 경우, 해당 위치에서 삭제되는 원소는 없다. (3) 배열 Y의 남은 원소로 만들어지는 정수가 회문수이면, 이때의 정수 N을 배열 X에 저장한다. (4) 배열 X에 저장된 정수를 가장 큰 수부터 내림차순으로 정렬하여 출력한다. (5) 입력된 정수 중 조건을 만족하는 정수가 하나도 없는 경우, “none”을 출력한다.
 - 종료 조건 : 0 또는 음수 입력
 - 입력되는 정수의 최대 개수는 100이다.
 - 입력된 정수 N 중에, Y[M1]과 Y[M2]의 자릿수를 삭제한 후, 남는 자릿수가 없는 정수는 없다고 가정한다.

 <img width="587" alt="스크린샷 2022-07-04 오전 2 48 55" src="https://user-images.githubusercontent.com/99342700/177051448-0efe1d33-5e2e-4431-8e02-d3d82fe6d17b.png">

1. 배열 및 정수 변수 지정.
2. for문을 이용하여 입력받은 정수N을 Y배열에 역순으로 저장.
3. for문을 이용하여 입력받은 M1,M2인덱스를 제외한 값을 Z배열에 저장.
4. for문을 이용하여 Z배열의 첫 번째 인덱스와 마지막 인덱스 부터 안쪽으로 차례대로 비교하며 카운트.
5. 만약 인덱스의 값과 비교한 카운트 값이 같을 경우 회문수이므로 X배열에 회문수 저장.
    - 한번이라도 회문수가 나오면 체크.(체크가 한번도 안되면 "none" 출력)
6. X배열 안에있는 값을 내림차순으로 저장.
7. X배열 순서대로 출력.

```c++
#include <stdio.h>

int main(void){
	int X[100]={0},Y[100]={0},Z[100]={0};
	int M1=0,M2=0,N=0,cnt=0,st=0,temp=0,idx=0,result=0,check=0;;
	scanf("%d %d",&M1,&M2);

	while(1){
		scanf("%d",&N);
		if(N < 1){break;}

		for(int i=N; i>0; i=i/10){
			Y[idx++] = i % 10;
			cnt++;
		}
		idx = 0;

		for(int i=0; i<cnt; i++){
			if(i == M1 || i == M2){
				continue;
			}
			else{
				Z[idx++] = Y[i];
			}
		}

		for(int i=0; i<idx; i++){
			if(Z[i] == Z[idx-1-i]){
				temp++;
			}
		}

		if(idx == temp){
			X[result++] = N;
			check = 1;
		}
		temp = 0;
		idx = 0;
		cnt = 0;
	}

	for(int i=0; i<result; i++){
		for(int j=0; j<result; j++){
			if(X[i] > X[j]){
				st = X[i];
				X[i] = X[j];
				X[j] = st;
			}
		}
	}
	if(check == 1){
		for(int i=0; i<result; i++){
			printf("%d ",X[i]);
		}
	}	
	else{
		printf("none");
	}
    return 0;
}
```



### C_과제 2-2.c
종료 조건까지 문자를 반복해서 입력받아, 배열 X에 저장한다.
 (1) 배열 X에 저장된 문자 중 중복된 문자는 제외하고 배열 Y에 저장한다. 동일한 문자가 여러
번 나오는 경우, 가장 처음에 입력된 문자를 배열 Y에 저장한다.
 (2) 배열 Y에 저장된 문자들을 출력한다.
 (3) 정수 M을 입력받고, M개의 문자를 입력받아 배열 Z에 저장한다. 단, M≤N.
 (4) 배열 Y에 저장된 문자 중에 배열 Z에 저장된 M개의 문자가 연속해서 나타나면, 배열 Y에서 연속된 M개 문자의 시작 위치(배열의 인덱스 값)을 출력한다. (5) 배열 Y에 저장된 문자 중에 배열 Z에 저장된 M개의 문자가 연속해서 나타나지 않으면
“none”을 출력한다.
 - 종료 조건 : 문자 ‘!’ 입력
 - 입력되는 문자의 최대 개수는 100이다. 
 - M 입력 후 배열 Z에 문자들을 입력받아 저장하기 전에  getchar();  문장을 사용해서
  <enter>를 읽어 들여야 함

<img width="622" alt="스크린샷 2022-07-05 오후 12 59 34" src="https://user-images.githubusercontent.com/99342700/177247102-f3fe15b0-1e1c-4c92-99a2-b3ff2f91a300.png">

1. 문제에 맞는 변수 지정.
2. 종료조건 전까지 무한루프를 이용하여 반복 계산.
3. 입력한 X배열에 중복되는 문자가 나오면 카운트를 하여 카운트가 자기자신 외에 더 있으면 Y배열에 저장 안함.
4. 중복되지 않은 문자들로 이루어진 Y배열 출력.
5. M을 입력받고 M크기 만큼의 문자를 새로운 배열 Z에 저장.
6. for문을 이용하여 같은 문자가 나오면 그 다음 문자들도 같은지 확인.
7. 몇번째에서 해당 문자가 시작하는지 카운트 후 출력.
8. 그 외에는 none출력.

```c++
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
```



### C_과제 3-2.c
1부터 20까지 정수를 배열 A[0]에서 A[19]에 순서대로 저장하고, 양의 정수 F(<20), R(F<R<20), M을 입력받아 A[F]부터 A[R]까지의 정수 중, A[R]부터 M개의 정수를 하나씩 오른쪽으로 이동시키는 프로그램을 작성하시오. M은 R-F+1보다 작은 수이다.

<img width="788" alt="스크린샷 2022-07-06 오후 4 18 26" src="https://user-images.githubusercontent.com/99342700/177492631-bcf822db-61fb-48ea-8d6f-5dee5cabd900.png">

1. 조건에 맞게 변수 지정.
2. 범위 내의 인덱스 크기 구하기.
3. 해당 인덱스 범위 내의 값들을 새로운 배열에 저장.
4. 새롭게 저장한 배열을 기존 배열의 N부터 차례로 저장하고 출력.

```c++
#include <stdio.h>

int main(void){
    int arr[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; 
	int X[20] = {0};
	int F=0,R=0,M=0,N=0,next=0,idx=0,cnt=0; 
	scanf("%d %d %d",&F,&R,&M); 

	N = R - M + 1;
	next = R;

	for(int i=N; i<=R; i++){
		X[idx++] = arr[i]; 
		cnt++; 
	}
	idx = cnt-1;

	for(int i=N; i<=R; i++){
		arr[i] = X[idx++]; 
		if(idx == cnt){
			idx = 0;
		}
	}

	for(int i=0; i<20; i++){ 
		printf("%d ",arr[i]);
	}

    return 0;
}
```



### C_과제 4-3.c
정수 N을 입력받고, N개의 정수 읽어 들여 1, 2단계 [ 문제 4-1 ] [ 문제 4-2 ]를 수 행한후, 결과로나온배열에다시2단계[문제4-2]를계속적용하여전체N개의정수중가 장 큰 수, 가장 작은 수가 남을 때 까지 반복하는 프로그램을 작성하시오.

<img width="788" alt="스크린샷 2022-07-06 오후 4 18 26" src="https://user-images.githubusercontent.com/99342700/177605977-a841542b-3f49-4c36-8e0b-cc2e2de639ad.png">

1. 각 변수 지정.
2. 입력 받은 크기로 각 배열 변수 지정.
3. 입력 받은 배열을 역순으로 출력.
4. 각 최대/최소 변수에 배열의 첫 번째 인덱스 저장.
5. 반복할 때 i는 3칸씩 이동.
6. max변수에 가장 큰 값 저장.
7. min변수에 가장 작은 값 저장.
8. 배열에 최대/최소값 각각 저장 후 출력.

```c++
#include <stdio.h>

int main(void){
    int N=0,idx=0,cnt=0,M=0,max=0,min=0;
	scanf("%d",&N);
	int arr[N],temp[N],X[N],Y[N],max_cnt[N],min_cnt[N];

	for(int i=0; i<N; i++){
		scanf("%d",&arr[i]);
		temp[i] = arr[i];
	}

	for(int i=N-1; i>=0; i--){
		printf(" %d",arr[i]);
	}
	printf("\n");

	while(1){
		idx=0;
		for(int i=0; i<N; i=i+3){
			max = arr[i];
			min = temp[i];
			for(int j=i; j<i+3 && j<N; j++){
				if(max < arr[j]){
					max = arr[j];
				}
				if(min > temp[j]){
					min = temp[j];
				}
			}
			max_cnt[idx] = max;
			min_cnt[idx] = min;
			idx++;
		}


		for(int i=0; i<idx; i++){
			printf(" %d",max_cnt[i]);
		}
		printf("\n");
		for(int i=0; i<idx; i++){
			printf(" %d",min_cnt[i]);
		}
		printf("\n");
		N = idx;
		if(N == 1){
			break;
		}
		for(int i=0; i<N; i++){
			arr[i] = max_cnt[i];
			temp[i] = min_cnt[i];
		}
	}
	return 0;
}
```



### C_과제 5-2.c
두 집합 A, B 의 원소를 합쳐서 합집합을 만들려고 한다. 두 집합의 원소는 각각 음 수가 입력될 때까지의 원소이다. 문제 5-1처럼 중복된 원소가 입력될 수 있고 이 때는 집합에 추 가되지 않아야 한다. 합집합은 두 집합이 합쳐 진 후 정렬을 하여 오름차순으로 출력한다.
각 줄에서, 음수를 제외하고 최대 100개의 정수가 입력된다.

<img width="697" alt="스크린샷 2022-07-07 오후 7 03 15" src="https://user-images.githubusercontent.com/99342700/177748308-cf2affc1-157a-475d-95c6-e1e23240b4f5.png">

1. 필요한 배열 및 변수 지정.
2. 종료조건 전까지 입력받고 입력받은 값은 A,B배열에 저장.
3. 현재 위치부터 0인덱스까지 비교하며 같은 경우가 자기 자신 밖에 없을 때 새로운 배열에 저장.(반복된 수 제거)
4. 반복 제거한 두 배열을 하나의 배열로 합치기.
5. 합친 배열에 반복값이 있는지 확인하고 반복된 수는 제외하고 새로운 배열에 저장.
6. 가장 작은 수 부터 정렬하며 오름차순으로 저장.
7. 해당 배열 출력.

```c++
#include <stdio.h>

int main(void){
    int A[101],B[101],C[101],D[101],E[202],F[101],G[101];
	int idx=0,idx2=0,idx3=0,idx4=0,idx5=0,cnt=0,num1=0,num2=0,add=0,min=99999999,n=0,temp=0;

	while(1){
		scanf("%d",&temp);
		if(temp < 0){break;}
		A[num1++] = temp;
	} 
	
	while(1){
		scanf("%d",&temp);
		if(temp < 0){break;}
		B[num2++] = temp;
	}

	for(int i=0; i<num1; i++){
		for(int j=i; j>=0; j--){
			if(A[i] == A[j]){
				cnt++;
			}
		}
		if(cnt==1){
			C[idx++] = A[i]; 
		}
		cnt=0;
	}
	cnt=0;
	for(int i=0; i<num2; i++){
		for(int j=i; j>=0; j--){
			if(B[i]==B[j]){
				cnt++;
			}
		}
		if(cnt==1){
			D[idx2++] = B[i];
		}
		cnt=0;
	}
	cnt=0;

	add = idx + idx2;

	for(int i=0; i<idx; i++){
		E[idx3++] = C[i]; 
	}

	for(int i=0; i<idx2; i++){
		E[idx3++] = D[i];
	}

	for(int i=0; i<add; i++){
		for(int j=i; j>=0; j--){
			if(E[i] == E[j]){
				cnt++;
			}
		}
		if(cnt == 1){
			F[idx4++] = E[i];
		}
		cnt=0;
	}

	for(int i=0; i<idx4; i++){
		for(int j=0; j<idx4-1; j++){
			if(F[j] > F[j+1]){
				min = F[j];
				F[j] = F[j+1];
				F[j+1] = min;
			}
		}
	}

	for(int i=0; i<idx4; i++){
		printf("%d ",F[i]);
	}


	return 0;
}
```