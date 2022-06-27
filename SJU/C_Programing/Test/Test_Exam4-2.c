#include <stdio.h>

int main(void){
    char new='*'; char max='A'; char min='Z'; char temp;
    int cnt1=0; int cnt2=0; int cnt3=0;

    while(1){
        temp = new;
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

            if(min >= new){
                if(min == new){
                    if(cnt3 == 1){
                        min = min + 32;
                        cnt3 = 0;
                    }
                    max = min;
                    min = new;
                }
                else if(min > new){
                    if(cnt1 == 1){
                        new = new + 32;
                        cnt1 = 0;
                    }
                    if(cnt3 == 1){
                        min = min + 32;
                        cnt3 = 0;
                    }
                    max = min;
                    min = new;
                }
            } // if (min >= new)    
            else if(max >= new){
                if(max == new){
                    if(cnt3 == 1){
                        min = min + 32;
                        cnt3 = 0;
                    }
                    max = new;    
                }
                else if(max > new){
                    if(cnt1 == 1){
                        new = new + 32;
                        cnt1 = 0;
                    }
                    if(cnt3 == 1){
                        min = min + 32;
                        cnt3 = 0;
                    }
                    max = new;
                }
            } // else if (max >= new)
            else{
                if(cnt2 == 1){
                    max = max + 32;
                }
                if(cnt3 == 1){
                    min = min + 32;
                }
            }         
            cnt1=0;
            cnt2=0;
            cnt3=0;
        } // 맨 처음 알파벳 범위 if문
        
        if( (temp >= 'A' && temp <= 'Z') || (temp >= 'a' && temp <= 'z') ) {
            if((new >= 'A' && new <= 'Z') || (new >= 'a' && new <= 'z')){
                continue;
            }
            else{
               printf("%c%c\n",min,max);
                min = 'Z';
                max = 'A'; 
            }
        } // 마지막 if문
    }
    return 0;
}