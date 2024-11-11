#include <stdio.h>

#define MAX_SIZE 5  // Define maximum size of the circular queue


struct CircularQueue {
    int items[MAX_SIZE];
    int front, rear;
};


void initializeQueue(struct CircularQueue* cq) {
    cq->front = -1;
    cq->rear = -1;
}


int isQueueFull(struct CircularQueue* cq) {
    return (cq->front == 0 && cq->rear == MAX_SIZE - 1) || (cq->rear == (cq->front - 1) % (MAX_SIZE - 1));
}


int isQueueEmpty(struct CircularQueue* cq) {
    return cq->front == -1;
}


void enqueue(struct CircularQueue* cq, int value) {
    if (isQueueFull(cq)) {
        printf("Queue is full! Cannot add element.\n");
    } else {
        if (cq->front == -1) {
            cq->front = 0;  
        }
        cq->rear = (cq->rear + 1) % MAX_SIZE;  
        cq->items[cq->rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}


void dequeue(struct CircularQueue* cq) {
    if (isQueueEmpty(cq)) {
        printf("Queue is empty! No element to remove.\n");
    } else {
        printf("Removed %d from the queue.\n", cq->items[cq->front]);
        if (cq->front == cq->rear) {
            cq->front = cq->rear = -1; 
        } else {
            cq->front = (cq->front + 1) % MAX_SIZE;  
        }
    }
}


void displayQueue(struct CircularQueue* cq) {
    if (isQueueEmpty(cq)) {
        printf("Queue is empty! Nothing to display.\n");
    } else {
        printf("Queue elements: ");
        int i = cq->front;
        while (i != cq->rear) {
            printf("%d ", cq->items[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d ", cq->items[cq->rear]);  
        printf("\n");
    }
}


void peep(struct CircularQueue* cq) {
    if (isQueueEmpty(cq)) {
        printf("Queue is empty! No element to peek.\n");
    } else {
        printf("Element at the front: %d\n", cq->items[cq->front]);
    }
}

int main() {
    struct CircularQueue cq;
    int choice, value;

    
    initializeQueue(&cq);

    do {
        printf("\nCircular Queue Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
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
                enqueue(&cq, value);
                break;
            case 2:
                dequeue(&cq);
                break;
            case 3:
                displayQueue(&cq);
                break;
            case 4:
                peep(&cq);
                break;
            case 5:
                if (isQueueFull(&cq)) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 6:
                if (isQueueEmpty(&cq)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
