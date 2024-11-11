#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


void insertAtFront(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
    printf("Node inserted at the front: %d\n", value);
}


void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted at the end: %d\n", value);
}


void insertInOrder(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL && temp->next->data < value) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Node inserted in ascending order: %d\n", value);
}


void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, no node to delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("First node deleted.\n");
}


void deleteBeforePosition(struct Node** head, int pos) {
    if (*head == NULL || pos <= 1) {
        printf("Invalid position or empty list.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    
    
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("No node before position %d to delete.\n", pos);
        return;
    }
    
   
    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
    printf("Node before position %d deleted.\n", pos);
}


void deleteAfterPosition(struct Node** head, int pos) {
    if (*head == NULL || pos < 1) {
        printf("Invalid position or empty list.\n");
        return;
    }
    struct Node* temp = *head;
    
    
    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("No node after position %d to delete.\n", pos);
        return;
    }
    
    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
    printf("Node after position %d deleted.\n", pos);
}


void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node* head = NULL;
    int choice, value, position;

    do {
        
        printf("\nMenu:\n");
        printf("1. Insert a node at the front\n");
        printf("2. Insert a node at the end\n");
        printf("3. Insert a node in ascending order\n");
        printf("4. Delete the first node\n");
        printf("5. Delete the node before a specified position\n");
        printf("6. Delete the node after a specified position\n");
        printf("7. Traverse the linked list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the front: ");
                scanf("%d", &value);
                insertAtFront(&head, value);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter the value to insert in ascending order: ");
                scanf("%d", &value);
                insertInOrder(&head, value);
                break;
            case 4:
                deleteFirstNode(&head);
                break;
            case 5:
                printf("Enter the position before which to delete the node: ");
                scanf("%d", &position);
                deleteBeforePosition(&head, position);
                break;
            case 6:
                printf("Enter the position after which to delete the node: ");
                scanf("%d", &position);
                deleteAfterPosition(&head, position);
                break;
            case 7:
                traverseList(head);
                break;
            case 8:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
