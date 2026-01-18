#include <stdio.h>
#include <limits.h>
#define MAX 100
int main() {
    int n, i, j;
    int cost[MAX][MAX]; 
    int visited[MAX] = {0}; 
    int minCost = 0;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) {
                cost[i][j] = INT_MAX; 
            }
        }
    }
    visited[0] = 1; 
    printf("\nEdges in the Minimum Spanning Tree:\n");
    int edgeCount;
 for ( edgeCount = 0; edgeCount < n - 1; edgeCount++) {
        int min = INT_MAX, u = -1, v = -1;
        
        for (i = 0; i < n; i++) {
            if (visited[i]) { 
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        
        if (u != -1 && v != -1) {
            printf("%d - %d : %d\n", u + 1, v + 1, min);
            visited[v] = 1;
            minCost += min;
        }
    }
    
    printf("Total cost of MST: %d\n", minCost);
    return 0;
}

