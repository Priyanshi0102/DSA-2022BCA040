#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100  // Maximum size of the stack


struct Stack {
    char arr[MAX_SIZE];
    int top;
};


void initializeStack(struct Stack* stack) {
    stack->top = -1;
}


int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}


int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}


int precedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    } else if (operator == '^') {
        return 3;
    }
    return 0;
}


void infixToPostfix(char* infix, char* postfix) {
    struct Stack stack;
    initializeStack(&stack);
    int i, j = 0;

    for (i = 0; i < strlen(infix); i++) {
        char currentChar = infix[i];

       
        if (isalnum(currentChar)) {
            postfix[j++] = currentChar;
        }
       
        else if (currentChar == '(') {
            stack.arr[++stack.top] = currentChar;
        }
        
        else if (currentChar == ')') {
            while (!isEmpty(&stack) && stack.arr[stack.top] != '(') {
                postfix[j++] = stack.arr[stack.top--];
            }
            stack.top--;  
        }
        
        else {
            while (!isEmpty(&stack) && precedence(stack.arr[stack.top]) >= precedence(currentChar)) {
                postfix[j++] = stack.arr[stack.top--];
            }
            stack.arr[++stack.top] = currentChar;  
        }
    }

   
    while (!isEmpty(&stack)) {
        postfix[j++] = stack.arr[stack.top--];
    }

    postfix[j] = '\0';  
}


int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    
    printf("Enter an infix expression: ");
    scanf("%s", infix);

   
    infixToPostfix(infix, postfix);

    
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
