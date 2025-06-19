#include <stdio.h>
#include <limits.h>

#define V 100 

void printSolution(int dist[][V], int n) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][V], int n) {
    int dist[V][V];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    printSolution(dist, n);
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    int graph[V][V];
    printf("Enter the adjacency matrix (use %d for INF):\n", INT_MAX);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    floydWarshall(graph, n);
    return 0;
}

