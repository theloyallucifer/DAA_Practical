#include <stdio.h>
void mergeSort(int arr[], int lb, int ub);
void merge(int arr[], int lb, int mid, int ub);

void mergeSort(int arr[], int lb, int ub){
	int mid;
	if (lb >= ub)
		return;
	else{
		mid = (lb + ub) / 2;
		mergeSort(arr, lb, mid);
		mergeSort(arr, mid + 1, ub);
		merge(arr, lb, mid, ub);
	}
}

void merge(int arr[], int lb, int mid, int ub){

	int i = lb, k = 0, j = mid + 1;
	int temp[ub - lb + 1];
	while (i <= mid && j <= ub){
		if (arr[i] < arr[j]){
			temp[k] = arr[i];
			i++;
		}
		else{
			temp[k] = arr[j];
			j++;
		}
		k++;
	}
	// copy left sub-array (if any)
	while (i <= mid){
		temp[k] = arr[i];
		i++;
		k++;
	}
	// copy right sub-array (if any)
	while (j <= ub){
		temp[k] = arr[j];
		j++;
		k++;
	}

	for (i = lb, k = 0; i <= ub; i++, k++){
		arr[i] = temp[k];
	}
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

	mergeSort(arr, 0, n - 1);

	printf("\nThe Sorted Array:\n");
	for (i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
}