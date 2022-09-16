#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct comp {
	bool operator()(int a, int b) {
		return a>b;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	priority_queue<int, vector<int>, comp> pq;
	
	int n; cin>>n;
	
	int temp;
	for(int i=0; i<n; i++) {
		
		cin>>temp;
		if(temp == 0) {
			
			cout << pq.pop() << endl;
			
		} else {
			
			pq.push(temp);
			
		}
		
	}
}