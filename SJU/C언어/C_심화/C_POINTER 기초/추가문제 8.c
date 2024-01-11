#include <stdio.h>

int main(){
    // freopen("8.txt", "r" ,stdin);
    int N;
    scanf("%d", &N);
    int A[N];
    int *p;
    for(p=A; p<A+N; p++)
        scanf("%d", p);
    
    for(p=A; p<A+N; p++){
        int check = *p;
        int cnt = 0;
        if(check !=0){
            for(int*temp =p; temp<A+N; temp++){
                if(check == *temp){
                    *temp = 0;
                    cnt++;
                }
            }
        printf("%d %d\n", check ,cnt);
        
        }
    }

    return 0;
}