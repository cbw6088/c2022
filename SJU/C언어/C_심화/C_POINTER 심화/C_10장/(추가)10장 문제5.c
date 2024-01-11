#include <stdio.h>
#include <string.h>

int vowel(char str);

int main(){
    char str1[101] = {}, str2[101] = {};
    int check = 0, idx1 = 0, idx2 = 0;
    int max;
    gets(str1);
    gets(str2);
    
    max = strlen(str1) + strlen(str2);

    for(int i=0; i<max; i++){

        if(check == 0){
            printf("%c",str1[idx1]);

            if(vowel(str1[idx1]) || str1[idx1+1] == 0)
                check = 1;
            
            idx1++;

        }

        else if(check == 1){
            printf("%c",str2[idx2]);
            
            if(vowel(str2[idx2]) || str2[idx2+1] == 0)
                check = 0;

            idx2++;
        }

    }
    return 0;
}

int vowel(char str){
    if(str == 'a' || str == 'e' || str == 'i' || str == 'o' || str == 'u')
        return 1;
    else if(str == 'A' || str == 'E' || str == 'I' || str == 'O' || str == 'U')
        return 1;
    else  
        return 0;
}