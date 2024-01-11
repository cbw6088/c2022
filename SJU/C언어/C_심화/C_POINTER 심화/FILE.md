```c++
#include <stdio.h>

int main(){
	double height, weight;
	int age;
	FILE *fp1, *fp2;
	fp1 = fopen("input.dat", "r");
	fp2 = fopen("output.dat", "w");

	for(int i = 0; i < 3; i++){
		fscanf(fp1, "%lf %lf %d", &height, &weight, &age);
		fprintf(fp2, "%.2f %.2f %d\n", height, weight, age);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
```