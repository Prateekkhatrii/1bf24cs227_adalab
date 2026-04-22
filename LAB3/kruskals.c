#include <stdio.h>

#define V 3
#define MAXE 10

struct Edge {
    int u, v, w;
};

int parent[V];

int find(int i) {
    if (parent[i] == i)
        return i;
    return find(parent[i]);
}

void unionSet(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    parent[pu] = pv;
}

void sortEdges(struct Edge edges[], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main() {
    int input[V][2];
    struct Edge edges[MAXE];
    int E = 0;

    printf("Enter 3x2 weight matrix:\n");

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &input[i][j]);
        }
    }

    // Convert to edge list
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < 2; j++) {
            if (input[i][j] != 0 && i != j) {
                edges[E].u = i;
                edges[E].v = j;
                edges[E].w = input[i][j];
                E++;
            }
        }
    }

    for (int i = 0; i < V; i++)
        parent[i] = i;

    sortEdges(edges, E);

    int cost = 0;

    printf("Kruskal's MST:\n");

    for (int i = 0; i < E; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            printf("%d - %d  Weight: %d\n", edges[i].u, edges[i].v, edges[i].w);
            cost += edges[i].w;
            unionSet(edges[i].u, edges[i].v);
        }
    }

    printf("Total Cost: %d\n", cost);

    return 0;
}
