#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


#define MAX_SIZE 100


struct Stack {
    int items[MAX_SIZE];
    int top;
};


void initializeStack(struct Stack* stack) {
    stack->top = -1;
}


int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}


void push(struct Stack* stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}


int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}


int evaluatePostfix(char* postfix) {
    struct Stack stack;
    initializeStack(&stack);
    int i = 0;

    while (postfix[i] != '\0') {
        char currentChar = postfix[i];


        if (isdigit(currentChar)) {
            push(&stack, currentChar - '0'); 
        }
       
        else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            int result;
            switch (currentChar) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
            }

            push(&stack, result);
        }

        i++;
    }

    return pop(&stack);  
}


int main() {
    char postfix[MAX_SIZE];

   
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    
    int result = evaluatePostfix(postfix);

  
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}
