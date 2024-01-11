#include <stdio.h>

int main(void){
	int X[100]={0},Y[100]={0},Z[100]={0};
	int M1=0,M2=0,N=0,cnt=0,st=0,temp=0,idx=0,result=0,check=0;;
	scanf("%d %d",&M1,&M2);

	while(1){
		scanf("%d",&N);
		if(N < 1){break;}

		for(int i=N; i>0; i=i/10){
			Y[idx++] = i % 10;
			cnt++;
		}
		idx = 0;

		for(int i=0; i<cnt; i++){
			if(i == M1 || i == M2){
				continue;
			}
			else{
				Z[idx++] = Y[i];
			}
		}

		for(int i=0; i<idx; i++){
			if(Z[i] == Z[idx-1-i]){
				temp++;
			}
		}

		if(idx == temp){
			X[result++] = N;
			check = 1;
		}
		temp = 0;
		idx = 0;
		cnt = 0;
	}

	for(int i=0; i<result; i++){
		for(int j=0; j<result; j++){
			if(X[i] > X[j]){
				st = X[i];
				X[i] = X[j];
				X[j] = st;
			}
		}
	}
	if(check == 1){
		for(int i=0; i<result; i++){
			printf("%d ",X[i]);
		}
	}	
	else{
		printf("none");
	}
    return 0;
}

// -------------- 에 타 풀 이 ----------------

/*#include <stdio.h>

int main(void){
    int Y[100], X[100], result, cnt=0;
    int idx, rev, tmp;
    int N, M1, M2;

    // M1, M2 입력
    scanf("%d %d",&M1, &M2);

    while(1){
        idx = 0;
        //Y의 모든 요소를 -1로 초기화, 들어오는 정수들과 구분하기 위함
        for(int i=0; i<100; i++) Y[i] = -1;

        // N 입력, 종료 조건 : N<=0
        scanf("%d",&N);
        if(N < 1){break;}

        // N을 건드리지 않기 위해 tmp에 N값 저장
        tmp = N;

        // tmp, 즉 N을 다 나누어 배열 Y에 저장
        while(tmp){
            Y[idx++] = tmp%10;
            tmp /= 10;
        }

        // 입력 받은 수 중 M1, M2 인덱스를 제외한 수를 정수로 만든 것 : result
        result = 0;

        for(int i=0; i<idx; i++){
            // M1, M2의 요소를 -1로 초기화
            // 위에서 배열을 모두 -1로 초기화 해뒀기 때문에 필요한 값 이외에 모든 배열 요소가 -1임.
            if(i==M1 || i==M2) Y[i] = -1;
            if(Y[i] >= 0) result = result*10 + Y[i];
        }

        // 역수 구하는 방법으로 result의 역수를 구하고 result와 같은지 확인.
        // 만약 같다면 회문수이므로 N을 배열 X에 추가.
        rev = 0;
        tmp = result;
        while(tmp){
            rev = rev*10 + tmp%10;
            tmp/=10;
        }

        // rev == result 라면 회문수이므로, 최초 입력받은 N을 X에 추가
        if(rev == result) X[cnt++] = N;

    }

    // cnt==0 인 경우는 회문수가 없다는 뜻으로 "none" 출력 후 프로그램 종료
    if(cnt == 0){
        printf("none");
        return 0;
    }

    int st;
    for(int i=0; i<cnt; i++){
        for(int j=0; j<cnt; j++){
            if(X[i] > X[j]){
                st = X[i];
                X[i] = X[j];
                X[j] = st;
            }
        }
    }

    return 0;
}*/