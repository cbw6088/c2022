#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct body_size{
    int sex[10], kg[10], cm[10];
};

int main(){
    int N, ad[3] = {}, rank_1 = 0, rank_2 = 0, rank_3 = 0;
    struct body_size A,B,C;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d %d %d", &A.sex[i], &B.kg[i], &C.cm[i]);
    
    for(int i=0; i<N; i++){
        if(A.sex[i] == 1){
            if(B.kg[i] >= 70){
                if(C.cm[i] >= 175)
                    rank_1++;
                else if(C.cm[i] >= 165)
                    rank_3++;
                else
                    rank_2++;
            } // 몸무게 70 이상
            else if(B.kg[i] >= 60){
                if(C.cm[i] >= 175)
                    rank_2++;
                else if(C.cm[i] >= 165)
                    rank_1++;
                else
                    rank_3++;
            } // 몸무게 60 이상
            else 
                if(C.cm[i] >= 175)
                    rank_3++;
                else if(C.cm[i] >= 165)
                    rank_2++;
                else
                    rank_1++;
            // 몸무게 60 미만
        } // 여자

        if(A.sex[i] == 2){
            if(B.kg[i] >= 60){
                if(C.cm[i] >= 175)
                    rank_1++;
                else if(C.cm[i] >= 165)
                    rank_3++;
                else
                    rank_2++;
            }
            else if(B.kg[i] >= 50){
                if(C.cm[i] >= 175)
                    rank_2++;
                else if(C.cm[i] >= 165)
                    rank_1++;
                else
                    rank_3++;
            }
            else
                if(C.cm[i] >= 175)
                    rank_3++;
                else if(C.cm[i] >= 165)
                    rank_2++;
                else
                    rank_1++;
        }
    }
    printf("%d %d %d\n", rank_1, rank_2, rank_3);
    
    return 0;
}