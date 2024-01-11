#include <stdio.h>
#include <stdlib.h>

int mostOnes(int **p, int n);

int main(){
    int n;
    scanf("%d", &n);
    int **p = (int**)malloc(sizeof(int*) * n);
    if(p == NULL)
        return -1;
    for(int i = 0; i < n; i++){
        p[i] = (int*)malloc(sizeof(int) * n);
        if(p[i] == NULL)
            return -1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            scanf("%d", &p[i][j]);
    }
    printf("%d\n", mostOnes(p, n));
    return 0;
}

int mostOnes(int **p, int n){
    int row = 0, max = 0;
    for(int i = 0; i < n; i++){
        for(int j = max; j < n; j++){
            if (j == n - 1)
                return i;
            if(p[i][j] == 0){
                if(max < j){
                    max = j;
                    row = i;
                }
                break;
            }
        }
    }
    return row;
}

/*
8
1 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0
1 1 1 1 1 1 0 0
1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 1 0 0 0
*/