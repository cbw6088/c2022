#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
	char name[10];
	char id[11];
	char rank;
};

int main(){
	struct student st[5];
	for(int i = 0; i < 5; i++)
		scanf("%s %s %c", st[i].name, st[i].id, &st[i].rank);
	char find[10] = {};
	scanf("%s", find);
	for(int i = 0; i < 5; i++){
		if(strcmp(st[i].name, find) == 0)
			printf("%s %c", st[i].id, st[i].rank);
	}
	return 0;
}

/*
lee1 2017102656 A
lee2 2018111823 A
park 2018059961 A
choi 2018010101 F
lee3 2019565656 B
park
*/