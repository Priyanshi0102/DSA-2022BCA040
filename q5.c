#include <stdio.h>

int main() {
    int firstArray[50], secondArray[50], mergedArray[100];
    int size1, size2, totalSize;

    
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &size1);
    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &firstArray[i]);
    }

    
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &size2);
    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &secondArray[i]);
    }

  
    for (int i = 0; i < size1; i++) {
        mergedArray[i] = firstArray[i];
    }

    
    for (int i = 0; i < size2; i++) {
        mergedArray[size1 + i] = secondArray[i];
    }
    totalSize = size1 + size2;

    
    printf("Merged Array:\n");
    for (int i = 0; i < totalSize; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    return 0;
}
