#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct fighting{
	char name[11];
	int Attack, HP;
} fight;

int main(){
	int N, tmp1, tmp2;
	scanf("%d", &N);
	fight ar[10];
	fight swap;
	char name1[11], name2[11];
	for(int i = 0; i < N; i++)
		scanf("%s %d %d", ar[i].name, &ar[i].Attack, &ar[i].HP);

	for(int i = 0; i < 5; i++){
		scanf("%s %s", name1, name2);
		for(int j = 0; j < N; j++){
			if(strcmp(name1, ar[j].name) == 0){
				tmp1 = j;
				break;
			}
		}
		for(int k = 0; k < N; k++){
			if(strcmp(name2, ar[k].name) == 0){
				tmp2 = k;
				break;
			}
		}

		ar[tmp1].HP = ar[tmp1].HP - ar[tmp2].Attack;
		ar[tmp2].HP = ar[tmp2].HP - ar[tmp1].Attack;

		if(ar[tmp1].HP <= 0 || ar[tmp2].HP <= 0)
			break;
	}
	for(int i = 0; i < N - 1; i++){
		for(int j = 0; j < N - 1 - i; j++){
			if(ar[j].HP < ar[j+1].HP){
				swap = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = swap;
			}
		}
	}

	for(int i = 0; i < N; i++){
		if(ar[i].HP < 0)
			ar[i].HP = 0;
	}

	for(int i = 0; i < N; i++)
		printf("%s %d\n",ar[i].name, ar[i].HP);
	
	return 0;
}

/*
5
Harry 50 100
Ron 5 40
Hermione 10 50
Voldmort 40 80
Hagrid 30 70
Harry Voldmort
Ron Hagrid
Hagrid Voldmort
*/

/*
4
warrior 60 100
wizard 90 50
assassin 100 30
archer  70 70
warrior archer
assassin wizard
*/

/*
5
A 50 300
B 20 240
C 40 260
D 20 280
E 70 330
A B
B C
D E
C A
B D
*/