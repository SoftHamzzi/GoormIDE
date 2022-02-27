// sort를 쓴 뒤 이분탐색
#include <iostream>
#include <algorithm>

using namespace std;

int dex[100000];

int binarySearch(int start, int end, int target) {
	int middle = (end+start)/2;
	
	if(start>end)
		return 0;
	
	if(dex[middle] == target) {
		return 1;
	} else if(dex[middle] > target) {
		return binarySearch(start,middle-1,target);
	} else if(dex[middle] < target) {
		return binarySearch(middle+1,end,target);
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	// 코드 시작
	int n; cin>>n;
	int input;
	for(int i=0;i<n;i++) {
		cin>>input;
		dex[i] = input;
	}
	
	// 알고리즘 STL을 이용한 정렬
	sort(&dex[0],&dex[n]);
	
	int m; cin>>m;
	for(int i=0;i<m;i++) {
		cin>>input;
		cout<<binarySearch(0,n-1,input)<<"\n";
	}
}

/*
// algorithm STL 사용
// 하지만 find의 시간복잡도가 O(n)이라 실패
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	// cin, cout 동기화 해제
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	// 코드 시작
	int dex[100000];
	
	int n; cin>>n;
	int input;
	for(int i=0;i<n;i++) {
		cin>>input;
		dex[i] = input;
	}
	
	int m; cin>>m;
	int *result;
	for(int i=0;i<m;i++) {
		cin>>input;
		result = find(&dex[0],&dex[n],input);
		if(result == &dex[n]) {
			cout<<"0\n";
		} else {
			cout<<"1\n";
		}
	}
}
*/

/* AVL이나 Red black Tree가 아니라 시간초과
#include <iostream>

using namespace std;

typedef struct _node {
	struct _node *left;
	struct _node *right;
	int data;
} Node;

class Tree {
	public:
	Node *head;
	int numofData;
	
	public:
	void TreeInit() {
		this->head = NULL;
		this->numofData = 0;
	}
};

void insertNode(Tree &tree,int data) {
	// 노드 생성
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	
	// 트리가 비어있는 경우
	if(tree.head == NULL) {
		tree.head = newNode;
		return;
	}
	// 트리가 비어있지 않을 때
	Node *pNode = NULL;
	Node *cur = tree.head;
	while(cur != NULL) {
		pNode = cur;
		if(cur->data == data) { // 넣을 데이터가 현재 노드의 데이터와 같을때
			return; // 바로 종료
		} else if(cur->data > data) { // 넣을 데이터가 현재 노드의 데이터보다 작을 때
			cur = cur->left;
		} else if(cur->data < data) { // 넣을 데이터가 현재 노드의 데이터보다 클 때
			cur = cur->right;
		}
	}
	// 빈 노드에 도착했으므로 현재 노드에 새 노드 삽입
	if(pNode->data > data) {
		pNode->left = newNode;
	} else if(pNode->data < data) {
		pNode->right = newNode;
	}
}

int searchNode(Tree &tree, int target) {
	Node * cur = tree.head;
	
	while(cur != NULL) {
		if(cur->data == target) { // 넣을 데이터가 현재 노드의 데이터와 같을때
			return 1; // 바로 종료
		} else if(cur->data > target) { // 넣을 데이터가 현재 노드의 데이터보다 작을 때
			cur = cur->left;
		} else if(cur->data < target) { // 넣을 데이터가 현재 노드의 데이터보다 클 때
			cur = cur->right;
		}
	}
	// 원하는 값을 찾지 못했음
	return 0;
}

int main(void) {
	// cin, cout 동기화 해제
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	// 트리 생성
	Tree tree;
	tree.TreeInit();
	
	// 값 받아서 트리에 집어넣기
	int n; cin>>n;
	int input;
	for(int i=0;i<n;i++) {
		cin>>input;
		insertNode(tree, input);	
	}
	
	// 값 받아서 트리에서 찾기
	int m; cin>>m;
	for(int i=0;i<m;i++) {
		cin>>input;
		cout<<searchNode(tree, input)<<"\n";
	}
}
*/