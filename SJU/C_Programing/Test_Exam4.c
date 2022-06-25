#include <stdio.h>
int main(void)
{
    char ch='*'; char temp; char first = 'z'; char second; int cnt=0;
    while(ch != '!'){
        temp = ch;
        scanf("%c",&ch);

        if(ch >= 'A' && ch <'z'){
            if(first == ch+32){ // first가 소문자면 대문자로 바꾸기
                first = ch;
                //printf("%c\n",first);
            }
            else if(first == ch-32){ // first가 대문자면 대문자 그대로
                first = ch-32;
                //printf("%c\n",first);
            }
            else if(first > ch){ // first가 더 높은 아스키코드값일 경우
                second = first;
                first = ch;
                //printf("%c %c\n",first,second);
            }
            else if(second > ch){ // first보단 크지만 second보단 작을때
                second = ch;
            }
        } // 첫번째 if
        else{
            continue;
        }
        
        if( (temp >= 'A'  && temp <= 'z') && (ch < 'A' || ch > 'z') ){ // temp는 알파벳이고 ch는 그 외 일때
            printf("%c%c\n",first,second);
        }

    } //while
    
  return 0;
}
