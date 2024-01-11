## <strong>시험 대비 예상 문제</strong>
### <strong>01</strong>
- 양의 정수 n의 각 자리 숫자로 헤더 단일연결리스트를 생성하고 이 헤더노드 H의 주소를 반환하는 재귀알고리즘 makelist(n)의 빈 칸을 채우시오.
- 예시
    n = 4089에 대해, (H, 4, 0, 8, 9)리스트를 생성하고 H를 반환한다.
    n = 3에 대해, (H, 3)리스트를 생성하고 H를 반환한다.
    n = 0에 대해, (H), 즉  empty list의 헤더 H를 반환한다.
```c++
Alg makelist(n)
1. H <- getnode()
2. H.next <- '\0'
3. return rMakelist(n)

Alg rMakelist(H, n)
1. if(n = 0)
    return H
   else
    H.[A]
    [B]
```
- [A] : addFirst(n % 10)
- [B] : return rMakelist(H, n / 10)


### <strong>02</strong>
- 할당 크기 N인 비트벡터 A에 대한 두 개 메쏘드의 빈 칸에 들어갈 코드를 작성하라.
```c++
Alg member(x)
1. return [A]

Alg subset(B)
1. for i<- 0 to N - 1
    if([B])
        return False
2. return True
```
- [A] : A[x]
- [B] : A[i] & !B[i]

### <strong>03</strong>
- 할당 크기 N인 비트벡터 A에 대한 두 개 메쏘드의 빈 칸을 채우시오.
```c++
Alg intersect(B)
1. C <- empty bitvector
2. for i <- 0 to N - 1
    if([A])
        C.addElem(i)
3. return

Alg subtract(B)
1. C <- empty bitvector
2. for i <- 0 to N - 1
    if([B])
        C.addElem(i)
3. return
```
- [A] : A[i] & B[i]
- [B] : A[i] & !B[i]

### <strong>04</strong>
- 아래 알고리즘을 점근분석한 결과를 빈 칸에 Big-Oh로 표기하라.

```c++
Alg a(r, k)
1. s <- 0
2. for t <- 1 to 3 * k
    for i <- 1 to t
        s <- s + t * r
3. return
{Total [A]}
```
- [A] : O(kk)

### <strong>05</strong>
- 정렬된 단일연결리스트로 표현된 두 집합 A, B를 인자로 전달받아 파괴적이며 재귀적인 방식으로 수행하여 역시 정렬된 단일연결리스트로 표현된 합집합과 교집합을 반환하는 알고리즘 union(A, B) 및 intersect(A, B)를 가장 효율적으로 작성하고자 한다.
- 두 알고리즘이 수행해야 할 작업 내용 가운데 옳은 것을 "모두" 고르시오.
1. <strong>두 알고리즘 모두 구동알고리즘 없이 직접재귀하는 방식으로 작성 가능하다.</strong> (O)
2. <strong>두 재귀알고리즘의 base case는 모두 집합 A 또는 B가 널리스트 즉, 공집합에 이른 경우를 다룬다.</strong> (O)
3. <strong>두 알고리즘 모두 O(1)공간으로 수행 가능하다.</strong> (O)
4. <strong>두 알고리즘 모두 반복문 없이 작성 가능하다.</strong> (O)
5. 두 알고리즘 모두 O(|A| + |B|)공간 및 시간을 소요한다.
6. 집합을 구성하는 노드들의 링크 필드를 접근하지 않는 방식으로 작성 가능하다.
7. 집합을 구성하는 노드들의 원소 필드를 접근하지 않는 방식으로 작성 가능하다.
8. 합집합 알고리즘은 O(n)공간, 교집합 알고리즘은 O(1)공간으로 수행 가능하다.

### <strong>06</strong>
- 아래 알고리즘을 점근분석한 결과를 빈 칸에 Big-Oh로 표기하라.
```c++
Alg b(m, p)
1. s <- m
2. for i <- 1 to p
    for j <- 1 to i^2
        s <- s + j
3. return
{Total [A]}
```
- [A] : O(ppp) 

### <strong>07</strong>
- 헤더 및 트레일러가 없는 단일연결리스트 L을 복제하여 반환하는 재귀알고리즘의 빈칸을 채우시오.
```c++
Alg copy(L)
1. if(L = '\0')
    reutnr '\0'
2. node <- [A]
3. node.elem <- L.elem
4. node.next <- [B]
5. [C]
```
1. [A] : getnode()
2. [B] : copy(L.next)
3. [C] : return node

### <strong>08</strong>
- 다음 보기들은 점근분석에 관한 주장들이다.
- 이 가운데 옳은 것을 "모두" 고르시오.
1. 알고리즘의 점근분석 결과는 해당 알고리즘을 수행하는 하드웨어나 소프트웨어에 따라 달리질 수 있다.
2. 알고리즘 A의 모든 Big-Oh시간이 알고리즘 B의 Big-Oh시간보다 크면, 어떤 입력에 대해서든 알고리즘 A의 수행시간이 알고리즘 B의 수행시간보다 느리다는 것을 의미한다.
3. 어떤 알고리즘을 분석한 결과 Big-Oh값과 Big-Omega값이 동일하게 나타날 수 없다.
4. <strong>알고리즘에 대한 점근분석은 소량이 아닌 비교적 대량의 입력에 대한 분석을 목표로 한다.</strong> (O)
5. <strong>알고리즘의 공간 소요량에 대한 점근분석 시, 해당 알고리즘의 전역 변수 또는 매개변수가 차지하는 공간은 합산하지 않는다.</strong> (O)
6. 알고리즘의 Big-Oh시간과 Big-Oh공간은 대개 비례한다.
7. 점근분석은 결과 표기법 가운데 Big-Oh는 하한을, Big-Omega는 상한을 의미한다.
8. 점근분석은 알고리즘의 실행 시간과 공간 사용량에 대한 분석이며 알고리즘 수행에 필요한 원시작업의 개수를 합산하여 표현하는 것이 일반적이다.

### <strong>09</strong>
- 크기 n인 양의 정수 배열 A의 모든 원소가 홀수(odd)면 True를, 그렇지 않으면 False를 반환하는 재귀알고리즘 odd(A, n)의 빈 칸을 채우시오
```c++
Alg odd(A, n)
1. if(n = 0)
        return True
    else
        return A[n - 1] % 2 = 1 & [A]
```
- [A] : odd(A, n - 1)

### <strong>10</strong>
- 아래 알고리즘 w() 호출시점의 인자 연결리스트 A = (1, 5, 4, 6, 2, 8)이었다고 전제하고 반환값을 구하라.
```c++
Alg w(A)
1. k <- A.size()
2. B <- create a null linked list
3. for i <- 1 to k / 2
    if(A.get(i) < A.get(k - i + 1))
        B.addLast(A.remove(i))
        A.addFirst(0)
4. return A, B
```
- 반환값 A = [A] : (0, 0, 5, 6, 2, 8)
- 반환값 B = [B] : (1, 4)

### <strong>11</strong>
- 인자로 주어진 두 개의 양의 정수 a, b에 대해 a의 b승을 계산하여 반환하는 알고리즘 r(a, b)의 빈 칸을 채우시오.
```c++
Alg r(a, b)
1. if(b = 0)
        return 1
    else
        return [A]
```
- 정답 a * r(a, b - 1)

### <strong>12</strong>
- 이중연결리스트 중앙 노드를 찾는 알고리즘 findMiddle()의 빈 칸을 채우시오.
```c++
Alg findMiddle()
1. n <- H.next
2. p <- T.prev
3. while(n != p)
    n <- [A]
    p <- p.prev
4. return [B]
```
- [A] : n.next
- [B] : n | p