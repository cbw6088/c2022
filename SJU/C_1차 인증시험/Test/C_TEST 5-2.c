#include <stdio.h>

int main(void){
    char N; char M; char T1,T2,T3; char t1,t2,t3;
    int err=0; int T=0;
    scanf("%c%c-%c%c%c",&N,&M,&T1,&T2,&T3);
    for(char i = N; i <= M; i++){
        for(char j = N; j <= M; j++){
            for(char k = N; k <= M; k++){
                if(j=='a' || j=='e' || j=='i' || j=='o' || j=='u'){
                    err=1;
                    if(i != k){
                        if( (i <= j && k >= j) || (i >= j && k <= j) ){
                            printf("%c%c%c\n",i,j,k);
                            if(i < T1){
                                T=1;
                                t1 = i;
                                t2 = j;
                                t3 = k;
                            }
                            else if(i == T1){
                                if(j < T2){
                                    t1 = i;
                                    t2 = j;
                                    t3 = k;
                                }
                                else if(j == T2){
                                    if(k < T3){
                                        t1 = i;
                                        t2 = j;
                                        t3 = k;
                                    }
                                }
                            }
                        }
                        
                    }
                }
            }
        }
    }
    if(err==0){
        printf("none\n");
    }
    if(T==1){
        printf("%c%c%c",t1,t2,t3);
    }
    else if(T==0){
        printf("none");
    }
    return 0;
}