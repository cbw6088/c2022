#include <stdio.h>
#include <string.h>

int main(){
    char ch[101] = {};
    scanf("%s", ch);
    int len = strlen(ch);
    for(int i = 0; i < len; i++){
        printf("%s\n", &ch[i]);
        ch[strlen(ch)] = ch[i];
    }
    return 0;
}