#include <stdio.h>
#include <string.h>
#include "PriorityQueue.h"

int DataPriorityComp(char * ch1, char * ch2) {
	int ch1Len = strlen(ch1);
	int ch2Len = strlen(ch2);
	return ch2Len-ch1Len;
}

int main(void) {
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);
	
	PEnqueue(&pq, "Good Morning");
	PEnqueue(&pq, "I am a boy");
	PEnqueue(&pq, "Priority Queue");
	PEnqueue(&pq, "Do you like coffee");
	PEnqueue(&pq, "I am so happy");
	
	while(!PQIsEmpty(&pq)) {
		printf("%s \n", PDequeue(&pq));
	}
}