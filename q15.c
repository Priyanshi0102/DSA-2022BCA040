#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


void enqueue(struct Node** front, struct Node** rear, int value) {
    struct Node* newNode = createNode(value);
    if (newNode == NULL) return;

    if (*rear == NULL) {
        *front = *rear = newNode;  
        printf("Element %d enqueued to the queue.\n", value);
        return;
    }

    (*rear)->next = newNode;  
    *rear = newNode;  
    printf("Element %d enqueued to the queue.\n", value);
}


void dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue underflow! The queue is empty.\n");
        return;
    }

    struct Node* temp = *front;
    *front = (*front)->next;  
    if (*front == NULL) {
        *rear = NULL;  
    }
    printf("Element %d dequeued from the queue.\n", temp->data);
    free(temp);  
}


void peek(struct Node* front) {
    if (front == NULL) {
        printf("The queue is empty.\n");
        return;
    }
    printf("Front element is: %d\n", front->data);
}


int isEmpty(struct Node* front) {
    return front == NULL;
}


void display(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, value;

    do {
        
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue (Add element to the queue)\n");
        printf("2. Dequeue (Remove element from the queue)\n");
        printf("3. Peek at the front element\n");
        printf("4. Check if the queue is empty\n");
        printf("5. Display the queue elements\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&front, &rear, value);
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
                peek(front);
                break;
            case 4:
                if (isEmpty(front)) {
                    printf("The queue is empty.\n");
                } else {
                    printf("The queue is not empty.\n");
                }
                break;
            case 5:
                display(front);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
