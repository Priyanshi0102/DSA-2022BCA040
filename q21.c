#include <stdio.h>
#include <stdlib.h>


struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};


int getHeight(struct AVLNode* node) {
    return node ? node->height : 0;
}


int max(int a, int b) {
    return (a > b) ? a : b;
}


struct AVLNode* createNode(int value) {
    struct AVLNode* node = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    if (!node) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;  
    return node;
}


struct AVLNode* rotateRight(struct AVLNode* y) {
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}


struct AVLNode* rotateLeft(struct AVLNode* x) {
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}


int getBalance(struct AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}


struct AVLNode* insertNode(struct AVLNode* node, int value) {
    if (!node) {
        return createNode(value);
    }

    if (value < node->data) {
        node->left = insertNode(node->left, value);
    } else if (value > node->data) {
        node->right = insertNode(node->right, value);
    } else {
        return node; 
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    
    int balance = getBalance(node);

   
    if (balance > 1 && value < node->left->data) {
        return rotateRight(node);
    }

  
    if (balance < -1 && value > node->right->data) {
        return rotateLeft(node);
    }

    if (balance > 1 && value > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    
    if (balance < -1 && value < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void inorderTraversal(struct AVLNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct AVLNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}


void postorderTraversal(struct AVLNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}


int main() {
    struct AVLNode* root = NULL;
    int choice, value;

    do {
       
        printf("\nAVL Tree Operations:\n");
        printf("1. Insert a node\n");
        printf("2. In-order traversal\n");
        printf("3. Pre-order traversal\n");
        printf("4. Post-order traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("Node with value %d inserted.\n", value);
                break;
            case 2:
                printf("In-order traversal: ");
                inorderTraversal(root);
                printf("\n");
                brea
