#include <stdio.h>

#define INF 99999

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int W[n][n];

    // Input adjacency matrix
    printf("Enter the weight matrix:\n");
    printf("(Enter %d for INF if no edge exists)\n", INF);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &W[i][j]);
        }
    }

    // Floyd–Warshall Algorithm (in-place)
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (W[i][k] + W[k][j] < W[i][j]) {
                    W[i][j] = W[i][k] + W[k][j];
                }
            }
        }
    }

    // Output result
    printf("\nShortest distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (W[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", W[i][j]);
        }
        printf("\n");
    }

    // Optional: Negative cycle check
    for (int i = 0; i < n; i++) {
        if (W[i][i] < 0) {
            printf("\nNegative weight cycle detected!\n");
            break;
        }
    }

    return 0;
}
