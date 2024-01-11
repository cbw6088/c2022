#include <stdio.h>

int main(void){
    int N=0; int M=0; double avg=0; double NN=0; double MM=0;
    scanf("%d %d",&N,&M);
    if( (N > 100 || N < 0) || (M > 100 || M < 0) ){return -1;}

    NN = N * 0.4;
    MM = M * 0.6;
    avg = NN + MM;

    //printf("%.1lf %.1lf %.1lf\n",NN,MM,avg);

    if(avg >= 85.5){
        printf("A");
    }
    else if(avg < 85.5 && avg >= 75.5){
        printf("B");
    }
    else if(avg < 75.5 && avg >= 60.0){
        printf("C");
    }
    else{
        printf("F");
    }

    if(avg >= 60 || M >= 90){
        printf(" PASS");
    }
    else{
        printf(" FAIL");
    }

    return 0;
}