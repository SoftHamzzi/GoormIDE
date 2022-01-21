#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int EvalRPNExp(char exp[]) {
	Stack stack;
	StackInit(&stack);
	
	char tok, op1, op2;
	
	int expLen = strlen(exp);
	
	for(int i=0; i<expLen; i++) {
		tok = exp[i];
		if(isdigit(tok))
			SPush(&stack, tok - '0');
		else {
			op2 = SPop(&stack);
			op1 = SPop(&stack);
			
			switch(tok) {		
				case '+':
					SPush(&stack,op1+op2);
					break;
				case '-':
					SPush(&stack,op1-op2);
					break;
				case '*':
					SPush(&stack,op1*op2);
					break;
				case '/':
					SPush(&stack,op1/op2);
					break;
			}
		}
	}
	return SPop(&stack);
}