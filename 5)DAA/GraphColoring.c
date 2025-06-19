#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int V; // Number of vertices
int graph[MAX][MAX]; // Adjacency matrix
int color[MAX]; // Stores color assignments

// Function to check if it's safe to color a vertex with a given color
bool isSafe(int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve graph coloring problem
bool graphColoringUtil(int m, int v) {
    // Base case: All vertices are colored
    if (v == V) {
        return true;
    }

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;

            // Recur to assign colors to rest of the vertices
            if (graphColoringUtil(m, v + 1)) {
                return true;
            }

            // Backtrack: Remove color assignment if no solution
            color[v] = 0;
        }
    }

    return false;
}

// Main function to solve graph coloring problem
void graphColoring(int m) {
    // Initialize all color assignments as 0 (uncolored)
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    if (!graphColoringUtil(m, 0)) {
        printf("Solution does not exist with %d colors.\n", m);
    } else {
        printf("Graph can be colored with %d colors as follows:\n", m);
        for (int i = 0; i < V; i++) {
            printf("Vertex %d: Color %d\n", i, color[i]);
        }
    }
}

int main() {
    int m; // Number of colors
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter number of colors: ");
    scanf("%d", &m);

    graphColoring(m);

    return 0;
}


// output
// Enter number of vertices: 4
// Enter adjacency matrix:
// 0 1 1 1
// 1 0 1 0
// 1 1 0 1
// 1 0 1 0
// Enter number of colors: 3
// Graph can be colored with 3 colors as follows:
// Vertex 0: Color 1
// Vertex 1: Color 2
// Vertex 2: Color 3
// Vertex 3: Color 2                               
