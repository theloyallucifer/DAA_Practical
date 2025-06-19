#include <stdio.h>

void findMaxMin(int arr[], int low, int high, int *max, int *min) {
    if (low == high) {
        *max = arr[low];
        *min = arr[low];
        return;
    }

    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;
    int leftMax, leftMin, rightMax, rightMin;
    findMaxMin(arr, low, mid, &leftMax, &leftMin);
    findMaxMin(arr, mid + 1, high, &rightMax, &rightMin);

    if (leftMax > rightMax) {
        *max = leftMax;
    } else {
        *max = rightMax;
    }

    if (leftMin < rightMin) {
        *min = leftMin;
    } else {
        *min = rightMin;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max, min;
    findMaxMin(arr, 0, n - 1, &max, &min);
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return 0;
}

