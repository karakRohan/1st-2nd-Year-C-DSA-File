#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], n;

void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int edges, i, v1, v2, start;
    
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &edges);
    
    printf("Enter the edges (vertex1 vertex2):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &v1, &v2);
        adj[v1][v2] = adj[v2][v1] = 1;
    }

    for (i = 0; i < n; i++) visited[i] = 0;

    printf("Enter the starting node: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);
//   return 0;
}
