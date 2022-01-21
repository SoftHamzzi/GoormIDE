#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List * plist) {
	//plist->cur = NULL;
	plist->head = NULL;
	plist->numOfData = 0; 
}

void LInsert(List * plist, Data data) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = plist->head;
	if(plist->head!=NULL)
		plist->head->prev = newNode;
	newNode->prev = NULL;
	plist->head = newNode;
	
	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata) {
	if(plist->head != NULL) {
		plist->cur = plist->head;
		*pdata = plist->cur->data;
		return TRUE;
	} else {
		return FALSE;
	}
}

int LNext(List * plist, Data * pdata) {
	if(plist->cur->next != NULL) {
		plist->cur = plist->cur->next;
		*pdata = plist->cur->data;
		return TRUE;
	} else {
		return FALSE;
	}
}

int LPrevious(List * plist, Data * pdata) {
	if(plist->cur->prev != NULL) {
		plist->cur = plist->cur->prev;
		*pdata = plist->cur->data;
		return TRUE;
	} else {
		return FALSE;
	}
}

int LCount(List * plist) {
	return plist->numOfData;
}