#ifndef __PRIORITYQUEUE_H__
#define __PRIORITYQUEUE_H__

#include "UsefulHeap.h"

typedef HData PQData;
typedef Heap PQueue;

void PQueueInit(PQueue * ppq, PriorityComp pc);
int PQIsEmpty(PQueue * ppq);

void PEnqueue(PQueue * ppq, PQData data);
PQData PDequeue(PQueue * ppq);

#endif