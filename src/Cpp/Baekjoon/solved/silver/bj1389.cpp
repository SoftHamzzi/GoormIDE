// https://m.blog.naver.com/ndb796/221234424646
#include <iostream>

using namespace std;

int number;
int INF = 10000000;

int a[5001][5001];
bool v[5001]; // 방문한 노드
int d[5001]; // 거리

int getSmallIndex() {
	int min = INF;
	int index = 0;
	for(int i=0;i<number;i++) {
		// 방문하지 않았고, min보다 작다면
		if(!v[i] && min > d[i]) {
			min = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	// 거리를 채워넣음
	for(int i=0;i<number;i++) {
		d[i] = a[start][i];
	}
	
	v[start] = true;
	
	for(int i=0;i<number-2;i++) {
		int current = getSmallIndex();
		v[current] = true;
		
		for(int j=0;j<number;j++) {
			if(!v[j]) {
				if(d[j] > d[current] + a[current][j])
					d[j] = d[current] + a[current][j];
			}
		}
	}
}

void reset() {
	for(int i=0;i<number;i++) {
		v[i]=false;
	}
}
	
int main(void) {
	int m; cin>>number>>m;
	
	int input1,input2;
	for(int i=0;i<number;i++) {
		for(int j=0;j<number;j++) {
			if(i==j) a[i][j] = 0;
			else a[i][j] = INF;
		}
	}
	
	for(int i=0;i<m;i++) {
		cin>>input1>>input2;
		
		input1--; input2--;
		a[input1][input2] = a[input2][input1] = 1;
	}
	
	int min=INF;
	int sum;
	int index;
	for(int i=0;i<number;i++) {
		sum=0;
		dijkstra(i);

		for(int j=0;j<number;j++) {
			sum += d[j];
		}
		
		if(min > sum) {
				min = sum;
				index = i+1;
			}
		reset();
	}
	cout<<index;
}

/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int INF = 10000000;

vector<pair<int, int>> a[5001]; // 간선 정보
int d[5001]; // 최소 비용

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int,int>> pq;
	
	pq.push(make_pair(start,0));
	
	while(!pq.empty()) {
		int current = pq.top().first;
		
		int distance = -pq.top().second;
		pq.pop();
		// 최단 거리가 아니면 스킵
		if(d[current]<distance) continue;
		
		for(int i=0;i<a[current].size();i++) {
			// 선택된 노드의 인접 노드
			int next = a[current][i].first;
			// 선택된 노드를 인접 노드로 거쳐서 가는 비용
			int nextDistance = distance + a[current][i].second;
			
			// 기존의 최소 비용보다 저렴하다면 교체
			if(nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

void resetd() {
	for(int i=1;i<=n;i++)
		d[i] = INF;
}

int main(void) {
	int m; cin>>n>>m;
	// 최소 비용 배열을 모두 INF로 바꿈
	resetd();
	
	int input1,input2;
	for(int i=1;i<=m;i++) {
		cin>>input1>>input2;
		a[input1].push_back(make_pair(input2,1));
	}
	
	int min=INF;
	int sum;
	int index;
	for(int i=1;i<=n;i++) {
		dijkstra(i);
		
		for(int l=1;l<=n;l++) {
			cout<<d[l]<<" ";
		}
		cout<<endl;
		
		for(int j=1;j<=n;j++) {
			sum += d[j];
			if(min > sum) {
				min = sum;
				index = i;
			}
		}
		resetd();
	}
	
	cout<<index;
	
}
*/