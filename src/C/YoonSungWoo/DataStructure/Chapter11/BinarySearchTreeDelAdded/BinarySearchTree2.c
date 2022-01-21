#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree2.h"
#include "BinaryTree3.h"

void BSTMakeAndInit(BTreeNode ** pRoot) {
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst) {
	return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data) {
	BTreeNode * pNode = NULL;
	BTreeNode * cNode = *pRoot;
	BTreeNode * nNode = NULL;
	
	while(cNode != NULL) {
		if(data == GetData(cNode))
			return;
		
		pNode = cNode;
		
		if(GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	
	nNode = MakeBTreeNode();
	SetData(nNode, data);
	
	if(pNode != NULL) {
		if(data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	} else {
		*pRoot = nNode;
	}
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target) {
	BTreeNode * cNode = bst;
	BSTData cd;
	
	while(cNode != NULL) {
		cd = GetData(cNode);
		
		if(target == cd)
			return cNode;
		else if(target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	
	return NULL;
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target) {
	BTreeNode * pVRoot = MakeBTreeNode();
	BTreeNode * pNode = pVRoot;
	BTreeNode * cNode = *pRoot;
	BTreeNode * dNode;
	
	// 루트 노드를 pVRoot가 가리키는 노드의 오른쪽 자식 노드가 되게 한다.
	ChangeRightSubTree(pVRoot, *pRoot);
	
	// 삭제 대상인 노드를 탐색
	while(cNode != NULL && GetData(cNode) != target) {
		pNode = cNode;
		if(target < GetData(cNode)) {
			cNode = GetLeftSubTree(cNode);
		} else {
			cNode = GetRightSubTree(cNode);
		}
	}
	
	// 삭제 노드가 존재하지 않는다면,
	if(cNode == NULL) {
		return NULL;
	}
	
	dNode = cNode;
	
	// 첫 번째 경우: 삭제 대상이 단말 노드
	if(GetLeftSubTree(dNode)==NULL && GetRightSubTree(dNode)==NULL) {
		if(GetLeftSubTree(dNode) == dNode) {
			RemoveLeftSubTree(pNode);
		} else {
			RemoveRightSubTree(pNode);
		}
	}
	
	// 두 번쨰 경우: 삭제 대상이 하나의 자식 노드
	else if(GetLeftSubTree(dNode)==NULL || GetRightSubTree(dNode)==NULL) {
		BTreeNode * dcNode;    // delete node의 자식 노드

		if(GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		if(GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
		/*if(GetLeftSubTree(dNode)!=NULL) {
			ChangeRightSubTree(pNode,GetLeftSubTree(dNode));
		}
		else {
			ChangeRightSubTree(pNode,GetLeftSubTree(dNode));
		}*/
	}
	
	// 세 번째 경우: 삭제 대상이 두개의 자식 노드
	else {
		BTreeNode * mNode = GetRightSubTree(dNode);
		BTreeNode * mpNode = dNode;
		int delData;
		
		//삭제 대상의 대체 노드를 찾는다.
		while(GetLeftSubTree(mNode)!=NULL) {
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}
		
		// 대체 노드에 저장된 값을 삭제할 노드에 대입한다.
		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));
		
		// 대체 노드의 부모 노드와 자식 노드를 연결한다.
		if(GetLeftSubTree(mpNode)==mNode) {
			ChangeLeftSubTree(mpNode,GetRightSubTree(mNode));
		} else {
			ChangeRightSubTree(mpNode,GetRightSubTree(mNode));
		}
		
		dNode = mNode;
		SetData(dNode, delData);
	}
	
	// 삭제된 노드가 루트 노드인 경우에 대한 추가적인 처리
	if(GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);
		
	free(pVRoot);
	return dNode;
}

void ShowIntData(int data) {
	printf("%d ", data);
}

void BSTShowAll(BTreeNode * bst) {
	InOrderTraverse(bst, ShowIntData);
}