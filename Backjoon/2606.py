#DFS풀이
def DFS(value) : # DFS 함수
    global result # 개수 카운트
    recursion[value] = 1 # 해당 벨류 인덱스의 값 1로 저장

    for i in computer[value] : # 리스트의 벨류 인덱스 값 까지 반복 
        if recursion[i] == 0 : # 첫 방문 시
            DFS(i) # 재귀
            result += 1 # 카운트

# 변수
result = 0
N = int(input()) # 총 컴퓨터 개수
link = int(input()) # 연결된 컴퓨터 개수
computer = [[] for _ in range(N+1)] # append를 사용하므로 모두 null로 만들기
recursion = [0] * (N + 1) # 모두 0으로 초기화

for i in range(link) : # link만큼 반복
    fnt, bak = map(int, input().split()) # 입력 값을 공백 기준으로 나누고 해당 값을 int형으로 fnt, bak에 저장
    computer[fnt].append(bak) # 서로 값을 넣으며 연결
    computer[bak].append(fnt)

DFS(1) # 1번 컴퓨터 고정
print(result) # 결과값 출력