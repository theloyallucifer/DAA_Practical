#include <stdio.h>
#include <stdlib.h>

struct Item {
    int weight;
    int value;
    double ratio;
};

int compare(const void *a, const void *b) {
    double r1 = ((struct Item *)a)->ratio;
    double r2 = ((struct Item *)b)->ratio;
    return (r2 > r1) - (r2 < r1);
}

double fractionalKnapsack(int capacity, struct Item items[], int n) {
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += items[i].ratio * remainingWeight;
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item *items = (struct Item *)malloc(n * sizeof(struct Item));
    if (items == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Value Weight : ", i + 1);
        scanf("%d %d",&items[i].value, &items[i].weight);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    free(items);
    return 0;
}

