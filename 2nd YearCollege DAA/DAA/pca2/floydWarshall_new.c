#include <stdio.h>
#define MAX 100
#define INF 9999  // Representing Infinity

void floydWarshall(int cost[MAX][MAX], int total) {
    int result[MAX][MAX];
    int i, j, k;

    // Initialize result matrix with the given cost matrix
    for (i = 0; i < total; i++) {
        for (j = 0; j < total; j++) {
            result[i][j] = cost[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (k = 0; k < total; k++) {
        for (i = 0; i < total; i++) {
            for (j = 0; j < total; j++) {
                if (result[i][k] + result[k][j] < result[i][j]) {
                    result[i][j] = result[i][k] + result[k][j];
                }
            }
        }
    }

    // Print shortest path matrix
    printf("Shortest paths between all pairs:\n");
    for (i = 0; i < total; i++) {
        for (j = 0; j < total; j++) {
            if (result[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%3d ", result[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int cost[MAX][MAX];
    int total, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &total);

    printf("Enter cost adjacency matrix (use 9999 for infinity):\n");
    for (i = 0; i < total; i++) {
        for (j = 0; j < total; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    floydWarshall(cost, total);

    return 0;
}

