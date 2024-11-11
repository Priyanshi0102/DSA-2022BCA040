#include <stdio.h>

#define MAX_SIZE 5  // Define maximum size of the queue


struct Queue {
    int items[MAX_SIZE];
    int front, rear;
};


void initializeQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}


int isFull(struct Queue* q) {
    return q->rear == MAX_SIZE - 1;
}


int isEmpty(struct Queue* q) {
    return q->front == -1;
}


void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot insert element.\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}


void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No element to remove.\n");
    } else {
        printf("Removed %d from the queue.\n", q->items[q->front]);
        if (q->front == q->rear) {
            q->front = q->rear = -1; 
        } else {
            q->front++;
        }
    }

void traverseQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No elements to display.\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}


void peep(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No element to peek.\n");
    } else {
        printf("Element at the front: %d\n", q->items[q->front]);
    }
}

int main() {
    struct Queue q;
    int choice, value;

    
    initializeQueue(&q);

    do {
        printf("\nQueue Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Peep\n");
        printf("5. Check if Full\n");
        printf("6. Check if Empty\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                traverseQueue(&q);
                break;
            case 4:
                peep(&q);
                break;
            case 5:
                if (isFull(&q)) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 6:
                if (isEmpty(&q)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 7:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
