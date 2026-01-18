#include <stdio.h>
#define MAX 100 
int parent[MAX];
int find(int x) {
    while (parent[x] != x) {
        x = parent[x];
    }
    return x;
}
void union_set(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    parent[rootX] = rootY;
}
int main() {
    int n, e, i, j, u, v, cost, min_cost = 0;
    int edges[MAX][3];  
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    printf("Enter the edges (vertex1 vertex2 cost):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i][1], &edges[i][2], &edges[i][0]);
    }
    for (i = 0; i < n; i++) {
        parent[i] = i;
    }
    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j][0] > edges[j + 1][0]) {
                int tempCost = edges[j][0];
                int tempU = edges[j][1];
                int tempV = edges[j][2];
                
                edges[j][0] = edges[j + 1][0];
                edges[j][1] = edges[j + 1][1];
                edges[j][2] = edges[j + 1][2];
                
                edges[j + 1][0] = tempCost;
                edges[j + 1][1] = tempU;
                edges[j + 1][2] = tempV;
            }
        }
    }
    printf("Selected edges for MST:\n");
    int edge_count = 0;
    for (i = 0; i < e && edge_count < n - 1; i++) {
        u = edges[i][1];
        v = edges[i][2];
        cost = edges[i][0];
        if (find(u) != find(v)) { 
            union_set(u, v);
            printf("%d -- %d (Cost: %d)\n", u, v, cost);
            min_cost += cost;
            edge_count++;
        }
    }
    if (edge_count == n - 1) {
        printf("Minimum Cost of Spanning Tree: %d\n", min_cost);
    } else {
        printf("The network is not connected.\n");
    }
    return 0;
}

