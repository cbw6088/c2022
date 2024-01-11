#include <stdio.h>

int is_prime_number(int num);
int count_prime_number(int cnt, int num);

int main(){
    // freopen("input2.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    int A[N];
    
    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);

    int prime = 0;
    int temp = 0;
    int cnt = 0;
    int max_len = 0;

    for(int i=0; i<=N; i++){
        if(count_prime_number(cnt,A[i])!=0){
            cnt = count_prime_number(cnt,A[i]); // 길이 1개 증가
            temp = A[i]; // 마지막 소수 기억
        }// 소수인 경우
        else{
            if(max_len< cnt){ // 이전 소수의 연속 길이보다 현재 소수의 길이가 더 길면
                max_len = cnt; // 길이 갱신
                prime = temp; // 소수 갱신
                cnt = 0;
            }
            else {cnt = 0;}
        }//소수가 아니거나 100이상
    }
    if(max_len == 0){ printf("%d\n", max_len) ;}
    else
        printf("%d\n%d\n", max_len, prime);
    
    return 0;
}

int is_prime_number(int num){
    int cnt = 0;
        for(int i=1; i<num; i++){
            if(num%i == 0)
                cnt++;
            if(cnt>=2){
                return 0;
            }
        } //for
    return cnt;
}
int count_prime_number(int cnt, int num){
    return (num >=100 || is_prime_number(num)==0)?0:++cnt;
    // 만약 100이상이거나 소수라면 0을 반환하고 그게 아니면 카운터+1 리턴
}