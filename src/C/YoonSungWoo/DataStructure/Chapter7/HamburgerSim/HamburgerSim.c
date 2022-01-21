#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "CircularQueue.h"

#define CUS_COME_TERM 15

#define CHE_BUR 0
#define BUL_BUR 1
#define DUB_BUR 2

#define CHE_TERM 12
#define BUL_TERM 15
#define DUB_TERM 24

int main(void) {
	int makeProc = 0;
	int cheOrder=0, bulOrder=0, dubOrder=0;
	int sec;
	
	Queue q;
	QueueInit(&q);
	
	srand(time(NULL));
	for(sec=0;sec<3600;sec++) {
		if(sec%CUS_COME_TERM == 0) {
			switch(rand()%3) {
				case CHE_BUR:
					Enqueue(&q, CHE_TERM);
					cheOrder++;
					break;
				case BUL_BUR:
					Enqueue(&q, BUL_TERM);
					bulOrder++;
					break;
				case DUB_BUR:
					Enqueue(&q, DUB_TERM);
					dubOrder++;
					break;
			}
		}
		
		if(makeProc<=0 && !QIsEmpty(&q))
			makeProc=Dequeue(&q);
		
		makeProc--;
	}
	
	printf("Simulation Report! \n");
	printf(" - Cheese burger: %d \n", cheOrder);
	printf(" - Bulgogi burger: %d \n", bulOrder);
	printf(" - Double burger: %d \n", dubOrder);
	printf(" - waiting room size: %d \n", QUE_LEN);
}