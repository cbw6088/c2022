num = int(input()) # 입력
list_num = []
for i in range(num) : # 입력 받은 값 까지 반복
    num_input = int(input())
    list_num.append(num_input) # 입력 받은 값 저장
    
list_num.sort() # 정렬
for i in range(num) :
    print(list_num[i])