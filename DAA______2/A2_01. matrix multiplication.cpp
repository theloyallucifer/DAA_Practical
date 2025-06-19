#include <stdio.h>
#define MAX 10

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rowA, int colA, int rowB, int colB) {
    if (rowA == 1 && colA == 1 && rowB == 1 && colB == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int i, j, k;
    for (i = 0; i < rowA; i++) {
        for (j = 0; j < colB; j++) {
            C[i][j] = 0;  
            for (k = 0; k < colA; k++) {
                C[i][j] += A[i][k] * B[k][j]; 
            }
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int rowA, colA, rowB, colB;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rowA, &colA);
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rowB, &colB);

    if (colA != rowB) {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    multiplyMatrices(A, B, C, rowA, colA, rowB, colB);

    printf("Resulting matrix after multiplication:\n");
    printMatrix(C, rowA, colB);

    return 0;
}

