#include <stdio.h>
#include <limits.h>

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to implement Bellman-Ford Algorithm
void bellmanFord(struct Edge edges[], int V, int E, int src) {
    int distance[V];

    // [INITIALIZATION] - Set all distances to infinity
    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
    }
    distance[src] = 0; // Distance to source is 0

    // [START OF RELAXATION] - Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }
    // [END OF RELAXATION]

    // [CHECK FOR NEGATIVE WEIGHT CYCLE]
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            printf("Graph contains a negative weight cycle!\n");
            return;
        }
    }

    // [PRINT RESULT]
    printf("Vertex\tDistance from Source %d\n", src);
    for (int i = 0; i < V; i++) {
        if (distance[i] == INT_MAX)
            printf("%d\t\tINF\n", i);
        else
            printf("%d\t\t%d\n", i, distance[i]);
    }
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];

    printf("Enter edges (source destination weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    bellmanFord(edges, V, E, src);

    return 0;
}

// output
// Enter number of vertices: 5
// Enter number of edges: 8
// Enter edges (source destination weight):
// 0 1 -1
// 0 2 4
// 1 2 3
// 1 3 2
// 1 4 2
// 3 2 5
// 3 1 1
// 4 3 -3
// Enter source vertex: 0
// Vertex  Distance from Source 0
// 0       0
// 1       -1
// 2       2
// 3       -2
// 4       1


