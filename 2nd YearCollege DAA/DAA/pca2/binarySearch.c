#include <stdio.h>
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int main() {
    int n, i, key, result;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
	int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    result = binarySearch(arr, 0, n - 1, key);
    if (result != -1) {
        printf("Element found at index %d.\n", result);
    } else {
        printf("Element not found.\n");
    }
    return 0;
}

