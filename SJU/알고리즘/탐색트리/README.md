# <strong>탐색트리</strong>

## 트리와 이진트리
### 트리
1. 트리는 노드들과 노드들을 연결하는 링크들로 구성됨
    - 보통 부모 / 자식 / 형제 / 리프 / 조상 / 자손 노드로 구분
2. 트리의 레벨은 높이를 나타냄 (맨 위부터 레벨1 .... 레벨n까지 단, 받아드리는 학습자에 따라 다르므로 중요한 부분은 아님)
3. 트리의 높이는 해당 트리의 줄 수에 따라 나타냄. (즉, 트리의 갯수와 상관없이 배열한 트리의 배치가 3줄이면 높이는 3)
4. 노드가 N개인 트리는 항상 N-1개의 링크를 가진다. (링크는 노드와 노드를 연결해주는 선)
5. 트리 / 루트에서 어떤 노드로 가는 경로는 유일하다. 또한, 임의의 두 노드간의 경로도 유일하다. (같은 노드를 두 번 이상 방문하지 않는다는 조건하에)

### 이진트리
1. 이진 트리에서 각 노드는 최대 2개의 자식을 가진다.
2. 각각의 자식 노드는 자신이 부모의 왼쪽 자식인지 오른쪽 자식인지가 지정된다. (자식이 한 명인 경우에도)
3. 노드를 찾는 계싼 (x + y) * ((a + b) / c)

### Full binary tree / Complete binary tree
1. 높이가 h인 full binary tree는 2의h승 - 1 개의 노드를 가진다.
2. 노드가 N개인 full 혹은 complete 이진 트리의 높이는 O(logN)이다.(노드가 N개인 이진트리의 높이는 최악의 경우 N이 될 수 있다.)
3. 연결구조 표현
    - 각 노드에 하나의 데이터 필드와 왼쪽 자식, 오른쪽 자식, 그리고 부모노드의 주소를 저장
    - 부모노드의 주소는 반드시 필요한 경우가 아니면 보통 생략함
4. 높이가 h인 Full binary tree는 2의h승 - 1 개의 노드를 가진다.
5. 노드가 N개인 full혹은 complete 이진 트리의 높이는 O(log N)이다.

### 이진트리의 순회
1. 순회 : 이진 트리의 모든 노드를 방문하는 일
2. 중순위 순회 (inorder)
    - 루트노드 R 과 왼쪽 부트리를 TL 오른쪽 부트리를 TR이라고 했을 때
    - TL -> R -> TR 순으로 순회한다.
```c++ 
InOrder-Tree-Walk(x){ // 수도 코드 함수
    if(x != NULL){
        InOrder-Tree-Walk(left[x])
        printf("%d", key[x]);
        InOrder-Tree-Walk(right[x])
    }
}
```
3. 선순위 순회 (preorder)
    - R -> TL -> TR 순으로 순회한다.
 ```c++ 
PreOrder-Tree-Walk(x){ // 수도 코드 함수
    if(x != NULL){
        printf("%d", key[x]);
        PreOrder-Tree-Walk(left[x])
        PreOrder-Tree-Walk(right[x])
    }
}
```
4. 후순위 순회 (postorder)
    - TR -> TL -> R 순으로 순회한다.
 ```c++ 
PostOrder-Tree-Walk(x){ // 수도 코드 함수
    if(x != NULL){
        printf("%d", key[x]);
        PostOrder-Tree-Walk(left[x])
        PostOrder-Tree-Walk(right[x])
    }
}
```
5. 레벨오더 순회 (level - order)
    - 레벨 순으로 방문, 동일 레벨에서는 왼쪽에서 오른쪽 순서로
    - 큐(queue)를 이용하여 구현
```c++
LevelOrder-Tree-Traversal(){
    visit the root;
    Q = root;
    while(Q != NULL){
        v = dequeue(Q);
        visit children of v;
        enqueue children of v into Q;
        return;
    }
    return;
}
```

6. Expression트리를 inorder 순회하면 다음과 같이 출력됨
    - (x + y) * (a + b / c)
7. 각 부트리를 순회할 때 시작과 종료시에 괄호를 추가하면 다음과 같이 올바른 수식이 출력됨
    - (x + y) * ((a + b) / c)
8. Postorder 순회하면 후위표기식이 출력됨
    - x + y * a + b / c
9. 
