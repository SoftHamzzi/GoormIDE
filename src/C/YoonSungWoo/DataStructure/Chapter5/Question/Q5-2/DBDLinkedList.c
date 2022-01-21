#include <stdio.h>
#include <stdlib.h>
#include "DBDLinkedList.h"

void ListInit(List * plist) {
	//plist->cur = NULL;
	plist->head = (Node *)malloc(sizeof(Node));
	plist->tail = (Node *)malloc(sizeof(Node));
	
	plist->head->prev = NULL;
	plist->head->next = plist->tail;
	
	plist->tail->prev = plist->head;
	plist->tail->next = NULL;
	
	plist->numOfData = 0;
}

void LInsert(List * plist, Data data) {
	/*
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = plist->tail->prev;
	plist->tail->prev->next = newNode;

	newNode->next = plist->tail;
	plist->tail->prev = newNode;

	(plist->numOfData)++;
	*/
	
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	
	if(plist->head == plist->tail->prev) {
		newNode->next = plist->tail;
		newNode->prev = plist->head;
		
		plist->head->next = newNode;
		plist->tail->prev = newNode;
	} else {
		plist->tail->prev->next = newNode; // 1 2 3. 1->2
		newNode->prev = plist->tail->prev; // 1 2 3. 2->1
		
		newNode->next = plist->tail; // 1 2 3. 2->3
		plist->tail->prev = newNode; // 1 2 3. 3->2
	}
	(plist->numOfData)++;
	
}

int LFirst(List * plist, Data * pdata) {
	/*
	if(plist->head->next == plist->tail)
		return FALSE;

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return TRUE;
	*/
	
	if(plist->head->next != plist->tail) {
		plist->cur = plist->head->next;
		*pdata = plist->cur->data;
		return TRUE;
	} else {
		return FALSE;
	}
	
}

int LNext(List * plist, Data * pdata) {
	/*
	if(plist->cur->next == plist->tail)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
	*/
	
	if(plist->cur->next != plist->tail) {
		plist->cur = plist->cur->next;
		*pdata = plist->cur->data;
		return TRUE;
	} else {
		return FALSE;
	}
	
}

Data LRemove(List * plist) {
	Node * rpos = plist->cur;
	Data ret;
	
	ret = plist->cur->data;
		
	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;
		
	plist->cur = plist->cur->prev;
		
	free(rpos);
	(plist->numOfData)--;
		
	return ret; 
	
}

int LCount(List * plist) {
	return plist->numOfData;
}