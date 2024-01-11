# C_Programming POINTER(기초)

### C_과제 1(추가).c
입력된 정수 N이 두 개의 소수의 합으로 표현되는지 조사하여, 모두 출력하시오. 하나 도 없으면 none 을 출력하시오. N ≧ 4

1) isPrime( ) 함수 정의
- 인자: int형 포인터 변수 p
- 반환값: 소수이면 1, 아니면 0을 반환

<img width="563" alt="스크린샷 2022-07-26 오후 1 43 37" src="https://user-images.githubusercontent.com/99342700/180925014-42da2c7a-7de4-4a72-a5b2-7bd78f9d84b5.png">

1. 원형함수 및 변수 선언.
2. 포인터와 연결된 배열에 값 입력.
3. N크기의 1/2만큼 반복.
4. 소수임을 판단하는 함수 선언.
    - 1을 제외하므로 값이 1이면 0 반환.
    - 그게 아니면 2부터 하나씩 나누어서 카운트가 0인 경우에만 1 반환.
5. 소수인 경우 해당 포인터 값과 N의 값에서 포인터 값을 뺀 값 출력.

```c++
#include <stdio.h>

int isPrime(int *p);

int main(){
    int N = 0;
    scanf("%d", &N);

    int A[N];
    int *p;
    int Num =1;
    for(p = A; p<A+N; p++)
        *p = Num++;

    int * T = A;
   
    for(p = A; p<A+(N/2); p++){
        if(isPrime(p)){
           int temp = N-*p;
           if(isPrime(T+(temp-1))){
            printf("%d %d\n", *p,temp);
           }
        }
    }
        
    return 0;
}

int isPrime(int *p){
    int cnt = 0;
    int temp = *p ;
    if(temp == 1){return 0;}
    
    for(int i=2; i<temp; i++){
        if( temp %i ==0){
            cnt++;
        }
        if(cnt !=0){return 0;}
    }
    return 1;
}
```



### C_과제 2(추가).c
문장에서 각 알파벳의 횟수를 알파벳순으로 출력하시오. 입력되는 문자는 최대 100개
<img width="812" alt="image" src="https://user-images.githubusercontent.com/99342700/181156039-4910baad-c3b0-41df-9403-3b4aaf28fabc.png">

<img width="568" alt="image" src="https://user-images.githubusercontent.com/99342700/181156143-52825d6e-c77c-4b1b-a872-37938b3079fa.png">

1. 원형함수 및 필요한 변수 지정.
2. 포인터 배열에 단어 입력.
3. 포인터 배열에 알파벳 순서대로 지정.
4. 두 포인터 배열을 비교하여 a부터 z까지 카운트하는 함수 선언.
5. 해당 값 출력. 


```c++
#include <stdio.h>

int frequency(char * ar, char* p);

int main(){
    char alpha[26];
    char str[100];
    char * ar = str;
    char * p;
    int idx =0;

    scanf("%[^\n]s",ar);


    for(p=alpha; p<alpha+26; p++){
        *p = 'a'+idx++;
    }


    for(p=alpha; p<alpha+26; p++){
        int answer  = 0;
        answer = frequency(ar, p);
        if(answer !=0){
            printf("%c %d\n",*p, answer);
        }
    }

    return 0;
}

int frequency(char * ar, char* p){
    int result = 0;
    char *q = ar;
    while(*q!='.'){
        if(*q == *p){
            result++;
        }
        q ++;
    }
    return result;
}
```



### C_과제 3(추가).c
별까지 입력받는다. 모음, 자음, 숫자문자, 빈칸의 수를 출력하시오. 

1) count( ) 함수 정의
- 인자: char형 배열을 가리키는 포인터 ar, int형 배열을 가리키는 포인터 info - info가 가리키는 배열에 모음, 자음, 숫자문자, 빈칸의 수를 저장한다.
- 반환값: 없음

2) main 함수
- char ar[100]; int info[4] ; 선언한다. - 화면에 출력한다.
▶ 전역변수 사용금지

<img width="559" alt="스크린샷 2022-07-28 오후 2 07 04" src="https://user-images.githubusercontent.com/99342700/181425156-19e9f0e6-9e27-45c0-8306-f740d9bb970f.png">

1. 원형함수 및 변수 선언.
2. 포인터 배열 입력.
3. 배열에 들어가 있는 문자가 각각 모음,자음,숫자,빈칸이 몇개인지 세는 함수 선언
    - 각 수를 포인터 배열에 저장.
4. 포인터 배열 인덱스 순으로 출력.

```c++
#include <stdio.h>

void count(char *ar, int *info);

int main(){
    char ar[100];
    int info[4];
    int *p = info;

    scanf("%[^\n]s",ar);
    count(ar, info);

    printf("Vowels: %d\n", *p++);
    printf("Consonants: %d\n", *p++);
    printf("Digits: %d\n", *p++);
    printf("White spaces: %d\n", *p++);
    return 0;
}

void count(char *ar, int *info){
    int a =0;
    int b= 0;
    int c= 0;
    int d= 0;
    for(char *temp = ar; *ar != '*'; ar++){
        
        if(*ar =='a' || *ar =='A' || *ar =='e' || *ar =='E' || *ar =='i' || *ar =='I' || 
        *ar =='o' || *ar =='O' || *ar =='u' || *ar =='U'){
            a++;
        }
        else if(*ar>=48 && *ar<=59){
            c++;
        }
        else if(*ar ==' '){
            d++;
        }
        else {
            b ++;
        }
    }
    *info = a;
    info++;
    *info = b;
    info ++;
    *info = c;
    info++;
    *info = d;
    info ++;
}
```



### C_과제 4(추가).c
문자들을 별표까지 읽어 들인다. 

1) Remove( ) 함수 정의
- 인자: char형 배열을 가리키는 포인터 par1, par2
- par1 이 가리키는 배열에서 알파벳과 * 이외를 제거하여 par2 가리키는 배열에 저장한다. - 반환값: 없음

2) main 함수
- char ar1[100], ar2[100] ; 선언한다. - 화면에 출력한다.
▶ 전역변수 사용금지

<img width="562" alt="image" src="https://user-images.githubusercontent.com/99342700/181651989-e529731f-811f-401a-9013-d86178cb50dc.png">

1. 원형함수 및 변수 선언.
2. 포인터 베열에 입력.
3. 알파벳을 제외하고 지우는 함수 선언.
    - 알파벳인 경우에만 포인터 배열에 저장.
4. 포인터 배열 출력.

```c++
#include <stdio.h>

void Remove(char *ar1,char *ar2);

int main(){
    char ar1[100];
    char ar2[100];
    scanf("%[^\n]s",ar1);
    Remove(ar1, ar2);
    for(char *temp = ar2; *temp!='\0'; temp++){
        printf("%c",*temp);
    }
    printf("\n");

    return 0;
}

void Remove(char *ar1,char *ar2){
    char *point = ar2;
    for(char *temp = ar1; *temp != '*'; temp++){
        if( (*temp >=65 && *temp <=90) || (*temp >=97 && *temp <=122) ){
            *point = *temp;
            point++;
        }
    }
}
```



### C_과제 5(추가).c
정수 두 줄을 입력받아, 각줄을 정렬 후, 두 줄을 합쳐서 하나의 정렬된 수열로 만드시 오. 이것을 합병정렬이라고 한다. 다른 정렬들 보다 계산 속도가 빠르다.

1) sort( ) 함수 정의
- 인자: int형 배열을 가리키는 포인터 ar, 정수 N을 가리키는 int형 포인터 p - 정렬한다.
- 반환값: 없음

2) merge( ) 함수 정의
- 인자: int형 배열을 가리키는 포인터 ar1, ar2, ar3, 정수 N과 M을 가리키는 int형 포인터 p, q
1 첫 번째 배열의 첫 번째 원소와 두 번째 배열의 첫 번째 원소를 비교하여, 작은 수를 세 번째 배열에 저장한다.
2 세 번째 배열에 저장한 원소를 제외하고, 1의 과정으로 돌아간다. - 반환값: 없음

3) main 함수
- int ar1[100], ar2[100], ar3[100] ; 선언한다.
- sort( ) ; sort( ) ; merge( ) 순서로 호출한다. - 화면에 출력한다.
▶ 전역변수 사용금지

<img width="563" alt="스크린샷 2022-07-30 오후 5 40 11" src="https://user-images.githubusercontent.com/99342700/181902737-27465fd1-9a5b-4cd8-a818-ae80afcab4aa.png">

1. 원형함수 및 필요한 변수 선언.
2. 포인터 배열에 값 입력.
3. sort함수에 들어가서 포인터 배열 각각 최소값부터 차례대로 저장.
4. 각각 저장한 포인터 배열을 merge함수에서 작은 순서대로 하나의 포인터 배열에 저장 후 출력.

```c++
#include <stdio.h>

void sort(int *ar, int * p);
void merge(int *ar1, int *ar2, int *ar3, int *p, int *q);

int main(){
    int ar1[100];
    int ar2[100];
    int ar3[100];

    int N = 0;
    scanf("%d", &N);
    int *p1 = ar1;
    for(; p1< ar1+N; p1++)
        scanf("%d", p1);

    int M = 0;
    scanf("%d", &M);
    int *p2 = ar2;
    for(; p2< ar2+M; p2++)
        scanf("%d", p2);

    int *p = &N;
    int *q = &M;

    p1 = ar1;
    p2 = ar2;

    sort(p1,p);
    sort(p2,q);
    
    p1 = ar1;
    p2 = ar2;
    int *p3 = ar3;

    merge(p1,p2,p3,p,q);
    
    for(int *temp = ar3; temp <ar3+(*p+*q); temp++){
        printf("%d ", *temp);
    }
    

    return 0;
}


void sort(int *ar, int * p){
    int * find_index;
    for(int *temp =ar ; temp<ar+*p; temp++){
        int min = *temp; 
        for(int *T=temp; T<ar+*p; T++){
            if(min>=*T){
                min = *T;
                find_index = T;
            }
        }
        int swap = *find_index;
        *find_index = *temp;
        *temp = swap;
    }
}

void merge(int *ar1, int *ar2, int *ar3, int *p, int *q){
    int N = *p;
    int M= *q;
    while(1){
        if(*ar1 >*ar2){
            *ar3 = *ar2;
            ar3++;
            ar2++;
            M--;
            if(M==0)
                break;
        }
        else{
            *ar3 = *ar1;
            ar3++;
            ar1++;
            N--;
            if(N==0)
                break;
        }
    }

    if(N!=0){
        *ar3 = *ar1;
        ar3++;
        ar1++;
        N--;
    }
    else{
        *ar3 = *ar2;
        ar3++;
        ar2++;
        M--;
    }    
}
```



### C_과제 6(추가).c
첫 번째 문자들에서, 별표 두 개 사이에 있는 단어를 찾으시오. 마지막 나타나는 같은 단어를 대문자로 바꾸시오. 소문자만 입력된다.

1) change( ) 함수 정의
- 인자: char형 배열을 가리키는 포인터 ch
- 필요시 배열 선언해도 됨. 안 해도 됨.
- 마지막 나타나는 같은 단어를 대문자로 바꾼다. - 반환값: 없음

2) main 함수
- 배열 선언한다.
- 사용자로부터 입력받는다. - 함수를 호출한다.
- 화면에 출력한다.
▶ 배열 선언 후, 배열기호 [ ] 사용금지

<img width="559" alt="image" src="https://user-images.githubusercontent.com/99342700/182022572-8e3e47db-0803-452e-9880-f651a03d42ae.png">

1. 원형함수 및 필요한 변수 선언.
2. 별표 사이에 있는 마지막 단어를 찾아주는 함수 선언.
    - 별표가 나온 이후 새로운 포인터 배열에 별표가 아닌 문장들 저장.
    - 다시 별표가 나올 때 까지.
    - 별표에 나온 단어를 기존 포인터 배열에서 뒤에서 부터 찾은 후 한번만 나오는 부분을 대문자로 변경.
3. 새롭게 지정한 포인터 배열 출력.

```c++
#include <stdio.h>

void change(char *ar1);

int main(){
    char ar1[100];
    scanf("%[^\n]s",ar1);
    change(ar1);
    char *temp = ar1;
    while(*temp != '*'){
        printf("%c", *temp);
        temp++;
    }
    printf("\n");
    return 0;
}
void change(char *ar1){
    int check = 0;
    int seq = 0;
    char *temp = ar1;
    char ch[100];
    char *str = ch;
    int cnt= 0;

    while(1){
        if(*temp=='*'){
            temp++;
            while(*temp !='*'){
                *str = *temp;
                str++;
                temp ++;
                check++;
            }
            break;
        } 
        temp ++;
    }
    temp = ar1;
    str = ch;
    char *find;
    
    while(*temp!='*'){
        if(*temp == *str){
            cnt++;
            seq =1;
            str++;
        }
        else{seq =0; cnt = 0; str= ch;}
        temp++;

        if(seq==1 && cnt ==check){
            find = temp-check;
            seq = 0; cnt =0; str =ch;
        }
    }
    for(int i=0; i<check; i++){
        * find -= 32;
        find++;
    }
}
```



### C_과제 7(추가).c
평균과 가장 가까운 원소와 인덱스 출력하기
- N≦10
- 배열 선언 이 후에 배열기호 사용금지.
- 포인터 값이 증가하는 방식으로 배열을 훑어보시오. 즉 for(p= ; ; p++) 이용 한다. 
- 함수 center(int *p, N)
∘ 평균을 출력한다.
∘ 반환값: 평균과 가장 가까운 원소의 주소를 반환한다. - main 함수, 평균과 가장 가까운 원소와 인덱스를 출력한다.

<img width="694" alt="image" src="https://user-images.githubusercontent.com/99342700/182097998-55b6069f-c831-4086-89b7-594f555cdca0.png">

1. 원형함수 및 필요한 변수 지정.
2. 포인터 배열에 입력.
3. center함수에 들어가서 입력받은 정수 중 평균 인덱스에 가장 인접한 정수 구하기.
    - for문을 이용하여 평균값 구한 후 출력.
    - for문을 이용하여 최소값을 구한 후 반환.
4. 최소값과 해당 인덱스 출력.

```c++
#include <stdio.h>


int *center(int *p, int N);

int main(){
    int N;
    scanf("%d", &N);
    int A[N];
    int *p;

    for(p=A; p<A+N; p++)
        scanf("%d", p);
    p = A;
    int * answer =center(p, N);
    printf("%d\n", *answer);
    printf("%ld\n", answer-A);
    
    return 0;
}
int *center(int *p, int N){
    double sum = 0;
    for(int *temp =p; temp<p+N; temp++)
        sum += *temp;
    sum = sum /N;
    printf("%.1f\n", sum);
    int check = 0;
    int min = *p - sum;
    if(min<0){min = min *-1;}
    int *find_idx;

    for(int *temp =p+1; temp<p+N; temp++){
        check = *temp - sum;
        if(check<0){check = check *-1;}
        if(min>=check){
            min = check;
            find_idx = temp;
        }
    }
    return find_idx;
}
```



### C_과제 8(추가).c
반복되는 횟수를 입력된 순서대로 출력하시오.
- 반복되는 수는 처음 한 번만 출력한다.
- 배열 int x[100]
- 배열 선언 이후에는 배열기호 [ ] 사용금지
- 포인터 증가로 훑어보기 즉, *(x+i) 가 아닌 *p 를 이용한다. 즉 for(p=ar; p<ar+N; p++) 힌트: 2중 for 문 사용

<img width="673" alt="image" src="https://user-images.githubusercontent.com/99342700/182286731-527f7bfa-eab5-4341-a39d-bf1b8bdbae0a.png">

1. 필요한 변수 선언 및 입력.
2. check변수에 포인터 배열 p를 앞에서 부터 반복하며 저장하고 이중 for문으로 temp값에 p를 저장하여 수 가 같을 때 마다 카운트 후 출력.

```c++
#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int A[N];
    int *p;
    for(p=A; p<A+N; p++)
        scanf("%d", p);
    
    for(p=A; p<A+N; p++){
        int check = *p;
        int cnt = 0;
        if(check !=0){
            for(int*temp =p; temp<A+N; temp++){
                if(check == *temp){
                    *temp = 0;
                    cnt++;
                }
            }
        printf("%d %d\n", check ,cnt);
        
        }
    }

    return 0;
}
```