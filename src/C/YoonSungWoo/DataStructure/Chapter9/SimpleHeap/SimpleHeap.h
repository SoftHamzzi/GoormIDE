#ifndef __SIMPLEHEAP_H__
#define __SIMPLEHEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

// 힙 요소의 자세한 부분
typedef struct _heapElem {
	Priority pr;
	HData data;
} HeapElem;

// 힙을 관리하는 구조체
typedef struct _heap {
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap * ph);
int HIsEmpty(Heap * ph);

void HInsert(Heap * ph, HData data, Priority pr);
HData HDelete(Heap * ph);

#endif