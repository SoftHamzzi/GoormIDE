// DFS와 BFS
#include <iostream>
#include <deque>

using namespace std;

int edge[1001][1001];
deque<int> vertex;
int visit[1001];

int n,m,v;

void connectEdge(int a, int b) {
	edge[a][b]=1;
	edge[b][a]=1;
}

void dfs() {
	vertex.push_back(v);
	visit[v]=1;
	cout<<v<<" ";
	
	while(!vertex.empty()) {
		v = vertex.back();
		// v와 연결된 정점들이 연결O + 방문X 인 곳을 차례대로 찾는다.
		for(int i=1;i<=n;i++) {
			if(edge[v][i] && !visit[i]) {
				// 찾았다면 해당 정점을 스택에 넣고 방문 처리를 해준 뒤 출력하고 break;한다.
				vertex.push_back(i);
				visit[i]=1;
				cout<<i<<" ";
				break;
			}
			// v에서 더이상 갈 곳이 없을때, 스택에서 하나를 뺀다.
			if(i==n)
				vertex.pop_back();
		}
	}
	cout<<endl;
}

void bfs() {
	vertex.push_back(v);
	visit[v]=1;
	
	while(!vertex.empty()) {
		v = vertex.front();
		cout<<v<<" ";
		vertex.pop_front();
		// v와 연결된 정점들이 연결O + 방문X 인 곳을 차례대로 찾는다.
		for(int i=1;i<=n;i++) {
			if(edge[v][i] && !visit[i]) {
				vertex.push_back(i);
				visit[i]=1;
			}
		}
	}
	cout<<endl;
}

int main(void) {
	cin>>n>>m>>v;
	
	int input1, input2;
	for(int i=0;i<m;i++) {
		cin>>input1>>input2;
		connectEdge(input1,input2);
	}
	
	dfs();
	for(int i=1;i<=n;i++) {
		visit[i]=0;
	}
	bfs();
}