# Algorithm_Priority Queue
항목들을 미리 저장하여 우선 순위별로 반환 해주는 알고리즘이다.
<br> 응용 : 탑승 대기자 / 옥션 / 주식시장
### <br> <strong>주요 메소드</strong>
<br> *k = key / e = element
- insertltem(k,e) : 키 k인 원소 e를 큐에 삽입
- element removeMin() : 큐로부터 최소 키를 가진 원소를 삭제하여 반환

### <br> <strong>일반 메소드</strong>
- integer size() : 큐의 항목 수를 반환
- boolean isEmpty() : 큐가 비어 있는지 여부를 반환

### <br> <strong>접근 메소드</strong>
- element minElement() : 큐에서 최소 키를 가진 원소에 반환
- element minKey() : 큐에서 최소 키를 반환

### <br> <strong>예외</strong>
- emptyQueueException() : 비어 있는 큐에 대해 삭제나 원소 접근을 시도 할 경우 발령
- fullQueueException() : 만원큐에 대해 삽입을 시도 할 경우 발령

### <br> <strong>우선순위 큐를 이용한 정렬</strong>
<br> 실행 시간 : 우선순위 큐의 구현에 따라 다름
<br> L,P : 일반(generic) -> 배열과 연결리스트 모두 표현 가능
<br>비교 가능한 원소 집합을 정렬하는데 우선순위 큐 이용 가능
- 연속적인 insertltem(e,e)작업을 통해 원소들을 하나씩 삽입 (key = e로 전제)
- 연속적인 removeMin()작업을 통해 원소들을 정렬 순서로 삭제

```c++
Alg PQ-Sort(L)
    input list L
    output sorted list L

1. P <- empty priority queue
2. while(!L.isEmpty())
    e <- L.removeFirst()// '.'을 기준으로 좌측은 데이터구조/리스트/배열 등등
    P.insertItem(e)// '.'을 기준으로 우측은 메스도/함수 등등 
3. while(!P.isEmpty())
    e <- P.removeMin()
    L.addLast(e)
4. return
```
### <strong>리스트에 기초한 우선순위 큐</strong>
<br>1. 무순리트트로 구현 : 우선순위 큐의 항목들을 리스트에 임의 순서로 저장
- 성능
    - insertltem : O(1)시간 소요 - 항목을 리스트의 맨 앞 또는 맨 뒤에 삽입
    - removeMin,minKey,minElement : O(n)시간 소요 - 최소 키를 찾기 위해 전체 리스트를 순회

2.순서리스트로 구현 : 우선순위 큐의 항목들을 리스트에 키 정렬 순서로 저장

- 성능
    - insertltem : O(n)시간 소요 - 항목을 삽입 할 곳을 찾음
    - removeMin,minKey,minElement : O(n)시간 소요 = 최소 키가 리스트의 맨 앞에 위치

### <strong>선택 정렬</strong>(selection - sort) : PQ - Sort의 일종 / 우선순위 큐를 무순리스트로 구현
<br><strong>실행시간</strong>
    
- n회의 insertltem작업을 사용하여 원소들을 우선순위 큐에 삽입하는데 O(n)시간 소요
- n회의 removeMin작업을 사용하여 원소들을 우선순위 큐로부터 정렬 순서로 삭제하는데 다음에 비례하는 시간 소요 -> n + (n-1) + (n-2) + ... + 2 + 1
- Total : O(n^)

### <strong>삽입 정렬</strong>(insertion - soer) : PQ Sort의 일종 / 우선순위 큐를 순서리스트로 구현
<br><strong>실행시간</strong>
- n회의 insertltem작업을 사용하여 원소들을 우선순위 큐에 삽입하는데 다음에 비례하는 시간 소요 -> 1 + 2 + ... + (n-2) + (n-1) + n
- n회의 removeMin작업을 사용하여 원소들을 우선순위 큐로부터 정렬 순서로 삭제하는데 O(n)시간 소요
- Total : O(n^)



