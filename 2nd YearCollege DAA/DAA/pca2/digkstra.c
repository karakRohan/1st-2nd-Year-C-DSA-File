#include <stdio.h>

#define MAX 10

void sortJobs(int profit[], int deadline[], int count) {
    int i, j, temp;
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (profit[j] < profit[j + 1]) {
                // Swap profits
                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;

                // Swap deadlines accordingly
                temp = deadline[j];
                deadline[j] = deadline[j + 1];
                deadline[j + 1] = temp;
            }
        }
    }
}

void jobSequencing(int profit[], int deadline[], int count) {
    int jobOrder[MAX];
    int result[MAX];
    int maxDeadline = 0, i, j;

    // Find max deadline
    for (i = 0; i < count; i++) {
        if (deadline[i] > maxDeadline) {
            maxDeadline = deadline[i];
        }
    }

    // Initialize result array
    for (i = 0; i < maxDeadline; i++) {
        result[i] = -1;
    }

    // Assign jobs
    for (i = 0; i < count; i++) {
        for (j = deadline[i] - 1; j >= 0; j--) {
            if (result[j] == -1) {
                result[j] = i;
                break;
            }
        }
    }

    // Print selected jobs
    printf("\nSelected jobs for maximum profit:\n");
    for (i = 0; i < maxDeadline; i++) {
        if (result[i] != -1) {
            printf("Job%d ", result[i] + 1);
        }
    }
    printf("\n");
}

int main() {
    int profit[MAX], deadline[MAX];
    int i, total;

    printf("Enter number of jobs: ");
    scanf("%d", &total);

    for (i = 0; i < total; i++) {
        printf("Enter profit for Job %d: ", i + 1);
        scanf("%d", &profit[i]);
        printf("Enter deadline for Job %d: ", i + 1);
        scanf("%d", &deadline[i]);
    }

    // Sort jobs by profit
    sortJobs(profit, deadline, total);

    // Perform job sequencing
    jobSequencing(profit, deadline, total);

    return 0;
}

