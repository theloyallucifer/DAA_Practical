#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Global variables
int adjMatrix[MAX][MAX];
int visited[MAX];
int vertices;

// DFS function
void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    
    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, v1, v2, startVertex;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter edges (vertex1 vertex2):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &v1, &v2);
        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1; // For undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &startVertex);

    printf("DFS Traversal: ");
    DFS(startVertex);

    return 0;
}

//output
// Enter number of vertices: 5
// Enter number of edges: 6
// Enter edges (vertex1 vertex2):
// 0 1
// 0 2
// 1 3
// 1 4
// 2 3
// 3 4
// Enter starting vertex: 0             
// DFS Traversal: 0 1 3 4 2