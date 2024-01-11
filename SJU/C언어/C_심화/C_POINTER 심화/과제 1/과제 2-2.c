#include <stdio.h>

int passengerN(int n); // 원형 함수 선언
void rebooking(int *ar);
int changeseat(int *ar);

int main(){
    int N; // 변수 지정
	int ar[22]={0}; // 모든 배열의 값이 0인 배열 언선
	int *p = ar; // 포인터 선언 및 연결
	int n;
    scanf("%d",&N);	// N값 입력
	for(; p<ar+N; p++) // 포인터값 입력
		scanf("%d",p);

	n = passengerN(N); // 인원수가 미달인지 확인
	if(n == -1){ // 미달이면 -1 출력 후 종료
		printf("-1\n");
		return -1;
	}
	else // 미달이 아닌 경우 0 출력 후 진행
		printf("0\n");
	p = ar; // 포인터 초기화
	rebooking(p); // 중복 확인 함수 선언
	p = ar; // 초기화
	for(; p<ar+N; p++) // 배열 출력
		printf("%d ",*p);

    return 0;
}

int passengerN(int n){
	if(n < 5) // 인원이 5명 미만이면 -1 출력
		return -1;
	else
		return 0;
}

void rebooking(int *ar){
	int *p = ar; // 포인터 선언 및 연결
	int cnt = 0,cnt2 = 0,idx = 0; // 변수 선언
	int arr[22]={0}; // 모든 인덱스 값이 0인 배열 선언
	int tmp,tmp2; 
	while(*p != 0){ // 포인터 크기 확인
		cnt++;
		p++;
	}
	p = ar; // 포인터 초기화
	for(; p<ar+cnt-1; p++){ // 포인터 2중 반복문으로 중복된 부분 체크
		for(int *q=p+1; q<ar+cnt; q++){
			if(*p == *q){ // 중복인 경우
				tmp = changeseat(p-cnt2); // 배열값에 포함되지 않은 가장 작은 값 저장
				*q = tmp; // 포인터값 변경
			}
		}
		cnt2++; // 포인터 0인덱스를 선언하기 위한 카운트
	}

}

int changeseat(int *ar){
	int *p = ar; // 포인터 선언 및 연결
	int arr[22]={0}; // 모든 값이 0인 배열 선언
	int cnt=0, idx=0, tmp; // 변수 선언
	while(*p != 0){ // 포인터 크기 확인
		cnt++;
		p++;
	}
	p = ar; // 포인터 초기화
	for(; p<ar+cnt; p++){ // 해당 포인터값 인덱스의 값을 1로 변경
		idx = *p;
		arr[idx] = 1;
	}
	p = ar;
	for(int i=1; i<22; i++){
		if(arr[i] == 0) // 인덱스의 값이 0인 배열을 찾은 후 해당 인덱스 반환
			return i;
	}
	return -1;
}

