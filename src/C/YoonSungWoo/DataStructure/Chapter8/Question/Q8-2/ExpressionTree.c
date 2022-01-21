#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "ExpressionTree.h"
#include "BinaryTree2.h"
#include "ListBaseStack.h"

BTreeNode * MakeExpTree(char exp[]) {
	Stack stack;
	StackInit(&stack);
	int i;
	BTreeNode * pnode;
	int expLen = strlen(exp);
	for(i=0;i<expLen;i++) {
		pnode = MakeBTreeNode();
		if(isdigit(exp[i])) {
			SetData(pnode, exp[i]-'0');
		}
		else {
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}
		SPush(&stack, pnode);
	}
	return SPop(&stack);
}
int EvaluateExpTree(BTreeNode * bt) {
	if(bt->left == NULL && bt->right == NULL) {
		return GetData(bt);
	}
	
	int op1 = EvaluateExpTree(GetLeftSubTree(bt));
	int op2 = EvaluateExpTree(GetRightSubTree(bt));
	
	switch(GetData(bt)) {
		case '+':
			return op1+op2;
		case '-':
			return op1-op2;
		case '*':
			return op1*op2;
		case '/':
			return op1/op2;
	}
}

void ShowNodeData(int data) {
	if(0<=data && data<=9)
		printf("%d ", data);
	else
		printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode * bt) {
	PreOrderTraverse(bt, ShowNodeData);
}
void ShowInfixTypeExp(BTreeNode * bt) {
	if(bt == NULL) return;
	
	if(bt->left != NULL && bt->right != NULL) {
		printf("( ");
	}
	
	ShowInfixTypeExp(bt->left);
	ShowNodeData(bt->data);
	ShowInfixTypeExp(bt->right);
	
	if(bt->left != NULL && bt->right != NULL) {
		printf(") ");
	}
}
void ShowPostfixTypeExp(BTreeNode * bt) {
	PostOrderTraverse(bt, ShowNodeData);
}