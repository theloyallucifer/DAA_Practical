#include <stdio.h>

void linearSearch(int arr[], int size, int element) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("Element %d found at position %d.\n", element, i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the array.\n", element);
    }
}

int main() {
    int size, element;

    // Input the number of elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];

    // Input array elements
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the element to search for
    printf("Enter the element to search: ");
    scanf("%d", &element);

    // Call the linear search function
    linearSearch(arr, size, element);

    return 0;
}

