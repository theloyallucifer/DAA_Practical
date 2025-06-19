#include <stdio.h>
#include <stdbool.h>

// Function to print the chessboard with queen positions
void printSolution(int N, int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);  // 1 represents a queen
        printf("\n");
    }
}

// Check if a queen can be placed at board[row][col]
bool isSafe(int N, int board[N][N], int row, int col) {
    // Check left side of this row
    for (int i = 0; i < col; i++)
        if (board[row][i]) return false;

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // Check lower diagonal on left side
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j]) return false;

    return true;  // Safe to place queen
}

// Recursive function to solve N-Queens problem
bool solveNQUtil(int N, int board[N][N], int col) {
    // Base case: All queens placed
    if (col >= N) return true;

    // Try placing queen in all rows of current column
    for (int i = 0; i < N; i++) {
        if (isSafe(N, board, i, col)) {
            board[i][col] = 1;  // Place queen

            // Recur to place rest of queens
            if (solveNQUtil(N, board, col + 1)) 
                return true;

            board[i][col] = 0;  // Backtrack if no solution found
        }
    }
    return false;  // No safe position in this column
}

// Main function to solve N-Queens problem
bool solveNQ(int N) {
    int board[N][N];
    // Initialize board with 0 (no queens)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (!solveNQUtil(N, board, 0)) {
        printf("No solution exists for %d queens.\n", N);
        return false;
    }

    printf("Solution for %d queens:\n", N);
    printSolution(N, board);
    return true;
}

int main() {
    int N;
    printf("Enter number of queens: ");
    scanf("%d", &N);
    solveNQ(N);
    return 0;
}

// output
// Enter number of queens: 4
// Solution for 4 queens:
//  0  0  1  0 
//  1  0  0  0 
//  0  0  0  1 
//  0  1  0  0