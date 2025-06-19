#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Structure for adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Graph represented as an array of adjacency lists
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX];
    bool visited[MAX];
};

// Queue structure for BFS
struct Queue {
    int items[MAX];
    int front, rear;
};

// Function to create a node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }

    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since undirected, add reverse edge
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Queue functions
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isEmpty(struct Queue* q) {
    return q->rear == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1)
        return;

    if (q->front == -1)
        q->front = 0;

    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q))
        return -1;

    int item = q->items[q->front];
    q->front++;

    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }

    return item;
}

// BFS Algorithm
void bfs(struct Graph* graph, int startVertex) {
    struct Queue* q = createQueue();

    graph->visited[startVertex] = true;
    enqueue(q, startVertex);

    printf("BFS traversal starting from vertex %d:\n", startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = true;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    struct Graph* graph = createGraph(V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < E; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter starting vertex for BFS: ");
    scanf("%d", &startVertex);

    bfs(graph, startVertex);

    return 0;
}

