#include <stdio.h>

int main() {
    int left, mid, target, found, right;
    target = 22;
    found = 0;
    char array[10] = {10, 15, 20, 22, 25, 30, 35, 40, 45, 50};  // Array is sorted

    left = 0;
    right = 9;

    while (left <= right) {
        mid = (left + right) / 2;

        if (array[mid] == target) {
            printf("Target found at index %d\n", mid);
            found = 1;
            break;
        }

        if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found == 0) {
        printf("Target not found\n");
    }

    return 0;
}
