#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
	
	vector<int> v[51];
	
	int cnt=0;
	int root;
	int n; cin>>n;
	
	int temp;
	for(int i=0; i<n; i++) {
		cin>>temp;
		
		if(temp == -1) {
			root = i;
		} else {
			v[temp].push_back(i);
		}
	}
	
	cin>>temp;
	if(temp==root) {
		cout<<"0"<<endl;
	} else {
		
		for(int i=0; i<n; i++) {
			v[i].erase(remove(v[i].begin(), v[i].end(), temp), v[i].end());
		}
		
		queue<int> q;
		q.push(root);
		
		while(!q.empty()) {
			
			if(v[q.front()].empty())
				cnt++;
				
			for(int i : v[q.front()])
				q.push(i);
				
			q.pop();
			
		}
	
		cout << cnt << endl;
	}
	
}

//#include <iostream>
//
//using namespace std;
//
//int cnt=0;
//
//template <typename T>
//void safe_delete(T& p){
//
//    delete p;
//    p = NULL;
//    
//}
//
//typedef struct _node {
//	int data;
//	_node * left;
//	_node * right;
//} Node;
//
//Node* parentNode;
//
//class BinaryTree {
//	public:
//		
//		Node* rootNode; // 최상위 노드 
//		
//		Node* CreateNode() {
//			
//			Node* newNode = new Node;
//			newNode->left = NULL;
//			newNode->right = NULL;
//			
//			return newNode;
//			
//		}
//		
//		bool GetData(Node* node, int& data) {
//			
//			if(node == NULL)
//				return false;
//			
//			data = node->data;
//			return true;
//			
//		}
//		bool SetData(Node* node, int data) {
//			
//			if(node == NULL)
//				return false;
//				
//			node->data = data;
//			return true;
//			
//		}
//		
//		bool GetLeftNode(Node* parent, Node ** node) {
//			
//			if(parent == NULL) {
//				*node = NULL;
//				return false;
//			}
//			
//			*node = parent->left;
//			return true;
//			
//		}
//		bool GetRightNode(Node* parent, Node ** node) {
//			
//			if(parent == NULL) {
//				*node = NULL;
//				return false;
//			}
//			
//			*node = parent->right;
//			return true;
//			
//		}
//		
//		bool SetLeftNode(Node* parent, Node* child) {
//			
//			if(parent == NULL || child == NULL) {
//				return false;
//			}
//			
//			if(parent->left != NULL) {
//				RemoveNode(parent->left);
//			}
//			
//			parent->left = child;
//			return true;
//			
//		}
//		
//		bool SetRightNode(Node* parent, Node* child) {
//			
//			if(parent == NULL || child == NULL) {
//				return false;
//			}
//			
//			if(parent->right != NULL) {
//				RemoveNode(parent->right);
//			}
//			
//			parent->right = child;
//			return true;
//			
//		}
//		
//		Node* FindNode(Node* node, int target) {
//			
//			Node* tempNode;
//			
//			if(node == NULL)
//				return NULL;
//				
//			if(node->data == target)
//				return node;
//				
//			tempNode = FindNode(node->left, target);
//			
//			if(tempNode == NULL) {
//				tempNode = FindNode(node->right, target);
//			}
//				
//			return tempNode;
//			
//		}
//		
//		
//		void print(Node* node) {
//			
//			if(node == NULL)
//				return;
//				
//			cout << node->data << endl;
//			print(node->left);
//			print(node->right);
//			
//		}
//		
//		void cntLeap(Node* node) {
//			
//			if(node == NULL) {
//				return;
//			}
//			
//			if(node->left == NULL && node->right == NULL)
//				cnt++;
//			
//			cntLeap(node->left);
//			cntLeap(node->right);
//			
//		} 
//		
//		void RemoveNode(Node* node) {
//			
//			if(node == NULL)
//				return;
//				
//			RemoveNode(node->left);
//			RemoveNode(node->right);
//			safe_delete(node);
//			
//			
//		}
//};
//
//int main(void) {
//	int n; cin>>n;
//	BinaryTree tree;
//	
//	Node* tempNode;
//	
//	int temp;
//	for(int i=0; i<n; i++) {
//		
//		cin>>temp;
//		if(temp==-1) { // 첫 번째 노드 삽입
//			Node* tempNode = tree.CreateNode();
//			tree.SetData(tempNode,i);
//			tree.rootNode = tempNode;
//		} else { // 원하는 값을 가진 노드에 새로운 노드 삽입
//			Node* tempNode = tree.CreateNode();
//			tree.SetData(tempNode,i);
//			
//			Node* targetNode = tree.FindNode(tree.rootNode, temp);
//			
//			if(targetNode->left == NULL) {
//				tree.SetLeftNode(targetNode, tempNode);
//			} else {
//				tree.SetRightNode(targetNode, tempNode);
//			}
//		}
//	}
//	
//	cin>>temp;
//	tree.RemoveNode(tree.FindNode(tree.rootNode, temp));
//	
//	tree.print(tree.rootNode);
//	
//	tree.cntLeap(tree.rootNode);
//	
//	cout<< cnt << endl;	
//}