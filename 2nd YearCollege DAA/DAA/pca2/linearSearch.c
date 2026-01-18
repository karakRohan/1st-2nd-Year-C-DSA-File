#include <stdio.h>
int linearSearch(int arr[], int size, int key) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int n, i, key, result;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    result = linearSearch(arr, n, key);
    if (result != -1) {
        printf("Element found at index %d.\n", result);
    } else {
        printf("Element not found in the array.\n");
    }
    return 0;
}

