#include <stdio.h>

// Function to solve 0-1 Knapsack Problem using Dynamic Programming
int knapsack(int maxWeight, int weights[], int values[], int itemCount) {
    int dp[100][100];  // You can increase size if needed

    int i, w;

    for (i = 0; i <= itemCount; i++) {
        for (w = 0; w <= maxWeight; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                int include = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                int exclude = dp[i - 1][w];
                if (include > exclude) {
                    dp[i][w] = include;
                } else {
                    dp[i][w] = exclude;
                }
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[itemCount][maxWeight];
}

int main() {
    int weights[100], values[100];
    int itemCount, maxWeight, i;

    printf("Enter number of items (max 100): ");
    scanf("%d", &itemCount);

    printf("Enter maximum capacity of knapsack: ");
    scanf("%d", &maxWeight);

    printf("Enter weights of items:\n");
    for (i = 0; i < itemCount; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter values of items:\n");
    for (i = 0; i < itemCount; i++) {
        scanf("%d", &values[i]);
    }

    int result = knapsack(maxWeight, weights, values, itemCount);
    printf("Maximum value in knapsack: %d\n", result);

    return 0;
}
                                                //OR
//#include <stdio.h>
//
//int max(int a, int b) {
//    if (a > b)
//        return a;
//    else
//        return b;
//}
//
//int main() {
//    int weight[100], profit[100], table[101][101];
//    int numberOfItems, capacity;
//    int i, j;
//
//    printf("Enter number of items: ");
//    scanf("%d", &numberOfItems);
//
//    printf("Enter the capacity of knapsack: ");
//    scanf("%d", &capacity);
//
//    printf("Enter weights of items:\n");
//    for (i = 0; i < numberOfItems; i++) {
//        scanf("%d", &weight[i]);
//    }
//
//    printf("Enter profits of items:\n");
//    for (i = 0; i < numberOfItems; i++) {
//        scanf("%d", &profit[i]);
//    }
//
//    // Initialize table
//    for (i = 0; i <= numberOfItems; i++) {
//        for (j = 0; j <= capacity; j++) {
//            if (i == 0 || j == 0)
//                table[i][j] = 0;
//            else if (weight[i - 1] <= j)
//                table[i][j] = max(profit[i - 1] + table[i - 1][j - weight[i - 1]], table[i - 1][j]);
//            else
//                table[i][j] = table[i - 1][j];
//        }
//    }
//
//    printf("Maximum profit: %d\n", table[numberOfItems][capacity]);
//
//    return 0;
//}

