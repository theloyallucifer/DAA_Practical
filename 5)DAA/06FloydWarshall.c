//04/03/25
#include <stdio.h>
#include <limits.h>

#define INF 999999
#define MAX_V 100

void floydWarshall(int graph[MAX_V][MAX_V], int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][k] != INF && graph[k][j] != INF &&
                    graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

int main() {
    int V;
    
    printf("Enter the number of vertices (max %d): ", MAX_V);
    scanf("%d", &V);

    if (V <= 0 || V > MAX_V) {
        printf("Invalid number of vertices!\n");
        return 1;
    }

    int graph[MAX_V][MAX_V];

    printf("Enter the adjacency matrix (use %d for infinity):\n", INF);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (i == j) graph[i][j] = 0;  
        }
    }
    
    floydWarshall(graph, V);
    
    printf("\nShortest distance matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
