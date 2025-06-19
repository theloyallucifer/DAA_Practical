#include <stdio.h>

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
int knapsack(int weights[], int values[], int n, int capacity) {
    int dp[n+1][capacity+1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i-1] <= w)
                dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter weights and values of each item:\n");

    int weights[n], values[n];

    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight Value: ", i+1);
        scanf("%d %d", &weights[i], &values[i]);
    }
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    int maxValue = knapsack(weights, values, n, capacity);
    printf("Maximum value that can be obtained: %d\n", maxValue);

    return 0;
}

