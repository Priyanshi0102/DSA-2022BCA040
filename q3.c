#include <stdio.h>

int main() {
    int arr[100], numElements, newElement, insertPosition;

    
    printf("Enter the current size of the array: ");
    scanf("%d", &numElements);

    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &arr[i]);
    }

    
    printf("Enter the element you want to insert: ");
    scanf("%d", &newElement);
    printf("Enter the position (1 to %d) where you want to insert the element: ", numElements + 1);
    scanf("%d", &insertPosition);

    
    if (insertPosition < 1 || insertPosition > numElements + 1) {
        printf("Invalid position! Position must be between 1 and %d.\n", numElements + 1);
        return 1;
    }

    
    for (int i = numElements; i >= insertPosition - 1; i--) {
        arr[i + 1] = arr[i];
    }

    
    arr[insertPosition - 1] = newElement;
    numElements++;

    
    printf("Array after insertion:\n");
    for (int i = 0; i < numElements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
