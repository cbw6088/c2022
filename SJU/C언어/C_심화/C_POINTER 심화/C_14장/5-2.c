#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stu{
    char name[11];
    int score;
};

int main(){
    struct stu st[3];
    FILE *fp = fopen("student,dat", "rb");
    for(int i = 0; i < 3; i++){
        fread(&A[i], sizeof(struct stu), 1, fp);
        printf("%s %d\n", st[i].name, st[i].score);
    }
    fclose(fp);
    return 0;
}