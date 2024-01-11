#include <stdio.h>
#include <string.h>

int main(){
    char str1[101] = {0}, tmp[10][101] = {0}, str2[10][101] = {0};
    int idx = 0, x_idx = 0, y_idx = 0, cnt = 0, max = 0;
    
    gets(str1);

    for(int i=0; i<strlen(str1); i++){

        if(str1[i] == ' '){
            y_idx = 0;
            x_idx++;
            cnt++;
            continue;
        }

        tmp[x_idx][y_idx++] = str1[i];
    }
    x_idx = 0;
    y_idx = 0;

    for(int i=0; i<cnt; i++){
        for(int j=i+1; j<cnt+1; j++){
            if(strlen(tmp[i]) < strlen(tmp[j])){
                char t_tmp[101] = {0};
                strcpy(t_tmp,tmp[i]);
                strcpy(tmp[i],tmp[j]);
                strcpy(tmp[j],t_tmp);
            }
            else if(strlen(tmp[i]) == strlen(tmp[j])){
                if(strcmp(tmp[i],tmp[j]) > 0){
                    char t_tmp[101] = {0};
                    strcpy(t_tmp,tmp[i]);
                    strcpy(tmp[i],tmp[j]);
                    strcpy(tmp[j],t_tmp);
                }
            }
        }
    }

    for(int i=0; i<cnt+1; i++){
        printf("%s",tmp[i]);
        printf("\n");
    }
    return 0;
}