#include <stdio.h>

#define MAX 100
#define INF 99999

int graph[MAX][MAX], dist[MAX], visited[MAX];
int n;

// Function to find vertex with minimum distance
int minDistance() {
    int min = INF, min_index = -1;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Dijkstra function
void dijkstra(int source) {

    // Initialize
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    // Main loop
    for (int count = 0; count < n - 1; count++) {

        int u = minDistance();
        visited[u] = 1;

        for (int v = 0; v < n; v++) {

            if (!visited[v] &&
                graph[u][v] != 0 &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {

    int source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(source);

    return 0;
}
