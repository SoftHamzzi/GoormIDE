#ifndef __BINARYTREE3_H__
#define __BINARYTREE3_H__

typedef int BTData;

typedef struct _bTreeNode {
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
} BTreeNode;

typedef void VisitFuncPtr(BTData data);

void PreOrderTraverse(BTreeNode * bt, VisitFuncPtr action);
void InOrderTraverse(BTreeNode * bt, VisitFuncPtr action);
void PostOrderTraverse(BTreeNode * bt, VisitFuncPtr action);

BTreeNode * MakeBTreeNode(void);
BTData GetData(BTreeNode * bt);
void SetData(BTreeNode * bt, BTData data);

BTreeNode * RemoveLeftSubTree(BTreeNode * bt);
BTreeNode * RemoveRightSubTree(BTreeNode * bt);
void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub);

BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);
void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);

#endif