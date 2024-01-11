#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
	char name[22], r_name[22];
}student;

struct student *change(struct student st[]);

int main(){
	int N, max = 0, tmp;
	student ar[10] = {}, *longest;
	scanf("%d", &N);
	getchar();
	for(int i=0; i<N; i++)
		gets(ar[i].name);

	longest = change(ar);
	for(int i=0; i<N; i++){
		if(max <= strlen((longest+i)->r_name)){
			max = strlen((longest+i)->r_name);
			tmp = i;
		}
	}
	for(int i=0; i<N; i++)
		printf("%s\n", (longest+i)->r_name);
	printf("longest=%s", (longest+tmp)->r_name);
	
	return 0;
}

struct student *change(struct student st[]){
	student *p = st;
	int cnt = 0, cnt2 = 0, check = 0, idx = 0, idx2 = 0, idx3 = 0, tmp;
	int ar[10] = {};
	while(p->name[0] != 0){
		cnt++;
		p++;
	}
	p = st;
	for(int i=0; i<cnt; i++){
		cnt2 = strlen((p+i)->name);
		for(int j=0; j<cnt2; j++){
			if(check == 0){
				if((p+i)->name[j] == ' ')
					check = 1;
			}
			else if(check == 1){
				(p+i)->r_name[idx++] = (p+i)->name[j];
				(p+i)->name[j] = '!';
				idx3++;
				ar[idx2] = idx3;
			}
		}
		(p+i)->r_name[idx++] = ' ';
		idx3++;
		ar[idx2] = idx3;

		idx = 0;
		check = 0;
		idx2++;
		idx3 = 0;
	}

	p = st;
	for(int i=0; i<cnt; i++){
		tmp = ar[i];
		cnt2 = strlen(p->name);
		for(int j=0; j<cnt2; j++){
			if(p->name[j] == '!' || p->name[j] == ' ') break;
			p->r_name[tmp++] = p->name[j];
		}
		p++;
	}
	p = st;
	return p;
}

/*
3
hong gildong
kim hana
kim johnson
*/