#include <stdio.h>

int iterativeBinarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; 
        }
        if (arr[mid] < target) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }

    return -1; 
}


int recursiveBinarySearch(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1; 
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        return mid; 
    }
    if (arr[mid] < target) {
        return recursiveBinarySearch(arr, mid + 1, high, target);
    }
    return recursiveBinarySearch(arr, low, mid - 1, target);
}

int main() {
    int array[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int size = sizeof(array) / sizeof(array[0]);
    int target;

    
    printf("Enter the element to search: ");
    scanf("%d", &target);

    
    int resultIterative = iterativeBinarySearch(array, size, target);
    if (resultIterative != -1) {
        printf("Element found at index %d using iterative binary search.\n", resultIterative);
    } else {
        printf("Element not found using iterative binary search.\n");
    }

    
    int resultRecursive = recursiveBinarySearch(array, 0, size - 1, target);
    if (resultRecursive != -1) {
        printf("Element found at index %d using recursive binary search.\n", resultRecursive);
    } else {
        printf("Element not found using recursive binary search.\n");
    }

    return 0;
}
