#include <stdio.h>
#include <stdlib.h>

#define INF 1000000  // A large value representing infinity

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to print the path from source to vertex v
void printPath(int parent[], int v) {
    if (v < 0)
        return;

    if (parent[v] == -1) {
        printf("%d", v);
        return;
    }

    printPath(parent, parent[v]);
    printf(" -> %d", v);
}

// Bellman-Ford algorithm with path tracking
void bellmanFord(struct Edge edges[], int V, int E, int src) {
    int dist[V];
    int parent[V];

    // Step 1: Initialize distances and parent array
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;

    // Step 2: Relax edges |V| - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            printf("Graph contains a negative-weight cycle\n");
            return;
        }
    }

    // Print distances and paths
    printf("Vertex\tDistance from Source %d\tPath\n", src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d\t\tINF\t\t\tNo path\n", i);
        else {
            printf("%d\t\t%d\t\t\t", i, dist[i]);
            printPath(parent, i);
            printf("\n");
        }
    }
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];

    // Input edges
    printf("Enter each edge as: source destination weight\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    bellmanFord(edges, V, E, src);

    return 0;
}


