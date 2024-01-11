#include <stdio.h>
#include <string.h>

int main(){
    char str1[42]={0},str2[21]={0};
    int N,cnt=0,idx=0;
    char tmp;

    scanf("%s",str1);
    scanf("%s",str2);
    scanf("%d",&N);

    char *p1 = str1 + N;
    char *p2=str2;

    for(; *p2!=0; p2++){
        tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
        p1++;
    }
	p2 = str2;
	for(; *p2!=0; p2++){
		tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
	}
	p2 = str2;
	for(; *p2!=0; p2++){
		*p1 = *p2;
		p1++;
	}
	p1 = str1;

    printf("%s",p1);

    return 0;
}