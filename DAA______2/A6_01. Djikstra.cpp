#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

void djikstra(int graph[MAX_VERTICES][MAX_VERTICES], int source, int vertices) {
    int dist[MAX_VERTICES], visited[MAX_VERTICES], parent[MAX_VERTICES];

    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int min = INT_MAX, u = -1;

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && dist[v] < min) {
                min = dist[v];
                u = v;
            }
        }

        if (u == -1) break; // No more reachable vertices

        visited[u] = 1;

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < vertices; i++) {
        if (dist[i] == INT_MAX) {
            printf("No path from source %d to vertex %d\n", source, i);
            continue;
        }
        printf("Shortest distance from source %d to vertex %d is %d\n", source, i, dist[i]);
        printf("Path: %d\n", i);
        int p = parent[i];
        while (p != -1) {
            printf(" <- %d", p);
            p = parent[p];
        }
        printf("\n");
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Initialize with zeros
    int vertices, edges, u, v, weight, source;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    djikstra(graph, source, vertices);

    return 0;
}
    
