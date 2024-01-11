# C_POINTER 심화 (문자열)

### C_문자열 이론
- 문자열 : 문자들의 연속 즉, char형 배열.
- NULL == '\0'
    - NULL은 공백(아스키코드 0)과 같은 뜻으로 배열에 입력할 때 마지막 인덱스에 저장됨.
    - 그러므로 배열을 만들 때 저장하고자하는 문자보다 1을 더 크게 세팅해야함. ex) char str[5] = {'H','E','L','L','O','\0'};
    - 반복문에서 NULL문자가 나올 때 까지 출력하는 방식으로 활용. ex) while(str[i] != '\0');
- 문자열 저장.
    - char str[4] = {'a','b','c','\0'}; -> abc\0저장 (기본적인 형식이지만 다소 불편함)
    - char str[4] = "abc"               -> abc\0저장 (편리성을 위해 사용)
    - char str[4] =  "abcdef"           -> abc\0저장 (크기 만큼만 저장)
    - char str[4] = "";                 -> \0저장 (모두 NULL값으로 초기화)
    - char str[] = "abc";               -> abc\0저장 (뒤에 크기에 맞춰서 저장)
- gets(배열변수); 
    - 엔터를 입력 할 때 까지 배열에 문자열 저장.
    - '\0' 는 NULL과 같은 뜻.(문자열에서 지정된 문자 제외하곤 모두 NULL로 저장)
    - %s는 문자열을 가르킴.
```c++
#include <stdio.h>

int main(void) {
	int N=0,cnt=0;
	scanf("%d",&N);
	char arr[100];
	gets(arr);
	while(arr[cnt] != '\0'){
		cnt++;	
	}
	printf("입력된 문자열의 크기는 : %d 입니다.\n",cnt);
	printf("입력된 문자는 %s 입니다.",arr);
	return 0;
}
```

### C_문자열 라이브러리<string.h>
- 문자열 비교(strcmp)
    - strcmp(첫 번째 배열, 두 번째 배열); // 두 배열을 비교하여 왼쪽과 오른쪽 비교시 왼쪽이 더 클 시 '1' 더 작을 시 '-1' 같을 시 '0' 출력.
- 문자열 복사(strcpy)
    - strcpy(첫 번째 배열, 두 번째 배열); // 두 번째 배열의 인자들을 첫 번째 배열에 그대로 저장. (크기가 맞지 않아도 저장이 됨)
- 문자 단위의 표준 입출력
    - getchar // 키보드로부터 입력을 받음 (보통 배열에서 엔터를 임의로 넣기 위해 사용)
    - putchar // 모니터로 문자를 내보냄

```c++
#include <stdio.h>
#include <string.h>

int main(void){
    char input[10] = "I Love You";
    char result[5] = "Love";
    strcpy(result,input);
    printf("문자열 복사 : %s\n",result);
    return 0;
}
```

```c++
// [동적할당]
typedef struct student{
    char *name;
    int kor, eng, math;
}stu;

int N = 5;
stu **p = (stu**)malloc(sizeof(stu*) * N); // 구조체 자료형 ('*' 주의!!)
if(p == NULL) return -1; // 오류 확인 안하면 감점!!
for(int i = 0; i < N; i++){
    p[i] = (char*)malloc(sizeof(char) * 101); // 구조체 안 자료형
    if(p[i] == NULL) return -1;
}

for(int i = 0; i < N; i++){ // 제거 안하면 감점!!
    free(p[i]);
}
free(p);
```

```c++
// [문자열 옮기기]
char str[20] = {"Simple is best!!"};
char *p = str; // 배열의 주소를 이동 할 포인터
char ch[5][20] = {NULL}; // 단어를 담을 포인터
int idx = 0;
for(int i = 0; i < strlen(str); i++){
    if(str[i] == 0 || str[i] == '\0'){
        str[i] = '\0';
        strcpy(ch[idx++], p);
        p = p + strlen(p) + 1;
    }
}
```

```c++
// [버블 정렬]
for(int i = 0; i < N - 1; i++){
    for(int j = 0; j < N - 1 - i; j++){
        if(ar[j] < ar[j + 1]){
            char tmp = ar[j];
            ar[j] = ar[j + 1];
            ar[j + 1] = tmp;
        }
    }
}
```

```c++
// [문자열]
char str1[10] = {"Simple"}, str2[10] = {"Best"};

strlen(str1); // 길이 6
strlen(str2); // 길이 4

if(strcmp(str1, str2) == 0); // 동일 단어 일 경우
if(strcmp(str1, str2) > 0); // str1이 큰 경우 (부등호가 벌어진 방향이 큰 경우!!)
if(strcmp(str1, str2) < 0); // str2가 큰 경우

strcpy(str1, str2); // str1 = "Best" 저장 (Simple은 사라짐)

strcat(str1, str2); // str1에 str2가 접합 되어서 "Simple Best"로 변함
```