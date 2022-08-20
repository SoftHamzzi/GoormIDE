#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	queue<int> q;
	int check[200001][2]; // [0]은 visited 역할, [1]은 count의 역할
	
	int n1,n2; cin>>n1>>n2;
	check[n1][1] = 0;
	check[n1][0] = 1;
	q.push(n1);
	
	while(q.front()!=n2) {
		if(!check[q.front()-1][0] && 0 < q.front()) {
			check[q.front()-1][0] = 1;
			check[q.front()-1][1] = check[q.front()][1] + 1;
			q.push(q.front()-1);
		}
		if(!check[q.front()+1][0] && q.front()+1 < 100001) {
			check[q.front()+1][0] = 1;
			check[q.front()+1][1] = check[q.front()][1] + 1;
			q.push(q.front()+1);
		}
		if(!check[q.front()*2][0] && q.front()*2 < 100001) {
			check[q.front()*2][0] = 1;
			check[q.front()*2][1] = check[q.front()][1] + 1;
			q.push(q.front()*2);
		}
		q.pop();
	}
	
	cout<<check[q.front()][1]<<endl;
}