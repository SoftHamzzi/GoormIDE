#include <stdio.h>
#include "InfixCalculator.h"

int main(void) {
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";
	
	printf("1+2*3 = %d\n", EvalInfixExp(exp1));
	printf("(1+2)*3 = %d\n", EvalInfixExp(exp2));
	printf("((1-2)+3)*(5-2) = %d\n", EvalInfixExp(exp3));
	return 0;
}