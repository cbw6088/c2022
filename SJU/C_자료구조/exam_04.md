## <strong>4장 리스트</strong>
### <strong>추상자료형</strong>
- 추상자료형 : 데이터구조의 추상형
- ADT는 다음을 명세
    - 저장된 데이터
    - 데이터에 대한 작업들
    - 작업중 발생 가능한 에러 상황들

### <strong>리스트 ADT</strong>
- 리스트 ADT는 연속적인 임의 개체들을 모델링
- 원소에 대한 접근 도구 : 순위
- 메소드
    - 원소는 그 순위, 즉 원소 앞의 원소 개수를 특정함으로써 접근, 삽입, 또는 삭제
- 일반 메소드
    - boolean isEmpty()
    - integer size()
    - iterator elements()
- 접근 메소드
    - element get(r)
- 갱신 메소드
    - element set(r, e)
    - add(r, e), addFirst(e), addLast(e)
    - element remove(r), element removeFirst(), element removeLast()
- 예외 : 어떤 ADT작업을 실행하고자 할 때 발생할 수도 있는 오류 상황

### <strong>리스트 응용</strong>
- 리스트 ADT : 원소들의 순서(ordered) 집단을 저장하기 위한 기초적이고, 일반적인 목적의 데이터구조
- 직업 응용
    - 스택, 큐, 집합 등을 표현하기 위한 도구
    - 소규모 데이터베이스 (예 : 주소록)
- 간접 응용
    - 더 복잡한 데이터구조를 구축하기 위한 재료로 사용

### <strong>배열을 이용한 구현</strong>
- N개의 단순 또는 복잡한 원소들로 구성된 배열 V
- 변수 n으로 리스트의 크기, 즉 저장된 원소 개수를 관리
- 배열에서 순위는 0에서 출발
- 작업 get(r)또는 set(r, e)는 O(1)시간에 V[r]을 각각 반환 또는 저장하도록 구현
    - r < 0 or r > n - 1 인 경우 예외처리 필요
### <strong></strong>
### <strong></strong>
### <strong></strong>
### <strong></strong>
### <strong></strong>
### <strong></strong>
### <strong></strong>
