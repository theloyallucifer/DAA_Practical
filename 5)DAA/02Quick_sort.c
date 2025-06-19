#include <stdio.h>
int partition(int arr[], int lb, int ub);
void quickSort(int arr[], int lb, int ub);

void quickSort(int arr[], int lb, int ub){
	int loc;
	if (lb >= ub)
		return;
	else{
		loc = partition(arr, lb, ub);
		quickSort(arr, lb, loc - 1);
		quickSort(arr, loc + 1, ub);
	}
}

int partition(int arr[], int lb, int ub){
	int pivot = arr[lb];
	int start = lb, end = ub, temp;
	while (start < end){
		while (arr[start] <= pivot && start < ub){
			start++;
		}
		while (arr[end] > pivot && end > lb){
			end--;
		}
		if (start < end){
			temp = arr[start]; // swap start and end
			arr[start] = arr[end];
			arr[end] = temp;
		}
	}
	// swap pivot and end
	arr[lb] = arr[end];
	arr[end] = pivot;
	return end;
}
int main(){
	int n, i;
	printf("Enter the no. of Elements: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter the Elements Of the Array: ");
	for (i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}

	quickSort(arr, 0, n - 1);

	printf("\nThe Sorted Array:\n");
	for (i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
}