#include <stdio.h>

int main() {
    int numbers[] = {1, 3, 5, 7, 9, 11, 13};
    int counter;
    int arrLength = sizeof(numbers) / sizeof(numbers[0]);
    int targetValue = 9;
    int start = 0;
    int end = arrLength - 1;
    int targetFound = 0;
    int position = -1;

    for (counter = 0; start <= end; counter++) {
        int midPoint = start + (end - start) / 2;

        if (numbers[midPoint] == targetValue) {
            position = midPoint;
            targetFound = 1;
            break;
        }

        if (numbers[midPoint] < targetValue) {
            start = midPoint + 1;
        } else {
            end = midPoint - 1;
        }
    }

    if (targetFound) {
        printf("Target is located at index %d\n", position);
    } else {
        printf("Target not found in the array\n");
    }

    return 0;
}
