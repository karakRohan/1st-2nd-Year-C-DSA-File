#include <stdio.h>
int main() {
    int m,n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (m = 0; m < n; m++) {
        scanf("%d", &arr[m]);
    }
    int low = 0, high = n - 1;
    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pivot = arr[high];
            int i = low - 1,j;
            for (j = low; j < high; j++) {
                if (arr[j] < pivot) {
                    i++;
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            int temp = arr[i + 1];
            arr[i + 1] = arr[high];
            arr[high] = temp;
            int pivotIndex = i + 1;
            quickSort(arr, low, pivotIndex - 1);  
            quickSort(arr, pivotIndex + 1, high); 
        }
    }
    quickSort(arr, low, high);
    printf("Sorted array:\n");
    for (m = 0; m < n; m++) {
        printf("%d ", arr[m]);
    }
    printf("\n");
    return 0;
}

