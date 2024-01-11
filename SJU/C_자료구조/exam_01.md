## <strong>1장 알고리즘 분석</strong>
### <strong>Big-Oh</strong>
- Big-Oh와 증가율
    - Big-Oh 표기법은 함수 증가율의 상한을 나타낸다.
    - "f(n) = O(g(n))" 이라 함은 "f(n)의 증가율은 g(n)의 증가율을 넘지 않는다"는 의미
    - 즉, "f(n) = O(g(n))"은 "g(n)이 f(n)보다 크거나 같다"의 의미
    - Big-Oh는 최악의 시간을 나타낸다.
- Big-Oh 표기법의 예시
    - O(1) < O(log n) < O(n) < O(nlog n) < O(n^2) < O(2^n)
    - 계산 요령
        - 낮은 차수의 항 제거
        - 상수계수 제거
        - 최소한의 함수계열 사용
        - 해당 함수계열 중 가장 단순한 표현을 사용
        - ex : 3n + 5 = O(n), 2n^2 + 3n + 10 = O(n^2)
### <strong>Big-Oh 외의 것들</strong>
- Big-Omega
    - Big-Oh가 함수 증가율의 상한을 나타낸다면 Big-Omega는 하한을 나타낸다.
    - 최상의 시간을 나타낸다.
- Big-Theta
    - 함수 증가율의 상한, 하한 모두 나타냄으로 동일함수를 나타낸다.
    - 평균 시간을 나타낸다.
- 점근표기에 관한 직관
    - Big-Oh : f(n) <= g(n) 일 경우 f(n) = O(g(n))
    - Big-Omega : f(n) >= g(n) 일 경우 f(n) = 오메가(g(n))
    - Big-Theta : f(n) = g(n) 일 경우 f(n) = 세타(g(n))
- 전형적인 증가율
<img width="953" alt="image" src="https://user-images.githubusercontent.com/99342700/233916336-72698f1b-f443-42b6-99d1-6dfb51569817.png">

### <strong>응용 문제 : 행렬에서 특정 원소 찾기</strong>
<br>n x n 배열 A의 원소들 중 특정 원소 x를 찾는 알고리즘 findMatrix를 작성하고자 한다.
<br>알고리즘 findMatrix는 A의 행들을 반복하며, x를 찾거나 또는 A의 모든 행들에 대한 탐색을 마칠 때 까지 findRow를 호출한다.

1. findMatrix를 의사코드로 작성하라.
2. findMatrix의 최악의 실행시간을 n에 관하여 구하라.
3. 이는 선형시간 알고리즘인가? 이유와 함께 설명하라. (선형시간 == O(n))
```c++
/*제시된 문제 코드*/
Alg findRow(A,x)
    input array A of n elements, element x
    output index i such that x = A[i] or -1 if no element of A is equal to x

    1. i <- 0
    2. while(i < n)
        if(x = A[i])
            return i
        else
            i <- i + 1
    3. return -1
```
<br> 해결 답안

```c++
/*문제 해결 코드*/
Alg findMatrix(A, x)
    input array A of n x n elements, element x
    output the location of x in A or a failure message if no element of A is equal to x

    1. r <- 0
    2. while(r < n)
        i <- findRow(A[r], x)
        if(i >= 0)
            write("found at", r, i)
            return
        else
            r <- r + 1
    3. write("not found")
    4. return
```
1. 최악의 실행시간은 O(n^2)
    - 최악의 경우, 원소 x는 검사 대상인 n x n배열의 마지막 원소
    - 이 경우, findMatrix는 findRow를 n번 호출하게 된다.
    - 즉, findRow를 호출할 때 마다 n회의 비교가 수행
    - 그러므로 findRow가 n회 호출되므로 총 n x n회의 작업을 수행하는 것이 되고 이는 O(n^2)의 시간이 걸린다.
2. 선형시간 알고리즘이 아니다.
    - n^2은 2차시간이다. 즉, 실행시간이 입력 크기에 제곱비례 한다.
    - 선형시간이 되려면, 실행시간이 입력 크기에 정비례해야 할 것이다.

### <strong>응용문제 : 비트행렬에서 최대 1행 찾기</strong>
1. n x n 배열 A의 각 행은 1과 0으로만 구성되며, A의 어느 행에서나 1들은 해당 행의 0들보다 앞서 나온다고 가정
2. A가 이미 주기억장치에 존재한다고 가정하고, 가장 많은 1을  포함하는 행을 O(n) 시간에 찾는 mostOnes(A, n)을 의사코드로 작성
```c++
/*제시된 문제 코드*/
Alg mostOnesButSlow(A, n)
    input bit matrix A[n x n]
    output the row of A with most 1's

    1. row <- jmax <- 0
    2. for i <- 0 to n - 1
        j <- 0
        while((j < n) & (A[i, j] = 1))
            j <- j + 1
        if(j > jmax)
            row <- i
            jmax <- j
    3. return row

/*
1 1 1 1 0 0 0 0
1 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0
1 1 1 1 1 1 0 0
1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0 <- 가장 긴 행
1 1 1 1 1 0 0 0
*/
```
- 주의 : 알고리즘 mostOnesButSlow는 1이 가장 많은 행을 찾기는 하지만, 실행시간이 O(n)이 아닌 O(n^2)이다.

<br> 해결 답안

```c++
/*문제 해결 코드*/
/*ver.1*/
Alg mostOnew(A, n)
    input bit matrix A[n x n]
    output the row of A with most 1's

    1. i <- j <- 0
    2. while(1)
        while(A[i, j] = 1)
            j <- j + 1
            if(j = n)
                return i
        row <- i
        while(A[i, j] = 0)
            i <- i + 1
            if(i = n)
                return row
/*Total O(n)*/

/*ver.2*/
Alg mostOnes(A, n)
    input bit matrix A[n x n]
    output the row of A with most 1's

    1. i <- j <- row <- 0
    2. while((i < n) & (j < n))
        if(A[i, j] = 0)
            i <- i + 1
        else
            row <- i
            j <- j + 1
    3. return row
/*Total O(n)*/
```
1. 최대 2n회의 비교를 수행하므로, 명백히 O(n)시간 알고리즘
2. 두 가지 버전으로 작성 가능

### <strong>응용문제 : 누적평균</strong>
1. 배열 X의 i번째 누적평균이란 X의 i번째에 이르기까지의 i + 1개의 원소들의 평균이다.
2. 배열 X의 누적평균 배열 A를 구하는 알고리즘을 의사코드로 작성하라
3. 응용 : 경제, 통계 분야
    - 오르내림 변동을 순화시킴으로써 대략적인 추세를 얻어내기 위해 사용
    - 부동산, 주식, 펀드 등에 활용
<br> 해결 답안

- 아래 알고리즘은 정의를 이용하여 누적평균값들을 2차 시간에 구한다.
```c++
/*ver.1*/
Alg prefixAverages1(X, n)
    input array X, A of n integers
    output array A of prefix averages of X

    1. for i <- 0 to n - 1      // {n}
        sum <- 0                // {n}
        for j <- 0 to i         // {1 + 2 + . . . + n}
            sum <- sum + X[j]   // {1 + 2 + . . . + n}
        A[i] <- sum(i + 1)      // {n}
    2. return                   // {1}
/*Total O(n^2)*/
```
- 아래 알고리즘은 중간 합을 보관함으로써 누적평균값들을 선형시간에 구한다.
```c++
Alg prefixAverages2(X, n)
    input array X, A of n integers
    output array A of prefix averages of X

    1. sum <- 0             // {1}
    2. for i <- 0 to n - 1  // {n}
        sum <- sum + X[i]   // {n}
        A[i] <- sum(i + 1)  // {n}
    3. return               // {1}
/*Total O(n)*/
```

