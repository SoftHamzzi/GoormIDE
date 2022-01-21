#include <stdio.h>
#include "CLinkedList.h"

int main(void) {
	List stack;
	ListInit(&stack);
	
	// 데이터 넣기
	LInsertFront(&stack, 1); LInsertFront(&stack, 2);
	LInsertFront(&stack, 3); LInsertFront(&stack, 4);
	LInsertFront(&stack, 5);
	
	// 데이터 꺼내기
	Data data;
	if(LFirst(&stack, &data)) {
		printf("%d ", data);
		for(int i=0; i<LCount(&stack)-1; i++) {
			LNext(&stack, &data);
			printf("%d ", data);
		}
	}
	printf("\n");
	
	return 0;
}