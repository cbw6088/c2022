#include <stdio.h>

int main(void){
    char N; char M;
    int err=0;
    scanf("%c%c",&N,&M);
    for(char i = N; i <= M; i++){
        for(char j = N; j <= M; j++){
            for(char k = N; k <= M; k++){
                if(j=='a' || j=='e' || j=='i' || j=='o' || j=='u'){
                    if(i != k){
                        if(i <= j && k >= j){
                            printf("%c%c%c\n",i,j,k);
                        }
                        else if(i >= j && k <= j){
                            printf("%c%c%c\n",i,j,k);
                        }
                    }
                }
                else{
                    err=1;
                }
            }
        }
    }
    if(err==1){
        printf("none");
    }
    return 0;
}