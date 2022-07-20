# C Programming 과제.3 (반복문)

### C_과제 1-2.c
N개의 정수 M을 입력 받아, M과 M의 약수를 예시와 같이 출력하시오.
(단, N ≥ 3, M의 3자리 이상 정수) - 입력받은 각 정수에 대하여, (1) 입력된 정수를 그대로 출력하고
(2) 입력된 정수의 약수를 출력하고
(3) 각 정수에 대한 약수의 개수를 출력하고
(4) 약수의 개수가 가장 많은 M을 출력
(약수의 개수가 동일한 정수가 있을 경우, 첫 번째 일치하는 정수만 해당함)

<img width="594" alt="스크린샷 2022-06-30 오후 6 07 11" src="https://user-images.githubusercontent.com/99342700/176638774-501729b2-b790-41d7-9623-25906bb17203.png">

1. 각각의 변수 지정.
2. N번 만큼의 반복을 할 for문을 입력.
3. 이중 for문으로 약수를 구하여 약수일 시 출력과 갯수 추가.
4. 갯수 출력 후 줄 바꿈.
5. 카운트값을 비교하여 조건에 맞을 시 새로운 카운트 변수에 기존 카운트값 저장.
6. 카운트값이 가장 높은 값 출력.

```c++
#include <stdio.h>

int main(void){
    int N=0,M=0,cnt=0,ccnt=0,max=0;
	scanf("%d",&N);

	for(int i=0; i<N; i++){
		scanf("%d",&M);
		printf("%d:",M);
		for(int j=1; j<=M; j++){
			if(M%j==0){
				printf(" %d",j);
				cnt++;
			}
		}
		printf(" %d\n",cnt);
		if(ccnt < cnt){
			ccnt = cnt;
			max = M;
		}
		cnt=0;
	}
	printf("%d",max);
    return 0;
}
```



### C_과제 2-2.c
1 이상 1000 이하의 두 개의 양의 정수 N 과 M을 사용자로부터 입력 받아 N부터 M 까지의 각 숫자의 약수의 개수를 계산해서 약수의 개수가 가장 큰 수를 출력하고 그 수 의 약수의 개수도 함께 출력하시오. (만약, 약수의 개수가 가장 많은 수가 지정된 범위 내에서 여 러 개 존재할 때 가장 작은 수를 선택.)
단,각숫자의약수의개수는소인수분해를통해구하시오.숫자 을소인수의지수형태 n=ap xbq xcr 로나타낼수있을때,n의약수의개수는이다.예를들 어, 72 = 23 x 32 의 약수의 개수는  이다. 소인수 분해를 통해 계산했는지 확 인하기 위해 소인수의 지수 합 ()을 추가로 출력하시오.
- 입력: N M
- 출력: (약수의 개수가 가장 큰 수) (약수의 개수) (소인수의 지수 합)

<img width="393" alt="스크린샷 2022-06-30 오후 6 26 36" src="https://user-images.githubusercontent.com/99342700/176642754-0bad9f58-4560-41d4-90ae-3fb1816619b5.png">

1. 각각 변수 지정.
2. for문을 이용하여 N ~ M 까지 약수를 구하고 약수의 개수 1씩 올리기.
3. 갯수가 클 때 마다 i값(현재 N값) 저장.
4. 반복 연산으로 약수의 개수가 가장 큰 수와 그 약수의 개수를 출력.
5. 약수의 개수가 가장 큰 수를 2부터 나누며 다시 약수를 구하기.
6. 가장 큰 수가 0이 될 때 까지 반복 계산.
7. 소인수의 지수 합 출력.

```c++
#include <stdio.h>
int main(void)
{
  int N=0; int M=0; int cnt=0; int max=0; int answer=0;
  scanf("%d %d",&N,&M);
  if( ( N < 1 || N > 1000 ) || ( M < 1 || M > 1000 ) ){return -1;}
      for(int i=N; i<=M; i++){ 
        for(int j=2; j<=i; j++){ 
          if(i%j==0){
           cnt++;
          }
          if(max<cnt){ 
          max=cnt;
          answer=i; 
          }
        } 
         cnt=0;
      }    
       printf("%d %d ",answer,max+1);
      int f=2; int exp=0;
      while(answer>1){
        if(answer%f==0){
          exp++;
          answer=answer/f; 
        } 
        else{ 
          f++;
          if(answer%f==0){
            exp++;
            answer=answer/f;
          }
        } 
      } 
      printf("%d",exp); 
  return 0;
}
```



### C_과제 3.c
<img width="481" alt="스크린샷 2022-06-30 오후 6 37 42" src="https://user-images.githubusercontent.com/99342700/176645175-9c1ee1a6-0335-468e-a16a-6b5cc777110d.png">
<img width="462" alt="스크린샷 2022-06-30 오후 6 38 11" src="https://user-images.githubusercontent.com/99342700/176645183-362e91e2-3650-443e-9553-11cdbff88a3b.png">

1. 각각 변수 지정.
2. 조건을 충족하지 못할 시 주어진 멘트를 출력하며 종료.
3. 조건에 나온대로 순열 / 중복순열 / 조합 / 중복조합 을 계산하여 출력. 

```c++
#include <stdio.h>
int main(void)
{
    int n=0; int r=0; long long s=1; int nt=0; long long js=1;
    int rt=1; long long jj=1; int jt=0; long long j=1;

    scanf("%d %d",&n,&r); 
    if(n < r || r <= 0){ 
        printf("inputs n and r must satisfy '0 < r <= n'.");
        return -1;
    }

    nt = n;
    for(int i=0; i<r; i++){
        s = s * nt;
        nt--;
    }
    printf("%dP%d=%lld\n",n,r,s);

    for(int i=0; i<r; i++){
        js = js * n; 
    }
    printf("%dPI%d=%lld\n",n,r,js);

    for(int i=1; i<=r; i++){
        rt = rt * i;
    }
    j = s/rt;
    printf("%dC%d=%lld\n",n,r,j);

    jt = n + r -1; 
    for(int i=1; i<=r; i++){
        jj = jj * jt;
        jt--;
    }
    jj = jj / rt; 
    printf("%dH%d=%lld",n,r,jj);


  return 0;
}
```



### C_과제4-2.c
찾기 원하는 0이 아닌 한 자리 정수 T를 입력 받는다. 그 후 한 자리 혹은 여러 자리를 갖는 정수를 0이 나오기 전까지 지속적으로 입력 받은 다음 입력 받은 정수들에 T가 등장한 횟수, T 보다 작은 수가 등장한 횟수, T 보다 큰 수가 등장한 횟수를 출력하는 프로그램을 작성하시오. 이 때, 마지막에 입력된 0은 무시되며, 입력되는 수는 모두 양수라고 가정한다.

<img width="483" alt="스크린샷 2022-06-30 오후 6 47 51" src="https://user-images.githubusercontent.com/99342700/176647422-31873ae0-aed8-4be7-9718-27926e3a65a6.png">

1. 각각 변수 지정
2. 이중 반복문을 이용하여 각 자릿수의 값을 입력한 N과 비교하여 큰 값 / 작은 값 / 같은 값 나누어 저장.
3. 각각 나눈 변수 출력. 

```c++
#include <stdio.h>
int main(void)
{
  int N=0; int M=0; int num=0; int cnt=0,min=0,max=0;
  scanf("%d",&N);

  while(1){
	  scanf("%d",&M);
	  if(M == 0){break;}

	  for(int i=M; i>0; i=i/10){
		  num = i%10;
		  if(num == N){
			  cnt++;
		  }
		  else if(num > N){
			  max++;
		  }
		  else{
			  min++;
		  }
	  }	  
  }
  printf("%d %d %d",cnt,min,max);
  return 0;
}
```



### C_과제 5-3.c
정수 N을 입력 받아 (N>0)
- 자리수가 짝수인 수들만 역순으로 만든 수를 출력하시오. 그런 다음, - 자리수가 홀수인 수들만 역순으로 만든 수를 출력하시오.

<img width="381" alt="스크린샷 2022-06-30 오후 7 03 50" src="https://user-images.githubusercontent.com/99342700/176650935-88e380d5-b102-4377-bda6-c4c7a3bd52a0.png">

1. 각각 필요한 변수 지정.
2. 입력받은 N이 0이 될 때 까지 반복.
3. 입력받은 값을 1의자리부터 나누며 각 자릿수가 짝수일 경우와 홀수일 경우 구분.
4. 짝수일 경우 자릿수를 곱하며 뒤집은 값이 나오게 연산.
5. 홀수일 경우 짝수일 경우와 마찬가지로 연산.
6. 짝수인 경우와 홀수인 경우 출력.

```c++
#include <stdio.h>
int main(void)
{
  int N=0; int num=0; int even=0,odd=0;
  scanf("%d",&N);

  for(int i=N; i>0; i=i/10){
	  num = i % 10;
	  if(num%2 == 0){
		  even = even * 10;
		  even = even + num;
	  }
	  else if(num%2 != 0){
		  odd = odd * 10;
		  odd = odd + num;
	  }
  }
  printf("%d %d",even,odd);
  return 0;
}
```



### C_과제 6-2.c
삼각형 높이를 나타내는 N을 종료 조건 시까지 반복해서 입력받고, 앞의 문 제(문제 1-1)와 동일한 사각형 모양을 순서대로 출력하는 프로그램을 작성하시오.
(단, 2 <= N <= 20)
- 종료조건: 0, 1, 음수, 3의 배수 입력

<img width="433" alt="스크린샷 2022-06-30 오후 7 17 46" src="https://user-images.githubusercontent.com/99342700/176653704-a93a459a-1063-4e19-963a-ac579b469ba4.png">

1. 각각 필요한 변수 지정.
2. 반복하여 입력을 받고, 입력 예시와 맞게 가로 세로 인덱스를 구축 할 반복문코드 작성.
3. 각 인덱스 별로 모양에 맞추어 공백 / O / X 지정 후 출력.

```c++
#include <stdio.h>
int main(void){
int N=0;

while(1){
  	scanf("%d",&N);
  	if(N <= 1 || N%3 == 0){return -1;}
  	for(int i=0; i<N; i++){
	  	for(int j=0; j<N*2-1; j++){
		  	if(i+j < N-1){
				  printf(" ");
		  	}
		  	else if(j-i > N-1){
				  printf(" ");
		  	}
		  	else if(i+j == N-1){
				  printf("O");
		  	}
		  	else if(j-i == N-1){
				  printf("O");
		 	}
		  	else if(i == N-1){
				  printf("O");
		  	}
		  	else if(i+j >= N){
				  printf("X");
		  	}
	 	}
	  	printf("\n");
  	}
  }	  
  return 0;
}
```