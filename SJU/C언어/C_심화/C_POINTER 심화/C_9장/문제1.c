#include <stdio.h>

int main(){
	int x,y,z;
	int *px=&x, *py=&y, *pz=&z, *tmp;
	scanf("%d %d %d",px, py, pz);
		tmp = px;
		px = pz;
		pz = py;
		py = tmp;
	
	printf("%d %d %d",*px,*py,*pz);
	return 0;
}