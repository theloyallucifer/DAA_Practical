#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Queue implementation for BFS
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

int dequeue() {
    int vertex;
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        exit(1);
    }
    vertex = queue[front];
    front++;
    return vertex;
}

int isEmpty() {
    return front == -1 || front > rear;
}

// BFS function
void BFS(int adjMatrix[MAX][MAX], int vertices, int startVertex, int visited[]) {
    enqueue(startVertex);
    visited[startVertex] = 1;

    while (!isEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int vertices, edges, v1, v2, startVertex;
    int adjMatrix[MAX][MAX] = {0};
    int visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (vertex1 vertex2):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &v1, &v2);
        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1; // For undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &startVertex);

    printf("BFS Traversal: ");
    BFS(adjMatrix, vertices, startVertex, visited);

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
// BFS Traversal: 0 1 2 3 4  