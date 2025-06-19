#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];  // Adjacency matrix
int colors[MAX];      // Colors assigned to vertices
int V, m;             // V = number of vertices, m = number of colors

// Function to print solution
void printSolution() {
    printf("Color assignments to vertices:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d -> Color %d\n", i, colors[i]);
    }
    printf("\n");
}

// Check if the color assignment is valid
bool isSafe(int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && colors[i] == c)
            return false;
    }
    return true;
}

// Recursive function to solve m-coloring problem
bool graphColoring(int v) {
    if (v == V) {
        printSolution();
        return true; // Return true to show at least one solution
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            colors[v] = c;

            // Recur to assign colors to remaining vertices
            if (graphColoring(v + 1))
                return true; // Comment this line to print all solutions

            // Backtrack
            colors[v] = 0;
        }
    }

    return false;
}

int main() {
    int E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Initialize graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;  // Undirected graph
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    for (int i = 0; i < V; i++)
        colors[i] = 0;

    if (!graphColoring(0))
        printf("No solution exists with %d colors.\n", m);

    return 0;
}

