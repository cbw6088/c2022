#include <stdio.h>
#include <string.h>

int main(){
    char str1[101] = {0}, str2[10][101] = {0};
    int idx = 0, x_idx = 0, y_idx = 0, cnt = 0;
    
    gets(str1);

    for(int i=0; i<strlen(str1); i++){

        if(str1[i] == ' '){
            y_idx = 0;
            x_idx++;
            cnt++;
            continue;
        }

        str2[x_idx][y_idx++] = str1[i];
    }

    for(int i=0; i<cnt+1; i++){
        printf("%s",str2[i]);
        printf("\n");
    }
    return 0;
}