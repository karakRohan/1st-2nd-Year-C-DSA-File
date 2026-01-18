#include <stdio.h>

void merge(int arr[], int start, int middle, int end) {
    int i, j, k;
    int n1 = middle - start + 1;
    int n2 = end - middle;
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[start + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0; j = 0; k = start;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;

        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);
        merge(arr, start, middle, end);
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
    mergeSort(arr, 0, n - 1);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

