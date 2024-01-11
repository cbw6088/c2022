#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 2147483647
#pragma warning(disable : 4996)

struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode* head;
};

struct Graph {
    int numVert;
    struct AdjList* arr;
};

struct minHeapNode {
    int v;
    int dist;
};

struct MinHeap {
    int size;
    int capacity;
    int* pos;
    struct minHeapNode** arr;
};

struct AdjListNode* newAdjListNode(int dest, int weight);
struct Graph* createGraph(int numVert);
void addEdge(struct Graph* graph, int src, int dest, int weight);
struct minHeapNode* newminHeapNode(int v, int dist);
struct MinHeap* createMinHeap(int capacity);
void swapminHeapNode(struct minHeapNode** a, struct minHeapNode** b);
void minHeapify(struct MinHeap* minHeap, int idx);
int isEmpty(struct MinHeap* minHeap);
struct minHeapNode* extractMin(struct MinHeap* minHeap);
void decreaseKey(struct MinHeap* minHeap, int v, int dist);
int isInMinHeap(struct MinHeap* minHeap, int v);
void dijkstra(struct Graph* graph, int src, int target);

int main() {
    int numVert = 6;
    struct Graph* graph = createGraph(numVert);

    addEdge(graph, 0, 1, 8);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 0, 3, 4);
    addEdge(graph, 1, 2, 7); 
    addEdge(graph, 1, 4, 4);
    addEdge(graph, 2, 3, 5);
    addEdge(graph, 2, 4, 3);
    addEdge(graph, 2, 5, 9);
    addEdge(graph, 3, 5, 4);

    dijkstra(graph, 2, 0);
    dijkstra(graph, 2, 5);
    dijkstra(graph, 5, 2);
    dijkstra(graph, 1, 3);

    return 0;
}

/*인접 리스트 노드 초기화*/
struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

/*그래프 생성 및 초기화*/
struct Graph* createGraph(int numVert) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVert = numVert;
    graph->arr = (struct AdjList*)malloc(numVert * sizeof(struct AdjList));

    for (int i = 0; i < numVert; ++i) graph->arr[i].head = NULL;

    return graph;
}

/*간선 추가*/
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->arr[src].head;
    graph->arr[src].head = newNode;

    newNode = newAdjListNode(src, weight);
    newNode->next = graph->arr[dest].head;
    graph->arr[dest].head = newNode;
}

/*힙 노드 초기화*/
struct minHeapNode* newminHeapNode(int v, int dist) {
    struct minHeapNode* minHeapNode = (struct minHeapNode*)malloc(sizeof(struct minHeapNode));
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}

/*최소 힙 초기화*/
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->pos = (int*)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->arr = (struct minHeapNode**)malloc(capacity * sizeof(struct minHeapNode*));
    return minHeap;
}

/*힙 노드 교환*/
void swapminHeapNode(struct minHeapNode** a, struct minHeapNode** b) {
    struct minHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    /*왼쪽 또는 오른쪽 자식이 현재 노드보다 작으면 가장 작은 것으로*/
    if (left < minHeap->size && minHeap->arr[left]->dist < minHeap->arr[smallest]->dist) smallest = left;
    if (right < minHeap->size && minHeap->arr[right]->dist < minHeap->arr[smallest]->dist) smallest = right;
    
    /*가장 작은 노드가 현재 노드가 아니면 교환 후 재귀적으로 minHeapify 호출*/
    if (smallest != idx) {
        struct minHeapNode* smallestNode = minHeap->arr[smallest];
        struct minHeapNode* idxNode = minHeap->arr[idx];

        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        swapminHeapNode(&minHeap->arr[smallest], &minHeap->arr[idx]);
        minHeapify(minHeap, smallest);
    }
}

/*힙이 비어 있는지 확인*/
int isEmpty(struct MinHeap* minHeap) {
    return minHeap->size == 0;
}

/*힙에서 최소 노드 추출*/
struct minHeapNode* extractMin(struct MinHeap* minHeap) {
    if (isEmpty(minHeap)) return NULL;

    /*최소 노드 추출 및 마지막 노드를 루트로 이동*/
    struct minHeapNode* root = minHeap->arr[0];
    struct minHeapNode* lastNode = minHeap->arr[minHeap->size - 1];
    minHeap->arr[0] = lastNode;

    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;
    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

/*힙 내의 노드 거리 감소*/
void decreaseKey(struct MinHeap* minHeap, int v, int dist) {
    int i = minHeap->pos[v];
    minHeap->arr[i]->dist = dist;

    /*힙 속성 유지를 위해 부모 노드와 스왑*/
    while (i && minHeap->arr[i]->dist < minHeap->arr[(i - 1) / 2]->dist) {
        minHeap->pos[minHeap->arr[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->arr[(i - 1) / 2]->v] = i;
        swapminHeapNode(&minHeap->arr[i], &minHeap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

/*주어진 노드가 최소 힙에 있는지 확인*/
int isInMinHeap(struct MinHeap* minHeap, int v) {
    if (minHeap->pos[v] < minHeap->size) {
        return 1;
    }
    return 0;
}

/*다익스트라 알고리즘 구현 함수*/
void dijkstra(struct Graph* graph, int src, int target) {
    int V = graph->numVert;
    int* dist = (int*)malloc(V * sizeof(int));
    int* pathCount = (int*)malloc(V * sizeof(int));
    if (dist == NULL || pathCount == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(dist);
        free(pathCount);
        return;
    }

    /*최소 힙 생성*/
    struct MinHeap* minHeap = createMinHeap(V);
    for (int v = 0; v < V; ++v) {
        dist[v] = MAX;
        pathCount[v] = 0; 
        minHeap->arr[v] = newminHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }

    /*시작 정점의 거리를 0으로 설정*/
    dist[src] = 0;
    pathCount[src] = 1;
    decreaseKey(minHeap, src, dist[src]);
    minHeap->size = V;

    /*최소 힙이 존재하면 반복*/
    while (!isEmpty(minHeap)) {
        struct minHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;

        /*현재 노드의 인접 리스트 탐색*/
        struct AdjListNode* pCrawl = graph->arr[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->dest;
            /*최소 힙에 있는 노드이고, 최단 거리가 갱신될 경우*/
            if (isInMinHeap(minHeap, v) && dist[u] != MAX) {
                if (dist[v] > dist[u] + pCrawl->weight) {
                    dist[v] = dist[u] + pCrawl->weight;
                    pathCount[v] = pathCount[u];
                    decreaseKey(minHeap, v, dist[v]);
                }
                else if (dist[v] == dist[u] + pCrawl->weight) 
                    pathCount[v] += pathCount[u];
            }
            pCrawl = pCrawl->next;
        }
    }
    printf("%c, %c : 최단거리 = %d, 최단경로 수 = %d\n", src + 'A', target + 'A', dist[target], pathCount[target]);

    free(dist);
    free(pathCount);
}
