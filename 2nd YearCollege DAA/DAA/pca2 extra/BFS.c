#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], n;

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0, i;
    queue[rear++] = start;
    visited[start] = 1;
    
    printf("BFS Traversal: ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
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

    BFS(start);

}
