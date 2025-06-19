//18/02/25
#include <stdio.h>


int binarySearch(int arr[], int low, int high, int key) {
    if (low == high)
        if (arr[low] == key)
           return low;
        else return -1; 
    else{
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid; 
        else if (arr[mid] > key)
            return binarySearch(arr, low, mid - 1, key); 
        else
            return binarySearch(arr, mid + 1, high, key); 
    }

}
int main() {
    int n, key;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];

    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search: ");
    scanf("%d", &key);


    int result = binarySearch(arr, 0, n - 1, key);
    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
