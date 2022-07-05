#include <stdio.h>

int main(void){
    char ch=0; char min = '^'; char max = '^'; int temp=0; int cnt=0;

    while(1){
        scanf("%c",&ch);
        if(ch == '0'){break;}

        if(cnt == 0){
            temp = ch;
            cnt = 1;
        }

        if(ch >= 'A' && ch <= 'Z'){
            if(min >= ch){
                min = ch;
            }
        }

        else if(ch >= 'a' && ch <= 'z'){
            if(max <= ch){
                max = ch;
            }
        }
    }

    if(temp >= 'a' && temp <= 'z'){
        if(max >= 'a' && max <= 'z'){
            printf("%c",max);
        }
        if(min >= 'A' && min <= 'Z'){
            printf("%c",min);
        }
    }
    else if(temp >= 'A' && temp <= 'Z'){
        if(min >= 'A' && min <= 'Z'){
            printf("%c",min);
        }
        if(max >= 'a' && max <= 'z'){
            printf("%c",max);
        }
    }
    return 0;
}