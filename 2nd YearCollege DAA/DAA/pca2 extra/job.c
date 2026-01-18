#include <stdio.h>
#define MAX 10 
int findMaxDeadline(int deadlines[], int n) {
    int max = deadlines[0], i;
    for (i = 1; i < n; i++) {
        if (deadlines[i] > max) {
            max = deadlines[i];
        }
    }
    return max;
}
void jobSequencing(int profits[], int deadlines[], int n) {
    int maxDeadline = findMaxDeadline(deadlines, n);
    int J[MAX]; 
    int i, j, totalProfit = 0;
    for (i = 0; i <= maxDeadline; i++) {
        J[i] = -1;
    }
    for (i = 0; i < n; i++) {
        for (j = deadlines[i]; j > 0; j--) {
            if (J[j] == -1) { 
                J[j] = i;
                totalProfit += profits[i];
                break;
            }
        }
    }
    printf("Maximum Profit: %d\n", totalProfit);
    printf("Selected Jobs: ");
    for (i = 1; i <= maxDeadline; i++) {
        if (J[i] != -1) {
            printf("Job %d ", J[i] + 1);
        }
    }
    printf("\n");
}
int main() {
    int n, i;
    int profits[MAX], deadlines[MAX];
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    
    printf("Enter profits and deadlines of jobs:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &profits[i], &deadlines[i]);
    }
    jobSequencing(profits, deadlines, n);
    
    return 0;
}

