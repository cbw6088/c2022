#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str1[101] = {}, str2[101] = {}, str3[50][101] = {}, str4[50][101] = {};
    int len = 0, cnt = 0, idx = 0, xidx = 0, yidx = 0;
    gets(str1);
    gets(str2);
    len = strlen(str1);
    for(int i = 0; i < len; i++){
        if(str1[i] != ' ')
            str3[xidx][yidx++] = str1[i];
        else{
            xidx++;
            yidx = 0;
        }
    }
    xidx++;
    cnt = xidx;
    xidx = 0;
    yidx = 0;
    len = strlen(str2);
    for(int i = 0; i < len; i++){
        if(str2[i] != ' ')
            str4[xidx][yidx++] = str2[i];
        else{
            xidx++;
            yidx = 0;
        }
    }

    for(int i = 0; i < cnt - 1; i++){
        for(int j = i + 1; j < cnt; j++){
            if(strncmp(str3[i], str3[j], strlen(str3[i])) == 0)
                strcpy(str3[j], "!");
        }
    }
    int tmp = 0;
    for(int i = 0; i < cnt; i++){
        if(strcmp(str3[i], "!") == 0){
            strcpy(str3[i], str4[tmp++]);
        }
    }

    for(int i = 0; i < cnt; i++)
        printf("%s ", str3[i]);

    return 0;
}

/*
red orange red yellow green red blue purple yellow
white black gray pink brown blush crimson garnet vermilion indigo
*/
