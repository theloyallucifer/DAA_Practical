#include <stdio.h>

char board[3][3];
char currentPlayer;
 
// Function to initialize the board
void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '1' + i * 3 + j; // Fill with 1-9
}

// Function to display the board
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
            printf("\n---|---|---\n");
    }
    printf("\n\n");
}

// Function to check if a player has won
int checkWin() {
    // Rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return 1;
    }

    // Diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return 1;

    return 0;
}

// Function to check if the board is full (draw)
int checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
    return 1;
}

// Function to make a move
int makeMove(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (position < 1 || position > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return 0;
    }

    board[row][col] = currentPlayer;
    return 1;
}

// Function to switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    int move;
    currentPlayer = 'X';
    initializeBoard();

    printf("Tic-Tac-Toe Game (Player X vs Player O)\n");
    printBoard();

    while (1) {
        printf("Player %c, enter your move (1-9): ", currentPlayer);
        scanf("%d", &move);

        if (!makeMove(move)) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        printBoard();

        if (checkWin()) {
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (checkDraw()) {
            printf("It's a draw!\n");
            break;
        }

        switchPlayer();
    }

    return 0;
}

