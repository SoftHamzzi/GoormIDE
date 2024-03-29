#include "UsefulHeap.h"

void HeapInit(Heap * ph, PriorityComp pc) {
	ph->numOfData = 0;
	ph->comp = pc;
}
int HIsEmpty(Heap * ph) {
	if(ph->numOfData == 0) return TRUE;
	return FALSE;
}

int GetParentIDX(int idx) {
	return idx/2;
}
int GetLChildIDX(int idx) {
	return idx*2;
}
int GetRChildIDX(int idx) {
	return idx*2+1;
}

int GetHiPriChildIDX(Heap * ph, int idx) {
	
	// 자식 노드가 없을 때
	if(GetLChildIDX(idx) > ph->numOfData)
		return 0;
	// 왼쪽 자식 노드만 있을 때
	else if(GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);
	// 둘 다 있을 때
	else {
		if(ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) > 0)
			return GetLChildIDX(idx);
		else
			return GetRChildIDX(idx);
	}
}

void HInsert(Heap * ph, HData data) {
	int idx = (ph->numOfData)+1;
	
	while(idx != 1) {
		if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0) {
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		} else {
			break;
		}
	}
	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}
HData HDelete(Heap * ph) {
	HData retData = ph->heapArr[1];
	HData lastData = ph->heapArr[ph->numOfData];
	
	int parentIdx = 1;
	int childIdx;
	
	while(childIdx = GetHiPriChildIDX(ph, parentIdx)) {
		if(ph->comp(lastData, ph->heapArr[childIdx]) >= 0) {
			break;
		}
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}
	ph->heapArr[parentIdx] = lastData;
	ph->numOfData -= 1;
	return retData;
}