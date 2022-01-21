#ifndef __USEFULHEAP_H__
#define __USEFULHEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int PriorityComp(HData d1, HData d2);

// 힙을 관리하는 구조체
typedef struct _heap {
	PriorityComp * comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap * ph, PriorityComp pc);
int HIsEmpty(Heap * ph);

void HInsert(Heap * ph, HData data);
HData HDelete(Heap * ph);

#endif