#include <stdio.h>

void Swap(int * arr, int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

// 중간 값을 반환하는 함수
int MOT(int * arr, int left, int right) {
	int samples[3] = {left, (left+right)/2, right};
	
	if(arr[samples[0]] > arr[samples[1]])
		Swap(samples, 0, 1);
	if(arr[samples[1]] > arr[samples[2]])
		Swap(samples, 1, 2);
	if(arr[samples[0]] > arr[samples[1]])
		Swap(samples, 0, 1);
	
	return samples[1];
}

int Partition(int * arr, int left, int right) {
	int pIdx = MOT(arr, left, right);
	int pivot = arr[pIdx];
	
	int low = left+1;
	int high = right;
	
	Swap(arr, left, pIdx);
	
	printf("선택된 피봇 = %d\n", pivot);
	
	while(low <= high) {
		while(arr[low] <= pivot && low <= right) {
			low++;
		}
		while(arr[high] >= pivot && high >= (left+1)) {
			high--;
		}
		if(low<=high)
			Swap(arr, low, high);
	}
	Swap(arr, left, high);
	return high;
}

void QuickSort(int * arr, int left, int right) {
	if(left < right) {
		int pivot = Partition(arr,left,right);

		QuickSort(arr, left, pivot-1);
		QuickSort(arr, pivot+1, right);
	}
}

int main(void) {
	int arr[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	
	int arrSize = sizeof(arr)/sizeof(int);
	QuickSort(arr,0,arrSize-1);
	
	for(int i=0; i<arrSize; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	return 0;
}