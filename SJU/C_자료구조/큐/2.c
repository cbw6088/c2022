#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
    struct node *prev;
}Dq;

void add_front(Dq*f,Dq*r,int value){
    Dq*node=(Dq*)malloc(sizeof(Dq));
    node->data=value;
    node->next=NULL; // 노드 세팅
    node->prev=NULL;

    if(f->next==NULL){ // 가장 처음 NULL인 경우 새로 만든 node와 연결
        f->next=node;
        node->prev=f;

        r->prev=node;
        node->next=r;
    }
    else{
        Dq*fp=f->next; // 임의의 저장공간 생성
        f->next=node;
        node->prev=f;

        fp->prev=node; // 임의의 저장공간과 연결
        node->next=fp;
    }
}

int delete_front(Dq*f,Dq*r){
    int temp=0;
    if(f->next==NULL || f->next==r){
        printf("underflow\n");
        return -1;
    }
    else{
        Dq*fp=f->next; //fp는 1번 노드
        f->next=fp->next;  //fp->next는 2번노드
        fp->next->prev=f;
        temp=fp->data;
        free(fp);
    }
    return temp;
}

void add_rear(Dq*f,Dq*r,int value){
    Dq*node=(Dq*)malloc(sizeof(Dq));
    node->data=value;
    node->next=NULL; // 노드 세팅
    node->prev=NULL;

    if(r->prev==NULL){ // 가장 처음 NULL인 경우 새로 만든 node와 연결
        r->prev=node;
        node->next=r;

        f->next=node;
        node->prev=f;
    }
    else{
        Dq*rp=r->prev; // 임의의 저장공간 생성
        r->prev=node;
        node->next=r;

        rp->next=node; // 임의의 저장공간과 연결
        node->prev=rp;
    }
}

int delete_rear(Dq*f,Dq*r){
    int temp=0;
    if(r->prev==NULL || r->prev==f){
        printf("underflow\n");
        return -1;
    }
    else{
        Dq*rp=r->prev; //fp는 1번 노드
        r->prev=rp->prev;  //fp->next는 2번노드

        rp->prev->next=r;
        temp=rp->data;
        free(rp);
    }
    return temp;
}

void print(Dq*f,Dq*r){
    Dq*fp=f->next;
    while(fp!=r){
        printf("%d ",fp->data);
        fp=fp->next;
    }
    printf("\n");
}

int main(void){
    Dq*front=(Dq*)malloc(sizeof(Dq));
    Dq*rear=(Dq*)malloc(sizeof(Dq));
    front->next=NULL;
    rear->prev=NULL;

    int n=0;
    scanf("%d",&n);
 

    for(int i=0; i<n; i++){
        char text[10]; 
        //char *text = (char*)malloc(sizeof(char)); 
        int e=0;
        scanf("%s",text);

        if(strcmp(text,"AF")==0){
            scanf("%d",&e);
            add_front(front,rear,e);
        }
        else if(strcmp(text,"DF")==0){
            if(delete_front(front,rear)==-1){
                return 0;
            }
        }
        else if(strcmp(text,"AR")==0){
            scanf("%d",&e);
            add_rear(front,rear,e);
        }
        else if(strcmp(text,"DR")==0){
            if(delete_rear(front,rear)==-1){
                return 0;
            }
        }
        else if(strcmp(text,"P")==0){
            print(front,rear);
        }
    }

    return 0;
}
