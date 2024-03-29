#include <stdio.h>

int BSearch(int ar[], int len, int target) {
	int first = 0;
	int last = len-1;
	int mid;
	
	while(first<=last) {
		mid = (first+last)/2;
		if(target == ar[mid]) return mid;
		else {
			if(target<ar[mid])
				last=mid;
			else
				first=mid;
		}
	}
	return -1;
}

int main(void) {
	int arr[] = {1,3,5,7,9};
	int idx;
	
	idx = BSearch(arr, sizeof(arr)/sizeof(int), 7);
	if(idx==-1) printf("탐색 실패 \n");
	else printf("탐색 성공: %d", idx);
	
	return 0;
}