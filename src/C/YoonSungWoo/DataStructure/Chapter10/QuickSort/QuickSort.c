#include <stdio.h>

void Swap(int * arr, int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int * arr, int left, int right) {
	int pivot = arr[left];
	int low = left+1;
	int high = right;
	
	while(low <= high) {
		while(arr[low] <= pivot && low <= right && low <= high) {
			low++;
		}
		while(arr[high] >= pivot && high >= (left+1) && low <= high) {
			high--;
		}
		if(low<=high)
			Swap(arr, low, high);
	}
	Swap(arr, left, high);
	return high;
}

void QuickSort(int * arr, int left, int right) {
	if(left <= right) {
		printf("d");
		int pivot = Partition(arr,left,right);
		QuickSort(arr, left, pivot-1);
		QuickSort(arr, pivot+1, right);
	}
}

int main(void) {
	int arr[9]={5,1,3,4,2,9,7,6,8};
	
	int arrSize = sizeof(arr)/sizeof(int);
	QuickSort(arr,0,arrSize-1);
	
	for(int i=0; i<arrSize; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	return 0;
}