#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[101];
bool visited[101];

int ladderAndSnake() {
	
	int cnt=0;
	
	queue<int> q;
	
	q.push(1);
	visited[1] = true;
	
	while(!q.empty()) { // 큐가 빌 때까지
		
		for(int i=q.front(); i<q.front()+6; i++) {
		
			for(int to : v[i]) {
				if(!visited[to]) { // 갔던 곳이 아닐 때
					q.push(to);
					visited[to] = true;
					cnt++;
				}
				// 갔던 곳일때는 for문으로 돌아간다.
			}
		
		q.pop(); // 큐 하나 삭제
		
	}
	
	return cnt;
	
}

int main(void) {
	
	int ladder, snake; cin>>ladder>>snake;
	
	int s,e;
	for(int i=0; i<ladder+snake; i++) {
		cin>>s>>e;
		
		v[s].push_back(e);
	}
	
	cout << ladderAndSnake() << endl;
	
}