#include <stdio.h>
#define MAX 100
#define INF 9999

void bellmanFord(int matrix[MAX][MAX], int total, int source) {
    int dist[MAX];
    int i, j, k;

    for (i = 0; i < total; i++) {
        dist[i] = matrix[source][i];
    }

    // Perform relaxation for (total - 2) times
    for (k = 1; k <= total - 2; k++) {
        for (i = 0; i < total; i++) {
            if (i == source) continue;

            for (j = 0; j < total; j++) {
                if (matrix[j][i] != INF && dist[j] != INF) {
                    if (dist[i] > dist[j] + matrix[j][i]) {
                        dist[i] = dist[j] + matrix[j][i];
                    }
                }
            }
        }
    }

    printf("Shortest path costs from vertex %d:\n", source);
    for (i = 0; i < total; i++) {
        if (dist[i] == INF) {
            printf("To vertex %d: INF\n", i);
        } else {
            printf("To vertex %d: %d\n", i, dist[i]);
        }
    }
}

int main() {
    int matrix[MAX][MAX];
    int total, source, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &total);

    printf("Enter cost adjacency matrix:\n");
    printf("(Use 9999 for infinity)\n");

    for (i = 0; i < total; i++) {
        for (j = 0; j < total; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Enter source vertex (0 to %d): ", total - 1);
    scanf("%d", &source);

    bellmanFord(matrix, total, source);

    return 0;
}

