#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20  // Max board size

int board[MAX];
int n;

// Function to print the board
void printSolution() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if placing queen at row 'row' and column 'col' is safe
bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check column and diagonals
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

// Recursive function to solve N-Queens
void solve(int row) {
    if (row == n) {
        printSolution();
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1); // Recur to place rest of the queens
        }
    }
}

int main() {
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Please enter a value between 1 and %d\n", MAX);
        return 1;
    }

    printf("\nSolutions to the %d-Queens Problem:\n\n", n);
    solve(0);

    return 0;
}

