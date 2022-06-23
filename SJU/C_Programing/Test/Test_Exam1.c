#include <stdio.h>
int main(void){
    int N=0; int M=0; int HND=0; int c=0; int s=0; int d=0;
    int cnt=0; int cc=0; int sc=0; int dc=0; int x=0; int y=0; int z=0;
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%d",&M);
        x = M/10000;
        y = (M/1000)%10;
        z = (M/100)%10;

        if(M>=10000 && M<100000 && M%100==0 && M%10==0){

            if( (x != y && x != z && y != z) || (x == y && x == z && y == z)){
            printf("none\n");
            cnt=1;
            }

            else{
            HND = M/100;
            HND = HND%10;
                if(HND>=0 && HND<3){
                    printf("CE\n");
                    c++;
                    if(cnt != 0){
                        cc++;
                        cnt=0;
                    }
                }    
                else if(HND>=3 && HND<5){
                    printf("SW\n");
                    s++;
                    if(cnt != 0){
                        sc++;
                        cnt=0;
                    }
                }
                else if(HND==5){
                    printf("DS\n");
                    d++;
                    if(cnt != 0){
                        dc++;
                        cnt=0;
                    }
                }
                else{
                    printf("none\n");
                    cnt=1;
                }
            }
        }

        else{
            printf("none\n");
            cnt=1;
        }
    }
    printf("%d %d %d\n",c,s,d);
    printf("%d %d %d",c-cc,s-sc,d-dc);
  return 0;
}
