#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct time{
    int T[3];
};

int main(){
    struct time T1, T2, T3;
    scanf("%d %d %d", &T1.T[0], &T1.T[1], &T1.T[2]);
    scanf("%d %d %d", &T2.T[0], &T2.T[1], &T2.T[2]);


    for(int i=0; i<3; i++){
        T3.T[2-i] = T2.T[2-i] - T1.T[2-i];
        if(T3.T[2-i] < 0){
            T3.T[2-i] = T3.T[2-i] + 60;
            T1.T[1-i] = T1.T[1-i] + 1;
        }
    }

    printf("%d %d %d",T3.T[0], T3.T[1], T3.T[2]);
    
    return 0;
}