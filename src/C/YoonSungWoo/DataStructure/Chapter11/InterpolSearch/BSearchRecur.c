#include <stdio.h>

int BSearchRecur(int ar[], int first, int last, int target) {
	if(first>last) return -1;
	
	int mid = (first+last)/2;
	
	if(ar[mid]==target) return ar[mid];
	else if(ar[mid]>target) return BSearchRecur(ar,first,mid-1,target);
	else return BSearchRecur(ar,mid+1,last,target);
}

int main(void) {
	int arr[5] = {1,3,5,7,9};
	int idx;
	
	idx = BSearchRecur(arr,0,sizeof(arr)/sizeof(int)-1,7);
	if(idx==-1)
		printf("탐색 실패");
	else
		printf("탐색 성공 : %d", idx);
	return 0;
}