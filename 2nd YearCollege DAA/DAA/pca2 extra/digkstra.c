#include <stdio.h>
#define MAX 5
#define INF 99999

int minDistance(int dist[], int visited[], int n) {
    int min = INF, minIndex;
    int i;
    for (i = 0; i < n; i++) {
        if (visited[i] == 0 && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}
void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];
    int visited[MAX];
    int i, count, v;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;
        for (v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < n; i++) {
        if (dist[i] == INF) {
            printf("%d\t INF\n", i);
        } else {
            printf("%d\t %d\n", i, dist[i]);
        }
    }
}
int main() {
    int graph[MAX][MAX] = {
        {0, 10, 5, INF, INF},    
        {INF, 0, INF, 1, INF},    
        {INF, 3, 0, 9, 2},    
        {INF, INF, INF, 0, INF},    
        {2, INF, INF, 6, 0}   
    };
    int n = 5, src;
    printf("Enter the source vertex (0-%d): ", n - 1);
    scanf("%d", &src);
    
    if (src < 0 || src >= n) {
        printf("Invalid source vertex.\n");
        return 1;
    }
    dijkstra(graph, n, src);
    return 0;
}