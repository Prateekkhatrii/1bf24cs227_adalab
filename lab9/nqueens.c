#include <stdio.h>

#define N 10

int board[N][N];

int isSafe(int row, int col, int n) {

    // Check column
    for(int i = 0; i < row; i++)
        if(board[i][col])
            return 0;

    // Check left diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j])
            return 0;

    // Check right diagonal
    for(int i = row, j = col; i >= 0 && j < n; i--, j++)
        if(board[i][j])
            return 0;

    return 1;
}

int solve(int row, int n) {

    if(row == n)
        return 1;

    for(int col = 0; col < n; col++) {

        if(isSafe(row, col, n)) {

            board[row][col] = 1;

            if(solve(row + 1, n))
                return 1;

            board[row][col] = 0;
        }
    }

    return 0;
}

int main() {

    int n;
    scanf("%d", &n);

    if(solve(0, n)) {

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++)
                printf("%d ", board[i][j]);

            printf("\n");
        }
    }
    else {
        printf("No solution");
    }

    return 0;
}
