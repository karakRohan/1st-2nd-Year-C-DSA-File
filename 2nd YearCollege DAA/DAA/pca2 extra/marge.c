#include <stdio.h>
int main() {
    int n,m;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (m = 0; m < n; m++) {
        scanf("%d", &arr[m]);
    }
    int temp[n];  
    int left, mid, right,size, i, j, k;
    for (size = 1; size < n; size *= 2) {
        for (left = 0; left < n - 1; left += 2 * size) {
            mid = left + size - 1;
            right = (left + 2 * size - 1 < n) ? (left + 2 * size - 1) : (n - 1);
            i = left;
            j = mid + 1;
            k = left;
            while (i <= mid && j <= right) {
                if (arr[i] <= arr[j]) {
                    temp[k++] = arr[i++];
                } else {
                    temp[k++] = arr[j++];
                }
            }
            while (i <= mid) {
                temp[k++] = arr[i++];
            }
            while (j <= right) {
                temp[k++] = arr[j++];
            }
            for (i = left; i <= right; i++) {
                arr[i] = temp[i];
            }
        }
    }
    printf("Sorted array:\n");
    for (m = 0; m < n; m++) {
        printf("%d ", arr[m]);
    }
    printf("\n");
    return 0;
}

