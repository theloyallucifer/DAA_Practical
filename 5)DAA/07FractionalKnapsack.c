//11/03/25
#include <stdio.h>

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void sortItems(int n, float profit[], float weight[], float ratio[]) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                swap(&profit[j], &profit[j + 1]);
                swap(&weight[j], &weight[j + 1]);
                swap(&ratio[j], &ratio[j + 1]);
            }
        }
    }
}

void fractionalKnapsack(int n, float m, float profit[], float weight[]) {
    float x[n]; 
    float u = m;
    float ratio[n];
    int i, j;

    for (i = 0; i < n; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    sortItems(n, profit, weight, ratio);

    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    for (j = 0; j < n; j++) {
        if (weight[j] > u)
            break;
        x[j] = 1.0;
        u -= weight[j];
    }

    if (j < n) {
        x[j] = u / weight[j];
    }

    printf("\nFractions of items taken:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d: %.2f\n", i + 1, x[i]);
    }
}


int main() {
    int n;
    float m;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    float profit[n], weight[n];

    printf("Enter profit and weight of each item:\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("Item %d (profit weight): ", i + 1);
        scanf("%f %f", &profit[i], &weight[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &m);

    fractionalKnapsack(n, m, profit, weight);

    return 0;
}

