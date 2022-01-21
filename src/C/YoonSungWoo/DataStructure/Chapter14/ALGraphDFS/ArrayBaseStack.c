#include "ArrayBaseStack.h"

// 스택의 초기화를 진행한다.
void StackInit(Stack * pstack) {
	pstack->topIndex = -1;
}

// 스택이 빈 경우 TRUE를, 아니면 FALSE를 반환한다.
int SIsEmpty(Stack * pstack) {
	if(pstack->topIndex != -1)
		return FALSE;
	return TRUE;
}

// 스택에 데이터를 저장한다. 매개변수 data로 전달된 값을 저장한다.
void SPush(Stack * pstack, Data data) {
	pstack->topIndex++;
	pstack->stackArr[pstack->topIndex] = data;
}

// 마지막에 저장된 요소를 삭제하고 반환한다. SIsEmpty와 엮어쓴다.
Data SPop(Stack * pstack) {
	return pstack->stackArr[pstack->topIndex--];
}

// 마지막에 저장된 요소를 반환만 한다. SIsEmpty와 엮어쓴다.
Data SPeek(Stack * pstack) {
	return pstack->stackArr[pstack->topIndex];
}