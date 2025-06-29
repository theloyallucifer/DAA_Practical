#include <stdio.h>
#include <limits.h>

void matrixChain(int p[], int n) {
    int m[n][n];
    int s[n][n];

    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l < n; l++) { 
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) { 
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
 
    printf("Minimum number of multiplications: %d\n", m[1][n - 1]);

    printf("\n");
}

void printOrder(int s[][10], int i, int j) { 
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOrder(s, i, s[i][j]);
        printOrder(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int p[n + 1]; 
    printf("Enter the dimensions: ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    matrixChain(p, n + 1);

    return 0;
}

