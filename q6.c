#include <stdio.h>

int main() {
    int array1[50], array2[50], mergedArray[100];
    int size1, size2, totalSize;
    int i = 0, j = 0, k = 0;

  
    printf("Enter the number of elements in the first sorted array: ");
    scanf("%d", &size1);
    printf("Enter the elements of the first array in ascending order:\n");
    for (int x = 0; x < size1; x++) {
        scanf("%d", &array1[x]);
    }

    
    printf("Enter the number of elements in the second sorted array: ");
    scanf("%d", &size2);
    printf("Enter the elements of the second array in ascending order:\n");
    for (int x = 0; x < size2; x++) {
        scanf("%d", &array2[x]);
    }


    while (i < size1 && j < size2) {
        if (array1[i] < array2[j]) {
            mergedArray[k++] = array1[i++];
        } else {
            mergedArray[k++] = array2[j++];
        }
    }

  
    while (i < size1) {
        mergedArray[k++] = array1[i++];
    }

    
    while (j < size2) {
        mergedArray[k++] = array2[j++];
    }

    totalSize = size1 + size2;


    printf("Merged Sorted Array:\n");
    for (int x = 0; x < totalSize; x++) {
        printf("%d ", mergedArray[x]);
    }
    printf("\n");

    return 0;
}
