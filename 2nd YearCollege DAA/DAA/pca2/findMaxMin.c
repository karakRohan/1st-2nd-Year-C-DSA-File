#include <stdio.h>

int findMax(int arr[], int start, int end) {
    if (start == end) {
        return arr[start];
    }

    int middle = (start + end) / 2;
    int max1 = findMax(arr, start, middle);
    int max2 = findMax(arr, middle + 1, end);

    if (max1 > max2) {
        return max1;
    } else {
        return max2;
    }
}

int findMin(int arr[], int start, int end) {
    if (start == end) {
        return arr[start];
    }

    int middle = (start + end) / 2;
    int min1 = findMin(arr, start, middle);
    int min2 = findMin(arr, middle + 1, end);

    if (min1 < min2) {
        return min1;
    } else {
        return min2;
    }
}

int main() {
    int arr[100], n, i;

    printf("Enter the number of elements (max 100): ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maximum = findMax(arr, 0, n - 1);
    int minimum = findMin(arr, 0, n - 1);

    printf("Maximum element: %d\n", maximum);
    printf("Minimum element: %d\n", minimum);

    return 0;
}

