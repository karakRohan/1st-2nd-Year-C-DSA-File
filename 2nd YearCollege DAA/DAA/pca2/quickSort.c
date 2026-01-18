#include <stdio.h>

void quickSort(int arr[], int start, int end) {
    if (start < end) {
        int pivot = arr[end];
        int i = start - 1;
        int j, temp;

        for (j = start; j < end; j++) {
            if (arr[j] <= pivot) {
                i++;
                // Swap arr[i] and arr[j]
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        // Swap arr[i+1] and arr[end] (pivot)
        temp = arr[i + 1];
        arr[i + 1] = arr[end];
        arr[end] = temp;
        int pivotIndex = i + 1;
        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}

int main() {
    int n, i;
    printf("Enter number of elements : ");
    scanf("%d", &n);
	int arr[n];    
	printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

