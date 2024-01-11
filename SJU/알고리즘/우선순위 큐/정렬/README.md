### <strong>선택정렬</strong>(Selection Sort)
해당 순서에 원소를 넣을 위치는 이미 정해져 있고, 어떤 원소를 넣을지 선택하는 알고리즘이다. 즉, 배열에서 해당 자리를 선택하고 그 자리에 오는 값을  찾는 것.
1. 주어진 배열 중에 최소값을 찾는다.
2. 그 값을 맨 앞에 위치한 값과 교체한다. (pass)
3. 맨 처음 위치를 뺀 나머지 배열을 같은 방법으로 교체한다.
```c++
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int *ar,N,tmp,idx;
	ar = (int *)malloc(sizeof(int)*N);
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d",&ar[i]);

	for(int i=N-1; i>0; i--){ // 1.
		idx = i;
		for(int j=i-1; j>=0; j--){ // 2.
			if(ar[idx] < ar[j]) // 3.
				idx = j;
		}
		tmp = ar[idx]; // 4.
		ar[idx] = ar[i];
		ar[i] = tmp;	
	}

	for(int i=0; i<N; i++)
		printf(" %d",ar[i]);
		return 0;
}
```
코드 순서
1. 위치 인덱스 선정
2. i-1부터 선택한 위치의 인데스와 비교 (순서는 앞/뒤 상관 없음)
3. 기존의 값보다 비교하는 값이 더 크다면 인덱스 위치 변경(같은 방식으로 순회)
4. 2번 반복문이 끝나면 스왑(반복문에 변화가 없으면 순서는 그대로)

### <strong>삽입정렬</strong>(Insertion Sort)
손 안의 카드를 정렬하는 방법과 유사하다.
- Insertion Sort는 Selection Sort와 유사하지만, 좀 더 효울적인 알고리즘이다.
- Insertion Sort는 2번째 원소부터 시작하여 그 앞(왼쪽)의 원소들과 비교하여 삽입 할 위치를 지정한 후 원소를 뒤로 옮기고 지정된 자리에 자료를 삽입 하여 정렬하는 알고리즘이다.
- 최선의 경우 O(N)이라는 엄청나게 빠른 효율성을 가지고 있어, 다른 정렬 알고리즘의 일부로 사용될 만큼 좋은 정렬 알고리즘이다.
1. 정렬은 2번째 위치(idx)의 값을 tmp에 저장한다.
2. tmp와 이전에 있는 원소들과 비교하며 삽입해나간다.
3. 1번으로 돌아가 다음 위체(idx)의 값을 tmp에 저장하고 반복한다.
```c++
#include <stdio.h>
#include <string.h>

int main(){
	int ar[5];
	for(int idx=1; idx<strlen(ar); idx++){ // 1.
		int tmp = ar[idx];
		int prev = idx - 1;
		while( (prev >= 0) && (ar[prev] > tmp) ){ // 2.
			ar[prev+1] = ar[prev];
			prev--;
		}
		arr[prev+1] = tmp; // 3.
	}
	printf("%s",ar);
	return 0;
}
```
코드 순서
1. 첫 번째 원소 앞(왼쪽)에 어떤 원소도 갖고 있지 않기 때문에, 두 번째 위치(idx)부터 탐색을 시작한다. tmp에 임시로 해당 위치(idx)값을 저장하고, prev에는 해당 위치(idx)의 이전 위치(idx)를 저장한다.
2. 이전 위치(idx)를 가리키는 prev가 음수가 되지 않고, 이전 위치(idx)의 값이 1번에서 선택한 값보다 크다면, 서로 값을 교환헤주고 prev를 더 이전 위치(idx)를 가리키도록 한다.
3. 2번에서 반복문이 끝나고 난 뒤, prev에는 현재 tmp값 보다 작은 값들 중 제일 큰 값의 위치(idx)를 가리키게 된다. 따라서, (prev+1)에 tmp값을 삽입해준다.

<br>예제문제
n개의 양의 정수를 입력(중복 가능)받아, 아래에서 설명하는 삽입 정렬을 이용하여 정렬하는 프로그램을 작성하시오.
구현해야 할 삽입 정렬 알고리즘:
- 크기가 n인 배열을 동적 할당하여, 입력된 양의 정수 저장(입력 정수는 중복 가능)
- 제자리(in-place) 정렬 사용. 즉, 입력 값 저장을 위한 배열 이외에 O(1)의 추가 공간만 사용
- 배열의 앞부분을 정렬 상태로 유지
<img width="509" alt="image" src="https://user-images.githubusercontent.com/99342700/188823540-f845ce58-e8dd-479c-814b-4fee600553df.png">

```c++
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int *n, N, tmp, index;
	scanf("%d", &N);
	n = (int *)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &n[i]);

	}

	for (int i = 1; i < N; i++) { //i=6
		index = i;
		for (int j = i - 1; j >= 0; j--) {
			if (n[i] < n[j]) index = j;
			else break;
		}
		tmp = n[i];
		for (int k = i; k > index; k--) {
			n[k] = n[k - 1];
		}
		n[index] = tmp;

	}

	for (int i = 0; i < N; i++) {
		printf(" %d", n[i]);
	}
}
```

