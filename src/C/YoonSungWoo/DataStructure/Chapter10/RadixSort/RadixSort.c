#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM 10

void RadixSort(int * arr, int num, int maxLen) {
	int bi, di, divfac=1;
	Queue buckets[BUCKET_NUM];
	for(bi=0;bi<10;bi++) {
		QueueInit(&buckets[bi]);
	}
	
	for(int pos=0;pos<maxLen;pos++) {
		// 큐에 집어넣기
		for(di=0;di<num;di++) {
			Enqueue(&buckets[arr[di]/divfac%10], arr[di]);
		}
		
		for(di=0,bi=0;bi<BUCKET_NUM;bi++) {
			while(!QIsEmpty(&buckets[bi]))
				arr[di++] = Dequeue(&buckets[bi]);
		}
		
		divfac*=10;
	}
}

int main(void) {
	int arr[7] = {13, 212, 14, 7141, 10987, 6, 15};
	
	int len = sizeof(arr)/sizeof(int);
	int i;
	
	RadixSort(arr, len, 5);
	
	for(i=0; i<len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	return 0;
}