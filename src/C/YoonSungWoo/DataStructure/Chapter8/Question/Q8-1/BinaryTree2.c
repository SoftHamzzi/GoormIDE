#include <stdlib.h>
#include "BinaryTree2.h"

BTreeNode * MakeBTreeNode(void) {
	BTreeNode * newNode = (BTreeNode *)malloc(sizeof(BTreeNode));
	
	newNode->left = NULL;
	newNode->right = NULL;
}
BTData GetData(BTreeNode * bt) {
	return bt->data;
}
void SetData(BTreeNode * bt, BTData data) {
	bt->data = data;
}
void DeleteTree(BTreeNode * bt) {
	if(bt == NULL) return;
	DeleteTree(bt->left);
	DeleteTree(bt->right);
	bt->left = NULL;
	bt->right = NULL;
	free(bt);
}

BTreeNode * GetLeftSubTree(BTreeNode * bt) {
	return bt->left;
}
BTreeNode * GetRightSubTree(BTreeNode * bt) {
	return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub) {
	if(main->left != NULL)
		free(main->left);
	main->left = sub;
}
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub) {
	free(main->right);
	main->right = sub;
}

void PreOrderTraverse(BTreeNode * bt, VisitFuncPtr action) {
	if(bt == NULL) return;
	action(bt->data);
	PreOrderTraverse(bt->left, action);
	PreOrderTraverse(bt->right, action);
}
void InOrderTraverse(BTreeNode * bt, VisitFuncPtr action) {
	if(bt == NULL) return;
	InOrderTraverse(bt->left, action);
	action(bt->data);
	InOrderTraverse(bt->right, action);
}
void PostOrderTraverse(BTreeNode * bt, VisitFuncPtr action) {
	if(bt == NULL) return;
	PostOrderTraverse(bt->left, action);
	PostOrderTraverse(bt->right, action);
	action(bt->data);
}