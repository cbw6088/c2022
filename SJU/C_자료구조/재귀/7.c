#include <stdio.h>
#include <string.h>

int string_count(char *ar, char ch, int len);

int main(){
    char ar[100] = {};
    char ch;
    scanf("%s", ar);
    getchar();
    scanf("%c", &ch);
    int len = strlen(ar);
    printf("%d\n", string_count(ar, ch, len));
    return 0;
}

int string_count(char *ar, char ch, int len){
    if (len == 0){
        if(*ar == ch)
            return 1;
        else
            return 0;
    }
    if(*ar == ch)
        return (1 + string_count(++ar, ch, len - 1));
    else
        return (string_count(++ar, ch, len - 1));
}