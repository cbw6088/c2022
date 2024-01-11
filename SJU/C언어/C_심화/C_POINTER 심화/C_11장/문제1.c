#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Vector{
    int V[3];
};

int main(){
    struct Vector V1, V2, V3;
    int add = 0;
    scanf("%d %d %d", &V1.V[0], &V1.V[1], &V1.V[2]);
    scanf("%d %d %d", &V2.V[0], &V2.V[1], &V2.V[2]);


    for(int i=0; i<3; i++)
        V3.V[i] = V1.V[i] * V2.V[i];

    for(int i=0; i<3; i++)
        add = add + V3.V[i];

    for(int i=0; i<3; i++)
        printf("%d ", V3.V[i]);
    printf("\n");
    printf("%d",add);
    
    return 0;
}