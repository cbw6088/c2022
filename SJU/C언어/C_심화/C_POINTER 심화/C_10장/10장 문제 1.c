#include <stdio.h>
#include <string.h>

int main(void) {
	char tmp[21]={0};
    char arr[21]={0};
    int idx = 0;
	scanf("%s",tmp);

	for(int i=0; i<20; i++){
		if(tmp[i] >= 'a' && tmp[i] <= 'z')
         arr[idx++] = tmp[i]; 
      else if(tmp[i] == 0)
         break;
	}
   printf("%s",arr);
	return 0;
}