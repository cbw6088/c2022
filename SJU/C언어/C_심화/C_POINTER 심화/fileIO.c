#include <stdio.h>

int main(){
    FILE *fp;
    char str[100];
    fp = fopen("input.txt","r");
    while(!feof(fp)){
        fgets(str,100,fp);
        printf("%s",str);
    }
    fclose(fp);

    return 0;
}