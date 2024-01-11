from collections import deque

# 변수
NodeCnt, LinkCnt, StrNum = map(int, input().split())
dList = [0] * (NodeCnt + 1)
bList = [0] * (NodeCnt + 1)
LinkList = [[0]*(NodeCnt + 1) for i in range(NodeCnt + 1)] # 연결된 노드인지 2차원 배열을 이용하여 확인


def DFS(Node) : # DFS 함수
    dList[Node] = 1 # 해당 위치 1로 변경
    print(Node, end =  ' ')
    for i in range(1, NodeCnt + 1) : # 리스트의 벨류 인덱스 값 까지 반복 
        if dList[i] == 0 and LinkList[Node][i] == 1 : # 해당 노드 첫 방문 및 연결된 노드인지 확인
            DFS(i) # 재귀
            

def BFS(Node) : # BFS 함수
    queue = deque([Node]) # queue에 현재 노드 값 deque
    bList[Node] = 1 # 현재 위치 1로 변경
    while queue : # queue 모두 순회
        Node = queue.popleft() # queue의 좌측 부터 차례로 pop
        print(Node, end = ' ')
        for i in range(1, NodeCnt + 1) :
            if bList[i] == 0 and LinkList[i][Node] == 1 : # 해당 노드 첫 방문 및 연결된 노드인지 확인
                queue.append(i) # queue 맨 뒤에 현재 값 저장
                bList[i] = 1 # 현재 위치 1로 변경


for i in range(LinkCnt) : # LinkCnt만큼 반복
    fnt, bak = map(int, input().split()) # 입력 값을 공백 기준으로 나누고 해당 값을 int형으로 fnt, bak에 저장
    LinkList[fnt][bak] = LinkList[bak][fnt] = 1

DFS(StrNum)
print()
BFS(StrNum)