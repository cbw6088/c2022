#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int N, cnt = 0, idx = 0;
    scanf("%d", &N);
    getchar();
    for(int i=0; i<N; i++){
        cnt = 0;
        idx = 0;
        int check = 0;
        char str1[100] = {};
        char * p = str1, *q = str1;
        fgets(p, 100, stdin);
        int len = strlen(p);
        for(int i=0; i<=len; i++){       
            if(*(p+i) != ' '){
                if(*(p+i) >= '0' && *(p+i) <= '9'){
                    cnt++;
                }
            }
            else if(*(p+i) == ' '){
                q = p + i + 1;
                *(p + i) = 0;
                cnt = 0;
            }
            else
                cnt = 0;
            if(cnt == 4 && ( *(p+i+1) < '0' || *(p+i+1) > '9') ){
                *(p+i+1) = 0;
                printf("%s\n", q);
                check = 1;
                break;
            }
        }
        if(check == 0)
            printf("none\n");
    }
    return 0;
}

/*
4
1234 the 12345
12345 phone 2345
12345 my 12345 mobible
his number is 5555 12345
*/