#include <stdio.h>

int main(void){
    char new; char max='A'; char min='Z';
    int cnt1=0; int cnt2=0; int cnt3=0;

    while(1){
        scanf("%c",&new);
        if(new == '!'){break;}

        if( (new >= 'A' && new <= 'Z') || (new >= 'a' && new <= 'z') ){

            if(new >= 'a' && new <= 'z'){
                new = new - 32;
                cnt1 = 1;
            }
            if(max >= 'a' && max <= 'z'){
                max = max - 32;
                cnt2 = 1;
            }
            if(min >= 'a' && min <= 'z'){
                min = min - 32;
                cnt3 = 1;
            }

            if(max <= new){
                if(cnt1 == 1){
                    new = new + 32;
                }
                max = new;
                if(cnt1 == 1){
                    new = new - 32;
                }
            }
            else{
                if(cnt2 == 1){
                    max = max + 32;
                }
            }

            if(min >= new){
                if(cnt1 == 1){
                    new = new + 32;
                }
                min = new;
            }
            else{
                if(cnt3 == 1){
                    min = min + 32;
                }
            }
            
            cnt1=0;
            cnt2=0;
            cnt3=0;
        }
        
    }
    printf("%c\n%c",min,max);
    return 0;
}