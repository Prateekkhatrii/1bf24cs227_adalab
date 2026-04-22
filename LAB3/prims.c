#include <stdio.h>
#include <limits.h>

#define MAX 100

int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[MAX][MAX], int V) {
    printf("\nEdge \tWeight\n");
    int totalCost = 0;   // variable to store total MST weight
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("Total Cost of MST = %d\n", totalCost);  // print total weight
}

void primMST(int graph[MAX][MAX], int V) {
    int parent[V], key[V], mstSet[V];
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph, V);
}

int main() {
    int V;
    int graph[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter the weight matrix (%d x %d):\n", V, V-1);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V-1; j++) {
            int w;
            scanf("%d", &w);
            if (i != j) {
                graph[i][j] = w;
                graph[j][i] = w;
            }
        }
    }

    primMST(graph, V);
    return 0;
}
