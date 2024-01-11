#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 1987654321

typedef struct entry {
    int v;
    int cost;
    struct entry *next;
} entry;

entry *pq;
int visited[101];
int dist[101];
int matrix[101][101];
int n, m, s;

void dijkstra(int s);
void enQueue(entry *e);
entry* popQueue();
int isEmpty();
void printQueue();

int main() {
    int u, v, c;
    scanf("%d %d %d", &n, &m, &s);
    pq = (entry *) malloc(sizeof(entry));
    pq->next = NULL;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) 
            matrix[i][j] = 0;
        visited[i] = 0;
        dist[i] = INF;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &c);
        matrix[u][v] = c;
        matrix[v][u] = c;
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        if (i != s && dist[i] != INF)
            printf("%d %d\n", i, dist[i]);
    }
    free(pq);
    return 0;
}

void dijkstra(int s) {
    entry e;
    e.v = s;
    e.cost = 0;
    e.next = NULL; 
    enQueue(&e); 
    visited[s] = 1;
    while(!isEmpty()) {
        entry *cur = popQueue();
        for(int i=1;i<=n;i++) {
            if(matrix[cur->v][i] != 0 && visited[i] == 0) {
                int nCost = cur->cost + matrix[cur->v][i];
                if(nCost < dist[i]) {
                    entry e2;
                    e2.v = i; 
                    e2.cost = nCost;
                    e2.next = NULL;
                    dist[i] = nCost;
                    enQueue(&e2);
                }
            }
        }
        free(cur);
    }
}

void enQueue(entry *e) {
    entry *prev = pq;
    entry *p = prev->next;
    entry *copy = (entry *) malloc(sizeof(entry)); *copy = *e;
    while(p != NULL && p->cost < e->cost) {
        prev = p;
        p = p->next; 
    }
    prev->next = copy;
    copy->next = p; 
}

entry* popQueue() {
    entry *prev = pq;
    entry *ret = prev->next;

    if(ret == NULL) return NULL;

    prev->next = ret->next; 
    return ret;
}

int isEmpty() { 
    if(pq->next == NULL) return 1;
    else return 0;
}

void printQueue() {
    entry *p = pq->next;
    while(p != NULL) {
        printf("%d : %d\n", p->v, p->cost);
        p = p->next;
    }   
}
