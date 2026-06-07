#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int indegree[MAX];
int visited[MAX];

int queue[MAX];
int front = 0, rear = 0;

int main() {

    int n, e;
    int u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize graph
    for(int i = 0; i < n; i++) {
        indegree[i] = 0;
        visited[i] = 0;

        for(int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Read edges
    printf("Enter edges (u v):\n");

    for(int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;

        // Find indegree
        indegree[v]++;
    }

    // Enqueue vertices with indegree 0
    for(int i = 0; i < n; i++) {

        if(indegree[i] == 0) {

            queue[rear++] = i;

            visited[i] = 1;
        }
    }

    printf("Topological Order:\n");

    while(front < rear) {

        u = queue[front++];

        printf("%d ", u);

        // Adjacent vertices
        for(int w = 0; w < n; w++) {

            if(graph[u][w] == 1) {

                if(!visited[w]) {

                    indegree[w]--;

                    if(indegree[w] == 0) {

                        queue[rear++] = w;

                        visited[w] = 1;
                    }
                }
            }
        }
    }

    return 0;
}
