#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define INF 1987654321

int dist[101];
int graph[101][101];
int n, m, s; 

void bellman_ford(int s);

int main() {
    int u, v, c; 
    scanf("%d %d %d", &n, &m, &s);

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            graph[i][j] = INF; 
        }
        dist[i] = INF; 
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &c);
        graph[u][v] = c; 
    }

    bellman_ford(s);
    for (int i = 1; i <= n; i++) {
        if (i != s && dist[i] != INF) 
            printf("%d %d\n", i, dist[i]);
    }

    return 0; 
}

void bellman_ford(int s) {
    dist[s] = 0; 
    for (int l = 1; l <= n - 1; l++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][j] != INF) {
                    int cur = i; 
                    int next = j; 
                    int cost = graph[i][j];

                    if (dist[cur] != INF && dist[next] > dist[cur] + cost) {
                        dist[next] = dist[cur] + cost; 
                    }
                }
            }
        }
    }
}
