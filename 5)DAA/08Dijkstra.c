//18/03/25

#include <stdio.h>
#define INF 999999
#define MAX_VERTICES 10

int minDistance(int distance[], int visited[], int vertices) {
    int min = INF, min_index = -1;
    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && distance[v] <= min) {
            min = distance[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int source, int vertices) {
    int distance[MAX_VERTICES], visited[MAX_VERTICES], previous[MAX_VERTICES];
    
    for (int v = 0; v < vertices; v++) {
        distance[v] = INF;
        previous[v] = -1;
        visited[v] = 0;
    }
    distance[source] = 0;
    
    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(distance, visited, vertices);
        if (u == -1) break;
        visited[u] = 1;
        
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] && distance[u] != INF && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
                previous[v] = u;
            }
        }
    }
    
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d\t%d\n", i, distance[i]);
    }
}

int main() {
    int vertices, source;
    int graph[MAX_VERTICES][MAX_VERTICES];
    
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    if (vertices > MAX_VERTICES) {
        printf("The maximum number of vertices allowed is %d.\n", MAX_VERTICES);
        return 1;
    }
    
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("Edge from vertex %d to vertex %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    
    dijkstra(graph, source, vertices);
    return 0;
}
