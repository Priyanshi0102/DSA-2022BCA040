#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100  // Maximum size of the stack


    char elements[MAX_SIZE];
    int top;
};


void initializeStack(struct Stack* stack) {
    stack->top = -1;
}


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


void reverseString(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}


void infixToPrefix(char* infix, char* prefix) {
    struct Stack stack;
    initializeStack(&stack);
    int length = strlen(infix);
    int j = 0;

   
    reverseString(infix);

   
    for (int i = 0; i < length; i++) {
        char currentChar = infix[i];

        
        if (isalnum(currentChar)) {
            prefix[j++] = currentChar;
        }
        
        else if (currentChar == ')') {
            stack.elements[++stack.top] = currentChar;
        }
        
        else if (currentChar == '(') {
            while (!isEmpty(&stack) && stack.elements[stack.top] != ')') {
                prefix[j++] = stack.elements[stack.top--];
            }
            stack.top--; 
       
        else {
            while (!isEmpty(&stack) && precedence(stack.elements[stack.top]) >= precedence(currentChar)) {
                prefix[j++] = stack.elements[stack.top--];
            }
            stack.elements[++stack.top] = currentChar; 
    }

    
    while (!isEmpty(&stack)) {
        prefix[j++] = stack.elements[stack.top--];
    }

    prefix[j] = '\0';  

    
    reverseString(prefix);
}


int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    
    printf("Enter an infix expression: ");
    scanf("%s", infix);

   
    infixToPrefix(infix, prefix);

   
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
