#include "InfixCalculator.h"
#include "InfixToPostfix.h"
#include "PostCalculator.h"

int EvalInfixExp(char exp[]) {
	int result;
	
	ConvToRPNExp(exp);
	return result = EvalRPNExp(exp);
}