# <strong>정렬 일반</strong>

### 비교정렬의 하한
1. 비교정렬
    - 비교에 기초한 정렬(comparison - based sorting)
    - 개체 쌍을 비교함으로써 정렬
    - 예시 : 버블 정렬, 선택 정렬, 삽입 정렬, 힙 정렬, 합병 정렬, 퀵 정렬, ...
2. 각각 n개의 키 k1, k2, ... , kn 으로 구성된 원소들을 정렬하는 비교정렬 알고리즘의 하한을 유도

### 유도 단계 1
1. n개의 유일한 키로부터 n!개의 순서가 존재 (참고 : 순열)
2. 오름차순 정렬 기준으로, 이 가운데 단 하나의 순서만이 정렬 순서

### 유도 단계 2
1. 비교 회수를 세어보자
2. 각 알고리즘이 취할 수 있는 수행은 결정트리에서 루트로부터 잎으로 향하는 경로와 일치


### 유도 단계 3
1. 이 결정트리의 높이 : 실행시간의 하한
2. 각각의 상이한 입력 순열은 상이한 하향경로를 순회
3. n!개의 외부노드가 있으므로, 높이는 최소 log(n!)

### 유도 단계 4
1. 그러므로 어떤 비교정렬 알고리즘도 최소 log(n!)시간을 소요
2. log(n!) >= log(n/2)의 n/2승 == (n/2)log(n/2)
3. 결론 : 어떤 비교정렬 알고리즘이라도 오메가(n logn)시간에 수행

### 정렬의 안정성
1. 키-원소 항목들을 정렬할 때, 중요한 이슈는 동일 키가 어떻게 처리되냐는 것이다.
2. L = ( (k0, e0), ... , (kn-1, en-1) ) 을 항목들의 리스트라 하자
3. 두 개의 항목 (ki, ei)가 (kj, ej)에 대해
    - ki = kj며 정렬 전에 (ki, ei) 가 (kj, ej)보다 앞서 있었다면 (즉, i < j)
    - 만약 정렬 후에도 (ki, ei)가 (kj,ej)보다 앞서 있다면
    - 그 정렬 알고리즘을 안정적이라고 말한다.
4. 정렬 알고리즘에 있어서 안정성은 중요 - 왜냐하면 많은 응용에서 동일 키 원소들의 원래 순서가 보존되어야 할 필요가 있기 때문

### 비교정렬 알고리즘 비교
1. 선택 정렬
    - 시간 : O(n^)
    - 주요 전략 : 우선순위 큐 (무순 리스트로 구현)
    - 비고 : 제자리, 느림 (소규모 입력에 적당)
2. 삽입 정렬
    - 시간 : O(n^)
    - 주요 전략 : 우선순위 큐 (순서 리스트로 구현)
    - 비고 : 제자리, 느림 (소규모 입력에 적당)
3. 힙 정렬
    - 시간 : O(nlogn)
    - 주요 전략 : 우선순위 큐 (힙으로 구현)
    - 비고 : 제자리, 빠름 (대규모 입력에 적당)
4. 합병 정렬
    - 시간 : O(nlogn)
    - 주요 전략 : 분할통치
    - 비고 : 순차 데이터접근, 빠름 (초대규모 입력에 적당)
5. 퀵 정렬
    - 시간 : O(nlogn) 기대시간
    - 주요 전략 : 분할통치
    - 비고 : 제자리, 무작위, 가장 빠름 (대규모 입력에 적당)

### 응용문제 : 투포 / 두 키로 정렬은 교안 참조(교재 6주차 PDF_File)
