#include <stdio.h>
void fractionalKnapsack(int n, float weights[], float profits[], float capacity) {
    float x[n];
    float totalProfit = 0.0;
    float remainingCapacity = capacity;
    int i;
    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }
    
    for (i = 0; i < n; i++) {
        if (weights[i] > remainingCapacity) {
            break;
        }
        x[i] = 1.0;
        remainingCapacity -= weights[i];
        totalProfit += profits[i];
    }
    
    if (i < n) { 
        x[i] = remainingCapacity / weights[i];
        totalProfit += x[i] * profits[i];
    }
    printf("Maximum Profit: %.2f\n", totalProfit);
    printf("Fraction of items taken:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d: %.2f\n", i + 1, x[i]);
    }
}

int main() {
    int n, i;
    float capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    float weights[n], profits[n];
    printf("Enter weights and profits of items:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &weights[i], &profits[i]);
    }
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);
    fractionalKnapsack(n, weights, profits, capacity);
    return 0;
}

