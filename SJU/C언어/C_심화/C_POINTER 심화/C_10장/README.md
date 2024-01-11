# 고급 C_문자열

### 10장 문제 1.c

사용자로부터 공백을 포함하지 않는 문자열을 입력 받은 후 소문자만
출력하는 프로그램을 작성하시오.
- 입력 받는 문자열 길이는 최대 20 이다.

<img width="660" alt="스크린샷 2022-08-05 오후 4 34 20" src="https://user-images.githubusercontent.com/99342700/183026545-4fc06e8a-fab4-4642-89f6-4fdb32d38ecf.png">

1. 필요한 배열 변수 선언.
2. gets함수를 사용하여 입력 받기.
3. 반복문을 사용하여 소문자일 경우에만 출력.
4. 소문자가 아니면 넘어가기.

```java
#include <stdio.h>
#include <string.h>

int main(void) {
	char arr[20];
	gets(arr);

	for(int i=0; i<20; i++){
		if(arr[i] >= 'a' && arr[i] < 'z'){
			printf("%c",arr[i]);
		}
		else{
			continue;
		}
	}
	return 0;
}
```