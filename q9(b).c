#include <stdio.h>

#define MAX_SIZE 5  // Maximum size of the stack


struct Stack {
    int data[MAX_SIZE];
    int top;
};


void initializeStack(struct Stack* s) {
    s->top = -1;
}


int isFull(struct Stack* s) {
    return s->top == MAX_SIZE - 1;
}


int isEmpty(struct Stack* s) {
    return s->top == -1;
}


void push(struct Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d onto the stack.\n", value);
    } else {
        s->top++;
        s->data[s->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}


void pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow! No element to pop.\n");
    } else {
        printf("Popped %d from the stack.\n", s->data[s->top]);
        s->top--;
    }
}


void peep(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! No element to peek.\n");
    } else {
        printf("Element at the top: %d\n", s->data[s->top]);
    }
}


void display(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! No elements to display.\n");
    } else {
        printf("Stack elements: ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->data[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack s;
    int choice, value;

  
    initializeStack(&s);

    do {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Display\n");
        printf("5. Check if Full\n");
        printf("6. Check if Empty\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                peep(&s);
                break;
            case 4:
                display(&s);
                break;
            case 5:
                if (isFull(&s)) {
                    printf("Stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
                break;
            case 6:
                if (isEmpty(&s)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
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
