#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100


struct Node {
    int vertex;
    struct Node* next;
};


struct Node* adjList[MAX_NODES];


struct Queue {
    int items[MAX_NODES];
    int front, rear;
};


struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Add element to queue
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_NODES - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Remove element from queue
int dequeue(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue underflow\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// Check if queue is empty
int isQueueEmpty(struct Queue* q) {
    return q->front == -1;
}

// Create a new graph node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Add an edge between vertices in an undirected graph
void addEdge(int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

// Breadth-First Search function
void BFS(int startVertex, int numVertices) {
    int visited[MAX_NODES] = {0}; 
    struct Queue* q = createQueue();

    visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isQueueEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        struct Node* temp = adjList[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int numVertices = 6;


    for (int i = 0; i < numVertices; i++) {
        adjList[i] = NULL;
    }

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 4);
    addEdge(3, 5);
    addEdge(4, 5);

    printf("BFS traversal starting from vertex 0:\n");
    BFS(0, numVertices);

    return 0;
}
