#include <stdio.h>

int main() {
    int arr[100], numElements, delPosition;


    printf("Enter the number of elements in the array: ");
    scanf("%d", &numElements);

    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &arr[i]);
    }

    
    printf("Enter the position of the element to delete (1 to %d): ", numElements);
    scanf("%d", &delPosition);

    
    if (delPosition < 1 || delPosition > numElements) {
        printf("Invalid position! Position should be between 1 and %d.\n", numElements);
        return 1;
    }

    
    for (int i = delPosition - 1; i < numElements - 1; i++) {
        arr[i] = arr[i + 1];
    }
    numElements--;

  
    printf("Array after deletion:\n");
    for (int i = 0; i < numElements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
