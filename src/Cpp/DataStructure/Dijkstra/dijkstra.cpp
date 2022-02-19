// https://m.blog.naver.com/ndb796/221234424646
#include <iostream>

using namespace std;

int number=6;
int INF = 10000000;

int a[6][6] = {
	{0,2,5,1,INF,INF},
	{2,0,3,2,INF,INF},
	{5,3,0,3,1,5},
	{1,2,3,0,1,INF},
	{INF,INF,1,1,0,2},
	{INF,INF,5,INF,2,0}
};
bool v[6]; // 방문한 노드
int d[6]; // 거리

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

int main(void) {
	dijkstra(0);
	for(int i=0;i<number;i++) {
		cout<<d[i]<<" ";
	}
}