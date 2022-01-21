#include <stdio.h>
#include <stdlib.h>

#include "Slot2.h"
#include "Table2.h"
#include "DLinkedList.h"

void TBLInit(Table * pt, HashFunc * f) {
	int i;
	
	for(i=0;i<MAX_TBL;i++) {
		ListInit(&(pt->tbl[i]));
	}
	
	pt->hf = f;
}

void TBLInsert(Table * pt, Key k, Value v) {
	int hv = pt->hf(k);
	Slot ns = {k, v};
	
	if(TBLSearch(pt,k)!=NULL) {
		printf("중첩\n");
		return;
	} else {
	LInsert(&(pt->tbl[hv]), ns);
	}
}

/*
void TBLInsert(Table * pt, Key k, Value v) {
	int hv = pt->hf(k);
	FInsert(pt->tbl[hv].v, v);
}
*/
Value TBLDelete(Table * pt, Key k) {
	int hv = pt->hf(k);
	Slot cSlot;
	
	if(LFirst(&(pt->tbl[hv]), &cSlot)) {
		if(cSlot.key == k) {
			LRemove(&(pt->tbl[hv]));
			return cSlot.val;
		}
		while(LNext(&(pt->tbl[hv]), &cSlot)) {
			if(cSlot.key == k) {
				LRemove(&(pt->tbl[hv]));
				return cSlot.val;
			}
		}
	}
	
	return NULL;
}

Value TBLSearch(Table * pt, Key k) {
	int hv = pt->hf(k);
	Slot cSlot;
	
	if(LFirst(&(pt->tbl[hv]), &cSlot)) {
		if(cSlot.key == k) {
			return cSlot.val;
		}
		while(LNext(&(pt->tbl[hv]), &cSlot)) {
			if(cSlot.key == k) {
				return cSlot.val;
			}
		}
	}
	return NULL;
}