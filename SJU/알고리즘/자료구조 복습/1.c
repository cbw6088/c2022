#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode{
    char data;
    struct ListNode * next;
    struct ListNode * prv;
}List;

void init(List *H, List *T){
    H->next = T;
    T->prv = H;
}

int inputPosError(List*H, List*T, int pos){
    List * P = H->next;
    int cnt = 1; //1부터시작
    while(P!=T){
        P = P->next;
        cnt ++;
    }
    return (pos<0 || pos>cnt);
} // 삽인은 기존 포지션보다 1개 많아도 상관없음

int DeletePosError(List*H, List*T, int pos){
    List * P = H->next;
    int cnt = 0; // 0부터시작
    while(P!=T){
        P = P->next;
        cnt ++;
    }
    return (pos<0 || pos>cnt);
} //삭제는 기존 포지션보다 많으면 안됨

void add(List*H, List*T, int pos , char data){
    if(pos == 1){
        List *node = (List*)malloc(sizeof(List));
        node->data = data;
        node->prv = H;
        node->next = H->next;
        H->next->prv = node;
        H->next = node;
    }//가장 앞에 들어오는 경우
    else{
        if(inputPosError(H,T,pos)){
            printf("invalid position\n");
        }
        else{
            List *node = (List*)malloc(sizeof(List));
            List * P = H->next;
            for(int i=2; i<pos; i++){
                P = P->next;
            }
            node->data = data;
            node->prv = P;
            node->next = P->next;
            P->next->prv = node;
            P->next = node;
        }
    }
} //insrt 함수

void delete(List*H, List*T, int pos){
    List * P = H->next;
    if(DeletePosError(H,T,pos)){
        printf("invalid position\n");
    }
    else{
        for(int i=1; i<pos; i++)
            P = P->next;
        
        P->prv->next = P->next;
        P->next->prv = P->prv;
        free(P);
    }
} //delete함수

void get(List*H, List*T, int pos){
     List * P = H->next;
    if(DeletePosError(H,T,pos)){
        printf("invalid position\n");
    }
    else{
        for(int i=1; i<pos; i++)
            P = P->next;
        printf("%c\n", P->data);
    }
} //반환만 해줌

void print(List*H, List*T){
    List * P = H->next;
    while(P!=T){
        printf("%c", P->data);
        P= P->next;
    }
    printf("\n");
}

int main(){
    List *H = (List*)malloc(sizeof(List));
    List *T = (List*)malloc(sizeof(List));
    init(H,T);

    int testCase = 0;
    scanf("%d", &testCase);

    while(testCase--){
        char str[10];
        scanf("%s", str);

        if(strcmp(str,"A") == 0){
            int pos = 0;
            char data;
            scanf("%d %c", &pos,&data);
            add(H,T,pos,data);
        }
        else if(strcmp(str,"D") == 0){
            int pos = 0;
            scanf("%d", &pos);
            delete(H,T,pos);
        }
        
        else if(strcmp(str,"G") == 0){
            int pos = 0;
            scanf("%d", &pos);
            get(H,T,pos);
        }
        
        else if(strcmp(str,"P") == 0){
            print(H,T);
        }

    } // TestCase
    
    return 0;
}