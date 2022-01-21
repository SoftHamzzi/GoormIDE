#include <stdio.h>

int InterpolSearch(int ar[], int first, int last, int target) {
	if(ar[first]>target || ar[last]<target) return -1;
	
	int mid = ((double)(target-ar[first])/(ar[last]-ar[first])*(last-first))+first;
	
	if(ar[mid]==target) return ar[mid];
	else if(ar[mid]>target) return InterpolSearch(ar,first,mid-1,target);
	else return InterpolSearch(ar,mid+1,last,target);
}

int main(void) {
	int arr[5] = {1,3,5,7,9};
	int idx;
	
	idx = InterpolSearch(arr,0,sizeof(arr)/sizeof(int)-1,2);
	if(idx==-1)
		printf("탐색 실패");
	else
		printf("탐색 성공: %d", idx);
	return 0;
}