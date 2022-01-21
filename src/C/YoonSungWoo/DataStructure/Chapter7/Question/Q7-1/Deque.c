#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque * pdeq) {
	pdeq->head = NULL;
	pdeq->tail = NULL;
}
int DQIsEmpty(Deque * pdeq) {
	if(pdeq->head == NULL) return TRUE;
	return FALSE;
}

void DQAddFirst(Deque * pdeq, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = pdeq->head;
	
	if(DQIsEmpty(pdeq)) {
		pdeq->tail = newNode;
	} else {
		pdeq->head->prev = newNode;
	}
	
	newNode->prev = NULL; // 들어가야하나?
	pdeq->head = newNode;
}
void DQAddLast(Deque * pdeq, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->prev = pdeq->tail;
	
	if(DQIsEmpty(pdeq)) {
		pdeq->head = newNode;
	} else {
		pdeq->tail->next = newNode;
	}
	
	newNode->next = NULL; // 들어가야하나?
	pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque * pdeq) {
	Data retData = pdeq->head->data;;
	Node * retNode = pdeq->head;
	
	if(DQIsEmpty(pdeq)) {
		printf("Deque Memory Error!");
		exit(-1);
	}
	
	pdeq->head = pdeq->head->next;
	free(retNode);
	
	if(pdeq->head == NULL) {
		pdeq->tail = NULL;
	} else {
		pdeq->head->prev = NULL;
	}
	
	return retData;
}
Data DQRemoveLast(Deque * pdeq) {
	Data retData = pdeq->tail->data;
	Node * retNode = pdeq->tail;
	
	if(DQIsEmpty(pdeq)) {
		printf("Deque Memory Error!");
		exit(-1);
	}
	
	pdeq->tail = pdeq->tail->prev;
	free(retNode);
	
	if(pdeq->tail == NULL) {
		pdeq->head = NULL;
	} else {
		pdeq->tail->next = NULL;
	}
	
	return retData;
}

Data DQGetFirst(Deque * pdeq) {
	if(DQIsEmpty(pdeq)) {
		printf("Deque Memory Error!");
		exit(-1);
	}
	
	return pdeq->head->data;
}
Data DQGetLast(Deque * pdeq) {
	if(DQIsEmpty(pdeq)) {
		printf("Deque Memory Error!");
		exit(-1);
	}
	
	return pdeq->tail->data;
}