#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100


struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct Stack {
    struct TreeNode* data[MAX_STACK_SIZE];
    int top;
};


void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

int isStackEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, struct TreeNode* node) {
    if (stack->top < MAX_STACK_SIZE - 1) {
        stack->data[++stack->top] = node;
    }
}

struct TreeNode* pop(struct Stack* stack) {
    return isStackEmpty(stack) ? NULL : stack->data[stack->top--];
}


struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void inorderRecursive(struct TreeNode* root) {
    if (root) {
        inorderRecursive(root->left);
        printf("%d ", root->data);
        inorderRecursive(root->right);
    }
}


void inorderNonRecursive(struct TreeNode* root) {
    struct Stack stack;
    initializeStack(&stack);
    struct TreeNode* current = root;

    while (current || !isStackEmpty(&stack)) {
        while (current) {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
}


void preorderRecursive(struct TreeNode* root) {
    if (root) {
        printf("%d ", root->data);
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}


void preorderNonRecursive(struct TreeNode* root) {
    struct Stack stack;
    initializeStack(&stack);
    push(&stack, root);

    while (!isStackEmpty(&stack)) {
        struct TreeNode* current = pop(&stack);
        printf("%d ", current->data);

        if (current->right) {
            push(&stack, current->right);
        }
        if (current->left) {
            push(&stack, current->left);
        }
    }
}


void postorderRecursive(struct TreeNode* root) {
    if (root) {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        printf("%d ", root->data);
    }
}


    struct Stack stack1, stack2;
    initializeStack(&stack1);
    initializeStack(&stack2);

    push(&stack1, root);

    while (!isStackEmpty(&stack1)) {
        struct TreeNode* current = pop(&stack1);
        push(&stack2, current);

        if (current->left) {
            push(&stack1, current->left);
        }
        if (current->right) {
            push(&stack1, current->right);
        }
    }

    while (!isStackEmpty(&stack2)) {
        printf("%d ", pop(&stack2)->data);
    }
}


int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Recursive Inorder: ");
    inorderRecursive(root);
    printf("\nNon-Recursive Inorder: ");
    inorderNonRecursive(root);

    printf("\nRecursive Preorder: ");
    preorderRecursive(root);
    printf("\nNon-Recursive Preorder: ");
    preorderNonRecursive(root);

    printf("\nRecursive Postorder: ");
    postorderRecursive(root);
    printf("\nNon-Recursive Postorder: ");
    postorderNonRecursive(root);

    return 0;
}
