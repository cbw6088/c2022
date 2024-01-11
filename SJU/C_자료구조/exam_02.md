## <strong>2장 재귀</strong>
### <strong>재귀 알고리즘</strong>
- 알고리즘 자신을 사용하여 정의된 알고리즘을 재귀적이라고 말한다.
    - 비재귀적 또는 반복적 알고리즘과 대조
- 재귀의 요소
    - 재귀 케이스 : 차후의 재귀호출은 작아진 부문제들을 대상으로 이루어진다.
    - 베이스 케이스 : 부무제들이 충분히 작아지면, 알고리즘은 재귀를 사용하지 않고 이들을 직접 해결한다.
```c++
Alg sum(n)
1. if(n = 1)    // base case
        return 1
    else        // recursion
        return n + sum(n - 1)
```

### <strong>기본 규칙</strong>
- 베이스 케이스 : 베이스 케이스를 항상 가져야 하며, 이 부분은 재귀 없이 해결 가능
- 진행 방향 : 재귀적으로 해결되어야 할 경우, 재귀호출은 항상 베이스 케이스를 향하는 방향으로 진행
- 정상작동 가정 : 모든 재귀호출이 제대로 작동한다고 가정
- 적절한 사용 : 꼭 필요할 때만 사용 -> 저장 / 복구 때문에 성능 저하

### <strong>잘못된 재귀</strong>
- 잘못 설계된 재귀
    - 베이스 케이스 : 없음
    - 재귀 케이스 : 도달 불능 -> 즉, 베이스 케이스를 향해 재귀하지 않음
```c++
Alg sum1(n)
    1. return n + sum1(n - 1) // 베이스 케이스가 없는 경우

Alg sum2(n)
    1. if(n = 1)    // base case
        reutnr 1
    else            // recursion
        return n + sum2(n + 1)
```

### <strong>잘 설계된 재귀의 예</strong>
- printDigits는 재귀적 rPrintDigits를 구동하는 양의 정수를 한 라인에 한 숫자씩 인쇄
- ex : 3408 입력 시 3\n 4\n 0\n 8 출력
```c++
Alg printDigits()       // driver
1. write("Enter a number")
2. n = read()
3. if(n < 0)            // error check
        write("Negative number!")
    else
        rPrintDigits(n) // initial call

Alg rPrintDigits(n)     // recursive
1.  if(n < 10)          base case
        write(n)
    else                // recursion
        rPrintDigits(n / 10)
        write(n % 10)
```

### <strong>응용 문제 : 재귀적 곱하기와 나누기</strong>
1. a와 b의 곱을 계산하는 재귀 알고리즘 product(a, b)를 작성하라
2. a를 b로 나눈 나머지를 계산하는 재귀 알고리즘 modulo(a, b)를 작성하라
3. a를 b로 나눈 몫을 계산하는 재귀 알고리즘 quotient(a, b)를 작성하라
4. 주의 : 의사코드로 작성, a와 b는 양의 정수, 덧셈과 뺄셈을 제외한 산술연산자 사용 불가
```c++
Alg product(a, b)
    input positive integer a, b
    output product of a and b
1. if(b == 1)   // base case
        return a
    else        // recursion
        return a + product(a, b - 1)

Alg modulo(a, b)
    input positive integer a, b
    output a % b

1. if(a < b)    // base case
        return a
    else        // recursion
        return modulo(a - b, b)

Alg quotient(a, b)
    input positive integer a, b
    output a/b
1. if(a < b)    // base case
        return 0
    else        // recursion
        return 1 + quotient(a - b, b)
```

### <strong>응용문제 : 하노이탑</strong>
1. 하노이탑 문제
    - 세 개의 말뚝 : A, B, C
    - 초기 상황 : 직경이 다른 n > 0개의 원반이 A에 쌓여 있음
    - 목표 : 모든 원반을 A로부터 C로 옮김
    - 이동 순서를 "move from x to y" 형식으로 인쇄할 것
2. 조건
    - 한 번에 한 개의 원반만을 이동
    - 언제라도 직경이 큰 원반을 작은 원반 위에 놓지 말 것
    - 남은 말뚝을 보조 말뚝으로 사용 가능
    - 일반적으로 n개의 원반에 대해 2n - 1회의 이동이 필요
    - n = 1 인 경우, 1회의 이동
    - n = 2 인 경우, 3회의 이동
    - n = 3 인 경우, 7회의 이동
    - n = 64 인 경우, 264 - 1 = 1.844 x 1019회의 이동
<br> 해결 답안

- n : 이동해야 할 원반 수 / from : 출발 말뚝 / aux : 보조 말뚝 / to : 목표 말뚝
```c++
Alg hanoi(n)
1. rHanoi(n, 'A', 'B', 'C')     // initial call
2. return

Alg rHanoi(n, from, aux, to)    // recursive
    input integer n, peg from, aux, to
    output move sequence
1. if(n = 1)                    // base case
        write("move from", from, "to", to)
        return
2. rHanoi(n - 1, from, to, aux) // recursion
3. write("move from", from, "to", to)
4. rHanoi(n - 1, aux, from, to) // recursion
5. return
```
