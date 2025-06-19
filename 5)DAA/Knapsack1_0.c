#include <stdio.h>

// Function to find maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0-1 Knapsack Problem using Dynamic Programming
int knapsack(int capacity, int weights[], int profits[], int n) {
    int dp[n + 1][capacity + 1];

    // [INITIALIZATION] - Base case: no item or 0 capacity
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
        }
    }

    // [START OF LOOP] - Build dp table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(profits[i - 1] + dp[i - 1][w - weights[i - 1]],
                               dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    // [END OF LOOP]

    // [TRACEBACK] - To find selected items
    int selected[n];
    for (int i = 0; i < n; i++) selected[i] = 0; // Initialize to 0

    int i = n, w = capacity;
    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i-1][w]) {
            selected[i-1] = 1; // Item i is included
            w -= weights[i-1];
        }
        i--;
    }

    // Print selected array
    printf("Selected items (0: Not taken, 1: Taken):\n");
    for (int j = 0; j < n; j++) {
        printf("x%d: %d\n", j + 1, selected[j]);
    }

    return dp[n][capacity]; // Return max profit
}

int main() {
    int n; // Number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    int weights[n], profits[n];
    printf("Enter weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter profits of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &profits[i]);
    }

    int capacity;
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    int maxProfit = knapsack(capacity, weights, profits, n);
    printf("Maximum profit in knapsack = %d\n", maxProfit);

    return 0;
}

// output
// Enter number of items: 4
// Enter weights of the items:
// 2 3 4 5
// Enter profits of the items:
// 1 2 5 6
// Enter knapsack capacity: 8
// Selected items (0: Not taken, 1: Taken):
// x1: 0
// x2: 1
// x3: 0
// x4: 1
// Maximum profit in knapsack = 8

